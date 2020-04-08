def pentagonal(num):

    sum = 0
    sum2 = 1

    for i in range(num):
        sum2 += sum
        sum += 5

    return sum2

def main():

    num = int(input("Digit a number: "))
    print("The pentagonal number is: ", pentagonal(num))

if __name__ == "__main__":
    main()