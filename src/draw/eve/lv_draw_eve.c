#include "../lv_draw.h"

#if LV_USE_DRAW_EVE
#include "lv_draw_eve.h"

#define DRAW_UNIT_ID_EVE 18

static void (*drawing_cb)(lv_draw_eve_unit_t*) = NULL;

static int32_t eve_dispatch(lv_draw_unit_t* draw_unit, lv_layer_t* layer)
{
    lv_draw_eve_unit_t* draw_eve_unit = (lv_draw_eve_unit_t*)draw_unit;

    /*Return immediately if it's busy with draw task*/
    if(draw_eve_unit->task_act)
    {
        return 0;
    }

    lv_draw_task_t* t = NULL;
    t = lv_draw_get_next_available_task(layer, NULL, DRAW_UNIT_ID_EVE);
    if(t == NULL)
    {
        return -1;
    }

    t->state = LV_DRAW_TASK_STATE_IN_PROGRESS;
    draw_eve_unit->base_unit.target_layer = layer;
    draw_eve_unit->base_unit.clip_area = &t->clip_area;
    draw_eve_unit->task_act = t;

    drawing_cb(draw_eve_unit);

    draw_eve_unit->task_act->state = LV_DRAW_TASK_STATE_READY;
    draw_eve_unit->task_act = NULL;

    /*The draw unit is free now. Request a new dispatching as it can get a new task*/
    lv_draw_dispatch_request();

    return 1;
}

static int32_t eve_evaluate(lv_draw_unit_t* draw_unit, lv_draw_task_t* task)
{
    LV_UNUSED(draw_unit);

    if(((lv_draw_dsc_base_t*)task->draw_dsc)->user_data == NULL) {
        task->preference_score = 0;
        task->preferred_draw_unit_id = DRAW_UNIT_ID_EVE;
    }
    return 0;
}

void lv_draw_eve_init(void (*cb)(lv_draw_eve_unit_t*))
{
    drawing_cb = cb;

    lv_draw_eve_unit_t* draw_eve_unit = lv_draw_create_unit(sizeof(lv_draw_eve_unit_t));
    draw_eve_unit->base_unit.dispatch_cb = eve_dispatch;
    draw_eve_unit->base_unit.evaluate_cb = eve_evaluate;
}

#endif /*LV_USE_DRAW_EVE*/
