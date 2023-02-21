/******************************************************************************************************
Sastādīt C++ programmu, kas ļauj ievadīt teksta rindiņu un izdrukā to pa simbolam, pārveidojot visus burtu simbolus par lielajiem burtiem. Ievade programmā jāveic pa vienam simbolam.
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022


#include <iostream>

int main() {

  int ok;

  do
  {
  char simb;

  std::cin.get(simb);
  std::cin.ignore();
  while(simb !='\n'){
    if(std::isalpha(simb))
      std::cout<<(char)std::toupper(simb)<<"\n";
    else
      std::cout<<simb;
    std::cin.get(simb);
    std::cin.ignore();
  }



    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
