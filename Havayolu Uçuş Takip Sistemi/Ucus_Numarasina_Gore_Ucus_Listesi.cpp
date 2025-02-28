#include "Ucus_Numarasina_Gore_Ucus_LÝstesi.h"
#include <iostream>
#include <iomanip>

using namespace std;

Ucus_Numarasina_Gore_Ucus_Listesi::Ucus_Numarasina_Gore_Ucus_Listesi()
{
    baslangic=NULL;
}

Ucus_Numarasina_Gore_Ucus_Listesi::~Ucus_Numarasina_Gore_Ucus_Listesi()
{

}

void Ucus_Numarasina_Gore_Ucus_Listesi::UcusEkle(Ucus& a)
{
    Ucak * yeniUcus=new Ucak;
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
        Ucak * simdiki=baslangic;
        Ucak * onceki=NULL;
        while(simdiki!=NULL&&simdiki->numara<a.ucusNo)
        {
            onceki=simdiki;
            simdiki=simdiki->sonraki;
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

void Ucus_Numarasina_Gore_Ucus_Listesi::ListeyiDiz()
{
    Ucak * simdiki=baslangic;
    while(simdiki!=NULL)
    {
        cout<<"\n"<<simdiki->numara<<"\t\t"<<simdiki->kalkis<<"\t\t"<<simdiki->varis<<"\t\t"<<simdiki->kalkisSaati<<"."<<simdiki->kalkisDakikasi<<"\t\t"<<simdiki->koltuk<<"\t\t"<<simdiki->vipKoltuk;
        simdiki=simdiki->sonraki;
    }
}

void Ucus_Numarasina_Gore_Ucus_Listesi::KoltukGuncelle(int no,int yeniLuksKoltuk)
{
    Ucak * aranan=NULL;
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
    cout<<"\nUcus verileriniz su sekilde guncellenmistir:";
    cout<<"\n\nUcus No     \tKalkis Yeri     Varis Yeri     \tZamani     \tNormal Koltuk Sayisi     \tLuks Koltuk Sayisi\n-------     \t-----------     ----------     \t------     \t--------------------    \t------------------\n";
    cout<<aranan->numara<<"\t\t"<<aranan->kalkis<<"\t\t"<<aranan->varis<<"\t\t"<<setfill('0')<<setw(2)<<aranan->kalkisSaati<<":"<<setfill('0')<<setw(2)<<aranan->kalkisDakikasi<<"\t\t"<<aranan->koltuk<<"\t\t\t\t"<<aranan->vipKoltuk<<"\n";
}

void Ucus_Numarasina_Gore_Ucus_Listesi::UcusBilgisiGor(int no)
{
    Ucak * aranan=NULL;
    aranan=baslangic;
    while(aranan!=NULL)
    {
        if(aranan->numara==no)
        {
            break;
        }
        aranan=aranan->sonraki;
    }
    cout<<"\nUcus iliskin veriler su sekildedir:";
    cout<<"\n\nUcus No     \tKalkis Yeri     Varis Yeri     \tZamani     \tNormal Koltuk Sayisi     \tLuks Koltuk Sayisi\n-------     \t-----------     ----------     \t------     \t--------------------    \t------------------\n";
    cout<<aranan->numara<<"\t\t"<<aranan->kalkis<<"\t\t"<<aranan->varis<<"\t\t"<<setfill('0')<<setw(2)<<aranan->kalkisSaati<<":"<<setfill('0')<<setw(2)<<aranan->kalkisDakikasi<<"\t\t"<<aranan->koltuk<<"\t\t\t\t"<<aranan->vipKoltuk<<"\n";
}

void Ucus_Numarasina_Gore_Ucus_Listesi::LuksKoltukluUcuslar()
{
    int sayi=0;
    Ucak * aranan=NULL;
    aranan=baslangic;
    while(aranan!=NULL)
    {
        if(aranan->vipKoltuk>0)
        {
            sayi++;
            if(sayi==1)
            {
                cout<<"Luks koltuk iceren ucuslar su sekildedir:";
                cout<<"\n\nUcus No     \tKalkis Yeri     Varis Yeri     \tZamani     \tNormal Koltuk Sayisi     \tLuks Koltuk Sayisi\n-------     \t-----------     ----------     \t------     \t--------------------    \t------------------\n";
            }
            cout<<aranan->numara<<"\t\t"<<aranan->kalkis<<"\t\t"<<aranan->varis<<"\t\t"<<setfill('0')<<setw(2)<<aranan->kalkisSaati<<":"<<setfill('0')<<setw(2)<<aranan->kalkisDakikasi<<"\t\t"<<aranan->koltuk<<"\t\t\t\t"<<aranan->vipKoltuk<<"\n";
        }
        aranan=aranan->sonraki;
    }
    if(sayi==0)
    {
        cout<<"\nLuks koltuk iceren ucus bulunmamaktadir:";
    }
}

void Ucus_Numarasina_Gore_Ucus_Listesi::UcusSil(int no)
{
    cout <<"\n"<<no<< " numarali ucus silindi." << endl;
    if (baslangic->numara==no)
    {
        Ucak * silinecek = baslangic;
        baslangic = baslangic->sonraki;
        delete silinecek;
        return;
    }
    Ucak * onceki = baslangic;
    Ucak * simdiki = baslangic->sonraki;
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

int Ucus_Numarasina_Gore_Ucus_Listesi::NumaraVarMi(int a)
{
    int sayi=0;
    Ucak * p=NULL;
    p=baslangic;
    while(p!=NULL)
    {
        if(p->numara==a)
        {
            sayi++;
            break;
        }
        p=p->sonraki;
    }
    if(sayi==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}
