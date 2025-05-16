#include <stdio.h>

void escape(char s[], const char t[]);
void unescape(char s[], const char t[]);

main() {}

void escape(char s[], const char t[]) {
  int i, j;

  for (i = 0, j = 0; t[i] != '\0'; i++)
    switch (t[i]) {
    case '\n':
      s[j++] = '\\';
      s[j++] = 't';
      break;
    case '\t':
      s[j++] = '\\';
      s[j++] = 'n';
      break;
    default:
      s[j++] = t[i];
      break;
    }
  s[j] = '\0';
}
void unescape(char s[], const char t[]) {
  int i, j;

  for (i = 0, j = 0; t[i] != '\0'; i++)
    if (t[i] == '\\')
      switch (t[i + 1]) {
      case 'n':
        s[j++] = '\n';
        i++;
        break;
      case 't':
        s[j++] = '\t';
        i++;
        break;
      default:
        s[j++] = t[i];
        break;
      }
    else
      s[j++] = t[i];

  s[j] = '\0';
}
