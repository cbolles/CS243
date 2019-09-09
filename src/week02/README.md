# Intro
During week 2, we looked more at the C language, it's similarities and differences with Python and Java, how to accomplish some basic tasks. Included are some basic examples,
and some examples of more specific concepts that were discussed in class.

# Goal
The goal of this section is to re-enforce some of the basic concepts of C and to provide
examples of some of the unique aspects of C.

# Working with Multiple Files
In the multiple files folder, there is an example of using a function defined in another file. There are a couple of important points in the
example that were discussed in class. I also noted some things that will be important later in the course.

## Using -c vs -o
In the example, as in class, -c and -o are used at different points. Using -c compiles the code, creating an object file, but doesn't link
files. 

To see the importance of this run the command `gcc -Wall -Wextra -pedantic -std=c99 -c main.c` in multiple\_files. You should see
no error, which seems a little odd "what about the getArea function?".

Using -c stops before linking, so gcc isn't interested in finding where getArea is actually defined. However after running
`gcc -Wall -Wextra -pedantic -std=c99 -o main main.c` we get an error! -o is trying to connect the pieces, but getArea is not found.  

# Using Arrays
Arrays work a lot like arrays (not lists) in Java. They are created with a fixed size
that can be interacted with using an index.

There are some differences with Java however, C doesn't have the same safety nets as Java
which you can see in the examples.

# Some IO
getchar is one of the fundamental functions to get input from a file. An interesting thing about working with Unix/Linix is that just about everything is a file (including the
input from the command line). getchar is used to get a single character from the input one at a time. You can keep calling it while there are characters to be read. 

The end of a file has a special symbol in C `EOF` which stands for `end of file`. This comes up at the end of a file or when a user types in `CONTROL-D`.
