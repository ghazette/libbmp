/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bmp.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/13 11:17:52 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/13 11:26:31 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

typedef unsigned char		t_uchar;
typedef unsigned int		t_uint;
typedef unsigned short		t_ushort;
typedef unsigned long		t_ulong;

typedef union				u_rgb
{
	t_uchar					color[3];
	t_uint					hex;
}							t_rgb;

typedef struct				s_bmp_file_header
{
	t_uchar					signature[2];
	t_uint					totalsize;
	t_uint					offset;
}							t_bmp_file_header;

typedef struct				s_bitmap_info_header
{
	t_uint					bm_headersize;
	t_uint					imagesize;
	t_uint					width;
	t_uint					height;
	t_ushort				planes_number;
	t_ushort				bpp;
	t_uint					compression_type;
	t_uint					hres;
	t_uint					vres;
	t_uint					ncolors;
	t_uint					nimpcolors;
}							t_bitmap_info_header;

typedef struct				s_bitmap_data
{
	t_rgb					rgb;
	struct s_bitmap_data	*next;
}							t_bitmap_data;

/*
** padding used only for encoding
** row_ptr are pointers to starting pixel of each rows (data)
*/

typedef struct				s_bmp
{
	int						fd;
	t_bmp_file_header		*file_header;
	t_bitmap_info_header	*info_header;
	t_bitmap_data			*data;
	t_bitmap_data			**row_ptr;
	int						padding;
}							t_bmp;

#endif
