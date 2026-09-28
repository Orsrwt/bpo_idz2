#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * ИДЗ 2. Задание 2-3. Деобфускация.
 * Читаемая (деобфусцированная) версия программы проверки лицензионного ключа.
 * Ключ имеет формат xxxxx-xxxxx-xxxxx (3 блока по 5 символов, разделённых '-').
 *
 * Что было сделано при деобфускации:
 *  - осмысленные имена вместо наборов из l/I (iii -> normalize_key,
 *    iiii -> validate_key, lllll -> key, l/ll/lll/llll -> sum_upper/…);
 *  - удалён «мусорный» обфусцирующий код: в исходнике переменная ll = key[2]
 *    и переходы goto через метки lll/l/lllllllll образуют цепочку, условие
 *    которой (ll == key[2]) всегда истинно, то есть на логику не влияет;
 *  - именованы константы: 3 блока по 5 символов.
 */

#define BLOCKS 3
#define BLOCK_LEN 5
#define KEY_LEN (BLOCKS * BLOCK_LEN)          /* 15 значащих символов */
#define FORMATTED_LEN (KEY_LEN + (BLOCKS - 1)) /* 17 символов с двумя '-' */

/* Убирает разделители '-' из строки ключа и возвращает 15 значащих символов.
   Возвращает NULL при неверной длине или ошибке выделения памяти. */
char *normalize_key(char *formatted)
{
    if (strlen(formatted) != FORMATTED_LEN)
        return NULL;

    char *clean = (char *)malloc(KEY_LEN * sizeof(char));
    if (clean == NULL)
        return NULL;
    memset(clean, '\0', KEY_LEN);

    int j = 0;
    for (int i = 0; i < (int)strlen(formatted); i++)
    {
        if (formatted[i] != '-')
            clean[j++] = formatted[i];
    }
    return clean;
}

/* Проверяет ключ. Возвращает 0, если ключ корректен, иначе -1.

   Алгоритм: суммы sum_upper и sum_lower накапливаются НАРАСТАЮЩИМ итогом
   по всем блокам (между блоками не обнуляются). Символы с кодом < 91
   (заглавные латинские буквы и цифры) идут в sum_upper, остальные
   (строчные буквы) — в sum_lower. После каждого блока сравниваются
   ((sum_upper >> 2) & 0xF) и ((sum_lower + 1) & 0x7); при равенстве к
   accept прибавляется sum_upper, иначе к reject прибавляется sum_lower.
   Ключ верен, если accept == reject и accept != 0. */
int validate_key(char *key)
{
    if (key == NULL)
        return -1;

    int sum_upper = 0;
    int sum_lower = 0;
    int accept = 0;
    int reject = 0;

    for (int block = 0; block < BLOCKS; block++)
    {
        for (int pos = 0; pos < BLOCK_LEN; pos++)
        {
            char ch = key[BLOCK_LEN * block + pos];
            if (ch < 91)
                sum_upper += ch;
            else
                sum_lower += ch;
        }

        int left = (sum_upper >> 2) & 0xF;
        int right = (sum_lower + 1) & 0x7;

        if (left == right)
            accept += sum_upper;
        else
            reject += sum_lower;
    }

    if (accept == reject && accept != 0)
        return 0;
    return -1;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Необходимо ввести 2 аргумента - ключ в формате xxxxx-xxxxx-xxxxx.\n");
        printf("Например: \`%s GwS9t-2HSx2-gxVBc\`\n", argv[0]);
        return -1;
    }

    char *key = normalize_key(argv[1]);
    if (validate_key(key) != 0)
    {
        printf("Неверный ключ!\n");
        return -1;
    }

    printf("Программа активирована.\n");
    return 0;
}
