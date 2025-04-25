#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "shell_sort.h"

#define MAX_WORD_LENGTH 50

int data_sizes[] = {10000, 50000, 100000, 250000, 500000, 1000000, 1500000, 2000000};
int data_size_count = sizeof(data_sizes) / sizeof(data_sizes[0]);

// ===========================
// Bagian untuk Data Angka
// ===========================
void read_integers(const char *filename, int *array, int n) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Tidak bisa membuka file angka");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &array[i]);
    }
    fclose(file);
}

void copy_array(int *src, int *dest, int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

void test_algorithm(const char *name, void (*sort_func)(int*, int), int *original, int n) {
    int *arr = malloc(n * sizeof(int));
    size_t memory_used = n * sizeof(int);

    copy_array(original, arr, n);

    clock_t start = clock();
    sort_func(arr, n);
    clock_t end = clock();

    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("%-15s | Data: %7d | Waktu: %.3fs | Memori: %8zu bytes\n", name, n, elapsed_time, memory_used);

    free(arr);
}

void test_quick_sort(int *original, int n) {
    int *arr = malloc(n * sizeof(int));
    size_t memory_used = n * sizeof(int);

    copy_array(original, arr, n);

    clock_t start = clock();
    quick_sort(arr, 0, n - 1);
    clock_t end = clock();

    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("%-15s | Data: %7d | Waktu: %.3fs | Memori: %8zu bytes\n", "Quick Sort", n, elapsed_time, memory_used);

    free(arr);
}

void test_merge_sort(int *original, int n) {
    int *arr = malloc(n * sizeof(int));
    size_t memory_used = n * sizeof(int);

    copy_array(original, arr, n);

    clock_t start = clock();
    merge_sort(arr, 0, n - 1);
    clock_t end = clock();

    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("%-15s | Data: %7d | Waktu: %.3fs | Memori: %8zu bytes\n", "Merge Sort", n, elapsed_time, memory_used);

    free(arr);
}

// ===========================
// Bagian untuk Data Kata
// ===========================

void read_words(const char *filename, char **array, int n) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Tidak bisa membuka file kata");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        array[i] = malloc(MAX_WORD_LENGTH);
        fscanf(file, "%s", array[i]);
    }
    fclose(file);
}

void copy_words(char **src, char **dest, int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = malloc(MAX_WORD_LENGTH);
        strcpy(dest[i], src[i]);
    }
}

void free_words(char **array, int n) {
    for (int i = 0; i < n; i++) {
        free(array[i]);
    }
    free(array);
}

int compare_strings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void test_string_algorithm(const char *name, void (*sort_func)(char **, int), char **original, int n) {
    char **arr = malloc(n * sizeof(char *));
    size_t memory_used = n * sizeof(char *) + n * MAX_WORD_LENGTH;

    copy_words(original, arr, n);

    clock_t start = clock();
    sort_func(arr, n);
    clock_t end = clock();

    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("%-15s | Data: %7d | Waktu: %.3fs | Memori: %8zu bytes\n", name, n, elapsed_time, memory_used);

    free_words(arr, n);
}

// Untuk Merge & Quick Sort perlu versi string-based
void merge_sort_string(char **arr, int left, int right); // Implementasi harus ada
void quick_sort_string(char **arr, int left, int right); // Implementasi harus ada

void test_merge_sort_string(char **original, int n) {
    char **arr = malloc(n * sizeof(char *));
    size_t memory_used = n * sizeof(char *) + n * MAX_WORD_LENGTH;

    copy_words(original, arr, n);

    clock_t start = clock();
    merge_sort_string(arr, 0, n - 1);
    clock_t end = clock();

    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("%-15s | Data: %7d | Waktu: %.3fs | Memori: %8zu bytes\n", "Merge Sort", n, elapsed_time, memory_used);

    free_words(arr, n);
}

void test_quick_sort_string(char **original, int n) {
    char **arr = malloc(n * sizeof(char *));
    size_t memory_used = n * sizeof(char *) + n * MAX_WORD_LENGTH;

    copy_words(original, arr, n);

    clock_t start = clock();
    quick_sort_string(arr, 0, n - 1);
    clock_t end = clock();

    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("%-15s | Data: %7d | Waktu: %.3fs | Memori: %8zu bytes\n", "Quick Sort", n, elapsed_time, memory_used);

    free_words(arr, n);
}

// ===========================
// MAIN FUNCTION
// ===========================

int main() {
    const char *angka_file = "data_angka.txt";
    const char *kata_file = "data_kata.txt";

    printf("========== UJI PERFORMA ALGORITMA SORTING (ANGKA) ==========\n");
    for (int i = 0; i < data_size_count; i++) {
        int n = data_sizes[i];
        int *original = malloc(n * sizeof(int));
        read_integers(angka_file, original, n);

        test_algorithm("Bubble Sort", bubble_sort, original, n);
        test_algorithm("Selection Sort", selection_sort, original, n);
        test_algorithm("Insertion Sort", insertion_sort, original, n);
        test_merge_sort(original, n);
        test_quick_sort(original, n);
        test_algorithm("Shell Sort", shell_sort, original, n);

        printf("-------------------------------------------------------------\n");

        free(original);
    }

    printf("\n========== UJI PERFORMA ALGORITMA SORTING (KATA) ==========\n");
    for (int i = 0; i < data_size_count; i++) {
        int n = data_sizes[i];
        char **original = malloc(n * sizeof(char *));
        read_words(kata_file, original, n);

        test_string_algorithm("Bubble Sort", bubble_sort_string, original, n);
        test_string_algorithm("Selection Sort", selection_sort_string, original, n);
        test_string_algorithm("Insertion Sort", insertion_sort_string, original, n);
        test_merge_sort_string(original, n);
        test_quick_sort_string(original, n);
        test_string_algorithm("Shell Sort", shell_sort_string, original, n);

        printf("-------------------------------------------------------------\n");

        free_words(original, n);
    }

    return 0;
}
