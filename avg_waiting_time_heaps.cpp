// https://www.hackerrank.com/challenges/minimum-average-waiting-time/problem

#include<bits/stdc++.h>

using namespace std;

class CompareDist
{
public:
    bool operator()(pair<long int,long int> n1,pair<long int,long int> n2) {
        if(n1.second!=n2.second)
            return n1.second>n2.second;
        if(n1.first>=n2.first)
        {
        
        return n1.first>n2.first;
            
        }
        else
            return n2.first>n1.first;
    }
};


int main()
{
	long int n,i;
	priority_queue<pair<long int,long int>,vector<pair<long int,long int>>,CompareDist> minheap,copy;
	vector<pair<long int, long int>> tasks;
    pair<long int, long int> cur_task;
    
	long int cur_time=0,wait_time=0,arrival,cook_time;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>arrival>>cook_time;
		tasks.push_back(make_pair(arrival,cook_time));
	}
	sort(tasks.begin(),tasks.end());
	while(!tasks.empty() || !minheap.empty())
	{
		while(!tasks.empty() && tasks[0].first<=cur_time)
		{
			minheap.push(tasks.front());
			tasks.erase(tasks.begin());
		}
		if(!minheap.empty())
		{
			cur_task=minheap.top();
            minheap.pop();
			cur_time+=cur_task.second;
			wait_time+=cur_time-cur_task.first;
		}
		else
		{
			minheap.push(tasks.front());
			tasks.erase(tasks.begin());
			cur_time=minheap.top().first;
		}
	}
	cout<<(wait_time/n);
}