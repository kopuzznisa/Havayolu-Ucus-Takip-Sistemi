#ifndef UCUS_H_INCLUDED
#define UCUS_H_INCLUDED
#include <string>

class Ucus
{
    private:
        int ucusNo;
        std::string kalkisSehri;
        std::string varisSehri;
        int kalkisSaati;
        int kalkisDakikasi;
        int duzKoltuk;
        int luksKoltuk;
    public:
        void UcusBilgisiAl(int,std::string,std::string,int,int,int,int,int);
      //  void UcusSil(int);
        void UcusVerisiAyarla(int,std::string,std::string,int,int,int,int);
        std::string BuyukHarf(std::string &);
        friend class Ucus_Numarasina_Gore_Ucus_Listesi;
        friend class Kalkis_Yerine_Gore_Ucus_Listesi;
};

#endif // UCUS_H_INCLUDED
