import os

def clear():
    if os.name == 'nt':
        os.system('cls')
    else:
        os.system('clear')

while True:

    clear()

    task = input("Enter the number of task [1-7]\n\n>> ")

    try:
        task = int(task)
    except:
        print(f"\n\nIncorrect number '{task}'\n\n")
        input("\nPress 'Enter' to continue")
        continue

    if not 1 <= task <= 7:
        print(f"\n\nIncorrect number '{task}'\n\n")
        input("\nPress 'Enter' to continue")
        continue


    # Task 1. BMI calculator

    if task == 1:

        clear()

        weight = input("Enter your weigth (kg ex: 67)\n\n>> ")

        clear()

        height = input("Enter your height (meters ex: 1.85)\n\n>> ")

        clear()

        try:
            bmi = round(int(weight)/(float(height)**2), 2)
        except:
            print("Incorrect data provided!")

        print(f"BMI = {bmi}")

        if bmi < 18.5:
            print("Underweight")
        elif 18.5 <= bmi <= 24.9:
            print("Normal weight")
        elif 25 <= bmi <= 29.9:
            print("Overweight")
        elif 30 <= bmi:
            print("Obesity")
        
        input("\nPress 'Enter' to continue")


    # Task 2. To-Do list

    if task == 2:

        clear()

        todo = []

        while True:
            clear()

            print("Commadns:\n")
            print("add [text] - add new todo note in list")
            print("remove [number] - remove note from list by number")
            print("show - shows all todo list")
            print("exit - shutdown the program\n\n")

            command = input("Input the command\n\n>> ").strip()

            # if command == 'help':
            #     clear()
            #     print("Commadns:\n")
            #     print("add [text] - add new todo note in list")
            #     print("remove [number] - remove note from list by number")
            #     print("show - shows all todo list")
            #     print("exit - shutdown the program")
            #     input()

            if command[0:3] == 'add':
                task = ' '.join(command.split()[1::])
                if task:
                    todo.append(f"[{len(todo)}] {task}")
                    print(f"Task '{task}' successfully added!")
                    
                else:
                    print("There is no text to add :c")

                input("\nPress 'Enter' to continue")

            elif command[0:6] == 'remove':
                try:
                    element_index = int(command.split()[1].strip())
                except:
                    print("use 'remove [NUMBER!!!]'\nex.: remove 0")
                    continue
                
                if 0 <= element_index < len(todo):
                    task = ' '.join(todo.pop().split()[1::])
                    print(f"Task '{task}' successfully removed")
                else:
                    print(f"Write the correct number of the task [0-{len(todo)-1}]")

                for i in range(element_index, len(todo)):
                    index = todo[i].find("]")
                    todo[i] = todo[i][0] + str(i) + todo[i][index::]

                input("\nPress 'Enter' to continue")

            elif command.strip() == 'show':
                for i in todo:
                    print(i)
                
                input("\nPress 'Enter' to continue")


            elif command.strip() == 'exit':
                break

            else:
                print("Can`t recognize command.")
                input("\nPress 'Enter' to continue")



    # Task 3. Multiplication 

    if task == 3:
        clear()

        n = int(input("Enter number\n\n>> "))
        table = [[0 for i in range(n+1)] for i in range(n+1)]

        for i in range(n+1):
            for j in range(n+1):
                if i == 0:
                    table[i][j] = j
                elif j == 0:
                    table[i][j] = i
                else:
                    table[i][j] = i*j

        for row in table:
            formated = " ".join("{:>{}}".format(item, 3) for item in row)
            print(formated)
            
        input("\nPress 'Enter' to continue")



    # Task 4. Comprehensions and Filtering

    if task == 4:
        clear()

        a = [x for x in range(1, 51)]
        b = [x for x in range(1, 51) if x%3 == 0 and x%5 == 0]

        print(a, b, sep='\n')
        input("\nPress 'Enter' to continue")



    # Task 5. Contact Book


    if task == 5:


        book = {}

        while True:
            
            clear()


            print("Commadns:\n")
            print("add [name] [phone] - add new contact in list")
            print("remove [name] - remove contact from book by name")
            print("search [name] - search contact by name")
            print("show - shows all contacts")
            print("exit - shutdown the program\n\n")

            command = input("Input the command\n\n>> ").strip().split()

            # if command == 'help':
            #     print("Commadns:\n")
            #     print("add [name] [phone] - add new contact in list")
            #     print("remove [name] - remove contact from book by name")
            #     print("search [name] - search contact by name")
            #     print("show - shows all contacts")
            #     print("exit - shutdown the program")

            if command[0] == 'add':
                if len(command) != 3:
                    print("use 'add [name] [phone]'")

                else:
                    book[command[1]] = command[2]
                    print(f"'{command[1]}' added to the book!")
                input("\nPress 'Enter' to continue")

            elif command[0] == 'remove':
                if len(command) < 2:
                    print("use 'remove [name]'")
                    continue

                if command[1] not in book.keys():
                    print(f"There is no '{command[1]}' in contact book")
                
                else:
                    del book[command[1]]
                    print(f"'{command[1]}' removed from the book")

                input("\nPress 'Enter' to continue")

            elif command[0] == 'search':
                if len(command) != 2:
                    print("use 'remove [name]'")
                    continue
                
                if command[1] not in book.keys():
                    print(f"There is no '{command[1]}' in contact book")

                else:
                    print(f"{command[1]} : {book[command[1]]}")

                input("\nPress 'Enter' to continue")



            elif command[0] == 'show':
                for i in book.items():
                    print(f"{i[0]} : {i[1]}")
                    
                input("\nPress 'Enter' to continue")


            elif command[0] == 'exit':
                break

            else:
                print("Can`t recognize command.")
                input("\nPress 'Enter' to continue")



    # Task 6. Sorting and Display data

    if task == 6:

        clear()

        students = [
            ('Alice', 87),
            ('Bob', 77),
            ('Jamal', 99),
            ('Nurjan', 79)
        ]


        sorted_students = sorted(students, key=lambda student: student[1])
        for row in sorted_students:
            print(filtered)

        input("\nPress 'Enter' to continue")




    # Task 7. Palindrome checker

    if task == 7:

        clear()

        word = input("Enter word or phrase\n\n>> ").strip().lower()
        print(word)
        word = ''.join(char for char in word if char.isalpha() or char.isnumeric())

        if word == word[::-1]:
            print(f"{word} is palindrome")
        else:
            print(f"{word} is not a palindrome")

        input("\nPress 'Enter' to continue")