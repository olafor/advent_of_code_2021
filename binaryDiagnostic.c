#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 13
#define INIT_SIZE 2

typedef struct {
    int *array;
    size_t used;
    size_t size;
} Array;

int main() {
    void initArray(Array*, size_t);
    void appendArray(Array*, int);
    void freeArray(Array*);
    unsigned int getGamma(Array*, unsigned int);
    unsigned int getEpsilon(unsigned int, unsigned int);

    FILE *fileStream;
    char line[BUFSIZE] = "";
    unsigned int numberOfEntries = 0;
    Array countsOfOnes;

    initArray(&countsOfOnes, INIT_SIZE);

    if ((fileStream = fopen("BinaryDiagnosticInput.txt", "r"))) {
        while (fgets(line, BUFSIZE, fileStream)) {
            if (strlen(line) > 1)
                ++numberOfEntries;

            for (int i = 0; i < strlen(line); ++i) {
                if (i >= countsOfOnes.used)
                    appendArray(&countsOfOnes, 0);
                if (line[i] == '1')
                    countsOfOnes.array[i] += 1;
            }
        }
    }

    unsigned int gamma = getGamma(&countsOfOnes, numberOfEntries);
    unsigned int epsilon = getEpsilon(gamma, countsOfOnes.used);

    printf("Result: %d\n", gamma * epsilon);
    freeArray(&countsOfOnes);
}

void initArray(Array *arr, size_t initSize) {
    arr->array = malloc(INIT_SIZE * sizeof(int));
    arr->used = 0;
    arr->size = INIT_SIZE;
}

void appendArray(Array *arr, int element) {
    if (arr->used == arr->size) {
        arr->size *= 2;
        arr->array = realloc(arr->array, arr->size * sizeof(int));
    }
    arr->array[arr->used++] = element;
}

void freeArray(Array *arr) {
    free(arr->array);
    arr->array = NULL;
    arr->used = arr->size = 0;
}

unsigned int getGamma(Array *arr, unsigned int noOfEntries) {
    unsigned int gamma = 0;
    unsigned int mask = 1;

    for (int i = arr->used - 1; i >= 0; --i) {
        if (arr->array[i] > noOfEntries / 2) 
            gamma = (gamma & ~mask) | (0xfff & mask);
        else 
            gamma = (gamma & ~mask) | (0 & mask);
        
        mask = mask << 1;
    }
    return gamma;
}

unsigned int getEpsilon(unsigned int gamma, unsigned int noOfBits) {
    unsigned int mask = 1;
    unsigned int epsilon = gamma;

    for (int i = 0; i < noOfBits; ++i) {
        epsilon = (epsilon & ~mask) | (~epsilon & mask);
        mask = mask << 1;
    }
    return epsilon;
}
