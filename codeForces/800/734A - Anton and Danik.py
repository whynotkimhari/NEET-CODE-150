n = int(input())
matches = input()

anton = 0

for i in range(n):
    if matches[i] == "A":
        anton += 1

if anton > n - anton:
    print("Anton")
elif anton < n - anton:
    print("Danik")
else:
    print("Friendship")