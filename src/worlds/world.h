#pragma once
#include "../utilities/view_plane.h"
#include "../utilities/rgb_color.h"

struct world
{
	view_plane_t view_plane;
	rgb_color_t background_color;
};

typedef struct world world_t;

// api ??