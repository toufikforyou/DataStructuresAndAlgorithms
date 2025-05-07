#include <stdio.h>

int main()
{
    int n, total = 0, pos, temp;
    float avgwt, avgtat;
    int p[20], bt[20], wt[20], tat[20], pr[20];

    printf("Enter your number of processes (Max 20): ");
    scanf("%d", &n);

    printf("\nEnter burst time and priority for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d] Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
        printf("P[%d] Priority: ", i + 1);
        scanf("%d", &pr[i]);
        p[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (pr[j] < pr[pos])
                pos = j;
        }

        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (int j = 0; j < i; j++)
            wt[i] += bt[j];
        total += wt[i];
    }

    avgwt = (float)total / n;
    total = 0;

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        total += tat[i];

        printf("\np[%d]\t\t", p[i]);
        printf("%d\t\t", bt[i]);
        printf("%d\t\t", wt[i]);
        printf("%d\t\t", tat[i]);
    }

    avgtat = (float)total / n;
    printf("\n\nAverage Waiting Time: %f", avgwt);
    printf("\n\nAverage TurnAround Time: %f", avgtat);

    return 0;
}