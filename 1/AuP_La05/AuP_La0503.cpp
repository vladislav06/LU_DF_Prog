/******************************************************************************************************
Sastādīt C++ programmu, kas dotam naturālam skaitlim nosaka dota cipara skaitu
pierakstā. Risinājuma iegūšanai sastādīt funkciju, kura naturālam skaitlim
nosaka dota cipara skaitu pierakstā.
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include <iostream>

int digitCounter(int num);
int powOf10(int n);
int main() {

  int ok;
  int num;
  do {
    std::cout << "Ievadiet naturalo skaitli: ";
    std::cin >> num;

    std::cout << "Sim skaitlim ir " << digitCounter(num) << " skaitlu\n";

    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}

int digitCounter(int num) {
  int n = 0;
  while ((float)num / (float)powOf10(n) >= 1) {
    n++;
  }

  return n;
}

int powOf10(int n) {
  int i = 1;
  while (n > 0) {
    i = i * 10;
    n--;
  }
  return i;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
