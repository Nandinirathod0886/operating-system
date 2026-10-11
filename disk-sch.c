
#include <stdio.h>
#include <stdlib.h>
int main()
{
 int request[20], n, head;
 int i, movement = 0, current;
 printf("================================\n");
 printf(" FCFS DISK SCHEDULING\n");
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
 for (i = 0; i < n; i++)
 {
 movement += abs(request[i] - current);
 current = request[i];
 printf(" -> %d", current);
 }
 printf("\nTotal Head Movement = %d\n", movement);
 return 0;
}
