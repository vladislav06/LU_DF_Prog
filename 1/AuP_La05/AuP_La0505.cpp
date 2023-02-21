/******************************************************************************************************
basic prog
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include <iostream>

int bigger(int a, int b);
int main() {

  int ok;
  int max;
  int n;
  int num;
  do {

    do {
      std::cout << "Ievadiet veselo skaitļu skaitu: ";
      std::cin >> n;
    } while (n <= 0);

    for (int i = 1; i <= n; i++) {
      std::cout << "Ievadiet " << i << " skaitli: ";
      std::cin >> num;
     max = bigger(max, num);
      }

    std::cout<<"max: "<<max<<"\n";

    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}

int bigger(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
