# Printf Subject

Assignment name  : ft_printf <br />
Expected files   : ft_printf.c <br />
Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end <br />
-------------------------------------------------------------------------------- <br />

Write a function named `ft_printf` that will mimic the real printf but 
it will manage only the following conversions:

s (string), d (decimal) and x (lowercase hexademical). 


Your function must be declared as follows:

<br /> int ft_printf(const char *, ... );

Before you start we advise you to read the `man 3 printf` and the `man va_arg`.<br />
To test your program compare your results with the true printf.


<br /> Examples of the function output:

call: ft_printf("%s\n", "toto"); <br />
out: toto$

call: ft_printf("Magic %s is %d", "number", 42); <br />
out: Magic number is 42%

call: ft_printf("Hexadecimal for %d is %x\n", 42, 42); <br />
out: Hexadecimal for 42 is 2a$
