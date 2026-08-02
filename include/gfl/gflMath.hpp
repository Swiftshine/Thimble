#pragma once

#include <cafe.h>
#include <cmath>


namespace gfl {

struct Vec2 {
    Vec2()
        : x(0), y(0)
    { }

    Vec2(float _x, float _y)
        : x(_x), y(_y)
    { }

    float x;
    float y;
};

struct Vec3 {
    Vec3()
        : x(0), y(0), z(0)
    { }

    Vec3(float _x, float _y, float _z)
        : x(_x), y(_y), z(_z)
    { }

    float Length() const {
        return sqrtf(x * x + y * y + z * z);
    }

    void Normalize() {
        float len = Length();

        if (len > 0.0f) {
            x /= len;
            y /= len;
            z /= len;
        }
    }

    Vec3 Normalized() const {
        float len = Length();

        if (len > 0.0f) {
            return Vec3(
                x / len,
                y / len,
                z / len
            );
        }

        return Vec3(0.0f, 0.0f, 0.0f);
    }

    Vec3 operator-(const Vec3& rhs) const {
        return Vec3(
            x - rhs.x,
            y - rhs.y,
            z - rhs.z
        );
    }

    Vec3 operator+(const Vec3& rhs) const {
        return Vec3(
            x + rhs.x,
            y + rhs.y,
            z + rhs.z
        );
    }

    void operator*=(float f) {
        x *= f;
        y *= f;
        z *= f;
    }

    float Dot(const Vec3& rhs) const {
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }
    
    Vec3 Cross(const Vec3& rhs) const {
        return Vec3(
            y * rhs.z - z * rhs.y,
            z * rhs.x - x * rhs.z,
            x * rhs.y - y * rhs.x
        );
    }

    float x;
    float y;
    float z;
};


// no idea if it belongs to the gfl namespace but im putting it here
struct Quat {
    void Rotate(const gfl::Vec3& from, const gfl::Vec3& to) {
        gfl::Vec3 f = from.Normalized();
        gfl::Vec3 t = to.Normalized();

        float d = f.Dot(t);

        if (d > 0.999999f) {
            x = y = z = 0.0f;
            w = 1.0f;
            return;
        }


        if (d < -0.999999f) {
            gfl::Vec3 axis;

            if (fabsf(f.x) < fabsf(f.z)) {
                axis = f.Cross(gfl::Vec3(1.0f, 0.0f, 0.0f));
            } else {
                axis = f.Cross(gfl::Vec3(0.0f, 0.0f, 1.0f));
            }

            axis.Normalize();

            x = axis.x;
            y = axis.y;
            z = axis.z;
            w = 0.0f;
            return;
        }

        gfl::Vec3 c = f.Cross(t);

        float s = std::sqrt((1.0f + d) * 2.0f);
        float invs = 1.0f / s;

        x = c.x * invs;
        y = c.y * invs;
        z = c.z * invs;
        w = s * 0.5f;

        float len = sqrtf(x * x + y * y + z * z + w * w);
        x /= len;
        y /= len;
        z /= len;
        w /= len;
    }

    float x, y, z, w;
};


struct Matrix34 {
    union {
        float _2d[3][4];
        float _1d[3 * 4];
    };

    void Identity() {
        _2d[0][0] = 1.0f; _2d[0][1] = 0.0f; _2d[0][2] = 0.0f; _2d[0][3] = 0.0f;
        _2d[1][0] = 0.0f; _2d[1][1] = 1.0f; _2d[1][2] = 0.0f; _2d[1][3] = 0.0f;
        _2d[2][0] = 0.0f; _2d[2][1] = 0.0f; _2d[2][2] = 1.0f; _2d[2][3] = 0.0f;
    }

    void Scale(const gfl::Vec3& s) {
        ASM_MTXScale(_2d, s.x, s.y, s.z);
    }

    Matrix34 operator*(const Matrix34& rhs) const {
        Matrix34 out;
        for (int c = 0; c < 4; ++c) {
            for (int r = 0; r < 3; ++r) {
                out._2d[r][c] = _2d[r][0] * rhs._2d[0][c] +
                                _2d[r][1] * rhs._2d[1][c] +
                                _2d[r][2] * rhs._2d[2][c];
            }
        }

        out._2d[0][3] += _2d[0][3];
        out._2d[1][3] += _2d[1][3];
        out._2d[2][3] += _2d[2][3];
        return out;
    }

    static Matrix34 FromQuat(const Quat& q) {
        const float lenSq =
            q.x * q.x +
            q.y * q.y +
            q.z * q.z +
            q.w * q.w;

        const float invLen =
            (lenSq > 0.0f) ? 1.0f / sqrtf(lenSq) : 1.0f;

        Quat n = {
            q.x * invLen,
            q.y * invLen,
            q.z * invLen,
            q.w * invLen
        };

        const float xx = n.x * n.x;
        const float yy = n.y * n.y;
        const float zz = n.z * n.z;

        const float xy = n.x * n.y;
        const float xz = n.x * n.z;
        const float yz = n.y * n.z;

        const float wx = n.w * n.x;
        const float wy = n.w * n.y;
        const float wz = n.w * n.z;

        Matrix34 mtx;
        mtx._2d[0][0] = 1.0f - 2.0f * (yy + zz);
        mtx._2d[0][1] = 2.0f * (xy - wz);
        mtx._2d[0][2] = 2.0f * (xz + wy);
        mtx._2d[0][3] = 0.0f;

        mtx._2d[1][0] = 2.0f * (xy + wz);
        mtx._2d[1][1] = 1.0f - 2.0f * (xx + zz);
        mtx._2d[1][2] = 2.0f * (yz - wx);
        mtx._2d[1][3] = 0.0f;

        mtx._2d[2][0] = 2.0f * (xz - wy);
        mtx._2d[2][1] = 2.0f * (yz + wx);
        mtx._2d[2][2] = 1.0f - 2.0f * (xx + yy);
        mtx._2d[2][3] = 0.0f;

        return mtx;
    }

    void Translate(const gfl::Vec3& t) {
        _2d[0][3] = t.x;
        _2d[1][3] = t.y;
        _2d[2][3] = t.z;
    }
};

struct Matrix44 {
    union {
        float _2d[4][4];
        float _1d[16];
    };

    void Identity() {
        for (int r = 0; r < 4; ++r) {
            for (int c = 0; c < 4; ++c) {
                _2d[r][c] = (r == c) ? 1.0f : 0.0f;
            }
        }
    }

    Matrix44 operator*(const Matrix34& rhs) const {
        Matrix44 out;
        for (int c = 0; c < 4; ++c) {
            for (int r = 0; r < 4; ++r) {
                out._2d[r][c] = _2d[r][0] * rhs._2d[0][c] +
                                _2d[r][1] * rhs._2d[1][c] +
                                _2d[r][2] * rhs._2d[2][c];
            }
        }

        for (int r = 0; r < 4; ++r) {
            out._2d[r][3] += _2d[r][3];
        }
        return out;
    }

    Matrix44 operator*(const Matrix44& rhs) const {
        Matrix44 out;

        for (int r = 0; r < 4; ++r) {
            for (int c = 0; c < 4; ++c) {
                out._2d[r][c] =
                    _2d[r][0] * rhs._2d[0][c] +
                    _2d[r][1] * rhs._2d[1][c] +
                    _2d[r][2] * rhs._2d[2][c] +
                    _2d[r][3] * rhs._2d[3][c];
            }
        }

        return out;
    }
};

}
