/******************************************************************************************************
Izveidot C++ programmu, kas aprēķina funkcijas f(x) vērtību y.
Funkcija f(x) uzdota ar sakarību:
y ir 0, ja x mazāks par -2;
y ir –x-2, ja x ir robežās no -2 līdz -1;
y ir x, ja x ir robežās no -1 līdz 1(neieskaitot);
y ir –x+2, ja x ir robežās no 1 līdz 2(neieskaitot);
y ir 0, ja x ir lielāks vai vienāds ar 2.
Jābūt iespējai programmu izpildīt atkārtoti, neizejot no programmas.
*******************************************************************************************************/
/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include <iostream>
#include <stdio.h>

float f(float x);
int main() {
  float x = 0;
  float y = 0;

  //calculate and print all values from 3 to -3 with 0.1 increment for y = f(x)
  for (x = -3; x < 3; x += 0.1) {

    //calculate y = f(x) but with x shift to allow negative number representation
    y = f(x) + 3;
    std::printf("% 01.2f", x);

    //print that much spaces that y equals to
    for (int i = 0; i < (y * 30); i++) {
      std::cout << " ";
    }

    std::cout << "*\n";
  }

  while (true) {

    // get x value
    std::cout << "enter x for f(x): ";
    std::cin >> x;

    // calculate f(x)
    y = f(x);
    std::cout << "f(" << x << ") = " << y << "\n";
  }

  return 0;
}

float f(float x) {
  if (x < -2)
    return 0;
  if (x >= -2 && x <= -1)
    return -x - 2;
  if (x >= -1 && x < 1)
    return x;
  if (x >= 1 && x < 2)
    return -x + 2;
  if (x >= 2)
    return 0;
  return 0;
}
/***********************  Testu plāns ***********************
        F grādi         C grādi
       32                  0
        0                -17.7
       97.8               36.6
*************************************************************/
