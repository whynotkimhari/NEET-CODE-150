n = int(input())
list = []
ans = 0

for i in range(n):
    list.append(input())

for bits in list:
    if "++" in bits:
        ans += 1
    if "--" in bits:
        ans -= 1

print(ans)