#include<stdio.h>
#include<stdlib.h>

struct Process 
{
    int pid;
    int AT;
    int BT;
    int P;
    int CT;
    int TAT;
    int WT;
    int RT;
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
        printf("\nEnter AT, BT and Priority of P%d : ",i+1);
        scanf("%d %d %d",&p[i].AT,&p[i].BT,&p[i].P);
    }
    int count = 0;
    int current = 0;
    while(count < n)
    {
        int HP = -1;
        int idx = -1;
        for(int i = 0;i<n;i++)
        {
            if(current <= p[i].AT && HP < p[i].P)
            {
                HP = p[i].P;
                idx = i;
            }
            if(idx != -1)
                {
                    p[i].CT = current + p[i].BT;
                    p[i].TAT = p[i].CT - p[i].AT;
                    p[i].WT = p[i].TAT - p[i].BT;
                    p[i].RT = p[i].WT;
                    current = p[i].CT;
                    count++;
                }
            else
            {
                current++;
            }
        }
    }
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\tRT");
    int TTAT,TWT,TRT;
    for(int i = 0;i<n;i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d",p[i].pid,p[i].AT,p[i].BT,p[i].CT,p[i].TAT,p[i].WT,p[i].RT);
        TTAT += p[i].TAT;
        TWT += p[i].WT;
        TRT += p[i].RT;
    }
    float ATAT,AWT,ART;
    ATAT = (float)TTAT/n;
    AWT = (float)TWT/n;
    ART = (float)TRT/n;
    printf("\nAvgTAT : %.2f\tAvgWT : %.2f\tAvgRT : %.2f",ATAT,AWT,ART);
}
