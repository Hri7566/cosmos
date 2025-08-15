#include "print.h"
#include "../flanterm/flanterm.h"

void print(const char s[]) {
    flanterm_write(print_ft_ctx, s, sizeof(s));
}

void println(const char s[]) {
    print(s);
    print("\n");
}
