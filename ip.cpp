#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <iostream>
#include <map>
using namespace std;

int main()
{
	vector<pair<int, int> >v;
	v.push_back(make_pair(129,11));
	v.push_back(make_pair(19,10));
	v.push_back(make_pair(129,1122));

	for(int i=0;i<v.size();++i)
	 cout<<v[i].first<<" "<<v[i].second<<endl;
	return 0;
}
