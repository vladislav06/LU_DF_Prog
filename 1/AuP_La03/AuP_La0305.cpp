/******************************************************************************************************
 Izveidot C++ programmu, kura ļauj ievadīt trīs naturālus skaitļus un noskaidro,
vai starp skaitļiem ir kāds “laimīgais skaitlis”. “Laimīgais skaitlis” ir tāds
skaitlis, kura pēdējie divi cipari ir 21. Noskaidrošanu veikt tikai ar
skaitliskām darbībām.
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include <iostream>

int main() {

  int ok;
  int num1 = 0;
  int num2 = 0;
  int num3 = 0;
  do {

    do {
      std::cout << "Ievadiet pirmo naturalo skaitli: ";
      std::cin >> num1;
    } while (num1 <= 0);


    do {
      std::cout << "Ievadiet otro naturalo skaitli: ";
      std::cin >> num2;
    } while (num2 <= 0);


    do {
      std::cout << "Ievadiet trešo naturalo skaitli: ";
      std::cin >> num3;
    } while (num3 <= 0);


    if (num1 % 100 == 21) std::cout<<"Pirmais skaitlis ir laimigais skaitlis\n";
    if (num2 % 100 == 21) std::cout<<"Otrais skaitlis ir laimigais skaitlis\n";
    if (num3 % 100 == 21) std::cout<<"Trešais skaitlis ir laimigais skaitlis\n";


    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
