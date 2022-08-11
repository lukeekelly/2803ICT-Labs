#include <time.h>
#include <stdio.h>

#define SIZE 214

struct timespec start;
struct timespec end;

void TimerStart()
{
    clock_gettime(CLOCK_MONOTONIC, &start);
}

unsigned long TimerStop()
{
    clock_gettime(CLOCK_MONOTONIC, &end);
    return end.tv_nsec - start.tv_nsec;
}

void CopyAB(int src[SIZE][SIZE], int dst[SIZE][SIZE])
{
    for (int a = 0; a < SIZE; a++)
        for (int b = 0; b < SIZE; b++)
            dst[a][b] = src[a][b];
}

void CopyBA(int src[SIZE][SIZE], int dst[SIZE][SIZE])
{
    for (int b = 0; b < SIZE; b++)
        for (int a = 0; a < SIZE; a++)
            dst[a][b] = src[a][b];
}


int main()
{
    unsigned long delay1, delay2;
    int src[SIZE][SIZE];
    int dst[SIZE][SIZE];
    struct timespec ts;

    TimerStart();
    CopyAB(src, dst);
    delay1 = TimerStop();

    TimerStart();
    CopyBA(src, dst);
    delay2 = TimerStop();
    printf("Delay1 = %lu, Delay2 = %lu", delay1, delay2);

    return 0;
} 
