//14-09-2020
//Author: Ahmed Elrasoly
//Calculator Project V2.0
/*This Calculator Application calculates simple math operations and trigonometric functions
this program accepts math problems in a linear form
*/
//preprocessors
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#if _WIN32
    #define clrscr system("cls");
#elif __APPLE__
    #define clrscr system("clear");
#elif __linux__
    #define clrscr system("clear");
#endif

//functions prototypes
void rules();
float dvide(float num1, float num2);
void NewInput(void);
void DeleteSpacesAndRep(void);
void prepare(void);


//size of arrays
#define INPT_SIZE 200// maximum input characters
#define CALC_TOKEN_SIZE 100// maximum token numbers
#define TOKEN_SIZE 15 // maximum character per token

//Global variables
int token_no_index; //index of the last token in the linear problem
char inpt[INPT_SIZE];//input array
char CalculationTokens[CALC_TOKEN_SIZE][TOKEN_SIZE];//matured 2D array to hold the problem in a proper way

//main function
int main(void)
{
    Start://point of start for the goto statement
    token_no_index =0;
    NewInput();
    prepare();
    // operations' priority
    //1st: functions
    for ( int cal = token_no_index; cal >= 0; cal--){
        if (atof(CalculationTokens[cal])){continue;}
        if (!(strcmp(CalculationTokens[cal],"sind"))){
            gcvt (floor(10000*(sin(atof(CalculationTokens[cal +1]) * M_PI/180))+.5)/10000,TOKEN_SIZE, CalculationTokens[cal]);
        }//end if
        if (!(strcmp(CalculationTokens[cal],"sinr"))){
            gcvt (floor(10000*(sin(atof(CalculationTokens[cal +1])))+.5)/10000,TOKEN_SIZE, CalculationTokens[cal]);
        }//end if
        if (!(strcmp(CalculationTokens[cal],"asin"))){
            gcvt (floor(10000*(asin(atof(CalculationTokens[cal +1])))+.5)/10000,TOKEN_SIZE, CalculationTokens[cal]);
        }//end if
        if (!(strcmp(CalculationTokens[cal],"sinh"))){
            gcvt (floor(10000*(sinh(atof(CalculationTokens[cal +1])))+.5)/10000,TOKEN_SIZE, CalculationTokens[cal]);
        }//end if
        if (!(strcmp(CalculationTokens[cal],"cosd"))){
            gcvt (floor(10000*(cos(atof(CalculationTokens[cal +1]) * M_PI/180))+.5)/10000,TOKEN_SIZE, CalculationTokens[cal]);
        }//end if
        if (!(strcmp(CalculationTokens[cal],"cosr"))){
            gcvt (floor(10000*(cos(atof(CalculationTokens[cal +1])))+.5)/10000,TOKEN_SIZE, CalculationTokens[cal]);
        }//end if
        if (!(strcmp(CalculationTokens[cal],"acos"))){
            gcvt (floor(10000*(acos(atof(CalculationTokens[cal +1])))+.5)/10000,TOKEN_SIZE, CalculationTokens[cal]);
        }//end if
        if (!(strcmp(CalculationTokens[cal],"cosh"))){
            gcvt (floor(10000*(cosh(atof(CalculationTokens[cal +1])))+.5)/10000,TOKEN_SIZE, CalculationTokens[cal]);
        }//end if
        if (!(strcmp(CalculationTokens[cal],"tand"))){
            gcvt (floor(10000*(tan(atof(CalculationTokens[cal +1]) * M_PI/180))+.5)/10000,TOKEN_SIZE, CalculationTokens[cal]);
        }//end if
        if (!(strcmp(CalculationTokens[cal],"tanr"))){
            gcvt (floor(10000*(tan(atof(CalculationTokens[cal +1])))+.5)/10000,TOKEN_SIZE, CalculationTokens[cal]);
        }//end if
        if (!(strcmp(CalculationTokens[cal],"atan"))){
            gcvt (floor(10000*(atan(atof(CalculationTokens[cal +1])))+.5)/10000,TOKEN_SIZE, CalculationTokens[cal]);
        }//end if
        if (!(strcmp(CalculationTokens[cal],"tanh"))){
            gcvt (floor(10000*(tanh(atof(CalculationTokens[cal +1])))+.5)/10000,TOKEN_SIZE, CalculationTokens[cal]);
        }//end if
        if (!(strcmp(CalculationTokens[cal],"expo"))){
            gcvt (floor(10000*(exp(atof(CalculationTokens[cal +1])))+.5)/10000,TOKEN_SIZE, CalculationTokens[cal]);
        }//end if
        if (!(strcmp(CalculationTokens[cal],"loge"))){
            gcvt (floor(10000*(log10(atof(CalculationTokens[cal +1])))+.5)/10000,TOKEN_SIZE, CalculationTokens[cal]);
        }//end if
        if (!(strcmp(CalculationTokens[cal],"logs"))){
            gcvt (floor(10000*(log(atof(CalculationTokens[cal +1])))+.5)/10000,TOKEN_SIZE, CalculationTokens[cal]);
        }//end if
        if (!(strcmp(CalculationTokens[cal],"dgre"))){
            gcvt (floor(10000*((atof(CalculationTokens[cal +1])) * 180/M_PI)+.5)/10000,TOKEN_SIZE, CalculationTokens[cal]);
        }//end if
        if (!(strcmp(CalculationTokens[cal],"radn"))){
            gcvt (floor(10000*((atof(CalculationTokens[cal +1])) * M_PI/180)+.5)/10000,TOKEN_SIZE, CalculationTokens[cal]);
        }//end if
        for (unsigned int index = 0; index < CALC_TOKEN_SIZE; index++){
            if (!strcmp("00", CalculationTokens[index]) )
            {
                for (unsigned int subindex = index; subindex < CALC_TOKEN_SIZE; subindex++){strcpy(CalculationTokens[subindex], CalculationTokens[subindex+1]); }
            }//end if
        }//end for
    }//end for
//2nd: power
    for ( int cal1 = token_no_index; cal1 > 0; cal1--){
        if (!(strcmp(CalculationTokens[cal1],"^"))){
            gcvt (floor(10000*pow((atof(CalculationTokens[cal1 -1])), (atof(CalculationTokens[cal1 +1])))+.5)/10000,TOKEN_SIZE, CalculationTokens[cal1-1]);
            strcpy(CalculationTokens[cal1 +1], "00");
        }//end if
        for (unsigned int index = 0; index < CALC_TOKEN_SIZE; index++)    {
            if (!strcmp("00", CalculationTokens[index]) )
            {
                for (unsigned int subindex = index; subindex < CALC_TOKEN_SIZE; subindex++){strcpy(CalculationTokens[subindex], CalculationTokens[subindex+1]); }
            }//end if
        }//end for
    }//end for
    //3rd: multiplication and division
    for ( int cal1 = token_no_index; cal1 > 0; cal1--){
        if (!(strcmp(CalculationTokens[cal1],"*"))){
            gcvt (floor(10000*((atof(CalculationTokens[cal1 +1]))* (atof(CalculationTokens[cal1 -1])))+.5)/10000,TOKEN_SIZE, CalculationTokens[cal1-1]);
            strcpy(CalculationTokens[cal1 +1], "00");
        }//end if
        if (!(strcmp(CalculationTokens[cal1],"/"))){
            gcvt (floor(10000*dvide((atof(CalculationTokens[cal1 -1])), (atof(CalculationTokens[cal1 +1])))+.5)/10000,TOKEN_SIZE, CalculationTokens[cal1-1]);
            strcpy(CalculationTokens[cal1 +1], "00");
        }//end if
        for (unsigned int index = 0; index < CALC_TOKEN_SIZE; index++)    {
            if (!strcmp("00", CalculationTokens[index]) )
            {
                for (unsigned int subindex = index; subindex < CALC_TOKEN_SIZE; subindex++){strcpy(CalculationTokens[subindex], CalculationTokens[subindex+1]); }
            }//end if
        }//end for
    }//end for
    //4th: addition and subtraction
    for ( int cal1 = token_no_index; cal1 > 0; cal1--){
        if (!(strcmp(CalculationTokens[cal1],"+"))){
            gcvt (floor(10000*((atof(CalculationTokens[cal1 +1]))+ (atof(CalculationTokens[cal1 -1])))+.5)/10000,TOKEN_SIZE, CalculationTokens[cal1-1]);
            strcpy(CalculationTokens[cal1 +1], "00");
        }//end if
        if (!(strcmp(CalculationTokens[cal1],"-"))){
            gcvt (floor(10000*((atof(CalculationTokens[cal1 -1]))- (atof(CalculationTokens[cal1 +1])))+.5)/10000,TOKEN_SIZE, CalculationTokens[cal1-1]);
            strcpy(CalculationTokens[cal1 +1], "00");
        }//end if
        for (unsigned int index = 0; index < CALC_TOKEN_SIZE; index++)    {
            if (!strcmp("00", CalculationTokens[index]) )
            {
                for (unsigned int subindex = index; subindex < CALC_TOKEN_SIZE; subindex++){strcpy(CalculationTokens[subindex], CalculationTokens[subindex+1]); }
            }//end if
        }//end for
    }//end for
    printf("Your answer is {%s%s}\n", CalculationTokens[0], CalculationTokens[1]);//printing answers
    for (int i = 0; i < CALC_TOKEN_SIZE; i++){
        strcpy(CalculationTokens[i]," ");
    }
    puts("Restarting...\npress enter");
    getchar();
    fflush(stdin);
    goto Start;//repeating
} //end main


//functions definitions

void rules(void){
    clrscr;
    puts("\nThis program calculates simple math problem entered in linear form.");
    puts("it supports addition, subtraction, multiplication, division, raising to power, trigonometric functions, logarithms and hyperbolic functions.\n");
    puts("this program doesn't support Parentheses () so they'll be considered syntax error./n");
    puts ("add => +, sub => -, multiply => *, divide => /, power => ^.\n\n Sin(degree) => sind, Cos(degree) => cosd, Tan(degree) => tand.\nSin(rad) => sinr, Cos(rad) => cosr, Tan(rad) => tanr.\ninverse Sin() => asin, inverse Cos() => acos, inverse Tan() => atan.\n\nsinh() => sinh, cosh() => cosh, Tanh() => tanh.\n\nexponential() => expo, ln() => loge, log10() => logs.\nToturial => rule, Quit => quit.\n\n\"WARNING\"\ntrigonometric functions are not that accurate so sorry for the inconvenience. :)\n");
    puts("============================================================\nto return to the calculator press ENTER");
    getchar();
    for (int i = 0; i < CALC_TOKEN_SIZE; i++){
        strcpy(CalculationTokens[i]," ");
    }
    main();
    }//end rules

float dvide(float num1, float num2){
    if (num2 == 0)
    {
        puts("Seriously?!! DO NOT DIVIDE BY ZERO. i know it's lame, but that's law man. deal with it !!");
        fflush(stdin);
        getchar();
        for (int i = 0; i < CALC_TOKEN_SIZE; i++){
            strcpy(CalculationTokens[i]," ");
        }
        main();
    }
    else{
        return num1 / num2;
    }
}//end dvid


void NewInput(void){
    fflush(stdin);
    clrscr;
    for (int i = 0; i <= CALC_TOKEN_SIZE; i++){
        strcpy(CalculationTokens[i]," ");
    }
    printf("%s","\nadd => +, sub => -, multiply => *, divide => /, power => ^.\n\n Sin(degree) => sind, Cos(degree) => cosd, Tan(degree) => tand.\nSin(rad) => sinr, Cos(rad) => cosr, Tan(rad) => tanr.\ninverse Sin() => asin, inverse Cos() => acos, inverse Tan() => atan.\n\nsinh() => sinh, cosh() => cosh, Tanh() => tanh.\n\nexponential() => expo, ln() => loge, log10() => logs.\nToturial => rule, Quit => quit.\n\n\"WARNING\"\ntrigonometric functions are not that accurate so sorry for the inconvenience. :)\n");
    puts("enter a problem in a linear form :");
    gets(inpt);
    DeleteSpacesAndRep();
    for (unsigned int element = 0; element < strlen(inpt); element++)
    {
        if (isdigit(inpt[element]) || inpt[element] == '+' || inpt[element] == '-' || inpt[element] == '*' || inpt[element] == '/' || inpt[element] == '^' || inpt[element] == '.')
        {
            continue;
        }//end if
        else {
            if (!(isalpha(inpt[element])))
            {
                for (int i = 0; i < CALC_TOKEN_SIZE; i++){
                    strcpy(CalculationTokens[i]," ");
                }
                main();
            }//end if
            else
            {
                char func[] = "func";
                for(int i = 0; i<4; i++)
                {
                    func[i] = tolower(inpt[element+i]);
                }//end for
                if (!(strcmp(func,"sind")) || !(strcmp(func,"sinr")) || !(strcmp(func,"asin")) || !(strcmp(func,"sinh")) || !(strcmp(func,"cosd")) || !(strcmp(func,"cosr")) || !(strcmp(func,"acos")) || !(strcmp(func,"cosh")) || !(strcmp(func,"tand")) || !(strcmp(func,"tanr")) || !(strcmp(func,"atan")) || !(strcmp(func,"tanh")) || !(strcmp(func,"dgre")) || !(strcmp(func,"radn")) || !(strcmp(func,"expo")) || !(strcmp(func,"loge")) || !(strcmp(func,"logs")) || !(strcmp(func,"quit")) || !(strcmp(func,"rule")))
                {
                    element += 3;
                    continue;
                }//end if
                else
                {
                    puts ("Syntax Error!! Please stick to the rules\n restarting...\n\nPress Enter");
                    getchar();
                    for (int i = 0; i < CALC_TOKEN_SIZE; i++){
                        strcpy(CalculationTokens[i]," ");
                    }
                    main();
                }//end else
        }//end else
        }//end else
    }//end for
    for (unsigned int step = 1; step <= strlen(inpt); step++)
    {
        if (inpt[step] == inpt[step - 1] && !isdigit(inpt[step]))
        {
            inpt[step] = ' ';
        }//end if
    }//end for
            DeleteSpacesAndRep();
}//end NewInput

void DeleteSpacesAndRep(void){
    for (unsigned int index = 0; index < strlen(inpt); index++)
    {
        if (isspace(inpt[index]))
        {
            for (unsigned int subindex = index; subindex < strlen(inpt); subindex++){inpt[subindex] = inpt[subindex+1]; }
        }//end if
    }//end for
}//end DeleteSpacesAndRep
void prepare (){
    short digit = 1;
    int tokens = 0;
    int in_token = 0;
    if (isdigit(inpt[0]) || inpt[0] == '.'){digit = 1;}
    else{
        if (isalpha(inpt[0])){digit = 2;}
        else{
        puts ("Syntax Error!! Please enter a VALID problem\n restarting...\n\nPress Enter");
        getchar();
        for (int i = 0; i < CALC_TOKEN_SIZE; i++){
            strcpy(CalculationTokens[i]," ");
        }
        main();
        }//end else
    }//end else
    for (unsigned int inpt_char =0; inpt_char < strlen(inpt); inpt_char++){
        if (isdigit(inpt[inpt_char]) || inpt[inpt_char] == '.'){
            if (digit != 1){tokens++;in_token =0;}
            CalculationTokens[tokens][in_token] = inpt[inpt_char];
            digit = 1;
            if (tokens >= token_no_index && !isspace(CalculationTokens[tokens][in_token])){token_no_index = tokens;}
            in_token++;
            continue;
        }//end if
        if (isalpha(inpt[inpt_char])){
            if (digit != 2){tokens++;}
            char fun[] = "func";
            for (unsigned int count = 0; count < 4; count++){
               fun[count] = inpt[inpt_char+count];
            }//end for
            strcpy(CalculationTokens[tokens],fun);
            digit = 2;
            inpt_char += 3;
            if (tokens >= token_no_index && !isspace(CalculationTokens[tokens][in_token])){token_no_index = tokens;}
            continue;
        }//end if
        else{
            if (digit != 0){tokens++; in_token =0;}
            CalculationTokens[tokens][in_token] = inpt[inpt_char];
            digit = 0;
            if (tokens >= token_no_index && !isspace(CalculationTokens[tokens][in_token])){token_no_index = tokens;}
            in_token++;
        }//end else
    }//end for
    if (!atof(CalculationTokens[token_no_index])  && !isdigit(CalculationTokens[token_no_index][0])&& strcmp(CalculationTokens[token_no_index],"quit") && strcmp(CalculationTokens[token_no_index],"rule")){
            puts ("Syntax Error!! Please enter a VALID problem.\n restarting...\n\nPress Enter");
            getchar();
            for (int i = 0; i < CALC_TOKEN_SIZE; i++){
                strcpy(CalculationTokens[i]," ");
            }
            main();
    }//end if
    for (unsigned int token = token_no_index; token >= 0; token--){
        if (!strcmp(CalculationTokens[token],"quit")){exit(EXIT_SUCCESS);}
        if (!strcmp(CalculationTokens[token],"rule")){rules();}
        if(!(strcmp(CalculationTokens[token],"sind")) || !(strcmp(CalculationTokens[token],"sinr")) || !(strcmp(CalculationTokens[token],"asin")) || !(strcmp(CalculationTokens[token],"sinh")) || !(strcmp(CalculationTokens[token],"cosd")) || !(strcmp(CalculationTokens[token],"cosr")) || !(strcmp(CalculationTokens[token],"acos")) || !(strcmp(CalculationTokens[token],"cosh")) || !(strcmp(CalculationTokens[token],"tand")) || !(strcmp(CalculationTokens[token],"tanr")) || !(strcmp(CalculationTokens[token],"atan")) || !(strcmp(CalculationTokens[token],"tanh")) || !(strcmp(CalculationTokens[token],"dgre")) || !(strcmp(CalculationTokens[token],"radn")) || !(strcmp(CalculationTokens[token],"expo")) || !(strcmp(CalculationTokens[token],"loge")) || !(strcmp(CalculationTokens[token],"logs"))){
            if (!(strcmp(CalculationTokens[token+1],"+")) || !(strcmp(CalculationTokens[token+1],"-")) || !(strcmp(CalculationTokens[token+1],"*")) || !(strcmp(CalculationTokens[token+1],"/")) || !(strcmp(CalculationTokens[token+1],"^"))){
                puts ("Syntax Error!! Please enter a VALID problem..\n restarting...\n\nPress Enter");
                getchar();
                for (int i = 0; i < CALC_TOKEN_SIZE; i++){
                    strcpy(CalculationTokens[i]," ");
                }
                main();
            }//end if
        }//end if
        if (token == 0){break;}
    }//end for
}//end prepare
