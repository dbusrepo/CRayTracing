#pragma once
#include "../utilities/rgb_color.h"
#include "../utilities/ray.h"
#include "../worlds/world.h"

typedef struct tracer tracer_t;

struct tracer_vtable {
    void (*trace_ray)(tracer_t *tracer, ray_t *ray, rgb_color_t *out_color);
};

typedef struct tracer_vtable tracer_vtable_t;

struct tracer {
    tracer_vtable_t *vtable;
    world_t *world;
};

inline void tracer_trace_ray(tracer_t *tracer, ray_t *ray, rgb_color_t *out_color) {
    tracer->vtable->trace_ray(tracer, ray, out_color);
}

