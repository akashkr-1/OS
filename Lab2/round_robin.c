#include <stdio.h>
#include <stdlib.h>

void round_robin(int at[], int bt[], int n, int quantum) {
    int rt_remaining[n], ct[n], tat[n], wt[n], rt[n];
    int first_visit[n]; 
    int time = 0, count = 0;
    float avg_tat = 0, avg_wt = 0, avg_rt = 0;

    int queue[1000], head = 0, tail = 0;
    int in_queue[n];

    for (int i = 0; i < n; i++) {
        rt_remaining[i] = bt[i];
        in_queue[i] = 0;
        first_visit[i] = 1; 
    }

    for (int i = 0; i < n; i++) {
        if (at[i] <= time) {
            queue[tail++] = i;
            in_queue[i] = 1;
        }
    }

    while (count < n) {
        if (head == tail) { 
            time++;
            for (int i = 0; i < n; i++) {
                if (at[i] <= time && rt_remaining[i] > 0 && in_queue[i] == 0) {
                    queue[tail++] = i;
                    in_queue[i] = 1;
                }
            }
            continue;
        }

        int idx = queue[head++];
    
        if (first_visit[idx]) {
            rt[idx] = time - at[idx];
            first_visit[idx] = 0;
            avg_rt += rt[idx];
        }

        if (rt_remaining[idx] > quantum) {
            time += quantum;
            rt_remaining[idx] -= quantum;
        } else {
            time += rt_remaining[idx];
            rt_remaining[idx] = 0;
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            count++;
        }

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt_remaining[i] > 0 && in_queue[i] == 0) {
                queue[tail++] = i;
                in_queue[i] = 1;
            }
        }

        if (rt_remaining[idx] > 0) {
            queue[tail++] = idx;
        } else {
            in_queue[idx] = 0; 
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
        avg_tat += tat[i];
        avg_wt += wt[i];
    }
    printf("\nAvg TAT: %.2f", avg_tat / n);
    printf("\nAvg WT: %.2f", avg_wt / n);
    printf("\nAvg RT: %.2f\n", avg_rt / n);
}

int main() {
    int n, quantum;
    printf("USN: 1BM24CS027\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    int at[n], bt[n];
    printf("Enter the AT and BT\n");
    for (int i = 0; i < n; i++) {
        printf("p[%d] : ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    round_robin(at, bt, n, quantum);
    return 0;
}