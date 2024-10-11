# Bubble Sort
``` c
#include <stdio.h>
#define MAXSIZE 10
 
void main()
{
    int array[MAXSIZE];
    int i, j, num, temp;
 
    printf("Enter the value of num \n");
    scanf("%d", &num);
    printf("Enter the elements one by one \n");
    for (i = 0; i < num; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Input array is \n");
    for (i = 0; i < num; i++)
    {
        printf("%d\n", array[i]);
    }
    /*   Bubble sorting begins */
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < (num - i - 1); j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    printf("Sorted array is...\n");
    for (i = 0; i < num; i++)
    {
        printf("%d\n", array[i]);
    }
}
```
# Insertion Sort
``` c
#include <stdio.h>
int main(void)
{
    int n, i, j, temp;
    int arr[64];
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter %d integers\n", n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    for (i = 1; i < n; i++) 
    {   
        temp=arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > temp) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    printf("Sorted list in ascending order:\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
```
# Quick Sort
``` c
#include<stdio.h>

void quicksort(int x[20],int first,int last)
{
int pivot,j,temp,i;
if(first<last)
{
pivot=first;
i=first;
j=last;
while(i<j)
{
while(x[i]<=x[pivot]&&i<last)
i++;
while(x[j]>x[pivot])
j--;
if(i<j)
{
temp=x[i];
x[i]=x[j];
x[j]=temp;
}
}
temp=x[pivot];
x[pivot]=x[j];
x[j]=temp;
quicksort(x,first,j-1);
quicksort(x,j+1,last);
}
}
int main()
{
int x[20],size,i;
printf("\tQuick sort\n");
printf("-----------------------------------\n");
printf(" How many numbers you want to sort?: ");
scanf("%d",&size);
printf("\n Enter %d elements: \n",size);
for(i=0;i<size;i++)
scanf("%d",&x[i]);
quicksort(x,0,size-1);

printf("\n Sorted elements after applying quick sort: \n\n");
for(i=0;i<size;i++)
printf(" %d",x[i]);
return 0;
}
```
# Merge Sort
``` c
#include<stdio.h>
void merge(int arr[],int min,int mid,int max)
{
int tmp[30];
int i,j,k,m;
j=min;
m=mid+1;
for(i=min; j<=mid && m<=max ; i++)
{
if(arr[j]<=arr[m])
{

tmp[i]=arr[j];
j++;
}
else
{
tmp[i]=arr[m];
m++;
}
}
if(j>mid)
{
for(k=m; k<=max; k++)
{
tmp[i]=arr[k];
i++;
}
}
else
{
for(k=j; k<=mid; k++)
{
tmp[i]=arr[k];
i++;
}
}
for(k=min; k<=max; k++)
arr[k]=tmp[k];
}
void sortm(int arr[],int min,int max)
{
int mid;
if(min<max)
{
mid=(min+max)/2;
sortm(arr,min,mid);
sortm(arr,mid+1,max);
merge(arr,min,mid,max);
}
}
int main()

{
int arr[30];
int i,size= 5;
printf("\tMerge sort\n");
printf("-----------------------------------\n");
printf("\n Enter %d elements :\n ",size);
for(i=0; i<size; i++)
{
scanf("%d",&arr[i]);
}
sortm(arr,0,size-1);
printf("\n Sorted elements after using merge sort:\n\n");
for(i=0; i<size; i++)
printf(" %d ",arr[i]);
return 0;
}
```
