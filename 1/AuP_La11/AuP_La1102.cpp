/******************************************************************************************************
basic prog
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include <iostream>

template <typename T>
T lielakais(T a[], int n) {
  T max = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] > max)
      max = a[i];
  }
  return max;
}

int main() {

  int ok;
  float *mas = new float[] {1,2,3,4,5,6,7,9.01,9};
  do {

    std::cout<<lielakais(mas,9);


    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
