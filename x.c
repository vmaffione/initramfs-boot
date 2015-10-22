#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
        struct stat sb;
        int x;
        int ret;

        printf("Hello world\n");
        x = getchar();
        printf("Intero: %d\n", x);

        memset(&sb, 0, sizeof(sb));
#if 0
        ret = stat("/bin/sh", &sb);
        if (ret) {
                printf("stat() failed [errno=%d]\n", errno);
        } else {
                printf("File type:                ");

                switch (sb.st_mode & S_IFMT) {
                        case S_IFBLK:  printf("block device\n");            break;
                        case S_IFCHR:  printf("character device\n");        break;
                        case S_IFDIR:  printf("directory\n");               break;
                        case S_IFIFO:  printf("FIFO/pipe\n");               break;
                        case S_IFLNK:  printf("symlink\n");                 break;
                        case S_IFREG:  printf("regular file\n");            break;
                        case S_IFSOCK: printf("socket\n");                  break;
                        default:       printf("unknown?\n");                break;
                }

                printf("I-node number:            %ld\n", (long) sb.st_ino);

                printf("Mode:                     %lo (octal)\n",
                                (unsigned long) sb.st_mode);

                printf("Link count:               %ld\n", (long) sb.st_nlink);
                printf("Ownership:                UID=%ld   GID=%ld\n",
                                (long) sb.st_uid, (long) sb.st_gid);

                printf("Preferred I/O block size: %ld bytes\n",
                                (long) sb.st_blksize);
                printf("File size:                %lld bytes\n",
                                (long long) sb.st_size);
                printf("Blocks allocated:         %lld\n",
                                (long long) sb.st_blocks);

                printf("Last status change:       %s", ctime(&sb.st_ctime));
                printf("Last file access:         %s", ctime(&sb.st_atime));
                printf("Last file modification:   %s", ctime(&sb.st_mtime));
        }
#endif

        errno = 0;
        ret = execlp("/bin/sh", "/bin/sh");
        printf("execlp() returned %d [errno=%d]\n", ret, errno);
        sleep(999999999);
        return 0;
}

