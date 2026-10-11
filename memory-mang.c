#include <stdio.h>
int main()
{
 int pages, pageSize;
 int pageTable[20];
 int logicalAddress;
 int pageNumber, offset;
 int frameNumber, physicalAddress;
 int i;
 printf("========================================\n");
 printf(" PAGING MEMORY MANAGEMENT\n");
 printf("========================================\n");
 printf("\nEnter the number of pages: ");
 scanf("%d", &pages);
 printf("Enter the page size: ");
 scanf("%d", &pageSize);
 printf("\nEnter the page table:\n");
 for (i = 0; i < pages; i++)
 {
 printf("Page %d -> Frame: ", i);
 scanf("%d", &pageTable[i]);
 }
 printf("\nEnter the logical address: ");
 scanf("%d", &logicalAddress);
 pageNumber = logicalAddress / pageSize;
 offset = logicalAddress % pageSize;
 if (pageNumber >= pages)
 {
 printf("\nInvalid logical address!\n");
 }
 else
 {
 frameNumber = pageTable[pageNumber];
 physicalAddress = (frameNumber * pageSize) + offset;
 printf("\n----------- ADDRESS TRANSLATION -----------\n");
 printf("Logical Address : %d\n", logicalAddress);
 printf("Page Number : %d\n", pageNumber);
 printf("Offset : %d\n", offset);
 printf("Frame Number : %d\n", frameNumber);
 printf("Physical Address : %d\n", physicalAddress);
 }
 printf("\n========================================\n");
return 0;
}
