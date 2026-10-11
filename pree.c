#include <stdio.h>
int main()
{ int n, i;
 int at[20], bt[20], pr[20], rt[20];
 int ct[20], tat[20], wt[20];
 int completed = 0, time = 0;
 int highest, minPr;
 float avgWT = 0, avgTAT = 0;
 printf("Enter number of processes: ");
 scanf("%d", &n);
 for(i = 0; i < n; i++)
 { printf("Enter Arrival Time, Burst Time and Priority of P%d: ", i + 1);
 scanf("%d%d%d", &at[i], &bt[i], &pr[i]);
 rt[i] = bt[i];
 }
 while(completed < n)
 { highest = -1;
 minPr = 9999;
 for(i = 0; i < n; i++)
 { if(at[i] <= time && rt[i] > 0)
 { if(pr[i] < minPr)
 { minPr = pr[i];
 highest = i;
 }
 }
 }
 if(highest == -1)
 { time++;
 continue;
 }
 rt[highest]--;
 time++;
 if(rt[highest] == 0)
 { completed++;
 ct[highest] = time;
 tat[highest] = ct[highest] - at[highest];
 wt[highest] = tat[highest] - bt[highest];
 avgWT += wt[highest];
 avgTAT += tat[highest];
 }
 }
 printf("\n---------------------------------------------------------------\n");
 printf("Process\tAT\tBT\tPR\tCT\tTAT\tWT\n");
 printf("---------------------------------------------------------------\n");
 for(i = 0; i < n; i++)
 { printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
 i + 1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
 }
 printf("---------------------------------------------------------------\n");
 printf("Average Waiting Time = %.2f\n", avgWT / n);
 printf("Average Turnaround Time = %.2f\n", avgTAT / n);
 return 0;
}
