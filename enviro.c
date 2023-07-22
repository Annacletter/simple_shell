#include "shell.h"

/**
* find_num_dir - Function prints / finds the number of Directories.
* @path: path string.
* Return: Always 0.
*/
unsigned int find_num_dir(char *path)
{
	unsigned int i = 0, flag = 0, num_dir = 0;

	while (path[i])
	{
		if (path[i] != ':')
			flag = 1;

		if ((flag && path[i + 1] == ':') || (flag && path[i + 1] == '\0'))
		{
			num_dir++;
			flag = 0;
		}
		i++;
		}
		return (num_dir);
}

/**
* store_e_variables - Stores directory path,creates double pointer array.
* @environ: Allows access to enviroment variables.
*@fir_com: It is the first command inputed in the prompt.
*Return: Always 0.
*/

char **store_e_variables(char *fir_com, char **environ)
{
	char **directories, *path_env, *directory;
	unsigned int length, i = 0;
	int dir_length, command_length;

	path_env = _getenv("PATH", environ);
	length = find_num_dir(path_env);
	directories = malloc(sizeof(char *) * (length + 1));
	if (directories == NULL)
		return (NULL);

	directory = strtok(path_env, ":");

	while (directory != NULL)
	{
		dir_length = _strlen(directory);
		command_length = _strlen(fir_com);
		directories[i] = malloc(sizeof(char *) *
		(dir_length + command_length + 2));
		if (directories[i] == NULL)
		{
			free_all_dp(directories);
			return (NULL);
		}
			_strncpcommand(directories[i], directory, fir_com,
			dir_length, command_length);
			i++;
		directory = strtok(NULL, ":");
	}
		directories[i] = NULL;
	return (directories);
}

/**
* _getenv - This function prints and gets environment variable.
* @environ: This function allows access to environment variables.
* @name: gives name to the  enviroment variable.
* Return: Always 0.
*/

char *_getenv(const char *name, char **environ)
{
	char *env_value, *cp_name;
	unsigned int i = 0, length;

	length =  _strlen_const(name);

	cp_name = malloc(sizeof(char) * length + 1);
	if (cp_name == NULL)
		return (NULL);

	_strncpyconst(cp_name, name, length);

	env_value = strtok(environ[i], "=");
	while (environ[i])
	{
		if (_strcmp(env_value, cp_name))
			{																																										env_value = strtok(NULL, "\n");
				free(cp_name);
			return (env_value);
		}
		i++;
		env_value = strtok(environ[i], "=");
	}
	free(cp_name);
	return (NULL);
}

/**
* _strncpcommand - This function copies the path appends and command.
* @dest: this showa thr destination to store values.
* @c: this shows the length of the command.
* @command: this is the command to append.
* @src: this shows the source.
* @n: This indicates the length of the destination.
* Return: Always 0.
*/

char *_strncpcommand(char *dest, char *src, char *command, int n, int c)
{
	int i, j;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	/*append "/" and "command" to the src*/
	dest[i] = '/';
	i++;

	for (j = 0; j < c && command[j] != '\0'; j++, i++)
		dest[i] = command[j];
	dest[i] = '\0';
	return (dest);
}

/**
* print_env - This function prints environment variables.
* @environ: shows all the enviroment variables.
* Return: Always 0.
*/

void print_env(char **environ)
{
	unsigned int i = 0, length;

	while (environ[i])
	{
		length = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], length);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

