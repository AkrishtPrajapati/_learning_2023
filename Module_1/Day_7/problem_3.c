#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_ENTRIES 100

struct LogEntry {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char time[10];
};

int extractLog(const char *filename, struct LogEntry *logEntries) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 0;
    }

    char line[MAX_LINE_LENGTH];

    // Read and discard the header line
    fgets(line, MAX_LINE_LENGTH, file);

    int count = 0;
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        struct LogEntry entry;
        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,]",
               &entry.entryNo, entry.sensorNo, &entry.temperature,
               &entry.humidity, &entry.light, entry.time);

        logEntries[count++] = entry;
    }

    fclose(file);
    return count;
}

void displayLog(const struct LogEntry *logEntries, int count) {
    printf("Log Entries:\n");
    for (int i = 0; i < count; i++) {
        printf("EntryNo: %d\n", logEntries[i].entryNo);
        printf("SensorNo: %s\n", logEntries[i].sensorNo);
        printf("Temperature: %.2f\n", logEntries[i].temperature);
        printf("Humidity: %d\n", logEntries[i].humidity);
        printf("Light: %d\n", logEntries[i].light);
        printf("Time: %s\n", logEntries[i].time);
        printf("\n");
    }
}

int main() {
    const char *filename = "data.csv";
    struct LogEntry logEntries[MAX_ENTRIES];

    int count = extractLog(filename, logEntries);
    if (count > 0) {
        displayLog(logEntries, count);
    }

    return 0;
}
