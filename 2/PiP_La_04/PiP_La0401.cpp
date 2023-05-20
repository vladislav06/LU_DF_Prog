/******************************************************************************************************
basic prog
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include "List.cpp"
#include <iostream>
int main() {

  int ok;
  int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  List<int> list;

  for (int i = 0; i < 10; i++) {
    list.push_back(nums[i]);
  }

  for (int i = 0; i < 10; i++) {
    std::cout << list[i] << " | ";
  }
  std::cout << "\n";
  std::cout << 5 << ">>" << list[list.find(10)];

  do {

    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
