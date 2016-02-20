for i in range(int(raw_input())):
    a = int(raw_input().strip()); A = set(raw_input().strip().split())
    b = int(raw_input().strip()); B = set(raw_input().strip().split())
    print True if not A.difference(B) else False

