#pragma once
#include <cstring>
#include <game/object/ObjectIDs.hpp>
#include <game/object/ObjectProfile.hpp>
#include <game/object/YsGameObj.hpp>
#include <telkin/Telkin.h>
#include <types.h>
#include <vector>

typedef void (*MapGimmickInitFunction)(MapGimmick* pProfile, const char* pName, u32 objectID, u32 gimmickID);

namespace th {
class RegistrarManager {
    template <typename T> inline void increment(T& val) { val = static_cast<T>(static_cast<u32>(val) + 1); }

public:
    struct IDSet {
        YsGameObj::ObjectCategory mCategory;
        ObjectID mObjectID;
        u32 mLocalID;
    };

    struct GimmickRegistrant {
        template <size_t N> inline GimmickRegistrant(const char (&gimmickName)[N], MapGimmickInitFunction init) {
            static_assert(N <= 0x21, "Gimmick name must be at most 32 characters");

            memcpy(mInLevelName, gimmickName, N);
            mInitFunction = init;

            RegistrarManager::Instance().mGimmickRegistrants.push_back(*this);
        }

        char mInLevelName[0x20];
        MapGimmickInitFunction mInitFunction;
    };

    static RegistrarManager& Instance();

    RegistrarManager();

    void AddGimmickID();

    ObjectID mHighestObjectID;
    GimmickID mHighestGimmickID;
    std::vector<IDSet> mGimmickIDSets;
    std::vector<GimmickRegistrant> mGimmickRegistrants;
};
} // namespace th

#define REGISTER_GIMMICK(C, N)                                                                                         \
    static th::RegistrarManager::GimmickRegistrant s_GimmickRegistrant_##C {N, C::InitProfile};
