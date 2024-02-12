kpair = [0, 0, 6, 28]

for k in range(1, int(input())+1):
    if k > 3:
        # compute kpair[k] using the equation:
        # K(n) = K(n-1) + n(n-1)(2n-1) - 8n + 16
        temp = kpair[k-1] + 2*k**3 - 3*k**2 - 7*k + 16
        kpair.append(temp)

    print(kpair[k])
