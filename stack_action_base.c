/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:35:49 by rdupeux           #+#    #+#             */
/*   Updated: 2024/01/02 21:13:29 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

/// @brief add a new node at the start of the list
/// @param stack list, if list is NULL, return an initialised list with
/// to_append as it's only member
/// @param to_append node to append at the start of the list
void	appendleft(t_lst **stack, t_lst *to_append)
{
	if (!(*stack))
	{
		to_append->next = to_append;
		to_append->prev = to_append;
		*stack = to_append;
		return ;
	}
	to_append->next = *stack;
	to_append->prev = (*stack)->prev;
	(*stack)->prev->next = to_append;
	(*stack)->prev = to_append;
	*stack = to_append;
}

/// @brief add a new node at the end of the list
/// @param stack list, if list is NULL, return an initialised list with
/// to_append as it's only member
/// @param to_append node to append at the end of the list
void	append(t_lst **stack, t_lst *to_append)
{
	if (!(*stack))
	{
		to_append->next = to_append;
		to_append->prev = to_append;
		*stack = to_append;
		return ;
	}
	to_append->next = *stack;
	to_append->prev = (*stack)->prev;
	(*stack)->prev->next = to_append;
	(*stack)->prev = to_append;
}

/// @brief remove the first node of the list
/// ( node is not destroyed only removed from the list)
/// @param stack lst
/// @return	the removed node adress;
t_lst	*popleft(t_lst **stack)
{
	t_lst	*to_pop;

	to_pop = *stack;
	if (to_pop->next == to_pop && to_pop->prev == to_pop)
	{
		*stack = NULL;
		return (to_pop);
	}
	(*stack)->prev->next = (*stack)->next;
	(*stack)->next->prev = (*stack)->prev;
	*stack = (*stack)->next;
	to_pop->next = NULL;
	to_pop->prev = NULL;
	return (to_pop);
}

/// @brief remove the last node of the list
/// ( node is not destroyed only removed from the list)
/// @param stack lst
/// @return	the removed node adress;
t_lst	*pop(t_lst **stack)
{
	t_lst	*to_pop;

	to_pop = (*stack)->prev;
	if (to_pop->next == to_pop && to_pop->prev == to_pop)
	{
		*stack = NULL;
		return (to_pop);
	}
	(*stack)->prev = to_pop->prev;
	to_pop->prev->next = *stack;
	to_pop->prev = NULL;
	to_pop->next = NULL;
	return (to_pop);
}
