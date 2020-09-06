#include "irracional.h"
using namespace std;
int main()
{
    
    irracional a("2#5");
    cout << a << endl;
    
    irracional b(3,5);
    cout << b << endl;
    
    irracional c (4900);
    cout << c << endl;
    
    return 0;
}
