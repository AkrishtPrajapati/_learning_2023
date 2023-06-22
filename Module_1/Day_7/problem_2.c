#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void convertToUpper(char *str) {
    while (*str != '\0') {
        *str = toupper(*str);
        str++;
    }
}

void convertToLower(char *str) {
    while (*str != '\0') {
        *str = tolower(*str);
        str++;
    }
}

void convertToSentenceCase(char *str) {
    int firstChar = 1;
    while (*str != '\0') {
        if (firstChar) {
            *str = toupper(*str);
            firstChar = 0;
        } else {
            *str = tolower(*str);
        }

        if (*str == '.' || *str == '?' || *str == '!') {
            firstChar = 1;
        }

        str++;
    }
}

void copyFile(const char *sourceFileName, const char *targetFileName, char option) {
    FILE *sourceFile, *targetFile;
    char ch;

    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Source file '%s' not found.\n", sourceFileName);
        return;
    }

    targetFile = fopen(targetFileName, "w");
    if (targetFile == NULL) {
        printf("Error creating target file '%s'.\n", targetFileName);
        fclose(sourceFile);
        return;
    }

    while ((ch = fgetc(sourceFile)) != EOF) {
        if (option == 'u') {
            ch = toupper(ch);
        } else if (option == 'l') {
            ch = tolower(ch);
        } else if (option == 's') {
            ch = tolower(ch);
        }

        fputc(ch, targetFile);
    }

    fclose(sourceFile);
    fclose(targetFile);
    printf("File copied successfully.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp <option> <sourceFile> <targetFile>\n");
        return 1;
    }

    char option = 'n';
    if (argc >= 4) {
        option = argv[1][1];
    }

    char *sourceFileName = argv[argc - 2];
    char *targetFileName = argv[argc - 1];

    copyFile(sourceFileName, targetFileName, option);

    return 0;
}
