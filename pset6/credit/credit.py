from cs50 import get_int

creditCard = get_int("Number: ")
temp = creditCard
header = 0
Sum = 0
checkSum = 0

lenght = len(str(abs(creditCard)))

if lenght % 2 == 0:
    isEven = True
else:
    isEven = False

for i in range(0, lenght):
    temp = creditCard
    creditCard //= 10
    temp %= 10

    if i == lenght - 1:
        header += temp * 10
    elif i == lenght - 2:
        header += temp

    if i % 2 != 0:
        temp *= 2
        while temp != 0:
            checkSum += temp % 10
            temp //= 10
    else:
        Sum += temp

checkSum += Sum
checkSum %= 10
if checkSum == 0 and lenght >= 13 and lenght <= 16:
    if header == 34 or header == 37:
        print("AMEX")
    elif header >= 51 and header <= 55:
        print("MASTERCARD")
    elif header >= 40 and header <= 49:
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")