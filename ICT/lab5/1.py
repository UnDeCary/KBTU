def add(a: float, b: float) -> float:
    return a + b

def subtract(a: float, b: float) -> float:
    return a - b

def multiply(a: float, b: float) -> float:
    return a * b

def divide(a: float, b: float) -> float:
    return a / b


print(add("cf", "hj"))
def main():
    try:
        a = float(input("Enter first number: "))
        b = float(input("Enter second number: "))
    except Exception as e:
        print(repr(e))
        return

    operation = input("Select operation (add, subtract, multiply, divide): ")

    match operation:
        case 'add':
            print(f'Result: {add(a, b)}')
        case 'subtract':
            print(f'Result: {subtract(a, b)}')
        case 'multiply':
            print(f'Result: {multiply(a, b)}')
        case 'divide':
            print(f'Result: {divide(a, b)}')

main()