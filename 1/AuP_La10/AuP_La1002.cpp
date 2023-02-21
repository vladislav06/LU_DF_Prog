/******************************************************************************************************
basic prog
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include <iostream>
#include <vector>

std::vector<int> getVector() {
  std::vector<int> vec;
  std::cout << "Ievadiet naturālos skaitļus, ievadīšana beigas ar -1:\n";

  while (true) {
    int n;
    std::cin >> n;
    if (n < 0)
      break;
    vec.push_back(n);
  }
  return vec;
}

std::vector<int> slieks(std::vector<int> &vec, int min) {
  std::vector<int> vec2;
  for (int i = 0; i < vec.size(); i++) {
      int n = vec[i];
      if(n > min)
        vec2.push_back(n);
  }
  return vec2;
}

int main() {

  int ok;

  do {
    std::vector<int> v = getVector();
    std::vector<int> v2 = slieks(v, 17);

    std::cout<<"v2: ";
    for (int i = 0; i < v2.size(); i++) {
      std::cout<<v2[i]<<", ";
    }
    std::cout<<"/n";

    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
