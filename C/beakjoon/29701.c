#include<stdio.h>

char stack[100];
int top = 0;

void push(char Alpa);
char pop();
char find_mos(char *signal);

int main(){
    int cnt, n = 0;
    char tempA;
    char signal[6];

    scanf("%d", &cnt);
    scanf("%c", &tempA);

    for (int i = 0; i < cnt;i++){
        n = 0;
        while(1){
            scanf("%c", &tempA);
            if(tempA == ' '||tempA == '\n'){
                signal[n] = ' ';
                break;
                }
                signal[n] = tempA;
        }

        push(find_mos(signal));
    }

    printf("%s", stack);
}

void push(char Alpa){
    stack[top] = Alpa;
    top++;
}

char pop(){
    return stack[--top];
}

char find_mos(char *signal){
    int cnt = 0;

    switch (signal[cnt++])
    {
    case '.':
        switch (signal[cnt++])
        {
        case '.':
            switch (signal[cnt++])
            {
            case '.':
                switch (signal[cnt++])
                {
                case '.':
                    switch (signal[cnt++])
                    {
                        case '.':
                            return '5';
                        case '-':
                            return '4';
                            case ' ':
                            return 'H';
                    }

                case '-':
                    switch (signal[cnt++])
                    {
                        case '-':
                            return '3';
                        case ' ':
                            return 'V';
                    }
                case ' ':
                    return 'S';
            }
            case '-':
                switch (signal[cnt++])
                {
                    case '.':
                        return 'F';
                    case '-':
                        switch (signal[cnt++])
                        {
                            switch (signal[cnt++])
                            {
                                case '.':
                                    return '?';
                                case '-':
                                    return '2';
                            }
                        }
                    case ' ':
                        return 'U';
                }
            case ' ':
                return 'I';
            }
        case '-':
            switch (signal[cnt++])
            {
                case '.':
                    switch (signal[cnt++])
                    {
                        case '.':
                            return 'L';
                        case '-':
                            return '.';
                        case ' ':
                            return 'R';
                    }
                case '-':
                    switch (signal[cnt++])
                    {
                        case '.':
                            switch (signal[cnt++])
                            {
                                case '-':
                                    return '@';
                                case ' ':
                                    return 'P';
                            }
                        case '-':
                            switch (signal[cnt++])
                            {
                                case '-':
                                    return '1';
                                case ' ':
                                    return 'J';
                            }
                        case ' ':
                            return 'W';
                    }
                case ' ':
                return 'A';
            }

        case ' ':
            return 'E';
        }
    case '-':
        switch (signal[cnt++])
        {
            case '.':
                switch (signal[cnt++])
                {
                    case '.':
                        switch (signal[cnt++])
                        {
                            case '.':
                                switch (signal[cnt++])
                                {
                                    case '.':
                                        switch (signal[cnt++])
                                        {
                                            case '-':
                                                return '-';
                                            case ' ':
                                                return '6';
                                        }
                                    case ' ':
                                        return 'B';
                                }
                            case '-':
                                return 'X';
                            case ' ':
                                return 'D';
                        }
                    case '-':
                        switch (signal[cnt++])
                        {
                            case '.':
                                return 'C';
                            case '-':
                                return 'Y';
                            case ' ':
                                return 'K';
                        }
                    case ' ':
                        return 'N';
                }
            case '-':
                switch (signal[cnt++])
                {
                    case '.':
                        switch (signal[cnt++])
                        {
                            case '.':
                                switch (signal[cnt++])
                                {
                                    case '.':
                                        return '7';
                                    case '-':
                                        return ',';
                                    case ' ':
                                        return 'Z';
                                }
                            case '-':
                                return 'Q';
                            case ' ':
                                return 'G';
                        }
                    case '-':
                        switch (signal[cnt++])
                        {
                            case '.':
                                switch (signal[cnt++])
                                {
                                    case '.':
                                        switch (signal[cnt++])
                                        {
                                            case '.':
                                                return ':';
                                            case ' ':
                                                return '8';
                                        }
                                }
                            case '-':
                                switch (signal[cnt++])
                                {
                                    case '.':
                                        return '9';
                                    case '-':
                                        return '0';
                                }
                        }
                    case ' ':
                        return 'M';
                }
            case ' ':
                return 'T';
        }
    }
}
