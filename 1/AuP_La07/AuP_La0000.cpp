/******************************************************************************************************
basic prog
*___________*
_*_________*_

*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include <iostream>

int main() {

  int ok;
  int n;
  do {
    std::cin >> n;


    for (int i = 0; i < n; i++) {
      int l = i % 14;

      for (int j = 0; j < n; j++) {

        int k = j % 14;

        if ((k - l) == 0) {
          std::cout << "*";
        } else if (12-(k + l) == 0) {
          std::cout << "*";
        } else {
          std::cout << "_";
        }
      }
      std::cout << "\n";
    }

    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
