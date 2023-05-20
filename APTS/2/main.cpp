//
// Created by Vladislavs Agarkovs on 23.20.5.
//
// apts 2
// This algo will use binary tree traversing to get ordered list of players and their trust levels
//
//
#include <fstream>

using namespace std;

struct Node {
    Node *woman;
    Node *man;
    int id;
};

Node *find(Node *root, int id);

Node *read(istream fin);

Node *read(istream fin) {
    //read in to binary tree
    //Participant Woman Man
    Node *root = new Node();

    //first will always be a root

    fin>>root->id;

    
    while (fin) {


        int id;
        fin >> id;

        Node *res = find(root, id);

        if (res == nullptr) {

        }

    }
}


Node *find(Node *root, int id) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->id == id) {
        return root;
    } else {
        Node *found = find(root->woman, id);
        if (found == nullptr) {
            found = find(root->man, id);
        }
        return found;
    }
}


int main() {
    //


    return 0;
}