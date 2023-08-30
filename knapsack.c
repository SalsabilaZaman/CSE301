#include<stdio.h>


int main(){
	int n,W;
	printf("Enter number of items-");
	scanf("%d",&n);
	int arr[n][4];
	printf("Enter how much items-\n");
	
	
	for(int i=0;i<n;i++){
	 scanf("%d",&arr[i][0]);
	 arr[i][3]=0;
	} 
	printf("Enter benefits from each item-\n");
	for(int i=0;i<n;i++)
	 scanf("%d",&arr[i][1]);
	 
	printf("Kototuk nite parba bolo-");
	scanf("%d",&W);
	
	
	int w=0; 		//kottuk nisi intially,ekhono kisu neinai
	 
	for(int i=0;i<n;i++)
	  arr[i][2]=arr[i][1]/arr[i][0];
	
	int swap,swap1;
	for(int i=0;i<n;i++)
	   for(int j=i+1;j<n;j++)
	   	if(arr[i][2]<arr[j][2]){
	   	    swap=arr[i][2];
	   	    swap1=arr[i][0];
	   	    arr[i][2]=arr[j][2];
	   	    arr[i][0]=arr[j][0];
	   	    arr[j][2]=swap;
	   	    arr[j][0]=swap1;
	   	}
	
	   
	for(int i=0;i<n;i++){
	  if(w<=W){
	  	if(arr[i][0]<=W-w){
	     		arr[i][3]=arr[i][0];
			w+=arr[i][3];
	     		arr[i][0]=0;
	     	}
	     	else{
	     		arr[i][3]=(W-w);
	     		w+=arr[i][3];
	     		arr[i][0]-=arr[i][3];
	     	}
	  }
	  else
	     break;
	}
	
	int profit=0;
	for(int i=0;i<n;i++){
	  if(arr[i][3]){
	  	profit+=(arr[i][3]*arr[i][2]);
	  }
	 //printf("%d %d %d %d\n",arr[i][0],arr[i][1],arr[i][2],arr[i][3]);
	}  	
	     
	printf("%d",profit);  
	   
	
	return 0;
}
