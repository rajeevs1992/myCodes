#include<stdio.h>


void merge(int *arr, int low, int mid, int high)
{
    int subarray[100], i=low, j=mid+1, k=0;
    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
        {
            subarray[k++] = arr[i++];
        }
        else
        {
            subarray[k++] = arr[j++];
        }
    }
    while(i<=mid)
    {
        subarray[k++] = arr[i++];
    }
    while(j<=high)
    {
        subarray[k++] = arr[j++];
    }
    for(i=0;i<k;i++)
    {
        arr[low + i] = subarray[i];
    }
}
void mergesort(int *arr, int low, int high)
{
    if(low!=high)
    {
        int mid = (low + high) /2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[100], n, i;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d", arr+i);
    }
    mergesort(arr, 0, n-1);
    for(i=0;i<n;i++)
    {
        printf("%d\n", *(arr+i));
    }

}
