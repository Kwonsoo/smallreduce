/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is false */

#line 212 "/usr/lib/gcc/x86_64-linux-gnu/4.8/include/stddef.h"
typedef unsigned long size_t;
#line 131 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __off_t;
#line 132 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __off64_t;
#line 44 "/usr/include/stdio.h"
struct _IO_FILE;
#line 44
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
#line 315 "/usr/include/libio.h"
typedef struct _IO_FILE _IO_FILE;
#line 49 "/home/june/collector/temp/c2050-0.3b/c2050.c"
struct tSweepBuffer {
   int bytepos ;
   int bitpos ;
   int bufpos ;
   int unprinted ;
   char *buffer ;
};
#line 434 "/usr/include/libio.h"
extern int _IO_getc(_IO_FILE *__fp ) ;
#line 435
extern int _IO_putc(int __c , _IO_FILE *__fp ) ;
#line 168 "/usr/include/stdio.h"
extern struct _IO_FILE *stdin ;
#line 169
extern struct _IO_FILE *stdout ;
#line 170
extern struct _IO_FILE *stderr ;
#line 237
extern int fclose(FILE *__stream ) ;
#line 356
extern int fprintf(FILE * __restrict  __stream , char const   * __restrict  __format 
                   , ...) ;
#line 466 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) malloc)(size_t __size )  __attribute__((__malloc__)) ;
#line 483
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) free)(void *__ptr ) ;
#line 60 "/home/june/collector/temp/c2050-0.3b/c2050.c"
void ClearBuffer(char *data , int bytes ) 
{ 
  register int i ;
  int tmp ;

  {
#line 63
  i = 0;
  {
#line 63
  while (1) {
    while_continue: /* CIL Label */ ;

#line 63
    if (! (i < bytes)) {
#line 63
      goto while_break;
    }
#line 63
    tmp = i;
#line 63
    i ++;
#line 63
    *(data + tmp) = (char)0;
  }
  while_break___0: /* CIL Label */ ;
  }
  while_break: ;
#line 64
  return;
}
}
#line 69 "/home/june/collector/temp/c2050-0.3b/c2050.c"
int SweepBuffer_Init(struct tSweepBuffer *SweepBuffer , int bytesize ) 
{ 
  void *tmp ;

  {
  {
#line 71
  SweepBuffer->bytepos = 0;
#line 72
  SweepBuffer->bitpos = 0;
#line 73
  SweepBuffer->bufpos = 0;
#line 74
  SweepBuffer->unprinted = 0;
#line 75
  tmp = malloc((size_t )bytesize);
#line 75
  SweepBuffer->buffer = (char *)tmp;
#line 76
  ClearBuffer(SweepBuffer->buffer, bytesize);
  }
#line 77
  return (0);
}
}
#line 83 "/home/june/collector/temp/c2050-0.3b/c2050.c"
void fPutLString(FILE *out , char *data ) 
{ 
  int i ;
  int tmp ;

  {
#line 85
  i = 1;
  {
#line 85
  while (1) {
    while_continue: /* CIL Label */ ;

#line 85
    if (! (i <= (int )*(data + 0))) {
#line 85
      goto while_break;
    }
    {
#line 85
    tmp = i;
#line 85
    i ++;
#line 85
    _IO_putc((int )*(data + tmp), out);
    }
  }
  while_break___0: /* CIL Label */ ;
  }
  while_break: ;
#line 86
  return;
}
}
#line 91 "/home/june/collector/temp/c2050-0.3b/c2050.c"
void LexMove(FILE *out , long pixel ) 
{ 
  char command[6] ;
  void *__cil_tmp4 ;

  {
  {
#line 93
  command[0] = (char)5;
#line 93
  command[1] = (char)27;
#line 93
  command[2] = (char)42;
#line 93
  command[3] = (char)3;
#line 93
  command[4] = (char)0;
#line 93
  command[5] = (char)0;
#line 94
  command[5] = (char )pixel;
#line 95
  command[4] = (char )(pixel >> 8);
#line 96
  fPutLString(out, command);
  }
#line 97
  return;
}
}
#line 102 "/home/june/collector/temp/c2050-0.3b/c2050.c"
void LexInit(FILE *out ) 
{ 
  char command[13] ;
  void *__cil_tmp3 ;

  {
  {
#line 104
  command[0] = (char)12;
#line 104
  command[1] = (char)27;
#line 104
  command[2] = (char)42;
#line 104
  command[3] = (char)-128;
#line 104
  command[4] = (char)27;
#line 104
  command[5] = (char)42;
#line 104
  command[6] = (char)7;
#line 104
  command[7] = (char)115;
#line 104
  command[8] = (char)48;
#line 104
  command[9] = (char)27;
#line 104
  command[10] = (char)42;
#line 104
  command[11] = (char)7;
#line 104
  command[12] = (char)99;
#line 106
  fPutLString(out, command);
#line 107
  LexMove(out, 100L);
  }
#line 108
  return;
}
}
#line 113 "/home/june/collector/temp/c2050-0.3b/c2050.c"
void LexEOP(FILE *out ) 
{ 
  char command[5] ;
  void *__cil_tmp3 ;

  {
  {
#line 115
  command[0] = (char)4;
#line 115
  command[1] = (char)27;
#line 115
  command[2] = (char)42;
#line 115
  command[3] = (char)7;
#line 115
  command[4] = (char)101;
#line 116
  fPutLString(out, command);
  }
#line 117
  return;
}
}
#line 124 "/home/june/collector/temp/c2050-0.3b/c2050.c"
int ReduceBytes(char *buffer , int bytespercolumn , int *leftmargin , int *breite ,
                int *bytesize ) 
{ 
  register int redleft ;
  register int redright ;
  int bstart ;

  {
#line 126
  redleft = 0;
#line 127
  redright = 0;
#line 128
  bstart = 0;
  {
#line 129
  while (1) {
    while_continue: /* CIL Label */ ;

#line 129
    if ((int )*(buffer + redleft) == 0) {
#line 129
      if (! (redleft < *bytesize)) {
#line 129
        goto while_break;
      }
    } else {
#line 129
      goto while_break;
    }
#line 129
    redleft ++;
  }
  while_break___1: /* CIL Label */ ;
  }
  while_break: ;
  {
#line 130
  while (1) {
    while_continue___0: /* CIL Label */ ;

#line 130
    if ((int )*(buffer + ((*bytesize - 1) - redright)) == 0) {
#line 130
      if (! (redright < *bytesize)) {
#line 130
        goto while_break___0;
      }
    } else {
#line 130
      goto while_break___0;
    }
#line 131
    redright ++;
  }
  while_break___2: /* CIL Label */ ;
  }
  while_break___0: 
#line 132
  *breite -= redleft / bytespercolumn + redright / bytespercolumn;
#line 133
  *leftmargin += redleft / bytespercolumn;
#line 134
  bstart = redleft - redleft % bytespercolumn;
#line 135
  if (bstart < 0) {
#line 135
    bstart = 0;
  }
#line 137
  return (bstart);
}
}
#line 143 "/home/june/collector/temp/c2050-0.3b/c2050.c"
void PrintSweep(char *buffer , char *header , int bytesize , int width , int leftmargin ,
                FILE *out ) 
{ 
  int bstart ;
  register int i ;

  {
  {
#line 148
  bstart = ReduceBytes(buffer, 6, & leftmargin, & width, & bytesize);
#line 152
  bytesize = 26 + 6 * width;
#line 153
  *(header + 4) = (char )bytesize;
#line 154
  *(header + 3) = (char )(bytesize >> 8);
#line 157
  *(header + 12) = (char )width;
#line 158
  *(header + 11) = (char )(width >> 8);
#line 161
  *(header + 14) = (char )leftmargin;
#line 162
  *(header + 13) = (char )(leftmargin >> 8);
  }
#line 164
  if (width > 0) {
#line 165
    i = 0;
    {
#line 165
    while (1) {
      while_continue: /* CIL Label */ ;

#line 165
      if (! (i < 26)) {
#line 165
        goto while_break;
      }
      {
#line 165
      _IO_putc((int )*(header + i), out);
#line 165
      i ++;
      }
    }
    while_break___1: /* CIL Label */ ;
    }
    while_break: 
#line 166
    i = 0;
    {
#line 166
    while (1) {
      while_continue___0: /* CIL Label */ ;

#line 166
      if (! (i < bytesize)) {
#line 166
        goto while_break___0;
      }
      {
#line 166
      _IO_putc((int )*(buffer + (i + bstart)), out);
#line 166
      i ++;
      }
    }
    while_break___2: /* CIL Label */ ;
    }
    while_break___0: ;
  }
#line 168
  return;
}
}
#line 173 "/home/june/collector/temp/c2050-0.3b/c2050.c"
int LineSum(signed char *line , int length ) 
{ 
  register int i ;
  int tmp ;

  {
#line 175
  i = 0;
  {
#line 176
  while (1) {
    while_continue: /* CIL Label */ ;

#line 176
    if (! (i < length)) {
#line 176
      goto while_break;
    }
#line 177
    tmp = i;
#line 177
    i ++;
    {

#line 177
    if ((int )*(line + tmp) != 0) {
#line 177
      return (1);
    }
    }
  }
  while_break___0: /* CIL Label */ ;
  }
  while_break: ;
#line 178
  return (0);
}
}
#line 184 "/home/june/collector/temp/c2050-0.3b/c2050.c"
void LexPrint(FILE *in , FILE *out ) 
{ 
  signed char line[1240] ;
  int done_page ;
  int cur_height ;
  int page_height ;
  int numpages ;
  char lex_blkhd[26] ;
  char lex_colhd[26] ;
  long blkbytesize ;
  long colbytesize ;
  register int i ;
  struct tSweepBuffer blkbuffer ;
  struct tSweepBuffer colbuffer[6] ;
  int CurrentColBuffer ;
  int blkwidth ;
  int colwidth ;
  int empty_lines ;
  int skipcolors ;
  signed char nibble ;
  int yellowcounter ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;
  int tmp___7 ;
  void *__cil_tmp31 ;
  void *__cil_tmp32 ;
  void *__cil_tmp33 ;
  void *__cil_tmp34 ;
  int __cil_tmp35 ;
  char *__cil_tmp36 ;

  {
#line 186
  cur_height = 0;
#line 186
  page_height = 0;
#line 186
  numpages = 0;
#line 187
  lex_blkhd[0] = (char)27;
#line 187
  lex_blkhd[1] = (char)42;
#line 187
  lex_blkhd[2] = (char)4;
#line 187
  lex_blkhd[3] = (char)-1;
#line 187
  lex_blkhd[4] = (char)-1;
#line 187
  lex_blkhd[5] = (char)0;
#line 187
  lex_blkhd[6] = (char)1;
#line 187
  lex_blkhd[7] = (char)0;
#line 187
  lex_blkhd[8] = (char)1;
#line 187
  lex_blkhd[9] = (char)6;
#line 187
  lex_blkhd[10] = (char)49;
#line 187
  lex_blkhd[11] = (char)-1;
#line 187
  lex_blkhd[12] = (char)-1;
#line 187
  lex_blkhd[13] = (char)-1;
#line 187
  lex_blkhd[14] = (char)-1;
#line 187
  lex_blkhd[15] = (char)0;
#line 187
  lex_blkhd[16] = (char)0;
#line 187
  lex_blkhd[17] = (char)0;
#line 187
  lex_blkhd[18] = (char)0;
#line 187
  lex_blkhd[19] = (char)0;
#line 187
  lex_blkhd[20] = (char)0;
#line 187
  lex_blkhd[21] = (char)0;
#line 187
  lex_blkhd[22] = (char)50;
#line 187
  lex_blkhd[23] = (char)51;
#line 187
  lex_blkhd[24] = (char)52;
#line 187
  lex_blkhd[25] = (char)53;
#line 191
  lex_colhd[0] = (char)27;
#line 191
  lex_colhd[1] = (char)42;
#line 191
  lex_colhd[2] = (char)4;
#line 191
  lex_colhd[3] = (char)-1;
#line 191
  lex_colhd[4] = (char)-1;
#line 191
  lex_colhd[5] = (char)0;
#line 191
  lex_colhd[6] = (char)1;
#line 191
  lex_colhd[7] = (char)0;
#line 191
  lex_colhd[8] = (char)0;
#line 191
  lex_colhd[9] = (char)6;
#line 191
  lex_colhd[10] = (char)49;
#line 191
  lex_colhd[11] = (char)-1;
#line 191
  lex_colhd[12] = (char)-1;
#line 191
  lex_colhd[13] = (char)-1;
#line 191
  lex_colhd[14] = (char)-1;
#line 191
  lex_colhd[15] = (char)0;
#line 191
  lex_colhd[16] = (char)0;
#line 191
  lex_colhd[17] = (char)0;
#line 191
  lex_colhd[18] = (char)0;
#line 191
  lex_colhd[19] = (char)0;
#line 191
  lex_colhd[20] = (char)0;
#line 191
  lex_colhd[21] = (char)0;
#line 191
  lex_colhd[22] = (char)50;
#line 191
  lex_colhd[23] = (char)51;
#line 191
  lex_colhd[24] = (char)52;
#line 191
  lex_colhd[25] = (char)53;
#line 196
  i = 0;
#line 198
  CurrentColBuffer = 0;
#line 202
  yellowcounter = 0;
#line 206
  blkwidth = 2420;
#line 208
  colwidth = blkwidth + 16;
#line 211
  blkbytesize = (long )(6 * blkwidth);
#line 212
  colbytesize = (long )(6 * colwidth);
  {
#line 215
  while (1) {
    while_continue: /* CIL Label */ ;
    {
#line 215
    tmp___7 = _IO_getc(in);
#line 215
    line[0] = (signed char )tmp___7;
    }
#line 215
    if (! ((int )line[0] != -1)) {
#line 215
      goto while_break;
    }
    {
#line 219
    SweepBuffer_Init(& blkbuffer, (int )blkbytesize);
#line 220
    i = 0;
    }
    {
#line 220
    while (1) {
      while_continue___0: /* CIL Label */ ;

#line 220
      if (! (i < 6)) {
#line 220
        goto while_break___0;
      }
      {
#line 221
      airac_observe(colbuffer, i);
#line 221
      SweepBuffer_Init(& colbuffer[i], (int )colbytesize);
#line 222
      colbuffer[i].bufpos = i;
#line 220
      i ++;
      }
    }
    while_break___9: /* CIL Label */ ;
    }
    while_break___0: 
    {
#line 226
    LexInit(out);
#line 229
    done_page = 0;
#line 230
    page_height = 0;
#line 231
    cur_height = 0;
#line 232
    empty_lines = 0;
#line 233
    skipcolors = 0;
#line 234
    yellowcounter = 4;
#line 235
    CurrentColBuffer = 0;
    }
    {
#line 238
    while (1) {
      while_continue___1: /* CIL Label */ ;

#line 238
      if (! (! done_page)) {
#line 238
        goto while_break___1;
      }
#line 242
      if (page_height == 0) {
#line 243
        i = 1;
        {
#line 243
        while (1) {
          while_continue___2: /* CIL Label */ ;

#line 243
          if (! (i < 1240)) {
#line 243
            goto while_break___2;
          }
          {
#line 243
          tmp = i;
#line 243
          i ++;
#line 243
          tmp___0 = _IO_getc(in);
#line 243
          line[tmp] = (signed char )tmp___0;
          }
        }
        while_break___11: /* CIL Label */ ;
        }
        while_break___2: ;
      } else {
#line 245
        i = 0;
        {
#line 245
        while (1) {
          while_continue___3: /* CIL Label */ ;

#line 245
          if (! (i < 1240)) {
#line 245
            goto while_break___3;
          }
          {
#line 245
          tmp___1 = i;
#line 245
          i ++;
#line 245
          tmp___2 = _IO_getc(in);
#line 245
          line[tmp___1] = (signed char )tmp___2;
          }
        }
        while_break___12: /* CIL Label */ ;
        }
        while_break___3: ;
      }
#line 249
      if (cur_height == 0) {
        {
#line 249
        tmp___3 = LineSum(line, 1240);
        }
#line 249
        if (tmp___3) {
#line 249
          goto _L___4;
        } else
#line 249
        if (page_height < 3408) {
#line 249
          if (page_height < 3507) {
#line 249
            if (! (((blkbuffer.unprinted | colbuffer[0].unprinted) | colbuffer[1].unprinted) | colbuffer[3].unprinted)) {
#line 256
              empty_lines ++;
            } else {
#line 249
              goto _L___4;
            }
          } else {
#line 249
            goto _L___4;
          }
        } else {
#line 249
          goto _L___4;
        }
      } else {
        _L___4: 
#line 260
        if (empty_lines) {
          {
#line 261
          LexMove(out, (long )(empty_lines * 2));
#line 262
          empty_lines = 0;
#line 263
          yellowcounter = 4;
          }
        }
#line 267
        blkbuffer.bitpos = (yellowcounter % 48) % 8;
#line 269
        blkbuffer.bytepos = 5 - (yellowcounter % 48) / 8;
#line 272
        colbuffer[0].bitpos = cur_height % 8;
#line 273
        colbuffer[0].bytepos = 1 - (cur_height / 8) % 2;
#line 274
        colbuffer[0].bufpos = cur_height / 16;
#line 277
        colbuffer[1].bitpos = ((cur_height + 4) + 16) % 8;
#line 279
        colbuffer[1].bytepos = 99 - (((cur_height + 4) + 16) / 8) % 2;
#line 281
        colbuffer[1].bufpos = (((cur_height + 4) + 16) / 16) % 3;
#line 288
        colbuffer[2].bitpos = (cur_height + 40) % 8;
#line 290
        colbuffer[2].bytepos = 5 - ((cur_height + 40) / 8) % 2;
#line 292
        colbuffer[2].bufpos = ((cur_height + 40) / 16) % 3;
#line 294
        if (colbuffer[2].bufpos == colbuffer[0].bufpos) {
#line 295
          colbuffer[2].bufpos += 3;
        }
#line 299
        i = 0;
        {
#line 299
        while (1) {
          while_continue___4: /* CIL Label */ ;

#line 299
          if (! (i <= blkwidth)) {
#line 299
            goto while_break___4;
          }
#line 301
          nibble = (signed char )(((int )line[i / 2] << 4 * (i % 2)) & 240);
#line 302
          if ((int )nibble & 16) {
#line 303
            *(blkbuffer.buffer + (i * 6 + blkbuffer.bytepos)) = (char )((int )*(blkbuffer.buffer + (i * 6 + blkbuffer.bytepos)) | (1 << blkbuffer.bitpos));
#line 305
            blkbuffer.unprinted = 1;
          }
#line 307
          if ((int )nibble & 128) {
#line 308
            *(colbuffer[colbuffer[0].bufpos].buffer + (i * 6 + colbuffer[0].bytepos)) = (char )((int )*(colbuffer[colbuffer[0].bufpos].buffer + (i * 6 + colbuffer[0].bytepos)) | (1 << colbuffer[0].bitpos));
#line 311
            colbuffer[colbuffer[0].bufpos].unprinted = 1;
          }
#line 313
          if ((int )nibble & 64) {
#line 314
            *(colbuffer[colbuffer[1].bufpos].buffer + (i * 6 + colbuffer[1].bytepos)) = (char )((int )*(colbuffer[colbuffer[1].bufpos].buffer + (i * 6 + colbuffer[1].bytepos)) | (1 << colbuffer[1].bitpos));
#line 317
            colbuffer[colbuffer[1].bufpos].unprinted = 1;
          }
#line 319
          if ((int )nibble & 32) {
#line 320
            *(colbuffer[colbuffer[2].bufpos].buffer + (i * 6 + colbuffer[2].bytepos)) = (char )((int )*(colbuffer[colbuffer[2].bufpos].buffer + (i * 6 + colbuffer[2].bytepos)) | (1 << colbuffer[2].bitpos));
#line 323
            colbuffer[colbuffer[2].bufpos].unprinted = 1;
          }
#line 299
          i ++;
        }
        while_break___13: /* CIL Label */ ;
        }
        while_break___4: 
#line 326
        cur_height ++;
#line 327
        yellowcounter ++;
#line 329
        if (! (yellowcounter % 48)) {
#line 329
          goto _L;
        } else
#line 329
        if (page_height >= 3408) {
          _L: 
#line 331
          if (skipcolors) {
            {
#line 332
            LexMove(out, (long )(32 * skipcolors));
#line 333
            skipcolors = 0;
            }
          }
          {
#line 335
          PrintSweep(blkbuffer.buffer, lex_blkhd, (int )blkbytesize, blkwidth, 10,
                     out);
#line 336
          ClearBuffer(blkbuffer.buffer, (int )blkbytesize);
#line 337
          blkbuffer.unprinted = 0;
          }
        }
#line 340
        if (! (cur_height % 16)) {
#line 340
          goto _L___0;
        } else
#line 340
        if (page_height >= 3408) {
          _L___0: 
#line 342
          if (colbuffer[CurrentColBuffer].unprinted) {
#line 343
            if (skipcolors) {
              {
#line 344
              LexMove(out, (long )(32 * skipcolors));
#line 345
              skipcolors = 0;
              }
            }
            {
#line 347
            PrintSweep(colbuffer[CurrentColBuffer].buffer, lex_colhd, (int )colbytesize,
                       colwidth, 14, out);
#line 349
            ClearBuffer(colbuffer[CurrentColBuffer].buffer, (int )colbytesize);
#line 350
            LexMove(out, 32L);
            }
          } else {
#line 353
            skipcolors ++;
          }
#line 355
          i = 0;
          {
#line 355
          while (1) {
            while_continue___5: /* CIL Label */ ;

#line 355
            if (! ((long )i < colbytesize)) {
#line 355
              goto while_break___5;
            }
#line 356
            *(colbuffer[CurrentColBuffer].buffer + i) = (char )((int )*(colbuffer[CurrentColBuffer].buffer + i) | (int )*(colbuffer[CurrentColBuffer + 3].buffer + i));
#line 355
            i ++;
          }
          while_break___14: /* CIL Label */ ;
          }
          while_break___5: 
          {
#line 358
          ClearBuffer(colbuffer[CurrentColBuffer + 3].buffer, (int )colbytesize);
#line 359
          colbuffer[CurrentColBuffer].unprinted = colbuffer[CurrentColBuffer + 3].unprinted;
#line 361
          colbuffer[CurrentColBuffer + 3].unprinted = 0;
#line 363
          CurrentColBuffer ++;
#line 363
          CurrentColBuffer %= 3;
          }
        }
#line 365
        if (cur_height == 48) {
#line 365
          cur_height = 0;
        }
#line 366
        if (! (yellowcounter % 48)) {
#line 366
          if (! (yellowcounter % 16)) {
#line 366
            yellowcounter = 0;
          }
        }
      }
#line 370
      tmp___4 = page_height;
#line 370
      page_height ++;
#line 370
      if (tmp___4 >= 3408) {
#line 371
        done_page = 1;
      } else
#line 370
      if (page_height >= 3507) {
#line 371
        done_page = 1;
      }
    }
    while_break___10: /* CIL Label */ ;
    }
    while_break___1: 
    {
#line 375
    LexEOP(out);
#line 379
    i = 0;
    }
    {
#line 379
    while (1) {
      while_continue___6: /* CIL Label */ ;

#line 379
      if (i < 122760) {
#line 379
        if (! ((int )nibble != -1)) {
#line 379
          goto while_break___6;
        }
      } else {
#line 379
        goto while_break___6;
      }
      {
#line 382
      tmp___5 = _IO_getc(in);
#line 382
      nibble = (signed char )tmp___5;
#line 379
      i ++;
      }
    }
    while_break___15: /* CIL Label */ ;
    }
    while_break___6: 
    {
#line 385
    numpages ++;
#line 386
    free((void *)blkbuffer.buffer);
#line 387
    i = 0;
    }
    {
#line 387
    while (1) {
      while_continue___7: /* CIL Label */ ;

#line 387
      if (! (i < 6)) {
#line 387
        goto while_break___7;
      }
      {
#line 387
      tmp___6 = i;
#line 387
      i ++;
#line 387
      free((void *)colbuffer[tmp___6].buffer);
      }
    }
    while_break___16: /* CIL Label */ ;
    }
    while_break___7: ;
  }
  while_break___8: /* CIL Label */ ;
  }
  while_break: ;
#line 389
  if (numpages == 0) {
    {
#line 389
    fprintf((FILE */* __restrict  */)stderr, (char const   */* __restrict  */)"c2050: No pages printed!");
    }
  }
#line 390
  return;
}
}
#line 395 "/home/june/collector/temp/c2050-0.3b/c2050.c"
int main(int argc , char **argv ) 
{ 
  FILE *InputFile ;
  FILE *OutPutFile ;

  {
  {
#line 399
  InputFile = stdin;
#line 400
  OutPutFile = stdout;
#line 402
  LexPrint(InputFile, OutPutFile);
#line 404
  fclose(OutPutFile);
#line 405
  fclose(InputFile);
  }
#line 406
  return (0);
}
}
