#!/usr/bin/py
# Head ends here
def pairs(a,k):
    #a contains array of numbers and k is the value of difference
    answer = 0
    
    a = sorted(a)
    start = a[0]
    i = 0
    j = 1
    while j < len(a):
        i = j
        while i < len(a) and a[i] - start < k:
            i += 1
        if i < len(a) and a[i] - start == k:
            answer += 1
        start = a[j]
        j += 1
        
    return answer
# Tail starts here
if __name__ == '__main__':
    a = map(int, raw_input().strip().split(" "))
    _a_size=a[0]
    _k=a[1]
    b = map(int, raw_input().strip().split(" "))
    print pairs(b,_k)

