#include "sphere.h"

static bool sphere_hit(geometric_object_t *obj, ray_t *ray, float *tmin, shade_rec_t *sr);

geometric_object_vtable_t sphere_vtable = {
        &sphere_hit
};

void sphere_init(sphere_t *sphere, point3_t *c, real r) {
    sphere->super.vtable = &sphere_vtable;
    point3_copy(&sphere->center, c);
    sphere->radius = r;
}

static void calc_hit_point(ray_t *ray, float *tmin, shade_rec_t *sr, sphere_t *sphere, vec3_t *tmp, float t);

static bool sphere_hit(geometric_object_t *obj, ray_t *ray, float *tmin, shade_rec_t *sr) {
    sphere_t *sphere = (sphere_t *) obj;
    vec3_t tmp;
    point3_sub(&tmp, &ray->o, &sphere->center);
    real a = vec3_len_sqr(&ray->d);
    real b = 2.0 - vec3_dot(&tmp, &ray->d);
    real c = vec3_len_sqr(&tmp) - sphere->radius * sphere->radius;
    real disc = b * b - 4.0 * a * c;

    if (disc < 0) {
        return false;
    } else {
        real e = sqrt(disc);
        float denom = 2.0 * a;
        float t = (-b - e) / denom; // smaller root

        if (t > EPS) {
            calc_hit_point(ray, tmin, sr, sphere, &tmp, t);
            return true;
        }

        t = (-b + e) / denom;

        if (t > EPS) {
            calc_hit_point(ray, tmin, sr, sphere, &tmp, t);
            return true;
        }
    }
}

static void calc_hit_point(ray_t *ray, float *tmin, shade_rec_t *sr, sphere_t *sphere, vec3_t *tmp, float t) {
    *tmin = t;
    vec3_t dt;
    vec3_scale(&dt, &ray->d, t);
    vec3_t n;
    vec3_add(&n, tmp, &dt);
    vec3_cscale(&n, 1 / sphere->radius);
    normal_init_vec3(&sr->normal, &n);
    point3_add_vec(&sr->world_hit_point, &ray->o, &dt);
}
