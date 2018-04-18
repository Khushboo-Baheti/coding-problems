#include<stdio.h>
#include<map>
using namespace std;
int main()
{
	int arr[8] = {1,2,3,4,1,2,3,4};
	int k =3;
	int n = 8;
	int j;
	int count = 0;
	map <int,bool> m;
	while(count < n)
	{
		j = count;
		for(int i = 0; i < k; i++)
		{
			if( j < n)
			{
				if(m.find(arr[j]) != m.end() && m[arr[j]] == true)
				{
					printf("true\n");
					return 0;
				}
				else
				{
					m[arr[j]] = true;
					j++;
				}
			}
		}
		m.clear();
		count++;
	}
	printf("false\n");
}
