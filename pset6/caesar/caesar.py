from cs50 import get_string
import sys


def main():
    if len(sys.argv) != 2:
        sys.exit(1)

    num = 0

    key = int(sys.argv[1])

    plainText = get_string("plainText: ")
    print("ciphertext: ", end="")
    for i in range(0, len(plainText)):
        if plainText[i].isalpha():
            if plainText[i].isupper():
                num = ord(plainText[i]) - 65
                num = ((num + key) % 26) + 65
                print(chr(num), end="")
            else:
                num = ord(plainText[i]) - 97
                num = ((num + key) % 26) + 97
                print(chr(num), end="")
        else:
            print(plainText[i], end="")
    print("")


if __name__ == "__main__":
    main()