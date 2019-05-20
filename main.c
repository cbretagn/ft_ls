/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 16:12:02 by cbretagn          #+#    #+#             */
/*   Updated: 2019/05/19 19:44:01 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_ls.h"

int		main(int argc, char **argv)
{
	char			*flags;
	t_file			**paths;
	int				i;
	int				j;
	struct stat		buffer;

	flags = ft_strnew(MAX_FLAGS);
	i = get_flags(argv, flags);
	ft_putendl(flags); //remove
	paths = get_paths(argv, argc, i);
	j = -1;
	while (paths[++j])
	{
		stat(paths[j]->file_name, &buffer);
		fill_struct(paths[j], buffer);
	}
	j = -1;//remove
	while (paths[++j])
	{
		ft_putendl(paths[j]->file_name);
		ft_putstr(ctime(&paths[j]->date));
		ft_putchar(paths[j]->type);
		ft_putchar('\n');
	}
	//sort paths depending on flags, cpy directory in separate array
	//
	//print long display (or not) till reach directory
	//
	//for each file (directory) remaining, call open_directory function
}