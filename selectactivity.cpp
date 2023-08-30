#include<iostream>
using namespace std;

struct job{
	char jobID[200];
	int startTime;
	int finishTime;
	int compatibility;
}jobs[50];
int numOfJobs;
void readInput(){
	cin >> numOfJobs;
	for(int i=0;i<numOfJobs;i++){
	  cin >> jobs[i].jobID >> jobs[i].startTime >>  jobs[i].finishTime;
	  jobs[i].compatibility=1;
	}  
	for(int i=0;i<numOfJobs;i++)
	  cout << jobs[i].jobID << " " << jobs[i].startTime << " " <<  jobs[i].finishTime << " " <<jobs[i].compatibility << endl;
}

void sort(){
	struct job temp;
	
	for(int i=0;i<numOfJobs;i++)
	   for(int j=i+1;j<numOfJobs;j++)
	   	if(jobs[i].finishTime > jobs[j].finishTime ){
	   		temp=jobs[i];
	   		jobs[i]=jobs[j];
	   		jobs[j]=temp;
	   	}
}
int main(){
	
	freopen("input.txt","r",stdin);
	readInput();
	
	sort();
	
	for(int i=0;i<numOfJobs;i++)
	  cout << jobs[i].jobID << " " << jobs[i].startTime << " " <<  jobs[i].finishTime << " " <<jobs[i].compatibility << endl;

}
