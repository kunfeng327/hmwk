import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

# w: width of the building.
# h: height of the building.
w, h = [int(i) for i in input().split()]
n = int(input())  # maximum number of turns before game over.
x0, y0 = [int(i) for i in input().split()]
ymin=0
ymax=h
xmin=0
xmax=w
# game loop
while True:
      # Current distance to the bomb compared to previous distance (COLDER, WARMER, SAME or UNKNOWN)
    ymid=(ymin+ymax)//2
    xmid=(xmin+xmax)//2
    
    bomb_dir = input()
    
    while ymid!=y0:
        ymid=(ymin+ymax)//2
        
        y0=2*ymid-y0
        print(x0,y0)
        bomb_dir = input()
        if bomb_dir=='UNKNOWN':
            pass
            
        elif bomb_dir=='WARMER':
            ymin=ymid+1

        elif bomb_dir=='COLDER':
            ymax=ymid-1
        
    while xmid!=x0:
        xmid=(xmin+xmax)//2
        x0=2*xmid-x0
        
        print(x0,y0)
        bomb_dir = input()
        if bomb_dir=='UNKNOWN':
            pass
        if bomb_dir=='WARMER':
            xmin=xmid+1
        elif bomb_dir=='COLDER':
            xmax=xmid-1
        
    # Write an action using print
    # To debug: print("Debug messages...", file=sys.stderr, flush=True)

    # print("0 0")
