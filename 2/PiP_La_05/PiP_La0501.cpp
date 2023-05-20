/******************************************************************************************************
basic prog
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022
#include "Ieraksts.h"
#include "prese.h"
#include <iostream>

using namespace std;

int main() {
  Prese prese;
  int ok;

  do {
    Ieraksts ier{};

   ier.setNosaukums("school");
    prese.getIeraksti()->push_back(ier);
    ofstream  fout= ofstream("out.bin",ios::binary);
    prese.save(&fout);
    fout.close();

    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
