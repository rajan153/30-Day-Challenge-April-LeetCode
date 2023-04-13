#include<bits/stdc++.h>
using namespace std;
//T.C. O(N)
//S.C. O(1)
bool check(vector<int> push, vector<int> pop)
{
	int i = 0;
	int j = 0;
	for(auto v : push){
		push[i++] = v;
		while(i > 0 && push[i - 1] == pop[j])
		{
			i--;
			j++;
		}
	}
	return i == 0;
}
//T.C. O(N)
//S.C. O(N)
bool check2(vector<int>& push, vector<int>& pop)
{
	stack<int> s;
    for(int i = 0, j = 0; i < push.size(); i++)
    {
        s.push(push[i]);
        while(!s.empty() && s.top() == pop[j])
        {
            s.pop();
            j++;
        }
    }
    return s.empty();
}
int main()
{
	vector<int> push;
	vector<int> pop;
	push.push_back(1);
	push.push_back(2);
	push.push_back(3);
	push.push_back(4);
	push.push_back(5);
	pop.push_back(4);
	pop.push_back(5);
	pop.push_back(3);
	pop.push_back(2);
	pop.push_back(1);
	cout<<check(push, pop);
	cout<<endl;
	cout<<check2(push,pop);
}
