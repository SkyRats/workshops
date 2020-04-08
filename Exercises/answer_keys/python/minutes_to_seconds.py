def convert(num): # this variable num is a copy of the variable num in main()

    return num * 60

def main():

    num = int(input("Write the number in minutes: "))

    print(convert(num))

if __name__ == "__main__":
    main()