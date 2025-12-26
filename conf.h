#define CONFIGURATION_PATH "/.config/dotupdater/"
#define CONF_PATH_MODE 0770
#define CONFIGURATION_FILE "config.toml"

char *getHomeDir();
char *getConfigFolder();
int checkConfDir();
int checkConfFile();
int createConfigFolder();
int createBluePrintConf();
