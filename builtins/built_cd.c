/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:03:06 by adantas-          #+#    #+#             */
/*   Updated: 2023/03/08 16:04:01 by adantas-         ###   ########.fr       */
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
		
	}
}

void	goto_oldpwd(void)
{

}

void	cd_error(char *pathway)
{
	perror("minishell: cd");
}
