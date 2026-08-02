#pragma once
#include <telkin/Runtime.h>

namespace ghs::std {
    class string {
    private:
        static void _assign(string* obj, const char* _Ptr, size_t _Num);
        static void _Tidy(string* obj, int _Built, size_t _Newsize);
    public:
        string(const char* pSrc) {
            _assign(this, pSrc, strlen(pSrc));
        }

        ~string() {
            _Tidy(this, 1, 0);
        }
        char contents[0x20];
    };
}
