/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mif_manager.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:07:36 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/08 19:09:14 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIF_MANAGER_H
# define MIF_MANAGER_H

# include	<stdio.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<fcntl.h>
# include	<mlx.h>
#include <string.h>

#include "./get_next_line/get_next_line.h"


typedef struct s_list {
	void	*content;
	struct s_list	*next;
}	t_list;

typedef struct s_mif {
	unsigned int	*container;
	int				width;
	int				height;
	t_list			*colors;
}	t_mif;

typedef struct s_color {
	unsigned int	value;
	char			c;
}	t_color;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_coord {
	int	x;
	int	y;
}	t_coord;

typedef struct s_elt_opt {
	t_data	img;
	int		color;
	t_coord	coord;
}	t_elt_opt;


void	mif_read(char *file, t_mif *options);
void	mif_to_img(t_mif *mif, t_data *img, int size);

/* UTILS */
// int		ft_atoi(const char *nptr);
void	put_pixel_information(void *container, int index, unsigned int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_lstadd_front(t_list **alst, t_list *new);
t_list	*ft_lstnew(void *content);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	put_square(t_elt_opt options, int width, int height, int color);

#endif