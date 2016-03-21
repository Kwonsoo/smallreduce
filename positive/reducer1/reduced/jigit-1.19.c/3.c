/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is false */

#line 212 "/usr/lib/gcc/x86_64-linux-gnu/4.8/include/stddef.h"
typedef unsigned long size_t;
#line 132 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __off64_t;
#line 172 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __ssize_t;
#line 109 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __ssize_t ssize_t;
#line 22 "/home/june/repo/benchmarks/collector/temp/jigit-1.19/jigdo.h"
typedef long long INT64;
#line 23 "/home/june/repo/benchmarks/collector/temp/jigit-1.19/jigdo.h"
typedef unsigned long long UINT64;
#line 24 "/home/june/repo/benchmarks/collector/temp/jigit-1.19/jigdo.h"
typedef unsigned long UINT32;
#line 36
enum state_ {
    STARTING = 0,
    IN_DATA = 1,
    IN_DESC = 2,
    DUMP_DESC = 3,
    DONE = 4,
    ERROR = 5
} ;
#line 36 "/home/june/repo/benchmarks/collector/temp/jigit-1.19/jigdo.h"
typedef enum state_ e_state;
#line 11 "/home/june/repo/benchmarks/collector/temp/jigit-1.19/md5.h"
typedef unsigned long mk_uint32;
#line 13 "/home/june/repo/benchmarks/collector/temp/jigit-1.19/md5.h"
struct mk_MD5Context {
   mk_uint32 buf[4] ;
   mk_uint32 bits[2] ;
   unsigned char in[64] ;
};
#line 50 "/usr/include/x86_64-linux-gnu/bits/errno.h"
extern  __attribute__((__nothrow__)) int *( __attribute__((__leaf__)) __errno_location)(void)  __attribute__((__const__)) ;
#line 466 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) malloc)(size_t __size )  __attribute__((__malloc__)) ;
#line 69 "/usr/include/string.h"
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2), __leaf__)) memcmp)(void const   *__s1 ,
                                                                                               void const   *__s2 ,
                                                                                               size_t __n )  __attribute__((__pure__)) ;
#line 147
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2), __leaf__)) strncmp)(char const   *__s1 ,
                                                                                                char const   *__s2 ,
                                                                                                size_t __n )  __attribute__((__pure__)) ;
#line 399
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__nonnull__(1), __leaf__)) strlen)(char const   *__s )  __attribute__((__pure__)) ;
#line 337 "/usr/include/unistd.h"
extern  __attribute__((__nothrow__)) __off64_t ( __attribute__((__leaf__)) lseek)(int __fd ,
                                                                                  __off64_t __offset ,
                                                                                  int __whence )  __asm__("lseek64")  ;
#line 353
extern int close(int __fd ) ;
#line 360
extern ssize_t read(int __fd , void *__buf , size_t __nbytes ) ;
#line 362 "/usr/include/stdio.h"
extern int printf(char const   * __restrict  __format  , ...) ;
#line 149 "/usr/include/fcntl.h"
extern int ( __attribute__((__nonnull__(1))) open)(char const   *__file , int __oflag 
                                                   , ...)  __asm__("open64")  ;
#line 26 "/home/june/repo/benchmarks/collector/temp/jigit-1.19/md5.h"
char *base64_dump(unsigned char *buf , size_t buf_size ) ;
#line 25 "/home/june/repo/benchmarks/collector/temp/jigit-1.19/jigdump.c"
static INT64 find_string(unsigned char *buf , size_t buf_size , char *search ) 
{ 
  size_t length ;
  size_t tmp ;
  INT64 result ;
  int tmp___0 ;

  {
  {
#line 27
  tmp = strlen((char const   *)search);
#line 27
  length = tmp;
#line 30
  result = (INT64 )0;
  }
  {
#line 30
  while (1) {
    while_continue: /* CIL Label */ ;

#line 30
    if (! (result < (INT64 )(buf_size - length))) {
#line 30
      goto while_break;
    }
    {
#line 32
    tmp___0 = memcmp((void const   *)(buf + result), (void const   *)search, length);
    }
#line 32
    if (! tmp___0) {
#line 33
      return (result);
    }
#line 30
    result ++;
  }
  while_break___0: /* CIL Label */ ;
  }
  while_break: ;
#line 35
  return ((INT64 )-1);
}
}
#line 38 "/home/june/repo/benchmarks/collector/temp/jigit-1.19/jigdump.c"
static INT64 parse_data_block(INT64 offset , unsigned char *buf , size_t buf_size ) 
{ 
  UINT64 dataLen ;
  UINT64 dataUnc ;
  int tmp ;
  char *__cil_tmp7 ;
  char *__cil_tmp8 ;
  char *__cil_tmp9 ;
  char *__cil_tmp10 ;
  char *__cil_tmp11 ;

  {
  {
#line 41
  dataLen = (UINT64 )0;
#line 42
  dataUnc = (UINT64 )0;
#line 44
  tmp = strncmp((char const   *)((char *)buf), "DATA", (size_t )4);
  }
#line 44
  if (tmp) {
    {
#line 47
    printf((char const   */* __restrict  */)"\nbzip2 data block found at offset %lld\n",
           offset);
    }
  } else {
    {
#line 45
    printf((char const   */* __restrict  */)"\ngzip data block found at offset %lld\n",
           offset);
    }
  }
  {
#line 49
  dataLen = (UINT64 )*(buf + 4);
#line 50
  dataLen |= (UINT64 )*(buf + 5) << 8;
#line 51
  dataLen |= (UINT64 )*(buf + 6) << 16;
#line 52
  dataLen |= (UINT64 )*(buf + 7) << 24;
#line 53
  dataLen |= (UINT64 )*(buf + 8) << 32;
#line 54
  dataLen |= (UINT64 )*(buf + 9) << 40;
#line 55
  printf((char const   */* __restrict  */)"  compressed block size %llu bytes\n",
         dataLen);
#line 57
  dataUnc = (UINT64 )*(buf + 10);
#line 58
  dataUnc |= (UINT64 )*(buf + 11) << 8;
#line 59
  dataUnc |= (UINT64 )*(buf + 12) << 16;
#line 60
  dataUnc |= (UINT64 )*(buf + 13) << 24;
#line 61
  dataUnc |= (UINT64 )*(buf + 14) << 32;
#line 62
  dataUnc |= (UINT64 )*(buf + 15) << 40;
#line 63
  printf((char const   */* __restrict  */)"  uncompressed block size %llu bytes\n",
         dataUnc);
  }
#line 65
  return ((INT64 )dataLen);
}
}
#line 68 "/home/june/repo/benchmarks/collector/temp/jigit-1.19/jigdump.c"
static INT64 parse_desc_block(INT64 offset , unsigned char *buf , size_t buf_size ) 
{ 
  UINT64 descLen ;
  char *__cil_tmp5 ;
  char *__cil_tmp6 ;

  {
  {
#line 71
  descLen = (UINT64 )0;
#line 73
  printf((char const   */* __restrict  */)"\nDESC block found at offset %lld\n", offset);
#line 74
  descLen = (UINT64 )*(buf + 4);
#line 75
  descLen |= (UINT64 )*(buf + 5) << 8;
#line 76
  descLen |= (UINT64 )*(buf + 6) << 16;
#line 77
  descLen |= (UINT64 )*(buf + 7) << 24;
#line 78
  descLen |= (UINT64 )*(buf + 8) << 32;
#line 79
  descLen |= (UINT64 )*(buf + 9) << 40;
#line 80
  printf((char const   */* __restrict  */)"  DESC block size is %llu bytes\n", descLen);
  }
#line 82
  return ((INT64 )10);
}
}
#line 85 "/home/june/repo/benchmarks/collector/temp/jigit-1.19/jigdump.c"
static INT64 parse_desc_data(INT64 offset , unsigned char *buf , size_t buf_size ) 
{ 
  int type ;
  UINT64 skipLen ;
  UINT64 imglen ;
  UINT32 blocklen ;
  int i ;
  char *tmp ;
  UINT64 fileLen ;
  int i___0 ;
  char *tmp___0 ;
  char *tmp___1 ;
  char *__cil_tmp14 ;
  char *__cil_tmp15 ;
  char *__cil_tmp16 ;
  char *__cil_tmp17 ;
  char *__cil_tmp18 ;
  char *__cil_tmp19 ;
  char *__cil_tmp20 ;
  char *__cil_tmp21 ;
  char *__cil_tmp22 ;
  char *__cil_tmp23 ;
  char *__cil_tmp24 ;
  char *__cil_tmp25 ;
  char *__cil_tmp26 ;
  char *__cil_tmp27 ;

  {
  {
#line 87
  type = (int )*(buf + 0);
#line 88
  printf((char const   */* __restrict  */)"  DESC entry: block type %d\n", type);
  }
#line 92
  if (type == 2) {
#line 92
    goto case_2;
  }
#line 104
  if (type == 5) {
#line 104
    goto case_5;
  }
#line 130
  if (type == 6) {
#line 130
    goto case_6;
  }
#line 153
  goto switch_default;
  case_2: 
  {
#line 94
  skipLen = (UINT64 )0;
#line 95
  skipLen = (UINT64 )*(buf + 1);
#line 96
  skipLen |= (UINT64 )*(buf + 2) << 8;
#line 97
  skipLen |= (UINT64 )*(buf + 3) << 16;
#line 98
  skipLen |= (UINT64 )*(buf + 4) << 24;
#line 99
  skipLen |= (UINT64 )*(buf + 5) << 32;
#line 100
  skipLen |= (UINT64 )*(buf + 6) << 40;
#line 101
  printf((char const   */* __restrict  */)"    Unmatched data, %llu bytes\n", skipLen);
  }
#line 102
  return ((INT64 )7);
  case_5: 
  {
#line 106
  imglen = (UINT64 )0;
#line 107
  blocklen = (UINT32 )0;
#line 108
  i = 0;
#line 110
  imglen = (UINT64 )*(buf + 1);
#line 111
  imglen |= (UINT64 )*(buf + 2) << 8;
#line 112
  imglen |= (UINT64 )*(buf + 3) << 16;
#line 113
  imglen |= (UINT64 )*(buf + 4) << 24;
#line 114
  imglen |= (UINT64 )*(buf + 5) << 32;
#line 115
  imglen |= (UINT64 )*(buf + 6) << 40;
#line 117
  blocklen = (UINT32 )*(buf + 23);
#line 118
  blocklen |= (UINT32 )*(buf + 24) << 8;
#line 119
  blocklen |= (UINT32 )*(buf + 25) << 16;
#line 120
  blocklen |= (UINT32 )*(buf + 26) << 24;
#line 122
  printf((char const   */* __restrict  */)"    Original image length %llu bytes\n",
         imglen);
#line 123
  printf((char const   */* __restrict  */)"    Image MD5: ");
#line 124
  i = 7;
  }
  {
#line 124
  while (1) {
    while_continue: /* CIL Label */ ;

#line 124
    if (! (i < 23)) {
#line 124
      goto while_break;
    }
    {
#line 125
    printf((char const   */* __restrict  */)"%2.2x", (int )*(buf + i));
#line 124
    i ++;
    }
  }
  while_break___2: /* CIL Label */ ;
  }
  while_break: 
  {
#line 126
  tmp = base64_dump(buf + 7, (size_t )16);
#line 126
  printf((char const   */* __restrict  */)" (%s)\n", tmp);
#line 127
  printf((char const   */* __restrict  */)"    Rsync block length %lu bytes\n", blocklen);
  }
#line 128
  return ((INT64 )0);
  case_6: 
  {
#line 132
  fileLen = (UINT64 )0;
#line 133
  i___0 = 0;
#line 135
  fileLen = (UINT64 )*(buf + 1);
#line 136
  fileLen |= (UINT64 )*(buf + 2) << 8;
#line 137
  fileLen |= (UINT64 )*(buf + 3) << 16;
#line 138
  fileLen |= (UINT64 )*(buf + 4) << 24;
#line 139
  fileLen |= (UINT64 )*(buf + 5) << 32;
#line 140
  fileLen |= (UINT64 )*(buf + 6) << 40;
#line 142
  printf((char const   */* __restrict  */)"    File, length %llu bytes\n", fileLen);
#line 143
  printf((char const   */* __restrict  */)"    file rsyncsum: ");
#line 144
  i___0 = 7;
  }
  {
#line 144
  while (1) {
    while_continue___0: /* CIL Label */ ;

#line 144
    if (! (i___0 < 15)) {
#line 144
      goto while_break___0;
    }
    {
#line 145
    printf((char const   */* __restrict  */)"%2.2x", (int )*(buf + i___0));
#line 144
    i___0 ++;
    }
  }
  while_break___3: /* CIL Label */ ;
  }
  while_break___0: 
  {
#line 146
  tmp___0 = base64_dump(buf + 7, (size_t )8);
#line 146
  printf((char const   */* __restrict  */)" (%s)\n", tmp___0);
#line 147
  printf((char const   */* __restrict  */)"    file md5: ");
#line 148
  i___0 = 15;
  }
  {
#line 148
  while (1) {
    while_continue___1: /* CIL Label */ ;

#line 148
    if (! (i___0 < 31)) {
#line 148
      goto while_break___1;
    }
    {
#line 149
    airac_observe(buf, i___0);
#line 149
    printf((char const   */* __restrict  */)"%2.2x", (int )*(buf + i___0));
#line 148
    i___0 ++;
    }
  }
  while_break___4: /* CIL Label */ ;
  }
  while_break___1: 
  {
#line 150
  tmp___1 = base64_dump(buf + 15, (size_t )16);
#line 150
  printf((char const   */* __restrict  */)" (%s)\n", tmp___1);
  }
#line 151
  return ((INT64 )31);
  switch_default: 
#line 154
  goto switch_break;
  switch_break: ;
#line 157
  return ((INT64 )0);
}
}
#line 160 "/home/june/repo/benchmarks/collector/temp/jigit-1.19/jigdump.c"
int main(int argc , char **argv ) 
{ 
  char *filename ;
  int fd ;
  unsigned char *buf ;
  INT64 offset ;
  INT64 bytes ;
  e_state state ;
  int *tmp ;
  int *tmp___0 ;
  void *tmp___1 ;
  INT64 start_offset ;
  ssize_t tmp___2 ;
  INT64 start_offset___0 ;
  ssize_t tmp___3 ;
  INT64 tmp___4 ;
  INT64 tmp___5 ;
  INT64 tmp___6 ;
  char *__cil_tmp19 ;
  char *__cil_tmp20 ;
  char *__cil_tmp21 ;
  char *__cil_tmp22 ;
  char *__cil_tmp23 ;
  char *__cil_tmp24 ;
  char *__cil_tmp25 ;
  char *__cil_tmp26 ;

  {
#line 162
  filename = (char *)((void *)0);
#line 163
  fd = -1;
#line 164
  buf = (unsigned char *)((void *)0);
#line 165
  offset = (INT64 )0;
#line 166
  bytes = (INT64 )0;
#line 167
  state = (e_state )0;
#line 169
  if (argc != 2) {
    {
#line 171
    printf((char const   */* __restrict  */)"No filename specified! Try again...\n");
    }
#line 172
    return (22);
  }
  {
#line 175
  filename = *(argv + 1);
#line 177
  fd = open((char const   *)filename, 0);
  }
#line 178
  if (-1 == fd) {
    {
#line 180
    tmp = __errno_location();
#line 180
    printf((char const   */* __restrict  */)"Failed to open file %s, error %d!. Try again...\n",
           filename, *tmp);
#line 181
    tmp___0 = __errno_location();
    }
#line 181
    return (*tmp___0);
  }
  {
#line 184
  tmp___1 = malloc((size_t )65536);
#line 184
  buf = (unsigned char *)tmp___1;
  }
#line 185
  if (! buf) {
    {
#line 187
    printf((char const   */* __restrict  */)"Failed to malloc %d bytes. Abort!\n",
           65536);
    }
#line 188
    return (12);
  }
  {
#line 192
  while (1) {
    while_continue: /* CIL Label */ ;

#line 192
    if (! (0U == (unsigned int )state)) {
#line 192
      goto while_break;
    }
    {
#line 194
    start_offset = (INT64 )-1;
#line 196
    tmp___2 = read(fd, (void *)buf, (size_t )65536);
#line 196
    bytes = (INT64 )tmp___2;
    }
#line 197
    if (0LL >= bytes) {
#line 199
      state = (e_state )4;
#line 200
      goto while_break;
    }
    {
#line 202
    start_offset = find_string(buf, (size_t )bytes, (char *)"DATA");
    }
#line 203
    if (-1LL == start_offset) {
      {
#line 204
      start_offset = find_string(buf, (size_t )bytes, (char *)"BZIP");
      }
    }
#line 205
    if (start_offset >= 0LL) {
#line 207
      offset += start_offset;
#line 208
      state = (e_state )1;
#line 209
      goto while_break;
    }
#line 211
    offset += bytes;
  }
  while_break___1: /* CIL Label */ ;
  }
  while_break: ;
  {
#line 214
  while (1) {
    while_continue___0: /* CIL Label */ ;

#line 214
    if (4U != (unsigned int )state) {
#line 214
      if (! (5U != (unsigned int )state)) {
#line 214
        goto while_break___0;
      }
    } else {
#line 214
      goto while_break___0;
    }
    {
#line 216
    start_offset___0 = (INT64 )-1;
#line 217
    lseek(fd, (__off64_t )offset, 0);
#line 218
    tmp___3 = read(fd, (void *)buf, (size_t )65536);
#line 218
    bytes = (INT64 )tmp___3;
    }
#line 219
    if (0LL >= bytes) {
#line 221
      state = (e_state )5;
#line 222
      goto while_break___0;
    }
#line 224
    if (1U == (unsigned int )state) {
      {
#line 226
      tmp___4 = find_string(buf, (size_t )bytes, (char *)"DATA");
      }
#line 226
      if (tmp___4) {
        {
#line 226
        tmp___5 = find_string(buf, (size_t )bytes, (char *)"BZIP");
        }
#line 226
        if (! tmp___5) {
#line 227
          state = (e_state )1;
        }
      } else {
#line 227
        state = (e_state )1;
      }
      {
#line 228
      tmp___6 = find_string(buf, (size_t )bytes, (char *)"DESC");
      }
#line 228
      if (! tmp___6) {
#line 229
        state = (e_state )2;
      }
    }
#line 233
    if ((unsigned int )state == 1U) {
#line 233
      goto case_1;
    }
#line 237
    if ((unsigned int )state == 2U) {
#line 237
      goto case_2;
    }
#line 242
    if ((unsigned int )state == 3U) {
#line 242
      goto case_3;
    }
#line 248
    goto switch_default;
    case_1: 
    {
#line 234
    start_offset___0 = parse_data_block(offset, buf, (size_t )bytes);
#line 235
    offset += start_offset___0;
    }
#line 236
    goto switch_break;
    case_2: 
    {
#line 238
    start_offset___0 = parse_desc_block(offset, buf, (size_t )bytes);
#line 239
    offset += start_offset___0;
#line 240
    state = (e_state )3;
    }
#line 241
    goto switch_break;
    case_3: 
    {
#line 243
    start_offset___0 = parse_desc_data(offset, buf, (size_t )bytes);
#line 244
    offset += start_offset___0;
    }
#line 245
    if (0LL == start_offset___0) {
#line 246
      state = (e_state )4;
    }
#line 247
    goto switch_break;
    switch_default: 
#line 249
    goto switch_break;
    switch_break: ;
  }
  while_break___2: /* CIL Label */ ;
  }
  while_break___0: 
  {
#line 253
  close(fd);
  }
#line 255
  return (0);
}
}
#line 46 "/usr/include/string.h"
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1,2), __leaf__)) memcpy)(void * __restrict  __dest ,
                                                                                                 void const   * __restrict  __src ,
                                                                                                 size_t __n ) ;
#line 66
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1), __leaf__)) memset)(void *__s ,
                                                                                               int __c ,
                                                                                               size_t __n ) ;
#line 468 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) calloc)(size_t __nmemb ,
                                                                               size_t __size )  __attribute__((__malloc__)) ;
#line 19 "/home/june/repo/benchmarks/collector/temp/jigit-1.19/md5.h"
void mk_MD5Init(struct mk_MD5Context *ctx ) ;
#line 20
void mk_MD5Update(struct mk_MD5Context *ctx , unsigned char const   *buf , unsigned int len ) ;
#line 22
void mk_MD5Final(unsigned char *digest , struct mk_MD5Context *ctx ) ;
#line 24
void mk_MD5Transform(mk_uint32 *buf , unsigned char const   *inraw ) ;
#line 49 "/home/june/repo/benchmarks/collector/temp/jigit-1.19/md5.c"
static mk_uint32 getu32(unsigned char const   *addr ) 
{ 


  {
#line 53
  return (((((((unsigned long )*(addr + 3) << 8) | (unsigned long )*(addr + 2)) << 8) | (unsigned long )*(addr + 1)) << 8) | (unsigned long )*(addr + 0));
}
}
#line 57 "/home/june/repo/benchmarks/collector/temp/jigit-1.19/md5.c"
static void putu32(mk_uint32 data , unsigned char *addr ) 
{ 


  {
#line 62
  *(addr + 0) = (unsigned char )data;
#line 63
  *(addr + 1) = (unsigned char )(data >> 8);
#line 64
  *(addr + 2) = (unsigned char )(data >> 16);
#line 65
  *(addr + 3) = (unsigned char )(data >> 24);
#line 66
  return;
}
}
#line 72 "/home/june/repo/benchmarks/collector/temp/jigit-1.19/md5.c"
void mk_MD5Init(struct mk_MD5Context *ctx ) 
{ 


  {
#line 76
  ctx->buf[0] = (mk_uint32 )1732584193;
#line 77
  ctx->buf[1] = (mk_uint32 )4023233417U;
#line 78
  ctx->buf[2] = (mk_uint32 )2562383102U;
#line 79
  ctx->buf[3] = (mk_uint32 )271733878;
#line 81
  ctx->bits[0] = (mk_uint32 )0;
#line 82
  ctx->bits[1] = (mk_uint32 )0;
#line 83
  return;
}
}
#line 89 "/home/june/repo/benchmarks/collector/temp/jigit-1.19/md5.c"
void mk_MD5Update(struct mk_MD5Context *ctx , unsigned char const   *buf , unsigned int len ) 
{ 
  mk_uint32 t ;
  mk_uint32 tmp ;
  unsigned char *p ;

  {
#line 99
  t = ctx->bits[0];
#line 100
  tmp = (t + ((mk_uint32 )len << 3)) & 4294967295UL;
#line 100
  ctx->bits[0] = tmp;
#line 100
  if (tmp < t) {
#line 101
    (ctx->bits[1]) ++;
  }
#line 102
  ctx->bits[1] += (mk_uint32 )(len >> 29);
#line 104
  t = (t >> 3) & 63UL;
#line 108
  if (t) {
#line 109
    p = ctx->in + t;
#line 111
    t = 64UL - t;
#line 112
    if ((mk_uint32 )len < t) {
      {
#line 113
      memcpy((void */* __restrict  */)((void *)p), (void const   */* __restrict  */)((void const   *)buf),
             (size_t )len);
      }
#line 114
      return;
    }
    {
#line 116
    memcpy((void */* __restrict  */)((void *)p), (void const   */* __restrict  */)((void const   *)buf),
           t);
#line 117
    mk_MD5Transform(ctx->buf, (unsigned char const   *)(ctx->in));
#line 118
    buf += t;
#line 119
    len = (unsigned int )((mk_uint32 )len - t);
    }
  }
  {
#line 124
  while (1) {
    while_continue: /* CIL Label */ ;

#line 124
    if (! (len >= 64U)) {
#line 124
      goto while_break;
    }
    {
#line 125
    memcpy((void */* __restrict  */)((void *)(ctx->in)), (void const   */* __restrict  */)((void const   *)buf),
           (size_t )64);
#line 126
    mk_MD5Transform(ctx->buf, (unsigned char const   *)(ctx->in));
#line 127
    buf += 64;
#line 128
    len -= 64U;
    }
  }
  while_break___0: /* CIL Label */ ;
  }
  while_break: 
  {
#line 133
  memcpy((void */* __restrict  */)((void *)(ctx->in)), (void const   */* __restrict  */)((void const   *)buf),
         (size_t )len);
  }
#line 134
  return;
}
}
#line 140 "/home/june/repo/benchmarks/collector/temp/jigit-1.19/md5.c"
void mk_MD5Final(unsigned char *digest , struct mk_MD5Context *ctx ) 
{ 
  unsigned int count ;
  unsigned char *p ;
  unsigned char *tmp ;

  {
#line 149
  count = (unsigned int )((ctx->bits[0] >> 3) & 63UL);
#line 153
  p = ctx->in + count;
#line 154
  tmp = p;
#line 154
  p ++;
#line 154
  *tmp = (unsigned char)128;
#line 157
  count = 63U - count;
#line 160
  if (count < 8U) {
    {
#line 162
    memset((void *)p, 0, (size_t )count);
#line 163
    mk_MD5Transform(ctx->buf, (unsigned char const   *)(ctx->in));
#line 166
    memset((void *)(ctx->in), 0, (size_t )56);
    }
  } else {
    {
#line 169
    memset((void *)p, 0, (size_t )(count - 8U));
    }
  }
  {
#line 173
  putu32(ctx->bits[0], ctx->in + 56);
#line 174
  putu32(ctx->bits[1], ctx->in + 60);
#line 176
  mk_MD5Transform(ctx->buf, (unsigned char const   *)(ctx->in));
#line 177
  putu32(ctx->buf[0], digest);
#line 178
  putu32(ctx->buf[1], digest + 4);
#line 179
  putu32(ctx->buf[2], digest + 8);
#line 180
  putu32(ctx->buf[3], digest + 12);
#line 181
  memset((void *)ctx, 0, sizeof(ctx));
  }
#line 182
  return;
}
}
#line 203 "/home/june/repo/benchmarks/collector/temp/jigit-1.19/md5.c"
void mk_MD5Transform(mk_uint32 *buf , unsigned char const   *inraw ) 
{ 
  register mk_uint32 a ;
  register mk_uint32 b ;
  register mk_uint32 c ;
  register mk_uint32 d ;
  mk_uint32 in[16] ;
  int i ;
  void *__cil_tmp9 ;

  {
#line 212
  i = 0;
  {
#line 212
  while (1) {
    while_continue: /* CIL Label */ ;

#line 212
    if (! (i < 16)) {
#line 212
      goto while_break;
    }
    {
#line 213
    in[i] = getu32(inraw + 4 * i);
#line 212
    i ++;
    }
  }
  while_break___0: /* CIL Label */ ;
  }
  while_break: 
#line 215
  a = *(buf + 0);
#line 216
  b = *(buf + 1);
#line 217
  c = *(buf + 2);
#line 218
  d = *(buf + 3);
#line 220
  a += ((d ^ (b & (c ^ d))) + in[0]) + 3614090360UL;
#line 220
  a &= 4294967295UL;
#line 220
  a = (a << 7) | (a >> 25);
#line 220
  a += b;
#line 221
  d += ((c ^ (a & (b ^ c))) + in[1]) + 3905402710UL;
#line 221
  d &= 4294967295UL;
#line 221
  d = (d << 12) | (d >> 20);
#line 221
  d += a;
#line 222
  c += ((b ^ (d & (a ^ b))) + in[2]) + 606105819UL;
#line 222
  c &= 4294967295UL;
#line 222
  c = (c << 17) | (c >> 15);
#line 222
  c += d;
#line 223
  b += ((a ^ (c & (d ^ a))) + in[3]) + 3250441966UL;
#line 223
  b &= 4294967295UL;
#line 223
  b = (b << 22) | (b >> 10);
#line 223
  b += c;
#line 224
  a += ((d ^ (b & (c ^ d))) + in[4]) + 4118548399UL;
#line 224
  a &= 4294967295UL;
#line 224
  a = (a << 7) | (a >> 25);
#line 224
  a += b;
#line 225
  d += ((c ^ (a & (b ^ c))) + in[5]) + 1200080426UL;
#line 225
  d &= 4294967295UL;
#line 225
  d = (d << 12) | (d >> 20);
#line 225
  d += a;
#line 226
  c += ((b ^ (d & (a ^ b))) + in[6]) + 2821735955UL;
#line 226
  c &= 4294967295UL;
#line 226
  c = (c << 17) | (c >> 15);
#line 226
  c += d;
#line 227
  b += ((a ^ (c & (d ^ a))) + in[7]) + 4249261313UL;
#line 227
  b &= 4294967295UL;
#line 227
  b = (b << 22) | (b >> 10);
#line 227
  b += c;
#line 228
  a += ((d ^ (b & (c ^ d))) + in[8]) + 1770035416UL;
#line 228
  a &= 4294967295UL;
#line 228
  a = (a << 7) | (a >> 25);
#line 228
  a += b;
#line 229
  d += ((c ^ (a & (b ^ c))) + in[9]) + 2336552879UL;
#line 229
  d &= 4294967295UL;
#line 229
  d = (d << 12) | (d >> 20);
#line 229
  d += a;
#line 230
  c += ((b ^ (d & (a ^ b))) + in[10]) + 4294925233UL;
#line 230
  c &= 4294967295UL;
#line 230
  c = (c << 17) | (c >> 15);
#line 230
  c += d;
#line 231
  b += ((a ^ (c & (d ^ a))) + in[11]) + 2304563134UL;
#line 231
  b &= 4294967295UL;
#line 231
  b = (b << 22) | (b >> 10);
#line 231
  b += c;
#line 232
  a += ((d ^ (b & (c ^ d))) + in[12]) + 1804603682UL;
#line 232
  a &= 4294967295UL;
#line 232
  a = (a << 7) | (a >> 25);
#line 232
  a += b;
#line 233
  d += ((c ^ (a & (b ^ c))) + in[13]) + 4254626195UL;
#line 233
  d &= 4294967295UL;
#line 233
  d = (d << 12) | (d >> 20);
#line 233
  d += a;
#line 234
  c += ((b ^ (d & (a ^ b))) + in[14]) + 2792965006UL;
#line 234
  c &= 4294967295UL;
#line 234
  c = (c << 17) | (c >> 15);
#line 234
  c += d;
#line 235
  b += ((a ^ (c & (d ^ a))) + in[15]) + 1236535329UL;
#line 235
  b &= 4294967295UL;
#line 235
  b = (b << 22) | (b >> 10);
#line 235
  b += c;
#line 237
  a += ((c ^ (d & (b ^ c))) + in[1]) + 4129170786UL;
#line 237
  a &= 4294967295UL;
#line 237
  a = (a << 5) | (a >> 27);
#line 237
  a += b;
#line 238
  d += ((b ^ (c & (a ^ b))) + in[6]) + 3225465664UL;
#line 238
  d &= 4294967295UL;
#line 238
  d = (d << 9) | (d >> 23);
#line 238
  d += a;
#line 239
  c += ((a ^ (b & (d ^ a))) + in[11]) + 643717713UL;
#line 239
  c &= 4294967295UL;
#line 239
  c = (c << 14) | (c >> 18);
#line 239
  c += d;
#line 240
  b += ((d ^ (a & (c ^ d))) + in[0]) + 3921069994UL;
#line 240
  b &= 4294967295UL;
#line 240
  b = (b << 20) | (b >> 12);
#line 240
  b += c;
#line 241
  a += ((c ^ (d & (b ^ c))) + in[5]) + 3593408605UL;
#line 241
  a &= 4294967295UL;
#line 241
  a = (a << 5) | (a >> 27);
#line 241
  a += b;
#line 242
  d += ((b ^ (c & (a ^ b))) + in[10]) + 38016083UL;
#line 242
  d &= 4294967295UL;
#line 242
  d = (d << 9) | (d >> 23);
#line 242
  d += a;
#line 243
  c += ((a ^ (b & (d ^ a))) + in[15]) + 3634488961UL;
#line 243
  c &= 4294967295UL;
#line 243
  c = (c << 14) | (c >> 18);
#line 243
  c += d;
#line 244
  b += ((d ^ (a & (c ^ d))) + in[4]) + 3889429448UL;
#line 244
  b &= 4294967295UL;
#line 244
  b = (b << 20) | (b >> 12);
#line 244
  b += c;
#line 245
  a += ((c ^ (d & (b ^ c))) + in[9]) + 568446438UL;
#line 245
  a &= 4294967295UL;
#line 245
  a = (a << 5) | (a >> 27);
#line 245
  a += b;
#line 246
  d += ((b ^ (c & (a ^ b))) + in[14]) + 3275163606UL;
#line 246
  d &= 4294967295UL;
#line 246
  d = (d << 9) | (d >> 23);
#line 246
  d += a;
#line 247
  c += ((a ^ (b & (d ^ a))) + in[3]) + 4107603335UL;
#line 247
  c &= 4294967295UL;
#line 247
  c = (c << 14) | (c >> 18);
#line 247
  c += d;
#line 248
  b += ((d ^ (a & (c ^ d))) + in[8]) + 1163531501UL;
#line 248
  b &= 4294967295UL;
#line 248
  b = (b << 20) | (b >> 12);
#line 248
  b += c;
#line 249
  a += ((c ^ (d & (b ^ c))) + in[13]) + 2850285829UL;
#line 249
  a &= 4294967295UL;
#line 249
  a = (a << 5) | (a >> 27);
#line 249
  a += b;
#line 250
  d += ((b ^ (c & (a ^ b))) + in[2]) + 4243563512UL;
#line 250
  d &= 4294967295UL;
#line 250
  d = (d << 9) | (d >> 23);
#line 250
  d += a;
#line 251
  c += ((a ^ (b & (d ^ a))) + in[7]) + 1735328473UL;
#line 251
  c &= 4294967295UL;
#line 251
  c = (c << 14) | (c >> 18);
#line 251
  c += d;
#line 252
  b += ((d ^ (a & (c ^ d))) + in[12]) + 2368359562UL;
#line 252
  b &= 4294967295UL;
#line 252
  b = (b << 20) | (b >> 12);
#line 252
  b += c;
#line 254
  a += (((b ^ c) ^ d) + in[5]) + 4294588738UL;
#line 254
  a &= 4294967295UL;
#line 254
  a = (a << 4) | (a >> 28);
#line 254
  a += b;
#line 255
  d += (((a ^ b) ^ c) + in[8]) + 2272392833UL;
#line 255
  d &= 4294967295UL;
#line 255
  d = (d << 11) | (d >> 21);
#line 255
  d += a;
#line 256
  c += (((d ^ a) ^ b) + in[11]) + 1839030562UL;
#line 256
  c &= 4294967295UL;
#line 256
  c = (c << 16) | (c >> 16);
#line 256
  c += d;
#line 257
  b += (((c ^ d) ^ a) + in[14]) + 4259657740UL;
#line 257
  b &= 4294967295UL;
#line 257
  b = (b << 23) | (b >> 9);
#line 257
  b += c;
#line 258
  a += (((b ^ c) ^ d) + in[1]) + 2763975236UL;
#line 258
  a &= 4294967295UL;
#line 258
  a = (a << 4) | (a >> 28);
#line 258
  a += b;
#line 259
  d += (((a ^ b) ^ c) + in[4]) + 1272893353UL;
#line 259
  d &= 4294967295UL;
#line 259
  d = (d << 11) | (d >> 21);
#line 259
  d += a;
#line 260
  c += (((d ^ a) ^ b) + in[7]) + 4139469664UL;
#line 260
  c &= 4294967295UL;
#line 260
  c = (c << 16) | (c >> 16);
#line 260
  c += d;
#line 261
  b += (((c ^ d) ^ a) + in[10]) + 3200236656UL;
#line 261
  b &= 4294967295UL;
#line 261
  b = (b << 23) | (b >> 9);
#line 261
  b += c;
#line 262
  a += (((b ^ c) ^ d) + in[13]) + 681279174UL;
#line 262
  a &= 4294967295UL;
#line 262
  a = (a << 4) | (a >> 28);
#line 262
  a += b;
#line 263
  d += (((a ^ b) ^ c) + in[0]) + 3936430074UL;
#line 263
  d &= 4294967295UL;
#line 263
  d = (d << 11) | (d >> 21);
#line 263
  d += a;
#line 264
  c += (((d ^ a) ^ b) + in[3]) + 3572445317UL;
#line 264
  c &= 4294967295UL;
#line 264
  c = (c << 16) | (c >> 16);
#line 264
  c += d;
#line 265
  b += (((c ^ d) ^ a) + in[6]) + 76029189UL;
#line 265
  b &= 4294967295UL;
#line 265
  b = (b << 23) | (b >> 9);
#line 265
  b += c;
#line 266
  a += (((b ^ c) ^ d) + in[9]) + 3654602809UL;
#line 266
  a &= 4294967295UL;
#line 266
  a = (a << 4) | (a >> 28);
#line 266
  a += b;
#line 267
  d += (((a ^ b) ^ c) + in[12]) + 3873151461UL;
#line 267
  d &= 4294967295UL;
#line 267
  d = (d << 11) | (d >> 21);
#line 267
  d += a;
#line 268
  c += (((d ^ a) ^ b) + in[15]) + 530742520UL;
#line 268
  c &= 4294967295UL;
#line 268
  c = (c << 16) | (c >> 16);
#line 268
  c += d;
#line 269
  b += (((c ^ d) ^ a) + in[2]) + 3299628645UL;
#line 269
  b &= 4294967295UL;
#line 269
  b = (b << 23) | (b >> 9);
#line 269
  b += c;
#line 271
  a += ((c ^ (b | ~ d)) + in[0]) + 4096336452UL;
#line 271
  a &= 4294967295UL;
#line 271
  a = (a << 6) | (a >> 26);
#line 271
  a += b;
#line 272
  d += ((b ^ (a | ~ c)) + in[7]) + 1126891415UL;
#line 272
  d &= 4294967295UL;
#line 272
  d = (d << 10) | (d >> 22);
#line 272
  d += a;
#line 273
  c += ((a ^ (d | ~ b)) + in[14]) + 2878612391UL;
#line 273
  c &= 4294967295UL;
#line 273
  c = (c << 15) | (c >> 17);
#line 273
  c += d;
#line 274
  b += ((d ^ (c | ~ a)) + in[5]) + 4237533241UL;
#line 274
  b &= 4294967295UL;
#line 274
  b = (b << 21) | (b >> 11);
#line 274
  b += c;
#line 275
  a += ((c ^ (b | ~ d)) + in[12]) + 1700485571UL;
#line 275
  a &= 4294967295UL;
#line 275
  a = (a << 6) | (a >> 26);
#line 275
  a += b;
#line 276
  d += ((b ^ (a | ~ c)) + in[3]) + 2399980690UL;
#line 276
  d &= 4294967295UL;
#line 276
  d = (d << 10) | (d >> 22);
#line 276
  d += a;
#line 277
  c += ((a ^ (d | ~ b)) + in[10]) + 4293915773UL;
#line 277
  c &= 4294967295UL;
#line 277
  c = (c << 15) | (c >> 17);
#line 277
  c += d;
#line 278
  b += ((d ^ (c | ~ a)) + in[1]) + 2240044497UL;
#line 278
  b &= 4294967295UL;
#line 278
  b = (b << 21) | (b >> 11);
#line 278
  b += c;
#line 279
  a += ((c ^ (b | ~ d)) + in[8]) + 1873313359UL;
#line 279
  a &= 4294967295UL;
#line 279
  a = (a << 6) | (a >> 26);
#line 279
  a += b;
#line 280
  d += ((b ^ (a | ~ c)) + in[15]) + 4264355552UL;
#line 280
  d &= 4294967295UL;
#line 280
  d = (d << 10) | (d >> 22);
#line 280
  d += a;
#line 281
  c += ((a ^ (d | ~ b)) + in[6]) + 2734768916UL;
#line 281
  c &= 4294967295UL;
#line 281
  c = (c << 15) | (c >> 17);
#line 281
  c += d;
#line 282
  b += ((d ^ (c | ~ a)) + in[13]) + 1309151649UL;
#line 282
  b &= 4294967295UL;
#line 282
  b = (b << 21) | (b >> 11);
#line 282
  b += c;
#line 283
  a += ((c ^ (b | ~ d)) + in[4]) + 4149444226UL;
#line 283
  a &= 4294967295UL;
#line 283
  a = (a << 6) | (a >> 26);
#line 283
  a += b;
#line 284
  d += ((b ^ (a | ~ c)) + in[11]) + 3174756917UL;
#line 284
  d &= 4294967295UL;
#line 284
  d = (d << 10) | (d >> 22);
#line 284
  d += a;
#line 285
  c += ((a ^ (d | ~ b)) + in[2]) + 718787259UL;
#line 285
  c &= 4294967295UL;
#line 285
  c = (c << 15) | (c >> 17);
#line 285
  c += d;
#line 286
  b += ((d ^ (c | ~ a)) + in[9]) + 3951481745UL;
#line 286
  b &= 4294967295UL;
#line 286
  b = (b << 21) | (b >> 11);
#line 286
  b += c;
#line 288
  *(buf + 0) += a;
#line 289
  *(buf + 1) += b;
#line 290
  *(buf + 2) += c;
#line 291
  *(buf + 3) += d;
#line 292
  return;
}
}
#line 295 "/home/june/repo/benchmarks/collector/temp/jigit-1.19/md5.c"
char *base64_dump(unsigned char *buf , size_t buf_size ) 
{ 
  char const   *b64_enc ;
  int value ;
  unsigned int i ;
  int bits ;
  char *out ;
  void *tmp ;
  unsigned int out_pos ;
  unsigned int tmp___0 ;
  unsigned int tmp___1 ;
  unsigned int tmp___2 ;
  char *__cil_tmp13 ;

  {
  {
#line 297
  b64_enc = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";
#line 298
  value = 0;
#line 300
  bits = 0;
#line 301
  tmp = calloc((size_t )1, (size_t )30);
#line 301
  out = (char *)tmp;
#line 302
  out_pos = 0U;
  }
#line 304
  if (! out) {
#line 305
    return ((char *)((void *)0));
  }
#line 307
  i = 0U;
  {
#line 307
  while (1) {
    while_continue: /* CIL Label */ ;

#line 307
    if (! ((size_t )i < buf_size)) {
#line 307
      goto while_break;
    }
#line 309
    value = (value << 8) | (int )*(buf + i);
#line 310
    bits += 2;
#line 311
    tmp___0 = out_pos;
#line 311
    out_pos ++;
#line 311
    *(out + tmp___0) = (char )*(b64_enc + ((unsigned int )(value >> bits) & 63U));
#line 312
    if (bits >= 6) {
#line 313
      bits -= 6;
#line 314
      tmp___1 = out_pos;
#line 314
      out_pos ++;
#line 314
      *(out + tmp___1) = (char )*(b64_enc + ((unsigned int )(value >> bits) & 63U));
    }
#line 307
    i ++;
  }
  while_break___0: /* CIL Label */ ;
  }
  while_break: ;
#line 317
  if (bits > 0) {
#line 319
    value <<= 6 - bits;
#line 320
    tmp___2 = out_pos;
#line 320
    out_pos ++;
#line 320
    *(out + tmp___2) = (char )*(b64_enc + ((unsigned int )value & 63U));
  }
#line 322
  return (out);
}
}