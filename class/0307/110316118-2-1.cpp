#include <stdio.h>
#include <ctype.h>
#include <unistd.h>


int main() {
    char string[] = "What is Health Informatics? "
                    "Health informatics is defined by the United States National Library of Medicine as \"the interdisciplinary study of the design, development, adoption, and application of "
                    "(information technology) IT-based innovations in healthcare services delivery, management, and planning.\" "
                    "Its applications in health include telemedicine, electronic medical records, health information systems with decision support, mHealth, data warehousing, and eLearning tools. "
                    "Health informatics makes the right information available to the right people—within and without an organization—at the right time and place, and for the right price.";
    char *head[20] = {&string[0]};
    char *end[20];
    int countHead = 1;
    int size = sizeof(string) / sizeof(char);
    for (int i = 0; i < size; i++) {
        if (string[i] == '.' && isspace(string[i + 1]) && isupper(string[i + 2]) ||
            string[i] == '?' && isspace(string[i + 1]) && isupper(string[i + 2]) ||
            string[i] == '"' && isspace(string[i + 1]) && isupper(string[i + 2])) {

            head[countHead] = &string[i + 2];
            end[countHead - 1] = &string[i + 1];
            countHead++;
        }
    }
    end[countHead - 1] = &string[size];
    for (int i = 0, j = 0; i < countHead; i++) {
        while (&head[i][j] < &end[i][0] && head[i][j] != '\0') {
            printf("%c", head[i][j]);
            j++;
        }
        j = 0;
        printf(" |\n");
    }
    return 0;
}
