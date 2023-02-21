/******************************************************************************************************
basic prog
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022


#include <iostream>

int vertskaits(int a[], int n, int s) {
    int skaits = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == s)
            skaits++;
    }
    return skaits;
}

int vertskaits(float a[], int n, float s) {
    int skaits = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == s)
            skaits++;
    }
    return skaits;
}


int main() {

    int ok;

    do {

        int a[] = {1,2,3,4,5,62,3,5,2354,23,3,33,};
        std::cout<<vertskaits(a,sizeof(a),3);
        std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
        std::cin >> ok;
    } while (ok == 1);

    return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
