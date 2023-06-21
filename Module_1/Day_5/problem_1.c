#include <stdio.h>

struct Box {
    float length;
    float width;
    float height;
};

float calculateVolume(struct Box* boxPtr) {
    return boxPtr->length * boxPtr->width * boxPtr->height;
}

float calculateSurfaceArea(struct Box* boxPtr) {
    return 2 * (boxPtr->length * boxPtr->width + boxPtr->length * boxPtr->height + boxPtr->width * boxPtr->height);
}

int main() {
    struct Box box;
    struct Box* boxPtr = &box;

    printf("Enter the dimensions of the box:\n");
    printf("Length: ");
    scanf("%f", &(boxPtr->length));
    printf("Width: ");
    scanf("%f", &(boxPtr->width));
    printf("Height: ");
    scanf("%f", &(boxPtr->height));

    float volume = calculateVolume(boxPtr);
    float surfaceArea = calculateSurfaceArea(boxPtr);

    printf("\nVolume of the box: %.2f\n", volume);
    printf("Total surface area of the box: %.2f\n", surfaceArea);

    return 0;
}
