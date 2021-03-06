/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:07:16 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:07:16 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

unsigned char	ft_uintlen(unsigned long n)
{
	unsigned char	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
