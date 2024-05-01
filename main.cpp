#include "ToolKit.hpp"
#include "Hittable_List.h"
#include "Sphere.hpp"
#include "Camera.hpp"
#include "Material.hpp"
#include "Lambertian.hpp"
#include "Metal.hpp"
using namespace std;
int main() {
    Hittable_List world;
        // Objects in World
    auto material_ground = make_shared<Lambertian>(color(0.8, 0.2, 0.0));
    auto material_center = make_shared<Lambertian>(color(0.1, 0.2, 0.5));

    world.add(make_shared<Sphere>(point3d ( 0.0, -100.5, 1.0), 100.0, material_ground));
    world.add(make_shared<Sphere>(point3d( 0.0, 0.0, 1.2),   0.5, material_center));

    Camera cam;
        // Image Rendered properties
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 400;
    cam.sample_number = 100;
    cam.diffuse_reflection_amount = 50;
    cam.render(world);
    return 0;
}
