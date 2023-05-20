/******************************************************************************************************
AuPLa1401. Izveidot C++ klasi darray, izmantojot objektorientētās programmēšanas līdzekļus un strukturējot programmu vismaz trīs failos. Klases hederi obligāti novietot atsevišķā hedera failā (darray.h). Visas metodes realizēt ārpus hedera faila – speciālā C++ failā (darray.cpp). Funkcija main ievietojama vēl citā C++ failā (main.cpp). Klases dati pēc noklusēšanas ir slēpti (private), bet metodes atklātas (public).
Klase darray attēlo dinamisku veselu skaitļu masīvu ar n elementiem.
Jārealizē metodes:
konstruktors,
kopijas konstruktors,
destruktors,
array_avg() - aprēķina masīva elementu vidējo vērtību un atgriež to,
print_array()) – izdrukā masīvu.
Masīva elementu aizpildīšanai realizēt privātu metodi fill_array().

Izveidot klasi darray pārbaudošu programmu, kurā tiek izveidoti divi klases objekti – automātiskā (tiešā) veidā un dinamiski un objektiem tiek pielietotas metodes.
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022


#include <iostream>
#include "darray.cpp"
int main() {

  int ok;

  do
  {
    Darray darray(5);
   std::cout<<"avg:"<< darray.array_avg()<<"\n";
    darray.print_array();
  } while (ok == 1);

  return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
