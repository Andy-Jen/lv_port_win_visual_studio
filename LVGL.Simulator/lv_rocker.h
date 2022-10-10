/**
 * @file lv_rocker.h
 *
 */

#ifndef LV_rocker_H
#define LV_rocker_H

#ifdef __cplusplus
extern "C" {
#endif

    /*********************
     *      INCLUDES
     *********************/
#include "../lv_conf_internal.h"

#if LV_USE_ROCKER != 0

#include "../core/lv_obj.h"
#include "../misc/lv_anim.h"
#include "lv_btn.h"
#include "lv_label.h"

     /*********************
      *      DEFINES
      *********************/

      /**********************
       *      TYPEDEFS
       **********************/

    enum {
        LV_ROCKER_MODE_NORMAL,
        LV_ROCKER_MODE_SYMMETRICAL,
        LV_ROCKER_MODE_RANGE
    };
    typedef uint8_t lv_rocker_mode_t;

    typedef struct {
        lv_obj_t* rocker;
        int32_t anim_start;
        int32_t anim_end;
        int32_t anim_state;
    } _lv_rocker_anim_t;

    typedef struct {
        lv_obj_t obj;
        int32_t cur_value;          /**< Current value of the rocker*/
        int32_t min_value;          /**< Minimum value of the rocker*/
        int32_t max_value;          /**< Maximum value of the rocker*/
        int32_t start_value;        /**< Start value of the rocker*/
        lv_area_t indic_area;       /**< Save the indicator area. Might be used by derived types*/
        _lv_rocker_anim_t cur_value_anim;
        _lv_rocker_anim_t start_value_anim;
        lv_rocker_mode_t mode : 2;     /**< Type of rocker*/
    } lv_rocker_t;

    extern const lv_obj_class_t lv_rocker_class;

    /**
     * `type` field in `lv_obj_draw_part_dsc_t` if `class_p = lv_rocker_class`
     * Used in `LV_EVENT_DRAW_PART_BEGIN` and `LV_EVENT_DRAW_PART_END`
     */
    typedef enum {
        LV_ROCKER_DRAW_PART_INDICATOR,    /**< The indicator*/
    } lv_rocker_draw_part_type_t;

    /**********************
     * GLOBAL PROTOTYPES
     **********************/

     /**
      * Create a rocker object
      * @param parent    pointer to an object, it will be the parent of the new rocker
      * @return          pointer to the created rocker
      */
    lv_obj_t* lv_rocker_create(lv_obj_t* parent);

    /*=====================
     * Setter functions
     *====================*/

     /**
      * Set a new value on the rocker
      * @param rocker       pointer to a rocker object
      * @param value     new value
      * @param anim      LV_ANIM_ON: set the value with an animation; LV_ANIM_OFF: change the value immediately
      */
    void lv_rocker_set_value(lv_obj_t* obj, int32_t value, lv_anim_enable_t anim);

    /**
     * Set a new start value on the rocker
     * @param obj       pointer to a rocker object
     * @param value     new start value
     * @param anim      LV_ANIM_ON: set the value with an animation; LV_ANIM_OFF: change the value immediately
     */
    void lv_rocker_set_start_value(lv_obj_t* obj, int32_t start_value, lv_anim_enable_t anim);

    /**
     * Set minimum and the maximum values of a rocker
     * @param obj       pointer to the rocker object
     * @param min       minimum value
     * @param max       maximum value
     */
    void lv_rocker_set_range(lv_obj_t* obj, int32_t min, int32_t max);

    /**
     * Set the type of rocker.
     * @param obj       pointer to rocker object
     * @param mode      rocker type from ::lv_rocker_mode_t
     */
    void lv_rocker_set_mode(lv_obj_t* obj, lv_rocker_mode_t mode);

    /*=====================
     * Getter functions
     *====================*/

     /**
      * Get the value of a rocker
      * @param obj       pointer to a rocker object
      * @return          the value of the rocker
      */
    int32_t lv_rocker_get_value(const lv_obj_t* obj);

    /**
     * Get the start value of a rocker
     * @param obj       pointer to a rocker object
     * @return          the start value of the rocker
     */
    int32_t lv_rocker_get_start_value(const lv_obj_t* obj);

    /**
     * Get the minimum value of a rocker
     * @param obj       pointer to a rocker object
     * @return          the minimum value of the rocker
     */
    int32_t lv_rocker_get_min_value(const lv_obj_t* obj);

    /**
     * Get the maximum value of a rocker
     * @param obj       pointer to a rocker object
     * @return          the maximum value of the rocker
     */
    int32_t lv_rocker_get_max_value(const lv_obj_t* obj);

    /**
     * Get the type of rocker.
     * @param obj       pointer to rocker object
     * @return          rocker type from ::lv_rocker_mode_t
     */
    lv_rocker_mode_t lv_rocker_get_mode(lv_obj_t* obj);

    /**********************
     *      MACROS
     **********************/

#endif /*LV_USE_ROCKER*/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_rocker_H*/
