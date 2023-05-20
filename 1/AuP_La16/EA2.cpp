/******************************************************************************************************
basic prog
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include <iostream>
using namespace std;
int main() {

  int ok;

  do {

    int n;
    cout << "Ievadiet virknes garumu: ";
    cin >> n;

    int *arr = new int[n];

    // get
    for (int i = 0; i < n; i++) {
      cout << "Ievadiet " << i << " elementu: ";
      cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
      cout << arr[i] << ", ";
    }

    // swap
    for (int i = 0; i < n / 2; i++) {
      int tmp;
      tmp = arr[i];
      arr[i] = arr[n - i - 1];
      arr[n - i - 1] = tmp;
    }

    // print
    cout << "Invertēts masīvs:\n";
    for (int i = 0; i < n; i++) {
      cout << arr[i] << ", ";
    }
    cout << "\n";

    delete[] arr;

    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
