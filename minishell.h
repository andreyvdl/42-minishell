/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:21:41 by adantas-          #+#    #+#             */
/*   Updated: 2023/03/08 17:02:52 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** readline = stdio.h readline/readline.h readline/history.h
** rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay = readline/readline.h
** add_history = readline/history.h
** printf, perror = stdio.h
** malloc, free, getenv = stdlib.h
** write, access, read, close, fork, exit, getcwd, chdir, unlink, execve, dup, dup2, pipe, isatty, ttyname, ttyslot = unistd.h
** open = fcntl.h sys/stat.h
** wait, waitpid = sys/types.h sys/wait.h
** wait3, wait4 = sys/types.h sys/time.h sys/resource.h sys/wait.h
** signal, sigaction, sigemptyset, sigaddset = signal.h
** kill = sys/types.h signal.h
** stat, lstat, fstat = sys/types.h sys/stat.h unistd.h
** opendir, closedir = sys/types.h dirent.h
** readdir = dirent.h
** strerror = string.h
** ioctl = sys/ioctl.h
** tcsetattr, tcgetattr = termios.h unistd.h
** tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs = curses.h term.h
*/

# include <term.h>
# include <fcntl.h>
# include <stdio.h>
# include <curses.h>
# include <dirent.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <termios.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/resource.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "libft/includes/libft.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_all
{
	t_env	env;
}	t_all;

#endif
