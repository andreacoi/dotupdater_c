#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "logger.h"
#include "helper.h"

void dup_log(char *message, int type) {
    Message *m = malloc(sizeof(Message));
    if (m == NULL) return;
    m->text = message;
    m->date = getCurrentDate();
    // cleanup if malloc for the date fails for some reason.
    if (m->date == NULL) return;
    switch (type) {
      case 1:
        m->type = "[E]";
        break;
      case 2:
        m->type = "[OSINT]";
        break;
      case 3:
        m->type = "[CERR]";
        break;
      case -1:
        m->type = "[INFO]";
        break;
      case -2:
        m->type = "[W]";
        break;
      default:
        m->type = "[LOG]";
        break;
    }
    char *estr = cStr("[", m->date, "] - ", m->type, " - ", m->text, "\n", NULL);
    printf("%s", estr);
    // free after using estr
    free(estr);
    // free m->date after using it.
    free(m->date);
}
