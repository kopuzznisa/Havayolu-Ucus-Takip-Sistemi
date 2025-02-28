#include <iostream>
#include "MyString.h"

using namespace std;

void MyString::Ayarla(string birinci,string ikinci)
{
    sehir1=birinci;
    sehir2=ikinci;
}

bool MyString::Kiyasla(string birinci, string ikinci)
{
    Ayarla(birinci,ikinci);
    if(sehir1==sehir2)
    {
        return 1;
    }
    return 0;
}
