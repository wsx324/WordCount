#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c | -w] filename\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[2], "r");
    if (fp == NULL) {
        printf("Can't open file %s!\n", argv[2]);
        return 2;
    }
    
    int count = 0;
    if (strcmp(argv[1], "-c") == 0) {//计算字符数 
        while (fgetc(fp) != EOF) {
            count++;
        }
        printf("字符数: %d\n", count);
    } else if (strcmp(argv[1], "-w") == 0) {//计算单词数 
        int state = 0; 
        char c;
        while ((c = fgetc(fp)) != EOF) {
            if (c == ' ' || c == '\t' || c == '\n') {
                state = 0; 
            } else if (!state) {
                state = 1; 
                count++;
            }
        }//
        printf("单词数: %d\n", count);
    }
    
    fclose(fp);
    return 0;
}
