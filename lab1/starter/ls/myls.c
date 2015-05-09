/**
 * @file:  ECE254/lab1/starter/ls/ls_fperm.c
 * @brief: Print owner permission of file for each command-line argument
 * @date: 2014/05/01
 * NOTES: limitation -> does not detect sticky bit setting 
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int i;
	char str[] = "---------\0";
	struct stat buf;

	if (argc == 1) {
		printf("Usage: %s <filename>\n", argv[0]);
		exit(0);
	}

	for (i = 1; i < argc; i++) {
		printf("Owner permission of %s: ", argv[i]);
		if (lstat(argv[i], &buf) < 0) {
			perror("lstat error");
			continue;
		}   

		mode_t mode = buf.st_mode;

		str[0] = (mode & S_IRUSR) ? 'r' : '-';
		str[1] = (mode & S_IWUSR) ? 'w' : '-';
		str[2] = (mode & S_IXUSR) ? 'x' : '-';	// assume no sticky bit
		str[3] = (mode & S_IRGRP) ? 'r' : '-'; 
		str[4] = (mode & S_IWGRP) ? 'w' : '-'; 
		str[5] = (mode & S_IXGRP) ? 'x' : '-';
		str[6] = (mode & S_IROTH) ? 'r' : '-'; 
		str[7] = (mode & S_IWOTH) ? 'w' : '-'; 
		str[8] = (mode & S_IXOTH) ? 'x' : '-';

		printf("%s\n", str);
	}

	return 0;
}
