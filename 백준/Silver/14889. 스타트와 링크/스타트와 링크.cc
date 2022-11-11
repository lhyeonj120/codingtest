#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int S[21][21];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> S[i][j];
	
	vector<int> person, start, link;
	for(int i = 0; i < N; i++)
		person.push_back(i);
	
	int minRes = 200;
	vector<int> v;
    for(int i = 0; i < N / 2; i++)
		v.push_back(0);
    for(int i = 0; i < N / 2; i++)
		v.push_back(1);
    do{
        vector<int> start, link;
        for(int i = 0; i < v.size(); i++){
            if(v[i] == 0)
				start.push_back(i);
            else
				link.push_back(i);
        }
		
		int startSum = 0;
		int linkSum = 0;
		for(int i = 0; i < N / 2; i++){
			for(int j = i + 1; j < N / 2; j++){
				if(i == j)
					continue;
				startSum += S[start[i]][start[j]] + S[start[j]][start[i]];
				linkSum += S[link[i]][link[j]] + S[link[j]][link[i]];
			}
		}
		
		minRes = min(minRes, abs(startSum - linkSum));
		
	} while(next_permutation(v.begin(), v.end()));
	
	cout << minRes;
	
	return 0;
}