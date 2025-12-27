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
  char *cf = sumStrings(homedir, dir);
  return cf;
}

char *getConfigFile() {
  // create a char* and put in it the value of the constant that contains the 
  // name of the configuration file.
  char *f = CONFIGURATION_FILE;
  char *cf = getConfigFolder();
  char *complete = sumStrings(cf, f);
  return complete;
}



int createConfigFolder(char *cf) {
  // TODO: insert the logger functions
  return mkdir(cf, CONF_PATH_MODE); 
}

int createBluePrintConf(char *cf, char *f) {
  char *f = sumStrings(cf, f);
  char buf[PLACEHOLDER_TEXT_SIZE] = "[[repositories]]\npath = \"yourpath\"\nbranch = \"yourbranchongh\"\n# this is the structure of the file, replicate it to manage more repos.";
  FILE *bpf = fopen(f, "w");
  fwrite(buf,PLACEHOLDER_TEXT_SIZE, 1, bpf);
  free(f);
  fclose(bpf);
  return 1;
}


int isConfDirExists(char *cf) {
  return 0;
}

int isConfFileExists(char *cf, char *f) {
  return 0;
} 
