n = int(raw_input())
s = ""
for N in range(n):
    s += " " * (n - 1 - N) + "#" * (N + 1) + "\n"
print s
