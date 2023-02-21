/******************************************************************************************************
Sastādīt C++ programmu, kas pieprasa naturālu skaitli n un izdrukā laukumu n × n no simboliem, kas atbilst šādam rakstam (pie n=7):

*
**
***
****
*****
******
*******
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022


#include <iostream>

int main() {

  int ok;
  int n;
  do
  {
    std::cout<<"Ievadiet naturalu skaitli\n";
    std::cin>>n;

    for(int i = 0; i < n; i++){
      for(int j = 0; j <= i; j++){
        std::cout<<"*";
      }
      std::cout<<"\n";
    }
    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
