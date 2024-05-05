/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:26:36 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/13 11:51:47 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_node
{
	int				n;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_num
{
	int				num;
	struct s_num	*next;
}	t_num;

/* ===============srcs/algorithm=============== */

void	small_sort(t_node **a, t_node **b, int total);
void	sort_three(t_node **a);
void	sort_four(t_node **a, t_node **b);
void	sort_five(t_node **a, t_node **b);
int		is_sorted(t_node **a);
void	move_to_a(t_node **a, t_node **b, int target, int diff);
int		move_target(t_node **a, t_node **b, int target);
int		cal_rotation(t_node **b, int target);
int		move_to_b(t_node **a, t_node **b, int total);
void	move_less_than_pivot(t_node **a, t_node**b, int pivot, int prev_pivot);
int		pivot_end(t_node **a, int pivot, int prev_pivot);
int		pick_3_r(t_node **a, t_node **b, int target);
int		pick_2_r(t_node **a, t_node **b, int target);
void	pick_1_r(t_node **a, t_node **b, int target);
int		pick_3_rr(t_node **a, t_node **b, int target);
int		pick_2_rr(t_node **a, t_node **b, int target);
void	pick_1_rr(t_node **a, t_node **b, int target);
void	quick_sort(t_node **a, t_node **b, int total);

/* ===============srcs/argument=============== */

t_num	*convt_list(t_num *num_list, int len);
int		get_ith_num(t_num *num_list, int i);
void	get_argument(t_num **num_list, int argc, char *argv[]);
void	put_lst(t_num **num_list, char **strs);
void	check_duplicate(int atoied_num, int *flag, t_num **num_list);
t_num	*ft_num_lst_new(int num);
void	ft_num_lst_addback(t_num **node, t_num *new);
int		ft_num_lst_len(t_num *num_list);

/* ===============srcs/commands=============== */

void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

/* ===============srcs/main=============== */

char	**ps_split(char const *str);
int		ps_atoi(int *flag, const char *str);
void	free_num_lst(t_num **num_list);
void	free_d_str(char **strs);
void	free_stack(t_node *a, int total);

/* ===============srcs/stack=============== */

t_node	*cdll_new_node(int num);
void	cdll_addback(t_node **lst, t_node *node);
void	cdll_addfront(t_node **lst, t_node *node);
void	cdll_deltop(t_node **lst);
void	make_stack(t_node **a, t_num *num_list);

#endif
