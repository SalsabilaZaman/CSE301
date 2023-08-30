#include<stdio.h>
#include<limits.h>
#define n 6
int m[n][n],s[n][n];
int p[]={10,5,1,10,2,10};
void printOptimalParens(int i,int j){
	if(i==j)
	  printf("A%d",p[i]);
	else{
		printf("(");
		printOptimalParens(i,s[i][j]);
		printOptimalParens(s[i][j]+1,j);
		printf(")");
	}  

}
int main(){
	int i,l,k;
	for(i=1;i<n;i++)
	   m[i][i]=0;
	
	for(l=2;l<n;l++)
	  for(i=1;i<n-l+1;i++){
	  	int j=i+l-1;
	  	m[i][j]=INT_MAX;
	  	for(k=1;k<j-1;k++){
	  	   int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];	
	  	   if(q<m[i][j]){
	  	      m[i][j]=q;
	  	      s[i][j]=k;
	  	   }   
	  	      
	  }
	}     
	printOptimalParens(1,5);
	
	return 0;

}
