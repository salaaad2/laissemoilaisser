/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:06:40 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:06:40 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_bool	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (TRUE);
	}
	return (FALSE);
}
