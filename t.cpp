#include <iostream>
using namespace std;

int main()
{

    int x=10;
    int **t, *p;
    t=&p;
    p=&x;
    cout<<**t<< " "<<*p<<endl;
    return 0;
}
