#include "irq.h"
#include "time.h"
#include "sched.h"
#include "string.h"

static void irq_timer()
{
    // TODO clock interrupt handler.
    // scheduler, time counter in here to do, emmmmmm maybe.
//    SET_CP0_COUNT(0);
//    SET_CP0_COMPARE(0x30000);
//    screen_reflush();
    do_scheduler();
}

void interrupt_helper(uint32_t status, uint32_t cause)
{
    // TODO interrupt handler.
    // Leve3 exception Handler.
    // read CP0 register to analyze the type of interrupt.
    uint32_t IP;
    IP = (cause & 0x0000ff00) >> 8;

    if(IP == 0x80)
        irq_timer();
    else
        other_exception_handler();
}

void other_exception_handler()
{
    // TODO other exception handler
}