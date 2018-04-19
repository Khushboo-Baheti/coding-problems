#include<stdio.h>
using namespace std;
int main(){
	int arr[7] = {1,4,0,0,3,10,5};
	int fsum=7;
	int sum =arr[0];
	int start = 0;
        for(int i =1; i<7 ;i++)
	{
	while(sum > fsum && start < i-1)
	{
		sum = sum - arr[start];
		start++;
	}
	if(sum == fsum)
		printf("%d %d", start, i-1);
	
	if(i < 7)
		sum = sum + arr[i];
	}
}
