/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:12:31 by jajuntti          #+#    #+#             */
/*   Updated: 2023/11/23 16:14:00 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x(t_printer *printer)
{
	unsigned long	hex;

	hex = va_arg(printer->params, unsigned int);
	if (*printer->source == 'x')
		printer->status = safer_putnbr_ul_base_fd(hex, "0123456789abcdef", 1);
	else
		printer->status = safer_putnbr_ul_base_fd(hex, "0123456789ABCDEF", 1);
	if (printer->status < 0)
		return (1);
	printer->output_count += printer->status;
	return (0);
}
