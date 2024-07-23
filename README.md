# Get-Next-Line

The Get Next Line project aims to create a function in C that reads and returns a line from a given file descriptor. This function is designed to handle various edge cases and should work efficiently even with varying buffer sizes. This project not only provides a useful function but also introduces the concept of static variables in C programming.

- Prototype: `char *get_next_line(int fd)`
- Parameters:
  - **fd**: The file descriptor to read from.
- Returns:
  A pointer to a string containing the next line from the file descriptor, or NULL if the end of the file is reached or an error occurs.

## Features

- Read and return a single line from the file descriptor each time it is called, including standard input.
- Support multiple file descriptors simultaneously without losing the reading thread for each.
- Handle various buffer sizes defined at compile time using -D BUFFER_SIZE=n.
- Handle end-of-file correctly, and include the newline character in the returned line, except if the end-of-file is reached.
- Utilize only one static variable in the implementation.
- Properly free all heap-allocated memory.

<br>

# File Handling

The `fcntl.h` and `unistd.h` libraries in C provides advanced file control operations.

### `open()`

- **Description**: Open a file.
- **Prototype**: `int open(const char *pathname, int flags);`
    - **Parameters**:
        - **pathname**: Path to the file.
        - **flags**: Mode in which to open the file.
            - `O_RDONLY`: Open for reading only.
            - `O_WRONLY`: Open for writing only.
            - `O_RDWR`: Open for reading and writing.
            - `O_CREAT`: Create the file if it does not exist.
            - `O_TRUNC`: Truncate the file to length 0 if it exists.
            - `O_APPEND`: Write at the end of the file.
    - **Returns**: File descriptor on success, `-1` on error.

### `read()`

- **Description**: Read from a file.
- **Prototype**: `ssize_t read(int fd, void *buf, size_t count);`
    - **Parameters**:
        - **fd**: File descriptor to read from.
        - **buf**: Buffer to read data into.
        - **count**: Number of bytes to read.
    - **Returns**: Number of bytes read on success, `-1` on error.

### `write()`

- **Description**: Write to a file.
- **Prototype**: `ssize_t write(int fd, const void *buf, size_t count);`
    - **Parameters**:
        - **fd**: File descriptor to write to.
        - **buf**: Buffer containing data to write.
        - **count**: Number of bytes to write.
    - **Returns**: Number of bytes written on success, `-1` on error.

### `close()`

- **Description**: Close a file.
- **Prototype**: `int close(int fd);`
    - **Parameters**:
        - **fd**: File descriptor to close.
    - **Returns**: `0` on success, `-1` on error.

<br>
 
### Usage Example:
```c
void	display(char *filename)
{
	int		fd;
	char	character;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (read(fd, &character, 1))
		write(1, &character, 1);
	close(fd);
}
```

<br>

# Static Variables

A static variable in C is a variable that retains its value between multiple function calls. It is initialized only once and exists for the lifetime of the program, but its scope is limited to the block in which it is defined.

```c
void count_calls() {
    static int count = 0; // Static variable
    count++;
    printf("Function called %d times\n", count);
}

int main() {
    for (int i = 0; i < 5; i++) {
        count_calls();
    }
    return 0;
}
```
- **Local Static Variables:** Defined within a function and retain their value between calls to that function.
- **Global Static Variables:** Defined outside of all functions and are accessible only within the file in which they are declared.


<br>

# Implementation
