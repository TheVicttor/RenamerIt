#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <locale.h>

int main(void)
{
    char *testepointer;
    char frase[MAX_PATH], novonome[MAX_PATH] = "", endereco[MAX_PATH];
    char letra;
    int result, contador = 1;

    HANDLE fileHandle;
    WIN32_FIND_DATA ffd;
    LARGE_INTEGER szDir;
    WIN32_FIND_DATA fileData;
    printf("Digite (Exatamente) o endereco da pasta onde deseja realizar a renomeacao de arquivos: ");
    // A entrada deve ser assim-> C:\\Users\\jvdeo\\OneDrive\\Victor\\Estudo\\Biblioteca\\Programacao\\*
    scanf("%s", &endereco);

    fileHandle = FindFirstFile(endereco, &ffd);

    fflush(stdin);

    if (INVALID_HANDLE_VALUE == fileHandle)
    {
        printf("Invalid File Handle Value \n");
    }

    printf("Digite a letra a ser deletada: ");
    scanf("%c", &letra);

    setlocale(LC_ALL, "");

    do
    {
        strcpy(frase, ffd.cFileName);
        
        if (frase[0] == letra)
        {
            char frasenova[MAX_PATH];
            memcpy(frasenova, frase, sizeof(frase));
            memmove(&frasenova[0], &frasenova[4], (sizeof(frasenova) - 1) * sizeof(frasenova[0]));

            result = rename(frase, frasenova);

            if (result == 0)
            {
                printf("O arquivo %d foi renomeado com sucesso.\n", contador);
            } 
            else
            {
                printf("O arquivo %d apresentou erro ao ser renomeado.\n", contador);
            }
        }

        contador++;

    } while (FindNextFile(fileHandle, &ffd) != 0);

    system("pause");

    return 0;
}