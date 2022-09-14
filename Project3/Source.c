#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printFileChangeBraces(FILE* file);
int containsTrigger(char* str);
void findRowsWithTriggers(FILE* file);

int main()
{
    FILE* file = fopen("text.txt", "r");

    if (!file)
    {
        perror("File not found!");
        exit(0);
    }
    printf("Text from file:\n");
    printFileChangeBraces(file);
    fclose(file);

    file = fopen("text.txt", "r");
    printf("\n\nRows with for, while, do, if, else:\n");
    findRowsWithTriggers(file);
    fclose(file);

    return 0;
}

void printFileChangeBraces(FILE* file) {
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '[') {
            printf("(*");
        }
        else if (c == ']') {
            printf("*)");
        }
        else {
            printf("%c", c);
        }
    }
}

void findRowsWithTriggers(FILE* file) {
    char str[256];
    int n = 0;

    while (fgets(str, 256, file) != NULL) {
        if (containsTrigger(str)) {
            printf("%d\n", n + 1);
        }
        n++;
    }
}

int containsTrigger(char* str) {
    char* p = str;

    while ((*p) != '\0') {

        if ((*p) == 'f' && (*(p + 1)) == 'o' && (*(p + 2)) == 'r') {
            return 1;
        }

        if ((*p) == 'w' && (*(p + 1)) == 'h' && (*(p + 2)) == 'i' && (*(p + 3)) == 'l' && (*(p + 4)) == 'e') {
            return 1;
        }

        if ((*p) == 'i' && (*(p + 1)) == 'f') {
            return 1;
        }

        if ((*p) == 'd' && (*(p + 1)) == 'o') {
            return 1;
        }

        if ((*p) == 'e' && (*(p + 1)) == 'l' && (*(p + 2)) == 's' && (*(p + 3)) == 'e') {
            return 1;
        }
        p++;
    }

    return 0;
}