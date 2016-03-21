/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is false */

#line 125 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned int __uid_t;
#line 126 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned int __gid_t;
#line 133 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef int __pid_t;
#line 172 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __ssize_t;
#line 189 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned int __socklen_t;
#line 65 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __gid_t gid_t;
#line 80 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __uid_t uid_t;
#line 98 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __pid_t pid_t;
#line 109 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __ssize_t ssize_t;
#line 212 "/usr/lib/gcc/x86_64-linux-gnu/4.8/include/stddef.h"
typedef unsigned long size_t;
#line 43 "/usr/include/x86_64-linux-gnu/bits/uio.h"
struct iovec {
   void *iov_base ;
   size_t iov_len ;
};
#line 33 "/usr/include/x86_64-linux-gnu/bits/socket.h"
typedef __socklen_t socklen_t;
#line 224 "/usr/include/x86_64-linux-gnu/bits/socket.h"
struct msghdr {
   void *msg_name ;
   socklen_t msg_namelen ;
   struct iovec *msg_iov ;
   size_t msg_iovlen ;
   void *msg_control ;
   size_t msg_controllen ;
   int msg_flags ;
};
#line 242 "/usr/include/x86_64-linux-gnu/bits/socket.h"
struct cmsghdr {
   size_t cmsg_len ;
   int cmsg_level ;
   int cmsg_type ;
   unsigned char __cmsg_data[] ;
};
#line 311 "/usr/include/x86_64-linux-gnu/bits/socket.h"
struct ucred {
   pid_t pid ;
   uid_t uid ;
   gid_t gid ;
};
#line 20 "/usr/include/asm-generic/int-ll64.h"
typedef unsigned char __u8;
#line 23 "/usr/include/asm-generic/int-ll64.h"
typedef unsigned short __u16;
#line 26 "/usr/include/asm-generic/int-ll64.h"
typedef unsigned int __u32;
#line 48 "/usr/include/stdint.h"
typedef unsigned char uint8_t;
#line 49 "/usr/include/stdint.h"
typedef unsigned short uint16_t;
#line 51 "/usr/include/stdint.h"
typedef unsigned int uint32_t;
#line 42 "/usr/include/linux/netlink.h"
struct nlmsghdr {
   __u32 nlmsg_len ;
   __u16 nlmsg_type ;
   __u16 nlmsg_flags ;
   __u32 nlmsg_seq ;
   __u32 nlmsg_pid ;
};
#line 99 "/usr/include/linux/netlink.h"
struct nlmsgerr {
   int error ;
   struct nlmsghdr msg ;
};
#line 7 "/usr/include/linux/if_addr.h"
struct ifaddrmsg {
   __u8 ifa_family ;
   __u8 ifa_prefixlen ;
   __u8 ifa_flags ;
   __u8 ifa_scope ;
   __u32 ifa_index ;
};
#line 149 "/usr/include/linux/rtnetlink.h"
struct rtattr {
   unsigned short rta_len ;
   unsigned short rta_type ;
};
#line 432 "/usr/include/linux/rtnetlink.h"
struct rtgenmsg {
   unsigned char rtgen_family ;
};
#line 209 "/usr/include/netinet/in.h"
union __anonunion___in6_u_60 {
   uint8_t __u6_addr8[16] ;
   uint16_t __u6_addr16[8] ;
   uint32_t __u6_addr32[4] ;
};
#line 209 "/usr/include/netinet/in.h"
struct in6_addr {
   union __anonunion___in6_u_60 __in6_u ;
};
#line 32 "/home/wheatley/newnew/temp/libnss-myhostname-0.3/ifconf.h"
struct address {
   unsigned char family ;
   uint8_t address[16] ;
   unsigned char scope ;
   int ifindex ;
};
#line 42 "/home/wheatley/newnew/temp/libnss-myhostname-0.3/netlink.c"
struct __anonstruct_req_71 {
   struct nlmsghdr hdr ;
   struct rtgenmsg gen ;
};
#line 84 "/home/wheatley/newnew/temp/libnss-myhostname-0.3/netlink.c"
struct __anonstruct_resp_72 {
   struct nlmsghdr hdr ;
   struct ifaddrmsg ifaddrmsg ;
   uint8_t payload[16384] ;
};
#line 38 "/usr/include/stdint.h"
typedef int int32_t;
#line 31 "/usr/include/nss.h"
enum nss_status {
    NSS_STATUS_TRYAGAIN = -2,
    NSS_STATUS_UNAVAIL = -1,
    NSS_STATUS_NOTFOUND = 0,
    NSS_STATUS_SUCCESS = 1,
    NSS_STATUS_RETURN = 2
} ;
#line 42 "/usr/include/nss.h"
struct gaih_addrtuple {
   struct gaih_addrtuple *next ;
   char *name ;
   int family ;
   uint32_t addr[4] ;
   uint32_t scopeid ;
};
#line 100 "/usr/include/netdb.h"
struct hostent {
   char *h_name ;
   char **h_aliases ;
   int h_addrtype ;
   int h_length ;
   char **h_addr_list ;
};
#line 113 "/usr/include/x86_64-linux-gnu/sys/socket.h"
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) socket)(int __domain ,
                                                                             int __type ,
                                                                             int __protocol ) ;
#line 149
extern ssize_t send(int __fd , void const   *__buf , size_t __n , int __flags ) ;
#line 202
extern ssize_t recvmsg(int __fd , struct msghdr *__message , int __flags ) ;
#line 226
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) setsockopt)(int __fd ,
                                                                                 int __level ,
                                                                                 int __optname ,
                                                                                 void const   *__optval ,
                                                                                 socklen_t __optlen ) ;
#line 46 "/usr/include/string.h"
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1,2), __leaf__)) memcpy)(void * __restrict  __dest ,
                                                                                                 void const   * __restrict  __src ,
                                                                                                 size_t __n ) ;
#line 66
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1), __leaf__)) memset)(void *__s ,
                                                                                               int __c ,
                                                                                               size_t __n ) ;
#line 50 "/usr/include/x86_64-linux-gnu/bits/errno.h"
extern  __attribute__((__nothrow__)) int *( __attribute__((__leaf__)) __errno_location)(void)  __attribute__((__const__)) ;
#line 377 "/usr/include/netinet/in.h"
extern  __attribute__((__nothrow__)) uint32_t ( __attribute__((__leaf__)) htonl)(uint32_t __hostlong )  __attribute__((__const__)) ;
#line 353 "/usr/include/unistd.h"
extern int close(int __fd ) ;
#line 480 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) void *( __attribute__((__warn_unused_result__,
__leaf__)) realloc)(void *__ptr , size_t __size ) ;
#line 483
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) free)(void *__ptr ) ;
#line 765
extern void ( __attribute__((__nonnull__(1,4))) qsort)(void *__base , size_t __nmemb ,
                                                       size_t __size , int (*__compar)(void const   * ,
                                                                                       void const   * ) ) ;
#line 42 "/home/wheatley/newnew/temp/libnss-myhostname-0.3/ifconf.h"
int ifconf_acquire_addresses(struct address **_list , unsigned int *_n_list )  __attribute__((__visibility__("hidden"))) ;
#line 50 "/home/wheatley/newnew/temp/libnss-myhostname-0.3/ifconf.h"
__inline static int address_compare(void const   *_a , void const   *_b ) 
{ 
  struct address  const  *a ;
  struct address  const  *b ;

  {
#line 51
  a = (struct address  const  *)_a;
#line 51
  b = (struct address  const  *)_b;
#line 55
  if ((int const   )a->scope < (int const   )b->scope) {
#line 56
    return (-1);
  }
#line 57
  if ((int const   )a->scope > (int const   )b->scope) {
#line 58
    return (1);
  }
#line 60
  if ((int const   )a->family == 2) {
#line 60
    if ((int const   )b->family == 10) {
#line 61
      return (-1);
    }
  }
#line 62
  if ((int const   )a->family == 10) {
#line 62
    if ((int const   )b->family == 2) {
#line 63
      return (1);
    }
  }
#line 65
  if (a->ifindex < b->ifindex) {
#line 66
    return (-1);
  }
#line 67
  if (a->ifindex > b->ifindex) {
#line 68
    return (1);
  }
#line 70
  return (0);
}
}
#line 40 "/home/wheatley/newnew/temp/libnss-myhostname-0.3/netlink.c"
int ifconf_acquire_addresses(struct address **_list , unsigned int *_n_list )  __attribute__((__visibility__("hidden"))) ;
#line 40 "/home/wheatley/newnew/temp/libnss-myhostname-0.3/netlink.c"
int ifconf_acquire_addresses(struct address **_list , unsigned int *_n_list ) 
{ 
  struct __anonstruct_req_71 req ;
  struct rtgenmsg *gen ;
  int fd ;
  int r ;
  int on ;
  uint32_t seq ;
  struct address *list ;
  unsigned int n_list ;
  int *tmp ;
  int *tmp___0 ;
  int tmp___1 ;
  int *tmp___2 ;
  ssize_t tmp___3 ;
  ssize_t bytes ;
  struct msghdr msg ;
  struct cmsghdr *cmsg ;
  struct ucred *ucred ;
  struct iovec iov ;
  struct nlmsghdr *p ;
  uint8_t cred_buffer[(((sizeof(struct ucred ) + sizeof(size_t )) - 1UL) & ~ (sizeof(size_t ) - 1UL)) + (((sizeof(struct cmsghdr ) + sizeof(size_t )) - 1UL) & ~ (sizeof(size_t ) - 1UL))] ;
  struct __anonstruct_resp_72 resp ;
  int *tmp___4 ;
  struct ifaddrmsg *ifaddrmsg ;
  struct rtattr *a ;
  size_t l ;
  void *local ;
  void *address ;
  struct nlmsgerr *nlmsgerr ;
  struct in6_addr  const  *__a ;
  uint32_t tmp___5 ;
  uint32_t tmp___6 ;
  void *tmp___7 ;
  int tmp___8 ;

  {
  {
#line 47
  on = 1;
#line 48
  seq = (uint32_t )4711;
#line 49
  list = (struct address *)((void *)0);
#line 50
  n_list = 0U;
#line 52
  fd = socket(16, 2, 0);
  }
#line 53
  if (fd < 0) {
    {
#line 54
    tmp = __errno_location();
    }
#line 54
    return (- *tmp);
  }
  {
#line 56
  tmp___1 = setsockopt(fd, 1, 16, (void const   *)(& on), (socklen_t )sizeof(on));
  }
#line 56
  if (tmp___1 < 0) {
    {
#line 57
    tmp___0 = __errno_location();
#line 57
    r = - *tmp___0;
    }
#line 58
    goto finish;
  }
  {
#line 61
  memset((void *)(& req), 0, sizeof(req));
#line 62
  req.hdr.nlmsg_len = (__u32 )(sizeof(struct rtgenmsg ) + (unsigned long )((int )(((sizeof(struct nlmsghdr ) + 4UL) - 1UL) & 4294967292UL)));
#line 63
  req.hdr.nlmsg_type = (__u16 )22;
#line 64
  req.hdr.nlmsg_flags = (__u16 )773;
#line 65
  req.hdr.nlmsg_seq = seq;
#line 66
  req.hdr.nlmsg_pid = (__u32 )0;
#line 68
  gen = (struct rtgenmsg *)((void *)((char *)(& req.hdr) + (int )(((sizeof(struct nlmsghdr ) + 4UL) - 1UL) & 4294967292UL)));
#line 69
  gen->rtgen_family = (unsigned char)0;
#line 71
  tmp___3 = send(fd, (void const   *)(& req), (size_t )req.hdr.nlmsg_len, 0);
  }
#line 71
  if (tmp___3 < 0L) {
    {
#line 72
    tmp___2 = __errno_location();
#line 72
    r = - *tmp___2;
    }
#line 73
    goto finish;
  }
  {
#line 76
  while (1) {
    while_continue: /* CIL Label */ ;
    {
#line 90
    memset((void *)(& iov), 0, sizeof(iov));
#line 91
    iov.iov_base = (void *)(& resp);
#line 92
    iov.iov_len = sizeof(resp);
#line 94
    memset((void *)(& msg), 0, sizeof(msg));
#line 95
    msg.msg_name = (void *)0;
#line 96
    msg.msg_namelen = (socklen_t )0;
#line 97
    msg.msg_iov = & iov;
#line 98
    msg.msg_iovlen = (size_t )1;
#line 99
    msg.msg_control = (void *)(cred_buffer);
#line 100
    msg.msg_controllen = sizeof(cred_buffer);
#line 101
    msg.msg_flags = 0;
#line 103
    bytes = recvmsg(fd, & msg, 0);
    }
#line 104
    if (bytes < 0L) {
      {
#line 105
      tmp___4 = __errno_location();
#line 105
      r = - *tmp___4;
      }
#line 106
      goto finish;
    }
#line 109
    if (msg.msg_controllen >= sizeof(struct cmsghdr )) {
#line 109
      cmsg = (struct cmsghdr *)msg.msg_control;
    } else {
#line 109
      cmsg = (struct cmsghdr *)0;
    }
#line 110
    if (! cmsg) {
#line 111
      r = -5;
#line 112
      goto finish;
    } else
#line 110
    if (cmsg->cmsg_type != 2) {
#line 111
      r = -5;
#line 112
      goto finish;
    }
#line 115
    ucred = (struct ucred *)(cmsg->__cmsg_data);
#line 116
    if (ucred->uid != 0U) {
#line 117
      goto __Cont;
    } else
#line 116
    if (ucred->pid != 0) {
#line 117
      goto __Cont;
    }
#line 119
    p = & resp.hdr;
    {
#line 119
    while (1) {
      while_continue___0: /* CIL Label */ ;
#line 119
      if (! (bytes > 0L)) {
#line 119
        goto while_break___0;
      }
#line 123
      local = (void *)0;
#line 123
      address = (void *)0;
#line 125
      if ((size_t )bytes >= (size_t )((int )sizeof(struct nlmsghdr ))) {
#line 125
        if ((unsigned long )p->nlmsg_len >= sizeof(struct nlmsghdr )) {
#line 125
          if (! ((size_t )p->nlmsg_len <= (size_t )bytes)) {
#line 126
            r = -5;
#line 127
            goto finish;
          }
        } else {
#line 126
          r = -5;
#line 127
          goto finish;
        }
      } else {
#line 126
        r = -5;
#line 127
        goto finish;
      }
#line 130
      if (p->nlmsg_seq != seq) {
#line 131
        goto __Cont___0;
      }
#line 133
      if ((int )p->nlmsg_type == 3) {
#line 134
        r = 0;
#line 135
        goto finish;
      }
#line 138
      if ((int )p->nlmsg_type == 2) {
#line 141
        nlmsgerr = (struct nlmsgerr *)((void *)((char *)p + (int )(((sizeof(struct nlmsghdr ) + 4UL) - 1UL) & 4294967292UL)));
#line 142
        r = - nlmsgerr->error;
#line 143
        goto finish;
      }
#line 146
      if ((int )p->nlmsg_type != 20) {
#line 147
        goto __Cont___0;
      }
#line 149
      ifaddrmsg = (struct ifaddrmsg *)((void *)((char *)p + (int )(((sizeof(struct nlmsghdr ) + 4UL) - 1UL) & 4294967292UL)));
#line 151
      if ((int )ifaddrmsg->ifa_family != 2) {
#line 151
        if ((int )ifaddrmsg->ifa_family != 10) {
#line 153
          goto __Cont___0;
        }
      }
#line 155
      if ((int )ifaddrmsg->ifa_scope == 254) {
#line 157
        goto __Cont___0;
      } else
#line 155
      if ((int )ifaddrmsg->ifa_scope == 255) {
#line 157
        goto __Cont___0;
      }
#line 159
      if ((int )ifaddrmsg->ifa_flags & 32) {
#line 160
        goto __Cont___0;
      }
#line 162
      l = (unsigned long )p->nlmsg_len - ((((sizeof(struct ifaddrmsg ) + (unsigned long )((int )(((sizeof(struct nlmsghdr ) + 4UL) - 1UL) & 4294967292UL))) + 4UL) - 1UL) & 4294967292UL);
#line 163
      a = (struct rtattr *)((char *)ifaddrmsg + (((sizeof(struct ifaddrmsg ) + 4UL) - 1UL) & 4294967292UL));
      {
#line 165
      while (1) {
        while_continue___1: /* CIL Label */ ;
#line 165
        if (l >= (size_t )((int )sizeof(struct rtattr ))) {
#line 165
          if ((unsigned long )a->rta_len >= sizeof(struct rtattr )) {
#line 165
            if (! ((size_t )a->rta_len <= l)) {
#line 165
              goto while_break___1;
            }
          } else {
#line 165
            goto while_break___1;
          }
        } else {
#line 165
          goto while_break___1;
        }
#line 167
        if ((int )a->rta_type == 1) {
#line 168
          address = (void *)((char *)a + (((sizeof(struct rtattr ) + 4UL) - 1UL) & 0xfffffffffffffffcUL));
        } else
#line 169
        if ((int )a->rta_type == 2) {
#line 170
          local = (void *)((char *)a + (((sizeof(struct rtattr ) + 4UL) - 1UL) & 0xfffffffffffffffcUL));
        }
#line 172
        l -= (size_t )((((int )a->rta_len + 4) - 1) & -4);
#line 172
        a = (struct rtattr *)((char *)a + ((((int )a->rta_len + 4) - 1) & -4));
      }
      while_break___1: /* CIL Label */ ;
      }
#line 175
      if (local) {
#line 176
        address = local;
      }
#line 178
      if (! address) {
#line 179
        goto __Cont___0;
      }
#line 184
      if ((int )ifaddrmsg->ifa_family == 10) {
        {
#line 184
        __a = (struct in6_addr  const  *)address;
#line 184
        tmp___5 = htonl(4290772992U);
#line 184
        tmp___6 = htonl(4269801472U);
        }
#line 184
        if ((__a->__in6_u.__u6_addr32[0] & tmp___5) == tmp___6) {
#line 185
          goto __Cont___0;
        }
      }
      {
#line 187
      tmp___7 = realloc((void *)list, (unsigned long )(n_list + 1U) * sizeof(struct address ));
#line 187
      list = (struct address *)tmp___7;
      }
#line 188
      if (! list) {
#line 189
        r = -12;
#line 190
        goto finish;
      }
#line 193
      (list + n_list)->family = ifaddrmsg->ifa_family;
#line 194
      (list + n_list)->scope = ifaddrmsg->ifa_scope;
#line 195
      if ((int )ifaddrmsg->ifa_family == 2) {
#line 195
        tmp___8 = 4;
      } else {
#line 195
        tmp___8 = 16;
      }
      {
#line 195
      memcpy((void */* __restrict  */)((list + n_list)->address), (void const   */* __restrict  */)address,
             (size_t )tmp___8);
#line 196
      (list + n_list)->ifindex = (int )ifaddrmsg->ifa_index;
#line 198
      n_list ++;
      }
      __Cont___0: /* CIL Label */ 
#line 119
      bytes -= (ssize_t )(((p->nlmsg_len + 4U) - 1U) & 4294967292U);
#line 119
      p = (struct nlmsghdr *)((char *)p + (((p->nlmsg_len + 4U) - 1U) & 4294967292U));
    }
    while_break___0: /* CIL Label */ ;
    }
    __Cont: /* CIL Label */ ;
  }
  while_break: /* CIL Label */ ;
  }
  finish: 
  {
#line 203
  close(fd);
  }
#line 205
  if (r < 0) {
    {
#line 206
    free((void *)list);
    }
  } else {
    {
#line 208
    qsort((void *)list, (size_t )n_list, sizeof(struct address ), & address_compare);
#line 210
    *_list = list;
#line 211
    *_n_list = n_list;
    }
  }
#line 214
  return (r);
}
}
#line 228 "/usr/include/netinet/in.h"
extern struct in6_addr  const  in6addr_loopback ;
#line 69 "/usr/include/string.h"
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2), __leaf__)) memcmp)(void const   *__s1 ,
                                                                                               void const   *__s2 ,
                                                                                               size_t __n )  __attribute__((__pure__)) ;
#line 399
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__nonnull__(1), __leaf__)) strlen)(char const   *__s )  __attribute__((__pure__)) ;
#line 534
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2), __leaf__)) strcasecmp)(char const   *__s1 ,
                                                                                                   char const   *__s2 )  __attribute__((__pure__)) ;
#line 69 "/usr/include/assert.h"
extern  __attribute__((__nothrow__, __noreturn__)) void ( __attribute__((__leaf__)) __assert_fail)(char const   *__assertion ,
                                                                                                   char const   *__file ,
                                                                                                   unsigned int __line ,
                                                                                                   char const   *__function ) ;
#line 879 "/usr/include/unistd.h"
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) gethostname)(char *__name ,
                                                                                                  size_t __len ) ;
#line 193 "/usr/include/net/if.h"
extern  __attribute__((__nothrow__)) unsigned int ( __attribute__((__leaf__)) if_nametoindex)(char const   *__ifname ) ;
#line 44 "/home/wheatley/newnew/temp/libnss-myhostname-0.3/ifconf.h"
__inline static size_t PROTO_ADDRESS_SIZE(int proto ) 
{ 
  int tmp ;

  {
#line 45
  if (! (proto == 2)) {
#line 45
    if (! (proto == 10)) {
      {
#line 45
      __assert_fail("proto == 2 || proto == 10", "/home/wheatley/newnew/temp/libnss-myhostname-0.3/ifconf.h",
                    45U, "PROTO_ADDRESS_SIZE");
      }
    }
  }
#line 47
  if (proto == 10) {
#line 47
    tmp = 16;
  } else {
#line 47
    tmp = 4;
  }
#line 47
  return ((size_t )tmp);
}
}
#line 50 "/home/wheatley/newnew/temp/libnss-myhostname-0.3/nss-myhostname.c"
enum nss_status _nss_myhostname_gethostbyname4_r(char const   *name , struct gaih_addrtuple **pat ,
                                                 char *buffer , size_t buflen , int *errnop ,
                                                 int *h_errnop , int32_t *ttlp )  __attribute__((__visibility__("default"))) ;
#line 57
enum nss_status _nss_myhostname_gethostbyname3_r(char const   *name , int af , struct hostent *host ,
                                                 char *buffer , size_t buflen , int *errnop ,
                                                 int *h_errnop , int32_t *ttlp , char **canonp )  __attribute__((__visibility__("default"))) ;
#line 66
enum nss_status _nss_myhostname_gethostbyname2_r(char const   *name , int af , struct hostent *host ,
                                                 char *buffer , size_t buflen , int *errnop ,
                                                 int *h_errnop )  __attribute__((__visibility__("default"))) ;
#line 73
enum nss_status _nss_myhostname_gethostbyname_r(char const   *name , struct hostent *host ,
                                                char *buffer , size_t buflen , int *errnop ,
                                                int *h_errnop )  __attribute__((__visibility__("default"))) ;
#line 79
enum nss_status _nss_myhostname_gethostbyaddr2_r(void const   *addr , socklen_t len ,
                                                 int af , struct hostent *host , char *buffer ,
                                                 size_t buflen , int *errnop , int *h_errnop ,
                                                 int32_t *ttlp )  __attribute__((__visibility__("default"))) ;
#line 87
enum nss_status _nss_myhostname_gethostbyaddr_r(void const   *addr , socklen_t len ,
                                                int af , struct hostent *host , char *buffer ,
                                                size_t buflen , int *errnop , int *h_errnop )  __attribute__((__visibility__("default"))) ;
#line 94
enum nss_status _nss_myhostname_gethostbyname4_r(char const   *name , struct gaih_addrtuple **pat ,
                                                 char *buffer , size_t buflen , int *errnop ,
                                                 int *h_errnop , int32_t *ttlp )  __attribute__((__visibility__("default"))) ;
#line 94 "/home/wheatley/newnew/temp/libnss-myhostname-0.3/nss-myhostname.c"
enum nss_status _nss_myhostname_gethostbyname4_r(char const   *name , struct gaih_addrtuple **pat ,
                                                 char *buffer , size_t buflen , int *errnop ,
                                                 int *h_errnop , int32_t *ttlp ) 
{ 
  unsigned int lo_ifi ;
  char hn[65] ;
  size_t l ;
  size_t idx ;
  size_t ms ;
  char *r_name ;
  struct gaih_addrtuple *r_tuple ;
  struct gaih_addrtuple *r_tuple_prev ;
  struct address *addresses ;
  struct address *a ;
  unsigned int n_addresses ;
  unsigned int n ;
  int *tmp ;
  int tmp___0 ;
  int tmp___1 ;
  unsigned int tmp___2 ;

  {
  {
#line 105
  r_tuple_prev = (struct gaih_addrtuple *)((void *)0);
#line 106
  addresses = (struct address *)((void *)0);
#line 107
  n_addresses = 0U;
#line 109
  memset((void *)(hn), 0, sizeof(hn));
#line 110
  tmp___0 = gethostname(hn, sizeof(hn) - 1UL);
  }
#line 110
  if (tmp___0 < 0) {
    {
#line 111
    tmp = __errno_location();
#line 111
    *errnop = *tmp;
#line 112
    *h_errnop = 3;
    }
#line 113
    return ((enum nss_status )-1);
  }
  {
#line 116
  tmp___1 = strcasecmp(name, (char const   *)(hn));
  }
#line 116
  if (tmp___1 != 0) {
#line 117
    *errnop = 2;
#line 118
    *h_errnop = 1;
#line 119
    return ((enum nss_status )0);
  }
  {
#line 123
  ifconf_acquire_addresses(& addresses, & n_addresses);
#line 126
  lo_ifi = if_nametoindex("lo");
#line 128
  l = strlen((char const   *)(hn));
  }
#line 129
  if (n_addresses > 0U) {
#line 129
    tmp___2 = n_addresses;
  } else {
#line 129
    tmp___2 = 2U;
  }
#line 129
  ms = ((((l + 1UL) + sizeof(void *)) - 1UL) / sizeof(void *)) * sizeof(void *) + ((((sizeof(struct gaih_addrtuple ) + sizeof(void *)) - 1UL) / sizeof(void *)) * sizeof(void *)) * (unsigned long )tmp___2;
#line 130
  if (buflen < ms) {
    {
#line 131
    *errnop = 12;
#line 132
    *h_errnop = 3;
#line 133
    free((void *)addresses);
    }
#line 134
    return ((enum nss_status )-2);
  }
  {
#line 138
  r_name = buffer;
#line 139
  memcpy((void */* __restrict  */)r_name, (void const   */* __restrict  */)(hn), l + 1UL);
#line 140
  idx = ((((l + 1UL) + sizeof(void *)) - 1UL) / sizeof(void *)) * sizeof(void *);
  }
#line 142
  if (n_addresses <= 0U) {
    {
#line 144
    r_tuple = (struct gaih_addrtuple *)(buffer + idx);
#line 145
    r_tuple->next = r_tuple_prev;
#line 146
    r_tuple->name = r_name;
#line 147
    r_tuple->family = 10;
#line 148
    memcpy((void */* __restrict  */)(r_tuple->addr), (void const   */* __restrict  */)(& in6addr_loopback),
           (size_t )16);
#line 149
    r_tuple->scopeid = lo_ifi;
#line 151
    idx += (((sizeof(struct gaih_addrtuple ) + sizeof(void *)) - 1UL) / sizeof(void *)) * sizeof(void *);
#line 152
    r_tuple_prev = r_tuple;
#line 155
    r_tuple = (struct gaih_addrtuple *)(buffer + idx);
#line 156
    r_tuple->next = r_tuple_prev;
#line 157
    r_tuple->name = r_name;
#line 158
    r_tuple->family = 2;
#line 159
    r_tuple->addr[0] = htonl((uint32_t )2130706689);
#line 160
    r_tuple->scopeid = lo_ifi;
#line 162
    idx += (((sizeof(struct gaih_addrtuple ) + sizeof(void *)) - 1UL) / sizeof(void *)) * sizeof(void *);
#line 163
    r_tuple_prev = r_tuple;
    }
  }
#line 167
  a = (addresses + n_addresses) - 1;
#line 167
  n = 0U;
  {
#line 167
  while (1) {
    while_continue: /* CIL Label */ ;
#line 167
    if (! (n < n_addresses)) {
#line 167
      goto while_break;
    }
    {
#line 168
    r_tuple = (struct gaih_addrtuple *)(buffer + idx);
#line 169
    r_tuple->next = r_tuple_prev;
#line 170
    r_tuple->name = r_name;
#line 171
    r_tuple->family = (int )a->family;
#line 172
    r_tuple->scopeid = (uint32_t )a->ifindex;
#line 173
    memcpy((void */* __restrict  */)(r_tuple->addr), (void const   */* __restrict  */)(a->address),
           (size_t )16);
#line 175
    idx += (((sizeof(struct gaih_addrtuple ) + sizeof(void *)) - 1UL) / sizeof(void *)) * sizeof(void *);
#line 176
    r_tuple_prev = r_tuple;
#line 167
    n ++;
#line 167
    a --;
    }
  }
  while_break: /* CIL Label */ ;
  }
#line 180
  if (! (idx == ms)) {
    {
#line 180
    __assert_fail("idx == ms", "/home/wheatley/newnew/temp/libnss-myhostname-0.3/nss-myhostname.c",
                  180U, "_nss_myhostname_gethostbyname4_r");
    }
  }
#line 182
  *pat = r_tuple_prev;
#line 184
  if (ttlp) {
#line 185
    *ttlp = 0;
  }
  {
#line 187
  free((void *)addresses);
  }
#line 189
  return ((enum nss_status )1);
}
}
#line 192 "/home/wheatley/newnew/temp/libnss-myhostname-0.3/nss-myhostname.c"
static enum nss_status fill_in_hostent(char const   *hn , int af , struct hostent *result ,
                                       char *buffer , size_t buflen , int *errnop ,
                                       int *h_errnop , int32_t *ttlp , char **canonp ) 
{ 
  size_t l ;
  size_t idx ;
  size_t ms ;
  char *r_addr ;
  char *r_name ;
  char *r_aliases ;
  char *r_addr_list ;
  size_t alen ;
  struct address *addresses ;
  struct address *a ;
  unsigned int n_addresses ;
  unsigned int n ;
  unsigned int c ;
  unsigned int tmp ;
  unsigned int tmp___0 ;
  unsigned int i ;
  unsigned int i___0 ;

  {
  {
#line 204
  addresses = (struct address *)((void *)0);
#line 205
  n_addresses = 0U;
#line 207
  alen = PROTO_ADDRESS_SIZE(af);
#line 209
  ifconf_acquire_addresses(& addresses, & n_addresses);
#line 211
  a = addresses;
#line 211
  n = 0U;
#line 211
  c = 0U;
  }
  {
#line 211
  while (1) {
    while_continue: /* CIL Label */ ;
#line 211
    if (! (n < n_addresses)) {
#line 211
      goto while_break;
    }
#line 212
    if (af == (int )a->family) {
#line 213
      c ++;
    }
#line 211
    a ++;
#line 211
    n ++;
  }
  while_break: /* CIL Label */ ;
  }
  {
#line 215
  l = strlen(hn);
  }
#line 216
  if (c > 0U) {
#line 216
    tmp = c;
  } else {
#line 216
    tmp = 1U;
  }
#line 216
  if (c > 0U) {
#line 216
    tmp___0 = c + 1U;
  } else {
#line 216
    tmp___0 = 2U;
  }
#line 216
  ms = ((((((l + 1UL) + sizeof(void *)) - 1UL) / sizeof(void *)) * sizeof(void *) + sizeof(char *)) + (size_t )tmp * ((((alen + sizeof(void *)) - 1UL) / sizeof(void *)) * sizeof(void *))) + (unsigned long )tmp___0 * sizeof(char *);
#line 221
  if (buflen < ms) {
    {
#line 222
    *errnop = 12;
#line 223
    *h_errnop = 3;
#line 224
    free((void *)addresses);
    }
#line 225
    return ((enum nss_status )-2);
  }
  {
#line 229
  r_name = buffer;
#line 230
  memcpy((void */* __restrict  */)r_name, (void const   */* __restrict  */)hn, l + 1UL);
#line 231
  idx = ((((l + 1UL) + sizeof(void *)) - 1UL) / sizeof(void *)) * sizeof(void *);
#line 234
  r_aliases = buffer + idx;
#line 235
  *((char **)r_aliases) = (char *)((void *)0);
#line 236
  idx += sizeof(char *);
#line 239
  r_addr = buffer + idx;
  }
#line 240
  if (c > 0U) {
#line 241
    i = 0U;
#line 243
    a = addresses;
#line 243
    n = 0U;
    {
#line 243
    while (1) {
      while_continue___0: /* CIL Label */ ;
#line 243
      if (! (n < n_addresses)) {
#line 243
        goto while_break___0;
      }
#line 244
      if (af != (int )a->family) {
#line 245
        goto __Cont;
      }
      {
#line 247
      memcpy((void */* __restrict  */)(r_addr + (size_t )i * ((((alen + sizeof(void *)) - 1UL) / sizeof(void *)) * sizeof(void *))),
             (void const   */* __restrict  */)(a->address), alen);
#line 248
      i ++;
      }
      __Cont: /* CIL Label */ 
#line 243
      a ++;
#line 243
      n ++;
    }
    while_break___0: /* CIL Label */ ;
    }
#line 251
    if (! (i == c)) {
      {
#line 251
      __assert_fail("i == c", "/home/wheatley/newnew/temp/libnss-myhostname-0.3/nss-myhostname.c",
                    251U, "fill_in_hostent");
      }
    }
#line 252
    idx += (size_t )c * ((((alen + sizeof(void *)) - 1UL) / sizeof(void *)) * sizeof(void *));
  } else {
#line 254
    if (af == 2) {
      {
#line 255
      *((uint32_t *)r_addr) = htonl((uint32_t )2130706689);
      }
    } else {
      {
#line 257
      memcpy((void */* __restrict  */)r_addr, (void const   */* __restrict  */)(& in6addr_loopback),
             (size_t )16);
      }
    }
#line 259
    idx += (((alen + sizeof(void *)) - 1UL) / sizeof(void *)) * sizeof(void *);
  }
#line 263
  r_addr_list = buffer + idx;
#line 264
  if (c > 0U) {
#line 265
    i___0 = 0U;
#line 267
    a = addresses;
#line 267
    n = 0U;
    {
#line 267
    while (1) {
      while_continue___1: /* CIL Label */ ;
#line 267
      if (! (n < n_addresses)) {
#line 267
        goto while_break___1;
      }
#line 268
      if (af != (int )a->family) {
#line 269
        goto __Cont___0;
      }
#line 271
      *((char **)r_addr_list + i___0) = r_addr + (size_t )i___0 * ((((alen + sizeof(void *)) - 1UL) / sizeof(void *)) * sizeof(void *));
#line 272
      i___0 ++;
      __Cont___0: /* CIL Label */ 
#line 267
      a ++;
#line 267
      n ++;
    }
    while_break___1: /* CIL Label */ ;
    }
#line 275
    if (! (i___0 == c)) {
      {
#line 275
      __assert_fail("i == c", "/home/wheatley/newnew/temp/libnss-myhostname-0.3/nss-myhostname.c",
                    275U, "fill_in_hostent");
      }
    }
#line 276
    *((char **)r_addr_list + c) = (char *)((void *)0);
#line 277
    idx += (unsigned long )(c + 1U) * sizeof(char *);
  } else {
#line 280
    *((char **)r_addr_list + 0) = r_addr;
#line 281
    *((char **)r_addr_list + 1) = (char *)((void *)0);
#line 282
    idx += 2UL * sizeof(char *);
  }
#line 286
  if (! (idx == ms)) {
    {
#line 286
    __assert_fail("idx == ms", "/home/wheatley/newnew/temp/libnss-myhostname-0.3/nss-myhostname.c",
                  286U, "fill_in_hostent");
    }
  }
#line 288
  result->h_name = r_name;
#line 289
  result->h_aliases = (char **)r_aliases;
#line 290
  result->h_addrtype = af;
#line 291
  result->h_length = (int )alen;
#line 292
  result->h_addr_list = (char **)r_addr_list;
#line 294
  if (ttlp) {
#line 295
    *ttlp = 0;
  }
#line 297
  if (canonp) {
#line 298
    *canonp = r_name;
  }
  {
#line 300
  free((void *)addresses);
  }
#line 302
  return ((enum nss_status )1);
}
}
#line 305
enum nss_status _nss_myhostname_gethostbyname3_r(char const   *name , int af , struct hostent *host ,
                                                 char *buffer , size_t buflen , int *errnop ,
                                                 int *h_errnop , int32_t *ttlp , char **canonp )  __attribute__((__visibility__("default"))) ;
#line 305 "/home/wheatley/newnew/temp/libnss-myhostname-0.3/nss-myhostname.c"
enum nss_status _nss_myhostname_gethostbyname3_r(char const   *name , int af , struct hostent *host ,
                                                 char *buffer , size_t buflen , int *errnop ,
                                                 int *h_errnop , int32_t *ttlp , char **canonp ) 
{ 
  char hn[65] ;
  int *tmp ;
  int tmp___0 ;
  int tmp___1 ;
  enum nss_status tmp___2 ;

  {
#line 316
  if (af == 0) {
#line 317
    af = 2;
  }
#line 319
  if (af != 2) {
#line 319
    if (af != 10) {
#line 320
      *errnop = 97;
#line 321
      *h_errnop = 4;
#line 322
      return ((enum nss_status )-1);
    }
  }
  {
#line 325
  memset((void *)(hn), 0, sizeof(hn));
#line 326
  tmp___0 = gethostname(hn, sizeof(hn) - 1UL);
  }
#line 326
  if (tmp___0 < 0) {
    {
#line 327
    tmp = __errno_location();
#line 327
    *errnop = *tmp;
#line 328
    *h_errnop = 3;
    }
#line 329
    return ((enum nss_status )-1);
  }
  {
#line 332
  tmp___1 = strcasecmp(name, (char const   *)(hn));
  }
#line 332
  if (tmp___1 != 0) {
#line 333
    *errnop = 2;
#line 334
    *h_errnop = 1;
#line 335
    return ((enum nss_status )0);
  }
  {
#line 338
  tmp___2 = fill_in_hostent((char const   *)(hn), af, host, buffer, buflen, errnop,
                            h_errnop, ttlp, canonp);
  }
#line 338
  return (tmp___2);
}
}
#line 341
enum nss_status _nss_myhostname_gethostbyname2_r(char const   *name , int af , struct hostent *host ,
                                                 char *buffer , size_t buflen , int *errnop ,
                                                 int *h_errnop )  __attribute__((__visibility__("default"))) ;
#line 341 "/home/wheatley/newnew/temp/libnss-myhostname-0.3/nss-myhostname.c"
enum nss_status _nss_myhostname_gethostbyname2_r(char const   *name , int af , struct hostent *host ,
                                                 char *buffer , size_t buflen , int *errnop ,
                                                 int *h_errnop ) 
{ 
  enum nss_status tmp ;

  {
  {
#line 348
  tmp = _nss_myhostname_gethostbyname3_r(name, af, host, buffer, buflen, errnop, h_errnop,
                                         (int32_t *)((void *)0), (char **)((void *)0));
  }
#line 348
  return (tmp);
}
}
#line 358
enum nss_status _nss_myhostname_gethostbyname_r(char const   *name , struct hostent *host ,
                                                char *buffer , size_t buflen , int *errnop ,
                                                int *h_errnop )  __attribute__((__visibility__("default"))) ;
#line 358 "/home/wheatley/newnew/temp/libnss-myhostname-0.3/nss-myhostname.c"
enum nss_status _nss_myhostname_gethostbyname_r(char const   *name , struct hostent *host ,
                                                char *buffer , size_t buflen , int *errnop ,
                                                int *h_errnop ) 
{ 
  enum nss_status tmp ;

  {
  {
#line 364
  tmp = _nss_myhostname_gethostbyname3_r(name, 0, host, buffer, buflen, errnop, h_errnop,
                                         (int32_t *)((void *)0), (char **)((void *)0));
  }
#line 364
  return (tmp);
}
}
#line 374
enum nss_status _nss_myhostname_gethostbyaddr2_r(void const   *addr , socklen_t len ,
                                                 int af , struct hostent *host , char *buffer ,
                                                 size_t buflen , int *errnop , int *h_errnop ,
                                                 int32_t *ttlp )  __attribute__((__visibility__("default"))) ;
#line 374 "/home/wheatley/newnew/temp/libnss-myhostname-0.3/nss-myhostname.c"
enum nss_status _nss_myhostname_gethostbyaddr2_r(void const   *addr , socklen_t len ,
                                                 int af , struct hostent *host , char *buffer ,
                                                 size_t buflen , int *errnop , int *h_errnop ,
                                                 int32_t *ttlp ) 
{ 
  char hn[65] ;
  struct address *addresses ;
  struct address *a ;
  unsigned int n_addresses ;
  unsigned int n ;
  size_t tmp ;
  uint32_t tmp___0 ;
  int tmp___1 ;
  size_t tmp___2 ;
  int tmp___3 ;
  int *tmp___4 ;
  int tmp___5 ;
  enum nss_status tmp___6 ;

  {
  {
#line 383
  addresses = (struct address *)((void *)0);
#line 384
  n_addresses = 0U;
#line 386
  tmp = PROTO_ADDRESS_SIZE(af);
  }
#line 386
  if ((size_t )len != tmp) {
#line 387
    *errnop = 22;
#line 388
    *h_errnop = 3;
#line 389
    return ((enum nss_status )-1);
  }
#line 392
  if (af == 2) {
    {
#line 394
    tmp___0 = htonl((uint32_t )2130706689);
    }
#line 394
    if (*((uint32_t *)addr) == tmp___0) {
#line 395
      goto found;
    }
  } else
#line 397
  if (af == 10) {
    {
#line 399
    tmp___1 = memcmp(addr, (void const   *)(& in6addr_loopback), (size_t )16);
    }
#line 399
    if (tmp___1 == 0) {
#line 400
      goto found;
    }
  } else {
#line 403
    *errnop = 97;
#line 404
    *h_errnop = 4;
#line 405
    return ((enum nss_status )-1);
  }
  {
#line 408
  ifconf_acquire_addresses(& addresses, & n_addresses);
#line 410
  a = addresses;
#line 410
  n = 0U;
  }
  {
#line 410
  while (1) {
    while_continue: /* CIL Label */ ;
#line 410
    if (! (n < n_addresses)) {
#line 410
      goto while_break;
    }
#line 411
    if (af != (int )a->family) {
#line 412
      goto __Cont;
    }
    {
#line 414
    tmp___2 = PROTO_ADDRESS_SIZE(af);
#line 414
    tmp___3 = memcmp(addr, (void const   *)(a->address), tmp___2);
    }
#line 414
    if (tmp___3 == 0) {
#line 415
      goto found;
    }
    __Cont: /* CIL Label */ 
#line 410
    n ++;
#line 410
    a ++;
  }
  while_break: /* CIL Label */ ;
  }
  {
#line 418
  *errnop = 2;
#line 419
  *h_errnop = 1;
#line 421
  free((void *)addresses);
  }
#line 422
  return ((enum nss_status )0);
  found: 
  {
#line 425
  free((void *)addresses);
#line 427
  memset((void *)(hn), 0, sizeof(hn));
#line 428
  tmp___5 = gethostname(hn, sizeof(hn) - 1UL);
  }
#line 428
  if (tmp___5 < 0) {
    {
#line 429
    tmp___4 = __errno_location();
#line 429
    *errnop = *tmp___4;
#line 430
    *h_errnop = 3;
    }
#line 432
    return ((enum nss_status )-1);
  }
  {
#line 435
  tmp___6 = fill_in_hostent((char const   *)(hn), af, host, buffer, buflen, errnop,
                            h_errnop, ttlp, (char **)((void *)0));
  }
#line 435
  return (tmp___6);
}
}
#line 439
enum nss_status _nss_myhostname_gethostbyaddr_r(void const   *addr , socklen_t len ,
                                                int af , struct hostent *host , char *buffer ,
                                                size_t buflen , int *errnop , int *h_errnop )  __attribute__((__visibility__("default"))) ;
#line 439 "/home/wheatley/newnew/temp/libnss-myhostname-0.3/nss-myhostname.c"
enum nss_status _nss_myhostname_gethostbyaddr_r(void const   *addr , socklen_t len ,
                                                int af , struct hostent *host , char *buffer ,
                                                size_t buflen , int *errnop , int *h_errnop ) 
{ 
  enum nss_status tmp ;

  {
  {
#line 446
  tmp = _nss_myhostname_gethostbyaddr2_r(addr, len, af, host, buffer, buflen, errnop,
                                         h_errnop, (int32_t *)((void *)0));
  }
#line 446
  return (tmp);
}
}