#include <iostream>
#include <cmath>
using namespace std;


int check(int num, int mode = 1)
{
	int arr[10];for(int i = 0; i < 10; i++)arr[i] = -1;
	double square = pow(num, 0.5);
	if(mode == 2)while (square > 1)square /= 10;
		
	int count = 0;
	for(int i = 0; i < 10; i++)
	{
		square -= (int)square;
		square *= 10;
		if(arr[(int)square%10] == -1){
			count++;
			arr[(int)square%10] = 1;
		} else {
			break;
		}
	}
	return count;
}

int main()
{
	int n1,n2,num;
	n1 = n2 = 0;
	num = 2;
	while(!n1 || !n2)
	{
		num++;
		if(!n1 && check(num) == 10)n1 = num;
		if(!n2 && check(num,2) == 10)n2 = num;
	}
	cout << n1 << endl;
	cout << n2 << endl;
	return 0;
}