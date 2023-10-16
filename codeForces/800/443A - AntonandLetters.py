line = input()
line = line[1:-1]

letter = line.split(", ")

check = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

count = 0

for char in letter:
    if char in check:
        count += 1
        check.pop(check.index(char))

print(count)