#include "misc.h"

// because libfxcg's implementation of printf/sprintf doesn't support hex formatting
void uchar_to_hex(unsigned char n, char *o_str) {
    const char charlist[] = "0123456789ABCDEF";
    o_str[1] = charlist[n % 0b10000];
    o_str[0] = charlist[(n >> 4)];
}
