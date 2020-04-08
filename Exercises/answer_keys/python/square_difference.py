import math

def sqrdif(r):

    bigger_square_area = 2*r*2*r
    smaller_square_area = math.sqrt(2)*r

    return larger_area - smaller_area

def main():

    radius = int(input("Give the radius of the circle: "))
    print("The difference of the areas of the squares is:", sqrdif(radius))

if __name__ == "__main__":
    main()