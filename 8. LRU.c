#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
    int p,f,hits = 0,faults = 0;
    printf(" Enter the number of frames : ");
    scanf("%d",&f);
    printf("\nEnter number of page requests : ");
    scanf("%d",&p);
    int frame[f];
    int pages[p];
    int time[f];
    for(int i = 0;i<f;i++)
    {
        frame[i] = -1;
        time[i] = 0;
    }
    for(int i = 0;i<p;i++)
    {
        printf("Enter page requests : ");
        scanf("%d",&pages[i]);
    }
    for(int i = 0;i < p;i++)
    {
        int idx = -1;
        
        for(int j = 0;j < f;j++)
        {
            if(frame[j] == pages[i])
            {
                idx = j;
                break;
            }
        }
        if(idx != -1)
        {
            hits++;
            time[idx] = i;
        }
        else
        {
            int pos = -1;
            for(int v = 0;v < f;v++)
            {
                if(frame[v] == -1)
                {
                    pos = v;
                    break;
                }
            }
            if(pos != -1)
            {
                faults++;
                frame[pos] = pages[i];
                time[pos] = i;
            }
            else
            {
                faults++;
                int minUsed = 0;
                for(int k = 1;k < f;k++)
                {
                    if(time[k] < time[minUsed]) minUsed = k;
                }
                frame[minUsed] = pages[i];
                time[minUsed] = i;
            }
        }
        for(int l = 0;l < f;l++)
        {
            printf(" %d ",frame[l]);
        }
        printf("\n");
    }
    printf("\nPage Hits : %d\nPage Faults : %d",hits,faults);
}
