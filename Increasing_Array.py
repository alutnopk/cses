n = int(input())
l = list(map(int, input().split()))
prev = -1
count = 0
for i in range(len(l)):
    if i==0:
        prev = l[i]
        continue
    if l[i]>=prev:
        prev = l[i]
    else:
        count += prev-l[i]
        l[i] = prev

print(count)