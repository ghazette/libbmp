/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/12 13:43:59 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/13 11:35:21 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/bitmap.h"

t_uint		bytes_to_number(t_uchar *str, t_uint n)
{
	t_uint ret;

	ret = 0;
	if (n == 4)
		ret = (str[3] << 24) | (str[2] << 16) | (str[1] << 8) | str[0];
	if (n == 2)
		ret = (str[1] << 8) | str[0];
	return (ret);
}

void		number_to_bytes(t_uint nb, t_uchar *buffer, t_uint len)
{
	int shift;
	int i;

	i = len - 1;
	shift = (len != 1) ? (len - 1) * 8 : 0;
	while (shift != 0)
	{
		buffer[i] = (nb >> shift) & 0xFF;
		shift -= 8;
		i--;
	}
	buffer[i] = nb & 0xFF;
}

void	free2d(char ***str)
{
	int i;

	i = 0;
	while ((*str)[i] != 0)
	{
		free((*str)[i]);
		i++;
	}
	free((*str)[i]);
	free(*str);
	*str = NULL;
}

/*
** void		display_header(t_bmp *bmp)
** {
**	printf("%c%c\n", bmp->file_header->signature[0],
**	bmp->file_header->signature[1]);
**	printf("total size : %d\n", bmp->file_header->totalsize);
**	printf("offset: %d\n", bmp->file_header->offset);
**	printf("bitmap info header size: %d\n", bmp->info_header->bm_headersize);
**	printf("width: %d\n", bmp->info_header->width);
**	printf("height: %d\n", bmp->info_header->height);
**	printf("planes number: %d\n", bmp->info_header->planes_number);
**	printf("BPP: %d\n", bmp->info_header->bpp);
**	printf("compression type: %d\n", bmp->info_header->compression_type);
**	printf("image size: %d\n", bmp->info_header->imagesize);
**	printf("horizontal resolution: %d\n", bmp->info_header->hres);
**	printf("vertical resolution: %d\n", bmp->info_header->vres);
**	printf("number of colors: %d\n", bmp->info_header->ncolors);
**	printf("number of important colors: %d\n", bmp->info_header->nimpcolors);
**	printf("padding: %d\n", bmp->padding);
** }
*/

 void		display_header(t_bmp *bmp)
 {
	printf("%c%c\n", bmp->file_header->signature[0],
	bmp->file_header->signature[1]);
	printf("total size : %d\n", bmp->file_header->totalsize);
	printf("offset: %d\n", bmp->file_header->offset);
	printf("bitmap info header size: %d\n", bmp->info_header->bm_headersize);
	printf("width: %d\n", bmp->info_header->width);
	printf("height: %d\n", bmp->info_header->height);
	printf("planes number: %d\n", bmp->info_header->planes_number);
	printf("BPP: %d\n", bmp->info_header->bpp);
	printf("compression type: %d\n", bmp->info_header->compression_type);
	printf("image size: %d\n", bmp->info_header->imagesize);
	printf("horizontal resolution: %d\n", bmp->info_header->hres);
	printf("vertical resolution: %d\n", bmp->info_header->vres);
	printf("number of colors: %d\n", bmp->info_header->ncolors);
	printf("number of important colors: %d\n", bmp->info_header->nimpcolors);
	printf("padding: %d\n", bmp->padding);
 }
