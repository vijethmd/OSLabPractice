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
    int ResT;
    int visited;
    int fcpu;
    int DONE;
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
        p[i].DONE = 0;
        p[i].visited = 0;
        p[i].RT = p[i].BT;
    }
    int count = 0;
    int current = 0;
    while(count < n)
    {
        int idx = -1;
        int HP = -1;
        for(int i = 0;i<n;i++)
        {
            if(current >= p[i].AT && p[i].DONE == 0)
            {
                if(p[i].P > HP)
                {
                    HP = p[i].P;
                    idx = i;
                }
            }
        }
        if(p[idx].visited == 0)
        {
            p[idx].visited = 1;
            p[idx].fcpu = current;
        }
        if(p[idx].RT > 1)
        {
            p[idx].RT--;
            current++;
        }
        else
        {
            p[idx].CT = current + 1;
            p[idx].TAT = p[idx].CT - p[idx].AT;
            p[idx].WT = p[idx].TAT - p[idx].BT;
            p[idx].RT = p[idx].fcpu - p[idx].AT;
            current++;
            p[idx].DONE = 1;
            count++;
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
