#include <stdio.h>

void srtf(int n, int at[], int bt[])
{
    int rt[n], ct[n], tat[n], wt[n];
    int time = 0, done = 0;
    float total_wt = 0, total_tat = 0;

    for(int i = 0; i < n; i++)
        rt[i] = bt[i];

    while(done < n)
    {
        int pos = -1;
        int min = 9999;

        for(int i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0)
            {
                if(rt[i] < min)
                {
                    min = rt[i];
                    pos = i;
                }
            }
        }

        if(pos == -1)
        {
            time++;
        }
        else
        {
            rt[pos]--;
            time++;

            if(rt[pos] == 0)
            {
                done++;

                ct[pos] = time;
                tat[pos] = ct[pos] - at[pos];
                wt[pos] = tat[pos] - bt[pos];

                total_wt += wt[pos];
                total_tat += tat[pos];
            }
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat/n);
}

int main()
{
    printf("Name: AKASH K R\nUSN: 1BM24CS027\n");

    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n];

    for(int i = 0; i < n; i++)
    {
        printf("Enter Arrival Time and Burst Time for P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    srtf(n, at, bt);

    return 0;
}
