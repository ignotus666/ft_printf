_This project has been created as part of the 42 curriculum by dahanlon._

## Description

**ft_printf** is a custom implementation of the standard C library function `printf` from `<stdio.h>`. 

The objective of this project is to explore and recreate one of C's most versatile I/O functions from the ground up. It handles formatted output by parsing a template string, extracting variable arguments, converting various data types (characters, strings, numbers, memory addresses) into printable text, and writing them directly to standard output.

Just like the original `printf`, `ft_printf`:
* Prints formatted output to standard output (`stdout`).
* Returns the **total count of characters written**, or `-1` if an output error occurs.
* Gracefully handles edge cases, such as `NULL` pointers, negative numbers, and boundary limits.

### Supported Conversions

| Specifier | Argument Type | Description |
| :---: | :--- | :--- |
| **`%c`** | `char` | Prints a single character. |
| **`%s`** | `char *` | Prints a string of characters (or `(null)` if pointer is `NULL`). |
| **`%p`** | `void *` | Prints a pointer address in hexadecimal format (prefixed with `0x`, or `(nil)` if `NULL`). |
| **`%d`** / **`%i`** | `int` | Prints a signed decimal integer (base 10). |
| **`%u`** | `unsigned int` | Prints an unsigned decimal integer (base 10). |
| **`%x`** | `unsigned int` | Prints a number in lowercase hexadecimal (base 16). |
| **`%X`** | `unsigned int` | Prints a number in uppercase hexadecimal (base 16). |
| **`%%`** | *None* | Prints a literal percent sign (`%`). |

## Instructions

### Prerequisites
* A Unix-based environment (Linux or macOS)
* `gcc` or `clang` compiler
* `make` (GNU Make)

### Compilation
The project includes a multi-rule `Makefile` to automate compilation without relinking. 

* **Compile the mandatory library:**
  ```bash
  make
  ```
* **Clean object files (`.o`):**
  ```bash
  make clean
  ```
* **Clean object files and the `libftprintf.a` library:**
  ```bash
  make fclean
  ```
* **Re-compile the entire project from scratch:**
  ```bash
  make re
  ```

### Installation & usage
To use this library in your own C projects, follow these steps:

1. **Clone or copy** this repository into your project directory.
2. **Compile the library** using `make`.
3. **Include the header** in your C files:
   ```c
   #include "ft_printf.h"
   ```
4. **Compile your project** while linking the static library:
   ```bash
   gcc main.c -L. -lftprintf -o my_program
   ```
   *(Note: `-L.` tells the compiler to look for the library in the current directory, and `-lftprintf` links `libftprintf.a`)*

---

## Algorithm

### 1. Parsing

- The the first argument is scanned character by character.
- Regular characters are written directly to standard output (`write(1, ...)`).
- When a `%` character is found, the code checks the following character (`fmt_str[i + 1]`) and calls a helper function to process it (`print_and_return_len`), checking to see if the specifier is valid and if it is, printing out the corresponding argument in the specified format via additional helper functions and returning the number of chars printed.
- The code increments past the specifier and continues checking the format string.

---

### 2. Numerical conversion
To format integers (`%d`, `%i`, `%u`), hexadecimal numbers (`%x`, `%X`), and pointer addresses (`%p`), the project uses **recursive decomposition**:

- **Order of execution**: Numbers are extracted from right to left (via `% base`), but must be printed left to right. Recursion reverses this order without requiring dynamic memory (`malloc`) or intermediate string buffers.
- **Base Conversion**: Hexadecimal conversions (`%x`, `%X`, `%p`) reuse the same recursive logic by operating in base 16 rather than base 10.

### Justification

The design of both the parser and numerical conversion prioritises **simplicity and zero heap allocation:**

* **Efficiency & predictability (parsing)**: A single-pass scanner processes the format string and writes characters as soon as they are encountered.
* **Memory safety & no leaks (Numerical Conversion)**: Performing base conversion recursively eliminates the need for dynamic memory allocation (`malloc`/`free`), removing any risk of memory leaks, allocation failures, or heap fragmentation. Because the maximum depth of recursion is limited by the data type's bit width, the stack footprint remains negligible.

---

### 3. Data Structures Used

While `ft_printf` does not require complex structures like linked lists, it relies on several key constructs:

#### A. Variadic list (`va_list` from `<stdarg.h>`)
* **Usage**: `va_start`, `va_arg`, `va_end`.
* **Justification**: Standard C mechanism to handle an arbitrary number of parameters of varying types.

#### B. Lookup tables (Base arrays)
* **Usage**: Constant character tables for hexadecimal conversion (`"0123456789abcdef"` and `"0123456789ABCDEF"`).
* **Justification**: Direct index mapping (`base[nbr % 16]`) provides character conversion without conditional branching (`if (nbr >= 10)`), keeping the code clean and fast.

---

### 4. Error handling & return values
Every output operation (`write`) is verified immediately:
* If any `write` call fails (returns `-1`), the error is sent up immediately through the call chain.
* On success, each sub-function returns the exact count of bytes it wrote, accumulating into the total returned length.


---

## Resources & AI Disclosure

### References & Documentation
* [Linux Man Pages](https://man7.org) - Used to verify standard libc behaviors, return values, and edge cases.

### AI Usage Disclosure
* AI was used to structure this `README.md` file and add some markdown styling.