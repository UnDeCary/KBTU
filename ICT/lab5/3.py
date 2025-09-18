def fact(n: int):

    if n == 1:
        return 1
    
    else:
        return n * fact(n-1)

def main():
    num = int(input("Enter number: "))

    print(f"Result {fact(num)}")