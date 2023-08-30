#include<bits/stdc++.h>
#define n 10
using namespace std;

int arr[] = {0,-2,10,9,2,5,3,7,101,18};
int lis[100],index_[100],pre[100];
int len=0;

void fastLIS(){
    lis[0]=-3729392;
    index_[0]=-1;
    pre[0]=-1;
    
    int i,j,k,s,e;
    
    for(i=1;i<n;i++){
        if(lis[len]<arr[i]){
            lis[++len]=arr[i];
            index_[len]=i;
            pre[i]=index_[len-1];
        }
        else{
            s=0;
            e=len;
            while(s<e){
                int mid=(s+e)/2;
                if(lis[mid]<arr[i])
                    s=mid+1;
                else
                    e=mid;
                
            }
            lis[s]=arr[i];	// replace with its immediate bigger value
            index_[s]=i;
            pre[i]=index_[s-1];
     }
  }
}

void printLIS(int ind){
    if(ind==-1)
        return;
    
    printLIS(pre[ind]);
    cout << arr[ind] <<" ";
}

int main(){
    fastLIS();
    cout << "Length of Longest Increasing Subsequence:" << len <<endl;
    printLIS(index_[len]);
    cout << endl;
    
    return 0;
}

