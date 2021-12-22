#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
/*
      -+-+-+-+-+-+- ASCII CODE -+-+-+-+-+-+-
  -+-+-+-+-+-+- FOREGROUND COLOUR -+-+-+-+-+-+-
FOREGROUND_BLACK_COLOUR 				"\033[30m"  CAN BE USED WHEN BACKGROUND IS WHITE
FOREGROUND_RED_COLOUR 					"\033[31m"
FOREGROUND_GREEN_COLOUR 				"\033[32m"
FOREGROUND_YELLOW_COLOUR 				"\033[33m"
FOREGROUND_BLUE_COLOUR 					"\033[34m"
FOREGROUND_MAGENTA_COLOUR 				"\033[35m"
FOREGROUND_CYAN_COLOUR 					"\033[36m"
FOREGROUND_LIGHT_GREY_COLOUR 			"\033[37m"
FOREGROUND_DARK_GREY_COLOUR	 			"\033[90m"
FOREGROUND_LIGHT_RED_COLOUR 			"\033[91m"
FOREGROUND_LIGHT_GREEN_COLOUR	 		"\033[92m"
FOREGROUND_LIGHT_YELLOW_COLOUR 			"\033[93m"
FOREGROUND_LIGHT_BLUE_COLOUR 			"\033[94m"
FOREGROUND_LIGHT_MAGNETA_COLOUR 		"\033[95m"
FOREGROUND_LIGHT_CYAN_COLOUR 			"\033[96m"
FOREGROUND_WHITE_COLOUR 				"\033[97m"

  -+-+-+-+-+-+- BACKGROUND COLOUR -+-+-+-+-+-+-
BACKGROUND_BLACK_COLOUR 			    "\033[40m"  CAN BE USED WHEN THE APPLICATION BACKGROUND IS WHITE
BACKGROUND_RED_COLOUR 				    "\033[41m"
BACKGROUND_GREEN_COLOUR 			    "\033[42m"
BACKGROUND_YELLOW_COLOUR 			    "\033[43m"
BACKGROUND_BLUE_COLOUR 				    "\033[44m"
BACKGROUND_MAGENTA_COLOUR 			    "\033[45m"
BACKGROUND_CYAN_COLOUR 				    "\033[46m"
BACKGROUND_LIGHT_GREY_COLOUR 		    "\033[47m"
BACKGROUND_DARK_GREY_COLOUR 		    "\033[100m"
BACKGROUND_LIGHT_RED_COLOUR             "\033[101m"
BACKGROUND_LIGHT_GREEN_COLOUR 		    "\033[102m"
BACKGROUND_LIGHT_YELLOW_COLOUR 		    "\033[103m"
BACKGROUND_LIGHT_BLUE_COLOUR 		    "\033[104m"
BACKGROUND_LIGHT_MAGNETA_COLOUR 	    "\033[105m"
BACKGROUND_LIGHT_CYAN_COLOUR 		    "\033[106m"
BACKGROUND_WHITE_COLOUR 			    "\033[107m"

     -+-+-+-+-+-+- PRSENTATION -+-+-+-+-+-+-
FOREGROUND_BOLD 						"\033[1m"
FOREGROUND_UNDERLINE 					"\033[4m"
FOREGROUND_NULL_UNDERLINE 				"\033[24m"
FOREGROUND_NEGATIVE_COLOUR 				"\033[7m"
FOREGROUND_NULL_NEGATIVE 				"\033[27m"
FOREGROUND_DEFAULT 						"\033[0m"

-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- ENUMERATOR BANK FOR QUICK REFERENCE -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
{Foreground_Black_Colour = 30 , Foreground_Red_Colour , Foreground_Green_Colour , Foreground_Yellow_Colour , Foreground_Blue_Colour , Foreground_Magenta_Colour , Foreground_Cyan_Colour ,
Foreground_Light_Grey_Colour , Background_Black_Colour = 40 , Background_Red_Colour , Background_Green_Colour , Background_Yellow_Colour , Background_Blue_Colour , Background_Magenta_Colour , Background_Cyan_Colour ,
BACKGROUND_Light_Grey_Colour , Foreground_Dark_Grey_Colour = 90 , Foreground_Light_Red_Colour , Foreground_Light_Green_Colour , Foreground_Light_Yellow_Colour , Foreground_Light_Blue_Colour , Foreground_Light_Magenta_Colour ,
Foreground_Light_Cyan_Colour , Foreground_White_Colour , Background_Dark_Grey_Colour  = 100 , Background_Light_Red_Colour , Background_Light_Green_Colour , Background_Light_Yellow_Colour , Background_Light_Blue_Colour ,
Background_Light_Magenta_Colour , Background_Light_Cyan_Colour , Background_White_Colour };         */

#define COLOUR(colour) printf("\033[%dm*\033[0m",colour) /* COLOUR CODE IS FORMATED AND IS PRINTED INTO COLOURED PATTERN */
#define CURSOR_POSITION( x , y ) printf("\033[%d;%dH",(y),(x))
#define PI 3.142857142857143


int *random_int(int *min , int *max);
void triangle(int *total_row);
void square(int *rows);
void pattern_select();
void cursor_position(int function_code);

int main(int argc , char *argv[]){
    pattern_select();
    return 0;
}

/* -+-+-+-+-+-+- THIS FUNCTION GENERATES RANDOM (INTEGER) NUMBERS -+-+-+-+-+-+- */
int *random_int(int *min , int *max){
    int *random , address;
    address = ((int)rand()%( *max - *min ) + *min);
    random = &address;
    return random;
}

/* -+-+-+-+-+-+- THIS FUNCTION PRINTS OUT COLOURFUL TRIANGLE PATTERN -+-+-+-+-+-+- */
void triangle(int *total_row){
    int row , counter , *colour;
    int min = 31 , max = 37;
    int mino = 90 , maxo = 97;
    for (row = 1 ; row <= *total_row ; row++){
        for (counter = 1 ; counter <= *total_row - row ; counter++){
            printf(" ");
        }
        for (counter = 1 ; counter <= 2*row - 1 ; counter++){
            if(counter%2){
                colour = random_int(&min , &max);
                COLOUR(*colour);
            }else{
                colour = random_int(&mino , &maxo);
                COLOUR(*colour);
            }
                //Sleep(50);
        }
        printf("\n");
    }
}

/* -+-+-+-+-+-+- THIS FUNCTION PRINTS OUT COLOURFUL SQUARE PATTERN -+-+-+-+-+-+- */
void square(int *rows){
    int row , column , *colour , x = 11 , y = 10 , counter;
    int min = 31 , max = 37;
    int mino = 90 , maxo = 97;
    printf("\n");
    for (row = 1 ; row <= *rows ; row++){
            counter = 1;
        for (column = 1 ; column <= *rows ; column++){
            if(counter != *rows){
                CURSOR_POSITION(x , y);
                //Sleep(500);
                x += 2;
                counter++;
            }else if(counter == *rows){
                x = 11;
                y += 1;
            }
            if(column%2){
                colour = random_int(&min , &max);
                COLOUR(*colour);
                printf(" ");
            }else{
                colour = random_int(&mino , &maxo);
                COLOUR(*colour);
                printf(" ");
            }
        }
        printf("\n");
    }
}

/* -+-+-+-+-+-+- THIS FUNCTION CALLS THE RESPECTIVE PATTERN FUNCTION -+-+-+-+-+-+- */
void pattern_select(){
    int select , value;
    cursor_position(1);
    scanf("%d",&select);
    switch(select){
        case 1: srand(time(NULL));
                printf("\n\nEnter the total number of ROWS : ");
                scanf("%d",&value);
                triangle(&value);
                break;

        case 2: srand(time(NULL));
                printf("\n\nEnter the total number of ROWS : ");
                scanf("%d",&value);
                square(&value);
                break;
        default : break;
    }
}

/* -+-+-+-+-+-+- THIS FUNCTION POSITIONS THE CURSOR ACCORDING TO THE RESPECTIVE FUNCTION -+-+-+-+-+-+- */
void cursor_position(int function_code){
    switch(function_code){
        case 1: printf("\n    --------\n"
                        "1. |TRIANGLE|\n"
                        "    --------");

                CURSOR_POSITION(20 , 2);
                printf("------");
                CURSOR_POSITION(16 , 3);
                printf("2. |SQUARE|");
                CURSOR_POSITION(20 , 4);
                printf("------\n");
                CURSOR_POSITION(28 , 5);

                CURSOR_POSITION(32 , 2);
                printf("------");
                CURSOR_POSITION(28 , 3);
                printf("3. |CIRCLE|");
                CURSOR_POSITION(32 , 4);
                printf("------\n");
                CURSOR_POSITION(28 , 5);

                printf("-----\n");
                printf("Enter your option here -> |     |");
                CURSOR_POSITION(28 , 7);
                printf("-----");
                CURSOR_POSITION(30 , 6);
                break;

    }
}























