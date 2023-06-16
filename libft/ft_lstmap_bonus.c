/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:02:58 by mehernan          #+#    #+#             */
/*   Updated: 2022/08/23 23:01:43 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	t_list	*sec;

	new = NULL;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		sec = f(lst->content);
		temp = ft_lstnew(sec);
		if (!temp)
		{
			del(sec);
			ft_lstclear(&temp, del);
		}
		ft_lstadd_back(&new, temp);
		lst = (lst)->next;
	}
	return (new);
}
