/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is false */

#line 18 "/home/wheatley/newnew/temp/postal-0.73/md5.h"
typedef unsigned char *POINTER;
#line 27 "/home/wheatley/newnew/temp/postal-0.73/md5.h"
typedef unsigned long UINT4;
#line 66 "/home/wheatley/newnew/temp/postal-0.73/md5.h"
struct __anonstruct_MD5_CTX_1 {
   UINT4 state[4] ;
   UINT4 count[2] ;
   unsigned char buffer[64] ;
};
#line 66 "/home/wheatley/newnew/temp/postal-0.73/md5.h"
typedef struct __anonstruct_MD5_CTX_1 MD5_CTX;
#line 72
void MD5Init(MD5_CTX *context ) ;
#line 73
void MD5Update(MD5_CTX *context , unsigned char *input , unsigned int inputLen ) ;
#line 75
void MD5Final(unsigned char *digest , MD5_CTX *context ) ;
#line 47 "/home/wheatley/newnew/temp/postal-0.73/md5.c"
static void MD5Transform(UINT4 *state , unsigned char *block ) ;
#line 48
static void Encode(unsigned char *output , UINT4 *input , unsigned int len ) ;
#line 50
static void Decode(UINT4 *output , unsigned char *input , unsigned int len ) ;
#line 52
static void MD5_memcpy(POINTER output , POINTER input , unsigned int len ) ;
#line 53
static void MD5_memset(POINTER output , int value , unsigned int len ) ;
#line 55 "/home/wheatley/newnew/temp/postal-0.73/md5.c"
static unsigned char PADDING[64]  = 
#line 55
  {      (unsigned char)128,      (unsigned char)0,      (unsigned char)0,      (unsigned char)0, 
        (unsigned char)0,      (unsigned char)0,      (unsigned char)0,      (unsigned char)0, 
        (unsigned char)0,      (unsigned char)0,      (unsigned char)0,      (unsigned char)0, 
        (unsigned char)0,      (unsigned char)0,      (unsigned char)0,      (unsigned char)0, 
        (unsigned char)0,      (unsigned char)0,      (unsigned char)0,      (unsigned char)0, 
        (unsigned char)0,      (unsigned char)0,      (unsigned char)0,      (unsigned char)0, 
        (unsigned char)0,      (unsigned char)0,      (unsigned char)0,      (unsigned char)0, 
        (unsigned char)0,      (unsigned char)0,      (unsigned char)0,      (unsigned char)0, 
        (unsigned char)0,      (unsigned char)0,      (unsigned char)0,      (unsigned char)0, 
        (unsigned char)0,      (unsigned char)0,      (unsigned char)0,      (unsigned char)0, 
        (unsigned char)0,      (unsigned char)0,      (unsigned char)0,      (unsigned char)0, 
        (unsigned char)0,      (unsigned char)0,      (unsigned char)0,      (unsigned char)0, 
        (unsigned char)0,      (unsigned char)0,      (unsigned char)0,      (unsigned char)0, 
        (unsigned char)0,      (unsigned char)0,      (unsigned char)0,      (unsigned char)0, 
        (unsigned char)0,      (unsigned char)0,      (unsigned char)0,      (unsigned char)0, 
        (unsigned char)0,      (unsigned char)0,      (unsigned char)0,      (unsigned char)0};
#line 96 "/home/wheatley/newnew/temp/postal-0.73/md5.c"
void md5_calc(unsigned char *output , unsigned char *input , unsigned int inlen ) 
{ 
  MD5_CTX context ;

  {
  {
#line 103
  MD5Init(& context);
#line 104
  MD5Update(& context, input, inlen);
#line 105
  MD5Final((unsigned char *)output, & context);
  }
#line 106
  return;
}
}
#line 110 "/home/wheatley/newnew/temp/postal-0.73/md5.c"
void MD5Init(MD5_CTX *context ) 
{ 
  UINT4 tmp ;

  {
#line 113
  tmp = (UINT4 )0;
#line 113
  context->count[1] = tmp;
#line 113
  context->count[0] = tmp;
#line 116
  context->state[0] = (UINT4 )1732584193;
#line 117
  context->state[1] = (UINT4 )4023233417U;
#line 118
  context->state[2] = (UINT4 )2562383102U;
#line 119
  context->state[3] = (UINT4 )271733878;
#line 120
  return;
}
}
#line 126 "/home/wheatley/newnew/temp/postal-0.73/md5.c"
void MD5Update(MD5_CTX *context , unsigned char *input , unsigned int inputLen ) 
{ 
  unsigned int i ;
  unsigned int index ;
  unsigned int partLen ;
  UINT4 tmp ;

  {
#line 134
  index = (unsigned int )((context->count[0] >> 3) & 63UL);
#line 137
  tmp = context->count[0] + ((UINT4 )inputLen << 3);
#line 137
  context->count[0] = tmp;
#line 137
  if (tmp < (UINT4 )inputLen << 3) {
#line 139
    (context->count[1]) ++;
  }
#line 140
  context->count[1] += (UINT4 )inputLen >> 29;
#line 142
  partLen = 64U - index;
#line 146
  if (inputLen >= partLen) {
    {
#line 147
    MD5_memcpy(& context->buffer[index], input, partLen);
#line 149
    MD5Transform((UINT4 *)(context->state), (unsigned char *)(context->buffer));
#line 151
    i = partLen;
    }
    {
#line 151
    while (1) {
      while_continue: /* CIL Label */ ;
#line 151
      if (! (i + 63U < inputLen)) {
#line 151
        goto while_break;
      }
      {
#line 152
      MD5Transform((UINT4 *)(context->state), (unsigned char *)(input + i));
#line 151
      i += 64U;
      }
    }
    while_break: /* CIL Label */ ;
    }
#line 154
    index = 0U;
  } else {
#line 157
    i = 0U;
  }
  {
#line 160
  MD5_memcpy(& context->buffer[index], input + i, inputLen - i);
  }
#line 163
  return;
}
}
#line 168 "/home/wheatley/newnew/temp/postal-0.73/md5.c"
void MD5Final(unsigned char *digest , MD5_CTX *context ) 
{ 
  unsigned char bits[8] ;
  unsigned int index ;
  unsigned int padLen ;

  {
  {
#line 176
  Encode(bits, context->count, 8U);
#line 180
  index = (unsigned int )((context->count[0] >> 3) & 63UL);
  }
#line 181
  if (index < 56U) {
#line 181
    padLen = 56U - index;
  } else {
#line 181
    padLen = 120U - index;
  }
  {
#line 182
  MD5Update(context, PADDING, padLen);
#line 185
  MD5Update(context, bits, 8U);
#line 188
  Encode((unsigned char *)digest, context->state, 16U);
#line 192
  MD5_memset((POINTER )context, 0, (unsigned int )sizeof(*context));
  }
#line 193
  return;
}
}
#line 197 "/home/wheatley/newnew/temp/postal-0.73/md5.c"
static void MD5Transform(UINT4 *state , unsigned char *block ) 
{ 
  UINT4 a ;
  UINT4 b ;
  UINT4 c ;
  UINT4 d ;
  UINT4 x[16] ;

  {
  {
#line 201
  a = *(state + 0);
#line 201
  b = *(state + 1);
#line 201
  c = *(state + 2);
#line 201
  d = *(state + 3);
#line 203
  Decode(x, (unsigned char *)block, 64U);
#line 206
  a += (((b & c) | (~ b & d)) + x[0]) + 3614090360UL;
#line 206
  a = (a << 7) | (a >> 25);
#line 206
  a += b;
#line 207
  d += (((a & b) | (~ a & c)) + x[1]) + 3905402710UL;
#line 207
  d = (d << 12) | (d >> 20);
#line 207
  d += a;
#line 208
  c += (((d & a) | (~ d & b)) + x[2]) + 606105819UL;
#line 208
  c = (c << 17) | (c >> 15);
#line 208
  c += d;
#line 209
  b += (((c & d) | (~ c & a)) + x[3]) + 3250441966UL;
#line 209
  b = (b << 22) | (b >> 10);
#line 209
  b += c;
#line 210
  a += (((b & c) | (~ b & d)) + x[4]) + 4118548399UL;
#line 210
  a = (a << 7) | (a >> 25);
#line 210
  a += b;
#line 211
  d += (((a & b) | (~ a & c)) + x[5]) + 1200080426UL;
#line 211
  d = (d << 12) | (d >> 20);
#line 211
  d += a;
#line 212
  c += (((d & a) | (~ d & b)) + x[6]) + 2821735955UL;
#line 212
  c = (c << 17) | (c >> 15);
#line 212
  c += d;
#line 213
  b += (((c & d) | (~ c & a)) + x[7]) + 4249261313UL;
#line 213
  b = (b << 22) | (b >> 10);
#line 213
  b += c;
#line 214
  a += (((b & c) | (~ b & d)) + x[8]) + 1770035416UL;
#line 214
  a = (a << 7) | (a >> 25);
#line 214
  a += b;
#line 215
  d += (((a & b) | (~ a & c)) + x[9]) + 2336552879UL;
#line 215
  d = (d << 12) | (d >> 20);
#line 215
  d += a;
#line 216
  c += (((d & a) | (~ d & b)) + x[10]) + 4294925233UL;
#line 216
  c = (c << 17) | (c >> 15);
#line 216
  c += d;
#line 217
  b += (((c & d) | (~ c & a)) + x[11]) + 2304563134UL;
#line 217
  b = (b << 22) | (b >> 10);
#line 217
  b += c;
#line 218
  a += (((b & c) | (~ b & d)) + x[12]) + 1804603682UL;
#line 218
  a = (a << 7) | (a >> 25);
#line 218
  a += b;
#line 219
  d += (((a & b) | (~ a & c)) + x[13]) + 4254626195UL;
#line 219
  d = (d << 12) | (d >> 20);
#line 219
  d += a;
#line 220
  c += (((d & a) | (~ d & b)) + x[14]) + 2792965006UL;
#line 220
  c = (c << 17) | (c >> 15);
#line 220
  c += d;
#line 221
  b += (((c & d) | (~ c & a)) + x[15]) + 1236535329UL;
#line 221
  b = (b << 22) | (b >> 10);
#line 221
  b += c;
#line 224
  a += (((b & d) | (c & ~ d)) + x[1]) + 4129170786UL;
#line 224
  a = (a << 5) | (a >> 27);
#line 224
  a += b;
#line 225
  d += (((a & c) | (b & ~ c)) + x[6]) + 3225465664UL;
#line 225
  d = (d << 9) | (d >> 23);
#line 225
  d += a;
#line 226
  c += (((d & b) | (a & ~ b)) + x[11]) + 643717713UL;
#line 226
  c = (c << 14) | (c >> 18);
#line 226
  c += d;
#line 227
  b += (((c & a) | (d & ~ a)) + x[0]) + 3921069994UL;
#line 227
  b = (b << 20) | (b >> 12);
#line 227
  b += c;
#line 228
  a += (((b & d) | (c & ~ d)) + x[5]) + 3593408605UL;
#line 228
  a = (a << 5) | (a >> 27);
#line 228
  a += b;
#line 229
  d += (((a & c) | (b & ~ c)) + x[10]) + 38016083UL;
#line 229
  d = (d << 9) | (d >> 23);
#line 229
  d += a;
#line 230
  c += (((d & b) | (a & ~ b)) + x[15]) + 3634488961UL;
#line 230
  c = (c << 14) | (c >> 18);
#line 230
  c += d;
#line 231
  b += (((c & a) | (d & ~ a)) + x[4]) + 3889429448UL;
#line 231
  b = (b << 20) | (b >> 12);
#line 231
  b += c;
#line 232
  a += (((b & d) | (c & ~ d)) + x[9]) + 568446438UL;
#line 232
  a = (a << 5) | (a >> 27);
#line 232
  a += b;
#line 233
  d += (((a & c) | (b & ~ c)) + x[14]) + 3275163606UL;
#line 233
  d = (d << 9) | (d >> 23);
#line 233
  d += a;
#line 234
  c += (((d & b) | (a & ~ b)) + x[3]) + 4107603335UL;
#line 234
  c = (c << 14) | (c >> 18);
#line 234
  c += d;
#line 235
  b += (((c & a) | (d & ~ a)) + x[8]) + 1163531501UL;
#line 235
  b = (b << 20) | (b >> 12);
#line 235
  b += c;
#line 236
  a += (((b & d) | (c & ~ d)) + x[13]) + 2850285829UL;
#line 236
  a = (a << 5) | (a >> 27);
#line 236
  a += b;
#line 237
  d += (((a & c) | (b & ~ c)) + x[2]) + 4243563512UL;
#line 237
  d = (d << 9) | (d >> 23);
#line 237
  d += a;
#line 238
  c += (((d & b) | (a & ~ b)) + x[7]) + 1735328473UL;
#line 238
  c = (c << 14) | (c >> 18);
#line 238
  c += d;
#line 239
  b += (((c & a) | (d & ~ a)) + x[12]) + 2368359562UL;
#line 239
  b = (b << 20) | (b >> 12);
#line 239
  b += c;
#line 242
  a += (((b ^ c) ^ d) + x[5]) + 4294588738UL;
#line 242
  a = (a << 4) | (a >> 28);
#line 242
  a += b;
#line 243
  d += (((a ^ b) ^ c) + x[8]) + 2272392833UL;
#line 243
  d = (d << 11) | (d >> 21);
#line 243
  d += a;
#line 244
  c += (((d ^ a) ^ b) + x[11]) + 1839030562UL;
#line 244
  c = (c << 16) | (c >> 16);
#line 244
  c += d;
#line 245
  b += (((c ^ d) ^ a) + x[14]) + 4259657740UL;
#line 245
  b = (b << 23) | (b >> 9);
#line 245
  b += c;
#line 246
  a += (((b ^ c) ^ d) + x[1]) + 2763975236UL;
#line 246
  a = (a << 4) | (a >> 28);
#line 246
  a += b;
#line 247
  d += (((a ^ b) ^ c) + x[4]) + 1272893353UL;
#line 247
  d = (d << 11) | (d >> 21);
#line 247
  d += a;
#line 248
  c += (((d ^ a) ^ b) + x[7]) + 4139469664UL;
#line 248
  c = (c << 16) | (c >> 16);
#line 248
  c += d;
#line 249
  b += (((c ^ d) ^ a) + x[10]) + 3200236656UL;
#line 249
  b = (b << 23) | (b >> 9);
#line 249
  b += c;
#line 250
  a += (((b ^ c) ^ d) + x[13]) + 681279174UL;
#line 250
  a = (a << 4) | (a >> 28);
#line 250
  a += b;
#line 251
  d += (((a ^ b) ^ c) + x[0]) + 3936430074UL;
#line 251
  d = (d << 11) | (d >> 21);
#line 251
  d += a;
#line 252
  c += (((d ^ a) ^ b) + x[3]) + 3572445317UL;
#line 252
  c = (c << 16) | (c >> 16);
#line 252
  c += d;
#line 253
  b += (((c ^ d) ^ a) + x[6]) + 76029189UL;
#line 253
  b = (b << 23) | (b >> 9);
#line 253
  b += c;
#line 254
  a += (((b ^ c) ^ d) + x[9]) + 3654602809UL;
#line 254
  a = (a << 4) | (a >> 28);
#line 254
  a += b;
#line 255
  d += (((a ^ b) ^ c) + x[12]) + 3873151461UL;
#line 255
  d = (d << 11) | (d >> 21);
#line 255
  d += a;
#line 256
  c += (((d ^ a) ^ b) + x[15]) + 530742520UL;
#line 256
  c = (c << 16) | (c >> 16);
#line 256
  c += d;
#line 257
  b += (((c ^ d) ^ a) + x[2]) + 3299628645UL;
#line 257
  b = (b << 23) | (b >> 9);
#line 257
  b += c;
#line 260
  a += ((c ^ (b | ~ d)) + x[0]) + 4096336452UL;
#line 260
  a = (a << 6) | (a >> 26);
#line 260
  a += b;
#line 261
  d += ((b ^ (a | ~ c)) + x[7]) + 1126891415UL;
#line 261
  d = (d << 10) | (d >> 22);
#line 261
  d += a;
#line 262
  c += ((a ^ (d | ~ b)) + x[14]) + 2878612391UL;
#line 262
  c = (c << 15) | (c >> 17);
#line 262
  c += d;
#line 263
  b += ((d ^ (c | ~ a)) + x[5]) + 4237533241UL;
#line 263
  b = (b << 21) | (b >> 11);
#line 263
  b += c;
#line 264
  a += ((c ^ (b | ~ d)) + x[12]) + 1700485571UL;
#line 264
  a = (a << 6) | (a >> 26);
#line 264
  a += b;
#line 265
  d += ((b ^ (a | ~ c)) + x[3]) + 2399980690UL;
#line 265
  d = (d << 10) | (d >> 22);
#line 265
  d += a;
#line 266
  c += ((a ^ (d | ~ b)) + x[10]) + 4293915773UL;
#line 266
  c = (c << 15) | (c >> 17);
#line 266
  c += d;
#line 267
  b += ((d ^ (c | ~ a)) + x[1]) + 2240044497UL;
#line 267
  b = (b << 21) | (b >> 11);
#line 267
  b += c;
#line 268
  a += ((c ^ (b | ~ d)) + x[8]) + 1873313359UL;
#line 268
  a = (a << 6) | (a >> 26);
#line 268
  a += b;
#line 269
  d += ((b ^ (a | ~ c)) + x[15]) + 4264355552UL;
#line 269
  d = (d << 10) | (d >> 22);
#line 269
  d += a;
#line 270
  c += ((a ^ (d | ~ b)) + x[6]) + 2734768916UL;
#line 270
  c = (c << 15) | (c >> 17);
#line 270
  c += d;
#line 271
  b += ((d ^ (c | ~ a)) + x[13]) + 1309151649UL;
#line 271
  b = (b << 21) | (b >> 11);
#line 271
  b += c;
#line 272
  a += ((c ^ (b | ~ d)) + x[4]) + 4149444226UL;
#line 272
  a = (a << 6) | (a >> 26);
#line 272
  a += b;
#line 273
  d += ((b ^ (a | ~ c)) + x[11]) + 3174756917UL;
#line 273
  d = (d << 10) | (d >> 22);
#line 273
  d += a;
#line 274
  c += ((a ^ (d | ~ b)) + x[2]) + 718787259UL;
#line 274
  c = (c << 15) | (c >> 17);
#line 274
  c += d;
#line 275
  b += ((d ^ (c | ~ a)) + x[9]) + 3951481745UL;
#line 275
  b = (b << 21) | (b >> 11);
#line 275
  b += c;
#line 277
  *(state + 0) += a;
#line 278
  *(state + 1) += b;
#line 279
  *(state + 2) += c;
#line 280
  *(state + 3) += d;
#line 284
  MD5_memset((POINTER )(x), 0, (unsigned int )sizeof(x));
  }
#line 285
  return;
}
}
#line 290 "/home/wheatley/newnew/temp/postal-0.73/md5.c"
static void Encode(unsigned char *output , UINT4 *input , unsigned int len ) 
{ 
  unsigned int i ;
  unsigned int j ;

  {
#line 297
  i = 0U;
#line 297
  j = 0U;
  {
#line 297
  while (1) {
    while_continue: /* CIL Label */ ;
#line 297
    if (! (j < len)) {
#line 297
      goto while_break;
    }
#line 298
    *(output + j) = (unsigned char )(*(input + i) & 255UL);
#line 299
    *(output + (j + 1U)) = (unsigned char )((*(input + i) >> 8) & 255UL);
#line 300
    *(output + (j + 2U)) = (unsigned char )((*(input + i) >> 16) & 255UL);
#line 301
    *(output + (j + 3U)) = (unsigned char )((*(input + i) >> 24) & 255UL);
#line 297
    i ++;
#line 297
    j += 4U;
  }
  while_break: /* CIL Label */ ;
  }
#line 303
  return;
}
}
#line 308 "/home/wheatley/newnew/temp/postal-0.73/md5.c"
static void Decode(UINT4 *output , unsigned char *input , unsigned int len ) 
{ 
  unsigned int i ;
  unsigned int j ;

  {
#line 315
  i = 0U;
#line 315
  j = 0U;
  {
#line 315
  while (1) {
    while_continue: /* CIL Label */ ;
#line 315
    if (! (j < len)) {
#line 315
      goto while_break;
    }
#line 316
    *(output + i) = (((UINT4 )*(input + j) | ((UINT4 )*(input + (j + 1U)) << 8)) | ((UINT4 )*(input + (j + 2U)) << 16)) | ((UINT4 )*(input + (j + 3U)) << 24);
#line 315
    i ++;
#line 315
    j += 4U;
  }
  while_break: /* CIL Label */ ;
  }
#line 318
  return;
}
}
#line 323 "/home/wheatley/newnew/temp/postal-0.73/md5.c"
static void MD5_memcpy(POINTER output , POINTER input , unsigned int len ) 
{ 
  unsigned int i ;

  {
#line 330
  i = 0U;
  {
#line 330
  while (1) {
    while_continue: /* CIL Label */ ;
#line 330
    if (! (i < len)) {
#line 330
      goto while_break;
    }
#line 331
    *(output + i) = *(input + i);
#line 330
    i ++;
  }
  while_break: /* CIL Label */ ;
  }
#line 332
  return;
}
}
#line 336 "/home/wheatley/newnew/temp/postal-0.73/md5.c"
static void MD5_memset(POINTER output , int value , unsigned int len ) 
{ 
  unsigned int i ;

  {
#line 343
  i = 0U;
  {
#line 343
  while (1) {
    while_continue: /* CIL Label */ ;
#line 343
    if (! (i < len)) {
#line 343
      goto while_break;
    }
#line 344
    *((char *)output + i) = (char )value;
#line 343
    i ++;
  }
  while_break: /* CIL Label */ ;
  }
#line 345
  return;
}
}
