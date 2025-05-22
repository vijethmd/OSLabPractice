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
    for(int i = 0;i<f;i++)
    {
        frame[i] = -1;
    }
    for(int i = 0;i<p;i++)
    {
        printf("Enter page requests : ");
        scanf("%d",&pages[i]);
    }
    int pos = -1;
    for(int i = 0;i<p;i++)
    {
        int idx = -1;
        for(int j = 0;j < f;j++)
        {
            if(pages[i] == frame[j])
            {
                idx = j;
                break;
            }
        }
        if(idx != -1)
        {
            hits++;
        }
        else
        {
            faults++;
            pos = (pos + 1)%f;
            frame[pos] = pages[i];
        }
        for(int l = 0;l<f;l++)
        {
            printf(" %d ",frame[l]);
        }
        printf("\n");
    }
    printf("\nPage Hits : %d \nPage Faults : %d",hits,faults);
}
