#pragma once
#include "camera.h"

struct orthographic_camera {
    camera_t super;
};

typedef struct orthographic_camera orthographic_camera_t;

void orthographic_camera_init(orthographic_camera_t *camera);
