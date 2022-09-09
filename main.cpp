#include <iostream>
#include <queue>
#include <vector>

using namespace std;

enum { birth1, birth2, die };

struct sheep
{
	int event_time;
	int event_code;
};

struct sheep_less
{
	bool operator()(const sheep& l, const sheep& r) const
	{
		return l.event_time < r.event_time;
	}
};

int main()
{
	int n;
	cin >> n;

	priority_queue<sheep, vector<sheep>, sheep_less> queue;
	queue.push({ 2, birth1 }); 

	while(!queue.empty())
	{	
		if(auto s = queue.top(); s.event_time <= n)
		{
			queue.pop();
			if(s.event_code == birth1)
			{
				queue.push({ s.event_time + 2, birth1 });
				queue.push({ s.event_time + 2, birth2 });
			} 
			else if(s.event_code == birth2) 
			{
				queue.push({ s.event_time + 2, birth1 });
				queue.push({ s.event_time + 1, die });
			}
			else
			{
				
			}
		}
		else
			break;
	}

	cout << queue.size() << endl;

	return 0;
}
