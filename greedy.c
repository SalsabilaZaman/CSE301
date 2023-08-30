#include<stdio.h>
int n=11;
void sort(int arr1[][1],int arr2[][1]){
	int temp,temp1;
	for(int i=0;i<n;i++)
	   for(int j=i+1;j<n;j++)
	     if(arr1[j][0]<arr1[i][0]){
	     	temp=arr1[j][0];
	     	temp1=arr2[j][0];
	     	arr1[j][0]=arr1[i][0];
	     	arr2[j][0]=arr2[i][0];
	     	arr1[i][0]=temp;
	     	arr2[i][0]=temp1;
	     }
}

int main(){
	int s[11][1]={1,3,0,5,3,5,6,8,8,2,12};
	int f[11][1]={4,5,6,7,9,9,10,11,12,14,16};
       	int arr[11][1],k=1;
       
       	sort(f,s);
       	arr[0][0]=0;
       	for(int i=1;i<n;i++)
		if(f[(arr[0][0])][0]<=s[i][0]){
			arr[k][0]=i;
			k++;
		}      
       	
       	for(int i=1;i<k;i++)
       	 for(int j=i+1;j<k;j++)
       	  if(f[arr[i][0]][0]>s[arr[j][0]][0])
       	        arr[j][0]=-1;
	       
	for(int i=0;i<k;i++)
	  if(arr[i][0]!=-1)       
	   printf("%d \n",arr[i][0]+1);
	return 0;
}
