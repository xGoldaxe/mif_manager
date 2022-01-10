/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:05:16 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/09 19:31:06 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mif_manager.h"

void	put_square(t_elt_opt options, int width, int height, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			my_mlx_pixel_put(&options.img, options.coord.x + x,
				options.coord.y + y, color);
			x++;
		}
		y++;
	}
}

void	my_put_from(t_data *data, t_data *from_data, int x, int y)
{
	char			*dst;
	unsigned int	from;
	int				offset;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	offset = (y * from_data->line_length + x * (from_data->bits_per_pixel / 8));
	from = *(unsigned int *)(from_data->addr + offset);
	*(unsigned int *)dst = from;
}

void	put_square_from_bg(t_data *img, t_data *bg, t_elt_opt options)
{
	int	x;
	int	y;

	y = 0;
	while (y < options.size.height)
	{
		x = 0;
		while (x < options.size.width)
		{
			my_put_from(img, bg, options.coord.x + x,
				options.coord.y + y);
			x++;
		}
		y++;
	}
}
