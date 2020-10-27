# PRINTF
![illustration](https://i.pinimg.com/originals/b4/c2/63/b4c26302a83ea0f06a4f649c0c61ee52.jpg)
## Context of this project and notions seen
This project was did the 27th october 2020.
<br /> This is a project of HOLBERTON school, we had only five days to do it. 
<br /> Warning this **printf** not handle flag format of printf (for now).  
#### Notions 
 1. **Variadic Functions** 
  * *va_start()*
  * *va_end()*
  * *va_arg()*
 2. **Pointer of Functions**
 3. **Structure**
 4. **Typedef**
 5. **Recursivity**
 6. **Memory allocation**
 7. **Working on same repository Github**
 8. **Delegate tasks**
 9. **Respect of deadline**

## What is printf 
Printf is a function in C that write output to stdout, taking arguments [%] in order that they were asked.
<br /> Printf return the number of characters printed. 
![Printf_arguments](https://upload.wikimedia.org/wikipedia/commons/thumb/2/2c/Printf.svg/1280px-Printf.svg.png)
[Source](https://fr.wikipedia.org/wiki/Printf#/media/Fichier:Printf.svg)
## Manage the following conversions: 
 ##### Accessible with **%** before 
  - -**c** ```print a character``` 
  - -**d** ```print a decimal number```
  - -**i** ```print an integer``` 
  - -**s** ```print a string```
  - -**u** ```print an unsigned integer``` 
  - -**x** ```convert an unsigned int into a hexadecimal && print```
  - -**o** ```convert an unsigned int into an octal && print``` 
  - -**X** ```convert an unsigned int into a hexadecimal UPPERCASE && print```
  - -**r** ```reverse a string && print```
  - -**R** ```convert a string into format ROT13 && print```
  - -**S** ```print a non printable string into \x*hexadecimal*```
  - -**p** ```print the adress of a pointer in hexadecimal```
  - -**%** ```print a simple %```
 
## COMPILE WITH OUR  _PRINTF
* ``` #include "holberton.h" ```
* ``` $ gcc -Wall -Werror -Wextra -pedantic *.c -o the_best_printf ```
* ``` $ ./the_best_printf ```

## Examples 
```
_printf("%s", "my string"); result : my string
```
```
_printf("%d", 125); result : 125
```
```
_printf("%%"); result : %
```

  
  This project was done by [Ophelie](https://github.com/fourbet)  && Thibaut. 
