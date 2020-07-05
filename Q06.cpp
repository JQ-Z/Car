#include <iostream>
using namespace std;

// int arr[10002] = {0};


// int find(int id)
// {
// 	int start = id;
// 	while(arr[id] != id)
// 		id = arr[id];
// 	while(start != id){
// 		int temp = arr[start]
// 		arr[start] = id;
// 		start = temp;
// 	}
// 	return id;
// }

// void join(int id1, int id2)
// {
// 	arr[id2] = id1;
// }


// void init(){
// 	for(int i = 1; i <= 10000; i++)
// 	{

// 	}
// }

int check(int num, int key)
{
	while(num != 1)
	{
		if(num == key)return 1;
		if(num % 2 == 0)num /= 2;
		else num = num * 3 + 1;
	}
	return 0;
}

int main()
{
	// for(int i = 1; i <= 10000; i++)arr[i] = i;
	// init();
	int count = 0;
	for(int i = 2; i <= 10000; i++)
		if(check(i * 3 + 1, i))count ++;
	cout << count << endl;
	return 0;
}