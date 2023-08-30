#include<iostream>
#include<cstring>
using namespace std;
int max(int x,int y){
	if(x>=y)
	  return x;
	else
	  return y;  
}

int findlcs(string s1,string s2){
	int m=s1.size();
	int n=s2.size();
	
	int arr[++m][++n];
	for(int i=0;i<m;i++)
		arr[i][0]=0;
		
	for(int j=0;j<n;j++)
		arr[0][j]=0;
	
	for(int i=1;i<m;i++)
	   for(int j=1;j<n;j++){
	   	if(s1[i]==s2[j])
	   	    arr[i][j]=1+arr[i-1][j-1];
	   	else
	   	    arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
	   }
	return arr[m-1][n-1];   	   
}
void printlcs(){
	
}
int main(){
	string str1="abcbdab";
	string str2="bdcaba";
	
	cout << findlcs(str1,str2);

	return 0;
}
