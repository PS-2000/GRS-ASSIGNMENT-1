# GRS-ASSIGNMENT-1
# Little description about GRS  assignment 1

## The user input command in the context of the custom shell is the text that the user types at the shell prompt (myshell>).

For example, in the custom shell, users can type commands like:

# Built-in commands:

ls: Lists the files in the current directory.
cd <directory>: Changes the working directory.
help: Displays the help menu.
exit: Exits the shell.
Custom program commands:

./fact 10: Runs the custom program fact to calculate the factorial of 10.
Explanation of User Input Command
User enters a command at the shell prompt:

Example: ./fact 10
Parsing the command:

The input (./fact 10) is broken into tokens using strtok:
args[0] = "./fact" (the program to execute).
args[1] = "10" (an argument passed to the program).
args[2] = NULL (indicating the end of the arguments).
Executing the command:

If the command is a built-in one like cd or help, the shell handles it directly.
If it's an external program (./fact 10), the shell creates a child process using fork, and the child executes the command with execvp.

![Screenshot from 2025-01-25 10-52-54](https://github.com/user-attachments/assets/58efef0b-4bb4-4594-b2fe-d648a44e374c)
![Screenshot from 2025-01-25 10-26-51](https://github.com/user-attachments/assets/cfd1f56e-c054-4914-94f7-672764f09f2c)
