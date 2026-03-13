#include<stdio.h>
#include<stdlib.h>

void pri_npre(int at[],int bt[],int p[],int n)
{
    int ct[n],tat[n],wt[n],completed[n];
    int time=0,count=0;
    float avg_tat=0,avg_wt=0;
    for(int i=0;i<n;i++)
    {
        completed[i]=0;
    }

    while(count<n)
    {
        int pri=999,idx=-1;
        for(int i=0;i<n;i++)
        {
            if(at[i]<=time && completed[i]==0 && p[i]<pri)
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
            ct[idx]=time+bt[idx];
            tat[idx]=ct[idx]-at[idx];
            wt[idx]=tat[idx]-bt[idx];
            time=ct[idx];
            completed[idx]=1;
            count++;
        }
    }
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
        avg_tat+=tat[i];
        avg_wt+=wt[i];
    }
    printf("Avg TAT: %.2f:",avg_tat/n);
    printf("Avg WT: %.2f:",avg_wt/n);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int at[n],bt[n],p[n];
    printf("Enter the AT,BT and Priority\n");
    for(int i=0;i<n;i++)
    {
        printf("p[%d] : ",i+1);
        scanf("%d%d%d",&at[i],&bt[i],&p[i]);
    }
    pri_npre(at,bt,p,n);
    return 0;
}
