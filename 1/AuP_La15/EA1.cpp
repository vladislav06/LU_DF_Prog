#include <iostream>
using namespace std;

int pow10(int n) {
  int res = 1;
  while (n > 0) {
    res *= 10;
    n--;
  }
  return res;
}

int getNumLength(int num) {
  int n = 0;
  while (num / pow10(n) >= 9) {
    n++;
  }
  return n ;
}

int main() {
  int skaitlis;
  cout << "Ievadiet skaitli: ";
  cin >> skaitlis;
  // get digits
  int MSD = skaitlis / pow10(getNumLength(skaitlis) );
  cout << MSD << "\n";
  int LSD = skaitlis % 10;
  cout << LSD << "\n";

  // swap
  int mid = skaitlis % pow10(getNumLength(skaitlis));
  cout << mid << "\n";

  int jauns = mid + (LSD * pow10(getNumLength(skaitlis)));
  jauns = (jauns -LSD) + MSD;

  cout << jauns << "\n";

  return 0;
}
