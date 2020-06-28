#include "orthographic_camera.h"

static void render_scene(camera_t *camera, world_t *world);

camera_vtable_t orthographic_camera_vtable = {
        &render_scene
};

void orthographic_camera_init(orthographic_camera_t *camera) {
    camera->super.vtable = &orthographic_camera_vtable;
}

static void render_scene(camera_t *camera, world_t *world) {
    // TODO
}
