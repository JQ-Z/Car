#include <iostream>
using namespace std;

int route[3] = {10, 8, 2};

int main()
{
   int i, Num;
   cin >> Num;
   for(i = 0; i < 3; i++)
   {
	int temp = Num;
	int reverse = 0;
	while (temp != 0){
	    reverse *= route[i];
            reverse += temp % route[i];
  	    temp /= route[i];
	}
	if(Num != reverse){
	    cout << i << ":" << reverse << endl;	
	    break;
	}
   }
   if(i != 3){
       cout << "NO" << endl;
   } else {
       cout << "YES" << endl;
   }
   return 0;
}
