/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is false */

#line 212 "/usr/lib/gcc/x86_64-linux-gnu/4.8/include/stddef.h"
typedef unsigned long size_t;
#line 131 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __off_t;
#line 132 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __off64_t;
#line 189 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned int __socklen_t;
#line 44 "/usr/include/stdio.h"
struct _IO_FILE;
#line 48 "/usr/include/stdio.h"
typedef struct _IO_FILE FILE;
#line 154 "/usr/include/libio.h"
typedef void _IO_lock_t;
#line 160 "/usr/include/libio.h"
struct _IO_marker {
   struct _IO_marker *_next ;
   struct _IO_FILE *_sbuf ;
   int _pos ;
};
#line 245 "/usr/include/libio.h"
struct _IO_FILE {
   int _flags ;
   char *_IO_read_ptr ;
   char *_IO_read_end ;
   char *_IO_read_base ;
   char *_IO_write_base ;
   char *_IO_write_ptr ;
   char *_IO_write_end ;
   char *_IO_buf_base ;
   char *_IO_buf_end ;
   char *_IO_save_base ;
   char *_IO_backup_base ;
   char *_IO_save_end ;
   struct _IO_marker *_markers ;
   struct _IO_FILE *_chain ;
   int _fileno ;
   int _flags2 ;
   __off_t _old_offset ;
   unsigned short _cur_column ;
   signed char _vtable_offset ;
   char _shortbuf[1] ;
   _IO_lock_t *_lock ;
   __off64_t _offset ;
   void *__pad1 ;
   void *__pad2 ;
   void *__pad3 ;
   void *__pad4 ;
   size_t __pad5 ;
   int _mode ;
   char _unused2[(15UL * sizeof(int ) - 4UL * sizeof(void *)) - sizeof(size_t )] ;
};
#line 51 "/usr/include/stdint.h"
typedef unsigned int uint32_t;
#line 33 "/usr/include/x86_64-linux-gnu/bits/socket.h"
typedef __socklen_t socklen_t;
#line 31 "/home/wheatley/newnew/temp/prips-0.9.9/main.c"
enum __anonenum_AddrFormat_38 {
    FORMAT_HEX = 0,
    FORMAT_DEC = 1,
    FORMAT_DOT = 2
} ;
#line 31 "/home/wheatley/newnew/temp/prips-0.9.9/main.c"
typedef enum __anonenum_AddrFormat_38 AddrFormat;
#line 170 "/usr/include/stdio.h"
extern struct _IO_FILE *stderr ;
#line 356
extern int fprintf(FILE * __restrict  __stream , char const   * __restrict  __format 
                   , ...) ;
#line 386
extern  __attribute__((__nothrow__)) int ( /* format attribute */  snprintf)(char * __restrict  __s ,
                                                                             size_t __maxlen ,
                                                                             char const   * __restrict  __format 
                                                                             , ...) ;
#line 543 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__, __noreturn__)) void ( __attribute__((__leaf__)) exit)(int __status ) ;
#line 374 "/usr/include/netinet/in.h"
extern  __attribute__((__nothrow__)) uint32_t ( __attribute__((__leaf__)) ntohl)(uint32_t __netlong )  __attribute__((__const__)) ;
#line 377
extern  __attribute__((__nothrow__)) uint32_t ( __attribute__((__leaf__)) htonl)(uint32_t __hostlong )  __attribute__((__const__)) ;
#line 58 "/usr/include/arpa/inet.h"
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) inet_pton)(int __af ,
                                                                                char const   * __restrict  __cp ,
                                                                                void * __restrict  __buf ) ;
#line 64
extern  __attribute__((__nothrow__)) char const   *( __attribute__((__leaf__)) inet_ntop)(int __af ,
                                                                                          void const   * __restrict  __cp ,
                                                                                          char * __restrict  __buf ,
                                                                                          socklen_t __len ) ;
#line 49 "/home/wheatley/newnew/temp/prips-0.9.9/prips.h"
uint32_t numberize(char const   *addr ) ;
#line 50
char const   *denumberize(uint32_t addr ) ;
#line 51
char const   *cidrize(uint32_t start , uint32_t end ) ;
#line 52
uint32_t add_offset(char const   *addr , int offset ) ;
#line 53
uint32_t set_bits_from_right(int bits ) ;
#line 54
int count_on_bits(uint32_t number ) ;
#line 55
char get_class(uint32_t address ) ;
#line 36 "/home/wheatley/newnew/temp/prips-0.9.9/prips.c"
uint32_t numberize(char const   *addr ) 
{ 
  uint32_t sin_addr ;
  int retval ;
  uint32_t tmp ;

  {
  {
#line 41
  retval = inet_pton(2, (char const   */* __restrict  */)addr, (void */* __restrict  */)(& sin_addr));
  }
#line 44
  if (retval == 0) {
#line 45
    return ((uint32_t )-1);
  } else
#line 44
  if (retval == -1) {
#line 45
    return ((uint32_t )-1);
  }
  {
#line 47
  tmp = ntohl(sin_addr);
  }
#line 47
  return (tmp);
}
}
#line 59 "/home/wheatley/newnew/temp/prips-0.9.9/prips.c"
static char buffer[16]  ;
#line 57 "/home/wheatley/newnew/temp/prips-0.9.9/prips.c"
char const   *denumberize(uint32_t addr ) 
{ 
  uint32_t addr_nl ;
  uint32_t tmp ;
  char const   *tmp___0 ;

  {
  {
#line 60
  tmp = htonl(addr);
#line 60
  addr_nl = tmp;
#line 62
  tmp___0 = inet_ntop(2, (void const   */* __restrict  */)(& addr_nl), (char */* __restrict  */)(buffer),
                      (socklen_t )sizeof(buffer));
  }
#line 62
  if (! tmp___0) {
#line 63
    return ((char const   *)((void *)0));
  }
#line 64
  return ((char const   *)(buffer));
}
}
#line 76 "/home/wheatley/newnew/temp/prips-0.9.9/prips.c"
static char buffer___0[128]  ;
#line 72 "/home/wheatley/newnew/temp/prips-0.9.9/prips.c"
char const   *cidrize(uint32_t start , uint32_t end ) 
{ 
  uint32_t base ;
  int offset ;
  uint32_t diff ;
  int i ;
  char const   *tmp ;

  {
#line 75
  offset = 0;
#line 82
  diff = start ^ end;
#line 86
  i = 1;
  {
#line 86
  while (1) {
    while_continue: /* CIL Label */ ;
#line 86
    if (! (i <= 32)) {
#line 86
      goto while_break;
    }
#line 88
    if (diff == 0U) {
#line 90
      offset = i - 1;
#line 91
      goto while_break;
    }
#line 93
    diff >>= 1;
#line 86
    i ++;
  }
  while_break: /* CIL Label */ ;
  }
  {
#line 97
  base = (start >> offset) << offset;
#line 99
  tmp = denumberize(base);
#line 99
  snprintf((char */* __restrict  */)(buffer___0), (size_t )128, (char const   */* __restrict  */)"%s/%d",
           tmp, 32 - offset);
  }
#line 102
  return ((char const   *)(buffer___0));
}
}
#line 112 "/home/wheatley/newnew/temp/prips-0.9.9/prips.c"
uint32_t add_offset(char const   *addr , int offset ) 
{ 
  uint32_t naddr ;

  {
#line 116
  if (offset > 32) {
    {
#line 118
    fprintf((FILE */* __restrict  */)stderr, (char const   */* __restrict  */)"CIDR offsets are between 0 and 32\n");
#line 119
    exit(1);
    }
  } else
#line 116
  if (offset < 0) {
    {
#line 118
    fprintf((FILE */* __restrict  */)stderr, (char const   */* __restrict  */)"CIDR offsets are between 0 and 32\n");
#line 119
    exit(1);
    }
  }
  {
#line 122
  naddr = numberize(addr);
  }
#line 123
  if (naddr << offset != 0U) {
    {
#line 125
    fprintf((FILE */* __restrict  */)stderr, (char const   */* __restrict  */)"CIDR base address didn\'t start at subnet boundary\n");
#line 127
    exit(1);
    }
  }
#line 130
  return (((uint32_t )(1 << (32 - offset)) + naddr) - 1U);
}
}
#line 133 "/home/wheatley/newnew/temp/prips-0.9.9/prips.c"
uint32_t set_bits_from_right(int bits ) 
{ 
  register int i ;
  uint32_t number ;

  {
#line 136
  number = (uint32_t )0;
#line 138
  i = 0;
  {
#line 138
  while (1) {
    while_continue: /* CIL Label */ ;
#line 138
    if (! (i < bits)) {
#line 138
      goto while_break;
    }
#line 139
    number += (uint32_t )(1 << i);
#line 138
    i ++;
  }
  while_break: /* CIL Label */ ;
  }
#line 141
  return (number);
}
}
#line 144 "/home/wheatley/newnew/temp/prips-0.9.9/prips.c"
int count_on_bits(uint32_t number ) 
{ 
  uint32_t mask ;
  int i ;
  int on_bits ;

  {
#line 146
  mask = (uint32_t )1;
#line 147
  on_bits = 0;
#line 149
  mask <<= 31;
#line 150
  i = 0;
  {
#line 150
  while (1) {
    while_continue: /* CIL Label */ ;
#line 150
    if (! (i < 32)) {
#line 150
      goto while_break;
    }
#line 152
    if (mask & number) {
#line 153
      on_bits ++;
    }
#line 154
    number <<= 1;
#line 150
    i ++;
  }
  while_break: /* CIL Label */ ;
  }
#line 157
  return (on_bits);
}
}
#line 160 "/home/wheatley/newnew/temp/prips-0.9.9/prips.c"
char get_class(uint32_t address ) 
{ 
  uint32_t addr ;
  char class ;

  {
#line 165
  addr = (address & 4278190080U) >> 24;
#line 167
  if (addr < 127U) {
#line 168
    class = (char )'a';
  } else
#line 169
  if (addr >= 127U) {
#line 169
    if (addr < 192U) {
#line 170
      class = (char )'b';
    } else {
#line 169
      goto _L;
    }
  } else
  _L: /* CIL Label */ 
#line 171
  if (addr >= 192U) {
#line 171
    if (addr < 224U) {
#line 172
      class = (char )'c';
    } else {
#line 174
      class = (char )'d';
    }
  } else {
#line 174
    class = (char )'d';
  }
#line 176
  return (class);
}
}
#line 362 "/usr/include/stdio.h"
extern int printf(char const   * __restrict  __format  , ...) ;
#line 147 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) atoi)(char const   *__nptr )  __attribute__((__pure__)) ;
#line 144 "/usr/include/string.h"
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2), __leaf__)) strcmp)(char const   *__s1 ,
                                                                                               char const   *__s2 )  __attribute__((__pure__)) ;
#line 348
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(2), __leaf__)) strtok)(char * __restrict  __s ,
                                                                                               char const   * __restrict  __delim ) ;
#line 57 "/usr/include/getopt.h"
extern char *optarg ;
#line 71
extern int optind ;
#line 76
extern int opterr ;
#line 150
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) getopt)(int ___argc ,
                                                                             char * const  *___argv ,
                                                                             char const   *__shortopts ) ;
#line 23 "/home/wheatley/newnew/temp/prips-0.9.9/except.h"
int set_exceptions(char *exp , int (*octet)[256] ) ;
#line 24
int except(uint32_t *current , int (*octet)[256] ) ;
#line 39 "/home/wheatley/newnew/temp/prips-0.9.9/main.c"
char const   *MAINTAINER  =    "Peter Pentchev <roam@ringlet.net>";
#line 40 "/home/wheatley/newnew/temp/prips-0.9.9/main.c"
char const   *VERSION  =    "\rprips 0.9.9\n\t\rThis program comes with NO WARRANTY,\n\t\rto the extent permitted by law.\n\t\rYou may redistribute copies under \n\t\rthe terms of the GNU General Public License.\n";
#line 47
static void usage(char *prog ) ;
#line 48
static AddrFormat get_format(char *format ) ;
#line 50 "/home/wheatley/newnew/temp/prips-0.9.9/main.c"
int main(int argc , char **argv ) 
{ 
  int ch ;
  char const   *argstr ;
  uint32_t start ;
  uint32_t end ;
  uint32_t current ;
  int octet[4][256] ;
  int format ;
  int delimiter ;
  int increment ;
  char *prefix ;
  char *offset ;
  int exception_flag ;
  int print_as_cidr_flag ;
  AddrFormat tmp ;
  int tmp___0 ;
  char const   *tmp___1 ;
  char const   *tmp___2 ;
  int tmp___3 ;

  {
#line 53
  argstr = "d:f:i:e:cv";
#line 54
  start = (uint32_t )0;
#line 54
  end = (uint32_t )0;
#line 56
  format = 2;
#line 57
  delimiter = 10;
#line 58
  increment = 1;
#line 62
  exception_flag = 0;
#line 63
  print_as_cidr_flag = 0;
#line 65
  opterr = 0;
  {
#line 66
  while (1) {
    while_continue: /* CIL Label */ ;
    {
#line 66
    ch = getopt(argc, (char * const  *)argv, argstr);
    }
#line 66
    if (! (ch != -1)) {
#line 66
      goto while_break;
    }
    {
#line 68
    if (ch == 99) {
#line 68
      goto case_99;
    }
#line 71
    if (ch == 100) {
#line 71
      goto case_100;
    }
#line 81
    if (ch == 102) {
#line 81
      goto case_102;
    }
#line 84
    if (ch == 105) {
#line 84
      goto case_105;
    }
#line 92
    if (ch == 101) {
#line 92
      goto case_101;
    }
#line 96
    if (ch == 118) {
#line 96
      goto case_118;
    }
#line 99
    if (ch == 63) {
#line 99
      goto case_63;
    }
#line 67
    goto switch_break;
    case_99: /* CIL Label */ 
#line 69
    print_as_cidr_flag = 1;
#line 70
    goto switch_break;
    case_100: /* CIL Label */ 
    {
#line 72
    delimiter = atoi((char const   *)optarg);
    }
#line 74
    if (delimiter < 0) {
      {
#line 76
      fprintf((FILE */* __restrict  */)stderr, (char const   */* __restrict  */)"%s: delimiter must be between 0 and 255\n",
              *(argv + 0));
#line 78
      exit(1);
      }
    } else
#line 74
    if (delimiter > 255) {
      {
#line 76
      fprintf((FILE */* __restrict  */)stderr, (char const   */* __restrict  */)"%s: delimiter must be between 0 and 255\n",
              *(argv + 0));
#line 78
      exit(1);
      }
    }
#line 80
    goto switch_break;
    case_102: /* CIL Label */ 
    {
#line 82
    tmp = get_format(optarg);
#line 82
    format = (int )tmp;
    }
#line 83
    goto switch_break;
    case_105: /* CIL Label */ 
    {
#line 85
    increment = atoi((char const   *)optarg);
    }
#line 85
    if (increment < 1) {
      {
#line 87
      fprintf((FILE */* __restrict  */)stderr, (char const   */* __restrict  */)"%s: increment must be a positive integer\n",
              *(argv + 0));
#line 89
      exit(1);
      }
    }
#line 91
    goto switch_break;
    case_101: /* CIL Label */ 
    {
#line 93
    set_exceptions(optarg, (int (*)[256])(octet));
#line 94
    exception_flag = 1;
    }
#line 95
    goto switch_break;
    case_118: /* CIL Label */ 
    {
#line 97
    printf((char const   */* __restrict  */)"%s", VERSION);
#line 98
    exit(0);
    }
    case_63: /* CIL Label */ 
    {
#line 100
    usage(*(argv + 0));
#line 101
    exit(1);
    }
    switch_break: /* CIL Label */ ;
    }
  }
  while_break: /* CIL Label */ ;
  }
  {
#line 116
  if (argc - optind == 1) {
#line 116
    goto case_1;
  }
#line 135
  if (argc - optind == 2) {
#line 135
    goto case_2;
  }
#line 144
  goto switch_default;
  case_1: /* CIL Label */ 
  {
#line 117
  prefix = strtok((char */* __restrict  */)*(argv + optind), (char const   */* __restrict  */)"/");
#line 119
  offset = strtok((char */* __restrict  */)((void *)0), (char const   */* __restrict  */)"/");
  }
#line 119
  if (offset) {
    {
#line 121
    start = numberize((char const   *)prefix);
    }
#line 122
    if (start == 4294967295U) {
      {
#line 124
      fprintf((FILE */* __restrict  */)stderr, (char const   */* __restrict  */)"%s: bad IP address\n",
              *(argv + 0));
#line 125
      exit(1);
      }
    }
    {
#line 127
    tmp___0 = atoi((char const   *)offset);
#line 127
    end = add_offset((char const   *)prefix, tmp___0);
    }
  } else {
    {
#line 131
    usage(*(argv + 0));
#line 132
    exit(1);
    }
  }
#line 134
  goto switch_break___0;
  case_2: /* CIL Label */ 
  {
#line 136
  start = numberize((char const   *)*(argv + optind));
#line 137
  end = numberize((char const   *)*(argv + (optind + 1)));
  }
#line 138
  if (start == 4294967295U) {
    {
#line 140
    fprintf((FILE */* __restrict  */)stderr, (char const   */* __restrict  */)"%s: bad IP address\n",
            *(argv + 0));
#line 141
    exit(1);
    }
  } else
#line 138
  if (end == 4294967295U) {
    {
#line 140
    fprintf((FILE */* __restrict  */)stderr, (char const   */* __restrict  */)"%s: bad IP address\n",
            *(argv + 0));
#line 141
    exit(1);
    }
  }
#line 143
  goto switch_break___0;
  switch_default: /* CIL Label */ 
  {
#line 145
  usage(*(argv + 0));
#line 146
  exit(1);
  }
  switch_break___0: /* CIL Label */ ;
  }
#line 156
  if (start > end) {
    {
#line 158
    fprintf((FILE */* __restrict  */)stderr, (char const   */* __restrict  */)"%s: start address must be smaller than end address\n",
            *(argv + 0));
#line 161
    exit(1);
    }
  }
#line 164
  if (print_as_cidr_flag) {
    {
#line 165
    tmp___1 = cidrize(start, end);
#line 165
    printf((char const   */* __restrict  */)"%s%c", tmp___1, delimiter);
    }
  } else {
#line 168
    current = start;
    {
#line 168
    while (1) {
      while_continue___0: /* CIL Label */ ;
#line 168
      if (! (current <= end)) {
#line 168
        goto while_break___0;
      }
#line 169
      if (! exception_flag) {
#line 169
        goto _L;
      } else {
        {
#line 169
        tmp___3 = except(& current, (int (*)[256])(octet));
        }
#line 169
        if (! tmp___3) {
          _L: /* CIL Label */ 
          {
#line 173
          if (format == 0) {
#line 173
            goto case_0;
          }
#line 176
          if (format == 1) {
#line 176
            goto case_1___0;
          }
#line 179
          goto switch_default___0;
          case_0: /* CIL Label */ 
          {
#line 174
          printf((char const   */* __restrict  */)"%lx%c", (long )current, delimiter);
          }
#line 175
          goto switch_break___1;
          case_1___0: /* CIL Label */ 
          {
#line 177
          printf((char const   */* __restrict  */)"%lu%c", (unsigned long )current,
                 delimiter);
          }
#line 178
          goto switch_break___1;
          switch_default___0: /* CIL Label */ 
          {
#line 180
          tmp___2 = denumberize(current);
#line 180
          printf((char const   */* __restrict  */)"%s%c", tmp___2, delimiter);
          }
#line 182
          goto switch_break___1;
          switch_break___1: /* CIL Label */ ;
          }
        }
      }
#line 168
      current += (uint32_t )increment;
    }
    while_break___0: /* CIL Label */ ;
    }
  }
#line 187
  return (0);
}
}
#line 190 "/home/wheatley/newnew/temp/prips-0.9.9/main.c"
static void usage(char *prog ) 
{ 


  {
  {
#line 192
  fprintf((FILE */* __restrict  */)stderr, (char const   */* __restrict  */)"usage: %s [options] <start end | CIDR block>\n\t-c\t\tprint range in CIDR notation\n\t-d <x>\t\tset the delimiter to the character with ASCII code \'x\'\n\t\t\twhere 0 <= x <= 255 \n\t-h\t\tdisplay this help message and exit \n\t-f <x> \t\tset the format of addresses (hex, dec, or dot)\n\t-i <x>\t\tset the increment to \'x\'\n\t-e <x.x.x,x.x>\texclude a range from the output, e.g. -e ..4. will\n\t\t\tnot print 192.168.4.[0-255]\n\t\n\t\rReport bugs to %s\n",
          prog, MAINTAINER);
  }
#line 204
  return;
}
}
#line 206 "/home/wheatley/newnew/temp/prips-0.9.9/main.c"
static AddrFormat get_format(char *format ) 
{ 
  char const   *list[3] ;
  size_t i ;
  int tmp ;

  {
#line 208
  list[0] = "hex";
#line 208
  list[1] = "dec";
#line 208
  list[2] = "dot";
#line 211
  i = (size_t )0;
  {
#line 211
  while (1) {
    while_continue: /* CIL Label */ ;
#line 211
    if (! (i < sizeof(list) / sizeof(list[0]))) {
#line 211
      goto while_break;
    }
    {
#line 212
    tmp = strcmp((char const   *)format, list[i]);
    }
#line 212
    if (tmp == 0) {
#line 213
      goto while_break;
    }
#line 211
    i ++;
  }
  while_break: /* CIL Label */ ;
  }
#line 214
  return ((AddrFormat )i);
}
}
#line 399 "/usr/include/string.h"
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__nonnull__(1), __leaf__)) strlen)(char const   *__s )  __attribute__((__pure__)) ;
#line 79 "/usr/include/ctype.h"
extern  __attribute__((__nothrow__)) unsigned short const   **( __attribute__((__leaf__)) __ctype_b_loc)(void)  __attribute__((__const__)) ;
#line 69 "/usr/include/assert.h"
extern  __attribute__((__nothrow__, __noreturn__)) void ( __attribute__((__leaf__)) __assert_fail)(char const   *__assertion ,
                                                                                                   char const   *__file ,
                                                                                                   unsigned int __line ,
                                                                                                   char const   *__function ) ;
#line 30 "/home/wheatley/newnew/temp/prips-0.9.9/except.c"
static void fill(int (*octet)[256] ) ;
#line 38 "/home/wheatley/newnew/temp/prips-0.9.9/except.c"
int set_exceptions(char *exp , int (*octet)[256] ) 
{ 
  size_t i ;
  int excludeind ;
  int bufferind ;
  int octind ;
  char buffer___1[4] ;
  unsigned short const   **tmp ;
  size_t tmp___0 ;

  {
  {
#line 41
  excludeind = 0;
#line 41
  bufferind = 0;
#line 41
  octind = 0;
#line 44
  fill(octet);
#line 45
  i = (size_t )0;
  }
  {
#line 45
  while (1) {
    while_continue: /* CIL Label */ ;
    {
#line 45
    tmp___0 = strlen((char const   *)exp);
    }
#line 45
    if (! (i < tmp___0 + 1UL)) {
#line 45
      goto while_break;
    }
    {
#line 47
    tmp = __ctype_b_loc();
    }
#line 47
    if ((int const   )*(*tmp + (int )*(exp + i)) & 2048) {
#line 49
      buffer___1[bufferind] = *(exp + i);
#line 50
      bufferind ++;
#line 51
      if (! (bufferind != 4)) {
        {
#line 51
        __assert_fail("bufferind != 4", "/home/wheatley/newnew/temp/prips-0.9.9/except.c",
                      51U, "set_exceptions");
        }
      }
    } else {
#line 55
      if (bufferind) {
        {
#line 57
        buffer___1[bufferind] = (char )'\000';
#line 58
        (*(octet + octind))[excludeind] = atoi((char const   *)(buffer___1));
#line 59
        bufferind = 0;
#line 60
        excludeind ++;
        }
      }
#line 63
      if ((int )*(exp + i) == 46) {
#line 65
        octind ++;
#line 66
        excludeind = 0;
      }
    }
#line 45
    i ++;
  }
  while_break: /* CIL Label */ ;
  }
#line 70
  return (0);
}
}
#line 73 "/home/wheatley/newnew/temp/prips-0.9.9/except.c"
static void fill(int (*octet)[256] ) 
{ 
  register int i ;
  register int j ;

  {
#line 77
  i = 0;
  {
#line 77
  while (1) {
    while_continue: /* CIL Label */ ;
#line 77
    if (! (i < 4)) {
#line 77
      goto while_break;
    }
#line 78
    j = 0;
    {
#line 78
    while (1) {
      while_continue___0: /* CIL Label */ ;
#line 78
      if (! (j < 256)) {
#line 78
        goto while_break___0;
      }
#line 79
      (*(octet + i))[j] = -1;
#line 78
      j ++;
    }
    while_break___0: /* CIL Label */ ;
    }
#line 77
    i ++;
  }
  while_break: /* CIL Label */ ;
  }
#line 80
  return;
}
}
#line 89 "/home/wheatley/newnew/temp/prips-0.9.9/except.c"
int except(uint32_t *current , int (*octet)[256] ) 
{ 
  register int i ;
  register int j ;

  {
#line 93
  i = 0;
  {
#line 93
  while (1) {
    while_continue: /* CIL Label */ ;
#line 93
    if (! (i < 4)) {
#line 93
      goto while_break;
    }
#line 95
    j = 0;
    {
#line 95
    while (1) {
      while_continue___0: /* CIL Label */ ;
#line 95
      if (! (j < 256)) {
#line 95
        goto while_break___0;
      }
      {
#line 99
      if (i == 0) {
#line 99
        goto case_0;
      }
#line 106
      if (i == 1) {
#line 106
        goto case_1;
      }
#line 113
      if (i == 2) {
#line 113
        goto case_2;
      }
#line 120
      if (i == 3) {
#line 120
        goto case_3;
      }
#line 97
      goto switch_break;
      case_0: /* CIL Label */ 
#line 100
      if ((int )((*current >> 24) & 255U) == (*(octet + i))[j]) {
#line 102
        *current += (uint32_t )(1 << 24) - 1U;
#line 103
        return (1);
      }
#line 105
      goto switch_break;
      case_1: /* CIL Label */ 
#line 107
      if ((int )((*current >> 16) & 255U) == (*(octet + i))[j]) {
#line 109
        *current += (uint32_t )(1 << 16) - 1U;
#line 110
        return (1);
      }
#line 112
      goto switch_break;
      case_2: /* CIL Label */ 
#line 114
      if ((int )((*current >> 8) & 255U) == (*(octet + i))[j]) {
#line 116
        *current += (uint32_t )(1 << 8) - 1U;
#line 117
        return (1);
      }
#line 119
      goto switch_break;
      case_3: /* CIL Label */ 
#line 121
      if ((int )(*current & 255U) == (*(octet + i))[j]) {
#line 122
        return (1);
      }
#line 123
      goto switch_break;
      switch_break: /* CIL Label */ ;
      }
#line 95
      j ++;
    }
    while_break___0: /* CIL Label */ ;
    }
#line 93
    i ++;
  }
  while_break: /* CIL Label */ ;
  }
#line 128
  return (0);
}
}
