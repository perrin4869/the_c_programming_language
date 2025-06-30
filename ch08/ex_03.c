#include <stdlib.h>

#include "stdio.h"
#include "syscalls.h"

int fflush(FILE *fp) {
  int n;

  /* fp->ptr points to the next character */
  n = fp->ptr - fp->base;
  if (write(fp->fd, fp->base, n) != n) {
    fp->flag |= _ERR;
    fp->cnt = 0;
    return EOF; /* putc returns EOF on error */
  }

  fp->ptr = fp->base;
  fp->cnt = fp->flag & _UNBUF ? 1 : BUFSIZ;
  return 0; /* return 0 on success */
}

int _flushbuf(int i, FILE *fp) {
  int bufsize;

  if ((fp->flag & (_WRITE | _EOF | _ERR)) != _WRITE)
    return EOF;
  bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
  if (fp->base == NULL) { /* no buffer yet */
    if ((fp->base = (char *)malloc(bufsize)) == NULL)
      return EOF; /* can't get buffer */
  } else if (fflush(fp) != 0)
    return EOF;

  fp->ptr = fp->base;
  fp->cnt = bufsize - 1;
  *fp->ptr++ = i;
  return i;
}

int fclose(FILE *fp) {
  if (fflush(fp) != 0)
    return EOF;

  if (close(fp->fd) != 0)
    return EOF;

  fp->flag = 0;
  fp->cnt = 0;
  fp->ptr = NULL;
  free(fp->base);
  fp->base = NULL;
  return 0; /* return 0 on success */
}
