/******************************************************************************************************
Izveidot C++ funkciju burti, kas no dotās teksta rindiņas izveido jaunu rindiņu,
liekot jaunajā teksta rindiņā tikai dotās rindiņas latīņu alfabēta burtus.
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include <iostream>
#include <string.h>

using namespace std;

void burti(char *rind, char *jrind) {
  int j = 0;
  for (int i = 0; rind[i] != '\0'; i++) {
    // if rind[i] is alphabetic char, then copy it to jrind
    if (('A' <= rind[i] && rind[i] <= 'Z') ||
        ('a' <= rind[i] && rind[i] <= 'z')) {
      jrind[j] = rind[i];
      j++;
    }
  }
}

string burti(string rind) {
  string jrind;
  for (int i = 0; i < rind.size(); i++) {
    if (('A' <= rind[i] && rind[i] <= 'Z') ||
        ('a' <= rind[i] && rind[i] <= 'z')) {
      jrind.push_back(rind[i]);
    }
  }
  return jrind;
}

int main() {

  int ok;

  do {
//     char *rind = (char *)"f854jr943k*/23*sdf498ds984sdsd4ds83wSDFWE*954SDF";
//
//     char *jrind = new char[strlen(rind) + 1];
//     jrind[strlen(rind) + 1] = '\0';
//
//     burti(rind, jrind);L
//
    char *rind = new char[100];
    char * jrind = new char[100];
    cout<<"Ievadiet rindi: \n";
    cin.getline(rind,101);


//    string rind = "aAf854jr943k*/23*sdf498ds984sdsd4ds83wSDFWE*954SDzZF";
    burti(rind,jrind);

    cout << jrind << endl;

    delete[] rind;
    delete[] jrind;

    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
