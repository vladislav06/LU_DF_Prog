//
// Created by Vladislavs Agarkovs on 20.05.2023.
//
// APTS 2

/*
 * brief algo:
 * open file
 * parse two arrays:
 *      array with players/ vertices(id)
 *      array with who invited who/ paths (from id, to id)
 * combine two arrays to create tree:
 *      get one path, find two vertices, set child address in parent vertex
 * find root(vertex whose address isn't assigned to any other vertex)
 *
 * go through each node in the tree and add it id to stack at node depth position in the array:
 *    1
 *   /  \
 *  /    \
 *  2    3
 * / \  / \
 * 4 5 6  7
 *
 *  [0] [1] [2]
 *   1   2   4
 *       3   5
 *           6
 *           7
 *
 * then just save to file
 *
 *  2: 4 5 6 7
 *  1: 2 3
 *  0: 1
 *
 */


#include <fstream>


//#define DEBUG

#ifdef  DEBUG
#include <iostream>
#endif

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

Node *read(fstream &fin);

void write(ostream &fout, Node *root);

int fillVectorStack(Vector<Stack<int>> &layers, Node *root, int depth);


int main() {
    //read
    fstream fin("team.in", ios::in);
    Node *root = read(fin);

    //write
    ofstream fout("team.out", ios::out);
#ifdef  DEBUG
    write(cout, root);
#else
    write(fout, root);
#endif
    return 0;
}

/**
 * open file.\n
 * parse two arrays:\n
 *    *  array with players/ vertices(id)\n
 *    *  array with who invited who/ paths (from id, to id)\n
 * combine two arrays to create tree:\n
 *    *  get one path, find two vertices, set child address in parent vertex\n
 * find root(vertex whose address isn't assigned to any other vertex)\n
 */
Node *read(fstream &fin) {
    //Participant Woman Man

    //create arrays
    Vector<Node *> nodes;
    int nodeCount = 0;

    struct Pair {
        int parent;
        int child;
        bool man;
    };

    Vector<Pair *> pairs;
    int pairCount = 0;




    //fill them
    while (fin) {
        //get one parent node
        Node *node = new Node();
        fin >> node->id;
        nodes[nodeCount] = node;
        nodeCount++;

        //get two connections to child nodes,first will be woman, and second will be man
        int childId;
        fin >> childId;
        if (childId != 0) {
            Pair *pair = new Pair();
            pair->parent = node->id;
            pair->child = childId;
            pair->man = false;
            pairs[pairCount] = pair;
            pairCount++;
        }

        fin >> childId;
        if (childId != 0) {
            Pair *pair = new Pair();
            pair->parent = node->id;
            pair->child = childId;
            pair->man = true;
            pairs[pairCount] = pair;
            pairCount++;
        }
    }

    //create tree
    for (int i = 0; i < pairCount; i++) {
        Pair *pair = pairs[i];
        //find parent and child
        Node *parent;
        Node *child;

        for (int j = 0; j < nodeCount; j++) {
            Node *node = nodes[j];
            if (node->id == pair->parent) {
                parent = node;
            } else if (node->id == pair->child) {
                child = node;
            }
        }
        if (pair->man) {
            parent->man = child;
        } else {
            parent->woman = child;
        }
    }

    //find root
    // if node isn't child for any other node, then it is the root

    for (int i = 0; i < nodeCount; i++) {
        Node *node = nodes[i];
        bool hasNoParents = true;

        for (int j = 0; j < pairCount; ++j) {
            Pair *pair = pairs[j];
            if (pair->child == node->id)
                hasNoParents = false;
        }

        if (hasNoParents) {
            return node;
        }
    }
    return nullptr;

    //   return root;
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
    int depth = fillVectorStack(layers, root, 1) - 2;

    //fill file
    for (int i = depth; i >= 0; i--) {
        fout << i << ":";
        for (int id = layers[i].pop(); id != -1; id = layers[i].pop()) {
            if (id == 0)
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
