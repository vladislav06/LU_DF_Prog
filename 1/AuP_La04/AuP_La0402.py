 
#AuP_La0201.Izveidot C++ programmu,kura pārvērš Fārenheita grādos uzdotu temperatūru par temperatūru Celsija grādos
#C = 5 / 9(F - 32)
#Jābūt iespējai programmu izpildīt atkārtoti, neizejot no programmas.

#Autors : Vladislavs Agarkovs
#Veidots : 13.09.2022

while True:
    #get input from user
    while True:
        try:
            n = int(input("Ievadiet positivo skaitļu skaitu: "))
        except ValueError:
            continue
        if n > 0:
            break
    i = 1
    max = 0
    rising = True
    while i <= n:
        print("Ievadiet ",i," skaitli: ")
        num = int(input())
        if num > max:
            max = num
        else:
            rising = False
        i +=1

    if not rising:
        print("Skaitli neveido stingri augošo secību!")
    else:
        print("Skaitli veido stingri augošo secību!")



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
