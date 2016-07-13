#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "sort_head_b.h"

void
swap(int p[], int s, int m) {
    int key = p[s];
    p[s] = p[m];
    p[m] = key;
}

void HeapAdjust(int p[], int s, int m) {
    int temp, j;
    temp = p[s];
    for (j = 2 * s; j <= m; j *= 2) {
        if (j < m && p[j] < p[j+1])
            ++j;
        if (temp >= p[j])
            break;
        p[s] = p[j];
        s = j;
    }
    p[s] = temp;
}

void
HeapSort(int p[]) {
    int i;
    int length = get_len(src);

    for (i = length/2; i > 0; i--) {
        HeapAdjust(p, i, length);
    }

    for (i = length; i > 1; i--) {
        swap(p, 1, i);
        HeapAdjust(p, 1, i - 1);
    }
}

int
main(int argc, char **argv) {
    HeapSort(src);
    show_num(src);
}
