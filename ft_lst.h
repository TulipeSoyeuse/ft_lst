/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:19:04 by rdupeux           #+#    #+#             */
/*   Updated: 2024/01/02 21:05:03 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H
# include <stdlib.h>

typedef struct s_lst
{
	struct s_lst	*next;
	struct s_lst	*prev;
	void			*data;
}					t_lst;
// init

t_lst				*lst_new(void *content);
size_t				get_lst_len(t_lst **stack);
void				free_lst(t_lst *stack_a, void (*f)(void *));
// base action

void				appendleft(t_lst **stack, t_lst *to_append);
t_lst				*popleft(t_lst **stack);
void				append(t_lst **stack, t_lst *to_append);
t_lst				*pop(t_lst **stack);

#endif
