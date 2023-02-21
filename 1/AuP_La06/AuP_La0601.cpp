/******************************************************************************************************
Sastādīt C++ programmu, kas noskaidro, vai doto naudas daudzumu var izveidot, lietojot pa vienai reizei tikai divas no dotajām trīs monētām – 1, 2 un 5 centu monētas.
Realizācijā jālieto priekšraksts „switch”.
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include <iostream>

int main() {

  int ok;
  int money;
  do {
    std::cout << "Ievadiet naudu daudzumu: ";
    std::cin >> money;
    switch (money) {
    case 3:
      std::cout << "var\n";
      break;
    case 6:
      std::cout << "var\n";
      break;
    case 7:
      std::cout << "var\n";
      break;
    default:
      std::cout << "nevar\n";
    }

    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
