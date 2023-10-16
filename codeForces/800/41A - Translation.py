s = input()
t = input()

if len(s) != len(t):
    print("NO")

else:
    check = True
    for i in range(len(s)):
        if s[i] != t[len(s) - i - 1]:
            check = False
            break

    if check == True:
        print("YES")
    else:
        print("NO")