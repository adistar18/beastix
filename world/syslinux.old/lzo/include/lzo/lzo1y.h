/* lzo1y.h -- public interface of the LZO1Y compression algorithm

   This file is part of the LZO real-time data compression library.

   Copyright (C) 1996-2014 Markus Franz Xaver Johannes Oberhumer
   All Rights Reserved.

   The LZO library is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of
   the License, or (at your option) any later version.

   The LZO library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with the LZO library; see the file COPYING.
   If not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.

   Markus F.X.J. Oberhumer
   <markus@oberhumer.com>
   http://www.oberhumer.com/opensource/lzo/
 */


#ifndef __LZO1Y_H_INCLUDED
#define __LZO1Y_H_INCLUDED 1

#ifndef __LZOCONF_H_INCLUDED
#include "lzoconf.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif


/***********************************************************************
//
************************************************************************/

/* Memory required for the wrkmem parameter.
 * When the required size is 0, you can also pass a NULL pointer.
 */

#define LZO1Y_MEM_COMPRESS      ((lzo_uint32_t) (16384L * lzo_sizeof_dict_t))
#define LZO1Y_MEM_DECOMPRESS    (0)
#define LZO1Y_MEM_OPTIMIZE      (0)


/* decompression */
LZO_EXTERN(int)
lzo1y_decompress        ( const lzo_bytep src, lzo_uint  src_len,
                                lzo_bytep dst, lzo_uintp dst_len,
                                lzo_voidp wrkmem /* NOT USED */ );

/* safe decompression with overrun testing */
LZO_EXTERN(int)
lzo1y_decompress_safe   ( const lzo_bytep src, lzo_uint  src_len,
                                lzo_bytep dst, lzo_uintp dst_len,
                                lzo_voidp wrkmem /* NOT USED */ );


/***********************************************************************
//
************************************************************************/

LZO_EXTERN(int)
lzo1y_1_compress        ( const lzo_bytep src, lzo_uint  src_len,
                                lzo_bytep dst, lzo_uintp dst_len,
                                lzo_voidp wrkmem );


/***********************************************************************
// better compression ratio at the cost of more memory and time
************************************************************************/

#define LZO1Y_999_MEM_COMPRESS  ((lzo_uint32_t) (14 * 16384L * sizeof(short)))

LZO_EXTERN(int)
lzo1y_999_compress      ( const lzo_bytep src, lzo_uint  src_len,
                                lzo_bytep dst, lzo_uintp dst_len,
                                lzo_voidp wrkmem );



/***********************************************************************
//
************************************************************************/

LZO_EXTERN(int)
lzo1y_999_compress_dict     ( const lzo_bytep src, lzo_uint  src_len,
                                    lzo_bytep dst, lzo_uintp dst_len,
                                    lzo_voidp wrkmem,
                              const lzo_bytep dict, lzo_uint dict_len );

LZO_EXTERN(int)
lzo1y_999_compress_level    ( const lzo_bytep src, lzo_uint  src_len,
                                    lzo_bytep dst, lzo_uintp dst_len,
                                    lzo_voidp wrkmem,
                              const lzo_bytep dict, lzo_uint dict_len,
                                    lzo_callback_p cb,
                                    int compression_level );

LZO_EXTERN(int)
lzo1y_decompress_dict_safe ( const lzo_bytep src, lzo_uint  src_len,
                                   lzo_bytep dst, lzo_uintp dst_len,
                                   lzo_voidp wrkmem /* NOT USED */,
                             const lzo_bytep dict, lzo_uint dict_len );


/***********************************************************************
// optimize a compressed data block
************************************************************************/

LZO_EXTERN(int)
lzo1y_optimize          (       lzo_bytep src, lzo_uint  src_len,
                                lzo_bytep dst, lzo_uintp dst_len,
                                lzo_voidp wrkmem /* NOT USED */ );



#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* already included */


/* vim:set ts=4 et: */
