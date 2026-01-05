#define CONFIGURATION_PATH "/.config/dotupdater-t/"
#define BPCONTENT "[[repositories]]\npath = \"yourpath\"\nbranch = \"yourbranchongh\"\n# this is the structure of the file, replicate it to manage more repos."
#define MODE 0770
#define PLACEHOLDER_TEXT_SIZE 133
#define CONFIGURATION_FILE "config-test.toml"
#define LOG_FILE "dotupdater-test.log"
#define LOG_LOCATION "/var/tmp/"
#define LOG_FOLDER "dotupdater_logs"

/**
 * @brief function to retrieve the home dir using env $HOME
 * @return char * -> the path of executing user home dir.
*/
char *getHomeDir(void);

/**
 * @brief function to retrieve the log files folder using the concatenation of the 
 *        string LOG_LOCATION and the string LOG_FOLDER.
 *        @return char * -> the path of log folder, sum of log location dir + log folder.
*/
char *getLogFilesFolder(void);

/**
 * @brief function to retrieve the log file name stored in LOG_FILE.
 * @return char * -> the name of log file.
*/
char *getLogFile(void);

/**
 * @brief function to retrieve the log files folder using the concatenation of the 
 *        string LOG_FOLDER and the return value of the function getHomeDir().
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
 * @param char *dir -> a string that contains the path of the folder.
 * @return int -> it's a boolean function, returns 0 if true, 1 otherwise.
 * @note cf stands for configuration folder.
*/
int isDirExists(char *dir);

/**
 * @brief function to check if the config file already exists in the specified config folder.
 * @param char *dir -> a string that contains the path of the folder.
 *        char *f -> a string that contains the file name.
 * @return int -> it's a boolean function, returns 0 if true, 1 otherwise.
*/
int isFileExists(char *dir, char *f);

/**
 * @brief wrapper function to create the config folder.
 * @param char *dir -> a string that contains the path of the configuration folder.
 * @return int -> it returns the same values of mkdir function (man mkdir(3)).
*/
int createFolder(char *dir);

/**
 * @brief function to create a file.
 * @param char *dir -> a string that contains the path of the file to be created.
 *        char *f -> a string that contains the file name in the folder dir.
 * @return int -> it returns 0 if the process is success, 1 otherwise.
*/
int createFile(char *dir, char *f, char *content);

/**
 * @brief function to verify that all conditions to run program are regularly satisfied. So, creates folder if not exists,
 *        configuration file (blueprint only) if not exists. This function also creates the log folder with its log file.
 * @return int -> it returns 0 if the process is success, 1 otherwise.
*/
int preliminaryCheck(void);
