n = int(input())
stones = input()
Stones = []

for i in range(len(stones)):
    Stones.append(stones[i])

a = -1
while True:
    c = 0
    for i in range(len(stones)+a):
        if Stones[i] == Stones[i+1]:
            Stones.pop(i)
            a -= 1
            c += 1
            break
    if c == 0:
        break

print(len(stones)-len(Stones))