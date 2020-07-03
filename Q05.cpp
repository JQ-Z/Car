#include <iostream>
using namespace std;

int choose[] = {500,100,50,10};

int sum = 0;
int ans = 0;

void dfs(int count,int limit)
{
	if(count > 15)return;
	for(int i = limit; i < 4; i++)
	{
		if(sum + choose[i] > 1000)continue;
		if(sum + choose[i] == 1000){
			ans ++;
			continue;
		}
		sum += choose[i];
		dfs(count + 1, i);
		sum -= choose[i];
	}
}

int main(){
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}