#AuP_La0201.Izveidot C++ programmu,kura pārvērš Fārenheita grādos uzdotu temperatūru par temperatūru Celsija grādos
#C = 5 / 9(F - 32)
#Jābūt iespējai programmu izpildīt atkārtoti, neizejot no programmas.
#Autors : Vladislavs Agarkovs
#Veidots : 13.09.2022

while True :
    farh = float(input('enter Farenheit temperature: '))
    cels = 5 / 9 * (farh - 32)
    print('temperature in celsius is:', cels)
