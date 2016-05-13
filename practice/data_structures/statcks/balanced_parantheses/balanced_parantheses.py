#!/usr/bin/env python

PAIRS = {'}':'{', ')': '(', ']':'['}
CLOSE = ['}', ')', ']']
OPEN  = ['{', '(', '[']

def balanced(i_p):
    st = []
    for P in i_p:
        if st:
            if P in CLOSE:
                if st[-1] == PAIRS[P]:
                    st.pop()
            else:
                st.append(P)
        else:
            if P in OPEN:
                st.append(P)
            else:
                return False
            
    return True if not st else False
    

n = int(raw_input().strip())
for _ in xrange(n):
    r = raw_input().strip()
    if balanced(r):
        print "YES"
    else:
        print "NO"

