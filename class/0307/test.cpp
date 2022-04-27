#include<stdio.h>
#include <ctype.h>

int main() {
    char string[] = "What is Health Informatics? Health informatics is defined by the United States National Library of Medicine as \"the interdisciplinary study of the design, development, adoption, and application of (information technology) IT-based innovations in healthcare services delivery, management, and planning.\" Its applications in health include telemedicine, electronic medical records, health information systems with decision support, mHealth, data warehousing, and eLearning tools. Health informatics makes the right information available to the right people—within and without an organization—at the right time and place, and for the right price.";
    char *head[20] = {&string[0]};
    int size = sizeof(string) / sizeof(char);
    int j = 1;
    for (int i = 0; i < size; i++) {
        if (string[i] == '.' && isspace(string[i + 1]) && (isupper(string[i + 2]) || string[i + 2] == '\0') ||
            string[i] == '?' && isspace(string[i + 1]) && (isupper(string[i + 2]) || string[i + 2] == '\0') ||
            string[i] == '"' && isspace(string[i + 1]) && (isupper(string[i + 2]) || string[i + 2] == '\0')) {
            head[j] = &string[i + 2];
            j++;
            string[i + 1] = '\0';
        } else if (string[i] == '.' && string[i + 1] == '"' && isspace(string[i + 2]) && (isupper(string[i + 3]) || string[i + 3] == '\0') ||
                   string[i] == '?' && string[i + 1] == '"' && isspace(string[i + 2]) && (isupper(string[i + 3]) || string[i + 3] == '\0') ||
                   string[i] == '"' && string[i + 1] == '"' && isspace(string[i + 2]) && (isupper(string[i + 3]) || string[i + 3] == '\0')){
            head[j] = &string[i + 3];
            j++;
            string[i + 2] = '\0';
        }
        else if(string[i] == '?' && string[i+1] == '\n'){
            head[j] = &string[i + 1];
            j++;
            string[i + 1] = '\0';
        }

    }
    for (int i = 0; i < j; i++) {
        printf("%s | \n", head[i]);
    }
    return 0;
}