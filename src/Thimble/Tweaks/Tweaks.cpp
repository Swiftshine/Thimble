#include <telkin/Telkin.h>
#include "Thimble/ThimbleConfig.hpp"

// Prevent the game from switching into 30fps mode on the world map
#if !defined(__CONSOLE__) // This does not work on console
    tPatch32u(0x02B38D7C, tk::ppc::b(0x20));
#endif

inline void PatchInstruction(u32 address, u32& instr) {
    // US addr
    const u32 CONSOLE_TEXT_OFFSET = 0x0C700000;
    #if defined(__CONSOLE__)
        address += CONSOLE_TEXT_OFFSET;
    #endif

    tk::privilegedWrite((const void*)address, (const void*)&instr, sizeof(u32));
}

#define PATCH_INSTRUCTION(address, src, num_bytes) tk::priviledgedWrite((const void*)(address), (const void*)(src), num_bytes)
namespace th {
    void PatchInstructionsForTweaks() {

        {
            const u16 DEFAULT_EGG_LIMIT = 6;
            const u16 limit = (u16) th::ThimbleConfig::Instance()
                .GetBSON()
                ->GetIntFromRoot("yarn_ball_limit", DEFAULT_EGG_LIMIT);

            // PlEggCtrl::CreateFollowingEgg
            {
                u32 instr = tk::ppc::cmplwi(tk::ppc::GPR::r8, 0);
                instr |= limit;
                PatchInstruction(0x0291DE8C, instr);
            }

            // GmkBox::ShouldSpawnYarnBall
            {
                u32 instr = tk::ppc::cmplwi(tk::ppc::GPR::r0, 0);
                instr |= limit;
                PatchInstruction(0x02539C4C, instr);
            }

            // GmkEggBox::GetAvailableYarnBallSlots
            {
                // subfic r12, r0, ...
                u32 instr = 0x21800000;
                instr |= limit;
                PatchInstruction(0x02539BF8, instr);
            }
        }
    }
}
