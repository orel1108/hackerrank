n = int(raw_input())
stones = [set(raw_input()) for _ in range(n)]
gem = stones[0]
for i in range(1, len(stones)):
    tmp = gem.intersection(stones[i])
    gem = set(tmp)
print len(gem)
