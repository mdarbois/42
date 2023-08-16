# Libft: Create a library of basic C functions
 
 This project aims to redo in C a library of usual functions that can be used in the next projects of 42.
 ## List of functions:

 ### Functions from `<ctype.h>`
- [isalnum](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_isalnum.c): checking for an alphanumeric character
- [isalpha](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_isalpha.c): checking for an alphabetic character
- [isascii](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_isascii.c): checking for an ASCII character
- [isdigit](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_isdigit.c): checking for a digit (0 through 9)
- [isprint](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_isprint.c): checking for any printable character
- [tolower](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_tolower.c): converting char to lowercase
- [toupper](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_toupper.c): converting char to uppercase

 ### Functions from `<string.h>`
- [bzero](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_bzero.c): writing zeroes to a byte string
- [memchr](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_memchr.c): locating byte in byte string
- [memcmp](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_memcmp.c): comparing byte string
- [memcpy](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_memcpy.c): copying memory area
- [memmove](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_memmove.c): copying byte string
- [memset](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_memset.c): filling a byte string with a byte value
- [strchr](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_strchr.c): locating the first occurance of a character in a string
- [strdup](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_strdup.c): saving a copy of a string
- [strlcat](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_strlcat.c): concatenating a string to a specific size
- [strlcpy](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_strlcpy.c): copying a string to a specific size
- [strlen](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_strlen.c): calculating the length of a string
- [strncmp](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_strncmp.c): comparing strings up to a limit of characters
- [strnstr](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_strnstr.c): locating a substring in a string
- [strrchr](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_strrchr.c): locating the last occurance of a character in a string

 ### Functions from `<stdlib.h>`
- [atoi](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_atoi.c): turning a string into an integer
- [calloc](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_calloc.c): allocating contiguous memory and sets its bytes' values to 0

### Non-standard functions
- [itoa](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_itoa.c): turning an integer into a string
- [putchar_fd](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_putchar_fd.c): outputing a char to a file descriptor
- [putendl_fd](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_putendl_fd.c): outputing a string to a file descriptor, followed by a new line
- [putnbr_fd](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_putnbr_fd.c): outputing a number to a file descriptor
- [putstr_fd](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_putstr_fd.c): outputing a string to a file descriptor
- [split](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_split.c): spliting a string using a char as parameter
- [striteri](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_striteri.c): applying a function to each character of a string
- [strjoin](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_strjoin.c): concatenating two strings
- [strmapi](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_strmapi.c): applying a function to each character of a string and returning a modified string
- [strtrim](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_strtrim.c): triming the beginning and end of a string with a specific set of chars
- [substr](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_substr.c): returning a substring from a string

### Linked list functions
- [lstadd_back](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_lstadd_back_bonus.c): adding an element to the back of a linked list
- [lstadd_front](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_lstadd_front_bonus.c): adding an element to the front of a linked list
- [lstclear](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_lstclear_bonus.c): deleting all elements of a linked list
- [lstdelone](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_lstdelone_bonus.c): deleting one element of a linked list
- [lstiter](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_lstiter_bonus.c): iterating over a linked list, applying a function to each element
- [lstlast](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_lstlast_bonus.c): returning last element of a linked list
- [lstmap](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_lstmap_bonus.c): iterating over a linked list, applying a function to each element and returning a new list
- [lstnew](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_lstnew_bonus.c): creating a new element in a linked list
- [lstsize](https://github.com/mdarbois/42/blob/main/0.0%20Libft/src/ft_lstsize_bonus.c): getting the number of elements of a linked list
