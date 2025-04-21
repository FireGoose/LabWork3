#include <iostream>
#include "TString.h"

int main()
{
    char* c = new char[5];
    for (int i = 0; i < 5; ++i)
        c[i] = 'a';
    TString s(c, 5);
    TString s1(s);
    cout << s1;
    return 0;
}
