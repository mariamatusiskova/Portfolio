//
//
// vychadzala som hlavne z prednasok a z knih Ucebnice jazyka C 1.dil a 2.dil, autor: Pavel Herout
// snazila som sa osetrit vsetky vstupy, pri nespravnom formate, vrati pouzivatela do mainu --> switch
//
//  main.c
//  ls_projekt1
//
//  Created by Mária Matušisková on 08/03/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

void v_vystup(FILE **fr, int *pocitaj_zaznamy, int *alokacia_prebehla, char ***pole_prispevky, char ***pole_mena, char ***pole_typ_prez, int ***pole_cas_prez, int ***pole_datumy);
// pomocna funkcia
void over_dynamicke(FILE *fr, int *pocitaj_zaznamy, int *alokacia_prebehla, char ***pole_prispevky, char ***pole_mena, char ***pole_typ_prez, int ***pole_cas_prez, int ***pole_datumy);
void o_datum(FILE **fr, int *pocitaj_zaznamy, int *alokacia_prebehla, char ***pole_prispevky, char ***pole_mena, char ***pole_typ_prez, int ***pole_cas_prez, int ***pole_datumy);
// pomocna funkcia
int cas_jeden(int *pocitaj_zaznamy, char ***pole_prispevky, char ***pole_mena, char ***pole_typ_prez, int ***kopia_pole_cas, int ***pole_datumy, int *nacitaj_datum);
// pomocna funkcia
int cas_dva(int *pocitaj_zaznamy, char ***pole_prispevky, char ***pole_mena, char ***pole_typ_prez, int ***kopia_pole_cas, int ***pole_datumy, int *nacitaj_datum);
void n_nacitanie(FILE **fr, int *pocitaj_zaznamy, int *alokacia_prebehla, char ***pole_prispevky, char ***pole_mena, char ***pole_typ_prez, int ***pole_cas_prez, int ***pole_datumy);
void s_cas(int *pocitaj_zaznamy, int *alokacia_prebehla, char ***pole_prispevky, char ***pole_mena, char ***pole_typ_prez, int ***pole_cas_prez, int ***pole_datumy);
void h_histogram(int *pocitaj_zaznamy, int *alokacia_prebehla, char ***pole_prispevky, char ***pole_mena, char ***pole_typ_prez, int ***pole_cas_prez, int ***pole_datumy);
void z_zaznam(int *pocitaj_zaznamy, int *alokacia_prebehla, char ***pole_prispevky, char ***pole_mena, char ***pole_typ_prez, int ***pole_cas_prez, int ***pole_datumy);
void p_pridat(int *pocitaj_zaznamy, int *alokacia_prebehla, char ***pole_prispevky, char ***pole_mena, char ***pole_typ_prez, int ***pole_cas_prez, int ***pole_datumy, int *novy_cas, int *novy_datum);
// pomocna funkcia
void dealokuj(int *pocitaj_zaznamy, int *alokacia_prebehla, char ***pole_prispevky, char ***pole_mena, char ***pole_typ_prez, int ***pole_cas_prez, int ***pole_datumy);
// pomocna funkcia
void realokuj(int *pocitaj_zaznamy, char ***pole_prispevky, char ***pole_mena, char ***pole_typ_prez, int ***pole_cas_prez, int ***pole_datumy);

int main() {
    
//    polia
    
    int alokacia_prebehla = 0;
    int pocitaj_zaznamy = 1;
    
    char **pole_prispevky = NULL;
    char **pole_mena = NULL;
    char **pole_typ_prez = NULL;
    int **pole_cas_prez = NULL;
    int **pole_datumy = NULL;
    
    int novy_cas = 0;
    int novy_datum = 0;
    
// system("pwd");
    
    FILE *fr = NULL;
    
    char ch;
    
    int t = 1;
    
    while (t) {
        
        scanf(" %c", &ch);
        
        switch (ch) {
                
            case 'v': v_vystup(&fr, &pocitaj_zaznamy, &alokacia_prebehla, &pole_prispevky, &pole_mena, &pole_typ_prez, &pole_cas_prez, &pole_datumy);
                break;
                
            case 'o': o_datum(&fr, &pocitaj_zaznamy, &alokacia_prebehla, &pole_prispevky, &pole_mena, &pole_typ_prez, &pole_cas_prez, &pole_datumy);
                break;
                
            case 's': s_cas(&pocitaj_zaznamy, &alokacia_prebehla, &pole_prispevky, &pole_mena, &pole_typ_prez, &pole_cas_prez, &pole_datumy);
                break;
                
            case 'h': h_histogram(&pocitaj_zaznamy, &alokacia_prebehla, &pole_prispevky, &pole_mena, &pole_typ_prez, &pole_cas_prez, &pole_datumy);
                break;
                
            case 'z': z_zaznam(&pocitaj_zaznamy, &alokacia_prebehla, &pole_prispevky, &pole_mena, &pole_typ_prez, &pole_cas_prez, &pole_datumy);
                break;
                
            case 'p': p_pridat(&pocitaj_zaznamy, &alokacia_prebehla, &pole_prispevky, &pole_mena, &pole_typ_prez, &pole_cas_prez, &pole_datumy, &novy_cas, &novy_datum);
                break;
                
            case 'n': n_nacitanie(&fr, &pocitaj_zaznamy, &alokacia_prebehla, &pole_prispevky, &pole_mena, &pole_typ_prez, &pole_cas_prez, &pole_datumy);
                break;
                
            case 'k':
                
                if (alokacia_prebehla == 1) {
                    dealokuj(&pocitaj_zaznamy, &alokacia_prebehla, &pole_prispevky, &pole_mena, &pole_typ_prez, &pole_cas_prez, &pole_datumy);
                }
               
                if (fr != NULL) {
                    
                    fclose(fr);
                    
                    if (fclose(fr) != EOF)
                        printf("\nOtvoreny subor.\n");
                }
                
                t = 0;
                break;
                
            default:  if (t == 0)
                break;
        }
        
        fflush(stdin);
        
    }
    
    return 0;
}


void v_vystup(FILE **fr, int *pocitaj_zaznamy, int *alokacia_prebehla, char ***pole_prispevky, char ***pole_mena, char ***pole_typ_prez, int ***pole_cas_prez, int ***pole_datumy) {
    
    if (*fr == NULL) {

        *fr = fopen("OrganizacnePodujatia.txt", "r");
        
        if (*fr == NULL) {
            printf("Neotvoreny subor.\n");
        }
        else {
            over_dynamicke((*fr), pocitaj_zaznamy, alokacia_prebehla, pole_prispevky, pole_mena, pole_typ_prez, pole_cas_prez, pole_datumy);
        }
        
//  koniec if
    }
    else {
        over_dynamicke((*fr), pocitaj_zaznamy, alokacia_prebehla, pole_prispevky, pole_mena, pole_typ_prez, pole_cas_prez, pole_datumy);
    }
    
}

void over_dynamicke(FILE *fr, int *pocitaj_zaznamy, int *alokacia_prebehla, char ***pole_prispevky, char ***pole_mena, char ***pole_typ_prez, int ***pole_cas_prez, int ***pole_datumy) {
    
    int i = 0;
    
    if (*alokacia_prebehla == 1) {
        
        putchar('\n');
        for (i = 0; i < *pocitaj_zaznamy; i++) {
            
            printf("Nazov prispevku: ");
            puts((*pole_prispevky)[i]);
            printf("Mena autorov: ");
            puts((*pole_mena)[i]);
            printf("Typ prezentovania: ");
            puts((*pole_typ_prez)[i]);
            printf("Cas prezentovania: ");
            printf("%d\n", *(*pole_cas_prez)[i]);
            printf("Datum: ");
            printf("%d\n", *(*pole_datumy)[i]);
            putchar('\n');
        }
//  koniec if
    }
    else {
        
//      *riadok prideli vyrovnavaciu pamat na ulozenie, potom pamat vsak treba uvolnit
        char *riadok = NULL;
        size_t dlzka = 0;
        ssize_t citaj;
        
        i = 1;
        
//      getline() zo stranky: https://linux.die.net/man/3/getline
//      getline() vracia hodnotu -1, ak sa nepodari precitat riadok
        while ((citaj = getline(&riadok, &dlzka, fr)) != -1) {
            
            if (i == 1) {
                printf("Nazov prispevku: %s", riadok);
                *pocitaj_zaznamy += 1;
                i++;
            }
            else if (i == 2) {
                printf("Mena autorov: %s", riadok);
                *pocitaj_zaznamy += 1;
                i++;
            }
            else if (i == 3) {
                printf("Typ prezentovania: %s", riadok);
                *pocitaj_zaznamy += 1;
                i++;
            }
            else if (i == 4) {
                printf("Cas prezentovania: %s", riadok);
                *pocitaj_zaznamy += 1;
                i++;
            }
            else if (i == 5) {
                printf("Datum: %s", riadok);
                *pocitaj_zaznamy += 1;
                i++;
            }
            else {
                i = 1;
                *pocitaj_zaznamy += 1;
                putchar('\n');
            }
            
//      koniec while
        }
        rewind(fr);
        
        if (riadok) {
                free(riadok);
        }
        
        *pocitaj_zaznamy /= 6;
        
//  koniec else
    }
    
}

void o_datum(FILE **fr, int *pocitaj_zaznamy, int *alokacia_prebehla, char ***pole_prispevky, char ***pole_mena, char ***pole_typ_prez, int ***pole_cas_prez, int ***pole_datumy) {
    
    int pozicia = 0;
    
    int nacitaj_datum = 0;
    
    printf("\nnapis datum:\n");
    
    while (1) {
        
        if(scanf("%d", &nacitaj_datum) != 1) {
            scanf("%*s");
        }
        else {
            if (nacitaj_datum >= 100000000 || nacitaj_datum <= 10000000) {
                return;
            }
            else {
                break;
            }
        }
    }
    
    if (*alokacia_prebehla == 1) {
        
        int **kopia_pole_cas = NULL;
        
        kopia_pole_cas = (int**) malloc(*pocitaj_zaznamy * sizeof(int *));
        
        for (int i = 0; i < *pocitaj_zaznamy; i++) {
            kopia_pole_cas[i] = (int*)malloc(4 * sizeof(int));
            
            if (kopia_pole_cas[i] == NULL) {
                 exit(0);
            }
        }
        
        for (int i = 0; i < *pocitaj_zaznamy; i++) {
            memcpy(kopia_pole_cas[i], (*pole_cas_prez)[i], *pocitaj_zaznamy);
        }
       
        for (int i = 0; i < *pocitaj_zaznamy; i++) {

            pozicia = cas_jeden(pocitaj_zaznamy, pole_prispevky, pole_mena, pole_typ_prez, &kopia_pole_cas, pole_datumy, &nacitaj_datum);
            
            if (pozicia == -1) {
                
                continue;
            }
            else {
            
                printf("\n%d\t", *(*pole_cas_prez)[pozicia]);
                printf("%s\t", (*pole_typ_prez)[pozicia]);
                printf("%s\t", (*pole_mena)[pozicia]);
                printf("%s", (*pole_prispevky)[pozicia]);
                
                *kopia_pole_cas[pozicia] = 999999999;
                
            }
            
        }
        
        putchar('\n');
        
        for (int i = 0; i < *pocitaj_zaznamy; i++) {
            
            free(kopia_pole_cas[i]);
            kopia_pole_cas[i] = NULL;
            
        }
        free(kopia_pole_cas);
        
        if (kopia_pole_cas == NULL) {
             exit(0);
        }
        
//        *******
        
        kopia_pole_cas = (int**) malloc(*pocitaj_zaznamy * sizeof(int *));
        
        for (int i = 0; i < *pocitaj_zaznamy; i++) {
            kopia_pole_cas[i] = (int*)malloc(4 * sizeof(int));
            
            if (kopia_pole_cas[i] == NULL) {
                 exit(0);
            }
        }
        
        for (int i = 0; i < *pocitaj_zaznamy; i++) {
            memcpy(kopia_pole_cas[i], (*pole_cas_prez)[i], *pocitaj_zaznamy);
        }
        
        for (int i = 0; i < *pocitaj_zaznamy; i++) {
            
            pozicia = cas_dva(pocitaj_zaznamy, pole_prispevky, pole_mena, pole_typ_prez, &kopia_pole_cas, pole_datumy, &nacitaj_datum);
            
            if (pozicia == -1) {
                
                continue;
            }
            else {
            
                printf("\n%d\t", *(*pole_cas_prez)[pozicia]);
                printf("%s\t", (*pole_typ_prez)[pozicia]);
                printf("%s\t", (*pole_mena)[pozicia]);
                printf("%s", (*pole_prispevky)[pozicia]);
                
                *kopia_pole_cas[pozicia] = 999999999;
            }
            
        }
        
        for (int i = 0; i < *pocitaj_zaznamy; i++) {
            
            free(kopia_pole_cas[i]);
            kopia_pole_cas[i] = NULL;
            
        }
        free(kopia_pole_cas);
        
        if (kopia_pole_cas == NULL) {
             exit(0);
        }
        
//      koniec if
    }
    else {
        
//      vypis zo suboru
        
        if (*fr == NULL) {
            printf("Neotvoreny subor.\n");
        }
        else {
            
            int i = 0;
            
//          docasna alokacia
                
            // pole nazvov prispevkov
            char **pole_prispevky = malloc(*pocitaj_zaznamy * sizeof(int *));
            
            for (i = 0; i < *pocitaj_zaznamy; i++) {
                pole_prispevky[i] = (char*)malloc(150 * sizeof(char));
                
                if (pole_prispevky[i] == NULL) {
                     exit(0);
                }
            }
            
            // pole mien autorov
            char **pole_mena = malloc(*pocitaj_zaznamy * sizeof(int *));
            
            for (i = 0; i < *pocitaj_zaznamy; i++) {
                pole_mena[i] = (char*)malloc(100 * sizeof(char));
                
                if (pole_mena[i] == NULL) {
                     exit(0);
                }
            }
            
            // pole typov prezentovania
            char **pole_typ_prez = malloc(*pocitaj_zaznamy * sizeof(int *));
            
            for (i = 0; i < *pocitaj_zaznamy; i++) {
                pole_typ_prez[i] = (char*)malloc(2 * sizeof(char));
                
                if (pole_typ_prez[i] == NULL) {
                     exit(0);
                }
            }
                
            // pole casov prezentovania
            int **pole_cas_prez = malloc(*pocitaj_zaznamy * sizeof(int *));
            
            for (i = 0; i < *pocitaj_zaznamy; i++) {
                pole_cas_prez[i] = (int*)malloc(4 * sizeof(int));
                
                if (pole_cas_prez[i] == NULL) {
                     exit(0);
                }
            }
            
            // pole datumov
            int **pole_datumy = malloc(*pocitaj_zaznamy * sizeof(int *));
            
            for (i = 0; i < *pocitaj_zaznamy; i++) {
                pole_datumy[i] = (int*)malloc(8 * sizeof(int));
                
                if (pole_datumy[i] == NULL) {
                     exit(0);
                }
            }
                
            // pole pre odpadu
            char **pole_odpadu = malloc(*pocitaj_zaznamy * sizeof(int *));
            
            for (i = 0; i < *pocitaj_zaznamy; i++) {
                pole_odpadu[i] = (char*)malloc(4 * sizeof(char));
                
                if (pole_odpadu[i] == NULL) {
                     exit(0);
                }
            }

//          pristup ku riadkom
                
            i = 1;
            
            int j = 0;
            
            while (!feof(*fr)) {
                
                if (i == 1) {
                    
                    fscanf(*fr, "%[^\r\n]s", pole_prispevky[j]);
                    fscanf(*fr,"%[ \n\t\r]s", pole_odpadu[j]);
                    
                }
                else if (i == 2) {
                    
                    fscanf(*fr, "%[^\r\n]s", pole_mena[j]);
                    fscanf(*fr,"%[ \n\t\r]s", pole_odpadu[j]);
                    
                }
                else if (i == 3) {
                        
                    fscanf(*fr, "%[^\r\n]s", pole_typ_prez[j]);
                    fscanf(*fr,"%[ \n\t\r]s", pole_odpadu[j]);
                    
                }
                else if (i == 4) {
                    
                    fscanf(*fr, "%d", pole_cas_prez[j]);
                    fscanf(*fr,"%[ \n\t\r]s", pole_odpadu[j]);
                    
                }
                else {
                    
                    fscanf(*fr, "%d", pole_datumy[j]);
                    fscanf(*fr,"%[ \n\t\r]s", pole_odpadu[j]);
                    j++;
                    
                }
                
                if (i == 5) {
                    i = 1;
                }
                else {
                    i++;
                }
                
//          koniec while
            }
            rewind(*fr);
            
            for (int i = 0; i < *pocitaj_zaznamy; i++) {
                
                pozicia = cas_jeden(pocitaj_zaznamy, &pole_prispevky, &pole_mena, &pole_typ_prez, &pole_cas_prez, &pole_datumy, &nacitaj_datum);
                
                if (pozicia == -1) {
                    
                    continue;
                }
                else {
                
                    printf("\n%d\t", *pole_cas_prez[pozicia]);
                    printf("%s\t", pole_typ_prez[pozicia]);
                    printf("%s\t", pole_mena[pozicia]);
                    printf("%s", pole_prispevky[pozicia]);
                    
                    *pole_cas_prez[pozicia] = 999999999;
                }
                
            }
            
            putchar('\n');
            
            for (int i = 0; i < *pocitaj_zaznamy; i++) {
                
                pozicia = cas_dva(pocitaj_zaznamy, &pole_prispevky, &pole_mena, &pole_typ_prez, &pole_cas_prez, &pole_datumy, &nacitaj_datum);
                
                if (pozicia == -1) {
                    
                    continue;
                }
                else {
                
                    printf("\n%d\t", *pole_cas_prez[pozicia]);
                    printf("%s\t", pole_typ_prez[pozicia]);
                    printf("%s\t", pole_mena[pozicia]);
                    printf("%s", pole_prispevky[pozicia]);
                    
                    *pole_cas_prez[pozicia] = 999999999;
                }
                
            }
            
//           dealokacia
            
            for (i = 0; i < *pocitaj_zaznamy; i++) {
                
                free(pole_prispevky[i]);
                pole_prispevky[i] = NULL;
                
            }
            free(pole_prispevky);
            
            if (pole_prispevky == NULL) {
                 exit(0);
            }
            
            // pole mien autorov
            for (i = 0; i < *pocitaj_zaznamy; i++) {
                
                free(pole_mena[i]);
                pole_mena[i] = NULL;
                
            }
            free(pole_mena);
            
            if (pole_mena == NULL) {
                 exit(0);
            }
            
            // pole typov prezentovania
            for (i = 0; i < *pocitaj_zaznamy; i++) {
                
                free(pole_typ_prez[i]);
                pole_typ_prez[i] = NULL;
                
            }
            free(pole_typ_prez);
            
            if (pole_typ_prez == NULL) {
                 exit(0);
            }
            
            // pole casov prezentovania
            for (i = 0; i < *pocitaj_zaznamy; i++) {
                
                free(pole_cas_prez[i]);
                pole_cas_prez[i] = NULL;
                
            }
            free(pole_cas_prez);
            
            if (pole_cas_prez == NULL) {
                 exit(0);
            }
            
            // pole datumov
            for (i = 0; i < *pocitaj_zaznamy; i++) {
                
                free(pole_datumy[i]);
                pole_datumy[i] = NULL;
                
            }
            free(pole_datumy);
            
            if (pole_datumy == NULL) {
                 exit(0);
            }
                
            for (i = 0; i < *pocitaj_zaznamy; i++) {
                
                free(pole_odpadu[i]);
                pole_odpadu[i] = NULL;
                
            }
            free(pole_odpadu);
            
            if (pole_odpadu == NULL) {
                 exit(0);
            }

//       koniec else suboru
        }

//   koniec velkeho else
    }
    
}

int cas_jeden(int *pocitaj_zaznamy, char ***pole_prispevky, char ***pole_mena, char ***pole_typ_prez, int ***kopia_pole_cas, int ***pole_datumy, int *nacitaj_datum) {
    
    int lepsi_cas = 999999999, predosly_cas = 999999999, pozicia = 0;
    
    for (int i = 0; i < *pocitaj_zaznamy; i++) {
        
        if (*(*pole_datumy)[i] == *nacitaj_datum) {
            
            if (strcmp((*pole_typ_prez)[i], "UP") == 0 || strcmp((*pole_typ_prez)[i], "UD") == 0) {
                
                if (*(*kopia_pole_cas)[i] <= predosly_cas) {
                    
                    predosly_cas = *(*kopia_pole_cas)[i];
                    
                    if (predosly_cas <= lepsi_cas) {
                        
                        lepsi_cas = *(*kopia_pole_cas)[i];
                        pozicia = i;
                    }
                    
                }
            }
        }
    }
    
    for (int i = 0; i < *pocitaj_zaznamy - 1; i++) {
        
        if (lepsi_cas >= *(*kopia_pole_cas)[i] && *(*kopia_pole_cas)[i] == *(*kopia_pole_cas)[i + 1]) {
            return -1;
        }
    }
    
    return pozicia;
}

int cas_dva(int *pocitaj_zaznamy, char ***pole_prispevky, char ***pole_mena, char ***pole_typ_prez, int ***kopia_pole_cas, int ***pole_datumy, int *nacitaj_datum) {
    
    int lepsi_cas = 999999999, predosly_cas = 999999999, pozicia = 0;
    
    for (int i = 0; i < *pocitaj_zaznamy; i++) {
        
        if (*(*pole_datumy)[i] == *nacitaj_datum) {
            
            if (strcmp((*pole_typ_prez)[i], "PP") == 0 || strcmp((*pole_typ_prez)[i], "PD") == 0)  {
                
                if (*(*kopia_pole_cas)[i] <= predosly_cas) {
                    
                    predosly_cas = *(*kopia_pole_cas)[i];
                    
                    if (predosly_cas <= lepsi_cas) {
                        
                        lepsi_cas = *(*kopia_pole_cas)[i];
                        pozicia = i;
                    }
                    
                }
            }
        }
        
    }
    
    for (int i = 0; i < *pocitaj_zaznamy - 1; i++) {
       
       if (lepsi_cas >= *(*kopia_pole_cas)[i] && *(*kopia_pole_cas)[i] == *(*kopia_pole_cas)[i + 1]) {
            return -1;
       }
    }
    
    return pozicia;
}

void n_nacitanie(FILE **fr, int *pocitaj_zaznamy, int *alokacia_prebehla, char ***pole_prispevky, char ***pole_mena, char ***pole_typ_prez, int ***pole_cas_prez, int ***pole_datumy) {
    
    if (*fr == NULL) {
        printf("Neotvoreny subor.\n");
    }
    else {
        
        int i = 0;
        
        // dealokacia
        
        if (*alokacia_prebehla == 1) {
            
            dealokuj(pocitaj_zaznamy, alokacia_prebehla, pole_prispevky, pole_mena, pole_typ_prez, pole_cas_prez, pole_datumy);
            
//      koniec if
        }
        if (*alokacia_prebehla == 0) {
            
//          pocitanie zaznamov
        
            char **pole_odpadu = NULL;
            
            *alokacia_prebehla = 1;
            
            char ch;
            
            while ((ch = fgetc(*fr)) != EOF) {
                if (ch == '\n') {
                    *pocitaj_zaznamy += 1;
                }
            }
            rewind(*fr);
            
            *pocitaj_zaznamy /= 6;
            
//          alokacia
            
            // pole nazvov prispevkov
            *pole_prispevky = malloc(*pocitaj_zaznamy * sizeof(int *));
            
            for (i = 0; i < *pocitaj_zaznamy; i++) {
                (*pole_prispevky)[i] = (char*)malloc(150 * sizeof(char));
                
                if ((*pole_prispevky)[i] == NULL) {
                     exit(0);
                }
            }
            
            // pole mien autorov
            *pole_mena = malloc(*pocitaj_zaznamy * sizeof(int *));
            
            for (i = 0; i < *pocitaj_zaznamy; i++) {
                (*pole_mena)[i] = (char*)malloc(100 * sizeof(char));
                
                if ((*pole_mena)[i] == NULL) {
                     exit(0);
                }
            }
            
            // pole typov prezentovania
            *pole_typ_prez = malloc(*pocitaj_zaznamy * sizeof(int *));
            
            for (i = 0; i < *pocitaj_zaznamy; i++) {
                (*pole_typ_prez)[i] = (char*)malloc(2 * sizeof(char));
                
                if ((*pole_typ_prez)[i] == NULL) {
                     exit(0);
                }
            }
            
            // pole casov prezentovania
            *pole_cas_prez = malloc(*pocitaj_zaznamy * sizeof(int *));
            
            for (i = 0; i < *pocitaj_zaznamy; i++) {
                (*pole_cas_prez)[i] = (int*)malloc(4 * sizeof(int));
                
                if ((*pole_cas_prez)[i] == NULL) {
                     exit(0);
                }
            }
            
            // pole datumov
            *pole_datumy = malloc(*pocitaj_zaznamy * sizeof(int *));
            
            for (i = 0; i < *pocitaj_zaznamy; i++) {
                (*pole_datumy)[i] = (int*)malloc(8 * sizeof(int));
                
                if ((*pole_datumy)[i] == NULL) {
                     exit(0);
                }
            }
            
            // pole pre odpad
            pole_odpadu = malloc(*pocitaj_zaznamy * sizeof(int *));
            
            for (i = 0; i < *pocitaj_zaznamy; i++) {
                pole_odpadu[i] = (char*)malloc(4 * sizeof(char));
                
                if (pole_odpadu[i] == NULL) {
                     exit(0);
                }
            }

//           pristup ku riadkom
            
            i = 1;
            
            int j = 0;
            
            while (!feof(*fr)) {
                
                if (i == 1) {
                    
                    fscanf(*fr, "%[^\r\n]s", (*pole_prispevky)[j]);
                    fscanf(*fr,"%[ \n\t\r]s", pole_odpadu[j]);
                    
                }
                else if (i == 2) {

                    fscanf(*fr, "%[^\r\n]s", (*pole_mena)[j]);
                    fscanf(*fr,"%[ \n\t\r]s", pole_odpadu[j]);
                    
                }
                else if (i == 3) {
                    
                    fscanf(*fr, "%[^\r\n]s", (*pole_typ_prez)[j]);
                    fscanf(*fr,"%[ \n\t\r]s", pole_odpadu[j]);
                    
                }
                else if (i == 4) {
                    
                    fscanf(*fr, "%d", (*pole_cas_prez)[j]);
                    fscanf(*fr,"%[ \n\t\r]s", pole_odpadu[j]);
                    
                }
                else {
                    
                    fscanf(*fr, "%d", (*pole_datumy)[j]);
                    fscanf(*fr,"%[ \n\t\r]s", pole_odpadu[j]);
                    j++;
                    
                }
                
                if (i == 5) {
                    i = 1;
                }
                else {
                    i++;
                }
                
//          koniec while
            }
            rewind(*fr);
            
            for (i = 0; i < *pocitaj_zaznamy; i++) {
                
                free(pole_odpadu[i]);
                pole_odpadu[i] = NULL;
                
            }
            free(pole_odpadu);
            
            if (pole_odpadu == NULL) {
                 exit(0);
            }
            
            *alokacia_prebehla = 1;
            
            printf("Nacitane data.\n");
            
        }
        
//      koniec else
    }
    
}

void dealokuj(int *pocitaj_zaznamy, int *alokacia_prebehla, char ***pole_prispevky, char ***pole_mena, char ***pole_typ_prez, int ***pole_cas_prez, int ***pole_datumy) {
    
    int i = 0;
    
    *alokacia_prebehla = 0;
    
    // pole nazvov prispevkov
    for (i = 0; i < *pocitaj_zaznamy; i++) {
        
        free((*pole_prispevky)[i]);
        (*pole_prispevky)[i] = NULL;
        
    }
    free(*pole_prispevky);
    
    if (*pole_prispevky == NULL) {
         exit(0);
    }
    
    // pole mien autorov
    for (i = 0; i < *pocitaj_zaznamy; i++) {
        
        free((*pole_mena)[i]);
        (*pole_mena)[i] = NULL;
        
    }
    free(*pole_mena);
    
    if (*pole_mena == NULL) {
         exit(0);
    }
    
    // pole typov prezentovania
    for (i = 0; i < *pocitaj_zaznamy; i++) {
        
        free((*pole_typ_prez)[i]);
        (*pole_typ_prez)[i] = NULL;
        
    }
    free(*pole_typ_prez);
    
    if (*pole_typ_prez == NULL) {
         exit(0);
    }
    
    // pole casov prezentovania
    for (i = 0; i < *pocitaj_zaznamy; i++) {
        
        free((*pole_cas_prez)[i]);
        (*pole_cas_prez)[i] = NULL;
        
    }
    free(*pole_cas_prez);
    
    if (*pole_cas_prez == NULL) {
         exit(0);
    }
    
    // pole datumov
    for (i = 0; i < *pocitaj_zaznamy; i++) {
        
        free((*pole_datumy)[i]);
        (*pole_datumy)[i] = NULL;
        
    }
    free(*pole_datumy);
    
    if (*pole_datumy == NULL) {
         exit(0);
    }
    
}

void s_cas(int *pocitaj_zaznamy, int *alokacia_prebehla, char ***pole_prispevky, char ***pole_mena, char ***pole_typ_prez, int ***pole_cas_prez, int ***pole_datumy) {
        
    int nacitaj_datum = 0;
    char napis_typ_prez[3] = {0};
    
    printf("\nnapis datum:\n");
    
    while (1) {
        
        if(scanf("%d", &nacitaj_datum) != 1) {
            scanf("%*s");
        }
        else {
            if (nacitaj_datum >= 100000000 || nacitaj_datum <= 10000000) {
                return;
            }
            else {
                break;
            }
        }
    }
    
    scanf("%s", napis_typ_prez);
    
    if (*alokacia_prebehla == 1) {
        
        for (int i = 0; i < *pocitaj_zaznamy; i++) {
            
            if (strcmp((*pole_typ_prez)[i], napis_typ_prez) == 0) {
                
                if (*(*pole_datumy)[i] == nacitaj_datum) {
                    
                    printf("\n%d\t", *(*pole_cas_prez)[i]);
                    printf("%s\t", (*pole_mena)[i]);
                    printf("%s", (*pole_prispevky)[i]);
                    
                }
                else {
                    
                    printf("Pre dany vstup neexistuju zaznamy.\n");
                    
                }
                
            }
            
//       koniec for
        }
        
//   koniec if
    }
    else {
        
        printf("Polia nie su vytvorene.\n");
        
//  koniec else
    }
    
}

void h_histogram(int *pocitaj_zaznamy, int *alokacia_prebehla, char ***pole_prispevky, char ***pole_mena, char ***pole_typ_prez, int ***pole_cas_prez, int ***pole_datumy) {
    
    if (*alokacia_prebehla == 1) {
        
        int i = 0, j = 0;
        
        int dlzka_prez = 4;
        int dlzka_casu = 6;
        int hodnota = 0;
        
        ///////////
        int prvy_cas = 8;
        int druhy_cas = 0;
        //////////////
        char typ_prez[][4] = {{"UP"}, {"UD"}, {"PP"}, {"PD"}};
        
        int **pole_pocet = malloc(dlzka_casu * sizeof(int *));
        
        for (i = 0; i < dlzka_casu; i++) {
            pole_pocet[i] = (int*)malloc(4 * sizeof(int));
            
            if (pole_pocet[i] == NULL) {
                 exit(0);
            }
        }
        
        for (i = 0; i < dlzka_casu; i++) {
            (*pole_pocet)[i] = 0;
        }
        
        putchar('\n');
        
        printf("\t\t\t\t");
        
        for (j = 0; j < dlzka_prez; j++) {
             printf("%s\t", typ_prez[j]);
        }
        
        for (i = 0; i < dlzka_casu; i++) {
            
            if (i == 0) {
                
                printf("\n0%d:00 - 0%d:59 :\t", prvy_cas, (prvy_cas + 1));
                
                for (j = 0; j < *pocitaj_zaznamy; j++) {
                    
                    hodnota = *(*pole_cas_prez)[j]/100;
                    druhy_cas = prvy_cas + 1;
                    
                    if ((prvy_cas == hodnota) || (druhy_cas == hodnota)) {
                        
                        for (int k = 0; k < dlzka_prez; k++) {
                            
                            if (strcmp((*pole_typ_prez)[j], typ_prez[k]) == 0) {
                                
                                pole_pocet[k][k] = pole_pocet[k][k] + 1;
                                
                            }
                        }
                    }
                    
                }
                
                for (j = 0; j < dlzka_prez; j++) {
                    printf("%d\t", pole_pocet[j][j]);
                }
                
                putchar('\n');
                
                for (j = 0; j < dlzka_casu; j++) {
                    pole_pocet[j][j] = 0;
                }
                
            }
            else {
                printf("%d:00 - %d:59 :\t", prvy_cas, (prvy_cas + 1));
                
                for (j = 0; j < *pocitaj_zaznamy; j++) {
                    
                    hodnota = *(*pole_cas_prez)[j]/100;
                    druhy_cas = prvy_cas + 1;
                    
                    if ((prvy_cas == hodnota) || (druhy_cas == hodnota)) {
                        
                        for (int k = 0; k < dlzka_prez; k++) {
                            
                            if (strcmp((*pole_typ_prez)[j], typ_prez[k]) == 0) {
                                
                                pole_pocet[k][k] = pole_pocet[k][k] + 1;
                                
                            }
                        }
                    }
                    
                }
                
                for (j = 0; j < dlzka_prez; j++) {
                    printf("%d\t", pole_pocet[j][j]);
                }
                
                putchar('\n');
                
                for (j = 0; j < dlzka_casu; j++) {
                    pole_pocet[j][j] = 0;
                }
            }
            
            prvy_cas += 2;
        }
        
        for (i = 0; i < *pocitaj_zaznamy; i++) {
            
            free(pole_pocet[i]);
            pole_pocet[i] = NULL;
            
        }
        free(pole_pocet);
        
        if (pole_pocet == NULL) {
             exit(0);
        }
    }
    else {
        
        printf("Polia nie su vytvorene.\n");
        
    }
    
}

void z_zaznam(int *pocitaj_zaznamy, int *alokacia_prebehla, char ***pole_prispevky, char ***pole_mena, char ***pole_typ_prez, int ***pole_cas_prez, int ***pole_datumy) {
    
    if (*alokacia_prebehla == 1) {
        
        int i = 0;
        
        int pocet_vymazanych = 0;
        
        char napis_prispevok[150] = {0};
        
        scanf(" %[^\n]150s", napis_prispevok);
        
        for (i = 0; i < *pocitaj_zaznamy; i++) {
            
            if (strcmp(napis_prispevok, (*pole_prispevky)[i]) == 0) {
                
                free((*pole_prispevky)[i]);
                (*pole_prispevky)[i] = NULL;
                
                free((*pole_mena)[i]);
                (*pole_mena)[i] = NULL;
                
                free((*pole_typ_prez)[i]);
                (*pole_typ_prez)[i] = NULL;
                
                free((*pole_cas_prez)[i]);
                (*pole_cas_prez)[i] = NULL;

                free((*pole_datumy)[i]);
                (*pole_datumy)[i] = NULL;
                
                pocet_vymazanych++;
                
//           koniec if
            }
            
//       koniec for
        }
        
        for (i = 0; i < *pocitaj_zaznamy; i++) {
            
            if((*pole_prispevky)[i] == NULL) {
                
                for(int j = i; j < *pocitaj_zaznamy; j++) {
                    
                    if ((*pole_prispevky)[j] != NULL) {
                        (*pole_prispevky)[i] = (*pole_prispevky)[j];
                        (*pole_mena)[i] = (*pole_mena)[j];
                        (*pole_typ_prez)[i] = (*pole_mena)[j];
                        (*pole_cas_prez)[i] = (*pole_cas_prez)[j];
                        (*pole_datumy)[i] = (*pole_datumy)[j];
                    }
                }
            }
        }
        
//      realokacia
        
        *pocitaj_zaznamy = *pocitaj_zaznamy - pocet_vymazanych;
        
        realokuj(pocitaj_zaznamy, pole_prispevky, pole_mena, pole_typ_prez, pole_cas_prez, pole_datumy);
        
        printf("Vymazalo sa: %d zaznamov!\n", pocet_vymazanych);
        
        
//   koniec if
    }
    else {
        
        printf("Polia nie su vytvorene.\n");
        
    }
    
}

void p_pridat(int *pocitaj_zaznamy, int *alokacia_prebehla, char ***pole_prispevky, char ***pole_mena, char ***pole_typ_prez, int ***pole_cas_prez, int ***pole_datumy, int *novy_cas, int *novy_datum) {
    
    if (*alokacia_prebehla == 1) {
        
        char *novy_prispevok = NULL;
        novy_prispevok = (char*) malloc(150 * sizeof(char));
        
        if (novy_prispevok == NULL) {
            exit(0);
        }
        
        char *nove_meno = NULL;
        nove_meno = (char*) malloc(100 * sizeof(char));
        
        if (nove_meno == NULL) {
            exit(0);
        }
        
        char *novy_typ = NULL;
        novy_typ = (char*) malloc(2 * sizeof(char));
        
        if (novy_typ == NULL) {
            exit(0);
        }
        
        int *novy_cas = NULL;
        novy_cas = (int*) malloc(4 * sizeof(int));
        
        if (novy_cas == NULL) {
            exit(0);
        }
        
        int *novy_datum = NULL;
        novy_datum = (int*) malloc(8 * sizeof(int));
        
        if (novy_datum == NULL) {
            exit(0);
        }
        
//      realokacia
        
        *pocitaj_zaznamy += 1;
        
        realokuj(pocitaj_zaznamy, pole_prispevky, pole_mena, pole_typ_prez, pole_cas_prez, pole_datumy);
        
//      scanf
        
        scanf(" %[^\n]150s", novy_prispevok);
        scanf(" %[^\n]100s", nove_meno);
        scanf(" %[^\n]2s", novy_typ);
        
        while (1) {
            
            if(scanf(" %04d", novy_cas) != 1) {
                scanf("%*s");
            }
            else {
                if (*novy_cas >= 10000 || *novy_cas <= 1000) {
                    return;
                }
                else {
                    break;
                }
            }
        }
        
        while (1) {
            
            if(scanf(" %d", novy_datum) != 1) {
                scanf("%*s");
            }
            else {
                if (*novy_datum >= 100000000 || *novy_datum <= 10000000) {
                   return;
                }
                else {
                    break;
                }
            }
        }
        
        int pozicia = *pocitaj_zaznamy - 1;
                
        strcpy((*pole_prispevky)[pozicia], novy_prispevok);
        strcpy((*pole_mena)[pozicia], nove_meno);
        strcpy((*pole_typ_prez)[pozicia], novy_typ);
        (*pole_cas_prez)[pozicia] = novy_cas;
        (*pole_datumy)[pozicia] = novy_datum;
        
//      vypis
        
        free(novy_prispevok);
        free(nove_meno);
        free(novy_typ);
        free(novy_cas);
        free(novy_datum);
        
        novy_prispevok = NULL;
        nove_meno = NULL;
        novy_typ = NULL;
        novy_cas = NULL;
        novy_datum = NULL;
        
        if ((*pole_prispevky)[pozicia] != NULL) {
            printf("Zaznam sa podario pridat.\n");
        }
        
    }
    else {
        
        printf("Polia nie su vytvorene.\n");
        
    }
    
}

void realokuj(int *pocitaj_zaznamy, char ***pole_prispevky, char ***pole_mena, char ***pole_typ_prez, int ***pole_cas_prez, int ***pole_datumy){
    
    int i = 0;
    
    // pole prispevkov
    
    *pole_prispevky = realloc(*pole_prispevky, *pocitaj_zaznamy * sizeof(char*));
    
    for (i = 0; i < *pocitaj_zaznamy; i++) {
       (*pole_prispevky)[i] = realloc((*pole_prispevky)[i], 150 * sizeof(char));
    
        if ((*pole_prispevky)[i] == NULL) {
            exit(0);
        }
    }
    
    // pole mien autorov
    
    *pole_mena = realloc(*pole_mena, *pocitaj_zaznamy * sizeof(char*));
    
    for (i = 0; i < *pocitaj_zaznamy; i++) {
        (*pole_mena)[i] = realloc((*pole_mena)[i], 100 * sizeof(char));
    
        if ((*pole_mena)[i] == NULL) {
            exit(0);
        }
    }
    
    // pole typu prezentovania
    
    *pole_typ_prez = realloc(*pole_typ_prez, *pocitaj_zaznamy *  sizeof(char*));
    
    for (i = 0; i < *pocitaj_zaznamy; i++) {
        (*pole_typ_prez)[i] = realloc((*pole_typ_prez)[i], 2 * sizeof(char));
    
        if ((*pole_typ_prez)[i] == NULL) {
            exit(0);
        }
    }
    
    // pole casov prezentovania
    
    *pole_cas_prez = realloc(*pole_cas_prez, *pocitaj_zaznamy * sizeof(int*));
    
    for (i = 0; i < *pocitaj_zaznamy; i++) {
        (*pole_cas_prez)[i] = realloc((*pole_cas_prez)[i], 4 * sizeof(int*));
    
        if ((*pole_cas_prez)[i] == NULL) {
            exit(0);
        }
    }
    
    // pole datumov
    
    *pole_datumy = realloc(*pole_datumy, *pocitaj_zaznamy * sizeof(int*));
    
    for (i = 0; i < *pocitaj_zaznamy; i++) {
        (*pole_datumy)[i] = realloc((*pole_datumy)[i], 8 * sizeof(int*));
    
        if ((*pole_datumy)[i] == NULL) {
            exit(0);
        }
    }
    
}
