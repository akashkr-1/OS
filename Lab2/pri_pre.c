#include<stdio.h>
#include<stdlib.h>

void pri_pre(int at[],int bt[],int p[],int rt[],int n)
{
    int time=0,comp=0;
    int ct[n],tat[n],wt[n];
    float avg_tat=0,avg_wt=0;

    while(comp<n)
    {
        int pri=999,idx=-1;
        for(int i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>0 && p[i]<pri)
            {
                pri=p[i];
                idx=i;
            }
        }
        if(idx==-1)
        {
            time++;
        }
        else{
            rt[idx]--;
            time++;
            if(rt[idx]==0){
                ct[idx]=time;
                tat[idx]=ct[idx]-at[idx];
                wt[idx]=tat[idx]-bt[idx];
                comp++;
            }
        }
    }
    printf("\nPID\tAT\tBT\tP\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
    {
        printf("P[%d]\t%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],p[i],ct[i],tat[i],wt[i]);
        avg_tat+=tat[i];
        avg_wt+=wt[i];
    }
    printf("Avg TAT: %.2f\n",avg_tat/n);
    printf("Avg WT: %.2f",avg_wt/n);
}

int main()
{
    printf("USN: 1BM24CS027\n");
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int at[n],bt[n],p[n],rt[n];
    printf("Enter the values of AT,BT,Priority\n");
    for(int i=0;i<n;i++)
    {
        printf("p[%d]:",i+1);
        scanf("%d%d%d",&at[i],&bt[i],&p[i]);
        rt[i]=bt[i];
    }
    pri_pre(at,bt,p,rt,n);
    return 0;
}
