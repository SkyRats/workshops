# This program has the goal to print a "Ladder" of chars that 
# is chosen by the user. The height of the "Ladder" also
# is chosen by the user.

def ladder(h, d):

    h = int(h)
    tmp = 1

    for i in range(h):
        for j in range(tmp):
            print (d, end= ' ')
        print("")
        tmp += 1

def main():

    height, digit = input("Input a height value and a type of digit: ").split()

    ladder(height, digit)

if __name__ == "__main__":
    main()