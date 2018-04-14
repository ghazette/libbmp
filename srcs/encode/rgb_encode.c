/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rgb_encode.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/12 22:11:11 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/13 11:30:13 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/bitmap.h"

static int		create_bitmap_data(char *img, int i, t_bitmap_data **data,
	t_bitmap_data **ptr)
{
	if (!(*data))
	{
		if (!((*data) = new_bitmapdata_node((t_uchar)img[i],
		(t_uchar)img[i + 1], (t_uchar)img[i + 2])))
			return (0);
		(*ptr) = (*data);
	}
	else
	{
		if (!((*ptr)->next = new_bitmapdata_node((t_uchar)img[i],
		(t_uchar)img[i + 1], (t_uchar)img[i + 2])))
			return (0);
		(*ptr) = (*ptr)->next;
	}
	return (1);
}

t_bitmap_data	*fill_imagedata(char *img, int width, int height)
{
	t_bitmap_data	*data;
	t_bitmap_data	*ptr;
	int				l;
	int				i;

	i = 0;
	l = width * height * 4;
	data = NULL;
	while (i < l)
	{
		if (!(create_bitmap_data(img, i, &data, &ptr)))
			return (NULL);
		i += 4;
	}
	return (data);
}

void			write_rgb(t_bmp *bmp)
{
	int				i;
	t_uint			j;
	t_bitmap_data	*ptr;

	i = bmp->info_header->height - 1;
	while (i != -1)
	{
		j = 0;
		ptr = bmp->row_ptr[i];
		while (j < bmp->info_header->width)
		{
			write(bmp->fd, ptr->rgb.color, 3);
			ptr = ptr->next;
			j++;
		}
		if (bmp->padding > 0)
			write(bmp->fd, "\0", bmp->padding);
		i--;
	}
}
