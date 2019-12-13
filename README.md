# Simple-Shell

Linux (and other Unix like OSes), have **shells** or programs which present a command line interface to users to type commands in.This is a similar basic shell made in C Using fork(), exec() family system calls and wait() family of system calls.


To compile, run the `make` command, and to excecute, run `./code`. 


There are 2 types of commands in Linux Shells :
1. **Internal** : Internal commands are those which are interpreted by the shell program itself, without requiring a different program to handle the expected operations.
2. **External** : External commands on the other hand relate to commands which are not handled directly by the shell program but by an external program.

All external commands with their options can be tested in Linux based OS, as programs have been extracted from the bin folder and used directly. For Windows and other OS, the path of files needs to be changed from bin to the directory where these program files are stored.

In case of internal commands, since this is a very basic shell, only 5 commands are handled. with 2 options each. 

1. exit : It exits the shell gracefully, displaying an exit message prior to exiting.
2. cd:  cd refers to ‘change directory’.
    - With one argument, cd <input> is used to change the present working directory to the one mentioned in the input.
    - cd.. changes the working directory to the parent directory of the current directory.
3. echo :  The echo command is used to display the line of a text. Here it neglects the extra space if present before or after the command.
    - echo -E : It explicitly suppresses the interpretation of backslash escapes.  `echo -E abcdef\nghi      xyz `. It will output >abcdefnghi xyz .(Neglects extra space and ignores backslash escape sequences.)
    
    - echo -n : It doesn’t append a new line.
    eg.  >>echo -n “abc          def”  
    It will output abc def (i.e it neglects the extra space)
4. history
    - history:  shows the complete history of commands entered by the user. It will also display the latest command including the command history.
    - history -c: It clears the entire command history. To check it, run the command history and it will only give the output as the very latest command -history.

5. pwd : pwd(Present Working Directory) shows the current working directory.






