#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<string.h>
void show_help()
{
  printf("Custom Shell Help:\n");
  printf("1. Run external programs (e.g: ./fact 10). \n");
  printf("2. Built-in commands:\n");
  printf("    -ls: List files in the current directory.\n");
  printf("    -cd<directory>:Change to the cutrrent directory.\n");
  printf("    -exit: Exit the shell.\n");
  printf("    -help: Display this help messagge. \n");
  printf("3.  Supports I/O redirection:\n");
  printf("   - < for input redirection\n");
  printf("   - > for output redirection\n");
}

void change_directory(char *path)
{
  if(chdir(path)==0)
   {
     printf("Directory changed to: %s\n", path);
    }
     else
     {
         perror("cd");
     }
 }

void execute_command(char **args)
{
  pid_t pid = fork();

   if(pid<0)
   {
     perror("Fork failed");
     return;
    }
  
 if(pid==0)
   {
     int i=0;
//     int input_red=0, output_red=0;
     int fd_in,fd_out;
     while(args[i]!=NULL)
       {
          if(strcmp(args[i], "<")==0)
            {
               if(args[i+1]!=NULL)
                {
                     fd_in=open(args[i+1],O_RDONLY);
                      if(fd_in<0)
                        {
                           perror("Error opening input file");
                             exit(EXIT_FAILURE);
                           }
                              dup2(fd_in,STDIN_FILENO);
                              close(fd_in);
                            //  input_red=1;
                               args[i]=NULL;
                     }
                   else
                     {
                          fprintf(stderr,"Syntax error:Expected input file  after '<'\n");
                           exit(EXIT_FAILURE);
                     }
               }
         else if(strcmp(args[i], ">")==0)
           {
              if(args[i+1] !=NULL)
              {
                 fd_out=open(args[i+1],O_WRONLY | O_CREAT | O_TRUNC, 0644);
                   if(fd_out<0)
                     {
                         perror("Error opening output file");
                          exit(EXIT_FAILURE);
                      }
                       dup2(fd_out,STDOUT_FILENO);
                       close(fd_out);
                      // output_red=1;
                       args[i]=NULL;
                }
                  else
                   {
 
                      fprintf(stderr, "Syntax  error: Expected output file after  '>'\n");
                       exit(EXIT_FAILURE);
                    }
             }
               i++;
        }


               if(execvp(args[0],args)==-1)
                 {
                      perror("Error executing command");
                 }
                    exit(EXIT_FAILURE);
     }

       else
         {
               int status;
               waitpid(pid, &status, 0);
          }
}

int main() {
    char input[1024];
    char *args[100];
    char *token;
    int running = 1;

    printf("Welcome to the Custom Shell! Type 'help' for assistance.\n");

    while (running) {
        printf("myshell> ");
        fflush(stdout);

        if (!fgets(input, sizeof(input), stdin)) {
            perror("Error reading input");
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        int i = 0;
        token = strtok(input, " ");
        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL; 
        if (args[0] == NULL) {
            continue; 
        } else if (strcmp(args[0], "exit") == 0) {
            running = 0; 
        } else if (strcmp(args[0], "help") == 0) {
            show_help();
        } else if (strcmp(args[0], "cd") == 0) {
            if (args[1] != NULL) {
                change_directory(args[1]);
            } else {
                printf("Usage: cd <directory>\n");
            }
        } else {
            execute_command(args);
        }
    }

    printf("Exiting Custom Shell. Goodbye!\n");
    return 0;
}



















     
               
