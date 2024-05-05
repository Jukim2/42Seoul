/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:43:17 by kjs               #+#    #+#             */
/*   Updated: 2023/06/20 20:51:20 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	capitalize_str(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		str[i] = std::toupper(str[i]);
	}
	std::cout << str;
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int idx = 1; idx < argc; idx++)
		capitalize_str(argv[idx]);
	std::cout << std::endl;
	return (0);
}