#include <iostream>
#include "sketch.h"

int main(int argc, char const *argv[])
{
    sketch s(4,10);
    unsigned int i, f;

    do
    {
        std::cout << "item >>" ;
        std::cin >> i;
        s.insert(i);
        f = s.frequency(i);
        std::cout << "freq >>" << f << std::endl;
        s.print();
    } while (i>0);
}

