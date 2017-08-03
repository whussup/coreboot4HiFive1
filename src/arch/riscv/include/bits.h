/*
 * Copyright (c) 2013, The Regents of the University of California (Regents).
 * All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Regents nor the
 * names of its contributors may be used to endorse or promote products
 * derived from this software without specific prior written permission.
 *
 * IN NO EVENT SHALL REGENTS BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT,
 * SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING LOST PROFITS, ARISING
 * OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF REGENTS HAS
 * BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * REGENTS SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE. THE SOFTWARE AND ACCOMPANYING DOCUMENTATION, IF ANY, PROVIDED
 * HEREUNDER IS PROVIDED "AS IS". REGENTS HAS NO OBLIGATION TO PROVIDE
 * MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
 */

#ifndef _BITS_H
#define _BITS_H

#define CONST_POPCOUNT2(x) ((((x) >> 0) & 1) + (((x) >> 1) & 1))
#define CONST_POPCOUNT4(x) (CONST_POPCOUNT2(x) + CONST_POPCOUNT2((x)>>2))
#define CONST_POPCOUNT8(x) (CONST_POPCOUNT4(x) + CONST_POPCOUNT4((x)>>4))
#define CONST_POPCOUNT16(x) (CONST_POPCOUNT8(x) + CONST_POPCOUNT8((x)>>8))
#define CONST_POPCOUNT32(x) (CONST_POPCOUNT16(x) + CONST_POPCOUNT16((x)>>16))
#define CONST_POPCOUNT64(x) (CONST_POPCOUNT32(x) + CONST_POPCOUNT32((x)>>32))
#define CONST_POPCOUNT(x) CONST_POPCOUNT64(x)

#define CONST_CTZ2(x) CONST_POPCOUNT2(((x) & -(x))-1)
#define CONST_CTZ4(x) CONST_POPCOUNT4(((x) & -(x))-1)
#define CONST_CTZ8(x) CONST_POPCOUNT8(((x) & -(x))-1)
#define CONST_CTZ16(x) CONST_POPCOUNT16(((x) & -(x))-1)
#define CONST_CTZ32(x) CONST_POPCOUNT32(((x) & -(x))-1)
#define CONST_CTZ64(x) CONST_POPCOUNT64(((x) & -(x))-1)
#define CONST_CTZ(x) CONST_CTZ64(x)

#define STR(x) XSTR(x)
#define XSTR(x) #x



#if __riscv_xlen == 32
# define SLL32    ssl
# define STORE    sw
# define LOAD     lw
# define LOG_REGBYTES 2
#elif __riscv_xlen == 64
# define SLL32    sllw
# define STORE    sd
# define LOAD     ld
# define LOG_REGBYTES 3
#endif

#define REGBYTES (1 << LOG_REGBYTES)

#endif
