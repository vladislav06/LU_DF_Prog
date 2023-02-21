/******************************************************************************************************
basic prog
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

int main() {

  int ok;

  std::vector<int> vec = {1,  45, 23, 89, 45, 12, 56, 79, 45,   46,    45, 56,
                          12, 23, 89, 78, 46, 79, 6,  19, 0515, 15004, 15};

  do {
    int n=-1;
    std::cin>>n;


    auto it = std::find(vec.begin(), vec.end(), n);

    if (it != vec.end())
      std::cout << "Element found in myvector: " << *it << '\n';
    else
      std::cout << "Element not found in myvector\n";


    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
