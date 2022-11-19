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
        int res = 0;
        string input;
        cin >> input;
        for(int i = 0; i < input.length(); i++){
            if(input[i] == i + 'a')
                res++;
            else
                break;
        }
        
        cout << '#' << test_case << ' ' << res << '\n';
	}
	return 0;
}