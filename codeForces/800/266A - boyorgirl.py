def main():
    print(BoG(input()))

    
def BoG(username):
    list = []
    for i in range(len(username)):
        if username[i] not in list:
            list.append(username[i])
    if len(list) % 2 == 0:
        return "CHAT WITH HER!"
    else:
        return "IGNORE HIM!"

if __name__ == "__main__":
    main()