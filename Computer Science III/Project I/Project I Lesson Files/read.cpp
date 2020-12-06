#include <fstream>
#include <iostream>

using namespace std;

int main()
{
   /*ifstream fin("twonums.txt");
   int x;
   int y;
   fin >> x;
   fin >> y;
   cout << x << " " << y << endl;
	*/
	ifstream fin("textFile.txt");
	char c;
	while(fin.get(c)){
		cout << c;
	}

}
