/******************************************************************************************************
Sastādīt C++ programmu, kas ļauj noskaidrot, cik reizes teksta rindiņā ir
sastopams konkrēts simbols. Gan teksta rindiņu, gan simbolu ievada lietotājs.
Teksta rindiņa jāsaglabā programmā kā zema līmeņa simbolu virkne. Jābūt iespējai
programmu izpildīt atkārtoti, neizejot no programmas.
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include <iostream>

int main() {

  int ok;

  do {
    // Atstājam vietu priekš \n
    char str[101];
    char simb;
    int count = 0;

    std::cout << "Ievadiet simbolu virkni, līdz 100 simboliem:\n";
    std::cin.getline(str, 101);

    std::cout << "Ievadiet meklējamo simbolu: ";
    std::cin.get(simb);

    // Iterēšana līdz virken beigam
    for (int i = 0; str[i] != '\n'; i++) {
      if (str[i] == simb)
        count++;
    }

    std::cout << "Simbols sastopas " << count << " reizes\n";

    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
    std::cin.ignore();// Ignore \n
  } while (ok == 1);

  return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
