 
#AuP_La0201.Izveidot C++ programmu,kura pārvērš Fārenheita grādos uzdotu temperatūru par temperatūru Celsija grādos
#C = 5 / 9(F - 32)
#Jābūt iespējai programmu izpildīt atkārtoti, neizejot no programmas.

#Autors : Vladislavs Agarkovs
#Veidots : 13.09.2022

# num / 10^n
# num % 10
def getNdigit(num,n):
    # dališana veselos skaitļos
    num = num // (10**n)
    return num % 10


while True:
    # Iegūt vērtības no lietotaja
    while True:
        num = int(input("Ievadiet nautralo skaitli:"))
        if num == 0:
            break
    while True:
        n = int(input("Ievadiet ciparu skaitu:"))
        if n >= 0:
            break
    # summēt n pedejos ciparus
    sum = 0
    for i in range(0,n):
        sum += getNdigit(num,i)

    print("Skaitļa",num,"pēdējo", n, "ciparu summa ir",sum )
    ok = int(input("Vai turpināt (1) vai beigt (0)?\n"))
    if ok == 0:
        break


######################## Testu plāns ########################
#       cipars m   cipars n        atbilde
#       1234       2               7
#              3               9
#        123       3               6
#    9999999       5              45
#          0       0               0
#        123       4               6
#          1      -1     Ievadiet ciparu skaitu
#         -1            Ievadiet nautralo skaitli
#############################################################
