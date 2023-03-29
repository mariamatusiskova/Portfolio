//vychadzala som hlavne z prednasok a z knih Ucebnice jazyka C 1.dil a 2.dil, autor: Pavel Herout
//ospravedlnujem sa, ale nevedela som sfunkcnit funkciu rmdriver
//program je v anglickom jazyku --> snazim sa naucit pracovat s anglickymi vyrazmi, kedze aj kody su v anj

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sum(void);
void driver(void);
void lap(void);
void gender(void);
//pomocna funkcia
void m_gender(void);
//pomocna funkcia
void f_gender(void);
void brand(void);
//pomocna funkcia
void bugatti(void);
//pomocna funkcia
void porsche(void);
//pomocna funkcia
void ferrari(void);
//pomocna funkcia
void honda(void);
void year(void);
void average(void);
void under(void);
void change(void);
void newdriver(void);
//void rmdriver(void);

int main() {
   
    char function;
    int condition = 1;
    
    while (condition) {
        
        printf("\nEnter the first letter of the function:\n");
        scanf(" %c", &function);
        
        switch (function) {
            //break ukoncuje prikaz switch alebo spracovava dalsiu vetvu
            case 's' : sum(); break;
            case 'd' : driver(); break;
            case 'l' : lap(); break;
            case 'g' : gender(); break;
            case 'b' : brand(); break;
            case 'y' : year(); break;
            case 'a' : average(); break;
            case 'u' : under(); break;
            case 'c' : change(); break;
            case 'n' : newdriver(); break;
           // case 'r' : rmdriver(); break;
            case 'x' : condition = 0; break;
            //posledna vetva prepinaca
            default: if (condition == 0)
                break;
        }
    }
    
    return 0;
}
    
void sum(void) {
    
    FILE *fr = fopen("/Users/maria/Desktop/zadanie/projektskuska.csv", "r");

    if (fr == NULL) {
        printf("The file is not available.\n");
    }
    else {
        
        char row[500];
        
        while (fgets(row, 500, fr) != NULL) {
           
            char *value = strtok(row, ";");
            
            for (int i=0; i<9; i++) {
                if (i == 0) {
                    printf("%s, ", value);
                }
                else if (i == 1 || (i >= 5 && i <= 7)) {
                    printf("%s, ", value);
                }
                else if (i == 2) {
                    printf("Born: %s, ", value);
                }
                else if (i == 3) {
                    printf("Racing car: %s,\n", value);
                }
                else if (i == 4) {
                    printf("Lap Tenses: %s, ", value);
                }
                else {
                    printf("%s", value);
                }
                value = strtok(NULL, ";");
            //koniec for
            }
            putchar('\n');
        //koniec while
        }
      
        fclose(fr);
    //koniec else
    }
}

void driver(void) {
    
    char surname[20];
    
    printf("Enter the driver's last name:\n");
    scanf("%s", surname);
    
    FILE *fr = fopen("/Users/maria/Desktop/zadanie/projektskuska.csv", "r");

    if (fr == NULL) {
        printf("The file is not available.\n");
    }
    else {
        
        float race_results[5];
        char row[500];
        char specificRow[500];
        
        
        while (fgets(row, 500, fr) != NULL) {
           
            strcpy(specificRow, row);
            char *value = strtok(row, " ");
            
            for (int i=0; i<9; i++) {
                if (i==1 && strcmp(surname, value) == 0) {
                    char *val = strtok(specificRow, ";");
                    
                    for (int j=0; j<9; j++) {
                        if (j == 0) {
                            printf("\n%s\n", val);
                        }
                        else if (j == 1) {
                            printf("%s, ", val);
                        }
                        else if (j == 2) {
                            printf("Born: %s\n", val);
                        }
                        else if (j == 3) {
                            printf("Racing car: %s,\n", val);
                        }
                        else if (j == 4) {
                            printf("\nLap Times: %s, ", val);
                            race_results[j-4] = atof(val);
                        }
                        else if (j >= 5 && j <= 7) {
                            printf("%s, ", val);
                            race_results[j-4] = atof(val);
                         }
                        else {
                            printf("%s\n", val);
                            race_results[j-4] = atof(val);
                        }
                        val = strtok(NULL, ";");
                    // koniec for cyklu
                    }
                    
                    float best_lap;
                    float worst_lap;
                    float average_lap;
                    
                    best_lap = 999999999.9;
                    worst_lap = 0;
                    average_lap = 0;
                    
                    
                    for (int k = 0; k < 5; k++) {
                        
                        if (best_lap > race_results[k]) {
                            best_lap = race_results[k];
                        }
                    }
                    printf("Best lap: %.3f\n", best_lap);
                    
                    for (int l = 0; l < 5; l++) {
                        
                        if (worst_lap < race_results[l]) {
                            worst_lap = race_results[l];
                        }
                    }
                    printf("Worst lap: %.3f\n", worst_lap);
                    
                    for (int m = 0; m < 5; m++) {
                        average_lap += race_results[m];
                    }
                    
                    float division = average_lap/5;
                    printf("Average lap: %.3f\n", division);
                //koniec if
                }
                value = strtok(NULL, ";");
            //koniec for cyklu
            }
        //koniec while cyklu
        }
     fclose(fr);
        
    //koniec else
    }
}

void lap(void) {
    
    FILE *fr = fopen("/Users/maria/Desktop/zadanie/projektskuska.csv", "r");
    
    if (fr == NULL) {
        printf("The file is not available.\n");
    }
    else {
            
        char row[500];
        
        int number_of_drivers = 0;
        int position_of_driver = 0;
        int number_lap = 1;
        float race_results[5];
        float best_lap_time = 9999999999.9;
        
        while (fgets(row, 500, fr) != NULL) {
            
            char *value = strtok(row, ";");
            
            for (int i=0; i<9; i++) {
                if (i == 4) {
                    race_results[i-4] = atof(value);
                }
                else if (i >= 5 && i <= 7) {
                    race_results[i-4] = atof(value);
                }
                else if (i == 8) {
                    race_results[i-4] = atof(value);
                }
                value = strtok(NULL, ";");
            //koniec for
            }
            
            float best_lap = 9999999999.9;
            int best_lap_no = 0;
            
            for (int j = 0; j < 5; j++) {
                if (best_lap > race_results[j]) {
                    best_lap = race_results[j];
                    best_lap_no = j+1;
                }
            }
            
            if (best_lap_time > best_lap) {
                best_lap_time = best_lap;
                position_of_driver = number_of_drivers;
                number_lap = best_lap_no;
            }
            
            number_of_drivers++;
        //koniec while
        }
        fclose(fr);
        
        printf("Best lap: %.3f\n", best_lap_time);
        
        FILE *fr = fopen("/Users/maria/Desktop/zadanie/projektskuska.csv", "r");

        if (fr == NULL) {
            printf("The file is not available.\n");
        }
        else {
            char specific_row[500];
            int count = 0;
            
            while (fgets(specific_row, 500, fr) != NULL) {
                
                char *val = strtok(specific_row, ";");
    
                if (count == position_of_driver) {
                        printf("Driver: %s\n", val);
                }
                
                count++;
            }
        }
        
        printf("Number of the lap: %d\n", number_lap);
        
        fclose(fr);
    }
}

void gender(void) {
    
    char gen;
    
    while(1){
        printf("Enter m (male) or f (female):\n");
        scanf(" %c", &gen);
        
        if (gen == 'm') {
            m_gender();
            break;
        }
        else if (gen == 'f') {
            f_gender();
            break;
        }
        else {
            printf("Try it again -> ");
        }
    }

}

void m_gender(void) {
    
    
    FILE *fr = fopen("/Users/maria/Desktop/zadanie/projektskuska.csv", "r");

    if (fr == NULL) {
        printf("The file is not available.\n");
    }
    else {
            
        char row[500];
        char male[] = {"m"};
        
        int ff = 0;
        int f = 0;
        int number_of_drivers = 0;
        int position_of_driver = 0;
        int number_lap = 1;
        float race_results[5];
        float best_lap_time = 9999999999.9;
        
        while (fgets(row, 500, fr) != NULL) {
            
            char *value = strtok(row, ";");
            
            for (int i=0; i<9; i++) {
                if (i == 1) {
                    if (strcmp(male, value) == 0) {
                        value = strtok(NULL, ";");
                        continue;
                    }
                    else {
                        f++;
                        break;
                    }
                }
                else if (i == 4) {
                    race_results[i-4] = atof(value);
                }
                else if (i >= 5 && i <= 7) {
                    race_results[i-4] = atof(value);
                }
                else if (i == 8) {
                    race_results[i-4] = atof(value);
                }
                value = strtok(NULL, ";");
            //koniec for
            }
            
            
            if (ff < f) {
                ff = f;
                number_of_drivers++;
                continue;
            }
            
            float best_lap = 9999999999.9;
            int best_lap_no = 0;
            
            for (int j = 0; j < 5; j++) {
                if (best_lap > race_results[j]) {
                    best_lap = race_results[j];
                    best_lap_no = j+1;
                }
            }
            
            if (best_lap_time > best_lap) {
                best_lap_time = best_lap;
                position_of_driver = number_of_drivers;
                number_lap = best_lap_no;
            }
            
            number_of_drivers++;
        //koniec while
        }
        fclose(fr);
        
        printf("Best lap: %.3f\n", best_lap_time);
        
        FILE *fr = fopen("/Users/maria/Desktop/zadanie/projektskuska.csv", "r");

        if (fr == NULL) {
            printf("The file is not available.\n");
        }
        else {
            char specific_row[500];
            int count = 0;
            
            while (fgets(specific_row, 500, fr) != NULL) {
                
                char *val = strtok(specific_row, ";");
                
                if (count == position_of_driver) {
    
                    printf("Driver: %s\n", val);
                }
                count++;
            }
        }
        
        printf("Number of the lap: %d\n", number_lap);
        
        fclose(fr);
    }
}

void f_gender(void) {
    
    FILE *fr = fopen("/Users/maria/Desktop/zadanie/projektskuska.csv", "r");

    if (fr == NULL) {
        printf("The file is not available.\n");
    }
    else {
            
        char row[500];
        char female[] = {"f"};
        
        int mm = 0;
        int m = 0;
        int number_of_drivers = 0;
        int position_of_driver= 0;
        int number_lap = 1;
        float race_results[5];
        float best_lap_time = 9999999999.9;
        
        while (fgets(row, 500, fr) != NULL) {
            
            char *value = strtok(row, ";");
            
            for (int i=0; i<9; i++) {
                if (i == 1) {
                    if (strcmp(female, value) == 0) {
                        value = strtok(NULL, ";");
                        continue;
                    }
                    else {
                        m++;
                        break;
                    }
                }
                else if (i == 4) {
                    race_results[i-4] = atof(value);
                }
                else if (i >= 5 && i <= 7) {
                    race_results[i-4] = atof(value);
                }
                else if (i == 8) {
                    race_results[i-4] = atof(value);
                }
                value = strtok(NULL, ";");
            //koniec for
            }
            
            
            if (mm < m) {
                mm = m;
                number_of_drivers++;
                continue;
            }
            
            float best_lap = 9999999999.9;
            int best_lap_no = 0;
            
            for (int j = 0; j < 5; j++) {
                if (best_lap > race_results[j]) {
                    best_lap = race_results[j];
                    best_lap_no = j+1;
                }
            }
            
            if (best_lap_time > best_lap) {
                best_lap_time = best_lap;
                position_of_driver = number_of_drivers;
                number_lap = best_lap_no;
            }
            
            number_of_drivers++;
        //koniec while
        }
        fclose(fr);
        
        printf("Best lap: %.3f\n", best_lap_time);
        
        FILE *fr = fopen("/Users/maria/Desktop/zadanie/projektskuska.csv", "r");

        if (fr == NULL) {
            printf("The file is not available.\n");
        }
        else {
            char specific_row[500];
            int count = 0;
            
            while (fgets(specific_row, 500, fr) != NULL) {
                
                char *val = strtok(specific_row, ";");
 
                    if (count == position_of_driver) {
 
                        printf("Driver: %s\n", val);
                        
                    }
                count++;
            }
        }
        
        printf("Number of the lap: %d\n", number_lap);
        
        fclose(fr);
    }
    
}

void brand(void) {
    
    bugatti();
    porsche();
    ferrari();
    honda();
    
}

void bugatti(void) {
    
    FILE *fr = fopen("/Users/maria/Desktop/zadanie/projektskuska.csv", "r");

    if (fr == NULL) {
        printf("The file is not available.\n");
    }
    else {
            
        char row[500];
        char car_b[] = {"bugatti"};
        
        int another_car = 0;
        int car = 0;
        int number_of_drivers = 0;
        int position_of_driver = 0;
        int number_lap = 1;
        float race_results[5];
        float best_lap_time = 9999999999.9;
        
        while (fgets(row, 500, fr) != NULL) {
            
            char *value = strtok(row, ";");
            
            for (int i=0; i<9; i++) {
                if (i == 3) {
                    if (strcmp(car_b, value) == 0) {
                        value = strtok(NULL, ";");
                        continue;
                    }
                    else {
                        car++;
                        break;
                    }
                }
                else if (i == 4) {
                    race_results[i-4] = atof(value);
                }
                else if (i >= 5 && i <= 7) {
                    race_results[i-4] = atof(value);
                }
                else if (i == 8) {
                    race_results[i-4] = atof(value);
                }
                value = strtok(NULL, ";");
            //koniec for
            }
            
            
            if (another_car < car) {
                another_car = car;
                number_of_drivers++;
                continue;
            }
            
            float best_lap = 9999999999.9;
            int best_lap_no = 0;
            
            for (int j = 0; j < 5; j++) {
                if (best_lap > race_results[j]) {
                    best_lap = race_results[j];
                    best_lap_no = j+1;
                }
            }
            
            if (best_lap_time > best_lap) {
                best_lap_time = best_lap;
                position_of_driver = number_of_drivers;
                number_lap = best_lap_no;
            }
            
            number_of_drivers++;
        //koniec while
        }
        fclose(fr);
        
        printf("Brand: bugatti\n");
        printf("Best lap: %.3f\n", best_lap_time);
        
        FILE *fr = fopen("/Users/maria/Desktop/zadanie/projektskuska.csv", "r");

        if (fr == NULL) {
            printf("The file is not available.\n");
        }
        else {
            char specific_row[500];
            int count = 0;
            
            while (fgets(specific_row, 500, fr) != NULL) {
                
                char *val = strtok(specific_row, ";");

                    if (count == position_of_driver) {
                            printf("Driver: %s\n", val);
                    }
                
                count++;
            }
        }
        
        printf("Number of the lap: %d\n\n", number_lap);
        
        fclose(fr);
    }
    
}

void porsche(void) {
    
    FILE *fr = fopen("/Users/maria/Desktop/zadanie/projektskuska.csv", "r");

    if (fr == NULL) {
        printf("The file is not available.\n");
    }
    else {
            
        char row[500];
        char car_p[] = {"porsche"};
        
        int another_car = 0;
        int car = 0;
        int number_of_drivers = 0;
        int position_of_driver = 0;
        int number_lap = 1;
        float race_results[5];
        float best_lap_time = 9999999999.9;
        
        while (fgets(row, 500, fr) != NULL) {
            
            char *value = strtok(row, ";");
            
            for (int i=0; i<9; i++) {
                if (i == 3) {
                    if (strcmp(car_p, value) == 0) {
                        value = strtok(NULL, ";");
                        continue;
                    }
                    else {
                        car++;
                        break;
                    }
                }
                else if (i == 4) {
                    race_results[i-4] = atof(value);
                }
                else if (i >= 5 && i <= 7) {
                    race_results[i-4] = atof(value);
                }
                else if (i == 8) {
                    race_results[i-4] = atof(value);
                }
                value = strtok(NULL, ";");
            //koniec for
            }
            
            
            if (another_car < car) {
                another_car = car;
                number_of_drivers++;
                continue;
            }
            
            float best_lap = 9999999999.9;
            int best_lap_no = 0;
            
            for (int j = 0; j < 5; j++) {
                if (best_lap > race_results[j]) {
                    best_lap = race_results[j];
                    best_lap_no = j+1;
                }
            }
            
            if (best_lap_time > best_lap) {
                best_lap_time = best_lap;
                position_of_driver = number_of_drivers;
                number_lap = best_lap_no;
            }
            
            number_of_drivers++;
        //koniec while
        }
        fclose(fr);
        
        printf("Brand: porsche\n");
        printf("Best lap: %.3f\n", best_lap_time);
        
        FILE *fr = fopen("/Users/maria/Desktop/zadanie/projektskuska.csv", "r");

        if (fr == NULL) {
            printf("The file is not available.\n");
        }
        else {
            char specific_row[500];
            int count = 0;
            
            while (fgets(specific_row, 500, fr) != NULL) {
                
                char *val = strtok(specific_row, ";");
        
                if (count == position_of_driver) {
                        printf("Driver: %s\n", val);
                }
                count++;
            }
        }
        
        printf("Number of the lap: %d\n\n", number_lap);
        
        fclose(fr);
    }
}

void ferrari(void) {
    
    FILE *fr = fopen("/Users/maria/Desktop/zadanie/projektskuska.csv", "r");

    if (fr == NULL) {
        printf("The file is not available.\n");
    }
    else {
            
        char row[500];
        char car_f[] = {"ferrari"};
        
        int another_car = 0;
        int car = 0;
        int number_of_drivers = 0;
        int position_of_driver = 0;
        int number_lap = 1;
        float race_results[5];
        float best_lap_time = 9999999999.9;
        
        while (fgets(row, 500, fr) != NULL) {
            
            char *value = strtok(row, ";");
            
            for (int i=0; i<9; i++) {
                if (i == 3) {
                    if (strcmp(car_f, value) == 0) {
                        value = strtok(NULL, ";");
                        continue;
                    }
                    else {
                        car++;
                        break;
                    }
                }
                else if (i == 4) {
                    race_results[i-4] = atof(value);
                }
                else if (i >= 5 && i <= 7) {
                    race_results[i-4] = atof(value);
                }
                else if (i == 8) {
                    race_results[i-4] = atof(value);
                }
                value = strtok(NULL, ";");
            //koniec for
            }
            
            
            if (another_car < car) {
                another_car = car;
                number_of_drivers++;
                continue;
            }
            
            float best_lap = 9999999999.9;
            int best_lap_no = 0;
            
            for (int j = 0; j < 5; j++) {
                if (best_lap > race_results[j]) {
                    best_lap = race_results[j];
                    best_lap_no = j+1;
                }
            }
            
            if (best_lap_time > best_lap) {
                best_lap_time = best_lap;
                position_of_driver = number_of_drivers;
                number_lap = best_lap_no;
            }
            
            number_of_drivers++;
        //koniec while
        }
        fclose(fr);
        
        printf("Brand: ferrari\n");
        printf("Best lap: %.3f\n", best_lap_time);
        
        FILE *fr = fopen("/Users/maria/Desktop/zadanie/projektskuska.csv", "r");

        if (fr == NULL) {
            printf("The file is not available.\n");
        }
        else {
            char specific_row[500];
            int count = 0;
            
            while (fgets(specific_row, 500, fr) != NULL) {
                
                char *val = strtok(specific_row, ";");
                
                    if (count == position_of_driver) {
                            printf("Driver: %s\n", val);
                    }
                
                count++;
            }
        }
        
        printf("Number of the lap: %d\n\n", number_lap);
        
        fclose(fr);
    }
}

void honda(void) {
    
    FILE *fr = fopen("/Users/maria/Desktop/zadanie/projektskuska.csv", "r");

    if (fr == NULL) {
        printf("The file is not available.\n");
    }
    else {
            
        char row[500];
        char car_h[] = {"honda"};
        
        int another_car = 0;
        int car = 0;
        int number_of_drivers = 0;
        int position_of_driver = 0;
        int number_lap = 1;
        float race_results[5];
        float best_lap_time = 9999999999.9;
        
        while (fgets(row, 500, fr) != NULL) {
            
            char *value = strtok(row, ";");
            
            for (int i=0; i<9; i++) {
                if (i == 3) {
                    if (strcmp(car_h, value) == 0) {
                        value = strtok(NULL, ";");
                        continue;
                    }
                    else {
                        car++;
                        break;
                    }
                }
                else if (i == 4) {
                    race_results[i-4] = atof(value);
                }
                else if (i >= 5 && i <= 7) {
                    race_results[i-4] = atof(value);
                }
                else if (i == 8) {
                    race_results[i-4] = atof(value);
                }
                value = strtok(NULL, ";");
            //koniec for
            }
            
            if (another_car < car) {
                another_car = car;
                number_of_drivers++;
                continue;
            }
            
            float best_lap = 9999999999.9;
            int best_lap_no = 0;
            
            for (int j = 0; j < 5; j++) {
                if (best_lap > race_results[j]) {
                    best_lap = race_results[j];
                    best_lap_no = j+1;
                }
            }
            
            if (best_lap_time > best_lap) {
                best_lap_time = best_lap;
                position_of_driver = number_of_drivers;
                number_lap = best_lap_no;
            }
            
            number_of_drivers++;
        //koniec while
        }
        fclose(fr);
        
        printf("Brand: honda\n");
        printf("Best lap: %.3f\n", best_lap_time);
        
        FILE *fr = fopen("/Users/maria/Desktop/zadanie/projektskuska.csv", "r");

        if (fr == NULL) {
            printf("The file is not available.\n");
        }
        else {
            char specific_row[500];
            int count = 0;
            
            while (fgets(specific_row, 500, fr) != NULL) {
                
                char *val = strtok(specific_row, ";");
                
                    if (count == position_of_driver) {
                            printf("Driver: %s\n", val);
                    }
                count++;
            }
        }
        
        printf("Number of the lap: %d\n\n", number_lap);
        
        fclose(fr);
    }
}

void year(void) {
    
    int number_of_drivers = 0;
    int position_of_driver = 0;
    int number_lap = 1;
    float best_lap_time = 9999999999.9;
    
    int born;
    
    printf("Enter the year of birth:\n");
    scanf("%d", &born);
    
    FILE *fr = fopen("/Users/maria/Desktop/zadanie/projektskuska.csv", "r");

    if (fr == NULL) {
        printf("The file is not available.\n");
    }
    else {
        
        char row[500];
        
        float race_results[5];
        int year_b;
        int different_year = 0;
        int compare = 0;
        
        while (fgets(row, 500, fr) != NULL) {
            
            char *value = strtok(row, ";");
            
            for (int i=0; i<9; i++) {
                if (i == 2) {
                    year_b = atoi(value);
                    if (born >= year_b) {
                        value = strtok(NULL, ";");
                        continue;
                    }
                    else {
                        different_year++;
                        break;
                    }
                }
                else if (i == 4) {
                    race_results[i-4] = atof(value);
                }
                else if (i >= 5 && i <= 7) {
                    race_results[i-4] = atof(value);
                }
                else if (i == 8) {
                    race_results[i-4] = atof(value);
                }
                value = strtok(NULL, ";");
            }
            
            if (compare < different_year) {
                compare = different_year;
                number_of_drivers++;
                continue;
            }
            
            float best_lap = 9999999999.9;
            int best_lap_no = 0;
            
            for (int j = 0; j < 5; j++) {
                if (best_lap > race_results[j]) {
                    best_lap = race_results[j];
                    best_lap_no = j+1;
                }
            }
            
            if (best_lap_time > best_lap) {
                best_lap_time = best_lap;
                position_of_driver = number_of_drivers;
                number_lap = best_lap_no;
            }
            
            number_of_drivers++;
        //koniec while
        }
        fclose(fr);
        
        printf("Best lap: %.3f\n", best_lap_time);
        
        FILE *fr = fopen("/Users/maria/Desktop/zadanie/projektskuska.csv", "r");

        if (fr == NULL) {
            printf("The file is not available.\n");
        }
        else {
            char specific_row[500];
            int count = 0;
            
            while (fgets(specific_row, 500, fr) != NULL) {
                
                char *val = strtok(specific_row, ";");
                
                for (int i=0; i<3; i++) {
                    if (count == position_of_driver) {
                        if (i == 0) {
                            printf("Driver: %s\n", val);
                        }
                        else if (i == 3) {
                            printf("Born: %s\n", val);
                        }
                    }
                    val = strtok(NULL, ";");
                //koniec for
                }
                count++;
            }
        }
        
        printf("Number of the lap: %d\n\n", number_lap);
        
        fclose(fr);
    }
}

void average(void) {
    
    FILE *fr = fopen("/Users/maria/Desktop/zadanie/projektskuska.csv", "r");

    if (fr == NULL) {
        printf("The file is not available.\n");
    }
    else {
        
        char row[500];
        
        float race_results[5];
        float best_average_lap = 9999999999.9;
        int number_of_drivers = 0;
        int position_of_driver = 0;
        
        while (fgets(row, 500, fr) != NULL) {
            
            char *value = strtok(row, ";");
            
            for (int i=0; i<9; i++) {
                if (i == 0) {
                    printf("%s - ", value);
                }
                else if (i == 4) {
                    race_results[i-4] = atof(value);
                }
                else if (i >= 5 && i <= 7) {
                    race_results[i-4] = atof(value);
                }
                else if (i == 8) {
                    race_results[i-4] = atof(value);
                }
                value = strtok(NULL, ";");
            //koniec for
            }
            
            float average_lap = 0;
            
            for (int j = 0; j < 5; j++) {
                average_lap += race_results[j];
            }
            
            float division = average_lap/5;
            printf("%.3f\n", division);\
                
            if (best_average_lap > division) {
                best_average_lap = division;
                position_of_driver = number_of_drivers;
            }
            
            number_of_drivers++;
        //koniec while
        }
        fclose(fr);
        
        FILE *fr = fopen("/Users/maria/Desktop/zadanie/projektskuska.csv", "r");

        if (fr == NULL) {
            printf("The file is not available.\n");
        }
        else {
            char specific_row[500];
            int count = 0;
            
            while (fgets(specific_row, 500, fr) != NULL) {
                
                char *val = strtok(specific_row, ";");
                
                    if (count == position_of_driver) {
                        
                        printf("\nBest lap:\n");
                        printf("%s - ", val);
                        printf("%.3f\n", best_average_lap);
                        
                    }

                count++;
            }

            fclose(fr);
        }
    //koniec else
    }
    
}

void under(void) {
    
    float lap_time = 0.0;

    printf("Enter the lap time:\n");
    scanf("%f", &lap_time);
    
    FILE *fr = fopen("/Users/maria/Desktop/zadanie/projektskuska.csv", "r");

    if (fr == NULL) {
        printf("The file is not available.\n");
    }
    else {
        
        char row[500];
        
        float race_results[5];
        
        while (fgets(row, 500, fr) != NULL) {
            
            char *value = strtok(row, ";");
            
            for (int i=0; i<9; i++) {
                if (i == 0) {
                    printf("\n%s - ", value);
                }
                else if (i == 4) {
                    race_results[i-4] = atof(value);
                }
                else if (i >= 5 && i <= 7) {
                    race_results[i-4] = atof(value);
                }
                else if (i == 8) {
                    race_results[i-4] = atof(value);
                }
                value = strtok(NULL, ";");
            }
            
            int laps = 1;
            int laps_counter = 0;
            
            for (int j = 0; j <= 5; j++) {
                if (lap_time >= race_results[j]) {
                    laps_counter = laps;
                    laps++;
                }
            }
            if (laps_counter == 1) {
                printf("%d lap, " , laps_counter);
            }
            else {
                printf("%d laps, " , laps_counter);
            }
                
            for (int j = 0; j <= 5; j++) {
                if (lap_time >= race_results[j]) {
                    printf("%d (%.3f) ", j+1,  race_results[j]);
                }
            }
            
        }
        fclose(fr);
    }
}
 
void change(void) {
    
    int condition = 1;
    char surname[20];
    int order;
    float lap_time;
    
    printf("Enter surname of the driver:\n");
    scanf("%s", surname);
    printf("Enter order of the lap (1-5):\n");
    scanf("%d", &order);
    
    while (condition) {
        if (order > 0 && order < 6) {
            break;
        }
        else {
            printf("Enter order of the lap (1-5):\n");
            scanf("%d", &order);
        }
    }
    
    printf("Enter new lap time:\n");
    scanf("%f", &lap_time);
 
    FILE *fr = fopen("/Users/maria/Desktop/zadanie/projektskuska.csv", "r+");

    if (fr == NULL) {
        printf("The file is not available.\n");
    }
    else {
        
        char row[500];
        long int position;
        char drivers_data[10][30];
        position = ftell(fr);
    
        while (fgets(row, 500, fr) != NULL) {
            
            int count_the_rows = 0;
            char *value = strtok(row, " ");
            
            strcpy(drivers_data[count_the_rows], value);
            count_the_rows++;
            
            for (int i = 0; i < 9; i++) {
                if (i == 0) {
                    value = strtok(NULL, ";");
                    strcpy(drivers_data[count_the_rows], value);
                    count_the_rows++;
                }
                else {
                    value = strtok(NULL, ";");
                    strcpy(drivers_data[count_the_rows], value);
                    count_the_rows++;
                }
            //koniec for
            }
            
            if (strcmp(drivers_data[1], surname) == 0) {
                int number_of_lap = order + 4;
                char new_lap[20];
                if (number_of_lap == 9) {
                    sprintf(new_lap, "%.3f\r\n", lap_time);
                }
                else {
                    sprintf(new_lap, "%.3f", lap_time);
                }
                strcpy(drivers_data[number_of_lap], new_lap);
            }
            
            long int new_position = ftell(fr);
            fseek(fr, position, SEEK_SET);
            for (int j = 0; j < 10; j++) {
                if (j == 0) {
                    fprintf(fr, "%s ", drivers_data[j]);
                }
                else if (j == 9) {
                    fprintf(fr, "%s", drivers_data[j]);
                }
                else {
                    fprintf(fr, "%s;", drivers_data[j]);
                }
            }
            position = new_position;
        //koniec while
        }
        
    fclose(fr);
    }
}

void newdriver(void) {
    
    char name[50];
    char born[20];
    char gender[20];
    char brand[20];
    char lap_time[500];
  
    
    printf("Enter name and surname of the driver:\n");
    //obsahuje vsetky znaky okrem (najdene na internete)
    scanf(" %[^\n]", name);
    printf("Enter gender m (male) or f (female):\n");
    scanf(" %s", gender);
    printf("Enter year of birth:\n");
    scanf(" %s", born);
    printf("Enter brand of the racing car:\n");
    scanf(" %s", brand);
    printf("Enter first lap time:\n");
    scanf(" %s", lap_time);
    

    FILE *fr = fopen("/Users/maria/Desktop/zadanie/projektskuska.csv", "a");

    if (fr == NULL) {
        printf("The file is not available.\n");
    }
    else {
        
        fprintf(fr, "\n");
        fprintf(fr, "%s;%s;%s;%s;%s", name, gender, born, brand, lap_time);
        
    fclose(fr);
    }
}

