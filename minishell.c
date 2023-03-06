/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:21:39 by adantas-          #+#    #+#             */
/*   Updated: 2023/03/06 16:38:44 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_logo(char *username)
{
	printf("\e[1mHello %s, welcome to\n", username);
	printf("___  ________ _   _ _____ _____ _   _ _____ _     _\n");
	printf("|  \\/  |_   _| \\ | |_   _/  ___| | | |  ___| |   | |\n");
	printf("| .  . | | | |  \\| | | | \\ `--.| |_| | |__ | |   | |\n");
	printf("| |\\/| | | | | . ` | | |  `--. \\  _  |  __|| |   | |\n");
	printf("| |  | |_| |_| |\\  |_| |_/\\__/ / | | | |___| |___| |____\n");
	printf("\\_|  |_/\\___/\\_| \\_/\\___/\\____/\\_| |_|____/\\_____|_____/");
	printf("\e[0m\n");
}

int	main(int ac, char **av, char **ep)
{
	char	*command;
	size_t	i;
	char	*user;

	command = 0x0;
	i = 0;
	(void)ep;
	if (ac > 2)
	{
		printf("too many arguments\n");
		exit(22);
	}
	if (ac == 2)
	{
		if (!av[1] || !av[1][0])
		{
			printf("invalid argument\n");
			exit(22);
		}
		else if (!ft_strcmp(av[1], "-h") || !ft_strcmp(av[1], "--help"))
		{
			printf("This program is a minishell, it can use almost all shell/bash commands, but here are some extras:\n");
			printf("-h --help\n\tDisplay this text.\n");
			printf("-f --fast\n\tDisables the initial ASCII.\n");
			printf("-v --version\n\tDisplay the program version.\n");
			exit(0);
		}
		else if (!ft_strcmp(av[1], "-f") || !ft_strcmp(av[1], "--fast"))
		{
			readline("\e[1;36m🐚Type your command\e[0m$>");
			exit(0);
		}
		else if (!ft_strcmp(av[1], "-v") || !ft_strcmp(av[1], "--version"))
		{
			printf("minishell\tversion:0.1\n");
			exit(0);
		}
		else
		{
			printf("invalid argument\n");
			exit(22);
		}
	}
	user = getenv("USER");
	print_logo(user);
	while (1)
	{
		command = readline("\e[1;36m🐚Type your command\e[0m$>");
		if (command)
			if (ft_strcmp(command, "exit") == 0)
				break ;
		add_history(command);
		printf("Trying to execute [%s]\n", command);
		ft_free(command);
	}
	ft_free(command);
	exit(0);
}
