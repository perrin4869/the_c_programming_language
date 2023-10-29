#include <stdio.h>

#define SIZE 100

void escape(char s[], const char t[]);
void unescape(char s[], const char t[]);
void unescape_answerskey(char s[], const char t[]);

main() {
  char s[SIZE];
  escape(s, "omg I will be \n escaped");
  printf("%s\n", s);

  unescape(s, "omg I will be \\n unescaped");
  printf("%s\n", s);

  unescape(s, "omg I will be \\n unescaped sneakily \\");
  printf("%s\n", s);

  unescape_answerskey(s, "omg I will be \\n unescaped sneakily \\");
  printf("%s\n", s);

  char omg[38] = "omg I will be \\n unescaped sneakily \\";
  unescape_answerskey(s, omg);
  printf("%s\n", s);
}

void escape(char s[], const char t[]) {
  int i;
  int j;
  for (i = 0, j = 0; t[i] != '\0'; i++) {
    switch (t[i]) {
    case '\n':
      s[j++] = '\\';
      s[j++] = 'n';
      break;
    case '\t':
      s[j++] = '\\';
      s[j++] = 't';
      break;
    default:
      s[j++] = t[i];
      break;
    }
  }
  s[j++] = '\0';
}

// this one handles the case where t ends on `\` - this is not a valid
// string, but it could be an input to the function - maybe throw an error in
// that case
void unescape(char s[], const char t[]) {
  int i;
  int j;
  for (i = 0, j = 0; t[i] != '\0'; i++) {
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
        s[j++] = '\\';
        break;
      }
    else
      s[j++] = t[i];
  }
  s[j++] = '\0';
  // printf("%d %d %d %d, %d, %c, %d, %d\n", i, t[i - 1], t[i], t[i + 1], t[i +
  // 2],
  //        t[36], t[37], t[38]);
}

// this one has an issue - it can cause a stack overflow if the string ends with
// a backslash '\' - I guess the answerskey assumes the input is valid, and
// ignores the possibility of an escape at the end
void unescape_answerskey(char s[], const char t[]) {
  int i, j;
  for (i = j = 0; t[i] != '\0'; i++) {
    if (t[i] != '\\')
      s[j++] = t[i];
    else
      switch (t[++i]) {
      case 'n':
        s[j++] = '\n';
        break;
      case 't':
        s[j++] = '\t';
        break;
      default:
        s[j++] = '\\';
        s[j++] = t[i];
        break;
      }
  }
  s[j++] = '\0';
  // printf("%d %d %d %d, %d, %c, %d, %d\n", i, t[i - 1], t[i], t[i + 1], t[i +
  // 2],
  //        t[36], t[37], t[38]);
}
