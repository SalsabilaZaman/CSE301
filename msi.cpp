#include<iostream>
#include<climits>
using namespace std;
#define n 16
int arr[]={0,9,-3,1,7,-15,6,-2,8,4,2,3,-4,2,-7,-9};

int main(){
	int max=-495595;
	int start=-1,end=-1;
	int sum=0;
	int startI=-1;
	for(int i=0;i<n;i++){
		if(sum==0)
		  start=i;
		sum+=arr[i];
		if(sum<0)
		  sum =0;
		if(sum>max){
		        max=sum;
			startI=start;
			end=i;		
		}
	}
	
	cout << max <<endl;
	
	for(int i=startI;i<=end;i++)
	    cout << arr[i] << " ";
	 
	return 0;    
}
