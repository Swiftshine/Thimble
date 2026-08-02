#include <telkin/Telkin.h>
#include <game/object/ObjectProfile.hpp>

typedef void (* GimmickProfileInitFunction)(GimmickProfile* pProfile, const char* pName, u32 objectID, u32 gimmickID);
void RegisterGimmickProfile(const char* pNameInLevelFile, u32 objectID, u32 gimmickID, GimmickProfileInitFunction pInitFunction);

namespace th {

void SetupAdditionalGimmickProfiles() {
    u32 num = 0;

    if (num == 0) {
        tk::println("No additional gimmick profiles found.");
    } else {
        tk::println("Set up %d additional gimmick profiles.", num);
    }
}

}
