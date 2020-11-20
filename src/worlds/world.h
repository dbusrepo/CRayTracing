#pragma once
#include <stdlib.h>
#include "../utilities/view_plane.h"
#include "../utilities/rgb_color.h"

typedef struct tracer tracer_t;
typedef struct camera camera_t;
typedef struct geometric_object geometric_object_t;

struct world
{
    tracer_t *tracer;
    camera_t *camera;

	view_plane_t view_plane;
	rgb_color_t background_color;

	size_t num_objects;
    geometric_object_t *objects;
};

typedef struct world world_t;

// hit_objects
// delete objs
//