#include "Kalkis_Yerine_Gore_Ucus_Listesi.h"
#include <iostream>
#include <iomanip>

using namespace std;

Kalkis_Yerine_Gore_Ucus_Listesi::Kalkis_Yerine_Gore_Ucus_Listesi()
{
    baslangic=NULL;
}

Kalkis_Yerine_Gore_Ucus_Listesi::~Kalkis_Yerine_Gore_Ucus_Listesi()
{
}

void Kalkis_Yerine_Gore_Ucus_Listesi::UcusEkle(Ucus& a)
{
    Ucak2 * yeniUcus=new Ucak2;
    yeniUcus->sonraki=NULL;
    yeniUcus->numara=a.ucusNo;
    yeniUcus->kalkis=a.kalkisSehri;
    yeniUcus->koltuk=a.duzKoltuk;
    yeniUcus->varis=a.varisSehri;
    yeniUcus->kalkisSaati=a.kalkisSaati;
    yeniUcus->kalkisDakikasi=a.kalkisDakikasi;
    yeniUcus->vipKoltuk=a.luksKoltuk;
    if(baslangic==NULL)
    {
        baslangic=yeniUcus;
    }
    else
    {
        Ucak2 * simdiki=baslangic;
        Ucak2 * onceki=NULL;
        while(simdiki!=NULL&&simdiki->kalkis<a.kalkisSehri)
        {
            onceki=simdiki;
            simdiki=simdiki->sonraki;
        }
        if(simdiki->kalkis==a.kalkisSehri)
        {
            while(simdiki!=NULL&&simdiki->kalkisSaati<a.kalkisSaati)
            {
                onceki=simdiki;
                simdiki=simdiki->sonraki;
            }
            if(simdiki->kalkisSaati==a.kalkisSaati)
            {
                while(simdiki!=NULL&&simdiki->kalkisDakikasi<a.kalkisDakikasi)
                {
                    onceki=simdiki;
                    simdiki=simdiki->sonraki;
                }
            }
        }
        if(onceki==NULL)
        {
            baslangic=yeniUcus;
            yeniUcus->sonraki=simdiki;
        }
        else
        {
            onceki->sonraki=yeniUcus;
            yeniUcus->sonraki=simdiki;
        }
    }
}

void Kalkis_Yerine_Gore_Ucus_Listesi::KalkisYeriAra(string sehir)
{
    int sayi=0;
    MyString nesne;
    Ucus cisim;
    Ucak2 * aranan=NULL;
    aranan=baslangic;
    cout<<"Kalkis sehri giriniz:";
    cin>>sehir;
    cisim.BuyukHarf(sehir);
    while(aranan!=NULL)
    {
        if(nesne.Kiyasla(aranan->kalkis,sehir))
        {
            sayi++;
            if(sayi==1)
            {
                cout<<"\n\nUcus No     \tKalkis Yeri     Varis Yeri     \tZamani     \tNormal Koltuk Sayisi     \tLuks Koltuk Sayisi\n-------     \t-----------     ----------     \t------     \t--------------------    \t------------------\n";
            }
            cout<<aranan->numara<<"\t\t"<<aranan->kalkis<<"\t\t"<<aranan->varis<<"\t\t"<<setfill('0')<<setw(2)<<aranan->kalkisSaati<<":"<<setfill('0')<<setw(2)<<aranan->kalkisDakikasi<<"\t\t"<<aranan->koltuk<<"\t\t\t\t"<<aranan->vipKoltuk<<"\n";
        }
        aranan=aranan->sonraki;
    }
    if(sayi==0)
    {
        cout<<"\nAradiginiz kriterlere uygun ucus bulunmamaktadir:";
    }
}


void Kalkis_Yerine_Gore_Ucus_Listesi::VarisYeriAra(string sehir)
{
    int sayi=0;
    Ucus cisim;
    MyString nesne;
    Ucak2 * aranan=NULL;
    aranan=baslangic;
    cout<<"Varis sehri giriniz:";
    cin>>sehir;
    cisim.BuyukHarf(sehir);
    while(aranan!=NULL)
    {
        if(nesne.Kiyasla(aranan->varis,sehir))
        {
            sayi++;
            if(sayi==1)
            {
                cout<<"\n\nUcus No     \tKalkis Yeri     Varis Yeri     \tZamani     \tNormal Koltuk Sayisi     \tLuks Koltuk Sayisi\n-------     \t-----------     ----------     \t------     \t--------------------    \t------------------\n";
            }
            cout<<aranan->numara<<"\t\t"<<aranan->kalkis<<"\t\t"<<aranan->varis<<"\t\t"<<setfill('0')<<setw(2)<<aranan->kalkisSaati<<":"<<setfill('0')<<setw(2)<<aranan->kalkisDakikasi<<"\t\t"<<aranan->koltuk<<"\t\t\t\t"<<aranan->vipKoltuk<<"\n";
        }
        aranan=aranan->sonraki;
    }
    if(sayi==0)
    {
        cout<<"\nAradiginiz kriterlere uygun ucus bulunmamaktadir:";
    }
}

void Kalkis_Yerine_Gore_Ucus_Listesi::GuzergahAra(string sehir1,string sehir2)
{
    int sayi=0;
    MyString nesne;
    Ucus cisim;
    Ucak2 * aranan=NULL;
    aranan=baslangic;
    cout<<"Kalkis sehri giriniz:";
    cin>>sehir1;
    cout<<"Varis sehri giriniz:";
    cin>>sehir2;
    cisim.BuyukHarf(sehir1);
    cisim.BuyukHarf(sehir2);
    while(aranan!=NULL)
    {
        if(nesne.Kiyasla(aranan->varis,sehir2)&&nesne.Kiyasla(aranan->kalkis,sehir1))
        {
            sayi++;
            if(sayi==1)
            {
                cout<<"\n\nUcus No     \tKalkis Yeri     Varis Yeri     \tZamani     \tNormal Koltuk Sayisi     \tLuks Koltuk Sayisi\n-------     \t-----------     ----------     \t------     \t--------------------    \t------------------\n";
            }
            cout<<aranan->numara<<"\t\t"<<aranan->kalkis<<"\t\t"<<aranan->varis<<"\t\t"<<setfill('0')<<setw(2)<<aranan->kalkisSaati<<":"<<setfill('0')<<setw(2)<<aranan->kalkisDakikasi<<"\t\t"<<aranan->koltuk<<"\t\t\t\t"<<aranan->vipKoltuk<<"\n";
        }
        aranan=aranan->sonraki;
    }
    if(sayi==0)
    {
        cout<<"\nAradiginiz kriterlere uygun ucus bulunmamaktadir:";
    }
}

void Kalkis_Yerine_Gore_Ucus_Listesi::KoltukGuncelle(int no,int yeniLuksKoltuk)
{
    Ucak2 * aranan=NULL;
    aranan=baslangic;
    while(aranan!=NULL)
    {
        if(aranan->numara==no)
        {
            break;
        }
        aranan=aranan->sonraki;
    }
    aranan->vipKoltuk=yeniLuksKoltuk;
}

void Kalkis_Yerine_Gore_Ucus_Listesi::UcusSil(int no)
{
    if (baslangic->numara==no)
    {
        Ucak2 * silinecek = baslangic;
        baslangic = baslangic->sonraki;
        delete silinecek;
        return;
    }
    Ucak2 * onceki = baslangic;
    Ucak2 * simdiki = baslangic->sonraki;
    while (simdiki != NULL)
    {
        if (simdiki->numara == no)
        {
            onceki->sonraki = simdiki->sonraki;
            delete simdiki;
        }
        onceki = simdiki;
        simdiki = simdiki->sonraki;
    }
}
