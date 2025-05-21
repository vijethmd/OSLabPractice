#include<stdio.h>
#include<stdlib.h>

struct Process 
{
    int pid, AT, BT, CT, TAT, WT, RT, ResT, fcpu, visited, DONE;
};

int main()
{
    int n,quant;
    printf("Enter the number of processes and time quantum : ");
    scanf("%d %d",&n,&quant);
    struct Process p[n];
    int queue[n*100];
    int front = 0,rear = 0;
    for(int i = 0;i<n;i++)
    {
        p[i].pid = i+1;
        printf("Enter AT and BT of P%d : ",i+1);
        scanf("%d %d",&p[i].AT,&p[i].BT);
        p[i].DONE = 0;
        p[i].visited = 0;
        p[i].RT = p[i].BT;
        // p[i].ResT = -1;
    }
    for(int i = 0;i<n-1;i++)
    {
        for(int j = 0;j<n-i-1;j++)
        {
            if(p[j].AT > p[j+1].AT)
            {
                struct Process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    int count = 0;
    int current = 0;
    queue[rear++] = 0;
    while(count < n)
    {
        if(front >= rear) {  
        current++;
        continue;
    }

        int idx = queue[front++];
        if(p[idx].visited == 0)
        {
            p[idx].visited = 1;
            p[idx].ResT = current - p[idx].AT;
        }
        if(p[idx].RT >= quant)
        {
            p[idx].RT -= quant;
            current = current + quant;
            if(p[idx].RT == 0)
            {
                count++;
                p[idx].CT = current;
                p[idx].TAT = p[idx].CT - p[idx].AT;
                p[idx].WT = p[idx].TAT - p[idx].BT;
                // p[idx].ResT = p[idx].fcpu - p[idx].AT;
                p[idx].DONE = 1;
            }
        }
        else
        {
            current += p[idx].RT;
            p[idx].RT = 0;
            count++;
            p[idx].CT = current;
            p[idx].TAT = p[idx].CT - p[idx].AT;
            p[idx].WT = p[idx].TAT - p[idx].BT;
            // p[idx].ResT = p[idx].fcpu - p[idx].AT;
            p[idx].DONE = 1;
        }
        for(int i = 0;i<n;i++)
        {
            if(p[i].AT <= current && p[i].visited == 0)
            {
                queue[rear++] = i;
                // p[i].visited = 1;
            }
        }
        if(p[idx].RT > 0) queue[rear++] = idx;
    }
    
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\tRT");
    int TTAT = 0,TWT = 0,TRT = 0;
    for(int i = 0;i<n;i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d",p[i].pid,p[i].AT,p[i].BT,p[i].CT,p[i].TAT,p[i].WT,p[i].ResT);
        TTAT += p[i].TAT;
        TWT += p[i].WT;
        TRT += p[i].ResT;
    }
    float ATAT,AWT,ART;
    ATAT = (float)TTAT/n;
    AWT = (float)TWT/n;
    ART = (float)TRT/n;
    printf("\nAvgTAT : %.2f\tAvgWT : %.2f\tAvgRT : %.2f",ATAT,AWT,ART);
}
