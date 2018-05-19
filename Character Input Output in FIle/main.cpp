#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char ch;
    ofstream outfile("abc.txt");
    cout << "Type some text (type a dot and press enter to finish):\n";
    do {
        ch=getchar();
        if(ch=='.') break;
        outfile.put(ch);
    } while (ch != '.');
    return 0;
}