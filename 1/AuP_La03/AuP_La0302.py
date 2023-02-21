#Sastādīt Python programmu, kas dotam mēneša kārtas numuram (1, 2, ..., 12) nosaka #piederību gadalaikam. Ziemas mēneši: 1, 2, 12; pavasara mēneši: 3, 4, 5; vasaras #mēneši: 6, 7, 8; rudens mēneši: 8, 10, 11.
#Mēneša piederības gadalaikam noteikšanai lietot zarošanās priekšrakstu.
#Jābūt iespējai programmu izpildīt atkārtoti, neizejot no programmas.

#Autors : Vladislavs Agarkovs
#Veidots : 13.09.2022

while True :
  month = int(input("Ievadiet meneša kārtas numuru: "))

  if month < 1 or month > 12:
    print("Ievadiet pareizo menes numuru!")
    continue

  if month == 1 or month == 2 or month == 12:
    print("Tas ir ziemas mēnesis")
  elif month >=3 and month <= 5:
    print("Tas ir pavasaras mēnesis")
  elif month >= 6 and month <= 8:
    print("Tas ir vasaras mēnesis")
  elif month >= 9 and month <= 10:
    print("Tas ir rudens mēnesis")

  ok = int(input("Vai turpināt (1) vai beigt (0)?\n"))
  if ok == 0:
    break;

######################## Testu plāns ########################
#      ievads    izvads
#         1      ziema
#         5      pavasara
#         7      vasara
#         10     rudens
#############################################################
