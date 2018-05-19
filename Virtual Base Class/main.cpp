#include <iostream>
using namespace std;

class student {
	int rno;
public:
	void getnumber() {
		cout << "Enter Roll No:\t";
		cin >> rno;
	}
	void putnumber() {
		cout << "Roll No:\t" << rno << "\n";
	}
};
class test: virtual public student {
public:
	int part1, part2;

	void getmarks() {
		cout << "Enter Marks\n";
		cout << "Part1:\t";
		cin >> part1;
		cout << "Part2:\t";
		cin >> part2;
	}
	void putmarks() {
		cout << "Marks Obtained\n";
		cout << "Part1:\t" << part1 << endl;
		cout << "Part2:\t" << part2 << endl;
	}
};
class sports: public virtual student {
public:
	int score;
	void getscore() {
		cout << "Enter Sports Score:\t";
		cin >> score;
	}
	void putscore() {
		cout << "Sports Score is:\t" << score << endl;
	}
};
class result: public test, public sports {
	int total;
public:
	void display() {
		total = part1 + part2 + score;
		putnumber();
		putmarks();
		putscore();
		cout << "Total Score:\t" << total << endl;
	}
};
int main() {
	result obj;
	obj.getnumber();
	obj.getmarks();
	obj.getscore();
	obj.display();
	return 0;
}
