#include<iostream>

using namespace std;

void greedy_activity(int *s,int *f,int n){
	int j=0,k=0;
	
	int arr[n];
	arr[j]=k+1;
	j++;
	for(int i=k+1;i<n;i++)
	   if(s[i]>f[k]){
	   	arr[j]=i+1;
		j++;
		k=i;	   
	   }
	
	for(int i=0;i<j;i++)
	  cout << arr[i] << " ";  

}
int main(){
	int n,swap;
	cin >> n;
	int s[n],f[n];
	for(int i=0;i<n;i++)
		cin >> s[i] >> f[i];
	for(int i=0;i<n;i++)
	   for(int j=i+1;j<n;j++)		
		if(f[i]>f[j]){
			swap=f[i];
			f[i]=f[j];
			f[j]=swap;
		}
	greedy_activity(s,f,n);				
	


	return 0;
}
