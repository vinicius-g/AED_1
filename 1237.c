#include <stdio.h>
#include <string.h>

int main() {
    char string1[51], string2[51], result, maxResult;
    int i, j;

    while (scanf(" %[^\n]", string1) != EOF && scanf(" %[^\n]", string2) != EOF) {
        result = 0;
        maxResult = 0;

        for (i = 0; i < (int)strlen(string1); i++) {
            for (j = 0; j < (int)strlen(string2); j++) {
                if (string1[i] == string2[j]) {
                    result = 1;

                    while (string1[i + result] == string2[j + result] && i + result < (int)strlen(string1) && j + result < (int)strlen(string2)) {
                        result++;
                    }

                    if (result > maxResult) {
                        maxResult = result;
                    }
                }
            }
        }

        printf("%d\n", maxResult);
    }
}