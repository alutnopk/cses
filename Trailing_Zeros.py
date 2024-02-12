n = int(input())
count2 = 0
count5 = 0
term2 = 2
term5 = 5
while n//term2 >= 1:
    count2 += n//term2
    term2 *= 2

while n//term5 >= 1:
    count5 += n//term5
    term5 *= 5

count10 = count2 if count2 < count5 else count5
print(count10)