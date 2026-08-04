#pragma once
#include <types.h>
#include <vector>

#include <game/object/YsGameObj.hpp>
#include <game/object/ObjectIDs.hpp>

namespace th {
    class CustomIDManager {
        template <typename T>
        inline void increment(T& val) {
            val = static_cast<T>(static_cast<u32>(val) + 1);
        }
    public:
        struct IDSet {
            YsGameObj::ObjectCategory mCategory;
            ObjectID mObjectID;
            u32 mLocalID;
        };

        CustomIDManager();
        static CustomIDManager& Instance();

        void AddGimmickID() {
            increment(mHighestObjectID);
            increment(mHighestGimmickID);

            mGimmickIDSets.emplace_back(
                YsGameObj::ObjectCategory::GimmickObject,
                mHighestObjectID,
                static_cast<u32>(mHighestGimmickID)
            );
        }

        ObjectID mHighestObjectID;
        GimmickID mHighestGimmickID;
        std::vector<IDSet> mGimmickIDSets;
    };
}
