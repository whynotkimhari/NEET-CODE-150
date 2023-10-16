from sys import exit

string1 = input().lower()
string2 = input().lower()

for i in range(len(string1)):
    if ord(string1[i]) > ord(string2[i]):
        print(1)
        exit()
    if ord(string1[i]) < ord(string2[i]):
        print(-1)
        exit()

print(0)