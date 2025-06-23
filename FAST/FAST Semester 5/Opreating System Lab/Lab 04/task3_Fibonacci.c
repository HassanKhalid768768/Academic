#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int first = 0, second = 1;

    for (int i = 0; i < n; i++) {
        printf("%d ", first);
        int next = first + second;
        first = second;
        second = next;
    }

    printf("\n");

    return 0;
}

