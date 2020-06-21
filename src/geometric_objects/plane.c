#include "plane.h"

static bool plane_hit(geometric_object_t *obj, ray_t *ray, float *t, shade_rec_t *sr) {
    // cast obj ?
    return false;
}

geometric_object_vtable_t plane_vtable = {
    &plane_hit
};

void plane_init(plane_t *plane) {
    plane->super.vtable = &plane_vtable;
    // init base members plane->super.
    // init derived members
}
