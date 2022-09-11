import math
from re import S


X1 = [283746263, 987361523, 281936352, 143042069, 1000000000]
X2 = [123456789, 192837465, 135792468, 703692581]
Y1 = [475619273, 361738847, 666152443, 482716253, 100000000]
Y2 = [987654321, 918273645, 864209753, 185296307]

c = 98765432001
squared = 0
sq = 0
while (squared == sq):
    print(c)
    c += 1
    squared = c ** 2
    sq = math.pow(c, 2)
print(squared)
print(sq)
print(c)




sum = 0
p = 1000000007
for i in range(5):
    for j in range(4):
        sum = (sum + ((X1[i] - X2[j]) * (X1[i] - X2[j])) % p) % p
        sum = (sum + ((Y1[i] - Y2[j]) * (X1[i] - X2[j])) % p) % p

print(sum)