def lines_are_paralel(l1,l2):

    if l1[0] == l2[0]:
        return True
    else:
        return False

def main():
    a, b, c = input ("Digit the values for 'a', 'b' and 'c' of the first line ax + b = c: ").split()
    d, e, f = input ("Digit the values for 'd', 'e' and 'f' of the second line dx + e = f: ").split()

    l1 = [a, b, c]
    l2 = [d, e, f]
    
    print (lines_are_paralel(l1, l2))

if __name__ == "__main__":
    main()