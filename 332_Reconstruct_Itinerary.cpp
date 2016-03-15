#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		int i,j,curCity;
		set<string> cities;
		map<string, int> c2n;//city to number
		vector<string> n2c;//number to city
		vector<vector<int>> flight;
		vector<vector<bool>> isUsed;
		vector<int> orders;
		vector<string> results;
		for (i = 0; i < tickets.size(); i++)//find all cities
		{
			if (cities.find(tickets.at(i).first) == cities.end())
				cities.insert(tickets.at(i).first);
			if (cities.find(tickets.at(i).second) == cities.end())
				cities.insert(tickets.at(i).second);
		}
		i = 0;
		for (set<string>::iterator it = cities.begin(); it != cities.end(); it++)//map city to number and number to city
		{
			//cout << *it << endl;
			c2n.insert(pair<string, int>(*it, i));
			n2c.push_back(*it);
			vector<int> temp;
			flight.push_back(temp);//one vector for the from_city
			vector<bool> tmp;
			isUsed.push_back(tmp);
			i++;
		}
		for (i = 0; i < tickets.size(); i++)
		{
			flight.at(c2n.at(tickets.at(i).first)).push_back(c2n.at(tickets.at(i).second));
			isUsed.at(c2n.at(tickets.at(i).first)).push_back(false);
		}
		for (i = 0; i < flight.size(); i++)
			std::sort(flight.at(i).begin(), flight.at(i).end());
		/*for (i = 0; i < flight.size(); i++)
		{
			cout << n2c.at(i) << ":  ";
			for (j = 0; j < flight.at(i).size(); j++)
				cout << n2c.at(flight.at(i).at(j)) << " ";
			cout << endl;
		}*/
		orders.push_back(c2n.at("JFK"));
		while (orders.size() < tickets.size()+1)
		{
			curCity = orders.back();
			for (i = 0; i < isUsed.at(curCity).size(); i++)
			{
				if (!isUsed.at(curCity).at(i))
					break;
			}
			//cout << n2c.at(curCity) << "->";
			if (i < isUsed.at(curCity).size())//find one to test
			{
				orders.push_back(flight.at(curCity).at(i));
				isUsed.at(curCity).at(i) = true;
				//cout << n2c.at(flight.at(curCity).at(i));
			}
			else//从该城市出发的机票已统计完，需回溯
			{
				orders.pop_back();
				if (orders.empty())
					return results;
				int sourceCity = orders.back();
				for (i = 0; i < isUsed.at(sourceCity).size(); i++)
				{
					if (isUsed.at(sourceCity).at(i) && flight.at(sourceCity).at(i) == curCity)
						isUsed.at(sourceCity).at(i) = false;
				}
				while (true)
				{
					for (j = 0; j < isUsed.at(sourceCity).size(); j++)
					{
						if (flight.at(sourceCity).at(j)>curCity&&!isUsed.at(sourceCity).at(j))
							break;
					}
					if (j < isUsed.at(sourceCity).size())//find one
					{
						orders.push_back(flight.at(sourceCity).at(j));
						isUsed.at(sourceCity).at(j)=true;
						break;
					}
					else//continue to backtrace
					{
						curCity = sourceCity;
						orders.pop_back();
						if (orders.empty())
							return results;
						sourceCity = orders.back();
						for (i = 0; i < isUsed.at(sourceCity).size(); i++)
						{
							if (isUsed.at(sourceCity).at(i) && flight.at(sourceCity).at(i) == curCity)
								isUsed.at(sourceCity).at(i) = false;
						}
					}
				}
			}
			//cout << endl;
		}

		for (i = 0; i < orders.size(); i++)
			results.push_back(n2c.at(orders.at(i)));
		return results;
	}
	
};
int main()
{
	vector<pair<string, string>> tickets;
	tickets.push_back(pair<string, string>("JFK", "KUL"));
	tickets.push_back(pair<string, string>("JFK", "NRT"));
	tickets.push_back(pair<string, string>("NRT", "JFK"));
	//tickets.push_back(pair<string, string>("ATL", "JFK"));
	//tickets.push_back(pair<string, string>("ATL", "SFO"));
	Solution s;
	
	vector<string> result = s.findItinerary(tickets);
	for (int i = 0; i < result.size(); i++)
		cout << result.at(i) << endl;
	return 0;
}
