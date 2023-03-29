//
//  main.c
//  ls_projekt2
//
//  Created by Mária Matušisková on 11/04/2022.
//
// **********
//Zdroje: Zakomentovane stranky v programe, Priklady 8 a 9 od prednasajuceho Doktora Jána Zelenku a zakomentovane dve funkcie (dealokacia a z_zmazanie) od spoluziaka Adama Gabora, skupina 52, main - z mojho predosleho projektu
// chyba funkcia r
// **********

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define _CRT_SECURE_NO_WARNINGS

// mena
typedef struct meno {
    char *meno;
    char *priezvisko;
    struct meno *dalsie_meno;
} MENO;

// vseobecna
typedef struct zaznam {
    int pocitaj_mena;
    int ID_cislo;
    char *Nazov_prispevku;
    MENO *Meno_autora;
    char *Typ_prezentovania;
    int Cas_prezentovania;
    int Datum;
    struct zaznam *dalsi_zaznam;
} ZAZNAM;

ZAZNAM *n_nacitanie(FILE **fr, ZAZNAM *zaznam, ZAZNAM *node, int *pocitaj_zaznamy, int *nacitanie_prebehlo);
ZAZNAM *p_pridanie(ZAZNAM *zaznam,ZAZNAM *node, int *pocitaj_zaznamy);
ZAZNAM *a_aktualizacia(ZAZNAM *zaznam, ZAZNAM *node);
ZAZNAM *z_zmazanie(ZAZNAM *zaznam, ZAZNAM *node, int *pocitaj_zaznamy);
void v_vystup(int *pocitaj_zaznamy, ZAZNAM *data);
void h_hladat(ZAZNAM *data, int *pocitaj_zaznamy);
// pomocna funkcia
ZAZNAM *dealokacia(ZAZNAM *zaznam, ZAZNAM *node);

int main() {
    
    ZAZNAM *zaznam = NULL;
    ZAZNAM *node = NULL;
    
    int pocitaj_zaznamy = 0;
    int nacitanie_prebehlo = 0;
 
  //system("pwd");
    
    FILE *fr = NULL;
    
    char ch;
    int t = 1;
    
    while (t) {
        
        printf("\nZadaj char: ");
        scanf(" %c", &ch);
        
        switch (ch) {
                
            case 'v': v_vystup(&pocitaj_zaznamy, zaznam);
                break;
                
            case 'a': zaznam = a_aktualizacia(zaznam, node);
                break;
                
            case 'h': h_hladat(zaznam, &pocitaj_zaznamy);
                break;
                
            case 'z': zaznam = z_zmazanie(zaznam, node, &pocitaj_zaznamy);
                break;
                
            case 'p': zaznam = p_pridanie(zaznam, node, &pocitaj_zaznamy);
                break;
                
            case 'n': zaznam = n_nacitanie(&fr, zaznam, node, &pocitaj_zaznamy, &nacitanie_prebehlo);
                break;
                
            case 'k':
                
                if (nacitanie_prebehlo == 1) {
                    zaznam = dealokacia(zaznam, node);
                    nacitanie_prebehlo = 0;
                }
                
                if (fr != NULL) {
                    if (fclose(fr) == EOF) {
                        printf("\nOtvoreny subor.\n");
                    }
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

ZAZNAM *n_nacitanie(FILE **fr, ZAZNAM *zaznam, ZAZNAM *node, int *pocitaj_zaznamy, int *nacitanie_prebehlo) {
    
    int i = 0;
    
    if (*nacitanie_prebehlo == 1) {
        
        zaznam = dealokacia(zaznam, node);
        
        *nacitanie_prebehlo = 0;
    }
    
    if (*fr == NULL) {

        *fr = fopen("OrganizacnePodujatia2.txt", "r");
        i = 0;
        if (*fr == NULL) {
            printf("Zaznamy neboli nacitane!\n");
            return 0;
        }
    }
    else {
        i = -1;
    }
    
            
        rewind(*fr);
        *pocitaj_zaznamy = 0;
        int dolare = 0;
        char ch;
        
        while ((ch = fgetc(*fr)) != EOF) {
            if (ch == '$') {
                dolare += 1;
            }
        }
        rewind(*fr);
        
        *pocitaj_zaznamy = dolare/3;
        
//      *riadok prideli vyrovnavaciu pamat na ulozenie, potom pamat vsak treba uvolnit
        char *riadok = NULL;
        size_t dlzka = 0;
        ssize_t citaj;
        
        int count_names = 0;
        char *tmp_string;
        
        //node = tmp
        node = zaznam;
        // previous node
        ZAZNAM *previous_node = (ZAZNAM*)malloc(sizeof(ZAZNAM));
        
        
//      getline() zo stranky: https://linux.die.net/man/3/getline
//      getline() vracia hodnotu -1, ak sa nepodari precitat riadok
        while ((citaj = getline(&riadok, &dlzka, *fr)) != -1) {
            
            if (node == NULL && i == 0) {
                node = (ZAZNAM*)malloc(sizeof(ZAZNAM));
                zaznam = node;
            }
            else if (i == 6) {
                i = 0;
                previous_node = node;
                node = (ZAZNAM*)malloc(sizeof(ZAZNAM));
                previous_node->dalsi_zaznam = node;
            }
            else {
                i++;
            }
            
            // **************
            
            if (i == 1) {
                node->ID_cislo = atoi(riadok);
            }
            else if (i == 2) {
                tmp_string = (char*)malloc(150 * sizeof(char));
                strcpy(tmp_string, strtok(riadok, "\n"));
                node->Nazov_prispevku = tmp_string;
            }
            else if (i == 3) {
                tmp_string = (char*)malloc(200 * sizeof(char));
                strcpy(tmp_string, strtok(riadok, "\n"));
                
                node->Meno_autora = (MENO*)malloc(sizeof(MENO));
                
                node->Meno_autora = NULL;
                MENO *node_autor = node->Meno_autora;
                MENO *prev_node_autor = (MENO*)malloc(sizeof(MENO));

                char *string = strtok(tmp_string, "#");
                
                count_names = 0;
                
                while (string != NULL) {
                    
                    if (node_autor == NULL) {
                        node_autor = (MENO*)malloc(sizeof(MENO));
                        node->Meno_autora = node_autor;
                    }
                    else {
                        prev_node_autor = node_autor;
                        node_autor = (MENO*)malloc(sizeof(MENO));
                        prev_node_autor->dalsie_meno = node_autor;
                        node_autor->dalsie_meno = NULL;
                    }
                    
                    node_autor->priezvisko = (char*)malloc(200 * sizeof(char));
                    node_autor->meno = (char*)malloc(200 * sizeof(char));
                    
                    if (strchr(string, ' ')) {
                        strcpy(node_autor->priezvisko, strstr(string, " "));
                    }
//                      funkcia najdena zo stranky:
//                      https://stackoverflow.com/questions/45832469/get-the-beginning-of-a-string-until-a-given-char
                    size_t length = strcspn(string, " ");
                    strncpy(node_autor->meno, string, length);
                    
                    string = strtok(NULL, "#");
                    count_names++;
                    
                // koniec while
                }
                
                node->pocitaj_mena = count_names;
            }
            else if (i == 4) {
                tmp_string = (char*)malloc(3 * sizeof(char));
                strcpy(tmp_string, strtok(riadok, "\n"));
                node->Typ_prezentovania = tmp_string;
            }
            else if (i == 5) {
                node->Cas_prezentovania = atoi(riadok);
            }
            else if (i == 6){
                node->Datum = atoi(riadok);
            }
//      koniec while
        }
        rewind(*fr);
        
        if (riadok) {
            free(riadok);
        }
        *nacitanie_prebehlo = 1;

    printf("Nacitalo sa %d zaznamov.\n", *pocitaj_zaznamy);
    
    return zaznam;
}

void v_vystup(int *pocitaj_zaznamy, ZAZNAM *data) {
    
    if (data == NULL) {
        printf("Prazdny zoznam zaznamov.\n");
    }
    else {
        
        for (int i = 0; i < *pocitaj_zaznamy; i++) {
            
            printf("\n%d.\n", i + 1);
            printf("ID cislo: %d\n", data->ID_cislo);
            printf("Nazov prispevku: %s\n", data->Nazov_prispevku);
           
            MENO *data_autor = data->Meno_autora;
            if (data_autor == NULL) {
                printf("Zoznam mien je prazdny!\n");
            }
            else {
                printf("Mena autorov:\n");
                for (int j = 0; j < data->pocitaj_mena; j++) {
                    
                    printf("\t%d: %s", j+1, data_autor->meno);
                    printf("%s\n", data_autor->priezvisko);
                    data_autor = data_autor->dalsie_meno;
                }
            }
            printf("Typ prezentovania: %s\n", data->Typ_prezentovania);
            printf("Cas prezentovania: %d\n", data->Cas_prezentovania);
            printf("Datum: %d\n", data->Datum);
        
            data = data->dalsi_zaznam;
        }
    }
}

ZAZNAM *dealokacia(ZAZNAM *zaznam, ZAZNAM *node) {
    
    // kod od spoluziaka Adama Gabora, skupina 52
    if (node != NULL && zaznam != NULL) {
        
        node = zaznam;
        
        while (zaznam != NULL) {
            
            node = zaznam;
            zaznam = node->dalsi_zaznam;
            free(node->Nazov_prispevku);
            
            while (node->Meno_autora != NULL) {
                
                MENO *node2 = node->Meno_autora;
                node->Meno_autora = node->Meno_autora->dalsie_meno;
                free(node2->meno);
                free(node2->priezvisko);
                free(node2);
            }
            free(node->Typ_prezentovania);
            free(node);
        }
    }
    
    return zaznam;
}

ZAZNAM *p_pridanie(ZAZNAM *zaznam, ZAZNAM *node, int *pocitaj_zaznamy) {
    
    int pozicia = 0, correct = 0;
    char *tmp_string;
    char typy_prez[][4] = {{"UP"}, {"UD"}, {"PP"}, {"PD"}};
    
    printf("\nZadaj poziciu: ");
    while (1) {
        
        scanf(" %d", &pozicia);
        if (pozicia <= 0) {
            printf("Zadany udaj nie je korektny, zadaj novu poziciu: ");
        }
        else {
            break;
        }
    }
 
    int count_names = 0;
    *pocitaj_zaznamy += 1;
    //node = tmp
    node = zaznam;
    // previous node
    ZAZNAM *previous_node = (ZAZNAM*)malloc(sizeof(ZAZNAM));
    previous_node = zaznam;
    
    for (int i = 1; i <= *pocitaj_zaznamy; i++) {
        
        
        if (pozicia == i || pozicia > *pocitaj_zaznamy) {
            
            if (pozicia == 1) {
                node = (ZAZNAM*)malloc(sizeof(ZAZNAM));
                node->dalsi_zaznam = zaznam;
                zaznam = node;
                pozicia = -1;
            }
            else if (pozicia > *pocitaj_zaznamy) {
                node = (ZAZNAM*)malloc(sizeof(ZAZNAM));
                node->dalsi_zaznam = NULL;
                
                if (previous_node == NULL) {
                    zaznam = node;
                    pozicia = -1;
                }
                else {
                    while (previous_node->dalsi_zaznam != NULL) {
                        previous_node = previous_node->dalsi_zaznam;
                    }
                    previous_node->dalsi_zaznam = node;
                    pozicia = -1;
                }
            }
            else if (pozicia == i) {
                node = (ZAZNAM*)malloc(sizeof(ZAZNAM));
                node->dalsi_zaznam = previous_node->dalsi_zaznam;
                previous_node->dalsi_zaznam = node;
                
                pozicia = -1;
            }
            
            // ID_cislo
            printf("ID_cislo: ");
            while (1) {
                
                scanf(" %d", &(node->ID_cislo));
                if (node->ID_cislo % 15 == 0) {
                    break;
                }
                else {
                    printf("Zadany udaj nie je korektny, zadaj nove ID_cislo: ");
                }
            }
            
            // Nazov_prispevku
            tmp_string = (char*)malloc(150 * sizeof(char));
            printf("Nazov_prispevku: ");
            scanf(" %[^\n]s", tmp_string);
            node->Nazov_prispevku = tmp_string;
            free(tmp_string);
            
            // Meno_autora
            tmp_string = (char*)malloc(200 * sizeof(char));
            printf("Meno_autora: ");
            scanf(" %[^\n]s", tmp_string);
            node->Meno_autora = (MENO*)malloc(sizeof(MENO));
            
            node->Meno_autora = NULL;
            MENO *node_autor = node->Meno_autora;
            MENO *prev_node_autor = (MENO*)malloc(sizeof(MENO));

            char *string = strtok(tmp_string, "#");
            
            count_names = 0;
            
            while (string != NULL) {
                
                if (node_autor == NULL) {
                    node_autor = (MENO*)malloc(sizeof(MENO));
                    node->Meno_autora = node_autor;
                }
                else {
                    prev_node_autor = node_autor;
                    node_autor = (MENO*)malloc(sizeof(MENO));
                    prev_node_autor->dalsie_meno = node_autor;
                }
                
                node_autor->priezvisko = (char*)malloc(200 * sizeof(char));
                node_autor->meno = (char*)malloc(200 * sizeof(char));
                
                if (strchr(string, ' ')) {
                    strcpy(node_autor->priezvisko, strstr(string, " "));
                }
    //            funkcia najdena zo stranky:
    //              https://stackoverflow.com/questions/45832469/get-the-beginning-of-a-string-until-a-given-char
                size_t length = strcspn(string, " ");
                strncpy(node_autor->meno, string, length);
                
                string = strtok(NULL, "#");
                count_names++;
            
            node->pocitaj_mena = count_names;
            }
            
            // Typ_prezentovania
            tmp_string = (char*)malloc(3 * sizeof(char));
            
            printf("Typ_prezentovania: ");
            while (1) {
                
                scanf(" %[^\n]s", tmp_string);
                for (i = 0; i < 4; i++) {
                    if (strcmp(tmp_string, typy_prez[i]) == 0) {
                        correct = 1;
                        break;
                    }
                }
                
                if (correct == 1) {
                    break;
                }
                else {
                    printf("Zadany udaj nie je korektny, zadaj novy Typ prezentovania: ");
                }
            }
            node->Typ_prezentovania = tmp_string;
            
            // Cas_prezentovania
            printf("Cas_prezentovania: ");
            while (1) {
                
                if(scanf(" %04d", &(node->Cas_prezentovania)) != 1) {
                    scanf("%*s");
                }
                else {
                    if (node->Cas_prezentovania >= 10000 || node->Cas_prezentovania <= 1000) {
                        printf("Zadany udaj nie je korektny, zadaj novy Cas_prezentovania: ");
                    }
                    else {
                        break;
                    }
                }
            }
            
            // Datum
            printf("Datum: ");
            while (1) {
                
                if(scanf(" %d", &(node->Datum)) != 1) {
                    scanf("%*s");
                }
                else {
                    if (node->Datum >= 100000000 || node->Datum <= 10000000) {
                        printf("Zadany udaj nie je korektny, zadaj novy Datum: ");
                    }
                    else {
                        break;
                    }
                }
            }
        // koniec if
       }
        
        if (node != NULL) {
            previous_node = node;
            node = node->dalsi_zaznam;
        }
    // koniec for
    }
    return zaznam;
}

void h_hladat(ZAZNAM *data, int *pocitaj_zaznamy) {
    
    if (data == NULL) {
        printf("Prazdny zoznam zaznamov.\n");
        return;
    }
    
    char typy_prez[][4] = {{"UP"}, {"UD"}, {"PP"}, {"PD"}};
    char typ_prez[3] = {'\0'};
    int pocet_zaznamov = 0, i = 0, correct = 0;
    
    printf("\nTyp_prezentovania: ");
    while (1) {
    
        scanf(" %[^\n]s", typ_prez);
        for (i = 0; i < 4; i++) {
            if (strcmp(typ_prez, typy_prez[i]) == 0) {
                correct = 1;
                break;
            }
        }
        
        if (correct == 1) {
            break;
        }
        else {
            printf("Zadany udaj nie je korektny, zadaj novy Typ_prezentovania: ");
        }
    }
    
    for (i = 0; i < *pocitaj_zaznamy; i++) {
        
        if (strcmp(data->Typ_prezentovania, typ_prez) == 0) {
            
            printf("\n%d.\n", pocet_zaznamov + 1);
            printf("ID cislo: %d\n", data->ID_cislo);
            printf("Nazov prispevku: %s\n", data->Nazov_prispevku);
           
            MENO *data_autor = data->Meno_autora;
            if (data_autor == NULL) {
                printf("Zoznam mien je prazdny!\n");
            }
            else {
                printf("Mena autorov:\n");
                for (int j = 0; j < data->pocitaj_mena; j++) {
                    
                    printf("\t%d: %s", j+1, data_autor->meno);
                    printf("%s\n", data_autor->priezvisko);
                    data_autor = data_autor->dalsie_meno;
                }
            }
            printf("Typ prezentovania: %s\n", data->Typ_prezentovania);
            printf("Cas prezentovania: %d\n", data->Cas_prezentovania);
            printf("Datum: %d\n", data->Datum);
            
            pocet_zaznamov++;
        }
        
        if (data != NULL) {
            data = data->dalsi_zaznam;
        }
    // koniec for
    }
    
    if (pocet_zaznamov == 0) {
        printf("Pre typ: %s nie su ziadne zaznamy.\n", typ_prez);
    }
    
    return;
}

ZAZNAM *a_aktualizacia(ZAZNAM *zaznam, ZAZNAM *node) {
    
    if (zaznam == NULL) {
        printf("Prazdny zoznam zaznamov.\n");
        return zaznam;
    }
    
    node = zaznam;
    
    char typy_prez[][4] = {{"UP"}, {"UD"}, {"PP"}, {"PD"}};
    char typ_prez[3] = {'\0'};
    int i = 0, correct = 0, id_cislo = 0;
    
    printf("\nZadaj ID_cislo a novy typ_prezentovania: ");
    while (1) {
    
        scanf(" %d %[^\n]s", &id_cislo, typ_prez);
        for (i = 0; i < 4; i++) {
            if ((strcmp(typ_prez, typy_prez[i]) == 0) && (id_cislo % 15 == 0)) {
                correct = 1;
                break;
            }
        }
        
        if (correct == 1) {
            break;
        }
        else {
            printf("Zadane udaje nie su korektne, zadaj novy retazec: ");
        }
    }
    
    while (node != NULL) {
        
        if (node->ID_cislo == id_cislo) {
            
            printf("Prispevok s nazvom %s sa bude prezentovat %s [%s].\n", node->Nazov_prispevku, typ_prez, node->Typ_prezentovania);
            strcpy(node->Typ_prezentovania, typ_prez);
        }
        node = node->dalsi_zaznam;
    }
    
    return zaznam;
}

ZAZNAM *z_zmazanie(ZAZNAM *zaznam, ZAZNAM *node, int *pocitaj_zaznamy) {
    
    if (zaznam == NULL) {
        printf("Prazdny zoznam zaznamov.\n");
        return zaznam;
    }
    node = zaznam;
    
    ZAZNAM *previous_node = (ZAZNAM*)malloc(sizeof(ZAZNAM));
    previous_node = zaznam;
    
    char nacitany_autor[200] = {'\0'};
    char *tmp_meno_autora = NULL, *tmp_priezvisko_autora = NULL;
    int i = 0, l = 0, count_names = 0, position = 0;
    
    printf("Meno_autora: ");
    scanf(" %[^\n]s", nacitany_autor);
    
    https://stackoverflow.com/questions/16909302/how-to-set-a-string-to-all-lowercase
    for (i = 0; nacitany_autor[i] != '\0'; i++) {
        nacitany_autor[i] = tolower((unsigned char)nacitany_autor[i]);
    }
    
    MENO *autor = NULL;
    MENO *tmp_autor = NULL;

    tmp_autor = autor;
    MENO *prev_tmp_autor = (MENO*)malloc(sizeof(MENO));
    
    char *string = strtok(nacitany_autor, "#");
    
    while (string != NULL) {
        
        if (tmp_autor == NULL) {
            tmp_autor = (MENO*)malloc(sizeof(MENO));
            tmp_autor->dalsie_meno = autor;
            autor = tmp_autor;
        }
        else {
            prev_tmp_autor = tmp_autor;
            tmp_autor = (MENO*)malloc(sizeof(MENO));
            prev_tmp_autor->dalsie_meno = tmp_autor;
        }
        
        tmp_autor->priezvisko = (char*)malloc(200 * sizeof(char));
        tmp_autor->meno = (char*)malloc(200 * sizeof(char));
        
        if (strchr(string, ' ')) {
            strcpy(tmp_autor->priezvisko, strstr(string, " "));
        }
        
    //  funkcia najdena zo stranky:
    //  https://stackoverflow.com/questions/45832469/get-the-beginning-of-a-string-until-a-given-char
        size_t length = strcspn(string, " ");
        strncpy(tmp_autor->meno, string, length);
        
        string = strtok(NULL, "#");
        count_names++;
    }
    
    int loop_stop = *pocitaj_zaznamy, zaciatok = 0;
    for (int h = 0; h < loop_stop; h++) {
        
       if (zaciatok == 0) {
            
            if (node != NULL) {
                
                MENO *node_autor = node->Meno_autora;
                if (node_autor == NULL) {
                    printf("Zoznam mien je prazdny!\n");
                }
                else {
                    
                    for (int j = 0; j < node->pocitaj_mena; j++) {
                        
                        tmp_meno_autora = malloc(strlen(node_autor->meno) + 1);
                        tmp_priezvisko_autora = malloc(strlen(node_autor->priezvisko) + 1);
                        strcpy(tmp_meno_autora, node_autor->meno);
                        strcpy(tmp_priezvisko_autora, node_autor->priezvisko);
                        
                        // meno lower case
                        for (l = 0; tmp_meno_autora[l] != '\0'; l++) {
                            tmp_meno_autora[l] = tolower((unsigned char)tmp_meno_autora[l]);
                        }
                        
                        for (l = 0; tmp_priezvisko_autora[l] != '\0'; l++) {
                            tmp_priezvisko_autora[l] = tolower((unsigned char)tmp_priezvisko_autora[l]);
                        }
                        
                        for (int k = 0; k < count_names; k++) {
                            
                            if ((strcmp(autor->meno, tmp_meno_autora) == 0) && (strcmp(autor->priezvisko, tmp_priezvisko_autora) == 0)) {
                                position = 1;
                            }
                            
                            if (autor->dalsie_meno != NULL) {
                                autor = autor->dalsie_meno;
                            }
                        }
                        
                        if (node_autor->dalsie_meno != NULL) {
                            node_autor = node_autor->dalsie_meno;
                        }
                        
                        free(tmp_meno_autora);
                        free(tmp_priezvisko_autora);
                        tmp_meno_autora = NULL;
                        tmp_priezvisko_autora = NULL;
                    }
                }
                l = 0;
                if (position == 1) {
                    
                    printf("Zaznam %s bol vymazany.\n", node->Nazov_prispevku);
                    
                    if (node->dalsi_zaznam != NULL) {
                        
                        ZAZNAM *node2 = node;
                        
                        free(node2->Nazov_prispevku);
                        node2->Nazov_prispevku = NULL;
                        for (int s = 0; s < node2->pocitaj_mena; s++) {
                            
                            MENO *node2_autor = node2->Meno_autora;
                            node2->Meno_autora = node2->Meno_autora->dalsie_meno;
                            
                            free(node2_autor->meno);
                            free(node2_autor->priezvisko);
                            free(node2_autor);
                        }
                        free(node2->Typ_prezentovania);
                        free(node2);
                        node2 = NULL;
                    
                        *pocitaj_zaznamy -= 1;
                        l = 1;
                        position = 0;
                        node = node->dalsi_zaznam;
                        zaznam = node;
                        node = zaznam;
                        zaciatok = 1;
                    }
                }
            }
       }
        // syntax kodu od spoluziaka Adama Gabora, skupina 52
        i = 0;
        while (node->dalsi_zaznam != NULL) {
            
            MENO *node_autor = node->dalsi_zaznam->Meno_autora;
            if (node_autor == NULL) {
                printf("Zoznam mien je prazdny!\n");
            }
            else {
                
                for (int j = 0; j < node->dalsi_zaznam->pocitaj_mena; j++) {
                    
                    tmp_meno_autora = malloc(strlen(node_autor->meno) + 1);
                    tmp_priezvisko_autora = malloc(strlen(node_autor->priezvisko) + 1);
                    strcpy(tmp_meno_autora, node_autor->meno);
                    strcpy(tmp_priezvisko_autora, node_autor->priezvisko);
                    
                    // meno lower case
                    for (l = 0; tmp_meno_autora[l] != '\0'; l++) {
                        tmp_meno_autora[l] = tolower((unsigned char)tmp_meno_autora[l]);
                    }
                    
                    for (l = 0; tmp_priezvisko_autora[l] != '\0'; l++) {
                        tmp_priezvisko_autora[l] = tolower((unsigned char)tmp_priezvisko_autora[l]);
                    }
                    
                    for (int k = 0; k < count_names; k++) {
                        
                        if ((strcmp(autor->meno, tmp_meno_autora) == 0) && (strcmp(autor->priezvisko, tmp_priezvisko_autora) == 0)) {
                            position = i + 1;
                        }
                        
                        if (autor->dalsie_meno != NULL) {
                            autor = autor->dalsie_meno;
                        }
                    }
                    
                    if (node_autor->dalsie_meno != NULL) {
                        node_autor = node_autor->dalsie_meno;
                    }
                    
                    free(tmp_meno_autora);
                    free(tmp_priezvisko_autora);
                    tmp_meno_autora = NULL;
                    tmp_priezvisko_autora = NULL;
                // koniec for
                }
            // koniec else
            }
            l = 0;
            if (position != 0) {
                
                printf("Zaznam %s bol vymazany.\n", node->dalsi_zaznam->Nazov_prispevku);
                
                if (node->dalsi_zaznam != NULL) {
                    
                    ZAZNAM *node2 = node->dalsi_zaznam;
                    //zaznam = node;
                    
                    free(node2->Nazov_prispevku);
                    node2->Nazov_prispevku = NULL;
                    for (int x = 0; x < node2->pocitaj_mena; x++) {
                        
                        MENO *node2_autor = node2->Meno_autora;
                        node2->Meno_autora = node2->Meno_autora->dalsie_meno;
                        free(node2_autor->meno);
                        free(node2_autor->priezvisko);
                        free(node2_autor);
                    }
                    free(node2->Typ_prezentovania);
                    free(node2);
                    node2 = NULL;
                
                    *pocitaj_zaznamy -= 1;
                    l = 1;
                    position = 0;
                    node->dalsi_zaznam = node->dalsi_zaznam->dalsi_zaznam;
                    break;
                }
                else {
                    
                    ZAZNAM *node2 = node->dalsi_zaznam;
                    
                    free(node2->Nazov_prispevku);
                    node2->Nazov_prispevku = NULL;
                  
                    for (int p = 0; p < node2->pocitaj_mena; p++) {
                        
                        MENO *node2_autor = node2->Meno_autora;
                        node2->Meno_autora = node2->Meno_autora->dalsie_meno;
                        free(node2_autor->meno);
                        free(node2_autor->priezvisko);
                        free(node2_autor);
                        //node2_autor = node2_autor->dalsie_meno;
                    }
                    free(node2->Typ_prezentovania);
                    free(node2);
                    
                    *pocitaj_zaznamy -= 1;
                    l = 1;
                    position = 0;
                    node2 = NULL;
                    node->dalsi_zaznam = node->dalsi_zaznam;
                    break;
                }
            }
            
            if (node != NULL && l != 1) {
                node = node->dalsi_zaznam;
                previous_node = node;
            }
            i++;
        }
    }

    return zaznam;
}
