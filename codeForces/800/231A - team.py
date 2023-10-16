n = int(input())
lists = []
for i in range(n):
    lists.append(input().split(" "))

sol = 0
for i in range(n):
    cnt = 0
    for num in lists[i]:
        num = int(num)
        if num == 1:
            cnt += 1
        if cnt == 2:
            sol += 1
            break

print(sol)