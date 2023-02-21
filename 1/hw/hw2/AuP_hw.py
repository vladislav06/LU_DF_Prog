# Dots naturāls skaitlis m un naturāls skaitlis n=2..16. Izdrukāt skaitli m skaitīšanas sistēmā ar bāzi n.

# Autors : Vladislavs Agarkovs
# Veidots : 29.10.2022

digits = "0123456789ABCDEF"


def toBaseN(num, n):
    i = 0
    result = ""
    while num > 0:
        result += digits[num % n]
        num = num // n
    return result

def reversePrint(s):
    for i in range(len(s)-1,-1,-1):
        print(s[i],end = "")


while True:
    n = 0
    m = 0

    while True:
        m = int(input("Ievadiet naturālo skaitli m:"))
        if m > 0:
            break

    while True:
        n = int(
            input("Ievadiet naturālo skaitli n kuram vajag būt no 2 līdz 16 ieskaitot: "))
        if 2 <= n and n <= 16:
            break
    # konvertēšana
    answer = toBaseN(m, n)

    # Izvads
    print("skaitlis", m, "skaitīšanas sistēmā ar bāzi", n, "ir: ", end='')
    reversePrint(answer)
    print("")

    ok = int(input("Vai turpināt (1) vai beigt (0)?\n"))
    if ok == 0:
        break


######################## Testu plāns ########################
#       m            n           izeja
#      123           7            234
#       10           2           1010
#       10           7             13
#      255          16             FF
#       -1                         Ievadiet naturālo skaitli m:
#       1           -1             Ievadiet naturālo skaitli n kuram vajag būt no 2 līdz 16 ieskaitot
#############################################################
