enum { NO, YES };

int gettoken(void);

/* nexttoken: get the next token and push it back */
int nexttoken(void) {
  int type;
  extern int prevtoken;

  type = gettoken();
  prevtoken = YES;
  return type;
}
