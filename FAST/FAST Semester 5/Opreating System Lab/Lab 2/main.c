#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <array elements> <order> <position>\n", argv[0]);
        return 1;
    }

    int n = argc - 3; // Calculate the number of elements
    int array[n];

    for (int i = 1; i <= n; i++) {
        array[i - 1] = atoi(argv[i]);
    }

    int order = atoi(argv[n + 1]);
    int position = atoi(argv[n + 2]);

    printf("Array Elements: ");
    print(array, n);

    sort(array, order, n);
    printf("Sorted Elements: ");
    print(array, n);

    findHighest(array, position, n);

    return 0;
}

