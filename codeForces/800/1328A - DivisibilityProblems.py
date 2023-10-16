t = int(input())

fractions = []
ans = []

for i in range(t):
    fractions.append(input().split(" "))
    fractions[i][0] = int(fractions[i][0])
    fractions[i][1] = int(fractions[i][1])

for i in range(t):
    step = 0
    if fractions[i][0]%fractions[i][1] != 0:
        step = fractions[i][1]*(fractions[i][0]//fractions[i][1] + 1) - fractions[i][0]
    ans.append(int(step))

for num in ans:
    print(num)