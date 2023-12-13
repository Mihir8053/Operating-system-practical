#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct MainMem
{
    int start_add;
    int pn;
};

int main()
{
       int s,i,totPages,pno,offset,n,r,arr[200]={0},phy_add,fno[100];
       struct MainMem mm[100];
       srand((unsigned)time(NULL));
       cout<<"Logical Address To Physical Address\n";
       cout<<"Enter  the Size of File : ";
       cin>>n;
       cout<<"Enter the Page Size : ";
       cin>>s;
       totPages=n/s;
       for(i=0;i<totPages;i++)
       {
              r=rand()%totPages;
              if(arr[r] == 1)
              {
                           i--;
                           continue;
              }
              arr[r]=1;
              mm[i].pn=r;
              mm[i].start_add=i*s;
              fno[r]=i;
       }
       cout<<"\n*********************************\n";
       cout<<"The Structure of Main Memory\n";
       cout<<"*********************************\n";
       cout<<"Frame\tPage\nNumber\tNumber\n------\t------\n";
       for(i=0; i < totPages; i++)
       {
              cout<<i<<"\t"<<mm[i].pn<<endl;
       }
       cout<<"*********************************\n";
       cout<<"Enter The Logical Address\nPage Number : ";
       cin>>pno;
       cout<<"Offset : ";
       cin>>offset;
       if(pno >= totPages || offset > s)
       {
              cout<<"Invalid Input\n";
              return 0;
       }
       phy_add = mm[fno[pno]].start_add + offset;
       cout<<"*********************************\n";
       cout<<"Physical Address : "<<phy_add<<endl;
       cout<<"*********************************\n";
       return 0;
}