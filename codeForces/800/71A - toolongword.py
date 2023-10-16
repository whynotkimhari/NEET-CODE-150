n =  int(input())
list = []
for i in range(n):
    list.append(input())

for word in list:
    if len(word) > 10:
        word = word[0] + f"{len(word)-2}" + word[-1]
    print(word)