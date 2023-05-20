#include <iostream>
using namespace std;

int main() {
  int matr[] = {1, 1, 1, 2, -3, 4};
  int n = 2;
  int m = 3;
  int r = 1;

  r -= 1; // jo masiva numeracija sākas no 0

  int num = matr[n * r]; // r tas rindas pirmais skaitlis
  cout << num << "\n";
  bool vienada = true;

  for (int i = 1; i < m; i++) {
    cout << matr[i + n * r] << "\n";

    if (matr[i + n * r] != num) {
      vienada = false;
      break;
    }
  }
  if (vienada) {
    cout << "Sastāv";
  } else {
    cout << "Nesastāv";
  }
}
