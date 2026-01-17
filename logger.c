#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "logger.h"
#include "helper.h"

void dup_log(char *message, int type) {
    Message *m = malloc((sizeof(message) *3) + 1);
    m->text = message;
    m->date = getCurrentDate();
    switch (type) {
      case 1:
        m->type = " [E] ";
        break;
      case 2:
        m->type = " [OSINT] ";
        break;
      case 3:
        m->type = " [CERR] ";
        break;
      case -1:
        m->type = " [INFO] ";
        break;
      case -2:
        m->type = " [W] ";
        break;
    }
    char *estr = cStr("[", m->date, "] - ", m->type, " - ", m->text, "\n");
    printf("%s", estr);
    free(estr);
}
