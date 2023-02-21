/******************************************************************************************************
Izveidot C++ projektu AuPLa0701, kurā tiek atrisināts sekošs uzdevums.
Lietotājs ievada N veselus skaitļus. Skaitļu skaitu N (N <=100) uzdod lietotājs.
Skaitļi jāsaglabā masīvā. Jāizveido un jāizdrukā jauns masīvs, kurā ir
ierakstīti katra ievadītā skaitļa ciparu skaiti. Skaitļa ciparu skaita
aprēķināšanai jāizveido funkcija cipskaits(sk), kas atgriež kā rezultātu skaitļa
sk ciparu skaitu. Projektam jāsastāv no main funkcijas faila main.cpp, funkcijas
cipskaits galvenes(header) faila cipskaits.h un funkcijas cipskaits realizācijas
faila cipskaits.cpp. Jābūt iespējai projektu izpildīt atkārtoti, neizejot no
projekta.

*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include "cipskaits.h"
#include <iostream>

int main() {

  int ok;
  int n;
  int skaitli[100];
  do {
    do {
      std::cout << "Ievadiet skaitļu skaitu, nevairāk kā 100: ";
      std::cin >> n;
    } while (n > 100);

    for (int i = 0; i < n; i++) {
      std::cout << "Ievadiet " << i + 1 << " skaitli: ";
      std::cin >> skaitli[i];
    }

    for (int i = 0; i < n; i++) {
      std::cout << cipskaits(skaitli[i]) << std::endl;
    }

    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
