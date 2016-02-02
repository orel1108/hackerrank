t = int(raw_input())
for _ in range(t) :
    n = int(raw_input())
    a = int(raw_input())
    b = int(raw_input())
    if a == b :
        print a * (n - 1)
    else :
        if a > b :
            a, b = b, a
        if n == 1 :
            print 0
        else :
            for j in range(n) :
                print a * (n - 1 - j) + b * j,
        print 
