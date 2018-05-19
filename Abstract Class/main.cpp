/*#include<iostream>
using namespace std;

class sport {
protected:
	char name[20];
	int no_of_players;
public:
	sport(char *s, int a) {
		strcpy(name, s);
		no_of_players = a;
	}
	virtual void display() {
	}
};

class football: public sport {
	char team1[20], team2[20];
public:
	football(char* s, char* t, char* u, int n) :
			sport(s, n) {
		strcpy(team1, t);
		strcpy(team2, u);
	}
	void display();
};

class cricket: public sport {
	char team1[20], team2[20];
public:
	cricket(char* s, char* t, char* u, int n) :
			sport(s, n) {
		strcpy(team1, t);
		strcpy(team2, u);
	}
	void display();
};

void football::display() {
	cout << "\nName: " << name;
	cout << "\nNumber of Players: " << no_of_players;
	cout << "\nTeam 1: " << team1;
	cout << "\nTeam 2: " << team2;
}

void cricket::display() {
	cout << "\nName: " << name;
	cout << "\nNumber of Players: " << no_of_players;
	cout << "\nTeam 1: " << team1;
	cout << "\nTeam 2: " << team2;
}

int main() {
	char s1[20], s2[20], s3[20];
	int nop;
	cout << "Enter the name of the sport: ";
	gets(s1);
	cout << "Enter the number of players required: ";
	cin >> nop;
	cin.ignore();
	cout << "Enter Name of Team 1: ";
	gets(s2);
	cout << "Enter Name of Team 2: ";
	gets(s3);
	football f(s1, s2, s3, nop);
	cout << "Enter the name of the sport: ";
	gets(s1);
	cout << "Enter the number of players required: ";
	cin >> nop;
	cin.ignore();
	cout << "Enter Name of Team 1: ";
	gets(s2);
	cout << "Enter Name of Team 2: ";
	gets(s3);
	cricket c(s1, s2, s3, nop);
	sport* list[2];
	list[0] = &f;
	list[1] = &c;
	cout << "\n Sports Details";
	cout << "\n..........Football..........";
	list[0]->display();
	cout << "\n..........Cricket...........";
	list[1]->display();
	return 0;
}


#include<iostream>
using namespace std;

void print (int j) {
	for(int i = 1; i <= j; ++i) {
		cout << i;
	}
}

int main() {
	int i = cin.get();
	for(int j = 1; j <= i; ++j) {
		for(int k = 1; k <= j; ++k) {
			cout.width(i);
			print (j);
		}
		for(int l = j; l >= 1; --l) {
			cout << l;
			cout << endl;
		}
	}
	return 0;
}
*/
#include <iostream>
using namespace std;

int main () {
	int i = 7;
	int j = 0;
	j = ++i + i++ + i++ + ++i + i++;
	cout << j;
}
