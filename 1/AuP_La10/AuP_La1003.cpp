/******************************************************************************************************
basic prog
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022


#include <iostream>
#include <cmath>

/// Atrgriež true ja skaitli var izteikt kā naturāla skaitļa kvadrātu
bool skToNatSqrt(int n) {
    // jā std::sqrt(n) atgriež veselo skaitli, tad n var izteikt ka naturālo skaitļu kvadrātu
    return std::abs(std::sqrt(n) - (int) std::sqrt(n)) < 0.00001;
}

int main() {

    int ok;

    do {
        int n;
        int m;
        std::cout << "Ievadiet naturālo skaitļu intervālu:\n";
        std::cout << "no: ";
        std::cin >> m;
        std::cout << "līdz: ";
        std::cin >> n;
        std::cout << "\n";

        std::cout
                << "Visi naturālie skaitļi kuri pieder šim intervālam un kurus var izteikt kā naturāla skaitļa kvadrātu:\n";
        for (int i = m; i <= n; i++) {
          if( skToNatSqrt(i)){
              std::cout<<i<<", ";
          }
        }
        std::cout<<"\n";

        std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
        std::cin >> ok;
    } while (ok == 1);

    return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
