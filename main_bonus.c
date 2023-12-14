#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fds[argc - 1];
    char *line;
    int open_files = argc - 1;

    // Open each file provided as an argument
    for (int i = 1; i < argc; i++) {
        fds[i - 1] = open(argv[i], O_RDONLY);
        if (fds[i - 1] < 0) {
            printf("Error opening %s\n", argv[i]);
            return 1;
        }
    }

    // Read from each file in a round-robin fashion
    while (open_files > 0) {
        for (int i = 0; i < argc - 1; i++) {
            if (fds[i] >= 0) {
                line = get_next_line(fds[i]);
                if (line != NULL) {
                    printf("FD %d: %s", fds[i], line);
                    free(line);
                } else {
                    close(fds[i]);
                    fds[i] = -1;
                    open_files--;
                }
            }
        }
    }

    return 0;
}

