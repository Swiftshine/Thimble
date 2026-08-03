#include <telkin/Telkin.h>
#include <game/Game.hpp>
#include "ThimbleConfig.hpp"

#include <array>
#include <functional>

namespace th {
const char* CONFIG_PATH = "thimble/config.bson";

void SetupAdditionalGimmickProfiles();
void PatchInstructionsForTweaks();

void RunHook() {
    using Task = void(*)(size_t, size_t);

    auto tasks = std::array<Task, 3>{ {
        [](size_t i, size_t total) {
            tk::println("\t(%d/%d) Setting up ThimbleConfig...", i + 1, total);
            ThimbleConfig::Instance().ConfigureFrom(CONFIG_PATH);
        },
        [](size_t i, size_t total) {
            tk::println("\t(%d/%d) Setting up additional gimmick profiles...", i + 1, total);
            SetupAdditionalGimmickProfiles();
        },
        [](size_t i, size_t total) {
            tk::println("\t(%d/%d) Patching instructions for misc. tweaks...", i + 1, total);
            PatchInstructionsForTweaks();
        }
    }};

    tk::println("Running %d pre-run tasks...", tasks.size());

    for (size_t i = 0; i < tasks.size(); i++) {
        tasks[i](i, tasks.size());
    }

    tk::println("Done with pre-run tasks.");

    Game::Run();
}

}

// Hook into main()
tBranch(0x02BBE464, th::RunHook, tk::BranchType::bl);
