#include<stdio.h>
#include<stdlib.h>


void fcfs(int at[], int bt[], int n) {
    int ct[n], tat[n], wt[n], rt[n], start[n];
    float total_tat = 0, total_wt = 0, total_rt = 0;

    // Sort
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(at[i] > at[j]) {
                int temp;
                temp = at[i]; at[i] = at[j]; at[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
            }
        }
    }

    // Completion & start times
    start[0] = at[0];
    ct[0] = start[0] + bt[0];
    for(int i=1; i<n; i++) {
        if(at[i] > ct[i-1]) {
            start[i] = at[i];
        } else {
            start[i] = ct[i-1];
        }
        ct[i] = start[i] + bt[i];
    }

    // TAT, WT, RT
    for(int i=0; i<n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        rt[i] = start[i] - at[i];
        total_tat += tat[i];
        total_wt += wt[i];
        total_rt += rt[i];
    }

    // Display results
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i=0; i<n; i++) {
        printf("P[%d]\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }

    printf("\nAverage TAT = %.2f", total_tat/n);
    printf("\nAverage WT = %.2f", total_wt/n);
    printf("\nAverage RT = %.2f\n", total_rt/n);
}

int main() {
    int n;
    printf("Name: AKASH K R\nUSN:1BM24CS027\n\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n];
    for(int i=0; i<n; i++) {
        printf("P[%d]\n", i+1);
        printf("AT[%d]: ", i+1);
        scanf("%d", &at[i]);
        printf("BT[%d]: ", i+1);
        scanf("%d", &bt[i]);
    }

    fcfs(at, bt, n);
    return 0;
}
