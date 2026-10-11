#include <stdio.h>
int main() {
 int n, i, time = 0, completed = 0;
 int at[20], bt[20], pr[20];
 int ct[20], tat[20], wt[20];
 int visited[20] = {0};
 int highest, minPr;
 float avgWT = 0, avgTAT = 0;
 printf("Enter number of processes: ");
 scanf("%d", &n);
 for(i = 0; i < n; i++)
{ printf("Enter Arrival Time, Burst Time and Priority of P%d: ", i + 1);
 scanf("%d%d%d", &at[i], &bt[i], &pr[i]);
 }
 while(completed < n)
 { highest = -1;
 minPr = 9999;
 for(i = 0; i < n; i++)
{ if(at[i] <= time && visited[i] == 0 && pr[i] < minPr)
 { minPr = pr[i];
 highest = i;
 }
 }
 if(highest == -1) {
 time++;
 continue;
 }
 time += bt[highest];
 ct[highest] = time;
 tat[highest] = ct[highest] - at[highest];
 wt[highest] = tat[highest] - bt[highest];
 avgWT += wt[highest];
 avgTAT += tat[highest];
 visited[highest] = 1;
 completed++;
 }
 printf("\n-------------------------------------------------------------\n");
 printf("Process\tAT\tBT\tPR\tCT\tTAT\tWT\n");
 printf("-------------------------------------------------------------\n");
 for(i = 0; i < n; i++)
 { printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
 i+1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
 }
 printf("-------------------------------------------------------------\n");
 printf("Average Waiting Time = %.2f\n", avgWT / n);
 printf("Average Turnaround Time = %.2f\n", avgTAT / n);
 return 0;
}
