#include <iostream>
#include "String.h"

int main()
{
    String s1("Hello");
    String s2{ s1 };
    String s3('*', 20);

    s2 = s1 * 5;

    std::cout << s2 << "\n";

    return 0;
}
