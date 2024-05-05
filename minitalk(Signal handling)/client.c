/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:59:06 by kjs               #+#    #+#             */
/*   Updated: 2023/02/03 16:06:34 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "libft.h"

typedef struct s_signal
{
	pid_t	pid;
	char	*str;
	int		cnt;
	int		sig_sent;
	int		bit;
	int		send_cnt;
	int		receive_cnt;
}	t_signal;

t_signal	g_sig;

void	sig1_sigaction(int signum, siginfo_t *info, void *ptr)
{
	char		ch;

	(void) info;
	(void) ptr;
	g_sig.receive_cnt++;
	if (g_sig.bit == 8)
	{
		g_sig.cnt++;
		g_sig.bit = 0;
	}
	ch = g_sig.str[g_sig.cnt];
	if ((signum && (signum != g_sig.sig_sent)) || !ch)
		exit(0);
	if (ch & (1 << (g_sig.bit)++))
		g_sig.sig_sent = SIGUSR1;
	else
		g_sig.sig_sent = SIGUSR2;
}

void	sig2_sigaction(int signum, siginfo_t *info, void *ptr)
{
	char		ch;

	(void) info;
	(void) ptr;
	g_sig.receive_cnt++;
	if (g_sig.bit == 8)
	{
		g_sig.cnt++;
		g_sig.bit = 0;
	}
	ch = g_sig.str[g_sig.cnt];
	if ((signum && (signum != g_sig.sig_sent)) || !ch)
		exit(0);
	if (ch & (1 << (g_sig.bit)++))
		g_sig.sig_sent = SIGUSR1;
	else
		g_sig.sig_sent = SIGUSR2;
}

int	main(int argc, char *argv[])
{
	struct sigaction	act_sig1;
	struct sigaction	act_sig2;

	act_sig1.sa_sigaction = sig1_sigaction;
	act_sig1.sa_flags = SA_SIGINFO;
	sigemptyset(&act_sig1.sa_mask);
	act_sig2.sa_sigaction = sig2_sigaction;
	act_sig2.sa_flags = SA_SIGINFO;
	sigemptyset(&act_sig2.sa_mask);
	sigaction(SIGUSR1, &act_sig1, 0);
	sigaction(SIGUSR2, &act_sig2, 0);
	if (argc != 3)
		ft_printf("Check your argument please\n");
	ft_bzero(&g_sig, sizeof(t_signal));
	g_sig.pid = ft_atoi(argv[1]);
	g_sig.str = argv[2];
	sig1_sigaction(0, 0, 0);
	while (1)
	{
		if (g_sig.send_cnt != g_sig.receive_cnt)
		{
			g_sig.send_cnt++;
			kill(g_sig.pid, g_sig.sig_sent);
		}
	}
}
