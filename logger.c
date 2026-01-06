#include <stdio.h>
#include "logger.h"

void log(char *message, int type, char *path) {
  if (stat(path, &st) && S_ISREG(st.st_mode)) {
    Message *m;
    m->type = type;
    m->text = "test";
    m->date = "prova";
  } else {
    perror("log file/folder not found");
    return -1;
  }
}
