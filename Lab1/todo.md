# Lab 1 Todo

In homework you are to write in C your own static library for dynamic allocation using freelists.

You should write this library in standard C99 on a Linux/Unix system using mmap. 

The library should allocate (i.e., malloc) and deallocate (i.e., free).

It does not have support growing the “heap” if out of memory (make the default mmap large enough to do a few mallocs). 

The first Fit strategy for selection is fine to use.

Freeing memory should only combine segments if they are right next to each other.

No need to recursively combine segments as this is just a toy library.  

# References

The mmap heap initialization is located on page 173 in Operating System: 3 Easy Pieces

# ~~Read vm-api~~

This explains how to use the memory api in c

# Read vm-freespace

This explains how to use freelist

#  ~~Read mmap man~~

https://man7.org/linux/man-pages/man2/mmap.2.html

# Read how to create static libraries

https://tldp.org/HOWTO/Program-Library-HOWTO/static-libraries.html
https://medium.com/@eightlimbed/how-to-create-and-use-a-c-static-library-eec33d502aeb
