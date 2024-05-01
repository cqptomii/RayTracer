//
// Created by tomfr on 26/04/2024.
//

#include "Vec3d.hpp"
#include "Interval.hpp"
Vec3d::Vec3d() : e{0,0,0}{}

Vec3d::Vec3d(double x, double y, double z) : e{x,y,z} {}
double Vec3d::x() const{
    return e[0];
}

double Vec3d::y() const{
    return e[1];
}

double Vec3d::z() const{
    return e[2];
}

Vec3d Vec3d::operator-() const{
    return {-e[0],-e[1],-e[2]};
}
double Vec3d::operator[](int i) const {
    return e[i];
}
double& Vec3d::operator[](int i) {
    return e[i];
}

Vec3d Vec3d::operator+=(const Vec3d &u) {
    return {e[0]+u.e[0],e[1]+u.e[1],e[2]+u.e[2]};
}

Vec3d Vec3d::operator*=(double t) {
    return {e[0]*t,e[1]*t,e[2]*t};
}

Vec3d Vec3d::operator/=(double t) {
    if(t != 0) {
        return {e[0]/t,e[1]/t,e[2]/t};
    }
    return {0,0,0};
}
double Vec3d::lengthSquare() const {
    return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
}

double Vec3d::length() const{
    return sqrt(lengthSquare());
}

void Vec3d::toString(std::string name) {
    std::cout << name << std::endl;
    std::cout << " X_axis : " << this->e[0] <<  "\n Y_axis : " << this->e[1] << "\n Z-axis : " << this->e[2] << std::endl;
}
bool Vec3d::near_zero(){
    auto value = 1e-6;
    return (fabs(e[0]) < value) && (fabs(e[1]) < value) && (fabs(e[2]) < value);
}

Vec3d operator+ (const Vec3d& u, const Vec3d& v){
    return {u.e[0]+v.e[0],u.e[1]+v.e[1],u.e[2]+v.e[2]};
}
Vec3d operator- (const Vec3d& u,const Vec3d& v){
    return {u.e[0]-v.e[0],u.e[1]-v.e[1],u.e[2]-v.e[2]};
}
Vec3d operator* (const Vec3d& u,const Vec3d& v){
    return {u.e[0]*v.e[0],u.e[1]*v.e[1],u.e[2]*v.e[2]};
}
Vec3d operator* (double t,const Vec3d& u){
    return {u.e[0]*t,u.e[1]*t,u.e[2]*t};
}
Vec3d operator* (const Vec3d& u, double t){
    return t * u;
}
Vec3d operator/ (const Vec3d& u,double t){
    return (1/t) * u;
}

double dot(const Vec3d& u, const Vec3d& v){
    return u.e[0]*v.e[0]+u.e[1]*v.e[1]+u.e[2]*v.e[2];
}
Vec3d cross(const Vec3d& u, const Vec3d& v){
    return {u.e[0]*v.e[0],u.e[1]*v.e[1],u.e[2]*v.e[2]};
}
Vec3d unit_vector(const Vec3d& u){
    return u / u.length() ;
}

Vec3d random() {
    return {random_number(),random_number(),random_number()};
}
Vec3d random(double min, double max) {
    return {random_number(min, max), random_number(min, max), random_number(min, max)};
}
Vec3d random_vector_in_unit_sphere() {
    while(true) {
        auto vec = random(-1, 1);
        if (vec.lengthSquare() <= 1)
            return vec;
    }
}
Vec3d random_in_hemisphere(Vec3d &normal_p) {
    auto vec = random_vector_in_unit_sphere();
    vec = unit_vector(vec);
    if(dot(normal_p,vec) > 0.0){
        return vec;
    }else{
        return -vec;
    }
}
Vec3d random_lambertian_reflection(const Vec3d &normal_p) {
    return (normal_p + random_vector_in_unit_sphere());
}
Vec3d mirror_reflect(const Vec3d& v, const Vec3d& normal){
    // return v - 2*dot(v, normal)*normal;
    return 2*(v+normal) - v;
}