
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

### Exercise 2.15
> Which of the following definitions, if any, are invalid? Why?

1. int ival = 1.01; => valid, however the value 1.01 is a double so the value will be implicitly truncated to 1, so there is a loss of precision.
2. int &rval1 = 1.01; => invalid, can only bind an int reference to an int object, not to a double or a temporary value.
3. int &rval2 = ival; => valid, binds the reference rval2 to the existing variable ival.
4. int &rval3; => invalid => invalid, references must be initialized when they are declared, they cannot exist without pointing to an object.

### Exercise 2.16
> Which, if any, of the following assignments are invalid? If they are valid, explain what they do.

```
int i = 0, &r1 = i;
double d = 0, &r2 = d;
```

1. r2 = 3.14159; => valid, here we are basically setting the variable d to 3.14159.
2. r2 = r1; => valid, however since r1 is a reference to integer object i, the value of i will be implicitly converted into a double.
3. i = r2; => valid, since i in an integer, the value of d will be implicitly truncated into an integer, resulting in loss of precision.
4. r1 = d; => invalid, you cannot assign a double to an integer reference directly without casting.

When assigning to references, the types must match exactly because a reference directly refers to an object of a specific type.

### Exercise 2.17
> What does the following code print?

```
int i, &ri = i;
i = 5;
ri = 10;
std::cout << i << " " << ri << std::endl;
```

This will print "10 10".

### Exercise 2.19
> Explain the key differences between pointers and references.

- Pointers are variables that have their own memory addresses. They can point to the address space of another object. The address that a pointer points to can be re-assigned (assuming they are not `const` pointers) and they can also point to `nullptr` to indicate that they are not currently pointing to any valid object.
- References are not variables themselves, and therefore don't have their own memory addresses. They are binded to other objects in order to refer to them, acting as an alias. Once a reference is initialized to an object, it cannot be re-assigned, and so references must be binded to a valid object upon initialization.

### Exercise 2.20
> What does the following program do?

```
int i = 42;
int *p1 = &i;
*p1 = *p1 * *p1;
```

This program initializes `i` to be an integer with a value of 42. It then defines a pointer `p1` to point to the address of `i`. The line `*p1 = *p1 * *p1;` dereferences `pi` to access the value of `i`. It then squares this value (42x42), which results in 1764.

### Exercise 2.21
> Explain each of the following definitions. Indicate whether any are illegal and, if so, why.

```
int i = 0;
(a) double* dp = &i;
(b) int *ip = i;
(c) int *p = &i;
```

- (a) This line initializes `dp` to be a pointer to a double object. However, this is illegal as `i` is an integer and a pointer to a double cannot be assigned an address of an integer without an explicit cast.
- (b) This line initialies `ip` to be a pointer to an integer object. This is illegal a pointer must point to a memory address, not a value.
- (c) This initializes `p` to be a pointer to an integer object. This is legal as it points to the memory address of `i`.

### Exercise 2.22
> Assuming p is a pointer to int, explain the following code:

```
if (p) // ...
if (*p) // ...
```

- The first line checks if `p` is NOT a null pointer, meaning it points to a non-null memory address. 
- The second line checks that the integer value of the object that `p` points to is anything but 0.

### Exercise 2.23
> Given a pointer p, can you determine whether p points to a valid object? If so, how? If not, why not?

If the if block for `if (p)` runs, then pointer `p` points to a non-null memory address. However, this does not verify the validity of the object it points to. In C++, there is no built-in way to determine whether the memory a pointer refers to is valid or has been deallocated. This is because pointers only store addresses and do not contain information about the memory's validity.

### Exercise 2.24
> Why is the initialization of p legal but that of lp illegal?

```
int i = 42;
void *p = &i;
long *lp = &i;
```

Assigning an `int` address to a `long` pointer is not allowed without an explicit cast due to incompatible types. However, a void pointer is able to point to an an address of any data type, including `int`. The downside is that a void pointer won't actually know the type of the object it points to and therefore it cannot be dereferenced without a cast.

### Exercise 2.25
> Determine the types and values of each of the following variables.

```
(a) int* ip, &r = ip;
(b) int i, *ip = 0;
(c) int* ip, ip2;
```

- (a) `ip` is a pointer to an integer. `r` is a `*int` reference that is bound to the pointer `ip`.
- (b) `i` is an integer. `ip` is an integer pointer that points to 0 (which means it's a null pointer, equivalent to `nullptr`)
- (c) `ip` is a pointer to an integer. `ip2` is simply an integer.

### Exercise 2.26
> Which of the following are legal? For those that are illegal, explain why.

```
(a) const int buf;
(b) int cnt = 0;
(c) const int sz = cnt;
(d) ++cnt;
(e) ++sz;
```

- (a) Illegal, as a const type must be initialized at the time of declaration.
- (b) Legal, `cnt` is initialized to 0.
- (c) Legal, `sz` is initialized to the value of `cnt`, which is 0.
- (d) Legal, `cnt` is now 1.
- (e) Illegal, you cannot modify the value of a const type.

### Exercise 2.27
> Which of the following initializations are legal? Explain why.

```
(a) int i = -1, &r = 0;
(b) int *const p2 = &i2;
(c) const int i = -1, &r = 0;
(d) const int *const p3 = &i2;
(e) const int *p1 = &i2;
(f) const int &const r2;
(g) const int i2 = i, &r = i;
```

- (a) Illegal. `i` is an integer with value -1. However, `r` is a reference, and references must be bound to a valid object- not a literal like `0`.
- (b) Legal if `i2` is an integer. `p2` is a const pointer that points to an integer, meaning the object it points to cannot change, but the value of that object can.
- (c) Illegal. `i` is a const int, which is valid, but `r` is an attempt to bind a reference to `0`. Since r is a reference to `const int`, it must be bound to an actual object, not a literal.
- (d) Legal if `i2` is a const int. `p3` has a top-level `const` and points to an integer of type `const int`, meaning neither the pointer nor the value it points to can be changed.
- (e) Legal if `i2` is a const integer. `p1` is a `const int` pointer that points to the memory address of `i2`, so value it points to cannot be modified, but the pointer itself can be changed.
- (f) Illegal. Assigning `const` quantifier to a reference is invalid as references are inherently (cannot be re-binded) constant.
- (g) Legal. `i2` is a `const int` that is initialized to the value of `i`. `r` is a reference to a `const int` and is bound to `i`.

### Exercise 2.28
> Explain the following definitions. Identify any that are illegal.

```
(a) int i, *const cp;
(b) int *p1, *const p2;
(c) const int ic, &r = ic;
(d) const int *const p3;
(e) const int *p;
```

- (a) Illegal. The declaration of `i` is fine, but you cannot declare a `const` pointer without initializing it to point an object.
- (b) Illegal. The declaration of `p1` is legal, but p2 is a `const` pointer to `int` and must be initialized to point to a valid `int` upon declaration.
- (c) Illegal. `ic` is a const int, but it is not initialized. `const` variables must be initialized upon declaration. 
- (d) Illegal. A `const` pointer must be initialized upon declaration.
- (e) Legal. `p` is a pointer to `const int`. However, it is generally best practice to initialize pointers to avoid undefined behavior if they are dereferenced before being assigned.

### Exercise 2.29
> Using the variables in the previous exercise, which of the following assignments are legal? Explain why.

```
(a) i = ic;
(b) p1 = p3;
(c) p1 = &ic;
(d) p3 = &ic;
(e) p2 = p1;
(f) ic = *p3;
```

- (a) Legal. Both variables are of type `int`. Eventhough `ic` is a const, this line is fine as it does not alter `ic`.
- (b) Illegal. A pointer to `int` cannot be assigned to a pointer to `const int`.
- (c) Illegal. A pointer to `int` cannot be assigned to a `const int`.
- (d) Illegal. You cannot re-assign a `const` pointer to point to a different object.
- (e) Illegal. You cannot re-assign a `const` pointer to point to a different object.
- (f) Illegal. `ic` is a `const int`, so it cannot be modified.

### Exercise 2.30
> For each of the following declarations indicate whether the object being declared has top-level or low-level const.

```
(a) const int v2 = 0; int v1 = v2;
(b) int *p1 = &v1, &r1 = v1;
(c) const int *p2 = &v2, *const p3 = &i, &r2 = v2;
```

- (a) `v2` has top-level const, `v1` has no const on any level.
- (b) Neither `p1` nor `r1` has const at any level.
- (c) `p2` has low-level const, `p3` has const on both levels, `r2` has low level const.

### Exercise 2.31
> Given the declarations in the previous exercise determine whether the following assignments are legal. Explain how the top-level or low-level const applies in each case.

```
(a) r1 = v2;
(b) p1 = p2;
(c) p2 = p1;
(d) p1 = p3;
(e) p2 = p3;
```

- (a) Legal. The value of the object that reference `r1` is bound to is set to the value of `v2`. The `const int` type of `v2` does not matter as it's not being modified.
- (b) Illegal. A pointer to `int` cannot be assigned to a `const int`, which is the type of object `p2` points to, as it would allow for modification of a `const int` object value through `p1`. The low-level const of `p2` prevents this assignment. 
- (c) Illegal. A pointer to `const int` cannot be assigned to a `int`, which is the type of object `p1` points to. This is due to the low-level const in `p2`.
- (d) Illegal. A pointer to `int` cannot be assigned to a `const int`, which is the type of object `p2` points to. The top-level const in `p3` prevents reassigning `p3`, but it’s the low-level const in `p3` that prevents this assignment, as `p1` would allow modification of a `const int`.
- (e) Legal. The top-level `const` in `p3` does not matter as it won't be altered here. `p2` is assigned to the `const int` object that `p3` points to, they both have a low-level `const`.

## Exercise 2.32
> Is the following code legal or not? If not, how might you make it legal?

```
int null = 0, *p = null;
```

- The first declaration is legal and sets `null` to 0.
- However, the second declaration is illegal. This sets `p` to point to the value of the `null` variable (aka 0), not the memory address of the `null` variable.
- To make `p` a null pointer, we would do `int *p = nullptr;`.
- To make `p` point to the null variable, we would do `int *p = &null;`.

## Exercise 2.33
> Using the variable definitions from this section, determine what happens in each of these assignments:

```
a = 42;
b = 42;
c = 42;
d = 42;
e = 42;
g = 42;
```

1. 'a' is an `int` type.
2. 'b' is an `int` type.
3. 'c' is an `int` type.
4. Invalid assignment as 'd' is of type `int*`, so the value needs to be a valid memory address to `int`. Assigning to a literal `int` is not allowed,
5. Invalid assignment as 'e' is of type `const int*`, so the value needs to be a valid memory address to `const int`. Assigning to a literal `int` is not allowed,
6. Invalid assignment as 'g' is a reference to `const int` so the underlying object's value cannot be changed.

## Exercise 2.35
> Determine the types deduced in each of the following definitions. Once you’ve figured out the types, write a program to see whether you were correct.

```
const int i = 42;
auto j = i;
const auto &k = i;
auto *p = &i;
const auto j2 = i, &k2 = i;
```

1. 'i' is of type `const int`. It has top level const.
2. 'j' is of type `int`.
3. 'k' is of type `const int&`, aka a reference. It has low level const.
4. 'p' is of type `const int*`, aka a pointer. It has low level const.
5. 'j2' is of type `const int`. It has top level const.
6. 'k2' is of type `const int&`, aka a reference. It has low level const.

## Exercise 2.36
> In the following code, determine the type of each variable and the value each variable has when the code finishes:

```
int a = 3, b = 4;
decltype(a) c = a;
decltype((b)) d = a;
++c;
++d;
```

1. 'a' is of type `int` and will end with value 4.
2. 'b' is of type `int` and will end with value 4.
3. 'c' is of type `int` and will end with value 4.
4. 'd' is of type `int&` (reference to 'a') and will end with value 4.

## Exercise 2.37
> Assignment is an example of an expression that yields a reference type. The type is a reference to the type of the left-hand operand. That is, if i is an int, then the type of the expression i = x is int&. Using that knowledge, determine the type and value of each variable in this code:

```
int a = 3, b = 4;
decltype(a) c = a;
decltype(a = b) d = a;
```

1. 'a' is of type `int` and has value 3.
2. 'b' is of type `int` and has value 4.
3. 'c' is of type `int` and has value 3.
4. 'd' is of type `int&` (reference to 'a') and has value 3.

## Exercise 2.38
> Describe the differences in type deduction between decltype and auto. Give an example of an expression where auto and decltype will deduce the same type and an example where they will deduce differing types.

1. `decltype` - Determines the type exactly as it appears within the brackets, whether it’s an object or an expression.
2. `auto` - Uses the type of the assigned expression but ignores top-level const and references during type deduction.

#### Same Type:
```
int a = 5;
decltype(a) b = a;
auto c = a;
```

Here both 'b' and 'c' are of type `int`.

#### Different:
```
int a = 5, c = 10;
decltype(a = c) b = a;
auto d = a;
```

Here 'b' is of type `int&` (a reference to a), while 'd' is a of type `int`.