number = input().split("+")
ans = ""
for i in number:
    i = int(i)
number.sort()
for i in range(len(number)-1):
    ans += f"{number[i]}+"

ans += f"{number[-1]}"
print(ans)