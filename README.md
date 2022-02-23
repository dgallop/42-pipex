PIPEX:

This poject recreates the use of pipes such as:
<infile command1 | command2 > outfile

How to use the program after being compiled:
./pipex infile command1 command2 outfile
./pipex hello.txt "ls -l" "wc -l" bye.txt

Shells use this to implement commands with pipes, e.g. /bin/ls | more by connecting the stdout of one process to the stdin of the other.

Description of my pipex:

These are the functions from C libraries that I was allowed to use by 42: write, read, close, access, pipe, dup2, execve, fork, malloc, free, exit, waitpid and perror.

I used a struct named my_pipex to save all the important elements that I will need along my own functions.

In order to handle error I  assigned each one a message as u can see in pipex.h such as: ERR_INPUT, ERR_INFILE, ERR_OUTFILE and ERR_COMMD.

Despite int main I use 12 self-made functions that are sort in my library pipex.h

Functionality:

My program takes the path given by the enviorement(envp) and using get_path takes the parts of the path that are used by program like ls, cat, echo, etc. The paths are saved in my_pipex structure as strings.

Following, it comes up the function, treat_argvs that makes sure the number of arguments are valid and that as infile as outfile are ready to be used by pipex.

Further more we start the pipe which are also in my structure as fd[2], i saved it as 2 because I am going to aplly only for 2 proccesses. Then we fork toward create a child of the main pid.

This first child starts to read the infile and executes the first command.

This second child reads whats left from the last process, writes into outfile and executes the second command

At last close the fd, waitpid and free our struct.

Helpful links:
https://stackoverflow.com/questions/1720535/practical-examples-use-dup-or-dup2
https://www.geeksforgeeks.org/fork-system-call/?ref=lbp

fd:
0 -----> read-only
1 -----> write-only