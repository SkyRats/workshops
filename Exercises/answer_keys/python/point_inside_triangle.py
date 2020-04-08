def point_within_triangle(c1, c2, c3, c4):

    init_area = (c1[0]*c2[1]) - (c1[1]*c2[0]) + (c2[0]*c3[1]) - (c2[1]*c3[0]) + (c3[0]*c1[1]) - (c3[1]*c1[0])

    new_area = (c4[0]*c2[1]) - (c4[1]*c2[0]) + (c2[0]*c3[1]) - (c2[1]*c3[0]) + (c3[0]*c4[1]) - (c3[1]*c4[0])
    new_area += (c1[0]*c4[1]) - (c1[1]*c4[0]) + (c4[0]*c3[1]) - (c4[1]*c3[0]) + (c3[0]*c1[1]) - (c3[1]*c1[0])
    new_area += (c1[0]*c2[1]) - (c1[1]*c2[0]) + (c2[0]*c4[1]) - (c2[1]*c4[0]) + (c4[0]*c1[1]) - (c4[1]*c1[0])

    if new_area == init_area:
        return True
    else:
        return False

def main():

    cd1, cd2, cd3, cd4 = ([] for i in range(4))

    cd1 = input("Give the coordinates of the 1 dot: ").split()
    cd1 = list(map(int, cd1))
    cd2 = input("Give the coordinates of the 2 dot: ").split()
    cd2 = list(map(int, cd2))
    cd3 = input("Give the coordinates of the 3 dot: ").split()
    cd3 = list(map(int, cd3))
    cd4 = input("Give the coordinates of the 4 dot: ").split()
    cd4 = list(map(int, cd4))
    
    print("Your coodinates are:", cd1, cd2, cd3, cd4)

    print(point_within_triangle(cd1, cd2, cd3, cd4))

if __name__ == "__main__":
    main()