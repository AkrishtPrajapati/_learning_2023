#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

struct LogEntry {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char time[10];
};

void displayLog(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];

    // Read and discard the header line
    fgets(line, MAX_LINE_LENGTH, file);

    printf("Log Entries:\n");
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        struct LogEntry entry;
        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,]",
               &entry.entryNo, entry.sensorNo, &entry.temperature,
               &entry.humidity, &entry.light, entry.time);

        printf("EntryNo: %d\n", entry.entryNo);
        printf("SensorNo: %s\n", entry.sensorNo);
        printf("Temperature: %.2f\n", entry.temperature);
        printf("Humidity: %d\n", entry.humidity);
        printf("Light: %d\n", entry.light);
        printf("Time: %s\n", entry.time);
        printf("\n");
    }

    fclose(file);
}

int main() {
    const char *filename = "data.csv";
    displayLog(filename);

    return 0;
}
