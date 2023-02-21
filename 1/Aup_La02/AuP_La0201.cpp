/******************************************************************************************************
AuP_La0201. Izveidot C++ programmu, kura pārvērš Fārenheita grādos uzdotu temperatūru par temperatūru Celsija grādos
C = 5/9(F-32)
Jābūt iespējai programmu izpildīt atkārtoti, neizejot no programmas.
*******************************************************************************************************/
/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include <iostream>

int main(){
    while(true){
        //get temperaturne in fahrenheit

        std::cout<<"enter Farenheit temperature \n";
        float farh = 0;
        std::cin>>farh;

        //convert to celsius
        float cels = 5./9.*(farh-32);

        //print result
        std::cout<<"temperature in celsius is: "<<cels<<"\n";
    }

    return 0;
}

/***********************  Testu plāns ***********************
        F grādi         C grādi
       32                  0
        0                -17.7
       97.8               36.6
*************************************************************/
