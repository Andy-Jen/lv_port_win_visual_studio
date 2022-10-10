/**
 * @file lv_rocker.c
 *
 */

 /*********************
  *      INCLUDES
  *********************/
#include "lv_rocker.h"
#if LV_USE_ROCKER != 0

#include "../misc/lv_assert.h"
#include "../draw/lv_draw.h"
#include "../misc/lv_anim.h"
#include "../misc/lv_math.h"

  /*********************
   *      DEFINES
   *********************/
#define MY_CLASS &lv_rocker_class

   /** hor. pad and ver. pad cannot make the indicator smaller than this [px]*/
#define LV_ROCKER_SIZE_MIN  4

#define LV_ROCKER_IS_ANIMATING(anim_struct) (((anim_struct).anim_state) != LV_ROCKER_ANIM_STATE_INV)
#define LV_ROCKER_GET_ANIM_VALUE(orig_value, anim_struct) (LV_ROCKER_IS_ANIMATING(anim_struct) ? ((anim_struct).anim_end) : (orig_value))

/** rocker animation start value. (Not the real value of the rocker just indicates process animation)*/
#define LV_ROCKER_ANIM_STATE_START 0

/** rocker animation end value.  (Not the real value of the rocker just indicates process animation)*/
#define LV_ROCKER_ANIM_STATE_END   256

/** Mark no animation is in progress*/
#define LV_ROCKER_ANIM_STATE_INV   -1

/** log2(LV_rocker_ANIM_STATE_END) used to normalize data*/
#define LV_ROCKER_ANIM_STATE_NORM  8

/**********************
 *      TYPEDEFS
 **********************/

 /**********************
  *  STATIC PROTOTYPES
  **********************/
static void lv_rocker_constructor(const lv_obj_class_t* class_p, lv_obj_t* obj);
static void lv_rocker_destructor(const lv_obj_class_t* class_p, lv_obj_t* obj);
static void lv_rocker_event(const lv_obj_class_t* class_p, lv_event_t* e);
static void draw_indic(lv_event_t* e);
static void lv_rocker_set_value_with_anim(lv_obj_t* obj, int32_t new_value, int32_t* value_ptr,
    _lv_rocker_anim_t* anim_info, lv_anim_enable_t en);
static void lv_rocker_init_anim(lv_obj_t* rocker, _lv_rocker_anim_t* rocker_anim);
static void lv_rocker_anim(void* rocker, int32_t value);
static void lv_rocker_anim_ready(lv_anim_t* a);

/**********************
 *  STATIC VARIABLES
 **********************/
const lv_obj_class_t lv_rocker_class = {
    .constructor_cb = lv_rocker_constructor,
    .destructor_cb = lv_rocker_destructor,
    .event_cb = lv_rocker_event,
    .width_def = LV_DPI_DEF * 2,
    .height_def = LV_DPI_DEF / 10,
    .instance_size = sizeof(lv_rocker_t),
    .base_class = &lv_obj_class
};

/**********************
 *      MACROS
 **********************/

 /**********************
  *   GLOBAL FUNCTIONS
  **********************/

lv_obj_t* lv_rocker_create(lv_obj_t* parent)
{
    LV_LOG_USER("begin");
    lv_obj_t* obj = lv_obj_class_create_obj(MY_CLASS, parent);
    lv_obj_class_init_obj(obj);
    return obj;
}

/*=====================
 * Setter functions
 *====================*/

void lv_rocker_set_value(lv_obj_t* obj, int32_t value, lv_anim_enable_t anim)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);
    lv_rocker_t* rocker = (lv_rocker_t*)obj;

    if (rocker->cur_value == value) return;

    value = LV_CLAMP(rocker->min_value, value, rocker->max_value);
    value = value < rocker->start_value ? rocker->start_value : value; /*Can't be smaller than the left value*/

    if (rocker->cur_value == value) return;
    lv_rocker_set_value_with_anim(obj, value, &rocker->cur_value, &rocker->cur_value_anim, anim);
}

void lv_rocker_set_start_value(lv_obj_t* obj, int32_t value, lv_anim_enable_t anim)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);

    lv_rocker_t* rocker = (lv_rocker_t*)obj;

    if (rocker->mode != LV_ROCKER_MODE_RANGE) {
        return;
    }

    value = LV_CLAMP(rocker->min_value, value, rocker->max_value);
    value = value > rocker->cur_value ? rocker->cur_value : value; /*Can't be greater than the right value*/

    if (rocker->start_value == value) return;
    lv_rocker_set_value_with_anim(obj, value, &rocker->start_value, &rocker->start_value_anim, anim);
}

void lv_rocker_set_range(lv_obj_t* obj, int32_t min, int32_t max)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);

    lv_rocker_t* rocker = (lv_rocker_t*)obj;

    if (rocker->min_value == min && rocker->max_value == max) return;

    rocker->max_value = max;
    rocker->min_value = min;

    if (lv_rocker_get_mode(obj) != LV_ROCKER_MODE_RANGE)
        rocker->start_value = min;

    if (rocker->cur_value > max) {
        rocker->cur_value = max;
        lv_rocker_set_value(obj, rocker->cur_value, LV_ANIM_OFF);
    }
    if (rocker->cur_value < min) {
        rocker->cur_value = min;
        lv_rocker_set_value(obj, rocker->cur_value, LV_ANIM_OFF);
    }
    lv_obj_invalidate(obj);
}

void lv_rocker_set_mode(lv_obj_t* obj, lv_rocker_mode_t mode)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);
    lv_rocker_t* rocker = (lv_rocker_t*)obj;

    rocker->mode = mode;
    if (rocker->mode != LV_ROCKER_MODE_RANGE) {
        rocker->start_value = rocker->min_value;
    }

    lv_obj_invalidate(obj);
}

/*=====================
 * Getter functions
 *====================*/

int32_t lv_rocker_get_value(const lv_obj_t* obj)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);
    lv_rocker_t* rocker = (lv_rocker_t*)obj;

    return LV_ROCKER_GET_ANIM_VALUE(rocker->cur_value, rocker->cur_value_anim);
}

int32_t lv_rocker_get_start_value(const lv_obj_t* obj)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);
    lv_rocker_t* rocker = (lv_rocker_t*)obj;

    if (rocker->mode != LV_ROCKER_MODE_RANGE) return rocker->min_value;

    return LV_ROCKER_GET_ANIM_VALUE(rocker->start_value, rocker->start_value_anim);
}

int32_t lv_rocker_get_min_value(const lv_obj_t* obj)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);
    lv_rocker_t* rocker = (lv_rocker_t*)obj;
    return rocker->min_value;
}

int32_t lv_rocker_get_max_value(const lv_obj_t* obj)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);
    lv_rocker_t* rocker = (lv_rocker_t*)obj;

    return rocker->max_value;
}

lv_rocker_mode_t lv_rocker_get_mode(lv_obj_t* obj)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);
    lv_rocker_t* rocker = (lv_rocker_t*)obj;

    return rocker->mode;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void lv_rocker_constructor(const lv_obj_class_t* class_p, lv_obj_t* obj)
{
    LV_UNUSED(class_p);
    LV_LOG_USER("begin");

    lv_rocker_t* rocker = (lv_rocker_t*)obj;
    rocker->min_value = 0;
    rocker->max_value = 100;
    rocker->start_value = 0;
    rocker->cur_value = 0;
    rocker->indic_area.x1 = 0;
    rocker->indic_area.x2 = 0;
    rocker->indic_area.y1 = 0;
    rocker->indic_area.y2 = 0;
    rocker->mode = LV_ROCKER_MODE_NORMAL;

    lv_rocker_init_anim(obj, &rocker->cur_value_anim);
    lv_rocker_init_anim(obj, &rocker->start_value_anim);

    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_rocker_set_value(obj, 0, LV_ANIM_OFF);

    LV_LOG_USER("finished");
}

static void lv_rocker_destructor(const lv_obj_class_t* class_p, lv_obj_t* obj)
{
    LV_UNUSED(class_p);
    lv_rocker_t* rocker = (lv_rocker_t*)obj;

    lv_anim_del(&rocker->cur_value_anim, NULL);
    lv_anim_del(&rocker->start_value_anim, NULL);
}

static void draw_indic(lv_event_t* e)
{
    lv_obj_t* obj = lv_event_get_target(e);
    lv_rocker_t* rocker = (lv_rocker_t*)obj;

    lv_draw_ctx_t* draw_ctx = lv_event_get_draw_ctx(e);

    lv_area_t rocker_coords;
    lv_obj_get_coords(obj, &rocker_coords);

    lv_coord_t transf_w = lv_obj_get_style_transform_width(obj, LV_PART_MAIN);
    lv_coord_t transf_h = lv_obj_get_style_transform_height(obj, LV_PART_MAIN);
    rocker_coords.x1 -= transf_w;
    rocker_coords.x2 += transf_w;
    rocker_coords.y1 -= transf_h;
    rocker_coords.y2 += transf_h;
    lv_coord_t rockerw = lv_area_get_width(&rocker_coords);
    lv_coord_t rockerh = lv_area_get_height(&rocker_coords);
    int32_t range = rocker->max_value - rocker->min_value;
    bool hor = rockerw >= rockerh ? true : false;
    bool sym = false;
    if (rocker->mode == LV_ROCKER_MODE_SYMMETRICAL && rocker->min_value < 0 && rocker->max_value > 0 &&
        rocker->start_value == rocker->min_value) sym = true;

    /*Calculate the indicator area*/
    lv_coord_t bg_left = lv_obj_get_style_pad_left(obj, LV_PART_MAIN);
    lv_coord_t bg_right = lv_obj_get_style_pad_right(obj, LV_PART_MAIN);
    lv_coord_t bg_top = lv_obj_get_style_pad_top(obj, LV_PART_MAIN);
    lv_coord_t bg_bottom = lv_obj_get_style_pad_bottom(obj, LV_PART_MAIN);
    /*Respect padding and minimum width/height too*/
    lv_area_copy(&rocker->indic_area, &rocker_coords);
    rocker->indic_area.x1 += bg_left;
    rocker->indic_area.x2 -= bg_right;
    rocker->indic_area.y1 += bg_top;
    rocker->indic_area.y2 -= bg_bottom;

    if (hor && lv_area_get_height(&rocker->indic_area) < LV_ROCKER_SIZE_MIN) {
        rocker->indic_area.y1 = obj->coords.y1 + (rockerh / 2) - (LV_ROCKER_SIZE_MIN / 2);
        rocker->indic_area.y2 = rocker->indic_area.y1 + LV_ROCKER_SIZE_MIN;
    }
    else if (!hor && lv_area_get_width(&rocker->indic_area) < LV_ROCKER_SIZE_MIN) {
        rocker->indic_area.x1 = obj->coords.x1 + (rockerw / 2) - (LV_ROCKER_SIZE_MIN / 2);
        rocker->indic_area.x2 = rocker->indic_area.x1 + LV_ROCKER_SIZE_MIN;
    }

    lv_coord_t indicw = lv_area_get_width(&rocker->indic_area);
    lv_coord_t indich = lv_area_get_height(&rocker->indic_area);

    /*Calculate the indicator length*/
    lv_coord_t anim_length = hor ? indicw : indich;

    lv_coord_t anim_cur_value_x, anim_start_value_x;

    lv_coord_t* axis1, * axis2;
    lv_coord_t(*indic_length_calc)(const lv_area_t * area);

    if (hor) {
        axis1 = &rocker->indic_area.x1;
        axis2 = &rocker->indic_area.x2;
        indic_length_calc = lv_area_get_width;
    }
    else {
        axis1 = &rocker->indic_area.y1;
        axis2 = &rocker->indic_area.y2;
        indic_length_calc = lv_area_get_height;
    }

    if (LV_ROCKER_IS_ANIMATING(rocker->start_value_anim)) {
        lv_coord_t anim_start_value_start_x =
            (int32_t)((int32_t)anim_length * (rocker->start_value_anim.anim_start - rocker->min_value)) / range;
        lv_coord_t anim_start_value_end_x =
            (int32_t)((int32_t)anim_length * (rocker->start_value_anim.anim_end - rocker->min_value)) / range;

        anim_start_value_x = (((anim_start_value_end_x - anim_start_value_start_x) * rocker->start_value_anim.anim_state) /
            LV_ROCKER_ANIM_STATE_END);

        anim_start_value_x += anim_start_value_start_x;
    }
    else {
        anim_start_value_x = (int32_t)((int32_t)anim_length * (rocker->start_value - rocker->min_value)) / range;
    }

    if (LV_ROCKER_IS_ANIMATING(rocker->cur_value_anim)) {
        lv_coord_t anim_cur_value_start_x =
            (int32_t)((int32_t)anim_length * (rocker->cur_value_anim.anim_start - rocker->min_value)) / range;
        lv_coord_t anim_cur_value_end_x =
            (int32_t)((int32_t)anim_length * (rocker->cur_value_anim.anim_end - rocker->min_value)) / range;

        anim_cur_value_x = anim_cur_value_start_x + (((anim_cur_value_end_x - anim_cur_value_start_x) *
            rocker->cur_value_anim.anim_state) /
            LV_ROCKER_ANIM_STATE_END);
    }
    else {
        anim_cur_value_x = (int32_t)((int32_t)anim_length * (rocker->cur_value - rocker->min_value)) / range;
    }

    lv_base_dir_t base_dir = lv_obj_get_style_base_dir(obj, LV_PART_MAIN);
    if (hor && base_dir == LV_BASE_DIR_RTL) {
        /*Swap axes*/
        lv_coord_t* tmp;
        tmp = axis1;
        axis1 = axis2;
        axis2 = tmp;
        anim_cur_value_x = -anim_cur_value_x;
        anim_start_value_x = -anim_start_value_x;
    }

    /*Set the indicator length*/
    if (hor) {
        *axis2 = *axis1 + anim_cur_value_x;
        *axis1 += anim_start_value_x;
    }
    else {
        *axis1 = *axis2 - anim_cur_value_x + 1;
        *axis2 -= anim_start_value_x;
    }
    if (sym) {
        lv_coord_t zero, shift;
        shift = (-rocker->min_value * anim_length) / range;
        if (hor) {
            zero = *axis1 + shift;
            if (*axis2 > zero)
                *axis1 = zero;
            else {
                *axis1 = *axis2;
                *axis2 = zero;
            }
        }
        else {
            zero = *axis2 - shift + 1;
            if (*axis1 > zero)
                *axis2 = zero;
            else {
                *axis2 = *axis1;
                *axis1 = zero;
            }
            if (*axis2 < *axis1) {
                /*swap*/
                zero = *axis1;
                *axis1 = *axis2;
                *axis2 = zero;
            }
        }
    }

    /*Do not draw a zero length indicator but at least call the draw part events*/
    if (!sym && indic_length_calc(&rocker->indic_area) <= 1) {

        lv_obj_draw_part_dsc_t part_draw_dsc;
        lv_obj_draw_dsc_init(&part_draw_dsc, draw_ctx);
        part_draw_dsc.part = LV_PART_INDICATOR;
        part_draw_dsc.class_p = MY_CLASS;
        part_draw_dsc.type = LV_ROCKER_DRAW_PART_INDICATOR;
        part_draw_dsc.draw_area = &rocker->indic_area;

        lv_event_send(obj, LV_EVENT_DRAW_PART_BEGIN, &part_draw_dsc);
        lv_event_send(obj, LV_EVENT_DRAW_PART_END, &part_draw_dsc);
        return;
    }

    lv_area_t indic_area;
    lv_area_copy(&indic_area, &rocker->indic_area);

    lv_draw_rect_dsc_t draw_rect_dsc;
    lv_draw_rect_dsc_init(&draw_rect_dsc);
    lv_obj_init_draw_rect_dsc(obj, LV_PART_INDICATOR, &draw_rect_dsc);

    lv_obj_draw_part_dsc_t part_draw_dsc;
    lv_obj_draw_dsc_init(&part_draw_dsc, draw_ctx);
    part_draw_dsc.part = LV_PART_INDICATOR;
    part_draw_dsc.class_p = MY_CLASS;
    part_draw_dsc.type = LV_ROCKER_DRAW_PART_INDICATOR;
    part_draw_dsc.rect_dsc = &draw_rect_dsc;
    part_draw_dsc.draw_area = &rocker->indic_area;

    lv_event_send(obj, LV_EVENT_DRAW_PART_BEGIN, &part_draw_dsc);

    lv_coord_t bg_radius = lv_obj_get_style_radius(obj, LV_PART_MAIN);
    lv_coord_t short_side = LV_MIN(rockerw, rockerh);
    if (bg_radius > short_side >> 1) bg_radius = short_side >> 1;

    lv_coord_t indic_radius = draw_rect_dsc.radius;
    short_side = LV_MIN(indicw, indich);
    if (indic_radius > short_side >> 1) indic_radius = short_side >> 1;

    /*Draw only the shadow and outline only if the indicator is long enough.
     *The radius of the bg and the indicator can make a strange shape where
     *it'd be very difficult to draw shadow.*/
    if ((hor && lv_area_get_width(&rocker->indic_area) > indic_radius * 2) ||
        (!hor && lv_area_get_height(&rocker->indic_area) > indic_radius * 2)) {
        lv_opa_t bg_opa = draw_rect_dsc.bg_opa;
        lv_opa_t bg_img_opa = draw_rect_dsc.bg_img_opa;
        lv_opa_t border_opa = draw_rect_dsc.border_opa;
        draw_rect_dsc.bg_opa = LV_OPA_TRANSP;
        draw_rect_dsc.bg_img_opa = LV_OPA_TRANSP;
        draw_rect_dsc.border_opa = LV_OPA_TRANSP;

        lv_draw_rect(draw_ctx, &draw_rect_dsc, &rocker->indic_area);

        draw_rect_dsc.bg_opa = bg_opa;
        draw_rect_dsc.bg_img_opa = bg_img_opa;
        draw_rect_dsc.border_opa = border_opa;
    }

#if LV_DRAW_COMPLEX
    lv_draw_mask_radius_param_t mask_bg_param;
    lv_area_t bg_mask_area;
    bg_mask_area.x1 = obj->coords.x1 + bg_left;
    bg_mask_area.x2 = obj->coords.x2 - bg_right;
    bg_mask_area.y1 = obj->coords.y1 + bg_top;
    bg_mask_area.y2 = obj->coords.y2 - bg_bottom;

    lv_draw_mask_radius_init(&mask_bg_param, &bg_mask_area, bg_radius, false);
    lv_coord_t mask_bg_id = lv_draw_mask_add(&mask_bg_param, NULL);
#endif

    /*Draw_only the background and background image*/
    lv_opa_t shadow_opa = draw_rect_dsc.shadow_opa;
    lv_opa_t border_opa = draw_rect_dsc.border_opa;
    draw_rect_dsc.border_opa = LV_OPA_TRANSP;
    draw_rect_dsc.shadow_opa = LV_OPA_TRANSP;

    /*Get the max possible indicator area. The gradient should be applied on this*/
    lv_area_t mask_indic_max_area;
    lv_area_copy(&mask_indic_max_area, &rocker_coords);
    mask_indic_max_area.x1 += bg_left;
    mask_indic_max_area.y1 += bg_top;
    mask_indic_max_area.x2 -= bg_right;
    mask_indic_max_area.y2 -= bg_bottom;
    if (hor && lv_area_get_height(&mask_indic_max_area) < LV_ROCKER_SIZE_MIN) {
        mask_indic_max_area.y1 = obj->coords.y1 + (rockerh / 2) - (LV_ROCKER_SIZE_MIN / 2);
        mask_indic_max_area.y2 = mask_indic_max_area.y1 + LV_ROCKER_SIZE_MIN;
    }
    else if (!hor && lv_area_get_width(&mask_indic_max_area) < LV_ROCKER_SIZE_MIN) {
        mask_indic_max_area.x1 = obj->coords.x1 + (rockerw / 2) - (LV_ROCKER_SIZE_MIN / 2);
        mask_indic_max_area.x2 = mask_indic_max_area.x1 + LV_ROCKER_SIZE_MIN;
    }

#if LV_DRAW_COMPLEX
    /*Create a mask to the current indicator area to see only this part from the whole gradient.*/
    lv_draw_mask_radius_param_t mask_indic_param;
    lv_draw_mask_radius_init(&mask_indic_param, &rocker->indic_area, draw_rect_dsc.radius, false);
    int16_t mask_indic_id = lv_draw_mask_add(&mask_indic_param, NULL);
#endif

    lv_draw_rect(draw_ctx, &draw_rect_dsc, &mask_indic_max_area);
    draw_rect_dsc.border_opa = border_opa;
    draw_rect_dsc.shadow_opa = shadow_opa;

    /*Draw the border*/
    draw_rect_dsc.bg_opa = LV_OPA_TRANSP;
    draw_rect_dsc.bg_img_opa = LV_OPA_TRANSP;
    draw_rect_dsc.shadow_opa = LV_OPA_TRANSP;
    lv_draw_rect(draw_ctx, &draw_rect_dsc, &rocker->indic_area);

#if LV_DRAW_COMPLEX
    lv_draw_mask_free_param(&mask_indic_param);
    lv_draw_mask_free_param(&mask_bg_param);
    lv_draw_mask_remove_id(mask_indic_id);
    lv_draw_mask_remove_id(mask_bg_id);
#endif

    lv_event_send(obj, LV_EVENT_DRAW_PART_END, &part_draw_dsc);
}

static void lv_rocker_event(const lv_obj_class_t* class_p, lv_event_t* e)
{
    LV_UNUSED(class_p);

    lv_res_t res;

    /*Call the ancestor's event handler*/
    res = lv_obj_event_base(MY_CLASS, e);
    if (res != LV_RES_OK) return;

    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* obj = lv_event_get_target(e);

    if (code == LV_EVENT_REFR_EXT_DRAW_SIZE) {
        lv_coord_t indic_size;
        indic_size = lv_obj_calculate_ext_draw_size(obj, LV_PART_INDICATOR);

        /*Bg size is handled by lv_obj*/
        lv_coord_t* s = lv_event_get_param(e);
        *s = LV_MAX(*s, indic_size);

        /*Calculate the indicator area*/
        lv_coord_t bg_left = lv_obj_get_style_pad_left(obj, LV_PART_MAIN);
        lv_coord_t bg_right = lv_obj_get_style_pad_right(obj, LV_PART_MAIN);
        lv_coord_t bg_top = lv_obj_get_style_pad_top(obj, LV_PART_MAIN);
        lv_coord_t bg_bottom = lv_obj_get_style_pad_bottom(obj, LV_PART_MAIN);

        lv_coord_t pad = LV_MIN4(bg_left, bg_right, bg_top, bg_bottom);
        if (pad < 0) {
            *s = LV_MAX(*s, -pad);
        }
    }
    else if (code == LV_EVENT_PRESSED || code == LV_EVENT_RELEASED) {
        lv_rocker_t* rocker = (lv_rocker_t*)obj;
        lv_obj_invalidate_area(obj, &rocker->indic_area);
    }
    else if (code == LV_EVENT_DRAW_MAIN) {
        draw_indic(e);
        LV_LOG_USER("Draw bar");
    }
}

static void lv_rocker_anim(void* var, int32_t value)
{
    _lv_rocker_anim_t* rocker_anim = var;
    rocker_anim->anim_state = value;
    lv_obj_invalidate(rocker_anim->rocker);
}

static void lv_rocker_anim_ready(lv_anim_t* a)
{
    _lv_rocker_anim_t* var = a->var;
    lv_obj_t* obj = (lv_obj_t*)var->rocker;
    lv_rocker_t* rocker = (lv_rocker_t*)obj;

    var->anim_state = LV_ROCKER_ANIM_STATE_INV;
    if (var == &rocker->cur_value_anim)
        rocker->cur_value = var->anim_end;
    else if (var == &rocker->start_value_anim)
        rocker->start_value = var->anim_end;
    lv_obj_invalidate(var->rocker);
}

static void lv_rocker_set_value_with_anim(lv_obj_t* obj, int32_t new_value, int32_t* value_ptr,
    _lv_rocker_anim_t* anim_info, lv_anim_enable_t en)
{
    if (en == LV_ANIM_OFF) {
        *value_ptr = new_value;
        lv_obj_invalidate((lv_obj_t*)obj);
    }
    else {
        /*No animation in progress -> simply set the values*/
        if (anim_info->anim_state == LV_ROCKER_ANIM_STATE_INV) {
            anim_info->anim_start = *value_ptr;
            anim_info->anim_end = new_value;
        }
        /*Animation in progress. Start from the animation end value*/
        else {
            anim_info->anim_start = anim_info->anim_end;
            anim_info->anim_end = new_value;
        }
        *value_ptr = new_value;
        /*Stop the previous animation if it exists*/
        lv_anim_del(anim_info, NULL);

        lv_anim_t a;
        lv_anim_init(&a);
        lv_anim_set_var(&a, anim_info);
        lv_anim_set_exec_cb(&a, lv_rocker_anim);
        lv_anim_set_values(&a, LV_ROCKER_ANIM_STATE_START, LV_ROCKER_ANIM_STATE_END);
        lv_anim_set_ready_cb(&a, lv_rocker_anim_ready);
        lv_anim_set_time(&a, lv_obj_get_style_anim_time(obj, LV_PART_MAIN));
        lv_anim_start(&a);
    }
}

static void lv_rocker_init_anim(lv_obj_t* obj, _lv_rocker_anim_t* rocker_anim)
{
    rocker_anim->rocker = obj;
    rocker_anim->anim_start = 0;
    rocker_anim->anim_end = 0;
    rocker_anim->anim_state = LV_ROCKER_ANIM_STATE_INV;
}

#endif
