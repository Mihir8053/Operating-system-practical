#include<iostream>
using namespace std;
 
int main()
{
    int n,total=0,pos,temp,avg_waitingTime,avg_tat;
    cout<<"Enter Total Number of Process:";
    cin>>n;
    int burstTime[n],p[n],waitingTime[n],tat[n],pr[n],i,j;
 
    cout<<"\nEnter Burst Time and Priority\n";
    for(i=0;i<n;i++)
    {
        cout<<"\nP["<<i+1<<"]\n";
        cout<<"Burst Time:";
        cin>>burstTime[i];
        cout<<"Priority:";
        cin>>pr[i];
        p[i]=i+1;
    }
 
    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=burstTime[i];
        burstTime[i]=burstTime[pos];
        burstTime[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    waitingTime[0]=0;
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        waitingTime[i]=0;
        for(j=0;j<i;j++)
            waitingTime[i]+=burstTime[j];
 
        total+=waitingTime[i];
    }
 
    avg_waitingTime=total/n;
    total=0;
 
    cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for(i=0;i<n;i++)
    {
        tat[i]=burstTime[i]+waitingTime[i];//calculate turnaround time
        total+=tat[i];
        cout<<"\nP["<<p[i]<<"]\t\t  "<<burstTime[i]<<"\t\t    "<<waitingTime[i]<<"\t\t\t"<<tat[i];
    }
 
    avg_tat=total/n;//average turnaround time
    cout<<"\n\nAverage Waiting Time="<<avg_waitingTime;
    cout<<"\nAverage Turnaround Time="<<avg_tat;
 
    return 0;
}