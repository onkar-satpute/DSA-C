# Linear Search
``` c
#include <stdio.h>
int main()
{
int array[100], search, c, n;

printf("Enter number of elements in array\n");
scanf("%d", &n);

printf("Enter %d integer(s)\n", n);

for (c = 0; c < n; c++)
scanf("%d", &array[c]);

printf("Enter a number to search\n");
scanf("%d", &search);

for (c = 0; c < n; c++)

{
if (array[c] == search) /* If required element is found */
{
printf("%d is present at location %d.\n", search, c+1);
break;
}
}
if (c == n)
printf("%d isn't present in the array.\n", search);

return 0;
}
```
# Binary Search
``` c
#include <stdio.h>

int binarySearch(int array[], int x, int low, int high) {
// Repeat until the pointers low and high meet each other
while (low <= high) {

int mid = low + (high - low) / 2;

if (array[mid] == x)
return mid;

if (array[mid] < x)
low = mid + 1;

else
high = mid - 1;
}

return -1;
}

int main(void) {
int array[] = {3, 4, 5, 6, 7, 8, 9};
int n = sizeof(array) / sizeof(array[0]);
int x = 4;
int result = binarySearch(array, x, 0, n - 1);
if (result == -1)
printf("Not found");
else
printf("Element is found at index %d", result);
return 0;
}
```
