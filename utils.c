/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:36:31 by rdupeux           #+#    #+#             */
/*   Updated: 2024/01/02 21:00:39 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
/// @brief get the len of the list argument ( must be a double linked list)
/// @param lst a t_lst list
/// @return len of the staist
size_t	get_lst_len(t_lst **lst)
{
	t_lst	*cursor;
	size_t	len;

	cursor = *lst;
	len = 1;
	if (!(*lst))
		return (0);
	while (cursor->next != *lst)
	{
		len++;
		cursor = cursor->next;
	}
	return (len);
}

/// @brief create a new allocated list element, return NULL in case of malloc
/// error, recommending using this function in combinaison with the append
/// function to avoid bug.
/// @param content content to be add into the list (convert to void pointer)
/// @return the new node
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

/// @brief do all the garbage colecting for the list given as argument
/// @param lst pointer to one of the element of the list
/// @param f function used to free the list data
void	free_lst(t_lst *lst, void (*f)(void *))
{
	t_lst	*next;
	size_t	len;

	len = get_lst_len(&lst);
	while (len--)
	{
		next = lst->next;
		free(lst);
		f(lst->data);
		lst = next;
	}
}
