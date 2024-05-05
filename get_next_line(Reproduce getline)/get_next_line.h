/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:01:52 by jukim2            #+#    #+#             */
/*   Updated: 2022/12/05 15:49:53 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_file
{
	int				fd;
	struct s_line	*line;
	struct s_file	*next_file;
	struct s_file	*prev_file;
}	t_file;

typedef struct s_line
{
	char			*str;
	struct s_line	*next_line;
	struct s_line	*prev_line;
}	t_line;

t_file	*find_file(int fd, t_file *file_list);
int		make_line_node(t_file *file);
int		make_file_node(int fd, t_file **file_list);
int		find_newline(int idx, char *buffer);
char	*ft_strnjoin(char *str1, char *str2, int start_idx, int end_idx);
char	*get_next_line(int fd);
char	*read_file(int fd, char *buffer, t_file *file);
int		make_line(int rbyte, t_line *current_line, char *buffer);
int		push_line(t_line *current_line, char *buffer, int start, int end);
void	free_all(char *buffer, t_line *line, t_file *file, t_file **file_list);

#endif