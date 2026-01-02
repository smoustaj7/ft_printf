# 🖨️ ft_printf

## 📌 Description
**ft_printf** is a custom implementation of the C standard library function `printf`.  
The objective of this project is to recreate the core behavior of `printf` using only authorized functions, in order to better understand **variadic functions**, **format parsing**, and **low-level output handling**.

This project is part of the 42 curriculum and focuses on writing clean, modular, and efficient C code while respecting strict constraints.

---

## 🎯 Objectives
- Reproduce the behavior of the standard `printf`
- Understand and use variadic functions (`va_list`)
- Parse and handle formatted strings
- Manage output using low-level system calls
- Improve code organization and readability

---

## ⚙️ Supported Conversions

| Specifier | Description |
|----------|-------------|
| `%c` | Print a single character |
| `%s` | Print a string |
| `%p` | Print a pointer address |
| `%d` | Print a decimal number |
| `%i` | Print an integer |
| `%u` | Print an unsigned integer |
| `%x` | Print a hexadecimal number (lowercase) |
| `%X` | Print a hexadecimal number (uppercase) |
| `%%` | Print a percent sign |

---

## 🛠️ Allowed Functions
- `write`
- `malloc`
- `free`
- `va_start`
- `va_arg`
- `va_end`
- `va_copy`

Use of `printf` or any related standard library functions is strictly forbidden.

---

## 📂 Project Structure

