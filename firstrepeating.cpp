#include<stdio.h>
#include<map>
using namespace std;
int main()
{
	int arr[7] = {10,5,3,4,3,5,6};
	int n = 7;
	map<int, int> m;
	for(int i = 0; i < n; i++)
	{
		if(m.find(arr[i]) != m.end())
		{
			m[arr[i]]++;
		}
		else
		{
			m[arr[i]] = 1;
		}
	}
	for(int i = 0; i < n; i++)
	{
		if (m[arr[i]] > 1)
		{
			printf("%d\n", arr[i]);
			break;
		}
	}
	return 0;
}
