#ifndef SPACE_STUFF_STRUCTS_H
#define SPACE_STUFF_STRUCTS_H

//
// Created by Ethan Nerney on 11/1/18.
//

/*
 * This file declares the structs for RGBColor, RGBAColor, Vector2D, and Vector3D. It also declares several constants,
 * that are highly likely to be used frequently.
 */
#include <math.h>
#include <iostream>
namespace colorGraphics {
    struct RGBColor {
        double r;
        double g;
        double b;

        RGBColor(double red, double green, double blue) {
            r = red;
            g = green;
            b = blue;
        }

        RGBColor(int red, int green, int blue) {
            r = red / 255.;
            g = green / 255.;
            b = blue / 255.;
        }
    };

    struct RGBAColor {
        double r;
        double g;
        double b;
        double a;

        RGBAColor(double red, double green, double blue, double alpha) {
            r = red;
            g = green;
            b = blue;
            a = alpha;
        }

        RGBAColor(int red, int green, int blue, double alpha) {
            r = red / 255.;
            g = green / 255.;
            b = blue / 255.;
            a = alpha;
        }
    };

    const RGBColor BLACK(0,0,0);
    const RGBColor RED(1.,0.,0.);
    const RGBColor BLUE(0., 0., 1.);
    const RGBColor GREEN(0., 1., 0.);
    const RGBColor WHITE(1.,1.,1.);
    const RGBColor GRAY(.5,.5,.5);
}

namespace position2D {
    struct Vector2D {
        double x;
        double y;

        double rotationAngle;

        Vector2D(double x, double y): Vector2D(x,y,0) {}

        Vector2D(double x, double y, double rot) {
            this->x = x;
            this->y = y;
            rotationAngle = fmod(rot, 360);
        }

        friend Vector2D operator *(Vector2D v, double m) {
            return Vector2D(v.x * m, v.y * m, v.rotationAngle * m);
        }

        friend Vector2D operator *(Vector2D v, Vector2D v2) {
            return Vector2D(v.x * v2.x, v.y * v2.y, v.rotationAngle * v2.rotationAngle);
        }

        friend Vector2D operator /(Vector2D v, double d) {
            return Vector2D(v.x / d, v.y / d, v.rotationAngle / d);
        }


        friend Vector2D operator +(Vector2D v1, Vector2D v2) {
            return Vector2D(v1.x + v2.x, v1.y + v2.y, v1.rotationAngle + v2.rotationAngle);
        }

        Vector2D& operator +=(Vector2D v) {
            this->x += v.x;
            this->y += v.y;
            this->rotationAngle += rotationAngle;
            return *this;
        }

        friend bool operator ==(Vector2D lhs, Vector2D rhs) {
            return (lhs.x == rhs.x) and (lhs.y == rhs.y) and (lhs.rotationAngle == rhs.rotationAngle);
        }

        friend std::ostream& operator <<(std::ostream &outs, const Vector2D &rhs) {
            outs << "X: " << rhs.x << " Y: " << rhs.y << " A: " << rhs.rotationAngle;
            return outs;
        }

    };


    const Vector2D UP(0, -1);
    const Vector2D RIGHT(1, 0);
    const Vector2D DOWN(0,1);
    const Vector2D LEFT(-1, 0);

    const Vector2D ROTATE_RIGHT(0, 0, 1);
    const Vector2D ROTATE_LEFT(0, 0, -1);

    const Vector2D ZERO(0,0,0);

}

namespace position3D {
    struct Vector3D {
        int x,y,z;
        int rotationX,rotationY,rotationZ;

        Vector3D(int x, int y, int z) {
            this->x = x;
            this->y = y;
            this->z = z;

            rotationX = 0;
            rotationY = 0;
            rotationZ = 0;
        }

        Vector3D(int x, int y, int z, int rotX, int rotY, int rotZ) {
            this->x = x;
            this->y = y;
            this->z = z;

            rotationX = rotX % 360;
            rotationY = rotY % 360;
            rotationZ = rotZ % 360;
        }

        friend Vector3D operator *(Vector3D &v, int m) {
            return Vector3D(v.x * m, v.y * m, v.z * m, v.rotationX * m, v.rotationY * m, v.rotationZ * m);
        }
    };

    const Vector3D UP(0, -1, 0);
    const Vector3D RIGHT(1, 0, 0);
    const Vector3D DOWN(0, 1, 0);
    const Vector3D LEFT(-1, 0, 0);
    const Vector3D BACKWARD(0,0,1);
    const Vector3D FORWARD(0,0,-1);
}

#endif //SPACE_STUFF_STRUCTS_H
