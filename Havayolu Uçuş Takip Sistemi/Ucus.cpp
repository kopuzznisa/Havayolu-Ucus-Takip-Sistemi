#include "Ucus.h"
#include <iostream>
#include <iomanip>

using namespace std;

string Ucus::BuyukHarf(string &s)
{
    for(int i=0;i<s.length();i++)
    {
        s[i]=toupper(s[i]);
    }
    return s;
}

void Ucus::UcusVerisiAyarla(int no,string kalkisYeri,string varisYeri,int saat,int dakika,int fakirKoltuk,int luks)
{
    ucusNo=no;
    kalkisSehri=kalkisYeri;
    varisSehri=varisYeri;
    kalkisSaati=saat;
    kalkisDakikasi=dakika;
    duzKoltuk=fakirKoltuk;
    luksKoltuk=luks;
}

void Ucus::UcusBilgisiAl(int no,string kalkisYeri,string varisYeri,int saat,int dakika,int fakirKoltuk,int luks,int secim)
{
    cout<<"Kalkis yeri giriniz:";
    cin>>kalkisYeri;
    BuyukHarf(kalkisYeri);
    cout<<"Varis yeri giriniz:";
    cin>>varisYeri;
    BuyukHarf(varisYeri);
    cout<<"Kalkis saatini giriniz:";
    cin>>saat;
    cout<<"Kalkis dakikasini giriniz:";
    cin>>dakika;
    if(secim==1)
    {
        cout<<"Koltuk sayisini giriniz:";
        cin>>fakirKoltuk;
        luks=0;
    }
    else
    {
        cout<<"Normal koltuk sayisini giriniz:";
        cin>>fakirKoltuk;
        cout<<"Luks koltuk sayisini giriniz:";
        cin>>luks;
    }
    cout<<"\nYeni ucusa iliskin bilgiler su sekildedir:\n\n";
    if(luks==0)
    {
        cout<<"Ucus No     \tKalkis Yeri     Varis Yeri     \tZamani     \tKoltuk Sayisi\n-------     \t-----------     ----------     \t------     \t-------------\n";
        cout<<no<<"\t\t"<<kalkisYeri<<"\t\t"<<varisYeri<<"\t\t"<<setfill('0')<<setw(2)<<saat<<":"<<setfill('0')<<setw(2)<<dakika<<"\t\t"<<fakirKoltuk<<"\n";
        cout<<"\nUcusunuz basariyla eklenmistir.\n";
    }
    else
    {
        cout<<"Ucus No     \tKalkis Yeri     Varis Yeri     \tZamani     \tNormal Koltuk Sayisi     \tLuks Koltuk Sayisi\n-------     \t-----------     ----------     \t------     \t--------------------    \t------------------\n";
        cout<<no<<"\t\t"<<kalkisYeri<<"\t\t"<<varisYeri<<"\t\t"<<setfill('0')<<setw(2)<<saat<<":"<<setfill('0')<<setw(2)<<dakika<<"\t\t"<<fakirKoltuk<<"\t\t\t\t"<<luks<<"\n";
        cout<<"\nUcusunuz basariyla eklenmistir.\n";
    }
    UcusVerisiAyarla(no,kalkisYeri,varisYeri,saat,dakika,fakirKoltuk,luks);
}

