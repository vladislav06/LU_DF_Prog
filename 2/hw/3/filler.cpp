//
// Created by vm on 23.15.5.
//

#include <fstream>
#include <cstring>

struct record {
    int id =0;
    char name[31] = "";
};

using namespace std;

void save(int id, char name[31], ofstream &out);

int main() {

    ofstream out("f", ios::out);

    save(1, (char*)"petya1", out);
    save(2, (char*)"petya2", out);

    save(3, (char*)"petya3", out);

    save(4, (char*)"petya4", out);

    out.flush();
    out.close();

    return 0;
}


void save(int id, char name[31], ofstream &out) {
    record rec{};
    rec.id = id;

    strcpy(rec.name, name);

    out.write((char *)(&rec), sizeof (record));
}
