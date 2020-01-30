/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/12 18:54:04 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 13:49:10 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libbmp.h"

void	decode_bmp_file_header(t_bmp *bmp)
{
	t_uchar buffer[14];

	read(bmp->fd, buffer, 14);
	bmp->file_header->signature[0] = buffer[0];
	bmp->file_header->signature[1] = buffer[1];
	bmp->file_header->totalsize = bytes_to_number(buffer + 2, 4);
	bmp->file_header->offset = bytes_to_number(buffer + 10, 4);
}

void	decode_bitmap_info_header(t_bmp *bmp)
{
	t_uchar buffer[40];

	read(bmp->fd, buffer, 40);
	bmp->info_header->bm_headersize = bytes_to_number(buffer, 4);
	bmp->info_header->width = bytes_to_number(buffer + 4, 4);
	bmp->info_header->height = bytes_to_number(buffer + 8, 4);
	bmp->info_header->planes_number = bytes_to_number(buffer + 12, 2);
	bmp->info_header->bpp = bytes_to_number(buffer + 14, 2);
	bmp->info_header->compression_type = bytes_to_number(buffer + 16, 4);
	bmp->info_header->imagesize = bytes_to_number(buffer + 20, 4);
	bmp->info_header->hres = bytes_to_number(buffer + 24, 4);
	bmp->info_header->vres = bytes_to_number(buffer + 28, 4);
	bmp->info_header->ncolors = bytes_to_number(buffer + 32, 4);
	bmp->info_header->nimpcolors = bytes_to_number(buffer + 36, 4);
	bmp->padding = bmp->info_header->width % 4;
}
