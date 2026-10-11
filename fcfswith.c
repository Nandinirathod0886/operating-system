#include <stdio.h>
int main()
{ int n, i, j;
 int at[20], bt[20], ct[20], wt[20], tat[20], p[20];
 float avgWT = 0, avgTAT = 0;
 printf("Enter number of processes: ");
 scanf("%d", &n);
 for(i = 0; i < n; i++)
 {
 p[i] = i + 1;
 printf("Enter Arrival Time and Burst Time of P%d: ", i + 1);
 scanf("%d%d", &at[i], &bt[i]);
 }
 for(i = 0; i < n - 1; i++) {
 for(j = i + 1; j < n; j++) {
 if(at[i] > at[j]) {
 int temp;
 temp = at[i]; at[i] = at[j]; at[j] = temp;
 temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
 temp = p[i]; p[i] = p[j]; p[j] = temp;
 }
 }
 }
 ct[0] = at[0] + bt[0];
 for(i = 1; i < n; i++)
 {
 if(ct[i - 1] < at[i])
 ct[i] = at[i] + bt[i];
 else
 ct[i] = ct[i - 1] + bt[i];
 }
 for(i = 0; i < n; i++)
 {
 tat[i] = ct[i] - at[i];
 wt[i] = tat[i] - bt[i];
 avgWT += wt[i];
 avgTAT += tat[i];
 }
printf("\nP\tAT\tBT\tCT\tWT\tTAT\n");
 for(i = 0; i < n; i++)
 {
 printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
 p[i], at[i], bt[i], ct[i], wt[i], tat[i]);
 }
 printf("\nAverage Waiting Time = %.2f", avgWT / n);
 printf("\nAverage Turnaround Time = %.2f\n", avgTAT / n);
 return 0;
}
