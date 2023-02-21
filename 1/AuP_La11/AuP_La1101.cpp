/******************************************************************************************************
basic prog
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include <iostream>

/**********************
 * int cipliel5(int n)
 * aprēķina naturāla skaitļa n to ciparu summu, kuri ir lielāki par 5
 **********************/
int cipliel5(int n) {
  if (n <= 0)
    return 0;
  //     cipliel5(1234)+ja pēdējais cipars ir lielāks par 5 tad atgriezt to
  //     ciparu
  return cipliel5(n / 10) + (n % 10 > 5 ? n % 10 : 0);
}

int main() {

  int ok;
  int n;
  do {
    std::cout << "Ievadiet naturālo skaitļu: ";
    std::cin >> n;
    std::cout << "cipara " << n << " skaitļu summa kuri ir lielāki par 5 ir:" << cipliel5(n)<< "\n";
    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
