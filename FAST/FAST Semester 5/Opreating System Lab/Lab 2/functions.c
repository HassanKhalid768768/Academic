#include <stdio.h>
#include "header.h"

void sort(int array[], bool order, int n) {
    int temp;
    
    if (order) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    } else {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (array[j] < array[j + 1]) {
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }
}

void findHighest(int array[], int position, int n) {
    if (position >= 1 && position <= n) {
        printf("The %d highest value in the array is: %d\n", position, array[position - 1]);
    } else {
        printf("Invalid position. Position should be between 1 and %d.\n", n);
    }
}

void print(int array[], int n) {
    printf("Array Elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

