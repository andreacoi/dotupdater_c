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

char *getLogFilesFolder() {
  char *dir = LOG_LOCATION;
  return dir;
}

char *getLogFile() {
  char *f = LOG_FILE;
  return f;
}

int createFolder(char *dir) {
  return mkdir(dir, MODE); 
}

int createFile(char *dir, char *f, char *content) {
  char *filepath = concatStrings(dir, f);
  if (filepath == NULL) return -1;
  size_t sl = strlen(content);
  char *buf = malloc(sl + 1);
  memcpy(buf, content, sl);
  FILE *bpf = fopen(filepath, "w+");
  if (bpf == NULL) {
    free(filepath);
    return -1;
  }
  if (fwrite(buf,sizeof(char),strlen(buf), bpf) < strlen(buf)) {
    perror("write error");
    free(filepath);
    return -1;
  }
  free(filepath);
  fclose(bpf);
  return 0;
}

int isDirExists(char *dir) {
  struct stat st;
  if (stat(dir, &st) && S_ISDIR(st.st_mode)) {
    return 0;
  } else {
    return 1;
  }
}

int isFileExists(char *dir, char *f) {
  struct stat st;
  char *path = concatStrings(dir, f);
  if (stat(path, &st) && S_ISREG(st.st_mode)) {
    free(path);
    return 0;
  } else {
    free(path);
    return 1;
  }
}

int preliminaryCheck() {
  char *cfolder = getConfigFolder();
  char *cfile = getConfigFile();
  char *lfolder = getLogFilesFolder();
  char *lfile  = getLogFile();

  if (isDirExists(lfolder) == 1) {
    if (createFolder(lfolder) != 0) {
      perror("create folder");
      return -1;
    } 
  }
  if (isFileExists(lfolder, lfile) == 1) {
    if (createFile(lfolder, lfile, "Log file created.") != 0) {
      perror("create file");
      return -1;
    }  
  }
  return 0;
}
