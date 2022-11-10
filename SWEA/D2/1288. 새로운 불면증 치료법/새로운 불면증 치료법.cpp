#include <iostream>
#include <numeric>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N, k = 0;
        int a[10] = {0,};
        cin >> N;
        
        while(true){
            int cnt = ++k * N;
        	while(cnt != 0){
            	a[cnt % 10] = 1;
            	cnt /= 10;
        	}
        
        	if(accumulate(a, a + 10, 0) == 10){
                cout << '#' << test_case << ' ' << k * N << '\n';
                break;
            }
        }
	}
	return 0;
}