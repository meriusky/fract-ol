/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:54:28 by mehernan          #+#    #+#             */
/*   Updated: 2022/08/22 17:14:45 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*last_element;
	t_list	*element;

	last_element = NULL;
	element = *lst;
	if (!lst)
		return ;
	while (element)
	{
		last_element = element;
		element = element->next;
		del(last_element->content);
		free(last_element);
	}
	*lst = NULL;
}
