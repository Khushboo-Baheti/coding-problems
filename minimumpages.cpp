#include<stdio.h>
using namespace std;
int main()
{
	int pages[] = {1,1};
	int n = 2;
	int m = 1;
	int l = 1;
	int h = 2;
	while( l < h)
	{
		int mid = (h+l)/2;
		int count = 0;
		int student = 1;
		for(int i=0;i<n;i++)
		{
			if(count+pages[i] <= mid)
			       count = count+pages[i];
			else
			{
				student++;
				count = pages[i];
			}	
		}
		if(student <=  m)
			h = mid;
		else
			l = mid+1;
	}
	printf("%d\n",l);
}
