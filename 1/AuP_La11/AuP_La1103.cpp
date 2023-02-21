/******************************************************************************************************
basic prog
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include <iostream>

template <typename T>
int rindliels(T &matr, int n, int m, int r) {
  if (r > n)
    return 0;

  int counter = 0;
  for (int i = 0; i < m; i++) {
    if (matr[r][i] > 17)
      counter++;
  }
  return counter;
}

int main() {

  int ok;
  int matr[4][4] = {
    {1,2,3,4},
    {1,2,3,4},
    {1,20,20,4},
    {1,2,3,4}};
  do {
    std::cout<<rindliels(matr,4,4,2)<<"\n";
    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
