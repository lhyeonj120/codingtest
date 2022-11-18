#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string s;
		cin >> s;
		string res;
		string yearStr = s.substr(0, 4);
		string monthStr = s.substr(4, 2);
		string dayStr = s.substr(6, 2);
		int month = stoi(monthStr);
		int day = stoi(dayStr);
		switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (day < 1 || day > 31)
				res = "-1";
			else
				res = yearStr + "/" + monthStr + "/" + dayStr;
			break;
		case 2:
			if (day < 1 || day > 28)
				res = "-1";
			else
				res = yearStr + "/" + monthStr + "/" + dayStr;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day < 1 || day > 30)
				res = "-1";
			else
				res = yearStr + "/" + monthStr + "/" + dayStr;
			break;
		default:
			res = "-1";
		}
		cout << '#' << test_case << ' ' << res << '\n';
	}
	return 0;
}