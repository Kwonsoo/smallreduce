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
#line 132 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __off64_t;
#line 133 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef int __pid_t;
#line 135 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __clock_t;
#line 139 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __time_t;
#line 141 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __suseconds_t;
#line 153 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __blksize_t;
#line 158 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __blkcnt_t;
#line 172 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __ssize_t;
#line 175 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __syscall_slong_t;
#line 44 "/usr/include/stdio.h"
struct _IO_FILE;
#line 44
struct _IO_FILE;
#line 48 "/usr/include/stdio.h"
typedef struct _IO_FILE FILE;
#line 144 "/usr/include/libio.h"
struct _IO_FILE;
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
#line 102 "/usr/include/stdio.h"
typedef __ssize_t ssize_t;
#line 98 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __pid_t pid_t;
#line 75 "/usr/include/time.h"
typedef __time_t time_t;
#line 27 "/usr/include/x86_64-linux-gnu/bits/sigset.h"
struct __anonstruct___sigset_t_13 {
   unsigned long __val[1024UL / (8UL * sizeof(unsigned long ))] ;
};
#line 27 "/usr/include/x86_64-linux-gnu/bits/sigset.h"
typedef struct __anonstruct___sigset_t_13 __sigset_t;
#line 37 "/usr/include/x86_64-linux-gnu/sys/select.h"
typedef __sigset_t sigset_t;
#line 120 "/usr/include/time.h"
struct timespec {
   __time_t tv_sec ;
   __syscall_slong_t tv_nsec ;
};
#line 30 "/usr/include/x86_64-linux-gnu/bits/time.h"
struct timeval {
   __time_t tv_sec ;
   __suseconds_t tv_usec ;
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
#line 53 "/usr/include/mntent.h"
struct mntent {
   char *mnt_fsname ;
   char *mnt_dir ;
   char *mnt_type ;
   char *mnt_opts ;
   int mnt_freq ;
   int mnt_passno ;
};
#line 104 "/usr/include/getopt.h"
struct option {
   char const   *name ;
   int has_arg ;
   int *flag ;
   int val ;
};
#line 32 "/usr/include/x86_64-linux-gnu/bits/siginfo.h"
union sigval {
   int sival_int ;
   void *sival_ptr ;
};
#line 32 "/usr/include/x86_64-linux-gnu/bits/siginfo.h"
typedef union sigval sigval_t;
#line 58 "/usr/include/x86_64-linux-gnu/bits/siginfo.h"
typedef __clock_t __sigchld_clock_t;
#line 62 "/usr/include/x86_64-linux-gnu/bits/siginfo.h"
struct __anonstruct__kill_31 {
   __pid_t si_pid ;
   __uid_t si_uid ;
};
#line 62 "/usr/include/x86_64-linux-gnu/bits/siginfo.h"
struct __anonstruct__timer_32 {
   int si_tid ;
   int si_overrun ;
   sigval_t si_sigval ;
};
#line 62 "/usr/include/x86_64-linux-gnu/bits/siginfo.h"
struct __anonstruct__rt_33 {
   __pid_t si_pid ;
   __uid_t si_uid ;
   sigval_t si_sigval ;
};
#line 62 "/usr/include/x86_64-linux-gnu/bits/siginfo.h"
struct __anonstruct__sigchld_34 {
   __pid_t si_pid ;
   __uid_t si_uid ;
   int si_status ;
   __sigchld_clock_t si_utime ;
   __sigchld_clock_t si_stime ;
};
#line 62 "/usr/include/x86_64-linux-gnu/bits/siginfo.h"
struct __anonstruct__sigfault_35 {
   void *si_addr ;
   short si_addr_lsb ;
};
#line 62 "/usr/include/x86_64-linux-gnu/bits/siginfo.h"
struct __anonstruct__sigpoll_36 {
   long si_band ;
   int si_fd ;
};
#line 62 "/usr/include/x86_64-linux-gnu/bits/siginfo.h"
struct __anonstruct__sigsys_37 {
   void *_call_addr ;
   int _syscall ;
   unsigned int _arch ;
};
#line 62 "/usr/include/x86_64-linux-gnu/bits/siginfo.h"
union __anonunion__sifields_30 {
   int _pad[128UL / sizeof(int ) - 4UL] ;
   struct __anonstruct__kill_31 _kill ;
   struct __anonstruct__timer_32 _timer ;
   struct __anonstruct__rt_33 _rt ;
   struct __anonstruct__sigchld_34 _sigchld ;
   struct __anonstruct__sigfault_35 _sigfault ;
   struct __anonstruct__sigpoll_36 _sigpoll ;
   struct __anonstruct__sigsys_37 _sigsys ;
};
#line 62 "/usr/include/x86_64-linux-gnu/bits/siginfo.h"
struct __anonstruct_siginfo_t_29 {
   int si_signo ;
   int si_errno ;
   int si_code ;
   union __anonunion__sifields_30 _sifields ;
};
#line 62 "/usr/include/x86_64-linux-gnu/bits/siginfo.h"
typedef struct __anonstruct_siginfo_t_29 siginfo_t;
#line 24 "/usr/include/x86_64-linux-gnu/bits/sigaction.h"
union __anonunion___sigaction_handler_49 {
   void (*sa_handler)(int  ) ;
   void (*sa_sigaction)(int  , siginfo_t * , void * ) ;
};
#line 24 "/usr/include/x86_64-linux-gnu/bits/sigaction.h"
struct sigaction {
   union __anonunion___sigaction_handler_49 __sigaction_handler ;
   __sigset_t sa_mask ;
   int sa_flags ;
   void (*sa_restorer)(void) ;
};
#line 133 "/usr/include/time.h"
struct tm {
   int tm_sec ;
   int tm_min ;
   int tm_hour ;
   int tm_mday ;
   int tm_mon ;
   int tm_year ;
   int tm_wday ;
   int tm_yday ;
   int tm_isdst ;
   long tm_gmtoff ;
   char const   *tm_zone ;
};
#line 55 "/usr/include/stdint.h"
typedef unsigned long uint64_t;
#line 20 "/usr/include/asm-generic/int-ll64.h"
typedef unsigned char __u8;
#line 23 "/usr/include/asm-generic/int-ll64.h"
typedef unsigned short __u16;
#line 25 "/usr/include/asm-generic/int-ll64.h"
typedef int __s32;
#line 26 "/usr/include/asm-generic/int-ll64.h"
typedef unsigned int __u32;
#line 30 "/usr/include/asm-generic/int-ll64.h"
typedef unsigned long long __u64;
#line 84 "/usr/include/linux/fanotify.h"
struct fanotify_event_metadata {
   __u32 event_len ;
   __u8 vers ;
   __u8 reserved ;
   __u16 metadata_len ;
   __u64 __attribute__((__aligned__(8)))  mask ;
   __s32 fd ;
   __s32 pid ;
};
#line 55 "/usr/include/x86_64-linux-gnu/sys/time.h"
struct timezone {
   int tz_minuteswest ;
   int tz_dsttime ;
};
#line 61 "/usr/include/x86_64-linux-gnu/sys/time.h"
typedef struct timezone * __restrict  __timezone_ptr_t;
#line 169 "/usr/include/stdio.h"
extern struct _IO_FILE *stdout ;
#line 170
extern struct _IO_FILE *stderr ;
#line 242
extern int fflush(FILE *__stream ) ;
#line 356
extern int fprintf(FILE * __restrict  __stream , char const   * __restrict  __format 
                   , ...) ;
#line 362
extern int printf(char const   * __restrict  __format  , ...) ;
#line 386
extern  __attribute__((__nothrow__)) int ( /* format attribute */  snprintf)(char * __restrict  __s ,
                                                                             size_t __maxlen ,
                                                                             char const   * __restrict  __format 
                                                                             , ...) ;
#line 689
extern int fputs(char const   * __restrict  __s , FILE * __restrict  __stream ) ;
#line 695
extern int puts(char const   *__s ) ;
#line 846
extern void perror(char const   *__s ) ;
#line 183 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) long ( __attribute__((__nonnull__(1), __leaf__)) strtol)(char const   * __restrict  __nptr ,
                                                                                              char ** __restrict  __endptr ,
                                                                                              int __base ) ;
#line 27 "/usr/include/x86_64-linux-gnu/sys/sysmacros.h"
extern  __attribute__((__nothrow__)) unsigned int ( __attribute__((__leaf__)) gnu_dev_major)(unsigned long long __dev )  __attribute__((__const__)) ;
#line 30
extern  __attribute__((__nothrow__)) unsigned int ( __attribute__((__leaf__)) gnu_dev_minor)(unsigned long long __dev )  __attribute__((__const__)) ;
#line 503 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) posix_memalign)(void **__memptr ,
                                                                                                     size_t __alignment ,
                                                                                                     size_t __size ) ;
#line 543
extern  __attribute__((__nothrow__, __noreturn__)) void ( __attribute__((__leaf__)) exit)(int __status ) ;
#line 287 "/usr/include/unistd.h"
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) access)(char const   *__name ,
                                                                                             int __type ) ;
#line 353
extern int close(int __fd ) ;
#line 360
extern ssize_t read(int __fd , void *__buf , size_t __nbytes ) ;
#line 432
extern  __attribute__((__nothrow__)) unsigned int ( __attribute__((__leaf__)) alarm)(unsigned int __seconds ) ;
#line 534
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) dup2)(int __fd ,
                                                                           int __fd2 ) ;
#line 603
extern  __attribute__((__noreturn__)) void _exit(int __status ) ;
#line 628
extern  __attribute__((__nothrow__)) __pid_t ( __attribute__((__leaf__)) getpid)(void) ;
#line 809
extern  __attribute__((__nothrow__)) ssize_t ( __attribute__((__nonnull__(1,2), __leaf__)) readlink)(char const   * __restrict  __path ,
                                                                                                     char * __restrict  __buf ,
                                                                                                     size_t __len ) ;
#line 57 "/usr/include/getopt.h"
extern char *optarg ;
#line 66 "/usr/include/string.h"
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1), __leaf__)) memset)(void *__s ,
                                                                                               int __c ,
                                                                                               size_t __n ) ;
#line 129
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1,2), __leaf__)) strcpy)(char * __restrict  __dest ,
                                                                                                 char const   * __restrict  __src ) ;
#line 176
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1), __leaf__)) strdup)(char const   *__s )  __attribute__((__malloc__)) ;
#line 236
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1), __leaf__)) strchr)(char const   *__s ,
                                                                                               int __c )  __attribute__((__pure__)) ;
#line 413
extern  __attribute__((__nothrow__)) char *( __attribute__((__leaf__)) strerror)(int __errnum ) ;
#line 146 "/usr/include/fcntl.h"
extern int ( __attribute__((__nonnull__(1))) open)(char const   *__file , int __oflag 
                                                   , ...) ;
#line 66 "/usr/include/mntent.h"
extern  __attribute__((__nothrow__)) FILE *( __attribute__((__leaf__)) setmntent)(char const   *__file ,
                                                                                  char const   *__mode ) ;
#line 71
extern  __attribute__((__nothrow__)) struct mntent *( __attribute__((__leaf__)) getmntent)(FILE *__stream ) ;
#line 87
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) endmntent)(FILE *__stream ) ;
#line 173 "/usr/include/getopt.h"
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) getopt_long)(int ___argc ,
                                                                                  char * const  *___argv ,
                                                                                  char const   *__shortopts ,
                                                                                  struct option  const  *__longopts ,
                                                                                  int *__longind ) ;
#line 50 "/usr/include/x86_64-linux-gnu/bits/errno.h"
extern  __attribute__((__nothrow__)) int *( __attribute__((__leaf__)) __errno_location)(void)  __attribute__((__const__)) ;
#line 215 "/usr/include/signal.h"
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) sigemptyset)(sigset_t *__set ) ;
#line 259
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) sigaction)(int __sig ,
                                                                                struct sigaction  const  * __restrict  __act ,
                                                                                struct sigaction * __restrict  __oact ) ;
#line 205 "/usr/include/time.h"
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__leaf__)) strftime)(char * __restrict  __s ,
                                                                                  size_t __maxsize ,
                                                                                  char const   * __restrict  __format ,
                                                                                  struct tm  const  * __restrict  __tp ) ;
#line 243
extern  __attribute__((__nothrow__)) struct tm *( __attribute__((__leaf__)) localtime)(time_t const   *__timer ) ;
#line 214 "/usr/include/x86_64-linux-gnu/sys/stat.h"
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2), __leaf__)) fstat)(int __fd ,
                                                                                            struct stat *__buf ) ;
#line 28 "/usr/include/x86_64-linux-gnu/sys/fanotify.h"
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) fanotify_init)(unsigned int __flags ,
                                                                                    unsigned int __event_f_flags ) ;
#line 32
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) fanotify_mark)(int __fanotify_fd ,
                                                                                    unsigned int __flags ,
                                                                                    uint64_t __mask ,
                                                                                    int __dfd ,
                                                                                    char const   *__pathname ) ;
#line 71 "/usr/include/x86_64-linux-gnu/sys/time.h"
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) gettimeofday)(struct timeval * __restrict  __tv ,
                                                                                                   __timezone_ptr_t __tz ) ;
#line 37 "/home/june/repo/benchmarks/collector/temp/fatrace-0.6/fatrace.c"
static char *option_output  =    (char *)((void *)0);
#line 38 "/home/june/repo/benchmarks/collector/temp/fatrace-0.6/fatrace.c"
static long option_timeout  =    -1L;
#line 39 "/home/june/repo/benchmarks/collector/temp/fatrace-0.6/fatrace.c"
static int option_current_mount  =    0;
#line 40 "/home/june/repo/benchmarks/collector/temp/fatrace-0.6/fatrace.c"
static int option_timestamp  =    0;
#line 41 "/home/june/repo/benchmarks/collector/temp/fatrace-0.6/fatrace.c"
static pid_t ignored_pids[1024]  ;
#line 42 "/home/june/repo/benchmarks/collector/temp/fatrace-0.6/fatrace.c"
static unsigned int ignored_pids_len  =    0U;
#line 45 "/home/june/repo/benchmarks/collector/temp/fatrace-0.6/fatrace.c"
static int volatile   running  =    (int volatile   )1;
#line 46 "/home/june/repo/benchmarks/collector/temp/fatrace-0.6/fatrace.c"
static int volatile   signaled  =    (int volatile   )0;
#line 58 "/home/june/repo/benchmarks/collector/temp/fatrace-0.6/fatrace.c"
static char buffer[10]  ;
#line 55 "/home/june/repo/benchmarks/collector/temp/fatrace-0.6/fatrace.c"
static char const   *mask2str(uint64_t mask ) 
{ 
  int offset ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;

  {
#line 59
  offset = 0;
#line 61
  if (mask & 1UL) {
#line 62
    tmp = offset;
#line 62
    offset ++;
#line 62
    buffer[tmp] = (char )'R';
  }
#line 63
  if (mask & 8UL) {
#line 64
    tmp___0 = offset;
#line 64
    offset ++;
#line 64
    buffer[tmp___0] = (char )'C';
  } else
#line 63
  if (mask & 16UL) {
#line 64
    tmp___0 = offset;
#line 64
    offset ++;
#line 64
    buffer[tmp___0] = (char )'C';
  }
#line 65
  if (mask & 2UL) {
#line 66
    tmp___1 = offset;
#line 66
    offset ++;
#line 66
    buffer[tmp___1] = (char )'W';
  } else
#line 65
  if (mask & 8UL) {
#line 66
    tmp___1 = offset;
#line 66
    offset ++;
#line 66
    buffer[tmp___1] = (char )'W';
  }
#line 67
  if (mask & 32UL) {
#line 68
    tmp___2 = offset;
#line 68
    offset ++;
#line 68
    buffer[tmp___2] = (char )'O';
  }
#line 69
  buffer[offset] = (char )'\000';
#line 71
  return ((char const   *)(buffer));
}
}
#line 85 "/home/june/repo/benchmarks/collector/temp/fatrace-0.6/fatrace.c"
static char printbuf[100]  ;
#line 86 "/home/june/repo/benchmarks/collector/temp/fatrace-0.6/fatrace.c"
static char procname[100]  ;
#line 87 "/home/june/repo/benchmarks/collector/temp/fatrace-0.6/fatrace.c"
static char pathname[4096]  ;
#line 79 "/home/june/repo/benchmarks/collector/temp/fatrace-0.6/fatrace.c"
static void print_event(struct fanotify_event_metadata  const  *data , struct timeval  const  *event_time ) 
{ 
  int fd ;
  ssize_t len ;
  struct stat st ;
  int tmp ;
  unsigned int tmp___0 ;
  unsigned int tmp___1 ;
  struct tm *tmp___2 ;
  char const   *tmp___3 ;

  {
  {
#line 91
  snprintf((char */* __restrict  */)(printbuf), sizeof(printbuf), (char const   */* __restrict  */)"/proc/%i/comm",
           data->pid);
#line 92
  len = (ssize_t )0;
#line 93
  fd = open((char const   *)(printbuf), 0);
  }
#line 94
  if (fd >= 0) {
    {
#line 95
    len = read(fd, (void *)(procname), sizeof(procname));
    }
    {
#line 96
    while (1) {
      while_continue: /* CIL Label */ ;
#line 96
      if (len > 0L) {
#line 96
        if (! ((int )procname[len - 1L] == 10)) {
#line 96
          goto while_break;
        }
      } else {
#line 96
        goto while_break;
      }
#line 97
      len --;
    }
    while_break: /* CIL Label */ ;
    }
  }
#line 100
  if (len > 0L) {
#line 101
    procname[len] = (char )'\000';
  } else {
    {
#line 103
    strcpy((char */* __restrict  */)(procname), (char const   */* __restrict  */)"unknown");
    }
  }
#line 105
  if (fd >= 0) {
    {
#line 106
    close(fd);
    }
  }
  {
#line 109
  snprintf((char */* __restrict  */)(printbuf), sizeof(printbuf), (char const   */* __restrict  */)"/proc/self/fd/%i",
           data->fd);
#line 110
  len = readlink((char const   */* __restrict  */)(printbuf), (char */* __restrict  */)(pathname),
                 sizeof(pathname));
  }
#line 111
  if (len < 0L) {
    {
#line 113
    tmp = fstat((int )data->fd, & st);
    }
#line 113
    if (tmp < 0) {
      {
#line 114
      perror("stat");
#line 115
      exit(1);
      }
    }
    {
#line 117
    tmp___0 = gnu_dev_minor((unsigned long long )st.st_dev);
#line 117
    tmp___1 = gnu_dev_major((unsigned long long )st.st_dev);
#line 117
    snprintf((char */* __restrict  */)(pathname), sizeof(pathname), (char const   */* __restrict  */)"device %i:%i inode %ld\n",
             tmp___1, tmp___0, st.st_ino);
    }
  } else {
#line 119
    pathname[len] = (char )'\000';
  }
#line 123
  if (option_timestamp == 1) {
    {
#line 124
    tmp___2 = localtime(& event_time->tv_sec);
#line 124
    strftime((char */* __restrict  */)(printbuf), sizeof(printbuf), (char const   */* __restrict  */)"%H:%M:%S",
             (struct tm  const  */* __restrict  */)tmp___2);
#line 125
    printf((char const   */* __restrict  */)"%s.%06li ", printbuf, event_time->tv_usec);
    }
  } else
#line 126
  if (option_timestamp == 2) {
    {
#line 127
    printf((char const   */* __restrict  */)"%li.%06li ", event_time->tv_sec, event_time->tv_usec);
    }
  }
  {
#line 129
  tmp___3 = mask2str((uint64_t )data->mask);
#line 129
  printf((char const   */* __restrict  */)"%s(%i): %s %s\n", procname, data->pid,
         tmp___3, pathname);
  }
#line 130
  return;
}
}
#line 140 "/home/june/repo/benchmarks/collector/temp/fatrace-0.6/fatrace.c"
static void setup_fanotify(int fan_fd ) 
{ 
  int res ;
  FILE *mounts ;
  struct mntent *mount ;
  int *tmp ;
  char *tmp___0 ;
  int tmp___1 ;
  char *tmp___2 ;
  int *tmp___3 ;
  char *tmp___4 ;

  {
#line 147
  if (option_current_mount) {
    {
#line 148
    res = fanotify_mark(fan_fd, 17U, (uint64_t )1207959611, -100, ".");
    }
#line 151
    if (res < 0) {
      {
#line 152
      tmp = __errno_location();
#line 152
      tmp___0 = strerror(*tmp);
#line 152
      fprintf((FILE */* __restrict  */)stderr, (char const   */* __restrict  */)"Failed to add watch for current directory: %s\n",
              tmp___0);
#line 153
      exit(1);
      }
    }
#line 156
    return;
  }
  {
#line 160
  mounts = setmntent("/proc/self/mounts", "r");
  }
#line 161
  if ((unsigned long )mounts == (unsigned long )((void *)0)) {
    {
#line 162
    perror("setmntent");
#line 163
    exit(1);
    }
  }
  {
#line 166
  while (1) {
    while_continue: /* CIL Label */ ;
    {
#line 166
    mount = getmntent(mounts);
    }
#line 166
    if (! ((unsigned long )mount != (unsigned long )((void *)0))) {
#line 166
      goto while_break;
    }
#line 170
    if ((unsigned long )mount->mnt_fsname == (unsigned long )((void *)0)) {
#line 173
      goto while_continue;
    } else {
      {
#line 170
      tmp___1 = access((char const   *)mount->mnt_fsname, 0);
      }
#line 170
      if (tmp___1 != 0) {
#line 173
        goto while_continue;
      } else {
        {
#line 170
        tmp___2 = strchr((char const   *)mount->mnt_fsname, '/');
        }
#line 170
        if ((unsigned long )tmp___2 == (unsigned long )((void *)0)) {
#line 173
          goto while_continue;
        }
      }
    }
    {
#line 177
    res = fanotify_mark(fan_fd, 17U, (uint64_t )1207959611, -100, (char const   *)mount->mnt_dir);
    }
#line 180
    if (res < 0) {
      {
#line 181
      tmp___3 = __errno_location();
#line 181
      tmp___4 = strerror(*tmp___3);
#line 181
      fprintf((FILE */* __restrict  */)stderr, (char const   */* __restrict  */)"Failed to add watch for %s mount %s: %s\n",
              mount->mnt_type, mount->mnt_dir, tmp___4);
      }
    }
  }
  while_break: /* CIL Label */ ;
  }
  {
#line 186
  endmntent(mounts);
  }
#line 187
  return;
}
}
#line 194 "/home/june/repo/benchmarks/collector/temp/fatrace-0.6/fatrace.c"
static void help(void) 
{ 


  {
  {
#line 197
  puts("Usage: fatrace [options...] \n\nOptions:\n  -c, --current-mount\t\tOnly record events on partition/mount of current directory.\n  -o FILE, --output=FILE\tWrite events to a file instead of standard output.\n  -s SECONDS, --seconds=SECONDS\tStop after the given number of seconds.\n  -t, --timestamp\t\tAdd timestamp to events. Give twice for seconds since the epoch.\n  -p PID, --ignore-pid PID\tIgnore events for this process ID. Can be specified multiple times.\n  -h, --help\t\t\tShow help.");
  }
#line 206
  return;
}
}
#line 220
static void parse_args(int argc , char **argv ) ;
#line 220 "/home/june/repo/benchmarks/collector/temp/fatrace-0.6/fatrace.c"
static struct option long_options[7]  = {      {"current-mount", 0, (int *)0, 'c'}, 
        {"output", 1, (int *)0, 'o'}, 
        {"seconds", 1, (int *)0, 's'}, 
        {"timestamp", 0, (int *)0, 't'}, 
        {"ignore-pid", 1, (int *)0, 'p'}, 
        {"help", 0, (int *)0, 'h'}, 
        {(char const   *)0, 0, (int *)0, 0}};
#line 213 "/home/june/repo/benchmarks/collector/temp/fatrace-0.6/fatrace.c"
static void parse_args(int argc , char **argv ) 
{ 
  int c ;
  long pid ;
  char *endptr ;
  unsigned int tmp ;

  {
  {
#line 230
  while (1) {
    while_continue: /* CIL Label */ ;
    {
#line 231
    c = getopt_long(argc, (char * const  *)argv, "co:s:tp:h", (struct option  const  *)(long_options),
                    (int *)((void *)0));
    }
#line 233
    if (c == -1) {
#line 234
      goto while_break;
    }
    {
#line 237
    if (c == 99) {
#line 237
      goto case_99;
    }
#line 241
    if (c == 111) {
#line 241
      goto case_111;
    }
#line 245
    if (c == 115) {
#line 245
      goto case_115;
    }
#line 253
    if (c == 112) {
#line 253
      goto case_112;
    }
#line 267
    if (c == 116) {
#line 267
      goto case_116;
    }
#line 274
    if (c == 104) {
#line 274
      goto case_104;
    }
#line 278
    if (c == 63) {
#line 278
      goto case_63;
    }
#line 282
    goto switch_default;
    case_99: /* CIL Label */ 
#line 238
    option_current_mount = 1;
#line 239
    goto switch_break;
    case_111: /* CIL Label */ 
    {
#line 242
    option_output = strdup((char const   *)optarg);
    }
#line 243
    goto switch_break;
    case_115: /* CIL Label */ 
    {
#line 246
    option_timeout = strtol((char const   */* __restrict  */)optarg, (char **/* __restrict  */)(& endptr),
                            10);
    }
#line 247
    if ((int )*endptr != 0) {
      {
#line 248
      fputs((char const   */* __restrict  */)"Error: Invalid number of seconds\n",
            (FILE */* __restrict  */)stderr);
#line 249
      exit(1);
      }
    } else
#line 247
    if (option_timeout <= 0L) {
      {
#line 248
      fputs((char const   */* __restrict  */)"Error: Invalid number of seconds\n",
            (FILE */* __restrict  */)stderr);
#line 249
      exit(1);
      }
    }
#line 251
    goto switch_break;
    case_112: /* CIL Label */ 
    {
#line 254
    pid = strtol((char const   */* __restrict  */)optarg, (char **/* __restrict  */)(& endptr),
                 10);
    }
#line 255
    if ((int )*endptr != 0) {
      {
#line 256
      fputs((char const   */* __restrict  */)"Error: Invalid PID\n", (FILE */* __restrict  */)stderr);
#line 257
      exit(1);
      }
    } else
#line 255
    if (pid <= 0L) {
      {
#line 256
      fputs((char const   */* __restrict  */)"Error: Invalid PID\n", (FILE */* __restrict  */)stderr);
#line 257
      exit(1);
      }
    }
#line 259
    if ((unsigned long )ignored_pids_len < sizeof(ignored_pids)) {
#line 260
      tmp = ignored_pids_len;
#line 260
      ignored_pids_len ++;
#line 260
      ignored_pids[tmp] = (pid_t )pid;
    } else {
      {
#line 262
      fputs((char const   */* __restrict  */)"Error: Too many ignored PIDs\n", (FILE */* __restrict  */)stderr);
#line 263
      exit(1);
      }
    }
#line 265
    goto switch_break;
    case_116: /* CIL Label */ 
#line 268
    option_timestamp ++;
#line 268
    if (option_timestamp > 2) {
      {
#line 269
      fputs((char const   */* __restrict  */)"Error: --timestamp option can be given at most two times\n",
            (FILE */* __restrict  */)stderr);
#line 270
      exit(1);
      }
    }
#line 272
    goto switch_break;
    case_104: /* CIL Label */ 
    {
#line 275
    help();
#line 276
    exit(0);
    }
    case_63: /* CIL Label */ 
    {
#line 280
    exit(1);
    }
    switch_default: /* CIL Label */ 
    {
#line 283
    fprintf((FILE */* __restrict  */)stderr, (char const   */* __restrict  */)"Internal error: unexpected option \'%c\'\n",
            c);
#line 284
    exit(1);
    }
    switch_break: /* CIL Label */ ;
    }
  }
  while_break: /* CIL Label */ ;
  }
#line 287
  return;
}
}
#line 296 "/home/june/repo/benchmarks/collector/temp/fatrace-0.6/fatrace.c"
static int show_pid(pid_t pid ) 
{ 
  unsigned int i ;

  {
#line 300
  i = 0U;
  {
#line 300
  while (1) {
    while_continue: /* CIL Label */ ;
#line 300
    if (! (i < ignored_pids_len)) {
#line 300
      goto while_break;
    }
#line 301
    if (pid == ignored_pids[i]) {
#line 302
      return (0);
    }
#line 300
    i ++;
  }
  while_break: /* CIL Label */ ;
  }
#line 304
  return (1);
}
}
#line 307 "/home/june/repo/benchmarks/collector/temp/fatrace-0.6/fatrace.c"
static void signal_handler(int signal___0 ) 
{ 


  {
#line 313
  running = (int volatile   )0;
#line 314
  signaled += (int volatile   )1;
#line 317
  if (signaled > (int volatile   )1) {
    {
#line 318
    _exit(1);
    }
  }
#line 319
  return;
}
}
#line 321 "/home/june/repo/benchmarks/collector/temp/fatrace-0.6/fatrace.c"
int main(int argc , char **argv ) 
{ 
  int fan_fd ;
  int res ;
  int err ;
  void *buffer___0 ;
  struct fanotify_event_metadata *data ;
  struct sigaction sa ;
  struct timeval event_time ;
  unsigned int tmp ;
  int *tmp___0 ;
  char *tmp___1 ;
  char *tmp___2 ;
  int fd ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  ssize_t tmp___6 ;
  int *tmp___7 ;
  int tmp___8 ;
  int tmp___9 ;

  {
  {
#line 333
  tmp = ignored_pids_len;
#line 333
  ignored_pids_len ++;
#line 333
  ignored_pids[tmp] = getpid();
#line 335
  parse_args(argc, argv);
#line 337
  fan_fd = fanotify_init(0U, 0U);
  }
#line 338
  if (fan_fd < 0) {
    {
#line 339
    tmp___0 = __errno_location();
#line 339
    err = *tmp___0;
#line 340
    tmp___1 = strerror(err);
#line 340
    fprintf((FILE */* __restrict  */)stderr, (char const   */* __restrict  */)"Cannot initialize fanotify: %s\n",
            tmp___1);
    }
#line 341
    if (err == 1) {
      {
#line 342
      fputs((char const   */* __restrict  */)"You need to run this program as root.\n",
            (FILE */* __restrict  */)stderr);
      }
    }
    {
#line 343
    exit(1);
    }
  }
  {
#line 346
  setup_fanotify(fan_fd);
#line 349
  buffer___0 = (void *)0;
#line 350
  err = posix_memalign(& buffer___0, (size_t )4096, (size_t )4096);
  }
#line 351
  if (err != 0) {
    {
#line 352
    tmp___2 = strerror(err);
#line 352
    fprintf((FILE */* __restrict  */)stderr, (char const   */* __restrict  */)"Failed to allocate buffer: %s\n",
            tmp___2);
#line 353
    exit(1);
    }
  } else
#line 351
  if ((unsigned long )buffer___0 == (unsigned long )((void *)0)) {
    {
#line 352
    tmp___2 = strerror(err);
#line 352
    fprintf((FILE */* __restrict  */)stderr, (char const   */* __restrict  */)"Failed to allocate buffer: %s\n",
            tmp___2);
#line 353
    exit(1);
    }
  }
#line 357
  if (option_output) {
    {
#line 358
    tmp___3 = open((char const   *)option_output, 193, 438);
#line 358
    fd = tmp___3;
    }
#line 359
    if (fd < 0) {
      {
#line 360
      perror("Failed to open output file");
#line 361
      exit(1);
      }
    }
    {
#line 363
    fflush(stdout);
#line 364
    dup2(fd, 1);
#line 365
    close(fd);
    }
  }
  {
#line 369
  sa.__sigaction_handler.sa_handler = & signal_handler;
#line 370
  sigemptyset(& sa.sa_mask);
#line 371
  sa.sa_flags = 0;
#line 372
  tmp___4 = sigaction(2, (struct sigaction  const  */* __restrict  */)(& sa), (struct sigaction */* __restrict  */)((void *)0));
  }
#line 372
  if (tmp___4 < 0) {
    {
#line 373
    perror("sigaction");
#line 374
    exit(1);
    }
  }
#line 378
  if (option_timeout > 0L) {
    {
#line 379
    sa.__sigaction_handler.sa_handler = & signal_handler;
#line 380
    sigemptyset(& sa.sa_mask);
#line 381
    sa.sa_flags = 0;
#line 382
    tmp___5 = sigaction(14, (struct sigaction  const  */* __restrict  */)(& sa), (struct sigaction */* __restrict  */)((void *)0));
    }
#line 382
    if (tmp___5 < 0) {
      {
#line 383
      perror("sigaction");
#line 384
      exit(1);
      }
    }
    {
#line 386
    alarm((unsigned int )option_timeout);
    }
  }
#line 390
  if (! option_timestamp) {
    {
#line 391
    memset((void *)(& event_time), 0, sizeof(struct timeval ));
    }
  }
  {
#line 395
  while (1) {
    while_continue: /* CIL Label */ ;
#line 395
    if (! running) {
#line 395
      goto while_break;
    }
    {
#line 396
    tmp___6 = read(fan_fd, buffer___0, (size_t )4096);
#line 396
    res = (int )tmp___6;
    }
#line 397
    if (res == 0) {
      {
#line 398
      fprintf((FILE */* __restrict  */)stderr, (char const   */* __restrict  */)"No more fanotify event (EOF)\n");
      }
#line 399
      goto while_break;
    }
#line 401
    if (res < 0) {
      {
#line 402
      tmp___7 = __errno_location();
      }
#line 402
      if (*tmp___7 == 4) {
#line 403
        goto while_continue;
      }
      {
#line 404
      perror("read");
#line 405
      exit(1);
      }
    }
#line 409
    if (option_timestamp) {
      {
#line 410
      tmp___8 = gettimeofday((struct timeval */* __restrict  */)(& event_time), (__timezone_ptr_t )((void *)0));
      }
#line 410
      if (tmp___8 < 0) {
        {
#line 411
        perror("gettimeofday");
#line 412
        exit(1);
        }
      }
    }
#line 416
    data = (struct fanotify_event_metadata *)buffer___0;
    {
#line 417
    while (1) {
      while_continue___0: /* CIL Label */ ;
#line 417
      if ((long )res >= (long )sizeof(struct fanotify_event_metadata )) {
#line 417
        if ((long )data->event_len >= (long )sizeof(struct fanotify_event_metadata )) {
#line 417
          if (! ((long )data->event_len <= (long )res)) {
#line 417
            goto while_break___0;
          }
        } else {
#line 417
          goto while_break___0;
        }
      } else {
#line 417
        goto while_break___0;
      }
      {
#line 418
      tmp___9 = show_pid(data->pid);
      }
#line 418
      if (tmp___9) {
        {
#line 419
        print_event((struct fanotify_event_metadata  const  *)data, (struct timeval  const  *)(& event_time));
        }
      }
      {
#line 420
      close(data->fd);
#line 421
      res = (int )((__u32 )res - data->event_len);
#line 421
      data = (struct fanotify_event_metadata *)((char *)data + data->event_len);
      }
    }
    while_break___0: /* CIL Label */ ;
    }
  }
  while_break: /* CIL Label */ ;
  }
#line 425
  return (0);
}
}
