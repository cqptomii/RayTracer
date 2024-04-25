#include <iostream>
#include "color.h"

using namespace std;
int main() {
    // Image properties

    int image_width = 400;
    int image_height = 400;

    // Render

    for(int j = 0; j < image_height; j++){
        for(int i = 0; i < image_width; i++){
            std::clog << "Scanline : " << i << std::endl;
            auto pixel_color = Vec3d(double(i)/(image_width-1), double(j)/(image_height-1), 0);
            write_color(std::cout, pixel_color);
        }
        std::clog << "Done" << std::endl;
    }
    return 0;
}
