# Libft: Create a library of basic C functions
 
 This project aims to redo in C a library of usual functions that can be used in the next projects of 42.
 ## List of functions:

 ### Functions from `<ctype.h>`
- isalnum: checking for an alphanumeric character
- isalpha: checking for an alphabetic character
- isascii: checking for an ASCII character
- isdigit: checking for a digit (0 through 9)
- isprint: checking for any printable character
- tolower: converting char to lowercase
- toupper: converting char to uppercase

 ### Functions from `<string.h>`
- bzero: writing zeroes to a byte string
- memchr: locating byte in byte string
- memcmp: comparing byte string
- memcpy: copying memory area
- memmove: copying byte string
- memset: filling a byte string with a byte value
- strchr: locating the first occurance of a character in a string
- strdup: saving a copy of a string
- strlcat: concatenating a string to a specific size
- strlcpy: copying a string to a specific size
- strlen: calculating the length of a string
- strncmp: comparing strings up to a limit of characters
- strnstr: locating a substring in a string
- strrchr: locating the last occurance of a character in a string

 ### Functions from `<stdlib.h>`
- atoi: turning a string into an integer
- calloc: allocating contiguous memory and sets its bytes' values to 0

### Non-standard functions
- itoa: turning an integer into a string
- putchar_fd: outputing a char to a file descriptor
- putendl_fd: outputing a string to a file descriptor, followed by a new line
- putnbr_fd: outputing a number to a file descriptor
- putstr_fd: outputing a string to a file descriptor
- split: spliting a string using a char as parameter
- striteri: applying a function to each character of a string
- strjoin: concatenating two strings
- strmapi: applying a function to each character of a string and returning a modified string
- strtrim: triming the beginning and end of a string with a specific set of chars
- substr: returning a substring from a string

### Linked list functions
- lstadd_back: adding an element to the back of a linked list
- lstadd_front: adding an element to the front of a linked list
- lstclear: deleting all elements of a linked list
- lstdelone: deleting one element of a linked list
- lstiter: iterating over a linked list, applying a function to each element
- lstlast: returning last element of a linked list
- lstmap: iterating over a linked list, applying a function to each element and returning a new list
- lstnew: creating a new element in a linked list
- lstsize: getting the number of elements of a linked list
