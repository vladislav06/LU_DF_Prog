/******************************************************************************************************
 Sastādīt C++ programmu, kas pieprasa ievadīt N veselus skaitļus un nosaka, vai skaitļi veido stingri augošu virkni.
Jābūt iespējai programmu izpildīt atkārtoti, neizejot no programmas.
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 27.09.2022


#include <iostream>

int main() {

  int ok;
  int n;
  int num;
  int lastNum = INT32_MIN;
  bool augoša;
  do
  {

    do {
      std::cout << "Ievadiet veseslo skaitļu skaitu: ";
      std::cin >> n;
    } while (n <= 0);

    augoša = true;

    std::cout << "Ievadiet 1 skaitli: ";
      std::cin >> lastNum;

    for (int i = 2; i <= n; i++) {
      std::cout << "Ievadiet " << i << " skaitli: ";
      std::cin >> num;
      if (num > lastNum)
        lastNum = num;
      else{
        augoša = false;
        break;
      }
    }

    if(!augoša){
      std::cout << "Skaitli neveido stingri augošo secību! \n";
    } else {
      std::cout << "Skaitli veido stingri augošo secību!\n";
    }

    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
