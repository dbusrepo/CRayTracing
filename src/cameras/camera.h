#pragma once
#include "../worlds/world.h"

typedef struct camera camera_t;

struct camera_vtable {
    void (*render_scene)(camera_t *camera, world_t *world);
};

typedef struct camera_vtable camera_vtable_t;

struct camera {
    camera_vtable_t *vtable;
};

inline void camera_render_scene(camera_t *camera, world_t *world) {
    camera->vtable->render_scene(camera, world);
}
