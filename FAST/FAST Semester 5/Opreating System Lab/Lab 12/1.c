#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

void replaceWordInFile(const char *fileName, const char *wordToReplace, const char *replacementWord) {
    int fd = open(fileName, O_RDWR);
    if (fd == -1) {
        perror("open");
        return;
    }

    // Obtain file size
    off_t fileSize = lseek(fd, 0, SEEK_END);
    if (fileSize == -1) {
        perror("lseek");
        close(fd);
        return;
    }

    // Map the file into memory
    char *map = mmap(NULL, fileSize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return;
    }

    // Search and replace the word
    size_t wordToReplaceLen = strlen(wordToReplace);
    size_t replacementWordLen = strlen(replacementWord);
    char *pos = map;

    while ((pos = strstr(pos, wordToReplace)) != NULL && (pos - map) < fileSize) {
        // Calculate the offset of the found word
        size_t offset = pos - map;

        if (wordToReplaceLen != replacementWordLen) {
            // Shift the remaining characters if the lengths are different
            memmove(map + offset + replacementWordLen, map + offset + wordToReplaceLen, fileSize - offset - wordToReplaceLen);
        }

        // Copy the replacement word
        memcpy(map + offset, replacementWord, replacementWordLen);
        pos = map + offset + replacementWordLen;
    }

    // Unmap the file
    if (munmap(map, fileSize) == -1) {
        perror("munmap");
    }

    // Close the file
    if (close(fd) == -1) {
        perror("close");
    }
}


int main() {
    replaceWordInFile("file.txt", "hello", "goodbye");
    return 0;
}

