#include "ToolKit.hpp"
#include "Hittable_List.h"
#include "Sphere.hpp"
#include "Camera.hpp"

using namespace std;
int main() {
        // Objects in World
    Hittable_List world;
    world.add(make_shared<Sphere>(point3d(0,0,1),0.5));
    world.add(make_shared<Sphere>(point3d(0,-100.5,1),100));

    Camera cam;
        // Image Rendered properties
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 400;
    cam.sample_number = 100;
    cam.diffuse_reflection_amount = 50;
    cam.render(world);
    return 0;
}
