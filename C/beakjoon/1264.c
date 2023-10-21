#include <stdio.h>
#include <string.h>

int main(){
    char sentence;
    int cnt,flag = 0;

    while(1)
    {
        cnt = 0;
        while ((sentence = getchar())!='\n')
        {
            if(sentence == 'a' || sentence ==  'e' || sentence == 'i' || sentence == 'o' || sentence == 'u'){
                cnt++;
            }
            if(sentence == 'A' || sentence ==  'E' || sentence == 'I' || sentence == 'O' || sentence == 'U'){
                cnt++;
            }
            if(sentence == '#'){
                flag = 1;
            }
        }
        if(flag == 0)
            printf("%d\n", cnt);
        else
            break;
    }
}