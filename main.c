#include <stdio.h>
#include <string.h>

int main(void){
    char sentence[100];
    printf("enter sentence : ");
    fgets(sentence, sizeof sentence, stdin);
    int i = 0, cnt = 0;
    while(sentence[i] != '\0'){
        if(sentence[i] >= 65 && sentence[i] <= 90 ){ // if character == uppercase
            sentence[i] += 32;// lower case : 97 ~ 122,  upper case: 65 90
            cnt++;
        }
        i++;
    }
    printf("replaced sentence: %s", sentence);
    printf("replaced character : %d", cnt);
    return 0;
}
