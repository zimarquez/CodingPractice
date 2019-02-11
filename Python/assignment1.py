# Ismael Marquez, im6549

# initialize stop to false
stop = False

# loop until the user decides to quit
while not stop:
    # prompt user for the desired operation
    op = input("Enter operation: ")

    # set stop to true if the user wants to quit
    if op == 'q':
        stop = True
    # prompt the user for the two operands and cast them as floats
    else:
        num1 = input("Enter first number: ")
        num2 = input("Enter second number: ")
        
        if num1 == '':
            # set num1 to 0 if the user did not input anything
            num1 = 0.0
        else:
            # convert the number entered into a float
            num1 = float(num1)
        
        if num2 == '':
            # set num2 to 0 if the user did not input anything
            num2 = 0.0
        else:
            # convert the number entered into a float
            num2 = float(num2)
        
        # execute and print the desired operation
        if op == '+':
            print(num1 + num2)
        elif op == '-':
            print(num1 - num2)
        elif op == '*':
            print(num1 * num2)
        elif op == '/':
            print(num1 / num2)
        elif op == '^':
            print(num1 ** num2)
        # output an error if the entered operation is not a valid operation        
        else:
            print("Error: Not a valid operation")
    
    