#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Função para executar comandos no Windows
void executar_comando(char **args) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Concatena os argumentos em uma única string para CreateProcess
    char comando[1024] = "";
    for (int i = 0; args[i] != NULL; i++) {
        strcat(comando, args[i]);
        strcat(comando, " ");
    }

    // Cria um processo para executar o comando
    if (!CreateProcess(NULL, comando, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        printf("Erro ao executar comando.\n");
    } else {
        // Aguarda o processo terminar
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
}

// Função para ler a linha de entrada do usuário
char *ler_linha() {
    char *linha = malloc(1024 * sizeof(char)); // Aloca memória para a linha
    if (linha == NULL) {
        fprintf(stderr, "Erro de alocação\n");
        exit(EXIT_FAILURE);
    }
    
    // Lê a linha da entrada padrão (stdin)
    if (fgets(linha, 1024, stdin) != NULL) {
        size_t len = strlen(linha);
        if (len > 0 && linha[len - 1] == '\n') {
            linha[len - 1] = '\0'; // Remove o caractere de nova linha
        }
    }
    return linha;
}

// Função para dividir a linha em argumentos
char **dividir_linha(char *linha) {
    int bufsize = 64, pos = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    if (!tokens) {
        fprintf(stderr, "Erro de alocação\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(linha, " \t\r\n\a");
    while (token != NULL) {
        tokens[pos] = token;
        pos++;

        if (pos >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "Erro de alocação\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[pos] = NULL;
    return tokens;
}

// Função para implementar o comando "cd"
int shell_cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "shell: esperado argumento para \"cd\"\n");
    } else {
        if (!SetCurrentDirectory(args[1])) {
            printf("Erro ao mudar diretório\n");
        }
    }
    return 1;
}

// Função para implementar o comando "mkdir"
int shell_mkdir(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "shell: esperado argumento para \"mkdir\"\n");
    } else {
        if (!CreateDirectory(args[1], NULL)) {
            printf("Erro ao criar diretório\n");
        }
    }
    return 1;
}

// Função para sair do shell
int shell_sair(char **args) {
    return 0;
}

// Função para lidar com o comando "nano" ou "vim"
int shell_editor(char **args) {
    if (args[0] == NULL) {
        fprintf(stderr, "shell: esperado argumento para \"nano\" ou \"vim\"\n");
        return 1;
    }

    executar_comando(args);
    return 1;
}

// Função para o loop principal do shell
void shell_loop() {
    char *linha;
    char **args;
    int status = 1;

    do {
        printf("> "); // Prompt do shell
        linha = ler_linha(); // Lê a linha digitada pelo usuário
        args = dividir_linha(linha); // Divide a linha em comandos/argumentos

        // Verifica o comando e chama as funções apropriadas
        if (strcmp(args[0], "cd") == 0) {
            shell_cd(args);
        } else if (strcmp(args[0], "mkdir") == 0) {
            shell_mkdir(args);
        } else if (strcmp(args[0], "nano") == 0 || strcmp(args[0], "vim") == 0) {
            shell_editor(args);
        } else if (strcmp(args[0], "sair") == 0) {
            status = shell_sair(args);
        } else {
            executar_comando(args); // Executa outros comandos externos
        }

        free(linha);
        free(args);
    } while (status);
}

int main(int argc, char **argv) {
    // Inicia o loop do shell
    shell_loop();

    return EXIT_SUCCESS;
}
