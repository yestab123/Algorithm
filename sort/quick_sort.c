#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "sort_head.h"

void
swap(int p[], int a1, int a2) {
  int mark = p[a1];
  p[a1] = p[a2];
  p[a2] = mark;
}

int
quick_partition(int p[], int low, int high) {
  int key;

  key = p[low];
  while(low < high) {
    while(low < high && p[high] >= key)
      high--;
    swap(p, low, high);
    while(low < high && p[low] <= key)
      low++;
    swap(p, low, high);
  }
  return low;
}

void
quick_sort(int p[], int low, int high) {
  int pivot;
  if (low < high) {
    pivot = quick_partition(p, low, high);
    quick_sort(p, low, pivot - 1);
    quick_sort(p, pivot + 1, high);
  }
}

int
main(int argc, char **argv) {
  quick_sort(src, 0, sizeof(src)/sizeof(src[0]) - 1);
  int i;
  show_num(src);
}
