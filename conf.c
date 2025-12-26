#include <stdio.h>
#include "conf.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

// function to retrieve the home dir using env $HOME

char *getHomeDir() {
  char *homedir = getenv("HOME");
  return homedir;  
}

// function to retrieve the config folder using the concatenation of the 
// string CONFIGURATION_PATH and the return value of the function getHomeDir().

char *getConfigFolder() {
  char *fp = CONFIGURATION_PATH;
  char *hd = getHomeDir();

  size_t lfp = strlen(fp);
  size_t lhd = strlen(hd);
  char *cf = malloc(lfp + lhd + 1);
  cf = strcpy(cf, hd);
  cf = strcat(hd, fp);
  return cf;
}

// wrapper function to create the config folder, it returns same value of 
// mkdir(3).

int createConfigFolder(char *cf) {
  // TODO: insert the logger functions
  return mkdir(cf, CONF_PATH_MODE); 
}

int createBluePrintConf(char *cf) {
  // check if the folder exists
  if (checkConfDir(cf) == 0) {
    // if the folder exists, check if the file exists
  }
  return 0;
}

// function to check if the config folder already exists, includes a recursive
// call to createConfigFolder. Returns 0 if the folder exists or the return
// value of the createConfigFolder().

int checkConfDir(char *cf) {
  struct stat st;
  if (stat(cf, &st) == 0 && S_ISDIR(st.st_mode)) {
  // TODO: insert the logger functions
    return 0;
  } else {
    return createConfigFolder(cf);
  }
}

int checkConfFile(char *cf) {
  char *f = CONFIGURATION_FILE;
  size_t lfp = strlen(cf);
  size_t lf = strlen(f);
  char *cp = malloc(lfp + lf + 1);
  cp = strcpy(cp, cf);
  cp = strcat(cf, f);
  printf("%s", cp);
  return 0;
} 
