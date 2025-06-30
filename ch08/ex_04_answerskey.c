#include "stdio.h"
#include "syscalls.h"

int fseek(FILE *fp, long offset, int origin) {
  if (fp->flag & (_ERR | _EOF))
    return EOF;

  if (fp->flag & _READ && fp->ptr > fp->base) {
    fp->ptr = fp->base;
    fp->cnt = 0;
  }

  if (fp->flag & _WRITE & fp->ptr > fp->base)
    fflush(fp);

  if (lseek(fp->fd, offset, origin) < 0)
    return EOF;

  return 0;
}
