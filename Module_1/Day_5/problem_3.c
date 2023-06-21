#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct Time getTimeDifference(struct Time t1, struct Time t2);

int main() {
    struct Time startTime, endTime, difference;

    // Input start time
    printf("Enter start time (hh:mm:ss): ");
    scanf("%d:%d:%d", &startTime.hours, &startTime.minutes, &startTime.seconds);

    // Input end time
    printf("Enter end time (hh:mm:ss): ");
    scanf("%d:%d:%d", &endTime.hours, &endTime.minutes, &endTime.seconds);

    // Calculate difference
    difference = getTimeDifference(startTime, endTime);

    // Display the difference
    printf("Time difference: %02d:%02d:%02d\n", difference.hours, difference.minutes, difference.seconds);

    return 0;
}

struct Time getTimeDifference(struct Time t1, struct Time t2) {
    struct Time diff;

    // Convert both times to seconds
    int t1Seconds = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int t2Seconds = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    int secondsDiff = t2Seconds - t1Seconds;

    // Calculate the difference in hours, minutes, and seconds
    diff.hours = secondsDiff / 3600;
    secondsDiff %= 3600;
    diff.minutes = secondsDiff / 60;
    diff.seconds = secondsDiff % 60;

    return diff;
}
