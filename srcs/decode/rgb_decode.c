/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rgb_decode.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/12 18:42:40 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/13 11:27:44 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/bitmap.h"

static int	create_bitmapdata(t_bmp **bmp, t_bitmap_data **ptr, t_uchar pix[3])
{
	if (!(*bmp)->data)
	{
		if (!((*bmp)->data = new_bitmapdata_node(pix[0], pix[1], pix[2])))
			return (0);
		*ptr = (*bmp)->data;
	}
	else
	{
		if (!((*bmp)->data->next = new_bitmapdata_node(pix[0], pix[1], pix[2])))
			return (0);
		(*bmp)->data = (*bmp)->data->next;
	}
	return (1);
}

int			get_imagedata(t_bmp *bmp)
{
	t_uint			i;
	t_uint			j;
	int				padding;
	unsigned char	pix[3];
	t_bitmap_data	*ptr;

	ptr = NULL;
	i = 0;
	padding = bmp->info_header->width % 4;
	while (i < bmp->info_header->height)
	{
		j = 0;
		while (j < bmp->info_header->width)
		{
			read(bmp->fd, pix, 3);
			if (!(create_bitmapdata(&bmp, &ptr, pix)))
				return (0);
			j++;
		}
		if (padding > 0)
			read(bmp->fd, pix, padding);
		i++;
	}
	bmp->data = ptr;
	return (1);
}
