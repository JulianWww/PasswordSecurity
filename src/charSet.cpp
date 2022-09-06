#include <pswdsec/charSet.hpp>

size_t pswdsec::charSet(const char& c) {
    if (c>=65 && c<=90)
        return 1;
    else if (c>=48 && c<=57)
        return 2;
    else if (c>=97 && c<=122)
        return 0;
    return 3;
}