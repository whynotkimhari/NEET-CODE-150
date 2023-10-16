def main():
    print(do(input()))

def do(s):
    cntUp = 0
    for i in range(len(s)):
        if s[i].isupper() == True:
            cntUp += 1
    cntLw = len(s) - cntUp
    if cntUp == cntLw:
        return s.lower()
    elif cntUp > cntLw:
        return s.upper()
    else:
        return s.lower()

if __name__ == "__main__":
    main()