/******************************************************************************************************
basic prog
*******************************************************************************************************/
/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022


#include <iostream>

int main() {
    int i = 0;
    int sum = 0;
    while(true){
        std::cin>>i;
        if(i<0){
            sum +=i;
        }
        if(i == 0){
            std::cout<<"Negativo skaitlu suma ir: "<<sum;
        }
    }
    return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
