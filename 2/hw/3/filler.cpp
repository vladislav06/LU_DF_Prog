//
// Created by vm on 23.15.5.
//

#include <fstream>
#include <cstring>
#include <iostream>

struct Record {
    int id = 0;
    char name[31] = "";
};

using namespace std;

void save(int id, char name[31], ofstream &out);

void loadAndPrint(ifstream &in);

int main() {

    ofstream out("f.bin", ios::out | ios::binary);
    save(4, (char *) "ab", out);
    save(1, (char *) "a", out);
    save(3, (char *) "bb", out);
    save(2, (char *) "aa", out);


    save(5, (char *) "ac", out);
    save(0, (char *) "b", out);

    out.flush();
    out.close();

    ifstream in("f.bin", ios::in | ios::binary);
    loadAndPrint(in);
    in.close();

    return 0;
}


void save(int id, char name[31], ofstream &out) {
    Record *rec = new Record();
    rec->id = id;

    strcpy(rec->name, name);

    out.write((char *) (rec), sizeof(Record));
}


void loadAndPrint(ifstream &in) {
    while (in) {
        auto *rec = new Record();
        in.read((char *) rec, (sizeof(Record)));
        cout << "id: " << rec->id << ": " << rec->name << endl;
    }
}