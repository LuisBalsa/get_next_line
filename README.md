# Get Next Line

The "get_next_line" project is an implementation of a function that reads and returns a line from a file descriptor each time it is called, stopping at the end of the file.

## Function Description

The function "get_next_line" reads one line at a time from the given file descriptor. It returns a string pointer containing the line read, excluding the newline character '\n'. When the end of the file is reached or an error occurs, the function returns NULL. It uses a static variable to store any remaining characters from the previous call.

## Buffer Size

The buffer size, which is used to read from the file descriptor, can be specified during compilation. The default value is 42, but you can set your own buffer size using the flag "-D BUFFER_SIZE=n" at compile time.

## Optimization

One optimization in this implementation is that it uses one fewer malloc compared to most other codes. It doesn't allocate memory for the remaining buffer after extracting the line.

## Bonus Version

Additionally, there is a bonus version of the "get_next_line" function that can read from multiple file descriptors simultaneously.

## Repository

You can find the project repository [here](https://github.com/LuisBalsa/get_next_line).
