#include<stdio.h>
#include<map>
using namespace std;
int main()
{
	int arr[8] = {12,10,9,45,2,10,10,45};
	map<int,bool> xyz;
	for(int i =0 ; i<8 ;i++)
	{
		if(!(xyz[arr[i]]))
		{
			printf("%d\t",arr[i]);
			xyz[arr[i]] = 'true';
		}
	}
}
