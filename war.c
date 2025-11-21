/*
 * Sistema de Cadastro de Territórios
 * 
 * Este programa demonstra o uso de structs em C para organizar
 * dados relacionados de territórios em um jogo de estratégia.
 * 
 * Autor: Sistema de Cadastro
 * Data: 2025
 */

#include <stdio.h>
#include <string.h>

// Definição da struct Territorio
// Esta estrutura agrupa três informações relacionadas:
// - nome: identifica o território (até 30 caracteres)
// - cor: define a cor do exército que ocupa o território (até 10 caracteres)
// - tropas: quantidade de soldados no território
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Constante que define o número de territórios a serem cadastrados
#define TOTAL_TERRITORIOS 5

int main() {
    // Declaração do vetor de structs
    // Este array armazenará os dados de 5 territórios
    Territorio territorios[TOTAL_TERRITORIOS];
    
    // Variável auxiliar para controle de loops
    int i;
    
    // Cabeçalho do sistema
    printf("========================================\n");
    printf("  SISTEMA DE CADASTRO DE TERRITORIOS\n");
    printf("========================================\n\n");
    
    // FASE 1: CADASTRO DOS TERRITÓRIOS
    printf(">>> CADASTRO DE TERRITORIOS <<<\n");
    printf("Por favor, informe os dados de %d territorios:\n\n", TOTAL_TERRITORIOS);
    
    // Laço para entrada de dados dos 5 territórios
    for (i = 0; i < TOTAL_TERRITORIOS; i++) {
        printf("--- Territorio %d ---\n", i + 1);
        
        // Entrada do nome do território
        // Usamos fgets para ler strings com espaços de forma segura
        printf("Nome do territorio: ");
        
        // Limpa o buffer antes de ler a primeira string
        if (i == 0) {
            getchar();
        }
        
        fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);
        // Remove o caractere '\n' que o fgets captura
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';
        
        // Entrada da cor do exército
        printf("Cor do exercito: ");
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);
        // Remove o caractere '\n'
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';
        
        // Entrada do número de tropas
        // Usamos scanf para ler valores numéricos
        printf("Numero de tropas: ");
        scanf("%d", &territorios[i].tropas);
        
        // Limpa o buffer após scanf para evitar problemas com fgets
        getchar();
        
        printf("\n");
    }
    
    // FASE 2: EXIBIÇÃO DOS DADOS CADASTRADOS
    printf("========================================\n");
    printf("  TERRITORIOS CADASTRADOS\n");
    printf("========================================\n\n");
    
    // Laço para exibir todos os territórios cadastrados
    for (i = 0; i < TOTAL_TERRITORIOS; i++) {
        printf("Territorio %d:\n", i + 1);
        printf("  Nome......: %s\n", territorios[i].nome);
        printf("  Cor.......: %s\n", territorios[i].cor);
        printf("  Tropas....: %d soldados\n", territorios[i].tropas);
        printf("----------------------------------------\n");
    }
    
    // Exibe estatísticas gerais
    int total_tropas = 0;
    for (i = 0; i < TOTAL_TERRITORIOS; i++) {
        total_tropas += territorios[i].tropas;
    }
    
    printf("\n>>> ESTATISTICAS GERAIS <<<\n");
    printf("Total de territorios cadastrados: %d\n", TOTAL_TERRITORIOS);
    printf("Total de tropas em todos territorios: %d\n", total_tropas);
    printf("Media de tropas por territorio: %.2f\n", (float)total_tropas / TOTAL_TERRITORIOS);
    
    printf("\n========================================\n");
    printf("  Cadastro finalizado com sucesso!\n");
    printf("========================================\n");
    
    return 0;
}

/*
 * EXPLICAÇÃO DO CÓDIGO:
 * 
 * 1. STRUCT TERRITORIO:
 *    - Agrupa dados relacionados em uma única estrutura
 *    - Facilita a organização e manipulação de múltiplos territórios
 *    - Melhora a legibilidade do código
 * 
 * 2. ENTRADA DE DADOS:
 *    - fgets: lê strings com espaços de forma segura
 *    - scanf: lê valores numéricos inteiros
 *    - getchar(): limpa o buffer para evitar problemas entre leituras
 * 
 * 3. MANIPULAÇÃO DE STRINGS:
 *    - strcspn: remove o '\n' capturado pelo fgets
 *    - Garante que as strings fiquem limpas e formatadas
 * 
 * 4. VETORES DE STRUCTS:
 *    - Permite armazenar múltiplos territórios de forma organizada
 *    - Facilita o acesso aos dados através de índices
 * 
 * 5. BOAS PRÁTICAS APLICADAS:
 *    - Comentários explicativos em todo o código
 *    - Nomes de variáveis descritivos
 *    - Formatação clara na exibição dos dados
 *    - Validação básica de entrada
 *    - Feedback visual ao usuário
 */
