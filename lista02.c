#include <stdio.h>
#include <string.h>

// Função para trocar duas palavras no vetor
void swap(char **arr, int i, int j, int *trocas) {
    char *temp = arr[i];  // Armazena temporariamente a palavra em arr[i]
    arr[i] = arr[j];      // Substitui arr[i] pela palavra em arr[j]
    arr[j] = temp;        // Substitui arr[j] pela palavra temporária
    (*trocas)++;          // Incrementa o número de trocas
}

// Função para encontrar o pivô e particionar o vetor
int partition(char **arr, int low, int high, int *trocas) {
    char *pivot = arr[high]; // Escolhe o último elemento como pivô
    int i = low - 1;        // Inicializa um índice menor que o limite inferior

    for (int j = low; j <= high - 1; j++) {
        // Comparação de strings usando strcmp
        if (strcmp(arr[j], pivot) < 0) {
            i++;             // Incrementa o índice menor
            // Chamando a função swap para trocar as palavras
            swap(arr, i, j, trocas);
        }
    }

    // Troca a posição do pivô para colocá-lo na posição correta
    swap(arr, i + 1, high, trocas);
    return i + 1; // Retorna a posição do pivô
}

// Função principal do Quicksort
void quicksort(char **arr, int low, int high, int *trocas, int *comparacoes) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, trocas); // Encontra o pivô

        // Incrementa o número de comparações
        (*comparacoes) += high - low;

        // Classifica as sub-listas recursivamente
        quicksort(arr, low, pivotIndex - 1, trocas, comparacoes);
        quicksort(arr, pivotIndex + 1, high, trocas, comparacoes);
    }
}

int main() {
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limão", "manga", "abacate", "kiwi", "cereja", "morango", "pêssego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };

    int trocas = 0;         // Inicializa o contador de trocas
    int comparacoes = 0;    // Inicializa o contador de comparações

    int n = sizeof(arr) / sizeof(arr[0]); // Calcula o tamanho do vetor

    quicksort(arr, 0, n - 1, &trocas, &comparacoes); // Chama a função de classificação

    printf("Número de trocas: %d\n", trocas); // Imprime o número de trocas
    printf("Número de comparações: %d\n", comparacoes); // Imprime o número de comparações

    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]); // Imprime o vetor ordenado
    }

    // Gerar o arquivo de saída
    FILE *arquivoSaida;
    arquivoSaida = fopen("saida.txt", "w");

    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }

    fprintf(arquivoSaida, "Número de trocas: %d\n", trocas); // Escreve o número de trocas no arquivo
    fprintf(arquivoSaida, "Número de comparações: %d\n", comparacoes); // Escreve o número de comparações no arquivo

    fprintf(arquivoSaida, "Vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        fprintf(arquivoSaida, "%s\n", arr[i]); // Escreve o vetor ordenado no arquivo
    }

    fclose(arquivoSaida); // Fecha o arquivo de saída

    return 0; // Encerra o programa com código de sucesso
}
