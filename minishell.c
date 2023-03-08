/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:21:39 by adantas-          #+#    #+#             */
/*   Updated: 2023/03/08 16:26:45 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_arg(char **av);
void	print_logo(char *username);
void	loop_prompt(void);


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

void	check_arg(char **av)
{
	if (!av[1] || !av[1][0])
	{
		printf("invalid argument\n");
		exit(22);
	}
	else if (!ft_strcmp(av[1], "-h") || !ft_strcmp(av[1], "--help"))
	{
		printf("Minishell startup flags are:\n");
		printf("\e[1m-h --help\e[0m\n\tDisplay this text.\n");
		printf("\e[1m-f --fast\e[0m\n\tDisables the initial ASCII.\n");
		printf("\e[1m-v --version\e[0m\n\tDisplay the program version.\n");
		exit(0);
	}
	else if (!ft_strcmp(av[1], "-f") || !ft_strcmp(av[1], "--fast"))
		loop_prompt();
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

// LEMBRA DE MUDAR PARA Q ELES RECEBAM A STRUCT COM TUDO DE UTILIDADE
void	verify_input(char *cmd)
{
	if (!ft_strncmp(cmd, "cd", 2))
		exec_cd(&cmd[2]);
	else if (!ft_strncmp(cmd, "echo", 4))
		exec_echo(&cmd[4]);
	else if (!ft_strncmp(cmd, "unset", 5))
		exec_unset(&cmd[5]);
	else if (!ft_strncmp(cmd, "export", 6))
		exec_export(&cmd[6]);
	else if (!ft_strcmp(cmd, "pwd"))
		exec_pwd(&cmd[3]);
	else if (!ft_strcmp(cmd, "env"))
		exec_env(&cmd[3]);
	else if (!ft_strcmp(cmd, "exit"))
		exec_exit(&cmd[4]);
	else
		is_valid_cmd(cmd);
	ft_free(cmd);
}

void	loop_prompt(void)
{
	char	*command;

	command = 0x0;
	while (1)
	{
		command = readline("\e[1;36m🐚Type your command\e[0m$> ");
		// if (!command)
		// {
		// 	printf("exit");
		// 	break ;
		// }
		// if (*command)
		// 	add_history(command);
		verify_input(ft_strtrim(command, " "));
		ft_free(command);
	}
	ft_free(command);
	exit(0);
}

int	main(int ac, char **av, char **ep)
{
	char	*user;

	(void)ep;
	if (ac > 2)
	{
		printf("too many arguments\n");
		exit(22);
	}
	if (ac == 2)
		check_arg(av);
	user = getenv("USER");
	print_logo(user);
	ft_free(user);
	loop_prompt();
	exit(0);
}
