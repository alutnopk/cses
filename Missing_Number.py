n = int(input())
fullsum = (n*(n+1))//2
partialsum = sum(list(map(int, input().split(" "))))
print(fullsum-partialsum)