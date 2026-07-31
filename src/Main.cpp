#include <telkin/Hooks.h>
#include <telkin/Print.h>

int YarnBallColor(void *, int) {
    tk::println("Forcing yarn ball color to 4");
    return 4;
}

tBranch(0x0253a16c, YarnBallColor, tk::BranchType::bl);

void main() {
    tk::println("Hello, world!");
    // Hello world!
}
