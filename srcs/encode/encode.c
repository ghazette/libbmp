/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   encode.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/13 03:39:56 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/13 11:46:56 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/bitmap.h"

static void				get_next_row_ptr(t_bitmap_data **ptr, int width)
{
	int i;

	i = 0;
	while (i < width)
	{
		(*ptr) = (*ptr)->next;
		i++;
	}
}

static t_bitmap_data	**get_row_ptr(t_bmp *bmp)
{
	t_bitmap_data	**row_ptr;
	t_bitmap_data	*ptr;
	t_uint			i;

	i = 0;
	ptr = bmp->data;
	if (!(row_ptr = (t_bitmap_data**)malloc(sizeof(t_bitmap_data*))))
		return (NULL);
	while (i < bmp->info_header->height)
	{
		if (!(row_ptr[i] = malloc(sizeof(t_bitmap_data))))
			return (NULL);
		row_ptr[i] = ptr;
		get_next_row_ptr(&ptr, bmp->info_header->width);
		i++;
	}
	return (row_ptr);
}

t_bmp					*encode(char *img, int width, int height)
{
	t_bmp	*bmp;

	if (!(bmp = init_bmp()))
		return (NULL);
	fill_headers(bmp, width, height);
	if (!(bmp->data = fill_imagedata(img, width, height)))
		return (NULL);
	if (!(bmp->row_ptr = get_row_ptr(bmp)))
		return (NULL);
	return (bmp);
}

int						export_as_bmp(char *path, char *img, int width,
						int height)
{
	t_bmp	*bmp;

	if (!(bmp = encode(img, width, height)))
		return (0);
	bmp->fd = open(path, O_TRUNC | O_WRONLY | O_CREAT, 0777);
	if (bmp->fd == -1)
		return (-1);
	write_headers(bmp);
	write_rgb(bmp);
	close(bmp->fd);
	destroy_bmp(bmp);
	return (1);
}
