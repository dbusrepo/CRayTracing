#pragma once
#include "../utilities/point.h"
#include "../utilities/normal.h"
#include "geometric_object.h"

struct plane {
    geometric_object_t super;
    point3_t a; // point through which plane passes
    normal_t n; // normal to the plane
};

typedef struct plane plane_t;

void plane_init(plane_t *plane);
