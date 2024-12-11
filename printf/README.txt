The purpose of this project was to recreate the functionality and behavior of the standard printf function for the flags: "c, s, p, d, i, u, x, X, %"

In this project, the buffer management of the standard printf was not reproduced. Additionally, there were a few constaints to follow:
 - individual functions cannot have more than 25 lines
 - Only the following existing functions were allowed : malloc, free, write, va_start, va_arg, va_copy, va_end
 - ternary operators, for and do loops are not allowed