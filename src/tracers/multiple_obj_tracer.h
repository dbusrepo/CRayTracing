#pragma once
#include "tracer.h"

struct multiple_obj_tracer {
    tracer_t super;
};

typedef struct multiple_obj_tracer multiple_obj_tracer_t;

void multiple_obj_tracer_init(multiple_obj_tracer_t *tracer, world_t *world);
