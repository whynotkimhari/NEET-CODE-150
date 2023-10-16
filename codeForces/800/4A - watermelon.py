w = int(input())
 
if (w>=3 and w<=100) and w%2 ==0 and ((w/2 -2)%2==0 or ((w-2)/2)%2==0):
    print("YES")
 
else:
    print("NO")