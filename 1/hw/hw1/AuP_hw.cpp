/******************************************************************************************************
Doti divi naturāli skaitļi m un n. Noteikt skaitļa m pēdējo n ciparu summu.
Skaitļa dalīšana ciparos jāveic skaitliski.
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs va22017
/// Veidots: 07.10.2022

#include <iostream>
int powOf10(int n);
int getNdigit(int num, int n);
int main() {

  int ok;
  int num;
  int n;
  do {
    // Iegūt vērtības no lietotaja
    do {
      std::cout << "Ievadiet nautralo skaitli: ";
      std::cin >> num;
    } while (num < 0);

    do {
      std::cout << "Ievadiet ciparu skaitu: ";
      std::cin >> n;
    } while (n < 0);

    int sum = 0;
    // summēt n pedejos ciparus
    for (int i = 0; i < n; i++) {
      sum += getNdigit(num, i);
    }

    std::cout << "Skaitļa "<< num <<" pēdējo " << n << " ciparu summa ir " << sum << "\n";

    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}


// num / 10^n
// num %10
int getNdigit(int num, int n) {
  num /= powOf10(n);
  return num % 10;
}

// kapina 10 n pakape
int powOf10(int n) {
  int i = 1;
  while (n > 0) {
    i *= 10;
    n--;
  }
  return i;
}

/***********************  Testu plāns ***********************
       cipars m   cipars n        atbilde
       1234       2               7
       1234       3               9
        123       3               6
    9999999       5              45
          0       0               0
        123       4               6
         -1            Ievadiet nautralo skaitli
          1      -1     Ievadiet ciparu skaitu
*************************************************************/
