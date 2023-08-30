#include<iostream>
#include<cstring>
#define N 10
using namespace std;

int table[N][N];
char sign[N][N];


void printLCS(string x,int m,int n){
	if(m==0 || n==0)return;
	
	if(sign[m-1][n-1]=='D'){
		printLCS(x,m-1,n-1);
		cout << x[m-1]<<" ";	
	}
	else if(sign[m-1][n-1]=='U')
	   printLCS(x,m-1,n);
	else printLCS(x,m,n-1);
}

int LCS(string x,string y,int i,int j){
	if(i<0 || j<0)
	   return 0;
	else if(table[i][j]!=-1)
	   return table[i][j];
	else{
		if(x[i]==y[j]){
			sign[i][j]='D';
		   	return table[i][j]=1+LCS(x,y,i-1,j-1);
		}
		else{   
		     int m1=LCS(x,y,i-1,j);
		     int m2=LCS(x,y,i,j-1);	
		     if(m1>=m2){
		     	sign[i][j]='U';
		     	table[i][j]=m1;
		     }
		     else{
		     	sign[i][j]='D';
		     	table[i][j]=m2;
		     }
		     
		     return table[i][j];
	       }
	}      	

}

int main(){
	string x,y;
	x="abcbdab";
	y="bdcaba";
	int len1=x.size();
	int len2=y.size();
	
	for(int i=0;i<len1+1;i++)	
	   for(int j=0;j<len2+1;j++)
	      table[i][j]=-1;
	      
	cout <<"LCS Length-"<<LCS(x,y,len1-1,len2-1)<<endl;
 
	
	printLCS(x,len1,len2);
	
}

	
