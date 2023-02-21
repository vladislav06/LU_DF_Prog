/******************************************************************************************************
Sastādīt C++ programmu, kas pieprasa ievadīt N veselus skaitļus un nosaka
garākās stingri augošas virknes garumu. Jābūt iespējai programmu izpildīt
atkārtoti, neizejot no programmas.
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include <iostream>

int main() {

  int ok;
  int n;
  int num;
  int lastNum = INT32_MIN;

  // tagadnejas augošas secības garums
  int augGarums = 0;
  // visgarakas augošas secības garums
  int augLielGar = 0;
  do {

    do {
      std::cout << "Ievadiet veselo skaitļu skaitu: ";
      std::cin >> n;
    } while (n <= 0);

    for (int i = 1; i <= n; i++) {
      std::cout << "Ievadiet " << i << " skaitli: ";
      std::cin >> num;
      // parbaudam vai šis skaitlis ir lielāks neka ieprekšejais skaitlis
      if (num > lastNum) {
        lastNum = num;
        augGarums++;
        // ja nav lielāks, tad beigam secību, un sākam skaitīt no sākuma
      } else {
        if (augGarums > augLielGar) {
          augLielGar = augGarums;
          augGarums = 0;
        }
      }
    }
    // parbaudam pēdējas secības garumu
    if (augGarums > augLielGar) {
      augLielGar = augGarums;
    }

    std::cout << "Garākās stingri augošas virknes garums ir " << augLielGar
              << "\n";

    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
