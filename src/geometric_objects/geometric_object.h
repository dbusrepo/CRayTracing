#pragma once
#include "stdbool.h"
#include "../utilities/rgb_color.h"
#include "../utilities/ray.h"
#include "../utilities/shade_rec.h"

typedef struct geometric_object geometric_object_t;

struct geometric_object_vtable
{
	bool (*hit)(geometric_object_t *obj, ray_t *ray, float *t, shade_rec_t *sr);
};

typedef struct geometric_object_vtable geometric_object_vtable_t;

struct geometric_object
{
    geometric_object_vtable_t *vtable;
    /* base members */
	rgb_color_t color;    // only used for Bare Bones ray tracing
};

inline bool geometric_object_hit(geometric_object_t *obj, ray_t *ray, float *t, shade_rec_t *sr) {
    return obj->vtable->hit(obj, ray, t, sr);
}

//inline rgb_color_t geometric_object_color() {
//}