/******************************************************************************************************
Sastādīt C++ programmu, kas pieprasa ievadīt virknes N elementus un nosaka
lielākā elementa vērtību. Jānodrošina apstrāde veselu skaitļu virknēm un reālu
skaitļu virknēm (float un double). Risinājumā jāizmanto pārslogotas funkcijas
lielakais(a, b), kas atgriež kā rezultātu lielāko no dotajiem elementiem a un b.
Funkcijas lielakais(a, b) realizācijā jāizmanto nosacījuma funktors (conditional
operator).
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include <iostream>

double lielakais(double a, double b) { return a > b ? a : b; }

float lielakais(float a, float b) { return a > b ? a : b; }

int lielakais(int a, int b) { return a > b ? a : b; }

int main() {

  int ok;
  int n;

  double maxd;
  float maxf;
  int maxi;

  double numd;
  float numf;
  int numi;

  int type;
  do {
    std::cout << "Ievadiet ciparu skaitu";
    std::cin >> n;

    do{
    std::cout << "Ievadiet virknes tipu: 1-int, 2-float, 3-double\n";
    std::cin >> type;

    }while(1 > type || type > 3);

    switch (type) {
    case 1:
      std::cout << "Ievadiet 1 skaitli: ";
      std::cin>>maxi;
      for (int i = 2; i <= n; i++) {
        std::cout << "Ievadiet " << i << " skaitli: ";
        std::cin >> numi;
        maxi = lielakais(numi, maxi);
      }
      std::cout << "Lielakais skaitlis ir " << maxi << "\n";
    case 2:
      std::cout << "Ievadiet 1 skaitli: ";
      std::cin>>maxf;
      for (int i = 2; i <= n; i++) {
        std::cout << "Ievadiet " << i << " skaitli: ";
        std::cin >> numf;
        maxf = lielakais(numf, maxf);
      }
      std::cout << "Lielakais skaitlis ir " << maxf << "\n";
    case 3:
      std::cout << "Ievadiet 1 skaitli: ";
      std::cin>>maxd;
      for (int i = 2; i <= n; i++) {
        std::cout << "Ievadiet " << i << " skaitli: ";
        std::cin >> numd;
        maxd = lielakais(numd, maxd);
      }
      std::cout << "Lielakais skaitlis ir " << maxd << "\n";
      break;
    }

    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
