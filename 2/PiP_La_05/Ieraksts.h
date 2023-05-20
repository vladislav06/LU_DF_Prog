#pragma once

#include <string>

class Ieraksts {
public:
    union {
        char data[24+4+4+3+21+4];
        struct {
            char nosaukums[24];
            int izdeumaVeids;
            int iznaksanasBiezums;
            char valoda[3];
            char izdevejs[21];
            int izdevumaIndeks;
        };
    };

    Ieraksts();

    void setNosaukums(std::string nosaukums);
};
