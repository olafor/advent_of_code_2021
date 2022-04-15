#include <stdio.h>

int main() {
    FILE *fileStream;
    int sum = 0;
    int latest = -1;
    int window[] = {-1, -1, -1, -1};
    if ((fileStream = fopen("SonarSweepInput.txt", "r"))) {
        while (fscanf(fileStream, "%d", &latest) != EOF) {
            if (window[2] != -1) {
                if (window[0] > window[3]) {
                    sum += 1;
                }
            } 
            for (int i = 2; i >= 0; i -= 1) {
                window[i+1] = window[i];
            }
            window[0] = latest;
        } 
    }
    printf("%d\n", sum);
    return 0;
}
