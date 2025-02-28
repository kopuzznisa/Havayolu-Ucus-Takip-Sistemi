#ifndef KALKIS_YERINE_GORE_UCUS_LISTESI_H_INCLUDED
#define KALKIS_YERINE_GORE_UCUS_LISTESI_H_INCLUDED
#include <string>
#include "Ucus.h"
#include "MyString.h"

class Kalkis_Yerine_Gore_Ucus_Listesi
{
    private:
        struct Ucak2
        {
            int numara;
            std::string kalkis;
            std::string varis;
            int kalkisSaati;
            int kalkisDakikasi;
            int koltuk;
            int vipKoltuk;
            struct Ucak2 * sonraki;
        };
        Ucak2 * baslangic;
    public:
        Kalkis_Yerine_Gore_Ucus_Listesi();
        ~Kalkis_Yerine_Gore_Ucus_Listesi();
        void UcusEkle(Ucus&);
        void KoltukGuncelle(int,int);
        void UcusSil(int);
        void KalkisYeriAra(std::string);
        void VarisYeriAra(std::string);
        void GuzergahAra(std::string,std::string);
};


#endif // KALKIS_YERINE_GORE_UCUS_LISTESI_H_INCLUDED
