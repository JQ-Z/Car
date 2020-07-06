#include <iostream>
using namespace std;

int Isleap(int years)
{
	if((years % 4 == 0 && years % 100 != 0)|| years % 400 == 0)return 1;
	return 0;
}


int main()
{
	int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	int count;
	int start = 19641010;
	int end = 20200724;
	while (start < end){
		int temp = start, find = 1;
		// count = 25;
		// while (temp > 0){
		// 	if((start >> (count - 1)) % 2 != temp % 2){
		// 		find = 0;
		// 		break;
		// 	}
		// 	//cout << temp % 2;
		// 	count ++;
		// 	temp = temp >> 1;
		// }

		if(start % 100 > 31 || ((start/100) % 100) > 12) {
			start++;
			continue;
		}
		int sum = 0;
		while(temp > 0)
		{
			sum = sum << 1;
			sum += temp % 2;
			temp = temp >> 1;
		}
		int mon = ((start/100) % 100);
		int day = start%100;
		if(mon != 2){
			if(day > month[mon]){
				start++;
				continue;
			}
		} else {
			if(day > month[mon] + Isleap(start / 1000)){
				start++;
				continue;
			}
		}
		if(sum == start)cout << start << endl;
		start ++;
	}
	return 0;
}