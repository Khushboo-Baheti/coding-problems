#include<stdio.h>
using namespace std;
int merge(int arr[],int l,int mid,int h)
{
    int n1 = mid-l+1;
    int n2 = (h-mid);
    int left[n1];
    int right[n2];
    for(int y=0;y<n1;y++)
        left[y] = arr[l+y];
    for(int x = 0;x < n2;x++)
        right[x] = arr[mid+x+1];
    int i =0;
    int j =0;
    int k =l;
    int count = 0;
    while(i< n1 && j< n2)
    {
        if(left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
            printf("mid %d l %d i %d h %d\n", mid, l, i, h);
            count = count+(mid-(l+i));
        }
        printf("arr[%d]=%d\n", k, arr[k]); 
        k++;
    }
    while(i<n1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
    while(j < n2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
    return count;
}
/*int merge(int arr[],int temp[],int l,int mid,int h)
{
    int i =l;
    int j =mid;
    int k = l;
    int count =0;
    while(i <= mid-1 && j<= h)
    {
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
            count = count+(mid-i);
        }
    }
    while(i <= mid-1)
    {
        temp[k]=arr[i];
        k++;
        i++;
    }
    while( j <= h)
    {
        temp[k]=arr[j];
        k++;
        j++;
    }
    int y = 0;
    for(int x=l; x <= h; x++)
    {
        arr[x] = temp[x];
    }
    return count; 
}*/
/*int mergesort(int arr[],int temp[],int l, int h)
{
    int count = 0;
    if(l < h)
    {
        int mid = (l+h)/2;
        count =  mergesort(arr,temp,l,mid);
        count = count + mergesort(arr,temp,mid+1,h);
        count = count + merge(arr,temp,l,mid+1,h);
    }
    return count;
}*/
int mergesort(int arr[],int l, int h)
{
    int count = 0;
    if(l < h)
    {
        int mid = (l+h)/2;
        count =  mergesort(arr,l,mid);
        count = count + mergesort(arr,mid+1,h);
        count = count + merge(arr,l,mid,h);
    }
    return count;
}

int _mergesort(int arr[],int n)
{
    //int temp[n];
    return mergesort(arr,0,n-1);
}
int main()
{
    int arr[5] = {1,20,6,4,5};
    int n=5;
    int count = _mergesort(arr,n);
    for(int i = 0; i<n;i++)
        printf("%d\n",arr[i]);
    printf("inversion count: %d\n",count);
}
