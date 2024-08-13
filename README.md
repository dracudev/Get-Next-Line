>**This function is now part of <a href="https://github.com/dracudev/Libft" target="_blank">Libft</a>**

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

## Get_next_line_utils.c

### [ft_isnewline](src/get_next_line_utils.c)

The ft_isnewline function checks if there is a newline character (\n) in the given buffer and returns its position if found. If the buffer is NULL or no newline character is present, it returns -1.

```c
int	ft_isnewline(char *buffer)
{
	int	i;

	if (!buffer)
		return (-1);
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
```

**Parameters**:
- `char *buffer`: A pointer to the string buffer that will be checked for the presence of a newline character.

**Functionality**:
- Checks if the buffer is `NULL`. If it is, the function returns `-1` to indicate an error.
- Iterates through each character in the buffer.
- If a newline character (`\n`) is encountered, the function returns the index of that character within the buffer.
- If no newline character is found after checking the entire buffer, the function returns `-1`, indicating the absence of a newline character.

<br>

### [ft_strlen](src/get_next_line_utils.c)

The `ft_strlen` function calculates the length of a given string by counting the number of characters until the null terminator (`\0`). If the string is `NULL`, it returns `0`.

```c
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
```

**Parameters**:
- `char *str`: A pointer to the string whose length is to be calculated.

**Functionality**:
- Initializes an integer `i` to `0` to serve as a counter for the string length.
- Checks if the string `str` is `NULL`. If it is, the function returns `0` to indicate that the length of a `NULL` string is `0`.
- Iterates through the string, incrementing the counter `i` for each character until the null terminator (`\0`) is reached.
- Returns the value of `i`, which represents the total length of the string.

<br>

### [ft_strncat](src/get_next_line_utils.c)

The `ft_strncat` function concatenates a specified number of characters from the `buffer` string to the end of the `saved` string. It dynamically allocates memory for the concatenated result and updates the `saved` pointer to point to the new string.

```c
int	ft_strncat(char **saved, char *buffer, int size)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!(*saved))
		str = malloc((size + 1) * sizeof(char));
	else
		str = malloc(((ft_strlen(*saved) + size) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (*saved && (*saved)[i])
	{
		str[i] = (*saved)[i];
		i++;
	}
	j = 0;
	while (j < size)
		str[i++] = buffer[j++];
	str[i] = '\0';
	if (*saved)
		free(*saved);
	*saved = NULL;
	*saved = str;
	return (1);
}
```

**Parameters**:
- `char **saved`: A double pointer to the string that will be extended with the content from the `buffer`.
- `char *buffer`: A pointer to the string from which characters will be appended to `saved`.
- `int size`: The number of characters from the `buffer` to append to `saved`.

**Functionality**:
- Initializes integer variables `i` and `j` to `0` for indexing.
- Allocates memory for the new concatenated string. If `saved` is `NULL`, it allocates enough space for `size + 1` characters. If `saved` is not `NULL`, it allocates enough space for the combined length of `saved` and the new `size` characters plus the null terminator.
- Returns `0` if memory allocation fails.
- Copies the content of `saved` to the newly allocated string `str`.
- Appends `size` characters from `buffer` to the end of `str`.
- Adds a null terminator to `str`.
- Frees the memory previously allocated to `saved` if it was not `NULL`.
- Updates `saved` to point to the newly concatenated string `str`.
- Returns `1` to indicate successful concatenation.

<br>

### [ft_strtrim_jump](src/get_next_line_utils.c)

The `ft_strtrim_jump` function extracts a substring from the beginning of `saved` up to and including the first newline character (`\n`). It then updates `saved` to contain only the remaining part of the original string after the newline character. The extracted substring is returned, while the original string is modified.

```c
char	*ft_strtrim_jump(char **saved)
{
	char	*strcut;
	char	*strsaved;
	int		i;
	int		j;

	i = -1;
	strcut = malloc((ft_isnewline(*saved) + 2) * sizeof(char));
	if (!strcut)
		return (NULL);
	while ((*saved)[++i] != '\n')
		strcut[i] = (*saved)[i];
	strcut[i++] = '\n';
	strcut[i] = '\0';
	strsaved = NULL;
	if ((*saved)[i])
	{
		j = 0;
		strsaved = malloc((ft_strlen(&(*saved)[i]) + 1) * sizeof(char));
		while ((*saved)[i])
			strsaved[j++] = (*saved)[i++];
		strsaved[j] = '\0';
	}
	free(*saved);
	*saved = strsaved;
	return (strcut);
}
```

**Parameters**:
- `char **saved`: A double pointer to the string from which the function will extract and remove the substring up to the first newline character.

**Functionality**:
- Allocates memory for `strcut`, which will store the substring from the start of `saved` up to and including the first newline character (`\n`).
- Returns `NULL` if memory allocation for `strcut` fails.
- Copies characters from `saved` to `strcut` until the newline character is encountered.
- Appends the newline character (`\n`) to `strcut`, followed by a null terminator (`\0`).
- Allocates memory for `strsaved` to store the remaining part of `saved` after the newline character. If there are no characters left after the newline, `strsaved` is set to `NULL`.
- Copies the remaining characters from `saved` to `strsaved`.
- Frees the memory previously allocated to `saved` and updates `saved` to point to `strsaved`.
- Returns `strcut`, which contains the substring up to and including the first newline character.

<br>

## Get_next_line.c

### [get_last_line](src/get_next_line.c)

The `get_last_line` function extracts the entire string stored in `saved`, returning it as a new string. After extracting the string, it frees the memory associated with `saved` and sets `saved` to `NULL`.

```c
char	*get_last_line(char **saved)
{
	char	*res;
	int		i;

	if (!(*saved) || !(*saved)[0])
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(*saved) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while ((*saved)[i] != '\0')
	{
		res[i] = (*saved)[i];
		i++;
	}
	res[i] = '\0';
	free(*saved);
	*saved = NULL;
	return (res);
}
```

**Parameters**:
- `char **saved`: A double pointer to the string that will be extracted and freed.

**Functionality**:
- Checks if `saved` is `NULL` or if it points to an empty string. If either is true, the function returns `NULL`.
- Allocates memory for `res`, a new string that will store the contents of `saved`.
- Returns `NULL` if memory allocation for `res` fails.
- Copies each character from `saved` to `res` until the end of the string (`\0`) is reached.
- Appends a null terminator (`\0`) to `res` to ensure it is a properly terminated string.
- Frees the memory previously allocated to `saved` and sets `saved` to `NULL`.
- Returns the new string `res`, which contains the entire original content of `saved`.

<br>

### [ft_readfd](src/get_next_line.c)

The `ft_readfd` function reads data from a file descriptor `fd` into the `saved` string until a newline character (`\n`) is found or the end of the file is reached. The function returns a string up to the newline character or the remaining content of the file if no newline is found.

```c
char	*ft_readfd(char **saved, int fd)
{
	int		readed;
	char	*buffer;

	while (ft_isnewline((*saved)) == -1)
	{
		buffer = malloc(BUFFER_SIZE * sizeof(char));
		if (!buffer)
			return (NULL);
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed > 0)
			readed = ft_strncat(saved, buffer, readed);
		free(buffer);
		if (readed == 0)
			return (get_last_line(saved));
		else if (readed == -1)
		{
			if ((*saved))
			{
				free((*saved));
				(*saved) = NULL;
			}
			return (NULL);
		}
	}
	return (ft_strtrim_jump(saved));
}
```

**Parameters**:
- `char **saved`: A double pointer to the string that stores the accumulated content read from the file descriptor.
- `int fd`: The file descriptor from which data is read.

**Functionality**:
- Continuously reads from the file descriptor `fd` into `saved` until a newline character (`\n`) is encountered in `saved`.
- Allocates memory for `buffer` to temporarily hold the data read from the file.
- Returns `NULL` if memory allocation for `buffer` fails.
- Calls the `read` function to read up to `BUFFER_SIZE` bytes from `fd` into `buffer`.
- If data is successfully read (`readed > 0`), it appends the data in `buffer` to `saved` using `ft_strncat`.
- Frees the memory allocated for `buffer` after each read operation.
- If `readed == 0`, indicating that the end of the file is reached, it returns the remaining content of `saved` by calling `get_last_line`.
- If an error occurs during reading (`readed == -1`), it frees `saved`, sets it to `NULL`, and returns `NULL`.
- If a newline character is found, it returns the content of `saved` up to and including the newline character by calling `ft_strtrim_jump`.

<br>

### [get_next_line](src/get_next_line.c)

The `get_next_line` function reads and returns the next line from a file descriptor `fd`, including the newline character (`\n`) if present. It handles multiple file descriptors simultaneously by using a static array to keep track of the saved state for each file descriptor.

```c
char	*get_next_line(int fd)
{
	static char	*saved[1024];

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (saved[fd] && ft_isnewline(saved[fd]) > -1)
		return (ft_strtrim_jump(&saved[fd]));
	else
		return (ft_readfd(&saved[fd], fd));
	return (NULL);
}
```

**Parameters**:
- `int fd`: The file descriptor from which the next line is to be read.

**Functionality**:
- Uses a static array `saved[1024]` to store the accumulated data for each file descriptor up to 1024.
- Checks if the `fd` is valid (i.e., non-negative, less than 1024, and the `BUFFER_SIZE` is greater than 0). If any of these conditions are not met, the function returns `NULL`.
- If there is already data saved for the given `fd` and a newline character is present in that data, it extracts and returns the next line using `ft_strtrim_jump`.
- If no newline character is found in the saved data, or if the saved data is `NULL`, the function calls `ft_readfd` to read more data from the file descriptor until a newline is found or the end of the file is reached.
- The function ultimately returns either the next line from the file descriptor or `NULL` if an error occurs or no more lines are available.
