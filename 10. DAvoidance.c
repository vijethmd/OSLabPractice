#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
    int r,p;
    printf(" Enter number of processes and resources : ");
    scanf("%d %d",&p,&r);
    int allocation[p][r];
    int need[p][r];
    int max[p][r];
    int available[r];
    int work[r];
    bool finish[p];
    printf("\nEnter allocation matrix : \n");
    for(int i = 0;i < p;i++)
    {
        for(int j = 0;j < r;j++)
        {
            scanf("%d",&allocation[i][j]);
        }
    }
    printf("\nEnter available vector : \n");
    for(int i = 0;i < r;i++)
    {
        scanf("%d",&available[i]);
    }
    printf("\nEnter Max matrix : \n");
    for(int i = 0;i < p;i++)
    {
        for(int j = 0;j < r;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    for(int i = 0;i < p;i++)
    {
        for(int j = 0;j < r;j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    for(int i = 0;i < r;i++)
    {
        work[i] = available[i];
    }
    for(int i = 0;i < p;i++)
    {
        finish[i] = false;
    }
    int count = 0;
    int seq[p];
    for(int i = 0;i < p;i++)
    {
        seq[i] = -1;
    }
    int seqpos = -1;
    while(count < p)
    {
        int idx = -1;
        for(int i = 0;i < p;i++)
        {
            int j;
            if(finish[i] == false)
            {
                for(j = 0;j < r;j++)
                {
                    if(need[i][j] > work[j])
                    {
                        break;
                    }
                }
                if(j == r)
                {
                idx = i;
                break;
                }
            }
            
        }
        if(idx != -1)
        {
            for(int i = 0;i < r;i++)
            {
                work[i] = work[i] + allocation[idx][i];
            }
            finish[idx] = true;
            count++;
            seqpos++;
            seq[seqpos] = idx;
        }
        else
        {
            printf("\nDeadlock present");
            return 0;
        }
    }
    printf("\n System is in safe state");
    printf("\nSafe Sequence : ");
    for(int i = 0;i < p;i++)
    {
        printf(" P%d ",seq[i]);
    }
    
    
    
    
    
    
    
    
    
    
    
}
