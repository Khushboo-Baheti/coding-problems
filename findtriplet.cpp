#include<stdio.h>
using namespace std;
int main(){
	// sort array
	int arr[6]={1,4,6,8,10,45};
	int sum = 22;
	int l;
	int r;
	for(int i = 0; i < 4; i++)
	{
	l = i+1;
	r = 5;	
	while(l < r)
	{
		int sumlr = arr[l] + arr[r];
		if (sum == (sumlr + arr[i])){
				printf("triplet %d %d %d" , arr[l],arr[i],arr[r]);
				break;
				}
	else if( sum > (sumlr + arr[i])) 
			l++;
			else 
			r--;
	}
	}
	}

