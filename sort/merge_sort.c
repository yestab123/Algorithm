#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <malloc.h>

#include "sort_head.h"

void
merge_array(int s[], int low, int mid, int high, int p[]) {
    int i, j, k;
    k = 0;
    i = low;
    j = mid + 1;

    while(i <= mid && j <= high) {
        if (s[i] <= s[j]) {
            p[k++] = s[i++];
        } else {
            p[k++] = s[j++];
        }
    }

    while (i <= mid) {
        p[k++] = s[i++];
    }

    while (j <= high) {
        p[k++] = s[j++];
    }

    for (i = low, k = 0; i <= high; i++) {
        s[i] = p[k++];
    }
}

void
merge_sort(int s[], int low, int high, int p[]) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        merge_sort(s, low, mid, p);
        merge_sort(s, mid + 1, high, p);
        merge_array(s, low, mid, high, p);
    }
}

int
main(int argc, char **argv) {
    int *p;
    p = malloc(sizeof(src));
    merge_sort(src, 0, get_len(src) - 1, p);
    show_num(src);
}
