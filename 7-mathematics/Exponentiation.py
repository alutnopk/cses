###################### TLE
n = int(input())
for k in range(n):
    a, b = tuple(map(int, input().split()))
    res = 1
    a = a%1000000007
    while b > 0:
        if b%2 == 1:
            res = (res*a)%1000000007
        b = b//2
        a = pow(a, 2, 1000000007)
    print(res)