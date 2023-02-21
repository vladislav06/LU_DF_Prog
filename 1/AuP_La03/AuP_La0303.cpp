/******************************************************************************************************
 Sastādīt C++ programmu, kas pieprasa ievadīt N veselus skaitļus un nosaka
lielākā skaitļa vērtību. Jābūt iespējai programmu izpildīt atkārtoti, neizejot
no programmas.
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include <iostream>

int main() {

  int ok;
  // skaitļu skaits
  int n = 0;
  //
  int num = 0;
  // max skaitlis
  int max = 0;

  do {

    do {
      std::cout << "Ievadiet positivo skaitļu skaitu: ";
      std::cin >> n;
    } while (n <= 0);

    for (int i = 1; i <= n; i++) {
      std::cout << "Ievadiet " << i << " skaitli: ";
      std::cin >> num;
      if (num != 0) {
        if (num > max)
          max = num;
      }
    }
    std::cout << "Lielakais numurs ir: " << max << std::endl;

    std::cout << " Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
