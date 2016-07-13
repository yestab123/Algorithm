#ifndef _H_SORT_HEAD_
#define _H_SORT_HEAD_

#include <stdio.h>

int src[] = {
    56, 67, 23, 1, 0, 33, -34, 56, 89, -79, 34, 1, 3, 0, 77
};

#define show_num(n) do {                          \
    int i;                                        \
    for (i = 0; i < sizeof(n)/sizeof(n[0]);i++) { \
      printf(" %d ", n[i]);                       \
    }                                             \
    printf("\n");                                 \
  }while(0)

#define get_len(n) (sizeof(n)/sizeof(n[0]))

#endif
