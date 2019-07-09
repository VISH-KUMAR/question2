#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main()
{
	vector<double> p1;
	vector<double> p2;
	double x;
	for(int i =0;i<2;i++)
	{
		cin>>x;
		p1.push_back(x);
		
	}
	for(int i =0;i<2;i++)
	{
		cin>>x;
		p2.push_back(x);
		
	}
	float distance;
	distance = sqrt(pow((p1.front() - p2.front()), 2) + pow((p1.back()) - p2.back(), 2));
	//distance = sqrt((p1.front() - p2.front())*(p1.front() - p2.front()) + (p1.back() - p2.back())*(p1.back() - p2.back()));
	cout<<distance;
	
}
