#include <stdio.h>
void firstFit(int block[], int m, int process[], int n)
{
 int b[20], allocation[20];
 int i, j;
 for (i = 0; i < m; i++)
 b[i] = block[i];
 for (i = 0; i < n; i++)
 allocation[i] = -1;
 for (i = 0; i < n; i++)
 {
 for (j = 0; j < m; j++)
 {
 if (b[j] >= process[i])
 {
 allocation[i] = j;
 b[j] = b[j] - process[i];
 break;
 }
 }
 }
 printf("\n--- FIRST FIT ---\n");
 printf("Process\tSize\tBlock\n");
 for (i = 0; i < n; i++)
 {
 if (allocation[i] != -1)
 printf("P%d\t%d\tB%d\n", i + 1, process[i], allocation[i] + 1);
 else
 printf("P%d\t%d\tNot Allocated\n",i + 1, process[i]);
 }
}
void bestFit(int block[], int m, int process[], int n)
{
 int b[20], allocation[20];
 int i, j, best;
 for (i = 0; i < m; i++)
 b[i] = block[i];
 for (i = 0; i < n; i++)
 allocation[i] = -1;
 for (i = 0; i < n; i++)
 {
 best = -1;
 for (j = 0; j < m; j++)
 {
 if (b[j] >= process[i])
 {
 if (best == -1 || b[j] < b[best])
 best = j;
 }
 }
 if (best != -1)
 {
 allocation[i] = best;
 b[best] = b[best] - process[i];
 }
 }
 printf("\n--- BEST FIT ---\n");
 printf("Process\tSize\tBlock\n");
 for (i = 0; i < n; i++)
 {
 if (allocation[i] != -1)
 printf("P%d\t%d\tB%d\n", i + 1, process[i], allocation[i] + 1);
 else
 printf("P%d\t%d\tNot Allocated\n", i + 1, process[i]);
 }
}
void worstFit(int block[], int m, int process[], int n)
{
 int b[20], allocation[20];
 int i, j, worst;
 for (i = 0; i < m; i++)
 b[i] = block[i];
 for (i = 0; i < n; i++)
 allocation[i] = -1;
 for (i = 0; i < n; i++)
 {
 worst = -1;
 for (j = 0; j < m; j++)
 {
 if (b[j] >= process[i])
 {
 if (worst == -1 || b[j] > b[worst])
 worst = j;
 }
 }
 if (worst != -1)
 {
 allocation[i] = worst;
 b[worst] = b[worst] - process[i];
 }
 }
 printf("\n--- WORST FIT ---\n");
 printf("Process\tSize\tBlock\n");
 for (i = 0; i < n; i++)
 {
 if (allocation[i] != -1)
 printf("P%d\t%d\tB%d\n",i + 1, process[i], allocation[i] + 1);
 else
 printf("P%d\t%d\tNot Allocated\n",i + 1, process[i]);
 }
 }
int main()
{
 int block[20], process[20];
 int m, n, i;
 printf("========================================\n");
 printf(" MEMORY ALLOCATION METHODS\n");
 printf("========================================\n");
 printf("\nEnter number of memory blocks: ");
 scanf("%d", &m);
 printf("Enter size of each block:\n");
 for (i = 0; i < m; i++)
 {
 printf("Block %d: ", i + 1);
 scanf("%d", &block[i]);
 }
 printf("\nEnter number of processes: ");
 scanf("%d", &n);
 printf("Enter size of each process:\n");
 for (i = 0; i < n; i++)
 {
 printf("Process %d: ", i + 1);
 scanf("%d", &process[i]);
 }
 firstFit(block, m, process, n);
 bestFit(block, m, process, n);
 worstFit(block, m, process, n);
 printf("\n========================================\n");
 printf(" END OF PROGRAM\n");
 printf("========================================\n");
 return 0;
}
