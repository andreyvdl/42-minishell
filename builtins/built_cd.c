/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:03:06 by adantas-          #+#    #+#             */
/*   Updated: 2023/03/07 16:08:18 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_cd(char *cmd)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == '-')
		{
			if (!cmd[i + 1])
			{
				goto_oldpwd();
				break ;
			}
			else
			{
				cd_error(&cmd[i]);
				break ;
			}
		}
	}
}

void	goto_oldpwd(void)
{

}

void	cd_error(char *pathway)
{
	perror("minishell: cd");
}
