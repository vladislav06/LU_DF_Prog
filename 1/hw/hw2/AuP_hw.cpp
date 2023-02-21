/******************************************************************************************************
Dots naturāls skaitlis m un naturāls skaitlis n=2..16. Izdrukāt skaitli m skaitīšanas sistēmā ar bāzi n.
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 29.10.2022


#include <iostream>

char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void toBaseN(int num, int n, char *result) {
    int i = 0;
    //konvertēšana no base10 uz baseN
    while (num > 0) {
        result[i] = digits[(num % n)];
        num /= n;
        i++;
    }
}

void reversePrint(char *str) {
    // apreikināt garumu
    int len = 0;
    for (; str[len] != '\0'; len++);

    // izprintēt tekstu sakot no otra gala
    for (; len >= 0; len--) {
        std::cout << str[len];
    }
}

int main() {

    int ok;
    int m, n;
    do {
        do {
            std::cout << "Ievadiet naturālo skaitli m: ";
            std::cin >> m;
        } while (m <= 0);

        do {
            std::cout << "Ievadiet naturālo skaitli n kuram vajag būt no 2 līdz 16 ieskaitot: ";
            std::cin >> n;
        } while (2 > n || n > 16);

        //maksimalais skaitļa garums, jo int tipa skaitļa izmērs ir 32 biti
        char answer[32] = "";

        toBaseN(m, n, answer);

        //izvads
        std::cout << "Skaitlis " << m << " skaitīšanas sistēmā ar bāzi " << n << " ir: ";
        reversePrint(answer);
        std::cout << "\n";

        std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
        std::cin >> ok;
    } while (ok == 1);

    return 0;
}
/***********************  Testu plāns ***********************
       m            n           izeja
      123           7            234
       10           2           1010
       10           7             13
      255          16             FF
       -1                         Ievadiet naturālo skaitli m:
       1           -1             Ievadiet naturālo skaitli n kuram vajag būt no 2 līdz 16 ieskaitot
*************************************************************/
