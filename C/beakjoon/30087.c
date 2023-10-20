#include <stdio.h>
#include <string.h>

int main(){
    char semina[7][30] = {
        {"Algorithm"},
        {"DataAnalysis"},
        {"ArtificialIntelligence"},
        {"CyberSecurity"},
        {"Network"},
        {"Startup"},
        {"TestStrategy"}};
    char site[7][30] = {
        {"204"},
        {"207"},
        {"302"},
        {"B101"},
        {"303"},
        {"501"},
        {"105"}};

    int N;
    char name[30];

    scanf("%d", &N);

    for (int i = 0; i < N;i++){
        scanf("%s", name);
        for (int j = 0; j < 7;j++){
            if(strcmp(name, semina[j])==0){
                printf("%s\n", site[j]);
                break;
            }
        }
    }
}