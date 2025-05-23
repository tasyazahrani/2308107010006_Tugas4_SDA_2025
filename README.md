# Tugas 04: Implementasi dan Analisis Algoritma Sorting
Nama: Tasya Zahrani
NPM: 2308107010006
Kelas: Struktur Data dan Algoritma D

## 📌 Deskripsi Tugas
Tugas ini bertujuan untuk mengimplementasikan dan menganalisis performa berbagai algoritma pengurutan (sorting) menggunakan bahasa pemrograman C, baik untuk data angka maupun data kata, serta mengukur waktu eksekusi dari masing-masing algoritma.
Kasus yang Diimplementasikan:
- Pengurutan data angka menggunakan 6 algoritma sorting.
- Pengurutan data kata (string) menggunakan algoritma yang sama.
- Analisis waktu eksekusi dari setiap algoritma untuk berbagai ukuran data.
- Perbandingan performa sorting terhadap dataset berbeda.

## Struktur Folder
```
Tugas04/
│── bubble_sort.h               # Implementasi Bubble Sort
│── selection_sort.h            # Implementasi Selection Sort
│── insertion_sort.h            # Implementasi Insertion Sort
│── merge_sort.h                # Implementasi Merge Sort
│── shell_sort.h                # Implementasi Shell Sort
│── quick_sort.h                # Implementasi Quick Sort
│── data_angka.txt              # Dataset angka
│── data_kata.txt               # Dataset kata (string)
│── memuatAngka.c               # Membuat dan menyimpan data angka ke file
│── memuatAngka.exe             # Hasil kompilasi memuatAngka.c
│── memuatKata.c                # Membuat dan menyimpan data kata ke file
│── memuatKata.exe              # Hasil kompilasi memuatKata.c
│── main.c                      # File utama untuk menjalankan program
│── main.exe                    # Hasil kompilasi main.c
│── README.md                   # Dokumentasi tugas
```

## ⚙️ Deskripsi Fungsi Program
1. Generate Dataset
Program memuatAngka.c dan memuatKata.c digunakan untuk membuat data random yang kemudian disimpan ke file data_angka.txt dan data_kata.txt.

2. Implementasi Algoritma Sorting
6 algoritma sorting diimplementasikan secara modular di dalam file header (.h):
- Bubble Sort
- Selection Sort
- Insertion Sort
- Merge Sort
- Shell Sort
- Quick Sort

3. Eksekusi Program Utama
main.c membaca dataset, menerapkan seluruh algoritma sorting terhadap data tersebut, dan mencatat waktu eksekusi dari masing-masing metode.

## Contoh Output 
```
========== UJI PERFORMA ALGORITMA SORTING (ANGKA) ==========
Bubble Sort     | Data:   10000 | Waktu: 0.103s | Memori:    40000 bytes
Selection Sort  | Data:   10000 | Waktu: 0.066s | Memori:    40000 bytes
Insertion Sort  | Data:   10000 | Waktu: 0.037s | Memori:    40000 bytes
Merge Sort      | Data:   10000 | Waktu: 0.001s | Memori:    40000 bytes
Quick Sort      | Data:   10000 | Waktu: 0.000s | Memori:    40000 bytes
Shell Sort      | Data:   10000 | Waktu: 0.000s | Memori:    40000 bytes
-------------------------------------------------------------
```
```
========== UJI PERFORMA ALGORITMA SORTING (KATA) ==========
Bubble Sort     | Data:   10000 | Waktu: 0.409s | Memori:   540000 bytes
Selection Sort  | Data:   10000 | Waktu: 0.156s | Memori:   540000 bytes
Insertion Sort  | Data:   10000 | Waktu: 0.083s | Memori:   540000 bytes
Merge Sort      | Data:   10000 | Waktu: 0.003s | Memori:   540000 bytes
Quick Sort      | Data:   10000 | Waktu: 0.002s | Memori:   540000 bytes
Shell Sort      | Data:   10000 | Waktu: 0.002s | Memori:   540000 bytes
-------------------------------------------------------------
```

## ⚠️ Catatan
- Dataset diuji dengan ukuran berbeda: 10.000, 50.000, 100.000, 250.000, 500.000, 1.000.000, 1.500.000, dan 2.000.000 data.
- Gunakan fungsi clock() untuk mengukur waktu eksekusi sorting.
- Lakukan pengujian pada kedua jenis data: angka dan kata.
- Data kata berupa string acak untuk menguji stabilitas algoritma pada tipe data non-numerik.

Dapat juga dilihat di github melalui link berikut ini https://github.com/tasyazahrani/2308107010006_Tugas4_SDA_2025.git 

(c) 2025 - tasyazahrani