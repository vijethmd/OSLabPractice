#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, m;

    // Input number of processes and resources
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    // Declare arrays
    int Allocation[n][m];
    int Request[n][m];
    int Available[m];
    int Work[m];
    bool Finish[n];

    // Input Allocation matrix
    printf("\nEnter Allocation Matrix (%d x %d):\n", n, m);
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &Allocation[i][j]);
        }
    }

    // Input Request matrix
    printf("\nEnter Request Matrix (%d x %d):\n", n, m);
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &Request[i][j]);
        }
    }

    // Input Available resources
    printf("\nEnter Available Resources (%d values):\n", m);
    for (int j = 0; j < m; j++)
    {
        scanf("%d", &Available[j]);
    }

    // Initialize Work = Available
    for (int j = 0; j < m; j++)
    {
        Work[j] = Available[j];
    }

    // Initialize Finish[i]
    for (int i = 0; i < n; i++)
    {
        bool isZero = true;
        for (int j = 0; j < m; j++)
        {
            if (Allocation[i][j] != 0)
            {
                isZero = false;
                break;
            }
        }
        Finish[i] = isZero; // true if Allocation is all zeros
    }

    // Deadlock detection algorithm
  bool progress;
    do
    {
        progress = false;
        int idx = -1;
        for (int i = 0; i < n; i++)
        {
            
            if (!Finish[i])
            {
                // bool canBeSatisfied = true;
                int j;
                for (j = 0; j < m; j++)
                {
                    if (Request[i][j] > Work[j])
                    {
                        // canBeSatisfied = false;
                        break;
                    }
                }
                if(j == m)
                {
                    idx = i;
                }
                
            }
        }
        if (idx !=-1)
        {
            for (int j = 0; j < m; j++)
            {
                Work[j] += Allocation[idx][j];
                Finish[idx] = true;
                progress = true;
            }
        }
    } while (progress);
    // Deadlock detection algorithm
    bool progress;
    do
    {
        progress = false;
        int idx = -1;
        for (int i = 0; i < n; i++)
        {
            
            if (!Finish[i])
            {
                // bool canBeSatisfied = true;
                int j;
                for (j = 0; j < m; j++)
                {
                    if (Request[i][j] > Work[j])
                    {
                        // canBeSatisfied = false;
                        break;
                    }
                }
                if(j == m)
                {
                    idx = i;
                }
                
            }
        }
        if (idx !=-1)
        {
            for (int j = 0; j < m; j++)
            {
                Work[j] += Allocation[idx][j];
                Finish[idx] = true;
                progress = true;
            }
        }
    } while (progress);  bool progress;
    do
    {
        progress = false;
        int idx = -1;
        for (int i = 0; i < n; i++)
        {
            
            if (!Finish[i])
            {
                // bool canBeSatisfied = true;
                int j;
                for (j = 0; j < m; j++)
                {
                    if (Request[i][j] > Work[j])
                    {
                        // canBeSatisfied = false;
                        break;
                    }
                }
                if(j == m)
                {
                    idx = i;
                }
                
            }
        }
        if (idx !=-1)
        {
            for (int j = 0; j < m; j++)
            {
                Work[j] += Allocation[idx][j];
                Finish[idx] = true;
                progress = true;
            }
        }
    } while (progress);

    // Report deadlocked processes
    bool deadlock = false;
    printf("\nProcesses in deadlock: ");
    for (int i = 0; i < n; i++)
    {
        if (!Finish[i])
        {
            printf("P%d ", i);
            deadlock = true;
        }
    }

    if (!deadlock)
    {
        printf("None. No deadlock detected.\n");
    }
    else
    {
        printf("\nDeadlock detected among the above processes.\n");
    }

    return 0;
}
