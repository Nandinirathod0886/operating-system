#include <stdio.h>
#include <stdlib.h>
int main()
{
 int request[20], visited[20] = {0};
 int n, head;
 int i, count, min, index;
 int movement = 0, current;
 printf("================================\n");
 printf(" SSTF DISK SCHEDULING\n");
 printf("================================\n");
 printf("Enter number of requests: ");
 scanf("%d", &n);
 printf("Enter request queue:\n");
 for (i = 0; i < n; i++)
 scanf("%d", &request[i]);
 printf("Enter initial head position: ");
 scanf("%d", &head);
 current = head;
 printf("\nSeek Sequence: %d", head);
 for (count = 0; count < n; count++)
 {
 min = 9999;
 index = -1;
 for (i = 0; i < n; i++)
 {
if (!visited[i])
 {
 if (abs(request[i] - current) < min)
 {
 min = abs(request[i] - current);
 index = i;
 }
 }
 }
 visited[index] = 1;
 movement += abs(request[index] - current);
 current = request[index];
 printf(" -> %d", current);
 }
 printf("\nTotal Head Movement = %d\n", movement);
 return 0;
}
