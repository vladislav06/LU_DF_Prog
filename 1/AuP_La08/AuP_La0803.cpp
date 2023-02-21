/******************************************************************************************************
Sastādīt Python programmu, kas ļauj noskaidrot, cik reizes teksta rindiņā ir sastopams konkrēts simbols. Gan teksta rindiņu, gan simbolu ievada lietotājs.
Jābūt iespējai programmu izpildīt atkārtoti, neizejot no programmas.
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022


#include <iostream>

int main() {

  int ok;

  do
  {
    std::string str;
    char simb;

    std::cout << "Ievadiet simbolu virkni, līdz 100 simboliem:\n";
    getline(std::cin,str);

    std::cout << "Ievadiet meklējamo simbolu: ";
    std::cin.get(simb);

    int count = 0;
    int pos = -1;
    do{
      pos = str.find(simb,pos+1);
      count++;
    }while(pos != -1);
    // Noņemam vienu, jo do while dara vienu lieko atkartojumu
    count--;


    std::cout << "Simbols sastopas " << count << " reizes\n";



    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
    std::cin.ignore();// Ignore \n
  } while (ok == 1);

  return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
