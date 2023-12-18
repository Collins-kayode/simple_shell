#include "shell.h"
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

/**
 * _prompt - this is to display the shell prompt.
 */
void _prompt(void)
{
	printf("simple_shell$ ");
	fflush(stdout);
}

/**
 * exec_command - Execute the given command.
 * @command: The parameter for command to execute.
 */
void exec_command(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error forking process");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) /* Child pid */
	{
		if (execlp(command, command, (char *)NULL) == -1)
		{
			perror("Command not found");
			exit(EXIT_FAILURE);
		}
	}
	else /* Parent pid */
	{
		waitpid(pid, NULL, 0);
	}
}

/**
 * main - The entry point of the simple shell program.
 * Return: 0 on success.
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		_prompt();

		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			/* Handle end of file (Ctrl+D) or (exit)*/
			printf("\nExiting simple_shell.\n");
			exit(EXIT_SUCCESS);
		}

		/* Remove the newline character */
		if (command[strlen(command) - 1] == '\n')
		{
			command[strlen(command) - 1] = '\0';
		}

		exec_command(command);
	}

	return (0);
}

