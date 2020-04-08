def mmc (a, b):
    
    if a > b:
        maior = a
        tmp = a
        menor = b
    else:
        maior = b
        tmp = b
        menor = a

    while (maior%menor != 0):
        maior += tmp

    return maior

def main():

    a, b = input ("Give me 2 numbers: ").split()
    a = int (a)
    b = int(b)

    print("The MMC between ", a, " and ", b, " is ", mmc(a, b))

if __name__ == "__main__":
    main()