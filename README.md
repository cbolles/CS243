# Welcome
Welcome to my SI session and to The Mechanics of Programming in general! Feel free to use the resources in this repository in your quest to succeed in The Mechanics of Programming.

# Table of Contents
* [About Me](#aboutme)
* [How to Use This Repository](#usingrespository)
* [Resources/Tools](#resources)
  * [Vim](#vim) 
  * [Tmux](#tmux)
  * [GDB](#gdb)
  * [Valgrind](#valgrind)

# <a name="aboutme"></a>About Me
My name is Collin Bolles. I am a second year CS student at RIT. I am currently the
treasurer for Engineers for a Sustainable World and a member of the firmware team on the
Electric Vehicle Team. Love to read, especially science-fiction and fantasy, currently
looking for a new book series. I love learning new things about just about anything.

# <a name="usingrepository"></a>How to Use This Repository
The goal of this repository is to provide you with examples, practice problems, and
resources to make the class easier. I will not be putting up solutions or code snippets
that you can use in your homework assignments. Doing so is against the
[RIT Academic Integrity Policy](https://www.rit.edu/academicaffairs/policiesmanual/d080) 
and can have serious consequences.

Use the tools in here to help deepen your understanding, fill in any gaps, and practice
what you have learned. Throughout the year I will update the repository with examples
and practice problems that you can use. 

# <a name="resources"></a>Resources

## <a name="vim"></a>Vim
For editing files, I recommend using Vim. Vim is really powerful and very common among
the more "hardcore" developers. I will be writing (most) things in Vim.

The benefit of using Vim is that out of the box it has no autocomplete and code formatting
which means you have to learn how to write good c code on your own, like you will have to
on the final.

Here are some resources you can use to learn/get better with Vim.
* [Cheat Sheet 1](https://vim.rtorr.com/)
* [Cheat Sheet 2](https://devhints.io/vim)
* [Using Vim Tutor](https://thoughtbot.com/blog/the-vim-learning-curve-is-a-myth)

## <a name="tmux"></a>Tmux
You will quickly start to find switching between ssh sessions painful when you need to
access multiple files at once. I suggest using Tmux if you are feeling comfortable with
learning a new tool.

Full disclosure, this is completely optional and not meant to confuse you. If tmux isn't
making sense to you, don't let it confuse you.

Tmux lets you move between windows and panes from the command line so that you can work on
multiple things at once without having to close and reopen things

![Tmux Example](https://global-uploads.webflow.com/5c741219fd0819aad790e78b/5c9bb52c27e0bf0bd4a9808a_tmux-vim-style-nav-with-fzf.gif)

[Credits](https://www.bugsnag.com/blog/tmux-and-vim)

Here are some cheat sheets and ways to learn tmux. Note tmux is installed by default on 
all lab machines. Don't try to install it again
* [Cheat Sheet](https://tmuxcheatsheet.com/)
* [Tmux Tutorial](https://www.hamvocke.com/blog/a-quick-and-easy-guide-to-tmux/)

## <a name="gdb"></a>GDB
GDB is the GNU Project Debugger and is used for debugging from the command line. GDB has a lot of the features that you may have
already used in Java and Python just from the command line.

Using GDB is something that I wished I had learned more, but I always debugged using the "print shotgun" approach with is pretty
slow. I would recommend learning more about it and use it during homeworks/projects.

Here is some more information on GDB, cheat sheets, and other information.
* [GDB Main Page](https://www.gnu.org/software/gdb/)
* [GDB Cheat Sheet](https://kapeli.com/cheat_sheets/GDB.docset/Contents/Resources/Documents/index)
* [GDB Command Details](https://betterexplained.com/articles/debugging-with-gdb/)

## <a name="valgrind"></a>Valgrind
Valigrind  will be an extremely important tool for the rest of the semeseter. Even if you don't end up using gdb, you will need  to 
use valgrind. Valgrind tells you when you did something wrong with memory management which will happen A LOT. Homework assignments
will all require you to correctly use dynamic memory so valgrind will be your friend.

Most of the features of valgrind we will not use in the class. We will be using the memory check functionality a lot. Really all you
need to know about valgrind is running memory check using the following command.

```
valgrind --leak-check=full ./<my_program>
```
