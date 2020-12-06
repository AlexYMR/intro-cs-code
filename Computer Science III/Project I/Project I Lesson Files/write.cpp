#include <fstream>

using namespace std;

int main()
{
   ofstream fout("twonums.txt");
   int x = 3;
   int y = 734;
   fout << x << " " << y << endl;
}
