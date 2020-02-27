/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solutions_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:27:30 by aolen             #+#    #+#             */
/*   Updated: 2020/02/26 17:27:30 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_solution *copy_solution(t_solution *source_solutions)
{
	t_solution	*solution_iter;
	int			room_iterator;
	t_solution	*new_solution;

	new_solution = ft_memalloc(sizeof(*new_solution));
	solution_iter = new_solution;
	while (source_solutions)
	{
		room_iterator = -1;
		solution_iter->arr = ft_memalloc(sizeof(*(solution_iter->arr)) * solution_iter->path_len);
		solution_iter->path_len = source_solutions->path_len;
		while (++room_iterator < source_solutions->path_len)
			solution_iter->arr[room_iterator] = source_solutions->arr[room_iterator];
		solution_iter->next = source_solutions->next ?
				ft_memalloc(sizeof(*new_solution)): NULL;
		solution_iter = solution_iter->next;
		source_solutions = source_solutions->next;
	}
	return (new_solution);
}

void	destroy_solutions(t_solution **solution)
{
	t_solution *temp;

	while (*solution)
	{
		free((*solution)->arr);
		temp = (*solution)->next;
		free(*solution);
		*solution = temp;
	}
}