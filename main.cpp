#include "Double.h"
#include "fraction.h"
#include "irracional.h"

using namespace std;

int main()
{
    fraction frac(
            new fraction(
                    new irracional(12),
                    new irracional(24)
            ),
            new fraction(
                    new Double(3),
                    new irracional(2)
            )
    );
    fraction frac1(
            new fraction(
                    new irracional(13),
                    new irracional(26)
            ),
            new fraction(
                    new Double(5),
                    new irracional(13)
            )
    );
    
    frac *= frac1;
    cout << frac->to_string() << endl;
    return 0;
}
