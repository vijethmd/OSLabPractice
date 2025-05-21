#include<stdio.h>
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
};

int main()
{
    int n;
    printf("Enter the number of processes : \n");
    scanf("%d",&n);
    struct Process p[n];
    for(int i = 0;i<n;i++)
    {
        p[i].pid = i + 1;
        printf("\nEnter the AT and BT of P%d : ",i+1);
        scanf("%d %d",&p[i].AT,&p[i].BT);
    }
    
    for(int i = 0;i<n;i++)
    {
        for(int j = i + 1;j< n - i - 1;j++)
        {
            if(p[j].AT > p[j+1].AT)
            {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    
    for(int i = 0;i<n-1;i++)
    {
        if(p[i].AT == p[i+1].AT)
        {
            if(p[i].pid > p[i+1].pid)
            {
                struct Process temp = p[i];
                p[i] = p[i+1];
                p[i+1] = temp;
            }
        }
    }
    
    int current = 0;
    for(int i = 0;i<n;i++)
    {
        if(current < p[i].AT)
        {
            current = p[i].AT;
        }
        p[i].CT = current + p[i].BT;
        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BT;
        p[i].RT = p[i].WT;
        current = p[i].CT;
    }
    float AvgTAT = 0, AvgWT = 0, AvgRT = 0;
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i = 0;i<n;i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d",p[i].pid,p[i].AT,p[i].BT,p[i].CT,p[i].TAT,p[i].WT,p[i].RT);
        AvgTAT += (float)p[i].TAT;
        AvgWT += (float)p[i].WT;
        AvgRT += (float)p[i].RT;
    }
    AvgTAT = AvgTAT/n;
    AvgWT = AvgWT/n;
    AvgRT = AvgRT/n;
    printf("\nAvgTAT : %.2f \nAvgWT : %.2f \nAvgRT : %.2f",AvgTAT,AvgWT,AvgRT);
}
