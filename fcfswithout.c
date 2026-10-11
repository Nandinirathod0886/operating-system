#include <stdio.h>
int main()
{ int n, i;
int bt[20], order[20];
int current = 0;
float totalWT = 0, totalTAT = 0;
printf("Enter number of processes: ");
scanf("%d", &n);
for(i = 0; i < n; i++)
{
printf("Enter Burst Time of P%d: ", i + 1);
scanf("%d", &bt[i]);
}
printf("\nEnter FCFS execution order (process numbers): ");
for(i = 0; i < n; i++)
scanf("%d", &order[i]);
printf("\nProcess\tBT\tWT\tTAT\n");
for(i = 0; i < n; i++)
{
int p = order[i] - 1; // Convert process number to array index
 int wt = current;
int tat = wt + bt[p];
 printf("P%d\t%d\t%d\t%d\n", p + 1, bt[p], wt, tat);
 totalWT += wt;
 totalTAT += tat;
current = tat;
 }
printf("\nAverage Waiting Time = %.2f", totalWT / n);
printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);
return 0;
}
