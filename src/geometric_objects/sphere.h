#pragma once
#include "../utilities/point.h"
#include "geometric_object.h"

struct sphere {
    geometric_object_t super;
    point3_t center;
    real radius;
};

typedef struct sphere sphere_t;

void sphere_init(sphere_t *sphere, point3_t *c, real r);


