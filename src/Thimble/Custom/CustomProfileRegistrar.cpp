#include <game/object/ObjectProfile.hpp>
#include <game/object/YsGameObj.hpp>
#include <telkin/Telkin.h>
#include <thimble/RegistrarManager.hpp>

extern ObjectID GetObjectIDByCategoryAndLocalID(YsGameObj::ObjectCategory category, u32 localID);
extern YsGameObj::ObjectCategory GetCategoryByObjectID(ObjectID objectID);
extern void RegisterGimmickProfile(const char* pNameInLevelFile, ObjectID objectID, GimmickID gimmickID,
                                   GimmickProfileInitFunction pInitFunction);

ObjectID GetObjectIDByCategoryAndLocalID_Custom(YsGameObj::ObjectCategory category, u32 localID) {
    th::RegistrarManager& ids = th::RegistrarManager::Instance();

    switch (category) {
    case YsGameObj::ObjectCategory::GimmickObject: {
        for (const auto& set : ids.mGimmickIDSets) {
            if (set.mLocalID == localID) {
                return set.mObjectID;
            }
        }

        [[fallthrough]];
    }

    default:
        break;
    }

    // just let the game handle it
    return GetObjectIDByCategoryAndLocalID(category, localID);
}

tBranch(0x0217333C, GetObjectIDByCategoryAndLocalID_Custom, tk::BranchType::bl);
tBranch(0x02173378, GetObjectIDByCategoryAndLocalID_Custom, tk::BranchType::bl);
tBranch(0x021733B4, GetObjectIDByCategoryAndLocalID_Custom, tk::BranchType::bl);
tBranch(0x021733F0, GetObjectIDByCategoryAndLocalID_Custom, tk::BranchType::bl);
tBranch(0x0281C36C, GetObjectIDByCategoryAndLocalID_Custom, tk::BranchType::b);

YsGameObj::ObjectCategory GetCategoryByObjectID_Custom(ObjectID objectID) {
    th::RegistrarManager& ids = th::RegistrarManager::Instance();

    for (const auto& set : ids.mGimmickIDSets) {
        if (set.mObjectID == objectID) {
            return set.mCategory;
        }
    }

    return GetCategoryByObjectID(objectID);
}

tBranch(0x0281641C, GetCategoryByObjectID_Custom, tk::BranchType::bl);
tBranch(0x02818630, GetCategoryByObjectID_Custom, tk::BranchType::b);
tBranch(0x028199D0, GetCategoryByObjectID_Custom, tk::BranchType::bl);

namespace th {

void SetupAdditionalGimmickProfiles() {
    u32 num = 0;

    RegistrarManager& ids = RegistrarManager::Instance();

    // all IDs are filled in automatically
    for (const auto& registrant : ids.mGimmickRegistrants) {
        RegisterGimmickProfile(registrant.mInLevelName, ids.mHighestObjectID, ids.mHighestGimmickID,
                               registrant.mInitFunction);

        ids.AddGimmickID();
        num++;
    }

    if (num == 0) {
        tk::println("No additional gimmick profiles found.");
    } else {
        tk::println("Set up %d additional gimmick profiles.", num);
    }
}

} // namespace th
