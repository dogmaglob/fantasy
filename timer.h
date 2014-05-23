#ifndef __TIMER_H__
#define __TIMER_H__

typedef struct _timer timer;

timer * timer_new();
void    timer_destroy(timer * t);
void    timer_start(timer * t);
int     timer_get_ticks(timer * t);

#endif //__TIMER_H__
