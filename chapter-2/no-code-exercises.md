
### Exercise 2.1
> What are the differences between int, long, long long, and short? Between an unsigned and a signed type? Between a float and a double?

#### Number of Bits
1. `short` - at least 16 bits.
2. `int` - at least 16 bits for older specialized systems, however it's at least 32 bits on most modern system architectures.
3. `long` - at least 32 bits.
4. `long long` - at least 64 bits.
5. `float` - exactly 32 bits on most system architectures (x86, x64, ARM, etc) which means they can represent IEEE single-precision floating point numbers.
6. `double` - more precise than a float (64 bits), and can represent IEEE double-precision floating point numbers.

#### Signed & Unsigned Types:
1. `signed` - this type can represent all types of numbers (positive, negative, zero).
2. `unsigned` - this type can only represent numbers greater or equal to to zero.

Note that there isn't any `unsigned float` or `unsigned double` variants in C++.

#### Usage:
1. `short` is usually too small for most integer arithmetic calculations. Use `int` instead. If the number at hand is going to be larger than the minimum guaranteed number of bits for an `int`, then just use `long long`. `int` and `long` in practice usually have the same size.
2. Most times, you wanna use `double` instead of `float` for floating-point computations as `float` has lower precision which means higher discrepancies between systems + larger inaccuracies. Furthermore, the cost of double-precision calculations are negligible compared to single-precision so might as well use `double`. On the other hand, `long double` precision is usually unnecessary and often entails considerable run-time cost.
3. Use `unsigned` if you can guarantee the value won't go below zero.

### Exercise 2.2
> To calculate a mortgage payment, what types would you use for the rate, principal, and payment? Explain why you selected each type.

1. **Rate** - `double` as it would include decimal points (e.g., 3.5%, 0.035) and the double-precision floating point value means we will minimize rounding errors that could accumulate over time. On the other hand, using `float` might lead to inaccuracies in financial computations due to its lower precision.
2. **Principal** - `unsigned long long`. The reason we don't use `unsigned int` is because it's numerical range is from 0 to approximately 4.3 billion. To be on the safe side, we want to account for mortgages that are really huge (larger than 4.3 billion), so we use `unsigned long long` (0 to 18.4 quintillion). Additionally, the principal is always a positive value, so `unsigned` is appropriate.
3. **Payment** - `double`, as this monthly figure is likely to have decimals (e.g., $1,234.56). We don't use `unsigned` just in case accidental overpayments occur which temporarily brings the payment value below zero.

### Exercise 2.3
> What output will the following code produce?

```
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;

int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;

std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
```

1. The first output will simply be `32`.
2. The second output will be a large positive integer as unsigned types can't be negative so the value will be wrapped over to the positive side. This would be 2^32 - 32 = `4294967264` on most systems.
3. The third output will be `32`.
4. The fourth output will be `-32`.
5. The fifth value will be `0`. Important to note that the signed variable `i` gets promoted to unsigned. This happens when performing operations between signed and unsigned types.
6. The sixth value will be `0`. Same as output 5.

### Exercise 2.5
> Determine the type of each of the following literals. Explain the differences among the literals in each of the four examples:

1. 'a', L'a', "a", L"a"
	- character literal (`char`, 1 byte)
	- wide character literal (`wchar_t`, 2-4 bytes depending on platform)
	- string literal (`char[2]`, 2 bytes, one for the character and one for the null terminator, `'\0'`)
	- wide string literal (`wchar_t[2], at least 4 bytes, but could be up to 8, depending on the platform)
2. 10, 10u, 10L, 10uL, 012, 0xC
	- decimal integer literal (`int`, 4 bytes, base 10)
	- decimal unsigned integer literal (`unsigned int`, 4 bytes, base 10)
	- long integer literal (`long`, 4-8 bytes, base 10)
	- unsigned long decimal integer literal (`unsigned long`, 4-8 bytes, base 10)
	- octal integer literal (`int`, prefix indicates that the number is in octal, or base 8)
	- hexadecimal integer literal (`int`, prefix indicates the number is in hexadecimal, or base 16)
3. 3.14, 3.14f, 3.14L
	- double (`double`, 8 bytes, double-precision floating point literal)
	- float (`float`, 4 bytes, single-precision floating point literal)
	- long double (`long double`, 8-16 bytes, depending on the plaform/system)
4. 10, 10u, 10., 10e-2
	- decimal integer literal (`int`, 4 bytes, base 10)
	- unsigned decimal integer literal (`unsigned int`, 4 bytes, base 10)
	- double (`double`, 8 bytes, double-precision floating point literal)
	- double (`double`, 8 bytes, double-precision floating point literal)

### Exercise 2.6
> What, if any, are the differences between the following definitions:

1. `int month = 9, day = 7;`
	- These are decimal integer literals in base 10.
	- Both are valid.
2. `int month = 09, day = 07;`
	- These are octal integer literals in base 8.
	- Octal integer literals range from 0-7, so `09` is not a valid octal integer.

### Exercise 2.7
> What values do these literals represent? What type does each have?

1. `"Who goes with F\145rgus?\012"`
	- string literal, with some octal escape sequences within it. Octal escape sequences have '\' followed by 1-3 numbers ranging from 0-7 (eg, \11 or \377).
	- \145 = F
	- \012 = \n
	- "Who goes with Fergus?\n"
2. `3.14e1L`
	- long double
	- 31.4
3. `1024f`
	- float
	- 1024.0
4. `3.14L`
	- long double
	- 3.14

### Exercise 2.9
> Explain the following definitions. For those that are illegal, explain what’s wrong and how to correct it.

1. `std::cin >> int input_value;`
	- Not okay, you can't declare a variable straight from an input statement.
2. `int i = { 3.14 };`
	- This uses list initialization, which means that the compiler will throw an error since 3.14 is not an integer.
3. `double salary = wage = 9999.99;`
	- Not okay, the variable `wage` isn't declared before it's used.
	- We need another line to declare `wage` before this line -> `double wage`.
4. `int i = 3.14;`
	- The is legal but will involve a narrowing conversion which will round down the value to 3.

### Exercise 2.10
> What are the initial values, if any, of each of the following variables?

```
std::string global_str;
int global_int;

int main() {
	int local_int;
	std::string local_str;
}
```

1. `global_str` => ""
2. `global_int` => 0
3. `local_int` => uninitialized
4. `local_str` => ""

Global variables in C++ are automatically initialized. Class types like those from `std::string` usually have constructors that ensure they are properly initialized, unlike built-in types.

### Exercise 2.11
> Explain whether each of the following is a declaration or a definition:

1. `extern int ix = 1024;`
	- definition, 1024 is explicitly assigned so it overrides the `extern`. Therefore, memory is allocated for `ix`.
2. `int iy;`
	- definition, no value is assigned to `iy` unless this is done in the global scope, in which case the default value `0` will be assigned. Regardless, memory will be allocated to `iy`.
3. `extern int iz;`
	- declaration, no memory is allocated since `extern` is used. This tells the compiler that `iz` is declared somewhere else (possibly in another file).

### Exercise 2.12
> Which, if any, of the following names are invalid?

1. `int double = 3.14;` => invalid.
2. `int _;` => valid, but not good practice.
3. `int catch-22;` => invalid, dashes aren't allowed.
4. `int 1_or_2 = 1;` => invalid, can't start with a digit.
5. `double Double = 3.14;` => valid, but not good practice.

### Exercise 2.13
> What is the value of j in the following program?

```
int i = 42;

int main() {
	int i = 100;
	int j = i;
}
```

The value is 100.

### Exercise 2.14
> Is the following program legal? If so, what values are printed?

```
int i = 100, sum = 0;

for (int i = 0; i != 10; ++i)
    sum += i;

std::cout << i << " " << sum << std::endl;
```

The program will print `100 45`.
