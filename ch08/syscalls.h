#ifndef EOF
#define EOF (-1)
#endif

#ifndef BUFSIZ
#define BUFSIZ 1024
#endif

int read(int fd, char *buf, int n);
int write(int fd, char *buf, int n);
/* the def in the book is:
 * int open(const char *name, int flags, int perms);
 * however, it conflicts with the def in fcntl, which is:
 */
int open(const char *name, int flags, ...);
int close(int fd);
