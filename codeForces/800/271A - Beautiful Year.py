
def main():
    year = int(input())
    for next in range(year + 1, 1000000000000000000):
        if check(next) == True:
            print(next)
            break

def check(s):
    s = str(s)
    if s[0] not in [s[1], s[2], s[3]] and s[1] not in [s[2], s[3]] and s[2] != s[3]:
        return True
    return False

if __name__ == "__main__":
    main()