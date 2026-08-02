#include <telkin/Telkin.h>
#include "Thimble/ThimbleConfig.hpp"
#include "telkin/Assembly.h"

// Prevent the game from switching into 30fps mode on the world map
#if !defined(__CONSOLE__) // This does not work on console
    tPatch32u(0x02B38D7C, tk::ppc::b(0x20));
#endif


// Remove the yarn ball limit
#include <object/Player.hpp>
#include <manager/GameManager.hpp>
const u16 EGG_LIMIT = 100;
size_t GetAvailableYarnBallSlots() {
    size_t slotsRemaining = 0;

    for (size_t i = 0; i < GameManager::sInstance->GetNumPlayers(); i++) {
        Player* player = GameManager::sInstance->GetPlayer(i);
        PlEggCtrl* eggCtrl = player->GetPlEggCtrl();

        size_t numReserved = eggCtrl->mReservedYarnBalls.size();
        size_t numCurrentlyHeld = eggCtrl->GetNumAttachedYarnBalls();

        slotsRemaining += EGG_LIMIT - (numCurrentlyHeld + numReserved);
    }

    return slotsRemaining;
}

#include <object/gimmick/GmkEggBox.hpp>
bool ShouldSpawnYarnBall(GmkEggBox* pBox) {
    size_t count = pBox->mOtherEggCtrl->mList.size();
    size_t slots = GetAvailableYarnBallSlots();
    return count < EGG_LIMIT && count < slots;
}

tBranch(0x02539C58, GetAvailableYarnBallSlots, tk::BranchType::bl);
tBranch(0x0253A480, ShouldSpawnYarnBall, tk::BranchType::bl);
tBranch(0x0253A4FC, ShouldSpawnYarnBall, tk::BranchType::bl);
tBranch(0x0253A6B0, ShouldSpawnYarnBall, tk::BranchType::bl);

// PlEggCtrl::CreateFollowingEgg
tPatch32u(0x0291DE8C, tk::ppc::cmplwi(tk::ppc::GPR::r8, EGG_LIMIT));
