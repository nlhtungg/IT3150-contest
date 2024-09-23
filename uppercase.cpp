#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convertToUppercase(char *text) {
    for (int i = 0; text[i] != EOF; i++) {
        text[i] = toupper(text[i]);
    }
}

int main() {
    char paragraph[1000];

    fgets(paragraph, sizeof(paragraph), stdin);
    size_t len_para = strlen(paragraph);
    if (len_para > 0 && paragraph[len_para - 1] == '\n') {
        paragraph[len_para - 1] = '\0';
    }

    convertToUppercase(paragraph);
    printf("%s\n", paragraph);

    return 0;
}
