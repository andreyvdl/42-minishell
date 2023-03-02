/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:21:39 by adantas-          #+#    #+#             */
/*   Updated: 2023/03/02 13:58:25 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*command;
	size_t	i;
	char	*user;
	// int		oquotes;

	command = 0x0;
	i = 0;
	user = getenv("USER");
	printf("\e[1mHello %s, welcome to\n", user);
	printf("___  ________ _   _ _____ _____ _   _ _____ _     _\n");
	printf("|  \\/  |_   _| \\ | |_   _/  ___| | | |  ___| |   | |\n");
	printf("| .  . | | | |  \\| | | | \\ `--.| |_| | |__ | |   | |\n");
	printf("| |\\/| | | | | . ` | | |  `--. \\  _  |  __|| |   | |\n");
	printf("| |  | |_| |_| |\\  |_| |_/\\__/ / | | | |___| |___| |____\n");
	printf("\\_|  |_/\\___/\\_| \\_/\\___/\\____/\\_| |_|____/\\_____|_____/");
	printf("\e[0m\n");
	while (1)
	{
		command = readline("\e[1;36m🐚Type your command\e[0m$>");
		// while (command[i])
		// {
		// 	if
		// }
		if (command)
			if (strcmp(command, "exit") == 0)
				break ;
		add_history(command);
		printf("Trying to execute [%s]\n", command);
		ft_free(command);
	}
	ft_free(command);
	exit(0);
}
