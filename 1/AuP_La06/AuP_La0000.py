 
#AuP_La0201.Izveidot C++ programmu,kura pārvērš Fārenheita grādos uzdotu temperatūru par temperatūru Celsija grādos
#C = 5 / 9(F - 32)
#Jābūt iespējai programmu izpildīt atkārtoti, neizejot no programmas.

#Autors : Vladislavs Agarkovs
#Veidots : 13.09.2022

def lielakais(a,b):
    if a > b:
        return a
    else:
        return b

while True:
   
    print("Ievadiet elementu virkni ")
    try:
        max = int(input())
        while True:
            n = int(input())
            max = lielakais(max,n)
          
    # if the input is not-integer, just print the list
    except:
        print("maksimalais skaitlis ir",max)
    
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
