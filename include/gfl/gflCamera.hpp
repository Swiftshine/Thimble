#pragma once

#include <types.h>
#include <gflMath.hpp>

namespace gfl {
    class Camera {
    public:
        enum class CameraType : u32 {
            Perspective     = 0,
            Orthographic    = 1,
        };

        Camera(u32 arg1, u32 cameraType);
        virtual ~Camera();

        void SetPerspectiveProjection(float right, float left, float near, float far);
        void SetOrthographicProjection(float left, float right, float bottom, float top, float near, float far);
        const gfl::Vec3& GetPosition() const;
        void UpdateDirectionFromLookAt();
        void SetPosition(const gfl::Vec3& pos);
        const gfl::Vec3& GetLookAt() const;
        void SetLookAt(const gfl::Vec3& lookAt);
        void SetUpVector(const gfl::Vec3& up);
        const gfl::Vec3& GetUpVector() const;
        void SetViewMatrix(const gfl::Matrix34& rMtx);
        const gfl::Matrix34& GetViewMatrix() const;
        const gfl::Matrix44& GetProjectionMatrix() const;
        void SetNear(float near);
        void SetFar(float far);
        void SetPerspectiveRight(float right);
        void SetPerspectiveLeft(float left);
    private:
        /* 0x000 */ u32 m_0;
        /* 0x004 */ CameraType mCameraType;
        /* 0x008 */ Vec3 mCameraPos;
        /* 0x014 */ Vec3 mCameraLookAt;
        /* 0x020 */ Vec3 mCameraUp;
        /* 0x02C */ Vec3 mDirection;
        /* 0x038 */ Vec3 mDirectionNormalized;
        /* 0x044 */ Matrix34 mViewMatrix;
        /* 0x074 */ Matrix44 mProjectionMatrix;
        /* 0x0B4 */ float mNear;
        /* 0x0B8 */ float mFar;
        /* 0x0BC */ float mPerspectiveRight;
        /* 0x0C0 */ float mPerspectiveLeft;
        /* 0x0C4 */ float mOrthographicLeft;
        /* 0x0C8 */ float mOrthographicRight;
        /* 0x0CC */ float mOrthographicTop;
        /* 0x0D0 */ float mOrthographicBottom;
        /* 0x0D4 */ STRUCT_FILL(0x2F4 - 0xD4);
    };

    SIZE_ASSERT(Camera, 0x2F8);
}
