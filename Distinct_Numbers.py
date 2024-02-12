n = int(input())
v = list(map(int, input().split()))
v.sort()
dcount, prev = 0, 0
for x in v:
    if prev == x:
        continue
    else:
        dcount += 1
        prev = x

print(dcount)