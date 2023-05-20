#include "darray.h"
#include "iostream"

Darray::Darray(int n) {
  arr = new int[n];
  this->n = n;
  fill_array();
}

Darray::Darray(Darray *darray) { this->arr = darray->arr; }

Darray::~Darray() { delete[] arr; }

float Darray::array_avg() {
  float sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }

  return sum / n;
}

void Darray::print_array() {
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << ", ";
  }
  std::cout << std::endl;
}

void Darray::fill_array() {
  for (int i = 0; i < n; i++) {
    std::cout << "Ievadiet " << i << " vērtību: ";
    int j;
    std::cin >> j;
    arr[i] = j;
  }
}
