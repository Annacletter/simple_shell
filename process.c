#include "shell.h"

/**
* null_command - This function frees the buffer.
* @buffer: area in memory that stores data.
* Return: Always 0.
*/

void null_command(char *buffer)
{
	free(buffer);
	exit(EXIT_SUCCESS);
}

/**
* get_out - Commands and frees the buffer from getline.
* @commands: Displays the commands that are Inputed.
* @buffer: Displays buffer taken from getline.
* Return: Always 0;
*/

void get_out(char *buffer, char **commands)
{
	free(buffer);
	free_all_dp(commands);
	exit(EXIT_SUCCESS);
}

/**
* env_end - this function free the buffer and commands created in getline.
* @env: displays enviroment variables.
* @buffer: buffer from getline.
* @commands: this displays the stored array  commands.
* Return: Always 0.
*/

void env_end(char *buffer, char **commands, char **env)
{
	free(buffer);
	free_all_dp(commands);
	print_env(env);
	exit(EXIT_SUCCESS);
}

/**
* _path - This function executes and checked the command inputed.
* @argv: displays arguments.
* @env: shows environmental variables.
* @commands: Stored commands.
* @buffer: buffer from getline.
* @count: displays the number of times the command ran.
*/

void _path(char **commands, char *buffer, char **env, char **argv, int count)
{
	struct stat fileStat2;
	int i = 0;
	char **directories;

	directories = store_e_variables(commands[0], env);
	while (directories[i])
	{
		if (stat(directories[i], &fileStat2) == 0)
			execve(directories[i], commands, NULL);
		i++;
	}

	build_message(argv, commands[0], count);

	free(buffer);
	free_all_dp(commands);
	free_all_dp(directories);
	exit(EXIT_SUCCESS);
}
