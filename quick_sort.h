#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <string.h>

int partition(int *arr, int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++)
        if (arr[j] <= pivot)
            { int temp = arr[++i]; arr[i] = arr[j]; arr[j] = temp; }
    int temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp;
    return i + 1;
}

void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Untuk string
int partition_string(char **arr, int low, int high) {
    char *pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
        if (strcmp(arr[j], pivot) <= 0)
            { char *temp = arr[++i]; arr[i] = arr[j]; arr[j] = temp; }
    char *temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp;
    return i + 1;
}

void quick_sort_string(char **arr, int low, int high) {
    if (low < high) {
        int pi = partition_string(arr, low, high);
        quick_sort_string(arr, low, pi - 1);
        quick_sort_string(arr, pi + 1, high);
    }
}

#endif
