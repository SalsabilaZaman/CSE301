#include<iostream>
#include<cstring>
using namespace std;
int c[40][40];
char sign[40][40];

void print_lcs(string x,int i,int j){
	//cout << x;
	if(i==0 || j==0)
	   return ;
	if(sign[i][j]=='D'){
		print_lcs(x,i-1,j-1);
		cout << x[i] << ",";
	}
	else if(sign[i][j]=='U'){
		print_lcs(x,i-1,j);
		//cout << x[i];
	}
	else if(sign[i][j]=='L'){
		print_lcs(x,i,j-1);
		//cout << x[i];
	}    

}

int main(){
	string x,y;
	x=" abcbdab";
	y=" bdcaba";
	int len1=x.size();
	int len2=y.size();
	

	
	for(int i=0;i<len1;i++)
	   for(int j=0;j<len2;j++)
	       c[i][j]=0;
	
	for(int i=1;i<len1;i++)
	   for(int j=1;j<len2;j++){
	   	if(x[i]==y[j]){
	   	  c[i][j]=c[i-1][j-1]+1;
		  sign[i][j]='D';	
		}		
		else{
		  if(c[i-1][j] >= c[i][j-1]){
		    c[i][j]=c[i-1][j];
		    sign[i][j]='U';
		  }
		  else{
		    c[i][j]=c[i][j-1];
		    sign[i][j]='L';
		  }  
	 	}	   
	   }
	
	cout << c[len1-1][len2-1] <<endl;
	
	print_lcs(x,len1-1,len2-1);       
}
