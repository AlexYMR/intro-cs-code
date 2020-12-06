#include <iostream>

using namespace std;

int main()
{
   int x = 42;
   int y = 84;
   long long z = 5;

   cout << &x << " x: " << x << endl;
   cout << &y << " y: " << y << endl;
   cout << &z << " z: " << z << endl;

   int myArray[] = {1, 2, 3, 4, 5};

   for(int i = -10; i < 10; i++)
   {
      cout << myArray + i << " myArray[" << i << "]: " << myArray[i] << endl;
   }

   myArray[-5] = -24;
   myArray[-1] = -24;

   cout << "MyArray[-5] = -24" << endl;
   cout << "MyArray[-1] = -24" << endl;

   cout << &x << " x: " << x << endl;
   cout << &y << " y: " << y << endl;
   cout << &z << " z: " << z << endl;
}
