#include <cstring>
#include <iostream>
#include "Human.h";
using namespace std;


int main(int argc, char **argv)
{
    double x = 2000, y = 3000;
    Human h("Ken Lai", x, y);
    h.display();
    return 0;
}
