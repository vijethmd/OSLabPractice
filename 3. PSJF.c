#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Process 
{
    int pid;
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;
    int RT;
    int ResT;
    int DONE;
    int visited;
    int fcpu;
};

int main()
{
    int n;
    printf("Enter the number of processes : ");
    scanf("%d",&n);
    struct Process p[n];
    for(int i = 0;i<n;i++)
    {
        p[i].pid = i+1;
        printf("Enter AT and BT of P%d : ",i+1);
        scanf("%d %d",&p[i].AT,&p[i].BT);
        p[i].DONE = 0;
        p[i].visited = 0;
        p[i].RT = p[i].BT;
    }
    int current = 0,count = 0;
    while(count < n)
    {
        int idx =-1;
        int minBT = 1000;
        for(int i = 0;i<n;i++)
        {
            if(p[i].AT <= current && p[i].DONE == 0 && p[i].RT > 0)
            {
                if(p[i].RT < minBT)
                {
                    minBT = p[i].RT;
                    idx = i;
                }
            }
        }
        if(idx != -1)
        {
            if(p[idx].visited == 0) 
            {
                p[idx].visited = 1;
                p[idx].fcpu = current;
            }
            if(p[idx].RT > 1)
            {
                p[idx].RT -= 1;
                current++;
            }
            else if(p[idx].RT == 1)
            {
                p[idx].RT = 0;
                p[idx].CT = current + 1;
                p[idx].TAT = p[idx].CT - p[idx].AT;
                p[idx].WT = p[idx].TAT - p[idx].BT;
                p[idx].ResT = p[idx].fcpu - p[idx].AT;
                current++;
                p[idx].DONE = 1;
                count++;
            }
        }
        else
        {
            current++;
        }
    }
    int TotalTAT = 0, TotalWT = 0, TotalRT = 0;
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\tRT");
    for(int i = 0;i<n;i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d",p[i].pid,p[i].AT,p[i].BT,p[i].CT,p[i].TAT,p[i].WT,p[i].ResT);
        TotalTAT += p[i].TAT;
        TotalWT += p[i].WT;
        TotalRT += p[i].ResT;
    }
    float AvgTAT = (float)TotalTAT/n;
    float AvgWT = (float)TotalWT/n;
    float AvgRT = (float)TotalRT/n;
    printf("\nAvgTAT : %.2f \nAvgWT : %.2f \nAvgRT : %.2f",AvgTAT,AvgWT,AvgRT);
}















