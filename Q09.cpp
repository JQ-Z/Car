#include <iostream>
using namespace std;

int main()
{
	int arr[21][11] = {0};
	arr[0][0] = 1;
	for(int i = 0; i <= 20; i++)
		for(int j = 0; j <= 10; j++)
		{
			// if(j == i ||  j + 10 == i)continue;
			// cout << "arr[" << i-1 << "]" << "[" << j << "]=" << arr[i-1][j];
			// cout << "   arr[" << i << "]" << "[" << j-1 << "]=" << arr[i][j-1];
			// arr[i][j] = arr[i-1][j] + arr[i][j-1];
			// cout << "   arr[" << i << "]" << "[" << j << "]=" << arr[i][j] << endl;
			if(j != 0 && j == i) continue;
			if(j != 0 && j + 10 == i) continue;
			if(i - 1 > 0 ) arr[i][j] += arr[i-1][j];
			if(j - 1 > 0 ) arr[i][j] += arr[i][j-1];
		}
	cout << arr[20][9] + arr[19][10] << endl;
	return 0;
}