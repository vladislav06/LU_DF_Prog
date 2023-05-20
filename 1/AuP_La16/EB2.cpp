/******************************************************************************************************
basic prog
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include <iostream>
#include <string>

using namespace std;

int powOf10(int n) {
  int t = 1;
  while (n > 0) {
    t *= 10;
    n--;
  }
  return t;
}

int numLen(int num) {
  if (num < 0)
    num = -num;
  int len = 1;
  if (num > 0) {
    for (len = 0; num > 0; len++) {
      num = num / 10;
    }
  }
  return len;
}

void vid(int num, int &len, int *dig) {
  int l = numLen(num);

  // 1 digit
  if (l % 2 == 1) {
    len = 1;
    l /= 2;
    num /= powOf10(l);
    dig[0] = num % 10;

  } else {
    // 2 digit
    len = 2;
    l /= 2;
    num /= powOf10(l - 1);
    dig[1] = num % 10;

    num /= 10;
    dig[0] = num % 10;
  }
}

void vidS(int num, int &len, int *dig) {
  string str = to_string(num);
  int l = str.length();

  // 1 digit
  if (l % 2 == 1) {
    len = 1;
    l /= 2;

    dig[0] = str[l] - '0';

  } else {
    // 2 digit
    len = 2;
    l /= 2;
    dig[1] = str[l] - '0';
    dig[0] = str[l - 1] - '0';
  }
}
int main() {

  int ok;

  do {
    int len;
    int arr[2];
    vidS(12345, len, arr);
    cout << arr[0] << " " << arr[1] << " " << len << "\n";

    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
