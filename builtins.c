#include "shell.h"

char *builtin_str[] = {
    "cd",
    "help",
    "exit",
    "history"
};

int (*builtin_func[]) (char **) = {
    &cd,
    &help,
    &minishell_exit,
    &minishell_history
};

int num_builtins()
{
	return sizeof(builtin_str) / sizeof(char *);
}

int cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("Minishell");
		}
	}
	return 1;
}

int help()
{
	int i;
	printf("MINISHELL\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");

	for (i = 0; i < num_builtins(); i++)
	{
		printf("	%s\n", builtin_str[i]);
	}

	printf("Use the man commmand for information on other programs.\n");
	return 1;
}

int minishell_exit()
{
	write_history();
	
	return 0;
}

int minishell_history()
{
	Node* cur = history;
	int count = 0;

	while (cur != NULL)
	{
		printf("%d. %s\n", count, cur->data);
		cur = cur->next;
		count += 1;
	}

	return 1;
}