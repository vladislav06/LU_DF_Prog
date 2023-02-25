/******************************************************************************************************
Izveidot programmu valodā C++, kas apstrādā teksta failu secīgā režīmā. Dati no
faila jānolasa pa vienai rindiņai. Nedrīkst dublēt visa faila saturu operatīvajā
atmiņā. Sīkākas prasības sk. Laboratorijas darbu noteikumos.

F17. Dots netukšs teksta fails. Uzrakstīt procedūru, kura izveido failu, kurā
katras dotā faila rindas sākumā ir pierakstīts tās numurs (tam paredzēt 4
simbolus rindas sākumā). Saskaitīt simbolu, vārdu un rindiņu skaitu failā. Par
vārdu uzskatīt patvaļīgu simbolu virkni, kas atdalīta ar tukšumiem vai pieturas
zīmēm (punkts, komats, apaļās iekavas, izsaukuma zīme, jautājuma zīme).
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 25.02.2023

#include <cctype>
#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;

// numberFile(&fileInput, outputFileName);
// Izveido jauno failu ar nosaukumu foutName
// un kopē failu no failu stream pointera fin pierakstot rindas nummuru
void numberFile(fstream *fin, string foutName);



// isSymbol(c)
// Funkcija parbauda vai dotais simbols nav tukšs vai pietura simbols
bool isSymbol(char c){
  return isprint(c)&&!ispunct(c)&&!isspace(c);

}

int main() {

  fstream fin;
  char simb;
  string line;
  int len = 0;
  int lineN = 0;
  int wordN = 0;
  int ok;

  do {

    fin.open("file.txt", ios::in);

    if (!fin) {
      cout << "Nav faila!" << endl;
      return 13;
    }

    //copy file  fin and ann line number to each  line beginign
    numberFile(&fin, "output.txt");

    // goto begining
    fin.clear();
    fin.seekg(0, ios::beg);

    while (fin) {
      getline(fin, line);
      lineN++;

      //symbol counter
      len += line.length();

      //word counter
      //find first letter or number, +1 to wordN, then fast forward to the next non letter or number

      for (int i = 0; i < line.length(); i++) {
        if (isSymbol(line[i])) {
          wordN++;
          while (isSymbol(line[i]))
            i++;
        }
      }
    }
    fin.close();

    //cuz last \n counts as new line, but actualy isnt
    lineN--;

    cout << "Simbolu skaits: " << len << endl;
    cout << "Vārdu skaits: " << wordN << endl;
    cout << "Rindiņu skaits: " << lineN << endl;

    cout << "Vai turpināt (1) vai beigt (0)?" << endl;
    cin >> ok;
  } while (ok == 1);

  return 0;
}

// numberFile(&fileInput, outputFileName);
// Izveido jauno failu ar nosaukumu foutName
// un kopē failu no failu stream pointera fin pierakstot rindas nummuru
void numberFile(fstream *fin, string foutName) {

  fstream fout;
  string line;
  char out[6];
  int lineN = 1;

  fout.open(foutName, ios::out);

  while (*fin) {
    getline(*fin, line);
    sprintf(out, "%4d ", lineN);
    fout << out << line << endl;
    lineN++;
  }
  fout.close();
}

/***********************  Testu plāns ***********************
       ievads              Programmas vēlamā reakcija                     Rezultāts C++

q qq qqq qqqqqq           Simbolu skaits: 44                             Simbolu skaits: 44
qqqq q q, q, q            Vārdu skaits:   12                             Vārdu skaits:   12
(qq)qq234 23sfd           Rindiņu skaits: 3                              Rindiņu skaits: 3


a,f,tert,e3456%           Simbolu skaits: 45                             Simbolu skaits: 44
qe"qe[qe{qe]qe}           Vārdu skaits:   12                             Vārdu skaits:   12
qe,qe.qe/qe;qe'           Rindiņu skaits: 3                              Rindiņu skaits: 3

*************************************************************/
