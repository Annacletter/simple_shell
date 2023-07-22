#include "simple_shell.h"
/**
 * free_all_dp - all memory and a double pointer to be freed
 * @ptr: The pointer to free
 * Return: Nothing(void)
*/

void free_all_dp(char **ptr)
{
	unsigned int i = 0;

	if (ptr == NULL)
		return;

	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}

	if (ptr[i] == NULL)
		free(ptr[i]);
	free(ptr);
}

/**
 * parent_free_commands - The buffer and the commands to be freed
 * @buffer: buffer in getline
 * @commands: Inserted a double pointer that stores all the commands
 * Return: Nothing(void)
*/

void parent_free_commands(char *buffer, char **commands)
{
	free(buffer);
	free_all_dp(commands);
}

/**
* send_to_free - Function to set free when the child is not created
*@buffer: buffer created by getline
*@commands: array of commands
*Return: Nothing(void)
*/

void send_to_free(char *buffer, char **commands)
{
	if (commands == NULL)
		parent_free_commands(buffer, commands);

	else if (_strcmp("exit", commands[0]))
		get_out(buffer, commands);
	else
		parent_free_commands(buffer, commands);
}
