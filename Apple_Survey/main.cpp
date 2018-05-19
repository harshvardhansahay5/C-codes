#include<fstream>
#include<iostream>
#define FILE_NAME "apple_survey.dat"
using namespace std;

int strcmpi(char* s1, char* s2) {
	int i;
	if (strlen(s1) != strlen(s2))
		return -1;
	for (i = 0; i < strlen(s1); i++) {
		if (toupper(s1[i]) != toupper(s2[i]))
			return s1[i] - s2[i];
	}
	return 0;
}

class apple {
	char iPhone_model[20];
	int iOS_version;
public:
	apple() {
		strcpy(iPhone_model, " ");
		iOS_version = -1;
	}
	void put_iPhone_model(char *s) {
		strcpy(iPhone_model, s);
	}
	void put_iOS_version(int i) {
		iOS_version = i;
	}
	char* get_iPhone_model() {
		return iPhone_model;
	}
	int get_iOS_version() {
		return iOS_version;
	}
} obj;

int no_of_rec() {
	int no = 0;
	ifstream fin(FILE_NAME, ios::in);
	while (fin.read((char*) &obj, sizeof(apple))) {
		++no;
	}
	return no;
}

void stat_iPhone() {
	ifstream fin(FILE_NAME, ios::in);
	int _5 = 0, _5s = 0, _6 = 0, _6s = 0, _6p = 0, _7 = 0, _7s = 0, _7p = 0, se = 0;
	while (fin.read((char*) &obj, sizeof(apple))) {
		if (!strcmpi(obj.get_iPhone_model(), "iPhone 5")) {
			++_5;
		}
		if (!strcmpi(obj.get_iPhone_model(), "iPhone 5s")) {
			++_5s;
		}
		if (!strcmpi(obj.get_iPhone_model(), "iPhone 6")) {
			++_6;
		}
		if (!strcmpi(obj.get_iPhone_model(), "iPhone 6s")) {
			++_6s;
		}
		if (!strcmpi(obj.get_iPhone_model(), "iPhone 6+")) {
			++_6p;
		}
		if (!strcmpi(obj.get_iPhone_model(), "iPhone 7")) {
			++_7;
		}
		if (!strcmpi(obj.get_iPhone_model(), "iPhone 7+")) {
			++_7p;
		}
		if (!strcmpi(obj.get_iPhone_model(), "iPhone 7s")) {
			++_7s;
		}
		if (!strcmpi(obj.get_iPhone_model(), "iPhone se")) {
			++se;
		}
	}
	cout << "iPhone 5 :\t" << 100 * (double)_5 /no_of_rec()  << endl;
	cout << "iPhone 5S:\t" << 100 * (double)_5s/no_of_rec() << endl;
	cout << "iPhone 6 :\t" << 100 * (double)_6 /no_of_rec()  << endl;
	cout << "iPhone 6+:\t" << 100 * (double)_6p/no_of_rec() << endl;
	cout << "iPhone 6S:\t" << 100 * (double)_6s/no_of_rec() << endl;
	cout << "iPhone 7 :\t" << 100 * (double)_7 /no_of_rec()  << endl;
	cout << "iPhone 7+:\t" << 100 * (double)_7p/no_of_rec() << endl;
	cout << "iPhone 7S:\t" << 100 * (double)_7s/no_of_rec() << endl;
	cout << "iPhone SE:\t" << 100 * (double)se /no_of_rec()  << endl;
}

void stat_iOS() {
	ifstream fin(FILE_NAME, ios::in);
	int _3 = 0, _4 = 0, _5 = 0, _6 = 0, _7 = 0, _8 = 0, _9 = 0, _10 = 0, _11 = 0;
	while (fin.read((char*) &obj, sizeof(apple))) {
		if (obj.get_iOS_version() == 3) {
			++_3;
		}
		if (obj.get_iOS_version() == 4) {
			++_4;
		}
		if (obj.get_iOS_version() == 5) {
			++_5;
		}
		if (obj.get_iOS_version() == 6) {
			++_6;
		}
		if (obj.get_iOS_version() == 7) {
			++_7;
		}
		if (obj.get_iOS_version() == 8) {
			++_8;
		}
		if (obj.get_iOS_version() == 9) {
			++_9;
		}
		if (obj.get_iOS_version() == 10) {
			++_10;
		}
		if (obj.get_iOS_version() == 11) {
			++_11;
		}
	}
	cout << "iOS 3 :\t" << 100 * (double) _3  / no_of_rec() << endl;
	cout << "iOS 4 :\t" << 100 * (double) _4  / no_of_rec()<< endl;
	cout << "iOS 5 :\t" << 100 * (double) _5  / no_of_rec()<< endl;
	cout << "iOS 6 :\t" << 100 * (double) _6  / no_of_rec()<< endl;
	cout << "iOS 7 :\t" << 100 * (double) _7  / no_of_rec()<< endl;
	cout << "iOS 8 :\t" << 100 * (double) _8  / no_of_rec()<< endl;
	cout << "iOS 9 :\t" << 100 * (double) _9  / no_of_rec()<< endl;
	cout << "iOS 10:\t" << 100 * (double) _10 / no_of_rec()<< endl;
	cout << "iOS 11:\t" << 100 * (double) _11 / no_of_rec()<< endl;
}

void insert_new () {
	ofstream fout(FILE_NAME, ios::app);
	char model[20];
	int iOS;
	cout << "Enter iPhone Model:\t";
	gets(model);
	cout << "Enter iOS Version:\t";
	cin >> iOS;
	obj.put_iPhone_model(model);
	obj.put_iOS_version(iOS);
	fout.write((char*) &obj, sizeof(apple));
	fout.close();
}

void choice2() {
	int choice;
	do {
		cout << "\nEnter Your Choice:\t";
		cin >> choice;
	} while (choice < 1 || choice > 3);
	switch (choice) {
	case 1: stat_iPhone();
			break;
	case 2: stat_iOS();
			break;
	case 3: cout << "Total Number of Records:\t"<< no_of_rec() << endl;
			break;
	case 0: return;
			break;
	default:
		;
	}
}

void menu2 () {
	cout << "================================================================================";
	cout << "\n**************************************MENU**************************************\n";
	cout << "================================================================================";
	cout << "\n1. Percentage of users on each iPhone";
	cout << "\n2. Percentage of users on each iOS";
	cout << "\n3. Number of Records";
	choice2 ();
}

void clear() {
	ofstream fout(FILE_NAME, ios::trunc);
	fout.close();
}

void menu() {
	cout << "================================================================================";
	cout << "\n**************************************MENU**************************************\n";
	cout << "================================================================================";
	cout << "\n1. Insert a new record";
	cout << "\n2. See Stats";
	cout << "\n3. Clear all records";
	cout << "\n0. Exit";
}

void choice() {
	int choice;
	do {
		cout << "\nEnter Your Choice:\t";
		cin >> choice;
		cin.ignore();
	} while (choice < 0 || choice > 3);
	switch (choice) {
	case 1: insert_new();
			break;
	case 2: menu2();
			break;
	case 3: clear();
			break;
	case 0: exit(0);
			break;
	default:
		;
	}
}

int main() {
    while (1) {
        menu();
        choice();
    }
    return 0;
}
