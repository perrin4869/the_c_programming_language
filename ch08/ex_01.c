#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#include "syscalls.h"

/* cat: concatenate files, version 2 */
main(int argc, char *argv[]) {
  int fd;
  void filecopy(int, int);
  char *prog = argv[0]; /* program name for errors */

  if (argc == 1) /* no args; copy standard input */
    filecopy(0, 1);
  else
    while (--argc > 0)
      if ((fd = open(*++argv, O_RDONLY, 0)) == -1) {
        fprintf(stderr, "%s: can't open %s\n", prog, *argv);
        exit(1);
      } else {
        filecopy(fd, 1);
        close(fd);
      }
  exit(0);
}

/* filecopy: copy file ifp to file ofp */
void filecopy(int ifd, int ofd) {
  int n;
  char c;

  while ((n = read(ifd, &c, 1)) > 0)
    if (write(ofd, &c, n) != n) {
      fprintf(stderr, "error writing\n");
      exit(2);
    }
}
