/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:35:44 by izail             #+#    #+#             */
/*   Updated: 2022/03/29 17:35:46 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extention(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	if (str[i - 1] == 'r' && str[i - 2] == 'e' && str[i - 3] == 'b'
		&& str[i - 4] == '.')
		return (1);
	return (0);
}

int main(int ac, char **av)
{
    // t_game game;
    
    if (ac == 2)
    {
        if (!check_extention(av[1]))
        {
            ft_printf("The extention in invalid");
            return (0);
        }
        else 
        {
            
        }
    }
    else
    {
        ft_printf("Invalid number of argumets");
        return (0);
    }

}
