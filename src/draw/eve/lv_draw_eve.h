#ifndef LV_DRAW_EVE_H_
#define LV_DRAW_EVE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "../lv_draw.h"

#if LV_USE_DRAW_EVE

typedef struct {
    lv_draw_unit_t base_unit;
    lv_draw_task_t* task_act;
    void* eve;
} lv_draw_eve_unit_t;

void lv_draw_eve_init(void (*cb)(lv_draw_eve_unit_t*));

#endif /*LV_USE_DRAW_EVE*/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /* LV_DRAW_EVE_H_ */
