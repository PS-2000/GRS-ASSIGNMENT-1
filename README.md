![Screenshot from 2025-01-27 00-15-13](https://github.com/user-attachments/assets/3fdea41f-e2e2-425e-88b1-006deb08ad1c)
![Screenshot from 2025-01-27 00-15-04](https://github.com/user-attachments/assets/c50f966a-4142-4064-8a8f-f45ea1d1f1dc)
![Screenshot from 2025-01-27 00-14-57](https://github.com/user-attachments/assets/0c62e6ed-e28e-4f30-a3d7-e59e1b31a2dd)
![Screenshot from 2025-01-27 00-14-51](https://github.com/user-attachments/assets/2c836e7b-30ae-43e3-9f1e-592da848d3f0)
![Screenshot from 2025-01-27 00-14-45](https://github.com/user-attachments/assets/9ac97bd7-3055-4913-bf66-8ad68e4e1a95)
![Screenshot from 2025-01-27 00-14-38](https://github.com/user-attachments/assets/56ec1acd-9cdf-470a-9fd4-1cd9163682cc)
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

##  Process Tree :

![Screenshot from 2025-01-25 13-35-53](https://github.com/user-attachments/assets/6c4ee898-6697-4fa0-ac5b-1c443cca80bc)
