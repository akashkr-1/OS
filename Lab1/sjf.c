#include<stdio.h>
#include<stdlib.h>

void sjf(int at[], int bt[], int n) {
    int ct[n], tat[n], wt[n], rt[n], start[n], finished[n];
    float total_tat = 0, total_wt = 0, total_rt = 0;


    for(int i=0; i<n; i++) {
        finished[i] = 0;
    }


    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(at[i] > at[j]) {
                int temp;
                temp = at[i]; at[i] = at[j]; at[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
            }
        }
    }

    int current_time = 0, completed = 0;

    while(completed < n) {
        int idx = -1;
        int min_bt = 99999;


        for(int i=0; i<n; i++) {
            if(!finished[i] && at[i] <= current_time) {
                if(bt[i] < min_bt) {
                    min_bt = bt[i];
                    idx = i;
                }
            }
        }

        if(idx == -1) {

            current_time++;
        } else {

            start[idx] = current_time;


            current_time += bt[idx];
            ct[idx] = current_time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            rt[idx] = start[idx] - at[idx];

            total_tat += tat[idx];
            total_wt += wt[idx];
            total_rt += rt[idx];

            finished[idx] = 1;
            completed++;
        }
    }


    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i=0; i<n; i++) {
        printf("P[%d]\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat/n);
    printf("\nAverage Waiting Time = %.2f", total_wt/n);
    printf("\nAverage Response Time = %.2f\n", total_rt/n);
}

int main() {
    printf("Name: AKASH K R\nUSN:1BM24CS027\n\n");
    int n;
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

    sjf(at, bt, n);
    return 0;
}
