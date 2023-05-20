//
// Created by vm on 23.15.5.
//
/**
 * Izveidot programmu valodā C++.  Ar faila komponenti tiek saprasts fiksēta garuma ieraksts.
 * Sīkākās prasības sk. Laboratorijas darbu noteikumos.
 *
 * H7. Dots binārs fails f, kura komponentes ir ieraksti ar struktūru: atslēga (int), vārds (nepārsniedz 30 simbolus).
 * Izveidot divus citus bināros failus ar tādu pašu struktūru, kur ieraksti būtu sakārtoti augošā secībā attiecīgi (1) pēc atslēgas, (2) pēc vārda.
 * Abos gadījumos informācijas ielasīšanai un sakārtošanas nodrošināšanai izmantot struktūru STL map.
 * Papildus izveidot palīgprogrammas binārā faila izveidošanai un tā satura izdrukāšanai.
 * Drīkst pieņemt, ka ieraksti ir unikāli gan pēc atslēgas, gan vērtības.
 */

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


struct record {
    int id = 0;
    char name[31] = "";
};

void putInMap(ifstream &in, map<int, record *> &records);

void putInFileById(ofstream &out, map<int, record *> &records);

int main() {

    ifstream in("f", ios::in);

    map<int, record *> records;
    putInMap(in, records);

    for (const auto &record: records) {
        std::cout << record.first << " " << record.second->id << " " << record.second->name << "\n";
    }

    ofstream out("fout", ios::out);
    putInFileById(out, records);


    return 0;
}


void putInMap(ifstream &in, map<int, record *> &records) {
    while (in) {
        auto *rec = new record;
        in.read((char *) rec, (sizeof(record)));
        records[rec->id] = rec;
    }
}

void putInFileById(ofstream &out, map<int, record *> &records) {
    //sort map keys
    vector<int> ids;

    //save keys to vector
    for (auto &record: records) {
        ids.push_back(record.first);
    }

    //sort vector

    sort(ids.begin(), ids.end());

    //write to out file in order that is in vector

    for (int k: ids) {
        out.write((char *) records[k], sizeof(record));
    }
}



