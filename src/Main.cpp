#include <telkin/Hooks.h>
#include <telkin/Print.h>
#include <thimble/ThimbleConfig.hpp>

int YarnBallColor(void *, int) {
    int color = th::ThimbleConfig::Instance().ReadParam<int>("force_yarn_color");
    return color;
}

tBranch(0x0253a16c, YarnBallColor, tk::BranchType::bl);

void main() { }
