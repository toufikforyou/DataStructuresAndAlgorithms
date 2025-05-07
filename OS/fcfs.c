#include <stdio.h>

int main()
{
    int n, avtat = 0, avwat = 0;
    int bt[20], wt[20], tat[20];

    printf("Enter your number of processes (Max 20): ");
    scanf("%d", &n);

    printf("\nEnter process burst time: \n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;

    for (int i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (int j = 0; j < i; j++)
        {
            wt[i] += bt[j];
        }
    }
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        avwat += wt[i];
        avtat += tat[i];

        printf("\nP[%d]\t\t", i + 1);
        printf("%d\t\t", bt[i]);
        printf("%d\t\t", wt[i]);
        printf("%d\t\t", tat[i]);
    }

    avwat /= n;
    avtat /= n;
    printf("\n\nAverage Waiting Time: %d", avwat);
    printf("\n\nAverage TurnAround Time: %d", avtat);

    return 0;
}