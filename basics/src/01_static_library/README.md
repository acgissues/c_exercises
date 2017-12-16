# Static Library

Static libraries are introduced into the binary at compile-time, just as any
other object file.

## Steps

1. Compile all .c files.

2. Pack object files from the headers into a library (.a) file.
        ```
        ar rcs libmath.a add.o mult.o
        ```

3. Link files an create binary.
        ```
        gcc main.o libmath.a -o main
        ```
