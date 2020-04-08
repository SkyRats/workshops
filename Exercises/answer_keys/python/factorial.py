def factorial(num):

    n = num - 1
    while(n > 1):
        num = num * n
        n -= 1
    return num

def main():

    num = int(input("Input n: "))
    print("factorial of", num, "is", factorial(num))

if __name__ == "__main__":
    main()  