//
// Created by Vladislavs Agarkovs on 23.20.5.
//
// apts 2
// This algo will use binary tree traversing to get ordered list of players and their trust levels
//
//
#include <fstream>
#include <iostream>
using namespace std;

template<typename T>
class Stack {
    T *stack;
    int stackLen = 0;
    int end = 0;
public:
    Stack() {
        stack = new T[10];
        stackLen = 10;
    }

    ~Stack() {
        delete[] stack;
    }

    void push(T n) {
        if (end >= stackLen) {
            allocate((stackLen * 2));
        }
        stack[end] = n;
        end++;
    }

    T pop() {
        if (end == 0) {
            return -1;
        }
        T n = stack[end - 1];
        end--;
        return n;
    }

private:
    void allocate(int len) {
        T *newStack = new T[len];
        //copy from old to new
        for (int i = 0; i < stackLen; i++) {
            newStack[i] = stack[i];
        }

        delete stack;
        stack = newStack;
        stackLen = len;
    }

};


template<typename T>
class Vector {
    T *arr;
    int len;

public:
    Vector() {
        arr = new T[10];
        len = 10;
    }

    ~Vector() {
        delete[] arr;
    }

    T &operator[](int n) {
        if (n >= len) {
            allocate((n) * 2);
        }
        return arr[n];
    }


private:
    void allocate(int newLen) {
        T *newArr = new T[newLen];
        //copy from old to new
        for (int i = 0; i < len; i++) {
            newArr[i] = arr[i];
        }

        delete arr;
        arr = newArr;
        len = newLen;
    }

};


struct Node {
    Node *woman = nullptr;
    Node *man = nullptr;
    int id = 0;
};

Node *find(Node *root, int id);

Node *read(fstream &fin);

void write(ostream &fout, Node *root);

int fillVectorStack(Vector<Stack<int>> &layers, Node *root, int depth);


int main() {
    //read
    fstream fin("team.in", ios::in);
    Node *root = read(fin);

    //write
    ofstream fout("team.out", ios::out);
    write(fout, root);

    return 0;
}

Node *read(fstream &fin) {
    //read in to binary tree

    //Participant Woman Man

    //first node fill
    Node *root = new Node();
    fin >> root->id;

    Node *woman = new Node();
    fin >> woman->id;
    root->woman = woman;

    Node *man = new Node();
    fin >> man->id;
    root->man = man;


    while (fin) {
        int id;
        fin >> id;

        //skip line
        if (id == 0) {
            fin >> id >> id;
            continue;
        }
        //find
        Node *res = find(root, id);

        if (res == nullptr) {
            continue;
        }
        woman = new Node();
        fin >> woman->id;
        res->woman = woman;

        man = new Node();
        fin >> man->id;
        res->man = man;
    }
    return root;
}


/**
 * go thru each node and put their id at depth place in vector in stack, then get them back
 * @param fout
 * @param root
 */
void write(ostream &fout, Node *root) {

    Vector<Stack<int>> layers;

    layers[0].push(root->id);



    // -3 cuz end elements
    int depth = fillVectorStack(layers, root, 1) - 3;

    //fill file
    for (int i = depth; i >= 0; i--) {
        fout << i << ":";
        for (int id = layers[i].pop(); id != -1; id = layers[i].pop()) {
            if(id ==0)
                continue;
            fout << " " << id;
        }
        fout << endl;
    }
}

int fillVectorStack(Vector<Stack<int>> &layers, Node *root, int depth) {
    if (root == nullptr) {
        return depth;
    }

    int res1 = 0;
    int res2 = 0;
    res1 = fillVectorStack(layers, root->man, depth + 1);

    if (root->man != nullptr) {
        layers[depth].push(root->man->id);
    }

    res2 = fillVectorStack(layers, root->woman, depth + 1);

    if (root->woman != nullptr) {
        layers[depth].push(root->woman->id);
    }
    return res1 > res2 ? res1 : res2;

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