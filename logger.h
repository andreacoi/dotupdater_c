#define L_ERR 1
#define L_OS_ERR 2
#define L_C_ERR 3 
#define L_INFO -1
#define L_WARNING -2

#define LOGFILE "/var/tmp/dupc_logs/dupc.logs"

typedef struct message {
  char *type;
  char *date;
  char *text;
}Message;

void dup_log(char *mtext, int type);
