#include "Ucus.h"
#include "Ucus_Numarasina_Gore_Ucus_LÝstesi.h"
#include "Kalkis_Yerine_Gore_Ucus_Listesi.h"

#include <iostream>

using namespace std;

int main()
{
    int no,koltuk,luks,saat,dakika,secim;
    string kalkis;
    string varis;
    char devam;
    Ucus_Numarasina_Gore_Ucus_Listesi nesne;
    Kalkis_Yerine_Gore_Ucus_Listesi cisim;
    Ucus bilgi;
    cout<<"*Havayolu Ucus Takip Sistemine Hos Geldiniz!*";
    do
    {
        cout<<"\nYapmak istediginiz islemi seciniz\n\n1 - Luks koltuk icermeyen yeni bir ucusun eklenmesi\n2 - Luks koltuk iceren yeni bir ucusun eklenmesi\n3 - Bir ucusun luks koltuk sayisinin guncellenmesi\n4 - Bir ucusun iptal edilmesi\n5 - Bir ucusun bilgilerinin goruntulenmesi\n6 - Luks koltuk iceren ucuslarin listelenmesi\n7 - Bir yere olan ucuslarin listelenmesi\n8 - Bir yerden kalkan ucuslarin listelenmesi\n9 - Bir yerden bir yere olan ucuslarin listelenmesi\n\n:";
        cin>>secim;
        while(secim>9||secim<1)
        {
            cout<<"\nSeciminiz 1 ile 9 sayilari arasinda bir tam sayi olmalidir, lutfen tekrar deneyiniz:";
            cin>>secim;
        }
        if(secim<6)
        {
            cout<<"Numara giriniz:";
            cin>>no;
            while(no>9999||no<1000)
            {
                cout<<"\nUcus numarasi 1000-9999 arasi bir tam sayi olmalidir, lutfen tekrar deneyiniz:";
                cin>>no;
            }
        }
        switch(secim)
        {
        case 1:
            if(nesne.NumaraVarMi(no))
            {
                cout<<"\nGirdiginiz ucus numarasi kayitlarda mevcuttur.";
            }
            else
            {
                bilgi.UcusBilgisiAl(no,kalkis,varis,saat,dakika,koltuk,luks,secim);
                nesne.UcusEkle(bilgi);
                cisim.UcusEkle(bilgi);
            }
            break;
        case 2:
            if(nesne.NumaraVarMi(no))
            {
                cout<<"\nGirdiginiz ucus numarasi kayitlarda mevcuttur.";
            }
            else
            {
                bilgi.UcusBilgisiAl(no,kalkis,varis,saat,dakika,koltuk,luks,secim);
                nesne.UcusEkle(bilgi);
                cisim.UcusEkle(bilgi);
            }
            break;
        case 3:
            if(nesne.NumaraVarMi(no))
            {
                cout<<"Yeni luks koltuk sayisini giriniz:";
                cin>>luks;
                nesne.KoltukGuncelle(no,luks);
                cisim.KoltukGuncelle(no,luks);
            }
            else
            {
                cout<<"\nGirdiginiz ucus numarasi kayitlarda mevcut degildir.";
            }
            break;
        case 4:
            if(nesne.NumaraVarMi(no))
            {
                nesne.UcusSil(no);
                cisim.UcusSil(no);
            }
            else
            {
                cout<<"\nGirdiginiz ucus numarasi kayitlarda mevcut degildir.";
            }
            break;
        case 5:
            if(nesne.NumaraVarMi(no))
            {
                nesne.UcusBilgisiGor(no);
            }
            else
            {
                cout<<"\nGirdiginiz ucus numarasi kayitlarda mevcut degildir.";
            }
            break;
        case 6:
            nesne.LuksKoltukluUcuslar();
            break;
        case 7:
            cisim.VarisYeriAra(varis);
            break;
        case 8:
            cisim.KalkisYeriAra(kalkis);
            break;
        case 9:
            cisim.GuzergahAra(varis,kalkis);
            break;
        }
        cout<<"\nDevam?";
        cin>>devam;
    }while(devam=='e');
    return 0;
}
