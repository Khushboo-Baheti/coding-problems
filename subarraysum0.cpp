#include<stdio.h>
#include<unordered_map>
using namespace std;
int main()
{
	int arr[5]={-3,1,2,4,6};
	int n = 5;
	unordered_map<int,bool> summp;
	int sum = 0;
	for(int i=0; i<n; i++)
	{
		sum = sum + arr[i];
		if(sum == 0 || summp[sum] == true)
		{
			printf("true");
			break;
		}
		summp[sum] = true;	
	}
}
