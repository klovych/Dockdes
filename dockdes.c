#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY 1024
#define MAX_URL 2048

int language = 0; 

void print_ascii_art() {
    printf("\n");
    printf("  ____             _       _           \n");
    printf(" |  _ \\  ___   ___| | ____| | ___  ___ \n");
    printf(" | | | |/ _ \\ / __| |/ / _` |/ _ \\/ __|\n");
    printf(" | |_| | (_) | (__|   < (_| |  __/\\__ \\\n");
    printf(" |____/ \\___/ \\___|_|\\_\\__,_|\\___||___/\n");
    printf("               by klvy               \n");
    printf("========================================\n");
}

void print_menu() {
    if (language == 0) { 
        printf("\nChoose filters for Google Dorking:\n");
        printf("1. site: (Search within a specific site)\n");
        printf("2. filetype: (Search for specific file types)\n");
        printf("3. inurl: (Search for keywords in the URL)\n");
        printf("4. intitle: (Search for keywords in the title)\n");
        printf("5. allintext: (Search for specific text on a page)\n");
        printf("6. intext: (Search for a single word on a page)\n");
        printf("7. cache: (View cached versions of a site)\n");
        printf("0. Generate URL and exit\n");
    } else { 
        printf("\nВыберите фильтры для Google Dorking:\n");
        printf("1. site: (Поиск по сайту)\n");
        printf("2. filetype: (Поиск по типу файла)\n");
        printf("3. inurl: (Поиск по URL)\n");
        printf("4. intitle: (Поиск по заголовку страницы)\n");
        printf("5. allintext: (Поиск по тексту страницы)\n");
        printf("6. intext: (Поиск отдельного слова на странице)\n");
        printf("7. cache: (Показать кешированную версию сайта)\n");
        printf("0. Сгенерировать ссылку и выйти\n");
    }
}

void append_filter(char *query, const char *filter, const char *value) {
    if (strlen(value) > 0) {
        strcat(query, filter);
        strcat(query, value);
        strcat(query, " ");
    }
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void get_user_input(char *buffer, size_t size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; 
}

void select_language() {
    printf("Select Language / Выберите язык:\n");
    printf("1. English\n");
    printf("2. Русский\n");
    printf("Enter your choice / Введите ваш выбор: ");
    int choice;
    if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Invalid choice! Defaulting to English.\n");
        language = 0; 
    } else {
        language = choice - 1;
    }
    clear_input_buffer();
}

int main() {
    char base_url[] = "https://www.google.com/search?q=";
    char query[MAX_QUERY] = "";
    char final_url[MAX_URL] = "";
    char input[100];
    int choice;


    print_ascii_art();


    select_language();

    if (language == 0) {
        printf("=== Google Dorking Tool ===\n");
    } else {
        printf("=== Инструмент Google Dorking ===\n");
    }

    while (1) {
        print_menu();
        if (language == 0) {
            printf("\nChoose an option: ");
        } else {
            printf("\nВыберите опцию: ");
        }
        if (scanf("%d", &choice) != 1) {
            if (language == 0) {
                printf("Invalid input! Please try again.\n");
            } else {
                printf("Ошибка ввода! Попробуйте снова.\n");
            }
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();

        if (choice == 0) break;

        char value[256] = "";

        switch (choice) {
            case 1:
                if (language == 0) {
                    printf("Enter a site: ");
                } else {
                    printf("Введите сайт: ");
                }
                get_user_input(value, sizeof(value));
                append_filter(query, "site:", value);
                break;
            case 2:
                if (language == 0) {
                    printf("Enter a file type: ");
                } else {
                    printf("Введите тип файла: ");
                }
                get_user_input(value, sizeof(value));
                append_filter(query, "filetype:", value);
                break;
            case 3:
                if (language == 0) {
                    printf("Enter part of a URL: ");
                } else {
                    printf("Введите часть URL: ");
                }
                get_user_input(value, sizeof(value));
                append_filter(query, "inurl:", value);
                break;
            case 4:
                if (language == 0) {
                    printf("Enter a title keyword: ");
                } else {
                    printf("Введите заголовок: ");
                }
                get_user_input(value, sizeof(value));
                append_filter(query, "intitle:", value);
                break;
            case 5:
                if (language == 0) {
                    printf("Enter text to search for): ");
                } else {
                    printf("Введите текст для поиска: ");
                }
                get_user_input(value, sizeof(value));
                append_filter(query, "allintext:", value);
                break;
            case 6:
                if (language == 0) {
                    printf("Enter a word to search for: ");
                } else {
                    printf("Введите слово для поиска: ");
                }
                get_user_input(value, sizeof(value));
                append_filter(query, "intext:", value);
                break;
            case 7:
                if (language == 0) {
                    printf("Enter a URL to cache: ");
                } else {
                    printf("Введите URL для кеширования: ");
                }
                get_user_input(value, sizeof(value));
                append_filter(query, "cache:", value);
                break;
            default:
                if (language == 0) {
                    printf("Invalid choice! Please try again.\n");
                } else {
                    printf("Неверный выбор! Попробуйте снова.\n");
                }
        }
    }

   
    size_t len = strlen(query);
    if (len > 0 && query[len - 1] == ' ') {
        query[len - 1] = '\0';
    }

  
    snprintf(final_url, sizeof(final_url), "%s%s", base_url, query);

    if (language == 0) {
        printf("\nGenerated URL: \n%s\n", final_url);
        printf("Open this URL in your browser to perform the search.\n");
    } else {
        printf("\nСгенерированная ссылка: \n%s\n", final_url);
        printf("Откройте её в браузере для выполнения запроса.\n");
    }

    return 0;
}
