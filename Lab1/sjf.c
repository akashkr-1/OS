#include <stdio.h>

void sjf(int at[], int bt[], int n) {
    int pid[n], ct[n], tat[n], wt[n], finished[n];
    float avg_tat = 0, avg_wt = 0;

    // Assign process IDs
    for (int i = 0; i < n; i++) {
        pid[i] = i+1;
        finished[i] = 0;
    }

    // Sort by arrival time
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (at[i] > at[j]) {
                int temp;
                temp = at[i]; at[i] = at[j]; at[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = pid[i]; pid[i] = pid[j]; pid[j] = temp;
            }
        }
    }

    int current_time = 0, completed = 0;

    while (completed < n) {
        int idx = -1;
        int min_bt = 99999;

        // Finding smallest BT in ready queue
        for (int i = 0; i < n; i++) {
            if (!finished[i] && at[i] <= current_time) {
                if (bt[i] < min_bt) {
                    min_bt = bt[i];
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            // No process ready, CPU idle
            current_time++;
        } else {
            // Execute selected process
            current_time += bt[idx];
            ct[idx] = current_time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            finished[idx] = 1;
            completed++;
        }
    }

    // Print results
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P[%d]\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat/n);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt/n);
}

int main() {
    printf("Name: AKASH K R\n USN: 1BM24CS027\n\n");
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n];
    for (int i = 0; i < n; i++) {
        printf("P[%d]\t", i+1);
        printf("AT[%d]: ", i+1);
        scanf("%d", &at[i]);
        printf("\tBT[%d]: ", i+1);
        scanf("%d", &bt[i]);
    }

    sjf(at, bt, n);
    return 0;
}
