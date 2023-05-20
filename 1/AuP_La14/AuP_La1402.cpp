/******************************************************************************************************
basic prog
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include <iostream>




void findMostRepeating(const char *arr, int &repeats, char &character) {
  char chars[255];
    for (int i = 0; i < 255; i++) {
      chars[i] = 0;
    }

  for (int i = 0; arr[i] != '\0'; i++) {
    chars[arr[i]] += 1;
  }

  char maxChar = 0;
  int maxRepeats = 0;

  for (int i = 0; i < 255; i++) {
    if (chars[i] > maxRepeats) {
      maxRepeats = chars[i];
      maxChar = i;
    }
  }
  repeats = maxRepeats;
  character = maxChar;
}

int main() {

  int ok;

  do {
    char* arr = (char*)"abcabc";
     char characte = 0;
    int repeats = 0;

    findMostRepeating(arr,repeats,characte);
    std::cout<<"characte:"<<characte<<"\n";
    std::cout<<"repeats:"<<repeats<<"\n";

    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}

/***********************  Testu plāns ***********************
       output asd
*************************************************************/
