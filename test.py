
import sys
import math
def dfs():
    for i in range(height):
        for j in range(width):
            if lines[i][j] == '0':
                print(j, i, end = ' ')
                if j < width - 1:
                    for k in range(j+1, width):
                        if lines[i][k] == '0':
                            print(k, i, end = ' ')
                            break
                    else:
                        print(-1, -1, end = ' ')
                else:
                    print(-1, -1, end = ' ')
                if i < height - 1:
                    for k in range(i+1, height):
                        if lines[k][j] == '0':
                            print(j, k)
                            break
                    else:
                        print(-1, -1)
                else:
                    print(-1, -1)
    pass
# Don't let the machines win. You are humanity's last hope...
lines = []
width = int(input())  # the number of cells on the X axis
height = int(input())  # the number of cells on the Y axis
for i in range(height):
    line = input()  # width characters, each either 0 or .
    lines.append(line)
dfs()
# Auto-generated code below aims at helping you parse
# Write an action using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)


# Three coordinates: a node, its right neighbor, its bottom neighbor
# print("0 0 1 0 0 1")
