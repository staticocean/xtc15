
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <xs2a_user.h>

#include <xcore/channel_streaming.h>
#include <xcore/hwtimer.h>
#include <xcore/interrupt.h>
#include <xcore/select.h>
#include <xcore/parallel.h>

//------------------------------------------------------------------------------

DECLARE_JOB(main_t0c0, (void));
DECLARE_JOB(main_t0c1, (void));
DECLARE_JOB(main_t0c2, (void));
DECLARE_JOB(main_t0c3, (void));
DECLARE_JOB(main_t0c4, (void));
DECLARE_JOB(main_t0c5, (void));
DECLARE_JOB(main_t0c6, (void));
DECLARE_JOB(main_t0c7, (void));

void main_t0c0 (void) { while (1) { (void) 0; } }
void main_t0c1 (void) { while (1) { (void) 0; } }
void main_t0c2 (void) { while (1) { (void) 0; } }
void main_t0c3 (void) { while (1) { (void) 0; } }
void main_t0c4 (void) { while (1) { (void) 0; } }
void main_t0c5 (void) { while (1) { (void) 0; } }
void main_t0c6 (void) { while (1) { (void) 0; } }
void main_t0c7 (void) { while (1) { (void) 0; } }

void main_t0 (void)
{
    PAR_JOBS(
        PJOB(main_t0c0, ()),
        PJOB(main_t0c1, ()),
        PJOB(main_t0c2, ()),
        PJOB(main_t0c3, ()),
        PJOB(main_t0c4, ()),
        PJOB(main_t0c5, ()),
        PJOB(main_t0c6, ()),
        PJOB(main_t0c7, ())
    );
}

//------------------------------------------------------------------------------

DECLARE_JOB(main_t1c0, (void));
DECLARE_JOB(main_t1c1, (void));
DECLARE_JOB(main_t1c2, (void));
DECLARE_JOB(main_t1c3, (void));
DECLARE_JOB(main_t1c4, (void));
DECLARE_JOB(main_t1c5, (void));
DECLARE_JOB(main_t1c6, (void));
DECLARE_JOB(main_t1c7, (void));

void main_t1c0 (void) { while (1) { (void) 0; } }
void main_t1c1 (void) { while (1) { (void) 0; } }
void main_t1c2 (void) { while (1) { (void) 0; } }
void main_t1c3 (void) { while (1) { (void) 0; } }
void main_t1c4 (void) { while (1) { (void) 0; } }
void main_t1c5 (void) { while (1) { (void) 0; } }
void main_t1c6 (void) { while (1) { (void) 0; } }
void main_t1c7 (void) { while (1) { (void) 0; } }

void main_t1 (void)
{
    PAR_JOBS(
        PJOB(main_t1c0, ()),
        PJOB(main_t1c1, ()),
        PJOB(main_t1c2, ()),
        PJOB(main_t1c3, ()),
        PJOB(main_t1c4, ()),
        PJOB(main_t1c5, ()),
        PJOB(main_t1c6, ()),
        PJOB(main_t1c7, ())
    );
}

//------------------------------------------------------------------------------
