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
#include <cstring>

using namespace std;


struct Record {
    int id = 0;
    char name[31] = "";
};

void putInMap(ifstream &in, map<int, Record *> &records);

void putInFileById(ofstream &out, map<int, Record *> &records);

void putInFileByName(ofstream &out, map<int, Record *> &records);

int main() {

    cout << strcmp("a", "b") << endl;
    cout << strcmp("b", "a") << endl;
    cout << strcmp("a", "aa") << endl;
    cout << strcmp("bb", "aa") << endl;


    ifstream in("f.bin", ios::in | ios::binary);

    map<int, Record *> records;
    putInMap(in, records);

    for (const auto &record: records) {
        std::cout << record.first << " " << record.second->id << " " << record.second->name << "\n";
    }

    ofstream out1("foutByID.bin", ios::out | ios::binary);
    putInFileById(out1, records);
    out1.close();

    ofstream out2("foutByName.bin", ios::out | ios::binary);
    putInFileByName(out2, records);
    out2.close();


    return 0;
}


void putInMap(ifstream &in, map<int, Record *> &records) {
    while (in) {
        auto *rec = new Record();
        in.read((char *) rec, (sizeof(Record)));
        if (records.find(rec->id) == records.end()) {
            records[rec->id] = rec;
        }
    }
}

void putInFileById(ofstream &out, map<int, Record *> &records) {
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
        out.write((char *) records[k], sizeof(Record));
    }
}

void putInFileByName(ofstream &out, map<int, Record *> &records) {
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
        out.write((char *) records[k], sizeof(Record));
    }
}


