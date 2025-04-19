def f(x0,y0,w,h,x,y):
    x_min=0
    x_max=w
    y_min=0
    y_max=h
    x_mid=x0
    y_mid=y0
    print(x_mid,y_mid)
    while 1:
        bomb_dir=input()
        
        if 'U' in bomb_dir:
            y_max=y_mid
        elif 'D' in bomb_dir:
            y_min=y_mid
        if 'L' in bomb_dir:
            x_max=x_mid
        elif 'R' in bomb_dir:
            x_min=x_mid
        x_mid=(x_min+x_max)//2
        y_mid=(y_min+y_max)//2
        print(x_mid,y_mid)
        if x_mid==x and y_mid==y:
            break
        
    return (x_mid,y_mid)
f(20,40,100,100,18,6)


