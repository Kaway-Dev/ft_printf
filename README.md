*This project has been created as part of the 42 curriculum by phkaway-.*

# ft_printf

## Description

`ft_printf` is a reimplementation of the standard C library function `printf`.

The goal of this project is to understand variadic functions in C, formatted output, type handling, number-base conversion, recursion, pointers, and static libraries.

The project produces a static library named `libftprintf.a` and provides the following function:

```c
int	ft_printf(const char *fmt, ...);
```

The function reads a format string, processes supported conversion specifiers, prints the corresponding arguments to the standard output, and returns the total number of characters printed.

Unlike the original `printf`, this implementation does not use buffer management. Every character is written directly to the standard output using `write`.

## Supported conversions

| Conversion | Description |
|---|---|
| `%c` | Prints a single character |
| `%s` | Prints a null-terminated string |
| `%p` | Prints a pointer address in hexadecimal format |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed decimal integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints an unsigned integer in lowercase hexadecimal |
| `%X` | Prints an unsigned integer in uppercase hexadecimal |
| `%%` | Prints a percent sign |

## Project structure

```text
ft_printf/
├── Makefile
├── README.md
├── ft_printf.h
├── ft_printf.c
├── ft_print_char_str.c
├── ft_print_numbers.c
└── ft_print_hex_ptr.c
```

### File responsibilities

- `ft_printf.c`: reads the format string, initializes the variadic argument list, identifies conversions, and dispatches each conversion to the appropriate function.
- `ft_print_char_str.c`: prints individual characters and strings.
- `ft_print_numbers.c`: prints signed and unsigned decimal integers.
- `ft_print_hex_ptr.c`: prints hexadecimal values and pointer addresses.
- `ft_printf.h`: contains the public function prototypes and required includes.
- `Makefile`: compiles the source files and creates `libftprintf.a`.

## Algorithm and implementation

### Format-string parsing

The format string is processed from left to right in a single pass.

For each position:

1. If the current character is not `%`, it is printed directly.
2. If the current character is `%`, the following character is treated as a conversion specifier.
3. The parser selects the appropriate printing function.
4. The corresponding argument is retrieved from the variadic argument list.
5. The number of printed characters is added to the total count.

For a normal character, the index advances by one position.

For a conversion such as `%d`, the index advances by two positions because both `%` and the conversion character were consumed.

The parsing complexity is linear relative to the number of processed characters: `O(n)`.

### Variadic arguments

The project uses the macros provided by `<stdarg.h>`:

- `va_list` stores the state of the variadic argument list.
- `va_start` initializes the list after the last fixed argument.
- `va_arg` retrieves each argument using its expected type.
- `va_end` releases the variadic argument-list state.

Example:

```c
va_list	args;

va_start(args, fmt);
```

The parser receives the address of this list so that every conversion consumes arguments from the same sequence.

| Conversion | Type read with `va_arg` |
|---|---|
| `%c` | `int` |
| `%s` | `char *` |
| `%p` | `void *` |
| `%d`, `%i` | `int` |
| `%u`, `%x`, `%X` | `unsigned int` |

A character is retrieved as an `int` because values narrower than `int`, such as `char`, undergo default argument promotion when passed to variadic functions.

### Decimal-number conversion

Signed and unsigned numbers are printed recursively.

For a decimal number greater than or equal to `10`:

1. The function recursively prints `n / 10`.
2. It prints the last digit using `n % 10`.
3. The digit is converted to a character by adding `'0'`.

Example for `42`:

```text
42 / 10 = 4
42 % 10 = 2
```

The recursive call prints `4`, and the current call prints `2`.

Signed integers are internally copied to a `long`. This allows the implementation to safely handle `INT_MIN`, because the positive equivalent of `-2147483648` cannot be represented by an `int`.

### Hexadecimal conversion

Hexadecimal conversion uses division and remainder by `16`.

The following strings are used as lookup tables:

```text
0123456789abcdef
0123456789ABCDEF
```

The remainder of `n % 16` becomes an index in the selected lookup table.

For decimal `26`:

```text
26 / 16 = 1
26 % 16 = 10
```

Index `10` in the lowercase hexadecimal base is `a`, so the result is `1a`.

The same recursive algorithm is used for `%x` and `%X`, with only the lookup table changing.

### Pointer conversion

The `%p` conversion receives a `void *`.

The pointer is converted internally to `unsigned long`, allowing the address to be processed as an unsigned numeric value.

A valid pointer is printed with the `0x` prefix followed by its lowercase hexadecimal representation.

A null pointer is printed as `(nil)`, matching the behavior of the system `printf` used during development and testing.

### Strings and null pointers

Strings are printed one character at a time.

When `%s` receives a null pointer, the implementation prints `(null)`.

This prevents an invalid memory access and matches the behavior of the reference `printf` in the development environment.

### Return value

Every helper function returns the number of characters it printed.

The main `ft_printf` function accumulates these values and returns the final total.

For example:

```c
ft_printf("Hello %c", 'A');
```

prints seven characters and returns `7`.

The return value counts the actual output, not the number of characters in the original format string.

### Data structures and memory management

No custom data structure is required for this implementation.

The project uses:

- the format string and an integer index to parse input;
- a `va_list` to access variadic arguments;
- recursive function calls for decimal and hexadecimal conversion;
- integer counters to track the number of printed characters.

No dynamic memory allocation is used.

Although `malloc` and `free` are authorized by the subject, this implementation prints values directly instead of creating temporary allocated strings. This avoids unnecessary allocations, simplifies memory management, and eliminates allocation-related memory leaks.

`va_copy` is also authorized but unnecessary because the argument list is traversed only once.

## Instructions

### Requirements

- A C compiler such as `cc`
- `make`
- A Unix-like operating system
- The 42 Norminette for style validation

### Compilation

Run:

```bash
make
```

This creates:

```text
libftprintf.a
```

### Available Makefile rules

| Rule | Effect |
|---|---|
| `make` or `make all` | Compiles the source files and creates `libftprintf.a` |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and `libftprintf.a` |
| `make re` | Runs `fclean` and recompiles the library |

### Using the library

Create a test file:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Character: %c\n", 'A');
	ft_printf("String: %s\n", "Hello");
	ft_printf("Number: %d\n", -42);
	ft_printf("Hexadecimal: %x\n", 255);
	return (0);
}
```

Compile it with the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test
```

Run it:

```bash
./test
```

### Checking the Norm

```bash
norminette
```

### Checking memory errors

```bash
valgrind --leak-check=full --show-leak-kinds=all ./test
```

## Testing

The implementation was compared directly with the original `printf`.

The tests included:

- all mandatory conversions;
- multiple consecutive conversions;
- empty strings;
- null strings;
- valid and null pointers;
- `INT_MIN`;
- `INT_MAX`;
- `UINT_MAX`;
- zero;
- lowercase and uppercase hexadecimal;
- return-value comparison;
- Valgrind memory checks;
- repeated Makefile executions to verify that unnecessary recompilation does not occur.

Example tested output:

```text
C: A | S: Philippe | D: -42 | U: 4294967295 | x: ff | X: FF | %
```

The output and return values were compared with those of the original `printf`.

## Resources

### Documentation and references

- The C Programming Language — Brian Kernighan and Dennis Ritchie
- Linux manual pages:
  - `man 3 printf`
  - `man 3 stdarg`
  - `man 2 write`
  - `man 1 ar`
- cppreference — Variadic arguments and the C standard library
- GNU C Library documentation
- 42 Norm documentation and Norminette
- The official `ft_printf` subject provided by 42

### AI usage

AI was used as a guided learning and review tool during the project.

It was used for:

- explaining variadic functions and the roles of `va_list`, `va_start`, `va_arg`, and `va_end`;
- explaining decimal and hexadecimal recursive conversion;
- understanding pointer conversion and null-pointer behavior;
- planning edge-case tests and comparing behavior with the original `printf`;
- reviewing and organizing this README.

No code was generated by AI. All .c and .h source files were written manually to comply with 42 Norm requirements and to meet the pedagogical goals of the project.
