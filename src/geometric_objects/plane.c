#include "plane.h"
#include "../utilities/constants.h"

static bool plane_hit(geometric_object_t *obj, ray_t *ray, float *tmin, shade_rec_t *sr);

geometric_object_vtable_t plane_vtable = {
    &plane_hit
};

void plane_init(plane_t *plane, point3_t *a, normal_t *n) {
    plane->super.vtable = &plane_vtable;
    point3_copy(&plane->a, a);
    normal_copy(&plane->n, n);
}

static bool plane_hit(geometric_object_t *obj, ray_t *ray, float *tmin, shade_rec_t *sr) {
    plane_t *plane = (plane_t *) obj;
    vec3_t ao;
    point3_sub(&ao, &plane->a, &ray->o);
    real t = vec3_normal_dot(&ao, &plane->n) / vec3_normal_dot(&ray->d, &plane->n);
    if (t > EPS) {
        *tmin = t;
        normal_copy(&sr->normal, &plane->n);
        vec3_t dt;
        vec3_scale(&dt, &ray->d, t);
        point3_add_vec(&sr->world_hit_point, &ray->o, &dt);
        return true;
    }
    return false;
}
