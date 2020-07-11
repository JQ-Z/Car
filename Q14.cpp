#include <iostream>
using namespace std;

typedef struct node{
	char str[30];
	int id;
	int end;
	struct node * next;
}Node;

char country[][30] = {"Brazil", "Croatia", "Mexico", "Cameroon",
            "Spain", "Netherlands", "Chile", "Australia",
            "Colombia", "Greece", "Cote d'Ivoire", "Japan",
            "Uruguay", "Costa Rica", "England", "Italy",
            "Switzerland", "Ecuador", "France", "Honduras",
            "Argentina", "Bosnia and Herzegovina", "Iran",
            "Nigeria", "Germany", "Portugal", "Ghana",
            "USA", "Belgium", "Algeria", "Russia",
            "Korea Republic"};

//char country[][30] = {"abcdfef","fefjfks","vefgravdaf"};

int C_Num(int c)
{
	if(c - 'A' >= 0 && c - 'A' <= 25)return c - 'A';
	else return c - 'a';
}
long c = 1;
int answer = 0,Max = 0;
int *arr;
void dfs(Node *(*map), int start){
	Max = Max < answer ? answer : Max;
	cout << c++ << ":" << Max << endl;
	Node *current = map[start];
	while(current != NULL){
		if(arr[current->id] != 1){
			arr[current->id] = 1;
			answer++;
			dfs(map,current->end);
			arr[current->id] = 0;
			answer--;
		}
		current = current->next;
	}	
	
}

int main(){
	Node *map[26];
	for(int i = 0; i < 26; i++)map[i] = NULL;
	int len = sizeof(country) / sizeof(country[0]);
	arr = new int[len];
	for(int i = 0; i < len; i++)
	{
		//cout << i << endl;
		arr[i] = 0;
		Node *newnode = new Node;
		int start = C_Num(country[i][0]);
		//cout << country[i] << ":" << start << endl;
		strcpy(newnode->str, country[i]);
		//cout << "fuck" << endl;
		newnode->id = i;
		//cout << country[i] << "_end:" << C_Num(country[i][strlen(country[i]) - 1]) << endl;
		newnode->end = C_Num(country[i][strlen(country[i]) - 1]);
		
		
		if(map[start] == NULL){
			cout << "emmm" << endl;
			map[start] = newnode;
		} else {
			Node *t = map[start];
			while(t->next != NULL){
				t=t->next;
			}
			t->next = newnode;
		}
		
	}
	for(int i = 0; i < 26; i++)
		dfs(map,i);
	cout << Max << endl;
	return 0;
}