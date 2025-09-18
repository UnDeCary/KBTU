def add(tasks: dict, name: str, description: str) -> dict:
    tasks[name] = description
    return tasks

def view(tasks: dict) -> None:
    for name, desc in tasks.items():
        print(f"{name} : {desc}")

def delete(tasks: dict, name: str) -> dict:
    del tasks[name]
    return tasks


def main():
    tasks = {}

    while True:
        operation = input("Choose action: add, view, delete, quit\n> ")

        match operation:
            case 'add':
                name = input("Enter name: ")
                description = input("Enter description: ")

                tasks = add(tasks, name, description)

                print("Task added")
            
            case 'view':
                view(tasks)

            case 'delete':
                name = input("Enter name: ")

                tasks = delete(tasks, name)

            case 'quit':
                break

        print('\n')


main()