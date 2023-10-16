n =  input()
cnt = 0
for i in range(len(n)):
    if n[i] in ["4", "7"]:
        cnt += 1

if cnt in [4, 7]:
    print("YES")
else:
    print("NO")