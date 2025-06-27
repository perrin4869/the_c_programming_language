/* saves space: */
int isupper(char c) {
  if (c >= 'A' && c <= 'Z')
    return 1;
  else
    return 0;
}

/*
 * saves time: no overhead of the function call
 *
 * need to be careful, for example:
 * char *p = "This is a string";
 *
 * if (isupper(*p++))
 * ...
 *
 * expands into:
 * ((*p++) >= 'A' && (*p++) <= 'Z') ? 1 : 0
 *
 * which increments the pointer p twice.
 * You have to be aware of macros that may evaluate the argument more than once.
 * Examples ar ethe macros toupper and tolower in <ctype.h>
 *
 */
#define isupper(c) ((c) >= 'A' && (c) <= 'Z') ? 1 : 0;
