n = int(input())

while True:
    print(f"{n:d}",end=" ")
    if n==1:
        break
    n = n//2 if n%2 == 0 else 3*n + 1