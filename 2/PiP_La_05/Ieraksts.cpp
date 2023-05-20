#include "Ieraksts.h"
#include <iostream>
#include <string.h>


Ieraksts::Ieraksts() {
    strcpy(this->nosaukums, "                       ");
    this->izdeumaVeids = 0;
    this->iznaksanasBiezums = 0;
    strcpy(this->valoda, "  ");
    strcpy(this->izdevejs, "                    ");
    this->izdevumaIndeks = 0;

}


void Ieraksts::setNosaukums(std::string nosaukums) {
    if (nosaukums.length() > 23) {
        std::cout << "nosaukums ir parāk garš";
    }
    strcpy(this->nosaukums, nosaukums.c_str());

}

