#include <stdio.h>
#include <stdlib.h>

// Structure for an activity
struct Activity {
    int start;
    int finish;
    int index;
};

// Comparison function for qsort
int compare(const void *a, const void *b) {
    struct Activity *actA = (struct Activity *)a;
    struct Activity *actB = (struct Activity *)b;
    return (actA->finish - actB->finish);
}

// Function to perform Activity Selection
void activitySelection(struct Activity activities[], int n) {
    // Sort activities according to finish time
    qsort(activities, n, sizeof(struct Activity), compare);

    printf("\nSelected Activities (Greedy Approach):\n");

    // The first activity always gets selected
    int i = 0;
    printf("Activity %d (Start: %d, Finish: %d)\n", activities[i].index, activities[i].start, activities[i].finish);

    // Consider the rest of the activities
    for (int j = 1; j < n; j++) {
        // If this activity starts after or when the last selected activity finished
        if (activities[j].start >= activities[i].finish) {
            printf("Activity %d (Start: %d, Finish: %d)\n", activities[j].index, activities[j].start, activities[j].finish);
            i = j;
        }
    }
}

int main() {
    int n;
    printf("Enter number of activities: ");
    scanf("%d", &n);

    struct Activity activities[n];

    printf("Enter start and finish times of activities:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d:\n", i + 1);
        printf("Start time: ");
        scanf("%d", &activities[i].start);
        printf("Finish time: ");
        scanf("%d", &activities[i].finish);
        activities[i].index = i + 1; // Store activity index
    }

    activitySelection(activities, n);

    return 0;
}
