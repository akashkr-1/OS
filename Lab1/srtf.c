#include <stdio.h>
#include <limits.h>

void srtf(int n, int at[], int bt[]) {
    int rt[n], ct[n], tat[n], wt[n];
    int completed = 0, current_time = 0;
    float total_wt = 0, total_tat = 0;

    for(int i = 0; i < n; i++)
        rt[i] = bt[i];

    while(completed < n) {
        int shortest = -1;
        int min_rt = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(at[i] <= current_time && rt[i] > 0) {
                if(rt[i] < min_rt || (rt[i] == min_rt && at[i] < at[shortest])) {
                    min_rt = rt[i];
                    shortest = i;
                }
            }
        }

        if(shortest == -1) {
            current_time++;
        } else {
            rt[shortest]--;
            current_time++;

            if(rt[shortest] == 0) {
                completed++;
                ct[shortest] = current_time;
                tat[shortest] = ct[shortest] - at[shortest];
                wt[shortest] = tat[shortest] - bt[shortest];

                total_wt += wt[shortest];
                total_tat += tat[shortest];
            }
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
}

int main() {
    printf("Name: AKASH K R\nUSN: 1BM24CS027\n");
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n];
    for(int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    srtf(n, at, bt);
    return 0;
}