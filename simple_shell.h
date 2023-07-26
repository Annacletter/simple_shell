#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#define PATH_MAX_LENGTH 4096
#define PATH_SEPARATOR ":"
#define PROMPT "$"
#define MAX_TOKENS 1024
#define BUFFER_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void prompt(void);
void *get_line(void);
void INThandler(int sig);
void print_dollar(void);

unsigned int find_length_command(char *s);
char **array_strtok(char *str);

void execute(char **commands, char *buffer, char **env,
				char **argv, int count);

char *_strncpy(char *dest, char *src, int n);
char *_strncpyconst(char *dest, const char *src, int n);
unsigned int _strlen_const(const char *str);
unsigned int _strlen(char *str);
int _strcmp(char *s1, char *s2);

unsigned int find_num_dir(char *path);
char **store_e_variables(char *fir_com, char **environ);
char *_getenv(const char *name, char **environ);
char *_strncpcommand(char *dest, char *src, char *command, int n, int c);
void print_env(char **environ);

void free_all_dp(char **ptr);
void parent_free_commands(char *buffer, char **commands);
void send_to_free(char *buffer, char **commands);

void build_message(char **av, char *fir_com, int count);
int _puterror(char c);
void end_file(char *buffer);
void fork_fail(void);

void null_command(char *buffer);
void get_out(char *buffer, char **commands);
void env_end(char *buffer, char **commands, char **env);
void _path(char **commands, char *buffer, char **env, char **argv, int count);

#endif
