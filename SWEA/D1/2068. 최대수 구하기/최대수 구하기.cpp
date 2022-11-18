#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int arr[10];
        for(int i = 0; i < 10; i++)
            cin >> arr[i];
        cout << '#' << test_case << ' ' << *max_element(arr, arr + 10) << '\n';
	}
	return 0;
}