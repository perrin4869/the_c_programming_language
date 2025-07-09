void *calloc(unsigned n, unsigned size) {
  void *malloc(unsigned);
  void *ptr;
  char *c;
  int i;

  ptr = malloc(n * size);
  c = (char *)ptr;
  for (i = 0; i < n * size; i++)
    *(c + i) = 0;
  return ptr;
}
