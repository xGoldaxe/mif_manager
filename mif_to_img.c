/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mif_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:45:03 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/09 16:37:55 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mif_manager.h"

void	mif_to_img(t_mif *mif, t_data *img, int size)
{
	int				x;
	int				y;
	unsigned int	color;
	t_elt_opt		options;
	int				unit;
	int				reste;

	unit = size / mif->width;
	reste = size % mif->width;
	printf("%d %d\n", unit, reste);
	y = 0;
	options.coord.y = 0;
	options.img = *img;
	while (options.coord.y < size)
	{
		x = 0;
		options.coord.x = 0;
		while (options.coord.x < size)
		{
			color = mif->container[(y * mif->width )+ x];
			if (reste > x)
			{
				if (reste > y)
				{
					put_square(options, unit + 1, unit + 1, color);
					options.coord.x++;
				}
				else
				{
					put_square(options, unit + 1, unit, color);
					options.coord.x++;
				}
			}
			else if (reste > y)
				put_square(options, unit, unit + 1, color);
			else
				put_square(options, unit, unit, color);
			options.coord.x += unit;
			++x;
		}
		if (reste > y)
			++options.coord.y;
		++y;
		options.coord.y += unit;
	}
}
