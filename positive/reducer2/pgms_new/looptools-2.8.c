/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is false */

#line 212 "/usr/lib/gcc/x86_64-linux-gnu/4.8/include/stddef.h"
typedef unsigned long size_t;
#line 33 "/home/june/repo/benchmarks/collector/temp/looptools-2.8/build/cache.c"
typedef long long dblint;
#line 35 "/home/june/repo/benchmarks/collector/temp/looptools-2.8/build/cache.c"
typedef unsigned long long udblint;
#line 37 "/home/june/repo/benchmarks/collector/temp/looptools-2.8/build/cache.c"
struct __anonstruct_RealType_25 {
   dblint part[1] ;
};
#line 37 "/home/june/repo/benchmarks/collector/temp/looptools-2.8/build/cache.c"
typedef struct __anonstruct_RealType_25 RealType;
#line 39 "/home/june/repo/benchmarks/collector/temp/looptools-2.8/build/cache.c"
typedef RealType const   cRealType;
#line 41 "/home/june/repo/benchmarks/collector/temp/looptools-2.8/build/cache.c"
struct __anonstruct_ComplexType_26 {
   RealType re ;
   RealType im ;
};
#line 41 "/home/june/repo/benchmarks/collector/temp/looptools-2.8/build/cache.c"
typedef struct __anonstruct_ComplexType_26 ComplexType;
#line 44 "/home/june/repo/benchmarks/collector/temp/looptools-2.8/build/cache.c"
typedef long long memindex;
#line 47 "/home/june/repo/benchmarks/collector/temp/looptools-2.8/build/cache.c"
struct __anonstruct_ltcache__27 {
   int cmpbits ;
};
#line 108 "/home/june/repo/benchmarks/collector/temp/looptools-2.8/build/cache.c"
struct node {
   struct node *next[2] ;
   struct node *succ ;
   int serial ;
   RealType para[2] ;
};
#line 108 "/home/june/repo/benchmarks/collector/temp/looptools-2.8/build/cache.c"
typedef struct node Node;
#line 466 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) malloc)(size_t __size )  __attribute__((__malloc__)) ;
#line 46 "/usr/include/string.h"
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1,2), __leaf__)) memcpy)(void * __restrict  __dest ,
                                                                                                 void const   * __restrict  __src ,
                                                                                                 size_t __n ) ;
#line 69 "/usr/include/assert.h"
extern  __attribute__((__nothrow__, __noreturn__)) void ( __attribute__((__leaf__)) __assert_fail)(char const   *__assertion ,
                                                                                                   char const   *__file ,
                                                                                                   unsigned int __line ,
                                                                                                   char const   *__function ) ;
#line 47 "/home/june/repo/benchmarks/collector/temp/looptools-2.8/build/cache.c"
extern struct __anonstruct_ltcache__27 ltcache_ ;
#line 59 "/home/june/repo/benchmarks/collector/temp/looptools-2.8/build/cache.c"
__inline static int SignBit(dblint const   i ) 
{ 


  {
#line 61
  return ((int )((udblint )i >> (8UL * sizeof(i) - 1UL)));
}
}
#line 65 "/home/june/repo/benchmarks/collector/temp/looptools-2.8/build/cache.c"
__inline static memindex PtrDiff(void const   *a , void const   *b ) 
{ 


  {
#line 67
  return ((memindex )((char *)a - (char *)b));
}
}
#line 71 "/home/june/repo/benchmarks/collector/temp/looptools-2.8/build/cache.c"
static dblint CmpPara(cRealType *para1 , cRealType *para2 , int n , dblint const   mask ) 
{ 
  dblint c ;
  int tmp ;

  {
  {
#line 74
  while (1) {
    while_continue: /* CIL Label */ ;
#line 74
    tmp = n;
#line 74
    n --;
#line 74
    if (! tmp) {
#line 74
      goto while_break;
    }
#line 75
    c = (dblint )((mask & (long long const   )para1->part[0]) - (mask & (long long const   )para2->part[0]));
#line 77
    if (c) {
#line 77
      return (c);
    }
#line 78
    para1 ++;
#line 79
    para2 ++;
  }
  while_break: /* CIL Label */ ;
  }
#line 81
  return ((dblint )0);
}
}
#line 104 "/home/june/repo/benchmarks/collector/temp/looptools-2.8/build/cache.c"
static void *Lookup(cRealType *para , double *base , void (*calc)(RealType * , cRealType * ) ,
                    int const   npara , int const   nval ) 
{ 
  int valid ;
  Node **last ;
  Node **next ;
  Node *node ;
  dblint mask ;
  dblint i ;
  dblint tmp ;
  int tmp___0 ;
  void *tmp___1 ;
  memindex tmp___2 ;

  {
#line 118
  valid = *((int *)(base + 0));
#line 119
  last = *((Node ***)(base + 1));
#line 120
  next = (Node **)(base + 2);
#line 123
  if ((unsigned long )last == (unsigned long )((void *)0)) {
#line 123
    last = next;
  }
#line 125
  if (ltcache_.cmpbits > 0) {
#line 126
    mask = (dblint )(- (1ULL << ((64 - ltcache_.cmpbits) & (- (64 - ltcache_.cmpbits) >> (sizeof(- (64 - ltcache_.cmpbits)) * 8UL - 1UL)))));
    {
#line 137
    while (1) {
      while_continue: /* CIL Label */ ;
#line 137
      node = *next;
#line 137
      if (node) {
#line 137
        if (! (node->serial < valid)) {
#line 137
          goto while_break;
        }
      } else {
#line 137
        goto while_break;
      }
      {
#line 138
      tmp = CmpPara(para, (cRealType *)(node->para), (int )npara, (dblint const   )mask);
#line 138
      i = tmp;
      }
#line 139
      if (i == 0LL) {
#line 139
        return ((void *)(& node->para[npara]));
      }
      {
#line 140
      tmp___0 = SignBit((dblint const   )i);
#line 140
      next = & node->next[tmp___0];
      }
    }
    while_break: /* CIL Label */ ;
    }
  }
#line 144
  node = *last;
#line 146
  if ((unsigned long )node == (unsigned long )((void *)0)) {
    {
#line 150
    tmp___1 = malloc((sizeof(Node ) + (unsigned long )npara * sizeof(RealType )) + (unsigned long )nval * sizeof(ComplexType ));
#line 150
    node = (Node *)tmp___1;
    }
#line 150
    if (! node) {
      {
#line 150
      __assert_fail("node = malloc(sizeof(Node) + npara*sizeof(RealType) + nval*sizeof(ComplexType))",
                    "/home/june/repo/benchmarks/collector/temp/looptools-2.8/build/cache.c",
                    151U, "Lookup");
      }
    }
    {
#line 152
    tmp___2 = PtrDiff((void const   *)base, (void const   *)(& node->para[npara]));
#line 152
    node = (Node *)((char *)node + (tmp___2 & (long long )(sizeof(ComplexType ) - 1UL)));
#line 154
    node->succ = (struct node *)((void *)0);
#line 155
    node->serial = valid;
#line 156
    *last = node;
    }
  }
  {
#line 159
  *next = node;
#line 160
  *((Node ***)(base + 1)) = & node->succ;
#line 161
  *((int *)(base + 0)) = valid + 1;
#line 163
  node->next[0] = (struct node *)((void *)0);
#line 164
  node->next[1] = (struct node *)((void *)0);
#line 166
  memcpy((void */* __restrict  */)(node->para), (void const   */* __restrict  */)para,
         (unsigned long )npara * sizeof(RealType ));
#line 167
  (*calc)(& node->para[npara], para);
  }
#line 169
  return ((void *)(& node->para[npara]));
}
}
#line 173 "/home/june/repo/benchmarks/collector/temp/looptools-2.8/build/cache.c"
memindex ljcacheindex_(cRealType *para , double *base , void (*calc)(RealType * ,
                                                                     cRealType * ) ,
                       int const   *pnpara , int const   *pnval ) 
{ 
  ComplexType *val ;
  void *tmp ;
  memindex tmp___0 ;

  {
  {
#line 177
  tmp = Lookup(para, base, calc, *pnpara, *pnval);
#line 177
  val = (ComplexType *)tmp;
#line 178
  tmp___0 = PtrDiff((void const   *)val, (void const   *)base);
  }
#line 178
  return (tmp___0 / (memindex )((long )sizeof(ComplexType )));
}
}
#line 182 "/home/june/repo/benchmarks/collector/temp/looptools-2.8/build/cache.c"
void ljcachecopy_(ComplexType *dest , cRealType *para , double *base , void (*calc)(RealType * ,
                                                                                    cRealType * ) ,
                  int const   *pnpara , int const   *pnval ) 
{ 
  ComplexType *val ;
  void *tmp ;

  {
  {
#line 186
  tmp = Lookup(para, base, calc, *pnpara, *pnval);
#line 186
  val = (ComplexType *)tmp;
#line 187
  memcpy((void */* __restrict  */)dest, (void const   */* __restrict  */)val, (unsigned long )*pnval * sizeof(*dest));
  }
#line 188
  return;
}
}