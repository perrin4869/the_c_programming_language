#include "dirent.h"
#include "syscalls.h"

#include <stddef.h>
#include <string.h>
#include <sys/syscall.h>
#include <sys/types.h>

/* #include <bits/types.h> */
/* #define _DIRENT_H */
/* #include <bits/dirent.h> */

#ifndef DIRSIZ
#define DIRSIZ 14
#endif

struct dirent {
  ino_t d_ino;
  off_t d_off;
  unsigned short d_reclen;
  unsigned char d_type;
  char d_name[DIRSIZ];
};

/*
 * the function from the book doesn't work on linux
 * calling read on a dir file descriptor returns an error
 * the way to read directory contents on linux is via getdents64
 * syscall.
 * this is not a perfectly working version but it gets the job done
 * for demonstration purposes (it compiles and runs).
 */

/* readdir: read directory entries in sequence */
Dirent *readdir(DIR *dp) {
  struct dirent *dirbuf;
  char buf[sizeof(struct dirent)];
  static Dirent d; /* return: portable structure */

  int nread = syscall(SYS_getdents64, dp->fd, buf, sizeof(buf));
  if (nread <= 0)
    return NULL;

  dirbuf = (struct dirent *)buf;

  while (dirbuf->d_ino == 0) {
    /* skip deleted entry */
    int reclen = dirbuf->d_reclen;
    if (reclen >= nread)
      return NULL;
    dirbuf = (struct dirent *)((char *)dirbuf + reclen);
  }

  d.ino = dirbuf->d_ino;
  strncpy(d.name, dirbuf->d_name, DIRSIZ);
  d.name[DIRSIZ] = '\0'; /* Ensure null termination */
  return &d;
}
