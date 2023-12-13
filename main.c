#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"


int main(int argc, char **argv)
{
    int fd;
    char *line;

    // 测试从文件中读取
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (fd < 0)
        {
            printf("open error");
            return (1);
        }
        printf("je suis la argc == 2\n");
        while ((line = get_next_line(fd)) != NULL)
        {
            printf("je suis a l interieur de print gnl\n");
            printf("%s", line);
            free(line);
        }
        close(fd);
    }

    // 测试从标准输入读取
    else if (argc == 1)
    {
        fd = STDIN_FILENO;
        while ((line = get_next_line(fd)) != NULL)
        {
             printf("je suis la argc==1\n");
            printf("%s", line);
            free(line);
        }
    }
    else
    {
        printf("Usage: %s [file]\n", argv[0]);
    }

    return 0;
}
