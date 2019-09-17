#include "rang.hpp"

#include "std.h"
#include "emul.h"

#include "vars.h"

#include "util.h"
#include "mainloop.h"
#include "dx.h"
#include "init.h"
#include "draw.h"
#include "memory.h"
#include "iehelp.h"

using namespace std;
using namespace rang;

int nmi_pending = 0;
unsigned frametime = 111111; //Alone Coder (GUI value for conf.frame)

void showhelp(const char *anchor)
{
   sound_stop(); //Alone Coder 0.36.6
   showhelppp(anchor); //Alone Coder 0.36.6
   sound_play(); //Alone Coder 0.36.6
}

int main(int argc, char **argv)
{
    cout << style::reset;
    cout << "UnrealSpeccy by SMT and Others" << endl;
    cout << "Build date: " << fg::yellow <<  __DATE__ << "," << __TIME__ << endl << endl;

    rand_ram();
    load_spec_colors();
    init_all(argc - 1, argv + 1);
    sound_play();
    color();

#ifdef LOG_FE_OUT
    f_log_FE_out = fopen("log_FE_out.txt", "wb");
    fprintf(f_log_FE_out, "CPU_tact\tFE_val\r\n");
#endif
#ifdef LOG_FE_IN
    f_log_FE_in = fopen("log_FE_in.txt", "wb");
    fprintf(f_log_FE_in, "CPU_tact\tFE_val\tA[15:8]\r\n");
#endif
#ifdef LOG_TAPE_IN
    f_log_tape_in = fopen("log_tape_in.txt", "wb");
    fprintf(f_log_tape_in, "CPU_tact\ttape_bit\r\n");
#endif
    bool Exit = false;

    mainloop(Exit);

#ifdef LOG_FE_OUT
    fclose(f_log_FE_out);
#endif
#ifdef LOG_FE_IN
    fclose(f_log_FE_in);
#endif
#ifdef LOG_TAPE
    fclose(f_log_tape_in);
#endif

    return 0;
}