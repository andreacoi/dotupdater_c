#include <stdio.h>
#include "conf.h"
#include "helper.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

char *getHomeDir() {
  char *homedir = getenv("HOME");
  return homedir;  
}

char *getConfigFolder() {
  char *dir = CONFIGURATION_PATH;
  char *homedir = getHomeDir();
  char *cf = concatStrings(homedir, dir);
  return cf;
}

char *getConfigFile() {
  // create a char* and put in it the value of the constant that contains the 
  // name of the configuration file.
  char *f = CONFIGURATION_FILE;
  return f;
}

int createConfigFolder(char *cf) {
  // TODO: insert the logger functions
  return mkdir(cf, CONF_PATH_MODE); 
}

int createBluePrintConf(char *cf, char *f) {
  char *filepath = concatStrings(cf, f);
  if (filepath == NULL) return -1;
  printf(filepath);
  char buf[PLACEHOLDER_TEXT_SIZE] = "[[repositories]]\npath = \"yourpath\"\nbranch = \"yourbranchongh\"\n# this is the structure of the file, replicate it to manage more repos.";
  FILE *bpf = fopen(filepath, "w+");
  if (bpf == NULL) {
    free(filepath);
    return -1;
  }
  if (fwrite(buf,sizeof(char),strlen(buf), bpf) < strlen(buf)) {
    perror("write error");
    return -1;
  }
  free(filepath);
  fclose(bpf);
  return 0;
}

int isConfDirExists(char *cf) {
  struct stat st;
  if (stat(cf, &st) && S_ISDIR(st.st_mode)) {
    return 0;
  } else {
    return 1;
  }
}

int isConfFileExists(char *cf, char *f) {
  struct stat st;
  char *path = concatStrings(cf, f);
  if (stat(path, &st) && S_ISREG(st.st_mode)) {
    free(path);
    return 0;
  } else {
    free(path);
    return 1;
  }
}

int preliminaryCheck(char *cf, char *f) {
  if (isConfDirExists(cf) == 0 && isConfFileExists(cf, f) == 0) {
    return 0;
  } else if (isConfDirExists(cf) == 1) {
    createConfigFolder(cf);
    createBluePrintConf(cf, f);
    return -2;
  } else if (isConfFileExists(cf, f) == 1) {
    createBluePrintConf(cf, f);
    return -1;
  }
  return 0;
}
