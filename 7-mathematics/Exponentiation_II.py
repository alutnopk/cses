############################## TLE
T = int(input())
for t in range(T):
    a, b, c = tuple(map(int, input().split()))
    # b^c mod p-1
    exp = 1
    A = a%1000000007
    B = b%1000000006
    C = c
    while C > 0:
        if C%2 == 1:
            exp = (exp*B)%1000000006
        C = C//2
        B = pow(B, 2, 1000000006)
    
    # a^exp mod p
    res = 1
    while exp > 0:
        if exp%2 == 1:
            res = (res*A)%1000000007
        exp = exp//2
        A = pow(A, 2, 1000000007)
    
    print(res)