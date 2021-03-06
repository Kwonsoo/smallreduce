/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is false */

#line 212 "/usr/lib/gcc/x86_64-linux-gnu/4.8/include/stddef.h"
typedef unsigned long size_t;
#line 124 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned long __dev_t;
#line 125 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned int __uid_t;
#line 126 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned int __gid_t;
#line 127 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned long __ino_t;
#line 129 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned int __mode_t;
#line 130 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned long __nlink_t;
#line 131 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __off_t;
#line 139 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __time_t;
#line 153 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __blksize_t;
#line 158 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __blkcnt_t;
#line 172 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __ssize_t;
#line 175 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __syscall_slong_t;
#line 102 "/usr/include/stdio.h"
typedef __ssize_t ssize_t;
#line 120 "/usr/include/time.h"
struct timespec {
   __time_t tv_sec ;
   __syscall_slong_t tv_nsec ;
};
#line 46 "/usr/include/x86_64-linux-gnu/bits/stat.h"
struct stat {
   __dev_t st_dev ;
   __ino_t st_ino ;
   __nlink_t st_nlink ;
   __mode_t st_mode ;
   __uid_t st_uid ;
   __gid_t st_gid ;
   int __pad0 ;
   __dev_t st_rdev ;
   __off_t st_size ;
   __blksize_t st_blksize ;
   __blkcnt_t st_blocks ;
   struct timespec st_atim ;
   struct timespec st_mtim ;
   struct timespec st_ctim ;
   __syscall_slong_t __glibc_reserved[3] ;
};
#line 22 "/usr/include/x86_64-linux-gnu/bits/dirent.h"
struct dirent {
   __ino_t d_ino ;
   __off_t d_off ;
   unsigned short d_reclen ;
   unsigned char d_type ;
   char d_name[256] ;
};
#line 127 "/usr/include/dirent.h"
struct __dirstream;
#line 127 "/usr/include/dirent.h"
typedef struct __dirstream DIR;
#line 20 "/home/june/repo/benchmarks/collector/temp/smem-1.4/smemcap.c"
struct fileblock;
#line 20
struct fileblock;
#line 21 "/home/june/repo/benchmarks/collector/temp/smem-1.4/smemcap.c"
struct fileblock {
   char data[512] ;
   struct fileblock *next ;
};
#line 364 "/usr/include/stdio.h"
extern  __attribute__((__nothrow__)) int sprintf(char * __restrict  __s , char const   * __restrict  __format 
                                                 , ...) ;
#line 468 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) calloc)(size_t __nmemb ,
                                                                               size_t __size )  __attribute__((__malloc__)) ;
#line 483
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) free)(void *__ptr ) ;
#line 353 "/usr/include/unistd.h"
extern int close(int __fd ) ;
#line 360
extern ssize_t read(int __fd , void *__buf , size_t __nbytes ) ;
#line 366
extern ssize_t write(int __fd , void const   *__buf , size_t __n ) ;
#line 497
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) chdir)(char const   *__path ) ;
#line 209 "/usr/include/x86_64-linux-gnu/sys/stat.h"
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2), __leaf__)) stat)(char const   * __restrict  __file ,
                                                                                             struct stat * __restrict  __buf ) ;
#line 214
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2), __leaf__)) fstat)(int __fd ,
                                                                                            struct stat *__buf ) ;
#line 66 "/usr/include/string.h"
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1), __leaf__)) memset)(void *__s ,
                                                                                               int __c ,
                                                                                               size_t __n ) ;
#line 146 "/usr/include/fcntl.h"
extern int ( __attribute__((__nonnull__(1))) open)(char const   *__file , int __oflag 
                                                   , ...) ;
#line 134 "/usr/include/dirent.h"
extern DIR *( __attribute__((__nonnull__(1))) opendir)(char const   *__name ) ;
#line 162
extern struct dirent *( __attribute__((__nonnull__(1))) readdir)(DIR *__dirp ) ;
#line 26 "/home/june/repo/benchmarks/collector/temp/smem-1.4/smemcap.c"
int writeheader(int destfd , char const   *path , int mode , int uid , int gid , int size ,
                int mtime , int type ) 
{ 
  char header[512] ;
  int i ;
  int sum ;
  ssize_t tmp ;

  {
  {
#line 32
  memset((void *)(header), 0, (size_t )512);
#line 34
  sprintf((char */* __restrict  */)(header), (char const   */* __restrict  */)"%s",
          path);
#line 35
  sprintf((char */* __restrict  */)(header + 100), (char const   */* __restrict  */)"%07o",
          mode & 511);
#line 36
  sprintf((char */* __restrict  */)(header + 108), (char const   */* __restrict  */)"%07o",
          uid);
#line 37
  sprintf((char */* __restrict  */)(header + 116), (char const   */* __restrict  */)"%07o",
          gid);
#line 38
  sprintf((char */* __restrict  */)(header + 124), (char const   */* __restrict  */)"%011o",
          size);
#line 39
  sprintf((char */* __restrict  */)(header + 136), (char const   */* __restrict  */)"%07o",
          mtime);
#line 40
  sprintf((char */* __restrict  */)(header + 148), (char const   */* __restrict  */)"        %1d",
          type);
#line 43
  sum = 0;
#line 43
  i = sum;
  }
  {
#line 43
  while (1) {
    while_continue: /* CIL Label */ ;
#line 43
    if (! (i < 512)) {
#line 43
      goto while_break;
    }
#line 44
    sum += (int )header[i];
#line 43
    i ++;
  }
  while_break: /* CIL Label */ ;
  }
  {
#line 45
  sprintf((char */* __restrict  */)(header + 148), (char const   */* __restrict  */)"%06o",
          sum);
#line 47
  tmp = write(destfd, (void const   *)(header), (size_t )512);
  }
#line 47
  return ((int )tmp);
}
}
#line 50 "/home/june/repo/benchmarks/collector/temp/smem-1.4/smemcap.c"
int archivefile(char const   *path , int destfd ) 
{ 
  struct fileblock *start ;
  struct fileblock *cur ;
  struct fileblock **prev ;
  int fd ;
  int r ;
  int size ;
  struct stat s ;
  void *tmp ;
  ssize_t tmp___0 ;

  {
  {
#line 53
  prev = & start;
#line 54
  size = 0;
#line 58
  fd = open(path, 0);
#line 59
  fstat(fd, & s);
  }
  {
#line 61
  while (1) {
    while_continue: /* CIL Label */ ;
    {
#line 62
    tmp = calloc((size_t )1, sizeof(struct fileblock ));
#line 62
    cur = (struct fileblock *)tmp;
#line 63
    *prev = cur;
#line 64
    prev = & cur->next;
#line 65
    tmp___0 = read(fd, (void *)(cur->data), (size_t )512);
#line 65
    r = (int )tmp___0;
    }
#line 66
    if (r > 0) {
#line 67
      size += r;
    }
#line 61
    if (! (r == 512)) {
#line 61
      goto while_break;
    }
  }
  while_break: /* CIL Label */ ;
  }
  {
#line 70
  close(fd);
#line 73
  writeheader(destfd, path, (int )s.st_mode, (int )s.st_uid, (int )s.st_gid, size,
              (int )s.st_mtim.tv_sec, 0);
#line 77
  cur = start;
  }
  {
#line 77
  while (1) {
    while_continue___0: /* CIL Label */ ;
#line 77
    if (! (size > 0)) {
#line 77
      goto while_break___0;
    }
    {
#line 78
    write(destfd, (void const   *)(cur->data), (size_t )512);
#line 79
    start = cur;
#line 80
    cur = cur->next;
#line 81
    free((void *)start);
#line 77
    size -= 512;
    }
  }
  while_break___0: /* CIL Label */ ;
  }
#line 83
  return (0);
}
}
#line 85 "/home/june/repo/benchmarks/collector/temp/smem-1.4/smemcap.c"
int archivejoin(char const   *sub , char const   *name , int destfd ) 
{ 
  char path[256] ;
  int tmp ;

  {
  {
#line 88
  sprintf((char */* __restrict  */)(path), (char const   */* __restrict  */)"%s/%s",
          sub, name);
#line 89
  tmp = archivefile((char const   *)(path), destfd);
  }
#line 89
  return (tmp);
}
}
#line 92 "/home/june/repo/benchmarks/collector/temp/smem-1.4/smemcap.c"
int main(int argc , char **argv ) 
{ 
  DIR *d ;
  struct dirent *de ;
  struct stat s ;

  {
  {
#line 98
  chdir("/proc");
#line 99
  archivefile("meminfo", 1);
#line 100
  archivefile("version", 1);
#line 102
  d = opendir(".");
  }
  {
#line 103
  while (1) {
    while_continue: /* CIL Label */ ;
    {
#line 103
    de = readdir(d);
    }
#line 103
    if (! de) {
#line 103
      goto while_break;
    }
#line 104
    if ((int )de->d_name[0] >= 48) {
#line 104
      if ((int )de->d_name[0] <= 57) {
        {
#line 105
        stat((char const   */* __restrict  */)(de->d_name), (struct stat */* __restrict  */)(& s));
#line 106
        writeheader(1, (char const   *)(de->d_name), 365, (int )s.st_uid, (int )s.st_gid,
                    0, (int )s.st_mtim.tv_sec, 5);
#line 108
        archivejoin((char const   *)(de->d_name), "smaps", 1);
#line 109
        archivejoin((char const   *)(de->d_name), "cmdline", 1);
#line 110
        archivejoin((char const   *)(de->d_name), "stat", 1);
        }
      }
    }
  }
  while_break: /* CIL Label */ ;
  }
#line 113
  return (0);
}
}
