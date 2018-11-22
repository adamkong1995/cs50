from cs50 import get_int
x = get_int("Height: ")
while(x < 0 or x >= 24):
    x = get_int("Height: ")

for i in range(0, x):
    for j in range(0, x - i - 1):
        print(" ", end ="")
    for k in range(0, i + 1):
        print("#", end ="")
    print("  ", end ="")
    for l in range(0, i + 1):
        print("#", end ="")
    print("")