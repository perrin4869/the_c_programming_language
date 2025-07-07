#include <fcntl.h>
#include <stdlib.h>

#include "dirent.h"

/* closedir: close directory opened by opendir */
void closedir(DIR *dp) {
  if (dp) {
    close(dp->fd);
    free(dp);
  }
}
