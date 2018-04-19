#include<stdio.h>
using namespace std;
int main(){
	//sorted
	int arr[6] = {2,3,5,20,50,80};
	int find = 15;
	int l = 0;
	int r = 1;
	int diff;
	while(l<6 && r<6 )
	{
		diff = arr[r] - arr[l];
		if (r != l && diff == find){
			printf("\n%d %d\n", arr[r], arr[l]);
			return 0;
		}
		else if(diff < find)
			       r++;
		else
				l++;
			       
	} 
	printf("no pair found");
}
