#include<bits/stdc++.h>
using namespace std;
int main()
{
   priority_queue<int>pq;//max number arjonno
    //priority_queue<int,vector<int>,greater<int>>pq;//minimum ar jonno

    pq.push(10);
    pq.push(5);
    pq.push(30);
    cout<<pq.top()<<endl;
    pq.push(100);
    cout<<pq.top()<<endl;
    pq.pop();//100 remove
    pq.pop();//30 remove
     cout<<pq.top()<<endl;

     
    return 0;
}