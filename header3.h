//
// Created by Andre on 26/11/2026.
//

#ifndef CLASS4_HEADER3_H
#define CLASS4_HEADER3_H
#define filename "filetest1.txt"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int number;
    int rooms;
    char name[50];
    char owner[50];
    bool booked;
    char street[50];
    float rent;
}flat;
int WriteToFile(flat *X[],int N);

int ReadFromFile(flat*X[],int N){
    FILE *fp= fopen(filename,"r");
    if (fp==NULL) {
        perror("couldn´t open flats.txt");
        return 1;
    }
    printf("Apartments available: \n");
    int character = fgetc(fp);
    while (character != EOF) {
        printf("%c", character);
        character = fgetc(fp);
    }
        fclose(fp);
    return 0;
    }

int WriteToFile(flat *X[],int N) {
    /*int choice;
    printf("\n");
    printf("Do you wish to add appartments to the list?\n");
    printf("1. Yes/ 2. No\n");
    scanf("%d", &choice);
    if (choice == 1) {
        int amount;
        printf("How many appartments you want to add?: ");
        scanf("%d", &amount);*/
   // char numbuffer[12];//float numchecker=0;
        *X = malloc( sizeof(flat)*N);
        if (*X == NULL) {
            fprintf(stdout,"Out of memory\n");
            free(*X);
            return 1;
        }
        for (int i=0;i<N;i++) {
            printf("\nPlease enter the data of the apartment: \n");
            char maxchar[50];

            printf("Name: ");
            scanf("%49s", maxchar);
            strcpy(X[i]->name, maxchar);

            printf("Owner: ");
            scanf("%49s", maxchar);
            strcpy(X[i]->owner, maxchar);

            printf("Street name: ");
            scanf("%49s", maxchar);
            strcpy(X[i]->street, maxchar);

            do {
                printf("Rent: ");
                scanf("%f",&X[i]->rent );
            }while (X[i]->rent < 0);

            do {
            printf("Amount of rooms: ");
            scanf("%d", &X[i]->rooms);
            }while (X[i]->rooms<=0);

            do {
            printf("Apartment number: ");
            scanf("%d",&X[i]->number);
            }while (X[i]->number<0);

                unsigned char available = 'a';
            do {

                printf("Is the room available: Y/N\n");
                scanf(" %c", &available);

                switch (toupper(available)) {
                    case 'Y':

                        X[i]->booked = true;
                        break;
                    case 'N':

                        X[i]->booked = false;
                        break;
                    default:
                        printf("please enter Y or N\n");
                }
            }while (toupper(available) !='N' && toupper(available) != 'Y');
            printf("%d addition has been made!\n",i+1);
        }
    char choice;
    do {
        printf("Do you wish to add more flats: (Y/N)?");
        scanf(" %c", &choice);
        switch (toupper(choice)) {
            case 'Y':
                int xtra=0;

                do {
                    printf("processing request");
                    for (int i=0;i<3;i++) {
                        _sleep(1);
                        printf(".");
                        fflush(stdout);
                    }

                    printf("How many more apartments do you wish to add: ");
                    scanf("%d",&xtra );
                }while (xtra<=0);

                flat *storagex =realloc(*X,(N+xtra)*sizeof(flat));
                if (storagex == NULL) {
                    fprintf(stdout,"Out of memory\n");
                    return 404;
                }

                *X = storagex;
                char maxchar[50];

                for (int i=N;i<(N+xtra);i++) {
                    printf("\nPlease enter the data of the apartment: \n");


                    printf("Name: ");
                    scanf(" %49s", maxchar);
                    strcpy((*X)[i].name, maxchar); //after being realloced X needs to be adressed as (*X)[i].name
                    //or we can define a locar variable to just change the X for the new name Flat *NewX = *X ->  NewX[i].lerolero
                    //because of * inception in realloc we use *X
                    printf("Owner: ");
                    scanf(" %49s", maxchar);
                    strcpy((*X)[i].owner, maxchar);

                    printf("Street name: ");
                    scanf(" %49s", maxchar);
                    strcpy((*X)[i].street, maxchar);

                    do {
                        printf("Rent: ");
                        scanf("%f",&(*X)[i].rent );
                    }while ((*X)[i].rent < 0);

                    do {
                        printf("Amount of rooms: ");
                        scanf("%d", &(*X)[i].rooms);
                    }while ((*X)[i].rooms<=0);

                    do {
                        printf("Apartment number: ");
                        scanf("%d", &(*X)[i].number);
                    }while ((*X)[i].number<0);
                    unsigned char available = 'a';
                    do {

                        printf("Is the room available: Y/N\n");
                        scanf(" %c", &available);

                        switch (toupper(available)) {
                            case 'Y':

                                (*X)[i].booked = true;
                                break;
                            case 'N':

                                (*X)[i].booked = false;
                                break;
                            default:
                                printf("please enter Y or N\n");
                        }
                    }while (toupper(available) !='N' && toupper(available) != 'Y');
                    printf("%d addition has been made!\n",i+1);
                }


                break;


            case 'N':
                FILE *fp= fopen(filename,"a");
                if (fp==NULL) {
                    fprintf(stdout,"couldn't open file");
                    free(*X);
                    return 404;
                }

                for (int i=0;i<N+xtra;i++) {

                    fprintf(fp,"%d %d %s %s %d %s %.2f\n",(*X)[i].number,(*X)[i].rooms,(*X)[i].name,(*X)[i].owner,
                        (*X)[i].booked,(*X)[i].street, (*X)[i].rent);
                }
                printf("freeing memory");
                for (int i=0;i<3;i++) {
                    _sleep(1);
                    printf(".");
                    fflush(stdout);
                }
                free(*X);
                free(storagex);
                fclose(fp);
                printf("Thanks for adding files");
                return 2;

            default:
                printf("please enter Y or N\n");
        }
    }while (choice != 'Y');
        FILE *fp= fopen(filename,"a");
        if (fp==NULL) {
            perror("couldn't open file");
            free(*X);
        }

    for (int i=0;i<N;i++) {
        fprintf(fp,"%d %d %s %s %d %s %.2f\n",X[i]->number,X[i]->rooms,X[i]->name,X[i]->owner,
            X[i]->booked,X[i]->street, X[i]->rent);
    }
    free(X);
fclose(fp);
  //  }
    return 1;
}
/*

int WriteToFile(struct flat* X,int amount) {
    FILE *ftw = fopen(filename,"a");
    if (ftw == NULL) {
        perror("File not found\n");
        return 1;
    }
    int addammount = 1;
    int choice;
    flat rooms[]=NULL;
    flat rooms = malloc(sizeof(flat));
    flat rooms = malloc(sizeof(flat));
    int count = 1;                       // flats currently allocated
    flat room = malloc(count * sizeof(flat));
    if (room == NULL) {
        perror("malloc");
        return 1;
    }

    int choice, addammount;
    printf("Do you wish to add flats? (1 = yes): ");
    scanf("%d", &choice);
    flat *ptrn = realloc(room, (addammount) * sizeof(flat));
    switch (choice) {
        case 1:
            printf("How many apartments do you wish to add? ");
            scanf("%d", &addammount);


            if (ptrn == NULL) {
                perror("realloc");
                free(room);               // original block is still valid, so free it
                return 1;
            }
            ptr = ptrn;

        for (int i=0;i<addammount;i++) {
            printf("Enter the apartment building name: ");
            char nbuff[50];
            gets(nbuff);
            strcpy(ptrn[i].name,nbuff);
            printf("Enter the owner name: ");
            nbuff[50]='\0';
            gets(nbuff);
            strcpy(ptrn[i].owner,nbuff);

            printf("Enter its availability (0. booked/ 1. not booked): ");
            scanf("%d",&ptrn[i].booked);

            printf("Enter the street number: ");
            scanf("%d",&ptrn[i].street);

            printf("Enter the rent amount: ");
            scanf("%f",&ptrn[i].rent);

            printf("Enter the number of rooms: ");
            scanf("%d",&ptrn[i].rooms);

            printf("Enter the apartment number ");
            scanf("%d",&ptrn[i].number);

        }
        break;
        case 0;
        printf("have a good day");
        break;
        default:
            printf("Good day");
    }

    for (int i=0;i<addamount ;i++) {
        fwrite(&number,sizeof(flat),1,ftw);


       /* fprintf(file,"%d ", room[i].rooms);
        fprintf(file,"%s ", room[i].name);
        fprintf(file,"%s ", room[i].owner);
        fprintf(file,"%d ", room[i].booked);
        fprintf(file,"%s ", room[i].street);
        fprintf(file,"%1f \n", room[i].rent);

   fclose(file);
}
*/
#endif //CLASS4_HEADER3_H
