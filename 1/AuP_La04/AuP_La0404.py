 
# Sastādīt Python programmu, kas pieprasa ievadīt N veselus skaitļus
# un nosaka garākās stingri augošas virknes garumu.
# Jābūt iespējai programmu izpildīt atkārtoti, neizejot no programmas.

#Autors : Vladislavs Agarkovs
#Veidots : 27.09.2022

while True:
    #get input from user
    while True:
        try:
            n = int(input("Ievadiet positivo skaitļu skaitu: "))
        except ValueError:
            continue
        if n > 0:
            break


    secGar = 0;
    secLielGar = 0;

    print("Ievadiet 1 skaitli: ")
    lastNum = int(input())
    secGar +=1

    i = 2
    while i <= n:
        print("Ievadiet ",i," skaitli: ")
        num = int(input())
        if num > lastNum:
            lastNum = num
            secGar +=1
        else:
             if secGar > secLielGar:
                 secLielGar = secGar
                 secGar = 0;
        i +=1

    if secGar > secLielGar:
        secLielGar = secGar
        secGar = 0;


    print("Garākās stingri augošas virknes garums ir",secLielGar)


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
