#include <stdio.h>

int main() {
    FILE *sourceFile, *targetFile;
    char sourceFileName[100], targetFileName[100];
    char ch;

    printf("Enter the name of the source file: ");
    scanf("%s", sourceFileName);

    printf("Enter the name of the target file: ");
    scanf("%s", targetFileName);

    // Open the source file in read mode
    sourceFile = fopen(sourceFileName, "r");

    // Check if the source file exists
    if (sourceFile == NULL) {
        printf("Source file '%s' not found.\n", sourceFileName);
        return 1;
    }

    // Open the target file in write mode
    targetFile = fopen(targetFileName, "w");

    // Copy the contents of the source file to the target file
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, targetFile);
    }

    printf("File copied successfully.\n");

    // Close the files
    fclose(sourceFile);
    fclose(targetFile);

    return 0;
}
