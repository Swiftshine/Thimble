#include <telkin/Print.h>
#include <telkin/Hooks.h>
#include <game/Game.hpp>
#include <thimble/ThimbleConfig.hpp>

namespace th {

void RunHook() {
    // collect configs
    ThimbleConfig::Instance().ConfigureFrom("thimble/config.cfg");

    Game::Run();
}


// Hook into main()
tBranch(0x02BBE464, RunHook, tk::BranchType::bl);

}
