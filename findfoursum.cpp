#include<stdio.h>
using namespace std;
int main()
{
	int arr[6]= {1,4,6,10,12,45};
	int find = 21;
	int i,j,k,l,r,sum;
	for(i=0;i<6-3;i++)
	{
		for(j=i+1;j<6-2;j++)
		{
			l=j+1;
			r=6-1;
			while(l<r)
			{
				sum = arr[i]+arr[j]+arr[l]+arr[r];
				if(sum == find){
					printf("%d %d %d %d \n",arr[i],arr[j],arr[l],arr[r]);
					l++;
					r--;
				}
				else if(sum < find)
					l++;
				else
					r--;
			}
		}
	}

}
