#include <iostream>
#include <vector>
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
        int n;
        long long maxProfit = 0;
        vector<int> v;
        cin >> n;
        for(int i = 0; i < n; i++){
            int salePrice;
            cin >> salePrice;
            v.push_back(salePrice);
        }
        vector<int>::iterator start = v.begin();
        do{
            vector<int>::iterator maxIter = max_element(start, v.end());
            int idx = maxIter - v.begin();
            int startIdx = start - v.begin();
            long long sum = 0;
            for(int i = startIdx; i < idx; i++)
                sum += v[i];
            long long profit = *maxIter * (idx - startIdx) - sum;
            maxProfit = max(maxProfit, maxProfit + profit);
            start = maxIter + 1;
        } while(start < v.end());
        
        cout << '#' << test_case << ' ' << maxProfit << '\n';
	}
	return 0;
}