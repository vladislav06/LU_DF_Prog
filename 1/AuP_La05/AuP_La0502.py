 
#AuP_La0201.Izveidot C++ programmu,kura pārvērš Fārenheita grādos uzdotu temperatūru par temperatūru Celsija grādos
#C = 5 / 9(F - 32)
#Jābūt iespējai programmu izpildīt atkārtoti, neizejot no programmas.

#Autors : Vladislavs Agarkovs
#Veidots : 13.09.2022

while True:


    n = (input("Ievadiet naturalo skaitli: "))

    for i in range(0,n):
        for j in range(0,i+1):
            print("*",end="")
        print("")


    ok = int(input("Vai turpināt (1) vai beigt (0)?\n"))
    if ok == 0:
        break

######################## Testu plāns ########################
#
#
#
#
#
#############################################################
