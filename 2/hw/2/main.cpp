/*
 * Izveidot divas programmas valodā C++, kas strādā ar vērtību virkni divos dažādos veidos:
 * 1) to realizējot kā vienvirziena saistīto sarakstu, izmantojot dinamiskas datu struktūras,
 * 2) izmantojot STL::list konteineru.
 * Abās realizācijās ir jāizveido prasītā specifiskā vērtību virknes apstrādes funkcija
 * un jānodemonstrē tā darbībā, cita starpā parādot gan sākotnējās, gan rezultējošās
 * vērtības. Saistītā saraksta gadījumā jāuzraksta arī nepieciešamās palīgfunkcijas
 * (piemēram, elementu pievienošanai), kā arī pēc tā izmantošanas korekti jāatbrīvo
 * izdalītā atmiņa.
 *
 * G17. Uzrakstīt funkciju, kas atrod saraksta otro lielāko elementu, ja tāds eksistē un
 * pārvieto to uz saraksta beigām. Darbība jāveic, pārkabinot saites, nevis pārkopējot
 * elementu vērtības.
 */

/// Autors: Vladislavs Agarkovs va22017
/// Veidots: 09.04.2023

#include <iostream>
#include <functional>

using namespace std;


template<typename T>
struct Node {
    T val;
    Node *next;

};

/// addToEnd(head, n);
/// pievieno jauno vērtību pie
/// vienvirziena saistīto saraksta gala
template<typename T>
void addToEnd(Node<T> **head, T newVal);

/// addToEnd(head, newNode);
/// pievieno jauno elementu pie
/// vienvirziena saistīto saraksta gala
template<typename T>
void addToEnd(Node<T> **head, Node<T> *newNode);

/// addToFront(head, n);
/// pievieno jauno elementu pie
/// vienvirziena saistīto saraksta sākuma
template<typename T>
void addToFront(Node<T> **head, T newVal);

/// addAfter(head, n);
/// pievieno jauno elementu pēc
/// vienvirziena saistīto saraksta elementa
template<typename T>
void addAfter(Node<T> **head, T newVal);

/// print(head);
/// izvada visu vienvirziena saistīto sarakstu
template<typename T>
void print(Node<T> **head);

/// removeWhere(head,[](Node<T> *node) -> bool { return (node->val == 0); };
/// iznīcina visus elementus kūriem dota funkcija atgriež true
template<typename T, typename F>
void removeWhere(Node<T> **head, F &&predicate);

/// removeNext(head);
/// iznīcina vienvirziena saistīto saraksta elementu
/// pēc head elementa
template<typename T>
void removeNext(Node<T> **head);

/// removeAll(head);
/// iznīcina visu saistīto sarakstu
template<typename T>
void removeAll(Node<T> **head);

//task

/// secondGreatestToEnd(list)
/// funkcija kas atrod vienvirziena saistīto saraksta
/// otro lielāko elementu,
/// ja tāds eksistē un pārvieto to uz saraksta beigām.
template<typename T>
void secondGreatestToEnd(Node<T> **head);


int main() {



    // []->[]->[][][][][]
    Node<int> **head = new Node<int> *;

    int n;
    for (int i = 0; i < 4; i++) {
        cin >> n;
        addToEnd(head, n);
    }
    print(head);
    secondGreatestToEnd(head);
    print(head);
    removeAll(head);


    return 0;
}

template<typename T>
void secondGreatestToEnd(Node<T> **head) {

    //find largest elements
    Node<T> *tmp = (*head);
    if (tmp == nullptr) {
        cout << "list is empty\n";
        return;
    }
    Node<T> *largest = (*head);
    while (tmp != nullptr) {
        if (tmp->val > largest->val) {
            largest = tmp;
        }
        tmp = tmp->next;
    }

    cout << "largest: " << largest->val << endl;

    //find second largest elements
    tmp = (*head);
    Node<T> *secLargest = (*head);

    if ((*head)->next != nullptr) {
        //check if first element is largest
        if ((*head) == largest) {
            secLargest = (*head)->next;
        }
    }


    while (tmp != nullptr) {
        if (tmp->val > secLargest->val && tmp->val < largest->val) {
            secLargest = tmp;
        }
        tmp = tmp->next;
    }


    if (largest->val == secLargest->val) {
        cout << "second largest does not exist\n";
        return;
    }

    cout << "second largest: " << secLargest->val << endl;

    //move secLargest to the end

    //remove secLargest from list
    // [](int jo) { return jo + 10; }


    removeWhere(head, [secLargest](Node<T> *node) -> bool {
        return (node == secLargest);
    });


    //append it at back
    secLargest->next = nullptr;
    addToEnd(head, secLargest);
}


template<typename T>
void addToEnd(Node<T> **head, T newVal) {

    Node<T> *newNode = new Node<T>;
    newNode->val = newVal;
    addToEnd(head, newNode);
}

template<typename T>
void addToEnd(Node<T> **head, Node<T> *newNode) {
    Node<T> *start = (*head);

    if (start == nullptr) {
        (*head) = newNode;
    } else {
        while (start->next != nullptr)
            start = start->next;
        start->next = newNode;
    }
}

template<typename T>
void addToFront(Node<T> **head, T newVal) {
    Node<T> *newNode = new Node<T>;
    newNode->val = newVal;
    if ((*head) == nullptr) {
        (*head) = newNode;
        return;
    }
    newNode->next = (*head);
    (*head) = newNode;
}

template<typename T>
void addAfter(Node<T> **head, T newVal) {
    Node<T> *newNode = new Node<T>;
    newNode->val = newVal;
    newNode->next = head->next;
    head->next = newNode;
}

template<typename T>
void print(Node<T> **head) {
    Node<T> *start = (*head);

    if (start == nullptr) {
        cout << "[]";
        return;
    }

    cout << "[";
    while (start->next != nullptr) {
        cout << start->val << ", ";
        start = start->next;
    }
    cout << start->val << "]\n";
}

template<typename T, typename F>
void removeWhere(Node<T> **head, F &&predicate) {
    //check first element
    if (predicate((*head))) {
        (*head) = (*head)->next;
    }
    //foreach element
    Node<T> *tmp = (*head);
    if (tmp->next != nullptr) {
        while (tmp->next->next != nullptr) {
            if (predicate((tmp)->next)) {
                (tmp)->next = (tmp)->next->next;
            } else {
                tmp = tmp->next;
            }

        }
    }
    //check last element
    if (predicate(tmp->next)) {
        tmp->next = nullptr;
    }
}


template<typename T>
void removeNext(Node<T> **head) {
    Node<T> *del = (*head)->next;
    (*head)->next = (*head)->next->next;
    delete del;
}

template<typename T>
void removeAll(Node<T> **head) {
    if ((*head) == nullptr) {
        return;
    }
    while ((*head)->next != nullptr) {
        removeNext(head);
    }
    delete *head;
}


/***********************  Testu plāns ***********************
        saistīts saraksts        izvads
        [1, 2, 3]                [1, 3, 2]
        [1, 2, 3, 4]             [1, 2, 4, 3]
        [2, 1, 3]                [1, 3, 2]
        [1, 2, 3]                [1, 3, 2]
        [2, 3, 1]                [3, 1, 2]
        [3, 2, 1]                [3, 1, 2]
*************************************************************/
