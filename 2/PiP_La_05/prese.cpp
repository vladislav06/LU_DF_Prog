#include "prese.h"
#include <fstream>

list<Ieraksts> *Prese::getIeraksti() { return &ieraksti; }

void Prese::save(ofstream *out){
    for(Ieraksts ieraksts: ieraksti){
        out->write(ieraksts.data,sizeof ieraksts.data);
    }

}
