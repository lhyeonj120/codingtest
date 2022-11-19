#include <iostream>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

pair<int, int> rookPos[8];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n = 0, idx = 0;
		string res = "yes";
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				char c;
				cin >> c;
				if(c == 'O') {
					rookPos[idx++] = { i, j };
					n++;
				}
			}
		}
		if (n != 8) {
			res = "no";
		}
		else {
			set<int> s;
			for (int i = 0; i < 8; i++)
				s.insert(rookPos[i].first);
			if (s.size() != 8)
				res = "no";
			s.clear();
			for (int i = 0; i < 8; i++)
				s.insert(rookPos[i].second);
			if (s.size() != 8)
				res = "no";
		}

		cout << '#' << test_case << ' ' << res << '\n';
    }
	return 0;
}