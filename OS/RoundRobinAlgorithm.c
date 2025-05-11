#include <stdio.h>
#define true 1

int main()
{
    int n, quantum, total = 0;
    float avgwt = 0, avgtat = 0;
    int bt[20], wt[20], tat[20], rem_bt[20], p[20];

    printf("Enter number of processes (Max 20): ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
        p[i] = i + 1;
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    int t = 0;

    while (true)
    {
        int done = 1;

        for (int i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = 0;

                if (rem_bt[i] > quantum)
                {
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else
                {
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }

        if (done == 1)
            break;
    }

    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
    for (int i = 0; i < n; i++)
    {
        avgwt += wt[i];
        avgtat += tat[i];

        printf("\np[%d]\t\t", p[i]);
        printf("%d\t\t", bt[i]);
        printf("%d\t\t", wt[i]);
        printf("%d\t\t", tat[i]);
    }

    avgwt /= n;
    avgtat /= n;

    printf("\n\nAverage Waiting Time: %f", avgwt);
    printf("\nAverage TurnAround Time: %f", avgtat);

    return 0;
}
