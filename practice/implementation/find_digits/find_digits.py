t = int(raw_input())
for _ in range(t) :
    n = raw_input()
    digits = map(int, n)
    print len(filter(lambda x: x > 0 and int(n) % x == 0, digits))
