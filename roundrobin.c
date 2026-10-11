#include <stdio.h>
 int main()
{
 int n, tq;
 int bt[20], rt[20];
 int wt[20], tat[20], ct[20];
 int i, completed = 0, time = 0;
 float avgWT = 0, avgTAT = 0;
 printf("Enter number of processes: ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 printf("Enter Burst Time of P%d: ",i+1);
 scanf("%d",&bt[i]);
 rt[i]=bt[i];
 }
 printf("Enter Time Quantum: ");
 scanf("%d",&tq);
 while(completed<n)
 {
 for(i=0;i<n;i++)
 {
 if(rt[i]>0)
 {
 if(rt[i]>tq)
 {
 time += tq;
 rt[i] -= tq;
 }
 else
 {
 time += rt[i];
 ct[i]=time;
 tat[i]=ct[i];
 wt[i]=tat[i]-bt[i];
 avgWT += wt[i];
 avgTAT += tat[i];
 rt[i]=0;
 completed++;
 }
 }
 }
 }
 printf("\n----------------------------------------------\n");
 printf("Process\tBT\tCT\tTAT\tWT\n");
 printf("----------------------------------------------\n");
 for(i=0;i<n;i++)
 {
 printf("P%d\t%d\t%d\t%d\t%d\n",
 i+1,bt[i],ct[i],tat[i],wt[i]);
 }
 printf("----------------------------------------------\n");
 printf("Average Waiting Time = %.2f\n",avgWT/n);
 printf("Average Turnaround Time = %.2f\n",avgTAT/n);
 return 0;
}
