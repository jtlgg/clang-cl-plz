#include <iostream>
#include <cstdio>

// very badly platform specific code
auto show_message() -> void;

#ifdef WIN32
#include <Windows.h>
auto show_message() -> void {
    SYSTEMTIME st, lt;

    GetSystemTime(&st);
    GetLocalTime(&lt);
    std::cout << "Hello.exe :)" << std::endl;

    printf("The system time is: %02d:%02d\n", st.wHour, st.wMinute);
    printf(" The local time is: %02d:%02d\n", lt.wHour, lt.wMinute);
}
#else
#include <time.h>
#include <sys/time.h>

#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif
auto show_message() -> void {
    struct timespec ts;
#ifdef __MACH__ // OS X does not have clock_gettime, use clock_get_time
    clock_serv_t cclock;
    mach_timespec_t mts;
    host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
    clock_get_time(cclock, &mts);
    mach_port_deallocate(mach_task_self(), cclock);
    ts.tv_sec = mts.tv_sec;
    ts.tv_nsec = mts.tv_nsec;

#else
    clock_gettime(CLOCK_REALTIME, &ts);
#endif

    std::cout << "Hello :)" << std::endl;

    printf("s:  %lu\n", ts.tv_sec);
    printf("ns: %lu\n", ts.tv_nsec);
}
#endif
