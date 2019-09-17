#include "std.h"
#include "sysdefs.h"
#include "resource.h"
#include "mods.h"
#include "emul_2203.h"
#include "sndrender.h"
#include "emul.h"
#include "sndchip.h"
#include "sndcounter.h"
#include "init.h"
#include "funcs.h"
#include "debugger/debug.h"
#include "vars.h"
#include "dx.h"
#include "draw.h"
#include "mainloop.h"
#include "iehelp.h"
#include "util.h"
#include "memory.h"

#define SND_TEST_FAILURES
//#define SND_TEST_SHOWSTAT

#ifndef INVALID_SET_FILE_POINTER
#define INVALID_SET_FILE_POINTER (DWORD)-1
#endif


#ifdef LOG_FE_OUT
	FILE *f_log_FE_out;
#endif
#ifdef LOG_FE_IN
	FILE *f_log_FE_in;
#endif
#ifdef LOG_TAPE_IN
	FILE *f_log_tape_in;
#endif



