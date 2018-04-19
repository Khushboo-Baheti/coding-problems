#include<stdio.h>
using namespace std;
int main()
{
	int n = 2;  //small array
	int m = 4;  // large array
	int mid;
	int count = 0;
	int arr2[4] ={2,4,6,7};
	int arr1[2] = {3,8};
	if(n == 0 && m == 0){
		printf("-1");
		return 0;
	}
	if(n ==0 && m == 2)
	{
		printf("%d\n",(arr2[0] + arr2[1])/2);
		return 0;
	}
	if(n == 0 && m > 0)
	{
		//sort
		mid = m/2;
		if( m % 2 == 0)
		{
		printf("%d\n",(arr2[mid] + arr2[mid-1])/2);	
		}
		else
		{
			printf("%d\n", arr2[mid]);
		}
		return 0;
	}
	if(n == 1 && m == 1){
		printf("%d\n ", (arr1[0]+arr2[0])/2);
		return 0;

	}
		int  i = 0;
		int  j = 0;
		int temp=0;
		int temp2;
		while(count <= ((n+m)/2) && (i < n) && (j < m))
		{	
			temp2 = temp;
			if(arr1[i] < arr2[j]){	
				temp = arr1[i];	
				i++;
			/*	if((i<n) && (arr1[i] < arr2[j]))
					temp2 = arr1[i];
				else
					temp2 = arr2[j];*/
			}
			else
			{
				temp = arr2[j];
				j++;
			/*	if(j < m && (arr2[j] < arr1[i]))
					temp2 = arr2[j];
				else
					temp2 = arr1[i];*/

			}
			count++; 
		}
		printf("temp=%d temp2=%d\n", temp, temp2);
		while((count <= ((n+m)/2)) && (i < n))
				{
				temp2 = temp;
				temp = arr1[i];
				i++;
			/*	if( i < n)
					temp2 = arr1[i];*/
				count++;
				}
		while((count <= ((n+m)/2)) && (j < m))
		{
			temp2 = temp;
			temp = arr2[j];
			j++;
		/*	if(j < m)
				temp2 = arr2[j];*/
			count++;
		}

		if(((m%2 != 0)&&(n%2 == 0)) || ((n%2 != 0)&&(m%2 == 0))) 
		{
			printf("Median is %d" , temp);
			return 0;
		}
		else
		{
			
			printf("median is %d",((temp+temp2)/2));
			return 0;
		}

}
