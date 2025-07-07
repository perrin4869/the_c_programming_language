#include <fcntl.h> /* flags for read and write */
#include <stdio.h>
#include <string.h>
#define __USE_MISC
#include <sys/stat.h>  /* structure returned by stat */
#include <sys/types.h> /* typedefs */

#include "dirent.h"
#include "syscalls.h"

void fsize(char *);

/* print file sizes */
main(int argc, char **argv) {
  if (argc == 1) /* default: current directory */
    fsize(".");
  else
    while (--argc > 0)
      fsize(*++argv);
  return 0;
}

int stat(const char *, struct stat *);
void dirwalk(char *, void (*fcn)(char *));

/* fsize: print size of file "name" */
void fsize(char *name) {
  struct stat stbuf;

  if (stat(name, &stbuf) == -1) {
    fprintf(stderr, "fsize: can't access %s\n", name);
    return;
  }
  if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
    dirwalk(name, fsize);
  printf("%8ld %s\n", stbuf.st_size, name);
}
