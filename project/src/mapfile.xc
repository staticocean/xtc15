
#include <platform.h>

extern "C" { void main_t0 (void); }
extern "C" { void main_t1 (void); }

int main (void)
{
    par {
        on tile[0]: main_t0();
        on tile[1]: main_t1();
    }

    return 0;
}
