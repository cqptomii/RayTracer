//
// Created by tomfr on 26/04/2024.
//

#ifndef RAYTRACER_VEC3D_HPP
#define RAYTRACER_VEC3D_HPP
#include "iostream"
#include "cmath"

class Vec3d {
    public:
        double e[3];
        Vec3d();
        Vec3d(double x,double y,double z);
        double x() const;
        double y() const;
        double z() const ;
        Vec3d operator- ()const;
        double operator[] (int i) const;
        double& operator[](int i);
        Vec3d operator+=(const Vec3d& u);
        Vec3d operator*=(double t);
        Vec3d operator/=(double t);

        double lengthSquare() const;
        double length() const;
        void toString(std::string name);
};
using point3d = Vec3d;
// operator
Vec3d operator+ (const Vec3d& u, const Vec3d& v);
Vec3d operator- (const Vec3d& u,const Vec3d& v);
Vec3d operator* (const Vec3d& u,const Vec3d& v);
Vec3d operator* (double t,const Vec3d& u);
Vec3d operator* (const Vec3d& u, double t);
Vec3d operator/ (const Vec3d& u,double t);
double dot(const Vec3d& u, const Vec3d& v);
Vec3d cross(const Vec3d& u, const Vec3d& v);
Vec3d unit_vector(const Vec3d& u);

Vec3d random();
Vec3d random(double min, double max);
Vec3d random_vector_in_unit_sphere();
Vec3d random_in_hemisphere(Vec3d& p);
Vec3d random_lambertian_reflection(Vec3d &normal_p);
#endif //RAYTRACER_VEC3D_HPP
