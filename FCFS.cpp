#include<iostream>
 
using namespace std;
 
int main()
{
    int n;
    cout<<"Enter total number of processes:";
    cin>>n;
    int burstTime[n],waitingTime[n],turnAroundTime[n],AveragewaitingTime=0,AverageturnAroundTime=0,i,j;
    
 
    cout<<"\nEnter Process Burst Time\n";
    for(i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]:";
        cin>>burstTime[i];
    }
 
    waitingTime[0]=0;    //waiting time for first process is 0
 
    //waiting time calculation
    for(i=1;i<n;i++)
    {
        waitingTime[i]=0;
        for(j=0;j<i;j++)
            waitingTime[i]+=burstTime[j];
    }
 
    cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
 
    //turnaround time calculation
    for(i=0;i<n;i++)
    {
        turnAroundTime[i]=burstTime[i]+waitingTime[i];
        AveragewaitingTime+=waitingTime[i];
        AverageturnAroundTime+=turnAroundTime[i];
        cout<<"\nP["<<i+1<<"]"<<"\t\t"<<burstTime[i]<<"\t\t"<<waitingTime[i]<<"\t\t"<<turnAroundTime[i];
    }
 
    AveragewaitingTime/=i;
    AverageturnAroundTime/=i;
    cout<<"\n\nAverage Waiting Time:"<<AveragewaitingTime;
    cout<<"\nAverage Turnaround Time:"<<AverageturnAroundTime;
 
    return 0;
}