/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:36:31 by rdupeux           #+#    #+#             */
/*   Updated: 2024/01/01 17:52:47 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

size_t	get_lst_len(t_lst **stack)
{
	t_lst	*cursor;
	size_t	len;

	cursor = *stack;
	len = 1;
	if (!(*stack))
		return (0);
	while (cursor->next != *stack)
	{
		len++;
		cursor = cursor->next;
	}
	return (len);
}

t_lst	*lst_new(void *content)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->data = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	free_lst(t_lst *stack_a, void (*f)(void *))
{
	t_lst	*next;
	size_t	len;

	len = get_lst_len(&stack_a);
	while (len--)
	{
		next = stack_a->next;
		free(stack_a);
		f(stack_a->data);
		stack_a = next;
	}
}
