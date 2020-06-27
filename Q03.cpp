#include <iostream>
using namespace std;

int Howmanyfactor(int num)
{
	int count = 0;
	for(int i = 2; i < num; i++)
		if(num % i == 0)count++;
	return count;
}

int main()
{
	int arr[101] = {0};
	arr[1] = 0;
	int count;
	for(int i = 2; i <= 100; i++)
	{
		count = Howmanyfactor(i);
		if(count % 2 == 0)arr[i] = 1;
		else arr[i] = 0;
	}
	for(int i = 1; i <= 100; i++)
		//cout << i << ":" << (arr[i]==1?"正":"背 ") << endl;
		if(arr[i] == 0) cout << i << endl;
	return 0;
}