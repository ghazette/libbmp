/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bitmap.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/12 18:49:53 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/13 11:32:23 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/bitmap.h"

t_bmp			*init_bmp(int height)
{
	t_bmp	*bmp;

	if (!(bmp = malloc(sizeof(t_bmp))))
		return (NULL);
	if (!(bmp->file_header = malloc(sizeof(t_bmp_file_header))))
		return (NULL);
	if (!(bmp->info_header = malloc(sizeof(t_bitmap_info_header))))
		return (NULL);
	if (height != 0)
	{
		if (!(bmp->row_ptr = malloc(height * sizeof(t_bitmap_data*))))
			return(NULL);
	}
	else
		bmp->row_ptr = NULL;
	bmp->data = NULL;
	bmp->data_decode = NULL;
	return (bmp);
}

t_bitmap_data	*new_bitmapdata_node(t_uchar b, t_uchar g, t_uchar r)
{
	t_bitmap_data *bmd;

	if (!(bmd = malloc(sizeof(t_bitmap_data))))
		return (NULL);
	bmd->rgb.color[0] = b;
	bmd->rgb.color[1] = g;
	bmd->rgb.color[2] = r;
	bmd->next = NULL;
	return (bmd);
}

void			destroy_bmp(t_bmp *bmp)
{
	t_bitmap_data	*ptr;
	t_bitmap_data	*nxt;

	ptr = bmp->data;
	while (ptr != NULL)
	{
		nxt = ptr->next;
		free(ptr);
		ptr = nxt;
	}
	if (bmp->row_ptr)
		free(bmp->row_ptr);
	free(bmp->file_header);
	free(bmp->info_header);
	bmp->data = NULL;
	bmp->row_ptr = NULL;
	bmp->file_header = NULL;
	bmp->info_header = NULL;
	free(bmp);
	bmp = NULL;
}
