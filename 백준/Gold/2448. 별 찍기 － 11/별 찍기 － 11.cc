#include <iostream>
using namespace std;

char pattern[1024 * 3 + 2][(1024 * 3 + 2) * 2];

void drawStar(int x, int y){
	pattern[x][y] = '*';
	pattern[x + 1][y - 1] = '*';
	pattern[x + 1][y + 1] = '*';
	
	for(int i = y - 2; i <= y + 2; i++)
		pattern[x + 2][i] = '*';
}

void func(int x, int y, int n){
	if(n == 3){
		drawStar(x, y);
		return;
	}
	n /= 2;
	func(x, y, n);
	func(x + n, y - n, n);
	func(x + n, y + n, n);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++)
		fill(pattern[i], pattern[i] + 2 * N, ' ');
	
	func(0, N - 1, N);
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < 2 * N - 1; j++)
			cout << pattern[i][j];
		cout << '\n';
	}
		
	
	return 0;
}