/***********************************************
 * Dots veselu skaitļu masīvs A(n,n). Noskaidrot, vai tas ir latīņu kvadrāts.
 * n-kārtas latīņu kvadrāts ir tāda kvadrātiska matrica,
 * kuras katra rinda un katra kolonna satur visus skaitļus no 1 līdz n.
 *********************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 16.11.2022

#include <iostream>

using namespace std;

/*
 * int* getMatrix(int &size)
 * Dabuj matricu no lietotāja un atrgriež radītāju uz dabūto matricu
 * pirmā argumenta ieraksta matricas izmēru
 */
int *getMatrix(int &size) {
    int n;
    cout << "Ievadiet kvadratiskas matricas izmēru: ";
    cin >> n;
    size = n;
    int *matrix = new int[n * n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int element;
            cout << "Ievadiet " << i << " rindas " << j << " elementu: ";
            cin >> element;
            matrix[j + (i * size)] = element;
        }
    }
    return matrix;
}

/*
 * bool irLatinKvadrats(int *matrix,int size)
 * parbauda vai iedota matrica ir latīņu kvadrāts
 * matrix ir norādītajs uz matricu
 * size ir matricas izmērs
 */
bool irLatinKvadrats(int *matrix, int size) {
    // parbāudīt vai matrica ir n-kārtas latīņu kvadrāts

    // parbudīt rindas
    for (int x = 0; x < size; x++) {
        // search number in row
        for (int n = 1; n <= size; n++) {
            int numCounter = 0;
            for (int y = 0; y < size; y++) {
                if (matrix[y + x * size] == n) {
                    numCounter++;
                }
                cout << endl;
            }
            if (numCounter != 1)
                return false;
        }
    }
    // parbaudīt kolonnas
    for (int y = 0; y < size; y++) {
        // search number in colimn
        for (int n = 1; n <= size; n++) {
            int numCounter = 0;
            for (int x = 0; x < size; x++) {
                if (matrix[y + x * size] == n) {
                    numCounter++;
                }
            }
            if (numCounter != 1)
                return false;
        }
    }

    return true;
}

int main() {

    int ok;

    do {
        int *matrix;
        int size;

        matrix = getMatrix(size);
        /*
        int matrix[9] = {
                1, 2, 3,
                2, 3, 1,
                3, 1, 2};
        int size = 3;
        */
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << matrix[j + i * size] << " ";
            }
            cout << endl;
        }

        if (irLatinKvadrats(matrix, size)) {
            cout << "tas ir n-kārtas latīņu kvadrāts!\n";
        } else {
            cout << "tas nav n-kārtas latīņu kvadrāts!\n";
        }

        std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
        std::cin >> ok;
    } while (ok == 1);

    return 0;
}
/***********************  Testu plāns ***********************
       ievads                   izeja
       1 2
       2 1                      tas ir n-kārtas latīņu kvadrāts!

       1 2                      tas nav n-kārtas latīņu kvadrāts!
       1 2

       1 2 3                    tas ir n-kārtas latīņu kvadrāts!
       2 3 1
       3 1 2

*************************************************************/
