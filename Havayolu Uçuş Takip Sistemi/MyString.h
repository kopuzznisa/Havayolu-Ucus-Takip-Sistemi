#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED
#include <iostream>

class MyString
{
    public:
        void Ayarla(std::string,std::string);
        bool Kiyasla(std::string,std::string);
        friend class Kalkis_Yerine_Gore_Ucus_Listesi;
    private:
        std::string sehir1;
        std::string sehir2;
};

#endif // MYSTRING_H_INCLUDED
