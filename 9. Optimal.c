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
    // int time[f];
    for(int i = 0;i<f;i++)
    {
        frame[i] = -1;
        // time[i] = 0;
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
            // time[idx] = i;
        }
        else
        {
            faults++;
            int zero = -1;
            for(int q = 0;q < f;q++)
            {
                if(frame[q] == -1)
                {
                    zero = q;
                    break;
                }
            }
            if(zero !=-1)
            {
                frame[zero] = pages[i];
                
            }
            else
            {
                int pos = -1;
                int farthest = i;
                // int k = -1;
                for(int k = 0;k < f;k++)
                {
                    int l;
                    for(l = i;l < p;l++)
                    {
                        if(frame[k] == pages[l])
                        {
                            if(l > farthest)
                            {
                                farthest = l;
                                pos = k;
                            }
                            break;
                        }
                    }
                    if(l == p)
                    {
                        farthest = l;
                        pos = k;
                    }
                }
                frame[pos] = pages[i]; 
            }
        }
        for(int i = 0;i < f;i++)
        {
            printf(" %d ",frame[i]);
        }
        printf("\n");
    }
    printf("\nPage Faults : %d\nPage Hits : %d",faults,hits);
}
