#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#include "syscalls.h"

void error(char *fmt, ...);

/* cat: concatenate files - read / write / open / close */
main(int argc, char *argv[]) {
  int fd;
  void filecopy(int, int);

  if (argc == 1) /* no args; copy standard input */
    filecopy(0, 1);
  else
    while (--argc > 0)
      if ((fd = open(*++argv, O_RDONLY, 0)) == -1) {
        error("%s: can't open %s\n", *argv);
      } else {
        filecopy(fd, 1);
        close(fd);
      }
  exit(0);
}

/* filecopy: copy file ifp to file ofp */
void filecopy(int ifd, int ofd) {
  int n;
  char buf[BUFSIZ];

  while ((n = read(ifd, buf, BUFSIZ)) > 0)
    if (write(ofd, buf, n) != n)
      error("cat: write error");
}
