/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:58:33 by ylazrek           #+#    #+#             */
/*   Updated: 2019/11/04 10:27:30 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;
	t_list *prec;

	tmp = *lst;
	while (tmp != NULL)
	{
		del(tmp->content);
		prec = tmp;
		tmp = tmp->next;
		free(prec);
	}
	*lst = NULL;
}
