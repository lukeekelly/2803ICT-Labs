#include "prefixadd.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    const int min_args = 2;
    const int first_arg = 1;

    if (argc < min_args)
    {
        printf("Usage: argv[0] <argument> [argument] ....\n");
        return 1;
    }

    int curr_pos = first_arg;
    int value = process(&curr_pos, argc - 1, argv);

    printf("The value calculated is %d\n", value);

    return 0;
}