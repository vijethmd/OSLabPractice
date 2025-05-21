#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct Process 
{
    int pid;
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;
    int RT;
    int DONE;
};

int main()
{
    int n;
    printf("\nEnter the number of processes : \n");
    scanf("%d",&n);
    struct Process p[n];
    for(int i = 0;i<n;i++)
    {
        p[i].pid = i+1;
        printf("\nEnter AT and BT for P%d : ",i+1);
        scanf("%d %d",&p[i].AT,&p[i].BT);
        p[i].DONE = 0;
    }
    int current = 0,count = 0;
    
    while(count < n)
    {
        int idx = -1;
        int minBT = 10000;
        for(int i = 0;i<n;i++)
        {
            if(p[i].AT <= current && p[i].DONE == 0)
            {
                if(p[i].BT < minBT)
                {
                    minBT = p[i].BT;
                    idx = i;
                }
            }
        }
        if(idx != -1)
        {
            p[idx].CT = current + p[idx].BT;
            p[idx].TAT = p[idx].CT - p[idx].AT;
            p[idx].WT = p[idx].TAT - p[idx].BT;
            p[idx].RT = p[idx].WT;
            current = p[idx].CT;
            p[idx].DONE = 1;
            count++;
        }
        else
        {
            current++;
        }
    }
    int TotalTAT = 0,TotalWT = 0,TotalRT = 0;
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i = 0;i<n;i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d",p[i].pid,p[i].AT,p[i].BT,p[i].CT,p[i].TAT,p[i].WT,p[i].RT);
        TotalTAT += p[i].TAT;
        TotalWT += p[i].WT;
        TotalRT += p[i].RT;
    }
    float AvgTAT = (float)TotalTAT/n;
    float AvgWT = (float)TotalWT/n;
    float AvgRT = (float)TotalRT/n;
    printf("\nAvgTAT : %.2f \nAvgWT : %.2f \nAvgRT : %.2f",AvgTAT,AvgWT,AvgRT);
}
