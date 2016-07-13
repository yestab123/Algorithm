#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sort_head_b.h"

void
ShellSort(int p[]) {
    int length = get_len(src);
    int i, j;
    int increment = length;

    do {
        increment = increment / 3 + 1;
        for (i = increment + 1; i <= length; i++) {
            if (p[i] < p[i - increment]) {
                p[0] = p[i];
                for (j = i - increment; j > 0 && p[0] < p[j]; j -= increment) {
                    p[j + increment] = p[j];
                }
                p[j + increment] = p[0];
            }
        }
    } while(increment > 1);
}

int
main(int argc, char **argv) {
    ShellSort(src);
    show_num(src);
}
