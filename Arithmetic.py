# https://open.kattis.com/problems/simplearithmetic
from decimal import *

a, b, c = map(Decimal, input().split())
if c == 1:
    print(Decimal(a * b))
else:
    print(Decimal(a * (b / c)))

# 18446744073709551616
# 10000000000000000000