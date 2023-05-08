#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

/**
 * error_exit - prints an error message to stderr and exits with the given code
 * @exit_code: the exit code to use
 * @message: the error message to print
 */
void error_exit(int exit_code, char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(exit_code);
}

/**
 * main - copies the content of a file to another file
 * @argc: the number of arguments passed to the program
 * @argv: an array of pointers to the arguments
 * Return: 0 on success, or an error code on failure
 */
int main(int argc, char **argv)
{
	int fd_from, fd_to, n_read, n_written;
	char buf[BUF_SIZE];
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to");

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file %s", argv[1]);

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, mode);
	if (fd_to == -1)
		error_exit(99, "Error: Can't write to %s", argv[2]);

	while ((n_read = read(fd_from, buf, BUF_SIZE)) > 0)
	{
		n_written = write(fd_to, buf, n_read);
		if (n_written == -1)
			error_exit(99, "Error: Can't write to %s", argv[2]);
	}

	if (n_read == -1)
		error_exit(98, "Error: Can't read from file %s", argv[1]);

	if (close(fd_from) == -1)
		error_exit(100, "Error: Can't close fd %d", fd_from);

	if (close(fd_to) == -1)
		error_exit(100, "Error: Can't close fd %d", fd_to);

	return (0);
}

