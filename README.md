# **Project Name**
<p align="center">
  <img src="Simple shell in c.gif" width="650" height="500">
</p>

## **📋Table of Contents**
1. [Introduction](#introduction)
2. [Synopsis](#synopsis)
3. [Project](#Project)
  - [General Requirements](#general-requirements)
  - [Functions and system calls used](#functions-and-system-calls-used)
  - [Description of each file](#description-of-each-file)
    - [Description of helper files](#description-of-helper-files)
  - [Environment](#environment)
  - [Compilation](#compilation)
  - [Testing](#testing)
    - [Interactive](#interactive-mode)
    - [Non-Interactive](#non-interactive-mode)
    - [Sample usage](#sample-usage)
    - [Stop and return to your original shell](#stop-and-return-to-your-original-shell)
  - [Project Tasks](#project-tasks)
4. [Project Documentation](#project-documentation)
5. [Authors](#authors)

## **📜Introduction**
 * In this project we coded from scratch a simple Unix shell.
  
  * But what is a shell?

    A shell is an interactive command line interpreter(CLI). Which allows user's to type in a defined set of commands (e.g. "rm" to remove files, "cat" to combine word documents, etc) and have the operating system run the appropriate function. It is slightly different from a graphical user interface (GUI). For instance, instead of using a mouse to click to open folders and delete files, a user can type in a command (i.e. "ls" or "rm") and have the files be displayed or modified in a list on the command line. GUI and CLI both have the same purpose, to interact with the operating system but their input methods are different and some developers prefer the CLI to interact with the shell because their typing is quicker than clicking and dragging.

[Back to Top](#project-name)
    
## **💡Synopsis**

  This repository holds all the code necessary for our custom simple shell to run. Our shell currently handles the executions of executables found in the environmental variable PATH, with or without their full paths.
  
[Back to Top](#project-name)
  
## **💽Project**

### **📑General Requirements**
  
  - Allowed editors: `vi`, `vim`, `emacs`
  - All the files should end with a new line
  - A `README.md` file, at the root of the folder of the project is mandatory
  - The shell should not have any memory leaks
  - No more than 5 functions per file
  - All the header files should be include guarded
  - The system calls should be only when needed to

### **💻Functions and system calls allowed**

   - all functions from strings.h
   - access (man 2 access)
   - chdir (man 2 chdir)
   - close (man 2 close)
   - closedir (man 3 closedir)
   - execve (man 2 execve)
   - exit (man 3 exit)
   - _exit (man 2 _exit)
   - fflush (man 3 fflush)
   - fork (man 2 fork)
   - free (man 3 free)
   - getcwd (man 3 getcwd)
   - getline (man 3 getline)
   - getpid (man 2 getpid)
   - isatty (man 3 isatty)
   - kill (man 2 kill)
   - malloc (man 3 malloc)
   - open (man 2 open)
   - opendir (man 3 opendir)
   - perror (man 3 perror)
   - printf (man 3 printf)
   - fprintf (man 3 fprintf)
   - vfprintf (man 3 vfprintf)
   - sprintf (man 3 sprintf)
   - putchar (man 3 putchar)
   - read (man 2 read)
   - readdir (man 3 readdir)
   - signal (man 2 signal)
   - stat (__xstat) (man 2 stat)
   - lstat (__lxstat) (man 2 lstat)
   - fstat (__fxstat) (man 2 fstat)
   - strtok (man 3 strtok)
   - wait (man 2 wait)
   - waitpid (man 2 waitpid)
   - wait3 (man 2 wait3)
   - wait4 (man 2 wait4)
   - write (man 2 write)
  
### **🗃Description of each file**
- main.c - serves as the main entry point for the simple shell program and provides the basic functionality for reading user input, parsing it, and executing commands.

- shell.h - header file containing all the prototype functions and libraries needed.

- parser.c - provides the functionality to parse input strings into separate arguments.

- enviroment.c - allows the program to read and modify environment variables as needed during execution.

- free_array - used in the main.c to free the memory allocated for the array of arguments passed to the execve. 

- exec.c - execute user commands in the simple shell.

- get_directions - get the direction of an input command in the simple shell program.

### **🌎Environment**
  - Language: C
  - OS: Ubuntu 20.04
  - Compiler: gcc
  - Style guideines: Betty Style

### **💻Compilation**
  - All of our files will be compiled using:

    `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
    
  
### **💻Testing**
  
   -You can test our custom version of the shel in the interactive and non-interactive mode.
    
#### **💻Interactive mode**

  - The shell should work like this in interactive mode:
    
  ```bash
  $ ./hsh
  ($) /bin/ls
  hsh main.c shell.c
  ($)
  ($) exit
  $
  ```
    
#### **💻Non-Interactive mode**

  -In the non-interactive mode should work like this:
  
      
    $ echo "/bin/ls" | ./hsh
    hsh main.c shell.c test_ls_2
    $
    $ cat test_ls_2
    /bin/ls
    /bin/ls
    $
    $ cat test_ls_2 | ./hsh
    hsh main.c shell.c test_ls_2
    hsh main.c shell.c test_ls_2
    $
    

#### **💻Sample usage**

  - This is a simple example of what and how you can do some commands in our custom shell:
    
    ```bash
    $ echo "This is pretty cool!"
    This is pretty cool!
    $ man ./man_1_simple_shell (opens our manpage for more information)
    ```

#### **💻Stop and return to your original shell**

  - To stop our shell and return to your original shell you should type the command:
    
    ```bash
    $ exit
    (your_terminal)$
    ```
    
[Back to Top](#project-name)
  
    
## 📝Project Tasks

-We as a team have to follow a few given tasks to complete this project. Below you will find those tasks and what requirements have each one:

  - Task 0
    - Write a README
    - Write a man for your shell
    - AUTHORS file at the root of your repository
  - Task 1
    - Write a beautiful code that passes the Betty checks
  - Task 2
    -Write a UNIX command line interpreter
      - The Shell should:
        - Display a prompt and wait for the user to type a command. A command line always ends with a new line
        - The prompt is displayed again each time a command has been executed.
        - The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
        - The command lines are made only of one word. No arguments will be passed to programs.
        - If an executable cannot be found, print an error message and display the prompt again.
        - Handle errors.
        - Have to handle the “end of file” condition (`Ctrl+D`)
       - We don't have to:
        - use the `PATH`
        - implement built-ins
        - handle special characters : `"`, `'`, `, `\`, `*`, `&`, `#`
        - be able to move the cursor
        - handle commands with arguments
  - Task 3
    - Handle command lines with arguments
  - Task 4 
    - Handle the `PATH`
    - `fork` must not be called if the command doesn’t exist
  - Task 5 
    - Implement the `exit` built-in, that exits the shell
    - Usage: `exit`
    - Don’t have to handle any argument to the built-in `exit`
  - Task 6
    - Implement the `env` built-in, that prints the current environment

[Back to Top](#project-name)



## **📚Acknowledgements**
We would like to thank those who have contributed to this project:<br>
![Lizzbeth Garleb](https://github.com/LizzGarleb)<br>
![Eduardo Figueroa](https://github.com/Semaed)<br>
![Jose Rivera](https://github.com/jGohan-cpu)<br>

[Back to Top](#project-name)

## 🤝Authors
![Jean Micheal Barbosa](https://github.com/JeanBarbosa-hue)<br>
![Jonathan Perez](https://github.com/JonathanPR24)<br>
![Xai Betancourt](https://github.com/Xespinosa)

[Back to Top](#project-name)
