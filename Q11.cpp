#include <iostream>
using namespace std;

int main()
{
	long pre = 144, current  = 144 + 89;
	int count = 1;
	while (count <= 5)
	{
		long temp = current;
		int q = 0;
		while(temp > 0)
		{
			q += temp % 10;
			temp /= 10;
		}
		if(current % q == 0){
			count++;
			cout << current << endl;
		}
		pre += current * 2;
		current = pre - current;
		pre -= current;
	}
	return 0;
}