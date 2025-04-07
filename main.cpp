
#include <iostream>
#include "Date.h"

using namespace std;

int main() {
    // Test cases as per requirements
    cout << "1. Default constructor test:\n";
    Date d1;
    cout << d1.toString1() << "\n\n";

    cout << "2. Constructor with parameters test:\n";
    Date d2(2, 28, 2009);
    cout << d2.toString2() << "\n\n";

    cout << "3. setDate() test:\n";
    d1.setDate(3, 15, 2012);
    cout << d1.toString3() << "\n\n";

    cout << "4. Invalid date test (13/45/2018):\n";
    d1.setDate(13, 45, 2018);
    cout << d1.toString1() << "\n\n";

    cout << "5. Invalid date test (4/31/2000):\n";
    d1.setDate(4, 31, 2000);
    cout << d1.toString1() << "\n\n";

    cout << "6. Invalid date test (2/29/2009):\n";
    d1.setDate(2, 29, 2009);
    cout << d1.toString1() << "\n\n";

    cout << "7. Date subtraction test 1:\n";
    Date d3(4, 10, 2014);
    Date d4(4, 18, 2014);
    cout << "Days between " << d3 << " and " << d4 << ": " 
         << (d4 - d3) << "\n\n";

    cout << "8. Date subtraction test 2:\n";
    d3.setDate(2, 2, 2006);
    d4.setDate(11, 10, 2003);
    cout << "Days between " << d3 << " and " << d4 << ": " 
         << (d3 - d4) << "\n\n";

    cout << "9-11. Increment/Decrement tests:\n";
    Date d5(2, 29, 2008);
    cout << "Original: " << d5 << "\n";
    cout << "After --: " << --d5 << "\n";
    cout << "After ++: " << ++d5 << "\n";
    cout << "After post--: " << d5-- << "\n";
    cout << "Result: " << d5 << "\n";
    cout << "After post++: " << d5++ << "\n";
    cout << "Result: " << d5 << "\n\n";

    cout << "12-14. Year boundary tests:\n";
    Date d6(12, 31, 2024);
    cout << "Original: " << d6 << "\n";
    cout << "After post++: " << d6++ << "\n";
    cout << "Result: " << d6 << "\n";
    cout << "After post--: " << d6-- << "\n";
    cout << "Result: " << d6 << "\n";
    cout << "After pre++: " << ++d6 << "\n";
    cout << "After pre--: " << --d6 << "\n\n";

    cout << "15-16. Stream operator tests:\n";
    Date d7;
    cin >> d7;
    cout << "Entered date: " << d7 << "\n";

    return 0;
}
