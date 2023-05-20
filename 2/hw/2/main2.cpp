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

#include <list>
#include <iostream>

using namespace std;


/// print(list);
/// izvada visus list elementus
template<typename T>
void print(list<T> &list);

/// secondGreatestToEnd(list)
/// funkcija kas atrod list
/// otro lielāko elementu,
/// ja tāds eksistē un pārvieto to uz saraksta beigām.
template<typename T>
void secondGreatestToEnd(list<T> &list);


int main() {

    list<int> l = {3,1,2,4};
    //  [4,2,1,-1,-2,3]

    print(l);
    secondGreatestToEnd(l);
    print(l);

    return 0;
}


template<typename T>
void secondGreatestToEnd(list<T> &arr) {

    //find largest elements
    auto larg = arr.begin();

    for (auto it = arr.begin(); it != arr.end(); ++it) {
        if (*it > *larg) {
            larg = it;
        }
    }
    cout << "largest: " << *larg << endl;

    //find second largest elements
    auto secLarg = arr.begin();


    //check if first element is largest
    if (arr.begin() == larg) {
        secLarg = arr.begin();
        ++secLarg;
    }

    for (auto it = arr.begin(); it != arr.end(); ++it) {
        if (*it > *secLarg && *it < *larg) {
            secLarg = it;
        }
    }

    if(*secLarg == *larg){
        cout << "second largest does not exist\n";
        return;
    }

    cout << "second largest: " << *secLarg << endl;

    //move secLargest to the end
    arr.splice( arr.end(), arr, secLarg );
}

template<typename T>
void print(list<T> &arr) {
    cout << "[";
    auto it = arr.begin();
    for (; it != --arr.end(); ++it) {
        cout << *it << ", ";
    }
    cout << *it << "]\n";
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
