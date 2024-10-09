
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
	- integer literal (`int`, 4 bytes)
	- unsigned integer literal (`unsigned int`, 4 bytes)
	- long integer literal (`long`, 4-8 bytes)
	- unsigned long integer literal (`unsigned long`, 4-8 bytes)
	- octal integer literal (`int`, prefix indicates that the number is in octal, or base 8)
	- hexadecimal integer literal (`int`, prefix indicates the number is in hexadecimal, or base 16)
3. 3.14, 3.14f, 3.14L
	- double (`double`, 8 bytes, double-precision floating point literal)
	- float (`float`, 4 bytes, single-precision floating point literal)
	- long double (`long double`, 8-16 bytes, depending on the plaform/system)
4. 10, 10u, 10., 10e-2
	- integer literal (`int`, 4 bytes)
	- unsigned integer literal (`unsigned int`, 4 bytes)
	- double (`double`, 8 bytes, double-precision floating point literal)
	- double (`double`, 8 bytes, double-precision floating point literal)