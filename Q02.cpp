#include <iostream>
using namespace std;

char c[20] = "";
int in = 0;
int anwser[4] = {0};
int pre = 1;
int dfs(int count, int current)
{
	if(count == 4){
		c[in + 1] = '\0';
		int temp = anwser[3] * 1000 + anwser[2] * 100 + anwser[1] * 10 + anwser[0];
		if(strlen(c) == 4)return 0; //至少一个操作符号
		if(pre != 1) current *= pre; //pre乘数 current被乘数
	/*	getchar();								//调试
		cout << c << endl;
		cout << current << "==" << temp << endl; 	
	*/	
		if(current == temp){
			return 1;
		}
		else 
			return 0;
	}
	for(int i = 0; i <= 9; i++)
	{
		anwser[count] = i;
		if(i == 0){
			c[++in] = '0';
			if(dfs(count + 1, current * 10))return 1;
			in--;
		} else {
			c[++in] = '0' + i;
			if(dfs(count + 1, current * 10 + i))return 1;
			
			c[in] = '*';
			c[++in] = '0' + i;
			pre *= current;
			if(dfs(count + 1, i))return 1;
			pre /= current;
			in -= 2;
		}
	}
	return 0;
}

int main()
{
	for(int i = 1; i <= 9;i++)
	{
		in = 0;
		cout << "start: " << i << endl;
		c[in] = '0' + i;
		anwser[0] = i;
		if(dfs(1, i)){

			cout << c << endl;
			//break; //只找一个
		}
	}
	return 0;
}