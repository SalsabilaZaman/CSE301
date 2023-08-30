#include<iostream>
#define n 3
#define W 50
using namespace std;

int weight[]={10,20,30};
int profit[]={60,100,120};
int dp[n][W+1];

int max(int x,int y){
	if(x>=y)
	  return x;
	else 
	  return y;  
}

int maxprofit(int i,int w){
	if(i==0){
	   if(weight[i]<=w)
	     dp[i][w]=profit[i];
	   else
	     dp[i][w]=0;
	}       
	  
	else if(dp[i][w]!=-1)
	  return dp[i][w];
	else if(weight[i]>w)
	  dp[i][w]=maxprofit(i-1,w);
	else
		dp[i][w]=max(maxprofit(i-1,w),profit[i]+maxprofit(i-1,w-weight[i]));
	
	
	return dp[i][w];
}


int main(){

	for(int i=0;i<n;i++)
	  dp[i][0]=0;
	for(int i=0;i<W+1;i++)
	  dp[0][i]=0;  
	
	   
	for(int i=1;i<n;i++)
	  for(int j=1;j<W;j++)   
  		dp[i][j]=-1;
  		
  	cout << maxprofit(n-1,W);
  		
	return 0;
}

