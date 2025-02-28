#ifndef UCUS_NUMARASINA_GORE_UCUS_LISTESI_H_INCLUDED
#define UCUS_NUMARASINA_GORE_UCUS_LISTESI_H_INCLUDED
#include <string>
#include "Ucus.h"

class Ucus_Numarasina_Gore_Ucus_Listesi
{
    private:
        struct Ucak
        {
            int numara;
            std::string kalkis;
            std::string varis;
            int kalkisSaati;
            int kalkisDakikasi;
            int koltuk;
            int vipKoltuk;
            struct Ucak * sonraki;
        };
        Ucak * baslangic;
    public:
        Ucus_Numarasina_Gore_Ucus_Listesi();
        ~Ucus_Numarasina_Gore_Ucus_Listesi();
        void UcusEkle(Ucus&);
        void ListeyiDiz();
        void KoltukGuncelle(int,int);
        void UcusSil(int);
        void UcusBilgisiGor(int);
        void LuksKoltukluUcuslar();
        int NumaraVarMi(int);
};

#endif // UCUS_NUMARASINA_GORE_UCUS_LISTESI_H_INCLUDED
