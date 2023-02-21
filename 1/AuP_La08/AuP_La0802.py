 
#Sastādīt Python programmu, kas ļauj noskaidrot, cik reizes teksta rindiņā ir sastopams konkrēts simbols.
#Gan teksta rindiņu, gan simbolu ievada lietotājs.
#Jābūt iespējai programmu izpildīt atkārtoti, neizejot no programmas.

#Autors : Vladislavs Agarkovs
#Veidots : 13.09.2022

while True:

    teksts = input("Ievadiet teksta rindu:\n")
    simb = input("Ievadiet meklējamo simbolu:  ")
    count = 0
    for n in teksts:
        if n == simb:
            count+=1

    print("Simbols ir sastopams",count,"reizes")

    ok = int(input("Vai turpināt (1) vai beigt (0)?\n"))
    if k == 0:
        break


######################## Testu plāns ########################
#
#
#
#
#
#############################################################
