#include "multiple_obj_tracer.h"

static void multiple_obj_trace_ray(tracer_t *tracer, ray_t *ray, rgb_color_t *out_color);

tracer_vtable_t multiple_obj_tracer_vtable = {
        &multiple_obj_trace_ray
};

void multiple_obj_tracer_init(multiple_obj_tracer_t *tracer, world_t *world) {
    tracer->super.vtable = &multiple_obj_tracer_vtable;
}

static void multiple_obj_trace_ray(tracer_t *tracer, ray_t *ray, rgb_color_t *out_color) {
    // TODO
}
