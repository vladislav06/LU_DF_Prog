/******************************************************************************************************
Sastādīt C++ programmu, kas dotam naturālam skaitlim nosaka lielāko ciparu
pierakstā. Risinājuma iegūšanai sastādīt funkciju, kura naturālam skaitlim
nosaka lielāko ciparu pierakstā.
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include <iostream>
#include <math.h>

int getLargestDigit(int number);
int getNthDigit(int number, int n);

int main() {

  int ok;
  int skaitlis = 0;
  do {
    std::cout << "Ievadiet naturalo skaitli: ";
    std::cin >> skaitlis;

    std::cout << "Lielakias cipars ir: " << getLargestDigit(skaitlis) << "\n";

    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}

int getLargestDigit(int number) {
  int lenght = 1;

  while ((number / pow(10, lenght))>1)
  {
    std::cout<<"lenght "<<lenght<<"\n";
    lenght++;
  }
  lenght++;



  int max = 0;

  for (int n = 1; n <= lenght; n++) {
    int digit = getNthDigit(number, n);

    if (digit > max)
      max = digit;
  }

  return max;
}

int getNthDigit(int number, int n) {
  int num = 100;
  std::cout<<"n "<<n<<"\n";
  while (num > 10) {
    num = number / pow(10, n);
    std::cout<< "10^n "<<pow(10, n)<<"\n";
    std::cout << num << "\n";
    n++;
  }
  return number;
}

/***********************  Testu plāns ***********************
       output asd
*************************************************************/
