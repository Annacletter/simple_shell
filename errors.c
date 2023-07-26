#include "simple_shell.h"

/**
* build_message - Function to write an error message
*@av: argument vector
*@fir_com: first command to print if not found
*@count: number of times executed
*Return: Nothing(void)
*/

void build_message(char **av, char *fir_com, int count)
{
	int num_length = 1, cp, mult = 1;

	write(STDERR_FILENO, av[0], _strlen(av[0]));
	write(STDERR_FILENO, ": ", 2);
	cp = count;

	while (cp >= 10)
	{
		cp /= 10;
		mult *= 10;
		num_length++;
	}

	while (num_length > 1)
	{
		if ((count / mult) < 10)
			_puterror((count / mult + '0'));
		else
			_puterror((count / mult) % 10 + '0');
		--num_length;
		mult /= 10;
	}

	_puterror(count % 10 + '0');
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, fir_com, _strlen(fir_com));
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
* _puterror - Prints a character.
*@c: character to write
*Return: int to print
*/

int _puterror(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}

/**
 * get_line - Reads from the standard input.
 *
 * Return: The string enter by the user.
*/
void *get_line(void)
{
	static char buffer[BUFFER_SIZE];
	static int buf_pos, buf_size;
	char *input_str = NULL;
	char current_char;
	int input_len = 0;

	while (1)
	{
		if (buf_pos >= buf_size)
		{
			buf_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			buf_pos = 0;
			if (buf_size == 0)
				return (input_str);
			else if (buf_size < 0)
			{
				perror("read");
				return (NULL);
			}
		}

		current_char = buffer[buf_pos];

		buf_pos++;

		if (current_char == '\n')
		{
			input_str = realloc(input_str, input_len + 1);
			input_str[input_len] = '\0';
			return (input_str);
		}
		else
		{
			input_str = realloc(input_str, input_len + 1);
			input_str[input_len] = current_char;
			input_len++;
		}
	}
}
