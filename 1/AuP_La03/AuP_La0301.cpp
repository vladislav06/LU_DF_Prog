/******************************************************************************************************
Sastādīt C++ programmu, kas dotam mēneša kārtas numuram (1, 2, ..., 12) nosaka
piederību gadalaikam. Ziemas mēneši: 1, 2, 12; pavasara mēneši: 3, 4, 5; vasaras
mēneši: 6, 7, 8; rudens mēneši: 8, 10, 11. Mēneša piederības gadalaikam
noteikšanai lietot zarošanās priekšrakstu. Jābūt iespējai programmu izpildīt
atkārtoti, neizejot no programmas.
*******************************************************************************************************/
/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include <iostream>

int main() {
  int month = 0;
  int ok = 0;
  do {
    std::cout << "Ievadiet meneša kārtas numuru: ";
    std::cin >> month;

    if (month < 1 || month > 12) {
      std::cout << "Ievadiet pareizo menes numuru!\n";
      continue;
    }

    if (month == 1 || month == 2 || month == 12)
      std::cout << "Tas ir ziemas mēnesis\n";
    else if (month >= 3 && month <= 5)
      std::cout << "Tas ir pavasaras mēnesis\n";
    else if (month >= 6 && month <= 8)
      std::cout << "Tas ir vasaras mēnesis\n";
    else if (month >= 8 && month <= 10)
      std::cout << "Tas ir rudens mēnesis\n";

    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;

  } while (ok == 1);

  return 0;
}
/***********************  Testu plāns ***********************
      ievads    izvads
         1      ziema
         5      pavasara
         7      vasara
         10     rudens
*************************************************************/
