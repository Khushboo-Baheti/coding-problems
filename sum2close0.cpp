# include <stdio.h>
# include <stdlib.h> /* for abs() */
# include <limits.h>
using namespace std;
void minAbsSumPair(int arr[], int arr_size)
{
    int l = 0;
    int r = arr_size-1;
    int sum = 100000;
    int f;
    int s;
    while(l < r)
    {
        if(abs(arr[l]+arr[l]) < abs(sum))
        {
            sum = arr[l]+arr[r];
            f = l;
            s = r;
        }
        if(arr[l]+arr[r] < 0)
            l++;
        else
            r--;
    } 
 
  printf(" The two elements whose sum is minimum are %d and %d",
          arr[f], arr[s]);
}
 
/* Driver program to test above function */
int main()
{
  int arr[] = {-80,1,12,11,60,70,85};
  minAbsSumPair(arr, 7);
  return 0;
}
