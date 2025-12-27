#define CONFIGURATION_PATH "/.config/dotupdater/"
#define CONF_PATH_MODE 0770
#define PLACEHOLDER_TEXT_SIZE 132
#define CONFIGURATION_FILE "config-test.toml"

/**
 * @brief function to retrieve the home dir using env $HOME
 * @return char * -> the path of executing user home dir.
*/
char *getHomeDir(void);

/**
 * @brief function to retrieve the config folder using the concatenation of the 
 *        string CONFIGURATION_PATH and the return value of the function getHomeDir().
 * @return char * -> the path of config folder, sum of home dir + CONFIGURATION_PATH.
*/
char *getConfigFolder(void);

/**
 * @brief function to retrieve the config file name stored in CONFIGURATION_FILE.
 * @return char * -> the name of configuration file.
*/
char *getConfigFile(void);

/**
 * @brief function to check if the config folder already exists 
 * @param char *cf -> a string that contains the path of the configuration folder.
 * @return int -> it's a boolean function, returns 0 if true, 1 otherwise.
 * @note cf stands for configuration folder.
*/
int isConfDirExists(char *cf);

/**
 * @brief function to check if the config file already exists in the specified config folder.
 * @param char *cf -> a string that contains the path of the configuration folder.
 *        char *f -> a string that contains the filename into the configuration folder.
 * @note cf stands for configuration folder, f for file.
 * @return int -> it's a boolean function, returns 0 if true, 1 otherwise.
*/
int isConfFileExists(char *cf, char *f);

/**
 * @brief wrapper function to create the config folder.
 * @param char *cf -> a string that contains the path of the configuration folder.
 * @note cf stands for configuration folder.
 * @return int -> it returns the same values of mkdir function (man mkdir(3)).
*/
int createConfigFolder(char *cf);

/**
 * @brief function to create a blueprint TOML file to help the user in the starting configuration process.
 * @param char *cf -> a string that contains the path of the configuration folder.
 *        char *f -> a string that contains the filename of configuration file that has to be located in configuration folder.
 * @note cf stands for configuration folder, f for file.
 * @return int -> it returns 0 if the process is success, 1 otherwise.
*/
int createBluePrintConf(char *cf, char *f);
