#include <stdio.h>
#include <stdlib.h>
int main()
{
 int request[20];
 int n, head, diskSize;
 int i, j, temp;
 int movement = 0, current;
 printf("========================================\n");
 printf(" C-SCAN DISK SCHEDULING\n");
 printf("========================================\n");
 printf("Enter number of requests: ");
 scanf("%d", &n);
 printf("Enter request queue:\n");
 for (i = 0; i < n; i++)
 scanf("%d", &request[i]);
 printf("Enter initial head position: ");
 scanf("%d", &head);
 printf("Enter disk size: ");
 scanf("%d", &diskSize);
 for (i = 0; i < n - 1; i++)
 {
 for (j = i + 1; j < n; j++)
 {
 if (request[i] > request[j])
 {
 temp = request[i];
 request[i] = request[j];
 request[j] = temp;
 }
 }
 }
 current = head;
 printf("\nSeek Sequence: %d", head);
 for (i = 0; i < n; i++)
 {
 if (request[i] >= head)
 {
 movement += abs(request[i] - current);
 current = request[i];
 printf(" -> %d", current);
 }
 }
 movement += abs((diskSize - 1) - current);
 current = diskSize - 1;
printf(" -> %d", current);
 movement += current;
 current = 0;
 printf(" -> %d", current);
  for (i = 0; i < n; i++)
{
 if (request[i] < head)
 {
 movement += abs(request[i] - current);
 current = request[i];
 printf(" -> %d", current);
 }
 }
 printf("\n\nTotal Head Movement = %d cylinders\n", movement);
 return 0;
}
