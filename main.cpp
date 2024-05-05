#include "ToolKit.hpp"
#include "Hittable_List.h"
#include "Sphere.hpp"
#include "Camera.hpp"
#include "Material.hpp"
#include "Lambertian.hpp"
#include "Metal.hpp"
#include "Dielectric.hpp"
using namespace std;
int main() {
    Hittable_List world;
        // Objects in World

    auto ground_material = make_shared<Lambertian>(color(0.5, 0.5, 0.5));
    world.add(make_shared<Sphere>(point3d(0,-1000,0), 1000, ground_material));

    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            auto choose_mat = random_number();
            point3d center(a + 0.9*random_number(), 0.2, b + 0.9*random_number());

            if ((center - point3d(4, 0.2, 0)).length() > 0.9) {
                shared_ptr<Material> sphere_material;

                if (choose_mat < 0.8) {
                    // diffuse
                    auto albedo = random() * random();
                    sphere_material = make_shared<Lambertian>(albedo);
                    world.add(make_shared<Sphere>(center, 0.2, sphere_material));
                } else if (choose_mat < 0.95) {
                    // metal
                    auto albedo = random(0.5, 1);
                    auto fuzz = random_number(0, 0.5);
                    sphere_material = make_shared<Metal>(albedo, fuzz);
                    world.add(make_shared<Sphere>(center, 0.2, sphere_material));
                } else {
                    // glass
                    sphere_material = make_shared<Dielectric>(1.5);
                    world.add(make_shared<Sphere>(center, 0.2, sphere_material));
                }
            }
        }
    }

    auto material1 = make_shared<Dielectric>(1.5);
    world.add(make_shared<Sphere>(point3d(0, 1, 0), 1.0, material1));

    auto material2 = make_shared<Lambertian>(color(0.4, 0.2, 0.1));
    world.add(make_shared<Sphere>(point3d(-4, 1, 0), 1.0, material2));

    auto material3 = make_shared<Metal>(color(0.7, 0.6, 0.5), 0.1);
    world.add(make_shared<Sphere>(point3d(4, 1, 0), 1.0, material3));

    Camera cam;
    Vec3d origin = Vec3d(13,2,-3);
    Vec3d direction = Vec3d(0,0,0);

        // Image Rendered properties
    cam.set_aspect_ratio(16.0/9.0);
    cam.set_image_width(1200);
    cam.set_sample_amount(20);
    cam.set_diffuse_reflection_amount(50);
    cam.set_fov(20);
    cam.set_origin(origin);
    cam.set_direction(direction);
    cam.set_defocus_angle(0.6);
    cam.set_defocus_distance(10);

    cam.render(world);
    return 0;
}
