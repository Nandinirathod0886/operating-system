#include <stdio.h>
 int main() {
 int n, i, time = 0, completed = 0;
 int at[20], bt[20];
 int ct[20], tat[20], wt[20];
 int visited[20] = {0};
 int shortest, minBT;
 float avgWT = 0, avgTAT = 0;
 printf("Enter number of processes: ");
 scanf("%d", &n);
 for(i = 0; i < n; i++)
{ printf("Enter Arrival Time and Burst Time of P%d: ", i + 1);
 scanf("%d%d", &at[i], &bt[i]);
}
 while(completed < n)
{ shortest = -1;
 minBT = 9999;
for(i = 0; i < n; i++)
{ if(at[i] <= time && visited[i] == 0 && bt[i] < minBT)
 { minBT = bt[i];
 shortest = i; }
 }
 if(shortest == -1)
 { time++;
continue; }
 time += bt[shortest];
 ct[shortest] = time;
 tat[shortest] = ct[shortest] - at[shortest];
wt[shortest] = tat[shortest] - bt[shortest];
 avgWT += wt[shortest];
 avgTAT += tat[shortest];
 visited[shortest] = 1;
 completed++;
 }
 printf("\n--------------------------------------------------------\n");
 printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
  printf("-------------------------------------------------------\n");
 for(i = 0; i < n; i++)
 { printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
 i + 1, at[i], bt[i], ct[i], tat[i], wt[i]); }
 printf("--------------------------------------------------------\n");
 printf("Average Waiting Time = %.2f\n", avgWT / n);
 printf("Average Turnaround Time = %.2f\n", avgTAT / n);
 return 0;
}
