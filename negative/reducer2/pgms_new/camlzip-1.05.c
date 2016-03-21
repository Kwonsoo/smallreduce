/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is false */

#line 368 "/usr/include/x86_64-linux-gnu/zconf.h"
typedef unsigned char Byte;
#line 370 "/usr/include/x86_64-linux-gnu/zconf.h"
typedef unsigned int uInt;
#line 371 "/usr/include/x86_64-linux-gnu/zconf.h"
typedef unsigned long uLong;
#line 377 "/usr/include/x86_64-linux-gnu/zconf.h"
typedef Byte Bytef;
#line 382 "/usr/include/x86_64-linux-gnu/zconf.h"
typedef uLong uLongf;
#line 386 "/usr/include/x86_64-linux-gnu/zconf.h"
typedef void *voidpf;
#line 83 "/usr/include/zlib.h"
struct internal_state;
#line 83
struct internal_state;
#line 85 "/usr/include/zlib.h"
struct z_stream_s {
   Bytef *next_in ;
   uInt avail_in ;
   uLong total_in ;
   Bytef *next_out ;
   uInt avail_out ;
   uLong total_out ;
   char *msg ;
   struct internal_state *state ;
   voidpf (*zalloc)(voidpf opaque , uInt items , uInt size ) ;
   void (*zfree)(voidpf opaque , voidpf address ) ;
   voidpf opaque ;
   int data_type ;
   uLong adler ;
   uLong reserved ;
};
#line 85 "/usr/include/zlib.h"
typedef struct z_stream_s z_stream;
#line 106 "/usr/include/zlib.h"
typedef z_stream *z_streamp;
#line 1742 "/usr/include/zlib.h"
struct internal_state {
   int dummy ;
};
#line 94 "/usr/lib/ocaml/caml/config.h"
typedef int int32;
#line 95 "/usr/lib/ocaml/caml/config.h"
typedef unsigned int uint32;
#line 128 "/usr/lib/ocaml/caml/config.h"
typedef long intnat;
#line 129 "/usr/lib/ocaml/caml/config.h"
typedef unsigned long uintnat;
#line 58 "/usr/lib/ocaml/caml/mlvalues.h"
typedef intnat value;
#line 60 "/usr/lib/ocaml/caml/mlvalues.h"
typedef uintnat mlsize_t;
#line 61 "/usr/lib/ocaml/caml/mlvalues.h"
typedef unsigned int tag_t;
#line 49 "/usr/lib/ocaml/caml/memory.h"
struct caml__roots_block {
   struct caml__roots_block *next ;
   intnat ntables ;
   intnat nitems ;
   value *tables[5] ;
};
#line 246 "/usr/include/zlib.h"
extern int deflate(z_streamp strm , int flush ) ;
#line 353
extern int deflateEnd(z_streamp strm ) ;
#line 392
extern int inflate(z_streamp strm , int flush ) ;
#line 508
extern int inflateEnd(z_streamp strm ) ;
#line 1197
extern int uncompress(Bytef *dest , uLongf *destLen , Bytef const   *source , uLong sourceLen ) ;
#line 1600
extern uLong crc32(uLong crc , Bytef const   *buf , uInt len ) ;
#line 1637
extern int deflateInit2_(z_streamp strm , int level , int method , int windowBits ,
                         int memLevel , int strategy , char const   *version , int stream_size ) ;
#line 1641
extern int inflateInit2_(z_streamp strm , int windowBits , char const   *version ,
                         int stream_size ) ;
#line 28 "/usr/lib/ocaml/caml/alloc.h"
extern value caml_alloc(mlsize_t  , tag_t  ) ;
#line 29
extern value caml_alloc_small(mlsize_t  , tag_t  ) ;
#line 32
extern value caml_copy_string(char const   * ) ;
#line 35
extern value caml_copy_int32(int32  ) ;
#line 44 "/usr/lib/ocaml/caml/callback.h"
extern value *caml_named_value(char const   *name ) ;
#line 29 "/usr/lib/ocaml/caml/fail.h"
extern  __attribute__((__noreturn__)) void caml_raise(value bucket ) ;
#line 36
extern  __attribute__((__noreturn__)) void caml_invalid_argument(char const   * ) ;
#line 56 "/usr/lib/ocaml/caml/memory.h"
extern struct caml__roots_block *caml_local_roots ;
#line 28 "/home/june/repo/benchmarks/collector/temp/camlzip-1.05/zlibstubs.c"
static value *camlzip_error_exn  =    (value *)((void *)0);
#line 30 "/home/june/repo/benchmarks/collector/temp/camlzip-1.05/zlibstubs.c"
static void camlzip_error(char *fn , value vzs ) 
{ 
  char *msg ;
  value s1 ;
  value s2 ;
  value bucket ;
  struct caml__roots_block caml__roots_block ;

  {
#line 33
  s1 = 1L;
#line 33
  s2 = 1L;
#line 33
  bucket = 1L;
#line 35
  msg = ((z_stream *)vzs)->msg;
#line 36
  if ((unsigned long )msg == (unsigned long )((void *)0)) {
#line 36
    msg = (char *)"";
  }
#line 37
  if ((unsigned long )camlzip_error_exn == (unsigned long )((void *)0)) {
    {
#line 38
    camlzip_error_exn = caml_named_value("Zlib.Error");
    }
#line 39
    if ((unsigned long )camlzip_error_exn == (unsigned long )((void *)0)) {
      {
#line 40
      caml_invalid_argument("Exception Zlib.Error not initialized");
      }
    }
  }
  {
#line 42
  caml__roots_block.next = caml_local_roots;
#line 42
  caml_local_roots = & caml__roots_block;
#line 42
  caml__roots_block.nitems = (intnat )1;
#line 42
  caml__roots_block.ntables = (intnat )3;
#line 42
  caml__roots_block.tables[0] = & s1;
#line 42
  caml__roots_block.tables[1] = & s2;
#line 42
  caml__roots_block.tables[2] = & bucket;
#line 43
  s1 = caml_copy_string((char const   *)fn);
#line 44
  s2 = caml_copy_string((char const   *)msg);
#line 45
  bucket = caml_alloc_small((mlsize_t )3, (tag_t )0);
#line 46
  *((value *)bucket + 0) = *camlzip_error_exn;
#line 47
  *((value *)bucket + 1) = s1;
#line 48
  *((value *)bucket + 2) = s2;
#line 49
  caml_local_roots = caml__roots_block.next;
#line 50
  caml_raise(bucket);
  }
}
}
#line 53 "/home/june/repo/benchmarks/collector/temp/camlzip-1.05/zlibstubs.c"
static value camlzip_new_stream(void) 
{ 
  value res ;
  value tmp ;

  {
  {
#line 55
  tmp = caml_alloc(((sizeof(z_stream ) + sizeof(value )) - 1UL) / sizeof(value ),
                   (tag_t )251);
#line 55
  res = tmp;
#line 57
  ((z_stream *)res)->zalloc = (voidpf (*)(voidpf opaque , uInt items , uInt size ))((void *)0);
#line 58
  ((z_stream *)res)->zfree = (void (*)(voidpf opaque , voidpf address ))((void *)0);
#line 59
  ((z_stream *)res)->opaque = (void *)0;
#line 60
  ((z_stream *)res)->next_in = (Bytef *)((void *)0);
#line 61
  ((z_stream *)res)->next_out = (Bytef *)((void *)0);
  }
#line 62
  return (res);
}
}
#line 65 "/home/june/repo/benchmarks/collector/temp/camlzip-1.05/zlibstubs.c"
value camlzip_deflateInit(value vlevel , value expect_header ) 
{ 
  value vzs ;
  value tmp ;
  int tmp___0 ;
  int tmp___1 ;

  {
  {
#line 67
  tmp = camlzip_new_stream();
#line 67
  vzs = tmp;
  }
#line 68
  if ((int )(expect_header >> 1)) {
#line 68
    tmp___0 = 15;
  } else {
#line 68
    tmp___0 = -15;
  }
  {
#line 68
  tmp___1 = deflateInit2_((z_stream *)vzs, (int )(vlevel >> 1), 8, tmp___0, 8, 0,
                          "1.2.8", (int )sizeof(z_stream ));
  }
#line 68
  if (tmp___1 != 0) {
    {
#line 74
    camlzip_error((char *)"Zlib.deflateInit", vzs);
    }
  }
#line 75
  return (vzs);
}
}
#line 78 "/home/june/repo/benchmarks/collector/temp/camlzip-1.05/zlibstubs.c"
static int camlzip_flush_table[4]  = {      0,      2,      3,      4};
#line 81 "/home/june/repo/benchmarks/collector/temp/camlzip-1.05/zlibstubs.c"
value camlzip_deflate(value vzs , value srcbuf , value srcpos , value srclen , value dstbuf ,
                      value dstpos , value dstlen , value vflush ) 
{ 
  z_stream *zs ;
  int retcode ;
  long used_in ;
  long used_out ;
  value res ;

  {
  {
#line 85
  zs = (z_stream *)vzs;
#line 90
  zs->next_in = (unsigned char *)srcbuf + (srcpos >> 1);
#line 91
  zs->avail_in = (uInt )(srclen >> 1);
#line 92
  zs->next_out = (unsigned char *)dstbuf + (dstpos >> 1);
#line 93
  zs->avail_out = (uInt )(dstlen >> 1);
#line 94
  retcode = deflate(zs, camlzip_flush_table[(int )(vflush >> 1)]);
  }
#line 95
  if (retcode < 0) {
    {
#line 95
    camlzip_error((char *)"Zlib.deflate", vzs);
    }
  }
  {
#line 96
  used_in = (srclen >> 1) - (value )zs->avail_in;
#line 97
  used_out = (dstlen >> 1) - (value )zs->avail_out;
#line 98
  zs->next_in = (Bytef *)((void *)0);
#line 99
  zs->next_out = (Bytef *)((void *)0);
#line 100
  res = caml_alloc_small((mlsize_t )3, (tag_t )0);
#line 101
  *((value *)res + 0) = ((intnat )((retcode == 1) != 0) << 1) + 1L;
#line 102
  *((value *)res + 1) = (used_in << 1) + 1L;
#line 103
  *((value *)res + 2) = (used_out << 1) + 1L;
  }
#line 104
  return (res);
}
}
#line 107 "/home/june/repo/benchmarks/collector/temp/camlzip-1.05/zlibstubs.c"
value camlzip_deflate_bytecode(value *arg , int nargs ) 
{ 
  value tmp ;

  {
  {
#line 109
  tmp = camlzip_deflate(*(arg + 0), *(arg + 1), *(arg + 2), *(arg + 3), *(arg + 4),
                        *(arg + 5), *(arg + 6), *(arg + 7));
  }
#line 109
  return (tmp);
}
}
#line 113 "/home/june/repo/benchmarks/collector/temp/camlzip-1.05/zlibstubs.c"
value camlzip_deflateEnd(value vzs ) 
{ 
  int tmp ;

  {
  {
#line 115
  tmp = deflateEnd((z_stream *)vzs);
  }
#line 115
  if (tmp != 0) {
    {
#line 116
    camlzip_error((char *)"Zlib.deflateEnd", vzs);
    }
  }
#line 117
  return (1L);
}
}
#line 120 "/home/june/repo/benchmarks/collector/temp/camlzip-1.05/zlibstubs.c"
value camlzip_inflateInit(value expect_header ) 
{ 
  value vzs ;
  value tmp ;
  int tmp___0 ;
  int tmp___1 ;

  {
  {
#line 122
  tmp = camlzip_new_stream();
#line 122
  vzs = tmp;
  }
#line 123
  if ((int )(expect_header >> 1)) {
#line 123
    tmp___0 = 15;
  } else {
#line 123
    tmp___0 = -15;
  }
  {
#line 123
  tmp___1 = inflateInit2_((z_stream *)vzs, tmp___0, "1.2.8", (int )sizeof(z_stream ));
  }
#line 123
  if (tmp___1 != 0) {
    {
#line 125
    camlzip_error((char *)"Zlib.inflateInit", vzs);
    }
  }
#line 126
  return (vzs);
}
}
#line 129 "/home/june/repo/benchmarks/collector/temp/camlzip-1.05/zlibstubs.c"
value camlzip_inflate(value vzs , value srcbuf , value srcpos , value srclen , value dstbuf ,
                      value dstpos , value dstlen , value vflush ) 
{ 
  z_stream *zs ;
  int retcode ;
  long used_in ;
  long used_out ;
  value res ;

  {
  {
#line 133
  zs = (z_stream *)vzs;
#line 138
  zs->next_in = (unsigned char *)srcbuf + (srcpos >> 1);
#line 139
  zs->avail_in = (uInt )(srclen >> 1);
#line 140
  zs->next_out = (unsigned char *)dstbuf + (dstpos >> 1);
#line 141
  zs->avail_out = (uInt )(dstlen >> 1);
#line 142
  retcode = inflate(zs, camlzip_flush_table[(int )(vflush >> 1)]);
  }
#line 143
  if (retcode < 0) {
    {
#line 144
    camlzip_error((char *)"Zlib.inflate", vzs);
    }
  } else
#line 143
  if (retcode == 2) {
    {
#line 144
    camlzip_error((char *)"Zlib.inflate", vzs);
    }
  }
  {
#line 145
  used_in = (srclen >> 1) - (value )zs->avail_in;
#line 146
  used_out = (dstlen >> 1) - (value )zs->avail_out;
#line 147
  zs->next_in = (Bytef *)((void *)0);
#line 148
  zs->next_out = (Bytef *)((void *)0);
#line 149
  res = caml_alloc_small((mlsize_t )3, (tag_t )0);
#line 150
  *((value *)res + 0) = ((intnat )((retcode == 1) != 0) << 1) + 1L;
#line 151
  *((value *)res + 1) = (used_in << 1) + 1L;
#line 152
  *((value *)res + 2) = (used_out << 1) + 1L;
  }
#line 153
  return (res);
}
}
#line 156 "/home/june/repo/benchmarks/collector/temp/camlzip-1.05/zlibstubs.c"
value camlzip_inflate_bytecode(value *arg , int nargs ) 
{ 
  value tmp ;

  {
  {
#line 158
  tmp = camlzip_inflate(*(arg + 0), *(arg + 1), *(arg + 2), *(arg + 3), *(arg + 4),
                        *(arg + 5), *(arg + 6), *(arg + 7));
  }
#line 158
  return (tmp);
}
}
#line 162 "/home/june/repo/benchmarks/collector/temp/camlzip-1.05/zlibstubs.c"
value camlzip_inflateEnd(value vzs ) 
{ 
  int tmp ;

  {
  {
#line 164
  tmp = inflateEnd((z_stream *)vzs);
  }
#line 164
  if (tmp != 0) {
    {
#line 165
    camlzip_error((char *)"Zlib.inflateEnd", vzs);
    }
  }
#line 166
  return (1L);
}
}
#line 169 "/home/june/repo/benchmarks/collector/temp/camlzip-1.05/zlibstubs.c"
value camlzip_update_crc32(value crc , value buf , value pos , value len ) 
{ 
  uLong tmp ;
  value tmp___0 ;

  {
  {
#line 171
  tmp = crc32((uLong )((uint32 )*((int32 *)((void *)((value *)crc + 1)))), (Bytef const   *)((unsigned char *)buf + (pos >> 1)),
              (uInt )(len >> 1));
#line 171
  tmp___0 = caml_copy_int32((int32 )tmp);
  }
#line 171
  return (tmp___0);
}
}
#line 177 "/home/june/repo/benchmarks/collector/temp/camlzip-1.05/zlibstubs.c"
value camlzip_uncompress(value dest , value destlen , value src , value srclen ) 
{ 
  unsigned long destlenc ;
  unsigned long srclenc ;
  int status ;

  {
  {
#line 179
  destlenc = (unsigned long )((int )(destlen >> 1));
#line 180
  srclenc = (unsigned long )((int )(srclen >> 1));
#line 182
  status = uncompress((Bytef *)((char *)dest), & destlenc, (Bytef const   *)((char *)src),
                      srclenc);
  }
#line 183
  if (status == 0) {
#line 183
    return ((1L << 1) + 1L);
  } else {
#line 184
    return (1L);
  }
}
}