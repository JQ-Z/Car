#include <iostream>
using namespace std;

enum a{R, E, A, D, W, I, T, L, K, S};
int ans[10] = {0};
int mark[10] = {0};
int answer = 0;

void check()
{
	int read = ans[0] * 1000 + ans[1] * 100 + ans[2] * 10 + ans[3];
	int write = ans[4] * 10000 + ans[0] * 1000 + ans[5] * 100 + ans[6] * 10 + ans[1];
	int talk = ans[6] * 1000 + ans[2] * 100 + ans[7] * 10 + ans[8];
	int skill = ans[9] * 10000 + ans[8] * 1000 + ans[5] * 100 + ans[7] * 10 + ans[7];
	if(read + write + talk == skill) {
		answer++;
		cout << read << "+" << write << "+" << talk << "=" << skill << endl; 
	}
}

void dfs(enum a key)
{
	if(key > S){
		check();
		return;
	}
	int start;
	if(key == R || key == W || key == T || key == S)start = 1;
	else start = 0;
	for(;start <= 9; start++)
	{
		if(mark[start] != 0)continue;
		mark[start] = 1;
		ans[key] = start;
		dfs((enum a)(key + 1));
		mark[start] = 0;
	}
}

int main()
{
	dfs(R);
	cout << answer << endl;
	return 0;
}