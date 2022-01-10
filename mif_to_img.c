/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mif_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:45:03 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/10 17:05:05 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mif_manager.h"

void	mif_to_img(t_mif *mif, t_data *img, t_data *ref, int size, t_coord coord)
{
	int				x;
	int				y;
	unsigned int	color;
	t_elt_opt		options;
	int				unit;
	int				reste;

	unit = size / mif->width;
	reste = size % mif->width;
	y = 0;
	options.coord.y = coord.y;
	options.img = *img;
	while (options.coord.y - coord.y < size)
	{
		x = 0;
		options.coord.x = coord.x;
		while (options.coord.x - coord.x < size)
		{
			options.size.width = unit;
			options.size.height = unit;
			color = mif->container[(y * mif->width )+ x];
			if (reste > x)
			{
				if (reste > y)
				{
					++options.size.width;
					++options.size.height;
				}
				else
					++options.size.width;
				++options.coord.x;
			}
			else if (reste > y)
				++options.size.height;
			if (color >= 0xFF000000)
				put_square_from_bg(img, ref, options);
			else
				put_square(options, options.size.width, options.size.height, color);
			options.coord.x += unit;
			++x;
		}
		if (reste > y)
			++options.coord.y;
		++y;
		options.coord.y += unit;
	}
}
