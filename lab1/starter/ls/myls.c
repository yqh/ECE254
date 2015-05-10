/**
 * @file:  ECE254/lab1/starter/ls/ls_fperm.c
 * @brief: Print owner permission of file for each command-line argument
 * @date: 2014/05/01
 * NOTES: limitation -> does not detect sticky bit setting 
 */

#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>          // for printf().  man 3 printf
#include <stdlib.h>         // for exit().    man 3 exit
#include <pwd.h>            // for getpwuid()
#include <grp.h>            // for getgrgid()
#include <time.h>           // for ctime()
#include <string.h>         // for strlen()

#define STRLEN1 128
#define STRLEN2 64
int main(int argc, char *argv[])
{
	int i;
	char type;
	char perms[] = "---------\0";
	struct stat buf;
	DIR *p_dir;
        struct dirent *p_dirent;
       	if ((p_dir = opendir(argv[1])) == NULL) {
        	printf("opendir(%s) failed\n", argv[1]);
                exit(1);
        }

        while ((p_dirent = readdir(p_dir)) != NULL) {
                char *str_path = p_dirent->d_name;      // relative path name!
		//TODO: better error handling needed
               	if (str_path == NULL) {
              		printf("Null pointer found!");
                        exit(2);
               	} else {
			if (lstat(str_path, &buf) < 0) {
                        	perror("lstat error");
                        	continue;
               		}
                        mode_t mode = buf.st_mode;

               		if      (S_ISREG(mode))  type = '-';
                	else if (S_ISDIR(mode))  type = 'd';
#ifdef S_ISLNK
                	else if (S_ISLNK(mode))  type = 'l';
#endif
                	else                     type = '?';
			perms[0] = (mode & S_IRUSR) ? 'r' : '-';
			perms[1] = (mode & S_IWUSR) ? 'w' : '-';
			perms[2] = (mode & S_IXUSR) ? 'x' : '-';	// assume no sticky bit
			perms[3] = (mode & S_IRGRP) ? 'r' : '-'; 
			perms[4] = (mode & S_IWGRP) ? 'w' : '-'; 
			perms[5] = (mode & S_IXGRP) ? 'x' : '-';
			perms[6] = (mode & S_IROTH) ? 'r' : '-'; 
			perms[7] = (mode & S_IWOTH) ? 'w' : '-'; 
			perms[8] = (mode & S_IXOTH) ? 'x' : '-';
			printf("%c%s %s\n", type, perms, str_path);
                }
        }
	return 0;
}
