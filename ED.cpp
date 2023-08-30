#include<iostream>
#include<cstring>
using namespace std;

int min(int x,int y){
	if(x<=y)
	  return x;
	else
	  return y;  
}
int ED(string s1,string s2){
	int m=s1.size();
	int n=s2.size();
	
	int arr[++m][++n];
	
	for(int i=0;i<m;i++)
	   arr[i][0]=i;
	
	for(int j=0;j<n;j++)
	   arr[0][j]=j;
	   
	for(int i=1;i<m;i++)
	  for(int j=1;j<n;j++){
	  	if(s1[i-1]==s2[j-1])
	  	   arr[i][j]=arr[i-1][j-1];
	  	else
	  	   arr[i][j]=1+min(arr[i-1][j-1],min(arr[i-1][j],arr[i][j-1]));   
	  
	  }
	    
	  return arr[m-1][n-1];

}
int main(){
	string str1="heater";
	string str2="speak";
	
	cout << ED(str1,str2)<<endl;
	return 0;
}

