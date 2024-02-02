def func(idx : int, code : str):
    sum = 0
    for i in range(idx):
        alpha = code[i]
        sum += (ord(alpha)-96)*(31**i)
    return sum % 1234567891


def main():
    L = int(input())
    code = input()
    print(func(L, code))

if __name__ == '__main__':
    main()

