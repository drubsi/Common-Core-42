# Libft — Milestone 0

**Libft** is the first project of the *42 Common Core*.  
It consists of reimplementing essential functions from the C standard library, as well as additional utility functions.  
The main goal is to build a custom static library that will later be used in other projects.

---

## 📌 Project Objectives

- Understand how standard C library functions work internally.
- Work with dynamic memory, pointers, and data structures.
- Develop a reusable static library.

---

## 🛠️ Compilation

The library includes a `Makefile` with the following rules:

make        # Compiles the libft.a library  
make clean  # Removes .o files  
make fclean # Removes .o files and libft.a  
make re     # Rebuilds everything  

When compiled, the following file will be generated:

libft.a

Include the library header in your code:

```c
#include "libft.h"

Compile linking the library:

cc main.c -L. -lft -o program

📂 Library Contents
🔹 Memory Functions

ft_memset
ft_bzero
ft_memcpy
ft_memmove
ft_memchr
ft_memcmp
ft_calloc

🔹 String Functions

ft_strlen
ft_strlcpy
ft_strlcat
ft_strchr
ft_strrchr
ft_strncmp
ft_strnstr
ft_strdup
ft_substr
ft_strjoin
ft_strtrim
ft_split
ft_itoa
ft_strmapi
ft_striteri

🔹 Conversion Functions

ft_atoi

🔹 Character Functions

ft_isalpha
ft_isdigit
ft_isalnum
ft_isascii
ft_isprint
ft_toupper
ft_tolower
ft_isspace

🔹 Output Functions

ft_putchar_fd
ft_putstr_fd
ft_putendl_fd
ft_putnbr_fd

🟦 Bonus (optional)

Implementation of a simple linked list:

ft_lstnew
ft_lstadd_front
ft_lstsize
ft_lstlast
ft_lstadd_back
ft_lstdelone
ft_lstclear
ft_lstiter
ft_lstmap


# Libft — Milestone 0

**Libft** es el primer proyecto del *Common Core* de 42.  
Consiste en reimplementar un conjunto de funciones esenciales de la librería estándar de C, así como otras utilidades adicionales.  
El objetivo principal es construir una librería estática propia que después será usada en proyectos posteriores.

---

## 📌 Objetivos del proyecto

- Comprender cómo funcionan internamente las funciones estándar de C.
- Trabajar con memoria dinámica, punteros y estructuras.
- Desarrollar una librería estática reutilizable.

---

## 🛠️ Compilación

La librería incluye un `Makefile` con las reglas:

make        # Compila la librería libft.a
make clean  # Elimina los archivos .o
make fclean # Elimina los .o y libft.a
make re     # Reconstruye todo

Al compilar, se generará:

libft.a

Incluye el header de la librería:

#include "libft.h"


Y compila enlazando la librería:

cc main.c -L. -lft -o programa

📂 Contenido de la librería
🔹 Funciones de memoria

ft_memset

ft_bzero

ft_memcpy

ft_memmove

ft_memchr

ft_memcmp

ft_calloc

🔹 Funciones de strings

ft_strlen

ft_strlcpy

ft_strlcat

ft_strchr

ft_strrchr

ft_strncmp

ft_strnstr

ft_strdup

ft_substr

ft_strjoin

ft_strtrim

ft_split

ft_itoa

ft_strmapi

ft_striteri

🔹 Funciones de conversión

ft_atoi

🔹 Funciones de caracteres

ft_isalpha

ft_isdigit

ft_isalnum

ft_isascii

ft_isprint

ft_toupper

ft_tolower

ft_isspace

🔹 Funciones de escritura

ft_putchar_fd

ft_putstr_fd

ft_putendl_fd

ft_putnbr_fd

🟦 Bonus (opcional)

Implementación de una lista enlazada simple:

ft_lstnew

ft_lstadd_front

ft_lstsize

ft_lstlast

ft_lstadd_back

ft_lstdelone

ft_lstclear

ft_lstiter

ft_lstmap
