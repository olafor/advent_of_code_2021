#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 11

void extractInput(char rawLine[LINE_LENGTH], char **dir, int *mag) {
    char *refinedLine = (char *)malloc(strlen(rawLine) + 1);
    strcpy(refinedLine, rawLine);

    if ((*dir= strsep(&refinedLine, " ")) == NULL) {
        printf("Error 1...\n");
    }

    char *str;
    if ((str = strsep(&refinedLine, " ")) != NULL) {
        *mag= atoi(str);
    }
    else
        printf("Error 2...\n");
}

void updatePosition(char *dir, int mag, int *hPos, int *dPos) {
    if (strncmp(dir, "forward", strlen(dir)) == 0)
        *hPos += mag;
    else if (strncmp(dir, "up", strlen(dir)) == 0)
        *dPos -= mag;
    else if (strncmp(dir, "down", strlen(dir)) == 0)
        *dPos += mag;
    else
        printf("Error 3...\n");
}

int main() {
    FILE *fileStream;
    char line[LINE_LENGTH] = "";
    char *direction = "";
    int magnitude = 0;
    int horizontalPosition = 0;
    int depth = 0;

    if ((fileStream = fopen("DiveInput.txt", "r"))) {
        while (fgets(line, LINE_LENGTH, fileStream)) {
            extractInput(line, &direction, &magnitude);
            updatePosition(direction, magnitude, &horizontalPosition, &depth);
        }

        printf("Result: %d\n", horizontalPosition * depth);
    }

    fclose(fileStream);

    return 0;
}
