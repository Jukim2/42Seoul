/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:59:04 by kjs               #+#    #+#             */
/*   Updated: 2023/02/03 15:14:23 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include "libft.h"

typedef struct s_signal
{
	pid_t	pid;
	int		signum;
	int		send_cnt;
	int		receive_cnt;
}	t_signal;

t_signal	g_sig;

void	write_ch(int signum)
{
	static int	i;
	static char	ch;

	if (signum == 30)
		ch += (1 << i);
	if (++i == 8)
	{
		write(1, &ch, 1);
		i = 0;
		ch = 0;
	}
}

void	sig1_sigaction(int signum, siginfo_t *info, void *ptr)
{
	if (info->si_pid <= 100)
		return ;
	(void) ptr;
	write_ch(signum);
	g_sig.pid = info->si_pid;
	g_sig.signum = signum;
	g_sig.receive_cnt++;
}

void	sig2_sigaction(int signum, siginfo_t *info, void *ptr)
{
	if (info->si_pid <= 100)
		return ;
	(void) ptr;
	write_ch(signum);
	g_sig.pid = info->si_pid;
	g_sig.signum = signum;
	g_sig.receive_cnt++;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	act_sig1;
	struct sigaction	act_sig2;

	pid = getpid();
	ft_printf("pid : %d\n", pid);
	act_sig1.sa_sigaction = sig1_sigaction;
	act_sig1.sa_flags = SA_SIGINFO;
	sigemptyset(&act_sig1.sa_mask);
	act_sig2.sa_sigaction = sig2_sigaction;
	act_sig2.sa_flags = SA_SIGINFO;
	sigemptyset(&act_sig2.sa_mask);
	sigaction(SIGUSR1, &act_sig1, 0);
	sigaction(SIGUSR2, &act_sig2, 0);
	g_sig.send_cnt = 0;
	g_sig.receive_cnt = 0;
	while (1)
	{
		if (g_sig.send_cnt != g_sig.receive_cnt)
		{
			g_sig.send_cnt++;
			kill(g_sig.pid, g_sig.signum);
		}
	}
}
