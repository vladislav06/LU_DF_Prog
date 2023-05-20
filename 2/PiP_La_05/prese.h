#pragma once
#include <fstream>
#include <list>
#include "Ieraksts.h"
using namespace std;

class Prese {
private:
  list<Ieraksts> ieraksti = {};

public:
  list<Ieraksts> *getIeraksti();

  void fill();

  void save(ofstream  *out);
};
