#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while(true){
		int n;
		cin >> n;
		if(n == 0)
			break;
		
		int number;
		vector<int> num;
		for(int i = 0; i < n; i++){
			cin >> number;
			num.push_back(number);
		}
		
		vector<int> v;
		for(int i = 0; i < 6; i++)
			v.push_back(0);
		for(int i = 0; i < n - 6; i++)
			v.push_back(1);
			
		do{
			for(int i = 0; i < n; i++)
				if(v[i] == 0)
					cout << num[i] << ' ';
			cout << '\n';
		} while(next_permutation(v.begin(), v.end()));
		
		cout << '\n';
	}
	
	return 0;
}