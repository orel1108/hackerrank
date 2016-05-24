#!/usr/bin/env python

st = []
s = ''
n = int(raw_input().strip())
for _ in xrange(n):
    comm = raw_input().strip().split()
    if comm[0] == '1':
        st.append(str(s))
        s += comm[1]
    elif comm[0] == '2':
        st.append(str(s))
        s = s[:-int(comm[1])]
    elif comm[0] == '3':
        print s[int(comm[1]) - 1]
    else:
        s = st.pop()

