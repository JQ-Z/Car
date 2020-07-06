#include <iostream>
using namespace std;

int main()
{
	int arr1[] = {0, 32, 15, 19, 4, 21, 2, 25, 17, 34, 6, 27, 13, 36,
            11, 30, 8, 23, 10, 5, 24, 16, 33, 1, 20, 14, 31, 9,
            22, 18, 29, 7, 28, 12, 35, 3, 26};
	int arr2[] = {0, 28, 9, 26, 30, 11, 7, 20, 32, 17, 5, 22, 34, 15,
            3, 24, 36, 13, 1, 00, 27, 10, 25, 29, 12, 8, 19, 31,
            18, 6, 21, 33, 16, 4, 23, 35, 14, 2};

    int arr1_len = sizeof(arr1) / sizeof(int);
    int arr2_len = sizeof(arr2) / sizeof(int);
    int Max1, Max2, sum1, sum2;
    int answer = 0;
    for(int i = 2; i <=36; i++)
    {
    	sum1 = arr1[0];
    	sum2 = arr2[0];

    	for (int j = 1; j < i; j++)
    	{
    		sum1 += arr1[j];
    		sum2 += arr2[j];
    	}
    	//    	cout << sum1 << ":" << sum2 << endl;;
    	Max1 = sum1;
    	Max2 = sum2;
    	int i1 = 0, i2 = 0;
    	while(i1 < arr1_len)
    	{
    	//	cout << sum1 << ":" << arr1[i1 + i] << endl;
    	//	return 0;
    		sum1 += arr1[(i1 + i) % arr1_len];
    		sum1 -= arr1[i1];

    		i1 ++;
    		Max1 = Max1 < sum1 ? sum1 : Max1;
    	} 
    	while(i2 < arr2_len)
    	{
    		sum2 += arr2[(i2 + i) % arr2_len];
    		sum2 -= arr2[i2];
    		i2 ++;
    		Max2 = Max2 < sum2 ? sum2 : Max2;
    	} 
//    	cout << Max1 << ":" << Max2 << endl;
    	if(Max1 < Max2)answer++;
    }
    cout << answer << endl;
	return answer;
}
