#include <stdio.h>
int main()
{
 int n;
 int disk[100] = {0};
 int i, blocks, start, indexBlock;
 int blockList[50];
 printf("========================================\n");
 printf(" FILE ALLOCATION STRATEGIES\n");
 printf("========================================\n");
 printf("\nEnter number of disk blocks: ");
 scanf("%d", &n);
 printf("\n--- SEQUENTIAL ALLOCATION ---\n");
 printf("Enter starting block: ");
 scanf("%d", &start);
 printf("Enter number of blocks required: ");
 scanf("%d", &blocks);
 if (start >= 0 && start + blocks <= n)
 {
 printf("Allocated Blocks: ");
 for (i = start; i < start + blocks; i++)
 {
 disk[i] = 1;
 printf("%d ", i);
 }
 printf("\nFile allocated successfully.\n");
 }
 else
 {
 printf("File cannot be allocated.\n");
 }
 printf("\n--- INDEXED ALLOCATION ---\n");
 printf("Enter index block: ");
 scanf("%d", &indexBlock);
 printf("Enter number of blocks required: ");
 scanf("%d", &blocks);
 printf("Enter block numbers:\n");
 for (i = 0; i < blocks; i++)
 scanf("%d", &blockList[i]);
 if (indexBlock >= 0 && indexBlock < n)
 {
 printf("Index Block: %d\n", indexBlock);
 printf("Allocated Blocks: ");
 for (i = 0; i < blocks; i++)
 printf("%d ", blockList[i]);
 printf("\nFile allocated successfully.\n");
 }
 else
 {
 printf("File cannot be allocated.\n");
 }
 printf("\n--- LINKED ALLOCATION ---\n");
 printf("Enter number of blocks required: ");
 scanf("%d", &blocks);
 printf("Enter block numbers:\n");
 for (i = 0; i < blocks; i++)
 scanf("%d", &blockList[i]);
 printf("Linked Allocation:\n");
 for (i = 0; i < blocks; i++)
 {
 printf("%d", blockList[i]);
 if (i < blocks - 1)
 printf(" -> ");
 }
 printf(" -> NULL\n");
 printf("File allocated successfully.\n");
 return 0;
}
