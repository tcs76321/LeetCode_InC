#include <stdio.h>
#include <string.h>

int strStr(char * haystack, char * needle){
    int haystackLength = strlen(haystack);
    int needleLength = strlen(needle);

    if(*needle == '\0'){
        return 0;
    }

    int iter1, iter2 = 0;
    while(*(haystack+iter1) != '\0'){
        if(*(needle) == *(haystack + iter1)) {
            iter2 = 0;
            while(*(needle+iter2) != '\0'){
                if(*(needle+iter2) != *(haystack+iter1+iter2)){
                    goto incomplete_needle;
                }
                else if(iter1+needleLength > haystackLength){
                    return -1;
                }
                iter2++;
            }
            return iter1;
        }
        incomplete_needle:
        iter1++;
    }

    return -1;
}

int main(){
    char pile_of_hay[20] = {'\0'};
    pile_of_hay[0] = 'h';
    pile_of_hay[1] = 'e';
    pile_of_hay[2] = 'l';
    pile_of_hay[3] = 'l';
    pile_of_hay[4] = 'o';

    char aNeedle[5] = {'\0'};
    aNeedle[0] = 'l';
    aNeedle[1] = 'o';

    printf("%d", strStr(pile_of_hay, aNeedle));


    return 0;
}
