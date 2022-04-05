#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000
#define SIZE 100
#define NUMS_TO_GENERATE 100

int main() {
    srand(time(NULL));
    for (int i = 0; i < NUMS_TO_GENERATE; i++){
        printf("%d ", rand() % MAX);
    }

    exit(EXIT_SUCCESS);
}
