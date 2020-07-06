#include <iostream>
using namespace std;

int *(*map);
int answer = 0;
int endstep;
void dfs(int x, int y, int step)
{
	if(step == endstep){
		answer++;
		return;
	}
	for(int i = 1; i <= 4;i++){
		int nx = x, ny = y;
		switch(i){
			case 1: nx += 1;break;
			case 2: nx -= 1;break;
			case 3: ny += 1;break;
			case 4: ny -= 1;break;
		}
		if(map[nx][ny] == 1)continue;
		map[nx][ny] = 1;
		dfs(nx,ny,step + 1);
		map[nx][ny] = 0;
	}
}

int main()
{
	cin >> endstep;
	map = new int*[25];
	for(int i = 0; i <= 24; i++){
		map[i] = new int[25];
		for(int j = 0; j <= 24; j++)
			map[i][j] = 0;
	}
	map[12][12] = 1;
	dfs(12,12,0);
	cout << answer << endl;
	return 0;
}