# Enter your code here. Read input from STDIN. Print output to STDOUT
t = int(raw_input())
for _ in range(t):
    a = set(raw_input())
    b = set(raw_input())
    if a.intersection(b):
        print "YES"
    else:
        print "NO"
