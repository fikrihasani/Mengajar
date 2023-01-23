#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a, const void *b) {
    const char *ia = (const char *)a;
    const char *ib = (const char *)b;
    return strcmp(ia, ib);
}
int main() {
    // nyimpan karakter2 huruf vokal
    char vowels[] = "aeiou";
    // data string nya
    char strings[100000][9];
    // data menghitung konsonan
    int count[100000];
    // iterasi index
    int stringCount = 0;
    FILE *fp = fopen("prob3SortString.txt", "r");
    // read file
    while (fscanf(fp, "%s", strings[stringCount]) != EOF) {
        count[stringCount] = 0;
        //read setiap karakter dari string
        for (int k = 0; k < strlen(strings[stringCount]); k++) {
            // temp char
            char c = strings[stringCount][k];
            // strchr ngecek apakah c ada di string
            if (strchr(vowels, c) == NULL) {
                // kalau ga ada berarti konsonan. 
                // stringCount jadi += 1
                count[stringCount]++;
            }
        }
        // bertambah karena tambah baris
        stringCount++;
    }
    fclose(fp);
    for (int i = 0; i < stringCount; i++) {
        for (int j = i + 1; j < stringCount; j++) {
            // bubble sort, array check nya menggunakan array count
            if (count[i] < count[j]) {
                char tempString[9];
                strcpy(tempString, strings[i]);
                int tempCount = count[i];
                strcpy(strings[i], strings[j]);
                count[i] = count[j];
                strcpy(strings[j], tempString);
                count[j] = tempCount;
            }
            // jika count ke i dan j sama
            else if (count[i] == count[j]) {
                // swap by abjad
                if (strcmp(strings[i], strings[j]) > 0) {
                    char tempString[9];
                    strcpy(tempString, strings[i]);
                    strcpy(strings[i], strings[j]);
                    strcpy(strings[j], tempString);
                }
            }
        }
    }
    for (int i = 0; i < stringCount; i++) {
        printf("%s: %d\n", strings[i], count[i]);
    }
    return 0;
}
