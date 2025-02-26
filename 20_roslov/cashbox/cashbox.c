#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include "ctype.h"
#include <math.h>


#define print(a) printf("%d\n", (a))
#define forik(a) for(int i = 0; i < a; i++)

typedef struct shop
{ 
    int barcode;
    char name[101];
    double price;
    double count; 
} shop;

typedef struct product
{ 
    double count; 
    char name[100];
       
} product;

char warehouse[][100] = {"банан", "яблоко", "огурцы", "помидор", "киви"};
int size_cklad = sizeof( warehouse ) / sizeof(warehouse[0]);
product test[] = {{2.0, "банан"}, {2.5, "помидор"}, {3, "киви"}};
shop *entity;
product *notes;

//  #define _CRT_SECURE__NO_WARNING
/*
    убирать последние 2 буквы
    или проверять на конце гласная или согласная
*/

int menu(){
    int action;
    printf("Выберите способ ввода данных\n");
    printf("1) Из файла\n");
    printf("2) Из строки\n");
    scanf("%d", &action);
    while (action != 1 && action != 2)
        {
            printf("Неправильный ввод\n");
            printf("Повторите ввод\n");
            scanf("%d", &action);
        }
    return action;
}

int get_n(){
    int n;
    printf("Введите количество товаров\n");
    scanf("%d", &n);
    return n;
}

void set_shop(shop entity[], int size){
    srand(100);
    int i, id_barcode = 1;
    double pri, cou;
    for (i = 0; i < size; i++){
        pri = rand() % 100 + 1;
        cou = rand() % 100 + 1;
        strcpy(entity[i].name, warehouse[i]);
        entity[i].price = pri;
        entity[i].count = cou;
        entity[i].barcode = id_barcode;
        id_barcode++;
    }
}

void parse_str(char str[], int position, product arr[]){
    double count;
    char name[100];
    char sep [10]=" ,.!;";
   char *istr;
   istr = strtok (str,sep);
   while (istr != NULL)
   {
      if (isdigit(*istr)){
        count = atol(istr);
      }else{
        strcpy(name, istr);
      }
      istr = strtok(NULL,sep);
   }
   strcpy(arr[position - 1].name, name);
   arr[position - 1].count = count;
}

void print_struct(product entity[], int size){
    for (int i = 0; i < size; i++) {
        printf("%s %lf\n", entity[i].name, entity[i].count);
    }
}

int check_product(char *str){
    //str = tolower(*str);
    // НЕ ПЕРЕВОДИТ В НИЖНИЙ РЕГИСТР
    for (int i = 0; i < size_cklad; i++){
        if(!strcmp(warehouse[i], str)){
            return 1;
        }
    }
    return 0;
}

int get_id_product(char *str){
    for (int i = 0; i < size_cklad; i++){
        if(!strcmp(str, entity[i].name)){
            return entity[i].barcode;
        }
    }
    return -1;
}

int check_tmp(product arr[], int n, char *prod){
    for (int i = 0; i < n; i++){
        if (!strcmp(arr[i].name, prod)){
            return i;
        }
    }
    return -1;

}

void print_check(product all[], int size){
    double final = 0.0;
    notes = (product*)malloc(sizeof(product)*size_cklad);
    int n = 0;
    for (int i = 0; i < size; i++){
        if (check_product(all[i].name)){
            int id = check_tmp(notes, n, all[i].name);
            if( id != -1){
                notes[id].count += all[i].count;
            }else{
                strcpy(notes[n].name, all[i].name);
                notes[n].count = all[i].count;
                n++;
            }
        }
    }
    for (int i = 0; i < size; i++){
        if (check_product(notes[i].name)){
            int id = get_id_product(notes[i].name);
            if (entity[id - 1].count >= notes[i].count){
                entity[id - 1].count -= notes[i].count;
                printf("%s.....%.2lf*%.2lf.....%.2lf\n", entity[id - 1].name, notes[i].count, entity[id - 1].price, entity[id - 1].price * notes[i].count);
                final += entity[id - 1].price * notes[i].count;
            }else if(entity[id - 1].count > 0){
                printf("%s.....%.2lf*%.2lf.....%.2lf\n", entity[id - 1].name, entity[id - 1].count, entity[id - 1].price, entity[id - 1].price * entity[id - 1].count);
                final += entity[id - 1].price * entity[id - 1].count;
                entity[id - 1].count = 0.0;
            }
        }
    }
    // for (int i = 0; i < size; i++){
    //     if (check_product(all[i].name)){
    //         int id = get_id_product(all[i].name);
    //         if (entity[id - 1].count >= all[i].count){
    //             entity[id - 1].count -= all[i].count;
    //             printf("%s.....%.2lf*%.2lf.....%.2lf\n", entity[id - 1].name, all[i].count, entity[id - 1].price, entity[id - 1].price * all[i].count);
    //             final += entity[id - 1].price * all[i].count;
    //         }else if(entity[id - 1].count > 0){
    //             printf("%s.....%.2lf*%.2lf.....%.2lf\n", entity[id - 1].name, entity[id - 1].count, entity[id - 1].price, entity[id - 1].price * entity[id - 1].count);
    //             final += entity[id - 1].price * entity[id - 1].count;
    //             entity[id - 1].count = 0.0;
    //         }
    //     }
    // }
    printf("Сумма....................%.2lf\n", final);
}


void print_cklad(shop entity[], int size){
    for (int i = 0; i < size; i++){
        printf("%d  %s %.2lf  %.2lf\n", entity[i].barcode, entity[i].name, entity[i].count, entity[i].price);
    }
}



int main(){
    entity = (shop*)malloc(sizeof(shop)*size_cklad);
    set_shop(entity, size_cklad);
    print_cklad(entity, size_cklad);
    if (menu() == 1){
        FILE *file;
        double count;
        char name[100];
        product *arr;
        file = fopen("input.txt", "r");
        int i = 0;
        while (!feof(file)) {
            fscanf(file, "%lf %s", &(count), &(name));
            i++;
        }
        arr = (product*)malloc(sizeof(product)*i);
        fseek(file, 0, SEEK_SET);
        i = 0;
        while (!feof(file)) {
            fscanf(file, "%lf %s", &(arr[i].count), &(arr[i].name));
            i++;
        }
        print_check(arr, i);
    }else{
        int n = get_n();
        product *arr;
        arr = (product*)malloc(sizeof(product)*n);
        for (int i = 0; i < n + 1; i++){
            char test[100];
            gets(test);
            parse_str(test, i, arr);
        }
        print_check(arr, n);
    }
    return 0;
    
}


/*
2 банана
Помидоры 2,5
три киви
*/

/*
5 картошка
6 яблоко
2 киви 
*/