/******************************************************************************************************
basic prog
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include <iostream>

void printPattern(int lenght, int shift);

int main() {

  int ok;
  int n;
  int a = 0;
  do {
    std::cin>>n;

    for (int i=n;i>0;i--){
      printPattern(n,a);
      a--;
      if(a<0)a=2;
      std::cout<<std::endl;
    }


    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}

void printPattern(int lenght, int shift) {
  int symbol = shift;

  while (lenght > 0) {
     lenght--;
    if (symbol == 0) {
      std::cout << "*";
      symbol = 1;
      continue;
    } else if (symbol == 1) {
      std::cout << "_";
      symbol = 2;
      continue;
    } else if (symbol == 2) {
      std::cout << "_";
      symbol = 0;
      continue;
    }
  }
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
