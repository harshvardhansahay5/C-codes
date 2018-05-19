#include<iostream>
#include<fstream>
#define FILE_NAME "hotel.dat"
using namespace std;

int get_room_no(char);
class cust {
	int room_no, no_of_days;
	char name_of_customer[20], type_of_room;
	float tariff, bill;
	void Bill() {
		if (type_of_room == 'A' || type_of_room == 'a') {
			tariff = 500;
		}
		if (type_of_room == 'N' || type_of_room == 'n') {
			tariff = 300;
		}
		bill = tariff * no_of_days;
	}
public:
	void new_cust();
	void display();
	friend int get_room_no(char);
	char* ret_name() {
		return name_of_customer;
	}
} customer[9];
void cust::new_cust() {
	do {
		cout << "\nEnter The Name Of The Customer:\t";
		gets(name_of_customer);
	} while (strlen(name_of_customer) == 0);
	do {
		cout << "\nEnter The Type Of Room:\n";
		cout << "A for AC (Rs.500 Per Day)\n";
		cout << "N for Non-AC (Rs.300 Per Day):\t";
		cin >> type_of_room;
		cin.ignore();
		type_of_room = toupper(type_of_room);
	} while (type_of_room != 'A' && type_of_room != 'a' && type_of_room != 'N' && type_of_room != 'n');
	do {
		cout << "\nEnter The Number Of Days Of Stay (Maximum 6 Months For Renewal):\t";
		cin >> no_of_days;
		cin.ignore();
	} while (no_of_days < 1 || no_of_days > 180);
	room_no = get_room_no(type_of_room);
	Bill();
}
void cust::display() {
	cout << "\nName Of The Customer:\t";
	puts(name_of_customer);
	cout << "\nType Of Room:\t";
	cout << type_of_room;
	cout << "\nRoom Number:\t";
	if (type_of_room == 'A' || type_of_room == 'a') {
		cout << "A";
	}
	if (type_of_room == 'N' || type_of_room == 'n') {
		cout << "N";
	}
	cout << room_no;
	cout << "\nNumber Of Days Of Stay\t";
	cout << no_of_days;
	cout << "\nGrand Total:\t";
	cout << "Rs." << bill << endl << endl;
}

void cust_creator () {
	cust tmp;
	tmp.new_cust();
	ofstream file(FILE_NAME, ios::app | ios::binary);
	file.write((char*)&tmp,sizeof(tmp));
	file.close();
}

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

int get_room_no(char a) {
	cust tmp;
	int tmp_room, k = 0;
	fstream file(FILE_NAME, ios::in | ios::binary);
	while (file.read((char*) &tmp, sizeof(tmp))) {
		if (tmp.type_of_room == a) {
			tmp_room = tmp.room_no + 1;
			k++;
		}
	}
	file.close();
	if (k == 0)
		return 100;
	return tmp_room;
}

void search() {
	char name[20];
	cout << "\nEnter The Customer Name Whose Details You Want To Access:\t";
	gets(name);
	cust tmp;
	fstream file(FILE_NAME, ios::in | ios::binary);
	while (file.read((char*) &tmp, sizeof(tmp))) {
		if (!strcmpi(tmp.ret_name(), name)) {
			tmp.display();
		}
	}
	file.close();
}
void display_all() {
	cust tmp;
	fstream file(FILE_NAME, ios::in | ios::binary);
	while (file.read((char*) &tmp, sizeof(tmp))) {
		tmp.display();
	}
	file.close();
}
void choice() {
	int ans;
	do {
		cout << "\nEnter Your Choice:\t";
		cin >> ans;
		cin.ignore();
	} while (ans < 0 || ans > 3);
	switch (ans) {
	case 1: cust_creator ();
			break;
	case 2: display_all();
			break;
	case 3: search();
			break;
	case 0: exit(0);
			break;
	default:
		;
	}
}
void menu() {
	cout << "================================================================================";
	cout << "\n**************************************MENU**************************************\n";
	cout << "================================================================================";
	cout << "\n1. Add A New Customer";
	cout << "\n2. Display All Records";
	cout << "\n3. Search By Name";
	cout << "\n0. Exit";
}
void welcome() {
	cout << "Welcome To........\n\n\n\n\n";
	cout << "HH   HH   OOO   TTTTTT EEEEEEE LL     VV      VV EEEEEEE   GGG     AAA     SS\n";
	cout << "HH   HH  OO OO  TTTTTT EEEEEEE LL     VV      VV EEEEEEE  GG GG   AAAAA   S  S\n";
	cout << "HH   HH OO   OO   TT   EE      LL     VV      VV EE      GG   GG AA   AA SS\n";
	cout << "HH   HH OO   OO   TT   EE      LL      VV    VV  EE      GG      AA   AA SSSS\n";
	cout << "HHHHHHH OO   OO   TT   EEEEE   LL      VV    VV  EEEEE   GG      AAAAAAA  SSSS\n";
	cout << "HH   HH OO   OO   TT   EE      LL       VV  VV   EE      GG  GGG AA   AA     SS\n";
	cout << "HH   HH OO   OO   TT   EE      LL       VV  VV   EE      GG    G AA   AA SS  SS\n";
	cout << "HH   HH  OO OO    TT   EEEEEEE LLLLL     VVVV    EEEEEEE  GG  GG AA   AA SS  SS\n";
	cout << "HH   HH   OOO     TT   EEEEEEE LLLLL      VV     EEEEEEE   GGG   AA   AA  SSSS\n";
}
int main() {
	welcome();
	while (1) {
		menu();
		choice();
	}
	return 0;
}


/*
int main() {
	char str[30];
	bool x = false;
	ifstream fin("iphone.txt");
	ofstream fout("test.dat", ios::out);
	while (fin.getline(str, 25)) {
		x = !x;
		if (x == true) {
			str[strlen(str) - 1] = '\0';
			obj.put_iPhone_model(str);
		} else {
			obj.put_iOS_version(atoi(str));
			fout.write((char*) &obj, sizeof(apple));
		}
	}
	fin.close();
	fout.close();
	fin.open("test.dat", ios::in);
	while (fin.read((char*) &obj, sizeof(apple))) {
		puts(obj.get_iPhone_model());
		cout << obj.get_iOS_version() << endl;
	}
	return 0;
}
*/

