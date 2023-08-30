#include<iostream>
#include<climits>
#define n 5

using namespace std;

int A[]={40,20,30,10,30};
int dp[n][n],partition[n][n];

int mcm(int i,int j){
	if(i==j)
	  return 0;
	else if(dp[i][j]!=-1)
	   return dp[i][j];
	else{
	   int min=INT_MAX,p=-1;	
	   for(int k=i;k<j;k++){
	     int steps=A[i-1]*A[k]*A[j]+mcm(i,k)+mcm(k+1,j);
	     if(steps<min){
	        min=steps;
	        p=k;
	     } 	   	
	   }
	   partition[i][j]=p;
	   return min;     
	}   

}

void printpartition(int i,int j){
	if(i==j)
	  cout <<"A"<<i;
	else{
		cout << "(";
		printpartition(i,partition[i][j]);
		printpartition(partition[i][j]+1,j);
		cout << ")";	
	}  

}
int main(){
	int start=1;
	int end=4;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
		   dp[i][j]=-1;
		   partition[i][j]=-1;
		 }  
		   
	int min=mcm(start,end);		
	cout << min << endl;
	printpartition(start,end);
}
