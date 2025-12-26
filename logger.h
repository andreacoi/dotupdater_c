#define L_ERR 1
#define L_OS_ERR 2
#define L_C_ERR 3 
#define L_INFO -1
#define L_WARNING -2

int createLogFile(char *logfile);
void log(int type, char *message, char *path);
char *getLogFilePath();
