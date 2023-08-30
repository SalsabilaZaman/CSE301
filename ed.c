#include<stdio.h>
#include<string.h>
char arr[6][6];

int findMin(int x, int y, int z){
  if(x <= y && x <= z)
    return x;
  else if(y <=x && y <= z)
    return y;
  else
    return z;
}

void printED(int m,int n,int end){
	if(end==0)return;
	if(arr[m-1][n-1] == 'S'){
	   printED(m-1,n-1,end-1);
 	   printf("Replace\n");
	}
	else if(arr[m-1][n-1]=='N')
	   printED(m-1,n-1,end);//no operation
	
	else if(arr[m-1][n-1]=='D'){
		printED(m-1,n,end-1);
		printf("Delete\n");
	}
	else{
		printED(m,n-1,end-1);
		printf("Insert\n");
	}
}
/*void printED(char *array1,int i,int j){
    if(i==0 || j==0)
       return ;
    
    if(arr[i][j]=='S'){
      printf("%c ",array1[i]);
      printED(array1,i-1,j-1);
      //printf("%c ",array1[i]);
    }
    else if(arr[i][j]=='D'){
      printED(array1,i-1,j);
      printf("%c ",array1[i]);
    }  	
    else if(arr[i][j]=='I'){
      printED(array1,i,j-1);         
	printf("%c ",array1[i]);
    }
    else
       printf("%c ",array1[i]);
}*/
int main(){
	
	char arr1[15]="Heater";
	char arr2[15]="Speak";
	int a,b,i,j;
	a=strlen(arr1);
	b=strlen(arr2);
	
	int c[++a][++b];
	
	for(i=0;i<a;i++)
	  for(j=0;j<b;j++){
	         arr[i][j]='#';
	  	 c[i][j]=0;
	  }	 
	  
        
	for(i=0;i<a;i++){
	   c[i][0]=i;
	   arr[i][0]='D';
	}   
	for(j=0;j<b;j++){    
	    c[0][j]=j;
	    arr[0][j]='I';
	}    
	          
	for(i=1;i<a;i++)
	  for(j=1;j<b;j++){
	  	if(arr1[i-1]!=arr2[j-1]){
	  	  int x=c[i-1][j-1];
	  	  int y=c[i-1][j];
	  	  int z=c[i][j-1];
	  	  int min=findMin(x,y,z);
	  	  c[i][j]=min+1;
	  	  if(min==x)
	  	     arr[i][j]='S';
	  	  else if(min==y)
	  	     arr[i][j]='D';
	  	  else
	  	     arr[i][j]='I';   
	       }
	       else{
	          c[i][j]=c[i-1][j-1];	         
	  	  arr[i][j]='N';
	       }
	  }
	     
	for(i=0;i<a;i++){
	  for(j=0;j<b;j++){
	     printf("%d",c[i][j]);
	     printf("%c ",arr[i][j]);
	  }
	  printf("\n");
	}             
	
	printED(a,b,c[a-1][b-1]);
		  
	printf("\n\nDistance-%d\n\n",c[a-1][b-1]);
	return 0;
}

