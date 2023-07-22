#include "shell.h"

/**
* execute - This Progran prints , executes and double check commands.
* @argv: Indicates the number of arguments.
* @count: This function counts the number that was executed.
* @commands: command get
* @env: Runs a command in a modified environment.
* @buffer: Holds blocks of data
* Return: Always 0.
*/

void execute(char **commands, char *buffer, char **env, char **argv, int count)
{
	struct stat fileStat;

	if (commands == NULL)
		null_command(buffer);
	else if (_strcmp("exit", commands[0]))
		get_out(buffer, commands);
	else if (_strcmp("env", commands[0]))
		env_end(buffer, commands, env);
	else if (stat(commands[0], &fileStat) == 0)
		execve(commands[0], commands, NULL);
	else
		_path(commands, buffer, env, argv, count);
}
