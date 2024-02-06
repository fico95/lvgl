/**
 * @file lv_init.h
 *
 */

#ifndef LV_INIT_H
#define LV_INIT_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdbool.h>
#include "lv_conf_internal.h"

#if LV_USE_DRAW_EVE
#include "draw/eve/lv_draw_eve.h"
#endif
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Initialize LVGL library.
 * Should be called before any other LVGL related function.
 */
#if LV_USE_DRAW_EVE
void lv_init(void (*cb)(lv_draw_eve_unit_t*));
#else
void lv_init(void);
#endif

/**
 * Deinit the 'lv' library
 */
void lv_deinit(void);

/**
 * Returns whether the 'lv' library is currently initialized
 */
bool lv_is_initialized(void);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_INIT_H*/
