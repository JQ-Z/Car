#include <iostream>
using namespace std;

int cut(int n, int m, int current)
{
	if(current >= n){
		return 0;
	}else if(current < m){
		return 1 + cut(n, m, current * 2);
	}else {
		return 1 + cut(n, m, current + m);
	}
}

int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	cout << cut(n, m, 1) << endl;
	return 0;
}