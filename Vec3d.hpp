//
// Created by tomfr on 26/04/2024.
//

#ifndef RAYTRACER_VEC3D_HPP
#define RAYTRACER_VEC3D_HPP


class Vec3d {
    public:
        double e[3];

        Vec3d();
        Vec3d(double x,double y,double z);
        double x();
        double y();
        double z();
        Vec3d operator- ();
        double operator[] (int i) const;
        double& operator[](int i);
        Vec3d operator+=(const Vec3d& u);
        Vec3d operator*=(double t);
        Vec3d operator/=(double t);

        double lengthSquare() const;
        double length() const;
};

// operator
Vec3d operator+ (const Vec3d& u, const Vec3d& v);
Vec3d operator- (const Vec3d& u,const Vec3d& v);
Vec3d operator* (const Vec3d& u,const Vec3d& v);
Vec3d operator* (double t,const Vec3d& u);
Vec3d operator* (const Vec3d& u, double t);
Vec3d operator/ (double t, const Vec3d& u);
Vec3d dot(const Vec3d& u, const Vec3d& v);
Vec3d cross(const Vec3d& u, const Vec3d& v);
Vec3d unit_vector(Vec3d u);
#endif //RAYTRACER_VEC3D_HPP
