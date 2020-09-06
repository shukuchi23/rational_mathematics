#include "irracional.h"
using namespace std;
int main()
{
    
    irracional a("2#5");
    cout << a << endl;
    
    irracional b(3,5);
    cout << b << endl;
    
    irracional c (4900); // 2#33
    cout << c << endl;
    
//    cout << "b * c = " << b * c << endl;
    return 0;
}
