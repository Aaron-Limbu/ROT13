#include <stdio.h>
#include <string.h>

#define STRMAX 300

void RT(char word[STRMAX], char rot[STRMAX]);

int main(int argc, char* argv[]) {
    char Letters[26];
    for (int i = 0; i < 26; i++) {
        Letters[i] = 'a' + i;
    }
    
    char word[STRMAX];
    char rot[STRMAX];
    FILE *tfile;    
    int max = 0; 
    FILE *ofile = fopen("o.txt","w"); 
    if (argc == 2 && (tfile = fopen(argv[1], "r"))) {
        while (fgets(word, STRMAX, tfile) != NULL && max++ < STRMAX) {
            RT(word, rot); 
            rot[strlen(word)] = '\0'; 
            fprintf(ofile,"%s",&rot);
        }
        fclose(tfile);
    } else {
        printf("No file\n");
    }

    return 0;
}

void RT(char word[STRMAX], char rot[STRMAX]) {
    for (int i = 0; i < strlen(word); i++) {
        if (isalpha(word[i])) {
            char base = isupper(word[i]) ? 'A' : 'a';
            rot[i] = (word[i] - base + 13) % 26 + base;
        } else {
            rot[i] = word[i];
        }
    }
    rot[strlen(word)] = '\0'; 
}
