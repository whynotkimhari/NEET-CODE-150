def main():
    n, k = map(int, input().split(" "))
    print(do(n,k))
def do(n, k):
    while k != 0:
        if check(n) == True:
            n -= 1
        else:
            n //= 10
        k -= 1
    return n

def check(n):
    n = str(n)
    if n[-1] != "0":
        return True
    else:
        return False
if __name__ == "__main__":
    main()