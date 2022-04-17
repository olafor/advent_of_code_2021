#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 11
#define FORWARD "forward"
#define UP "up"
#define DOWN "down"

int main() {
    void extractDirectionAndMagnitude(char rawLine[LINE_LENGTH], char**, int*);
    void updatePosition(char*, int, int*, int*, int*);

    FILE *fileStream;
    char line[LINE_LENGTH] = "";
    char *direction = "";
    int magnitude = 0;
    int horizontalPosition = 0;
    int depth = 0;
    int aim = 0;

    if ((fileStream = fopen("DiveInput.txt", "r"))) {
        while (fgets(line, LINE_LENGTH, fileStream)) {
            extractDirectionAndMagnitude(line, &direction, &magnitude);
            updatePosition(direction, magnitude, &horizontalPosition, &depth, &aim);
        }

        printf("Result: %d\n", horizontalPosition * depth);
    }

    fclose(fileStream);

    return 0;
}

void extractDirectionAndMagnitude(char rawLine[LINE_LENGTH], char **direction, int *magnitude) {
    char *refinedLine = (char *) malloc(strlen(rawLine) + 1);
    strcpy(refinedLine, rawLine);

    char *copiedRefinedLine = strdup(refinedLine);

    *direction = strsep(&copiedRefinedLine, " ");
    *magnitude = atoi(copiedRefinedLine);

    free(refinedLine);
}

void updatePosition(char *direction, int magnitude, int *hPos, int *dPos, int *aim) {
    if (strncmp(direction, FORWARD, strlen(direction)) == 0) {
        *hPos += magnitude;
        *dPos += magnitude * (*aim);
    }
    else if (strncmp(direction, UP, strlen(direction)) == 0)
        *aim -= magnitude;
    else if (strncmp(direction, DOWN, strlen(direction)) == 0)
        *aim += magnitude;
    else
        printf("Error...\n");
}
