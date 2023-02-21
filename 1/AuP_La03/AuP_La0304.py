#Sastādīt Python programmu, kas pieprasa ievadīt N veselus skaitļus un nosaka lielākā skaitļa vērtību.
#Jābūt iespējai programmu izpildīt atkārtoti, neizejot no programmas.

#Autors : Vladislavs Agarkovs
#Veidots : 13.09.2022

while True:
    while True:
        try:
            n = int(input("Ievadiet positivo skaitļu skaitu: "))
        except ValueError:
            continue
        if n > 0:
            break
    i = 1
    max = 0
    while i <= n:
        print("Ievadiet ",i," skaitli: ")
        num = int(input())
        if num == 0:
            break;
        if num > max:
            max = num
        i +=1
    print("Lielakais numurs ir: ",max)
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
