#include <stdio.h> //biblioteca de comunicaçao de usario 
#include <stdlib.h> // biblioteca de alocação de espaço em memoria
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsavel por cuidar das string

int registro() //  função responsavel por cadastrar o usuario no sistema
{
	// inicio criação de variaveis/string
	
	 char arquivo [40];
     char cpf[40];
     char nome [40];
     char sobrenome [40];
     char cargo [40];
     // final da criação das variaveis/ string
     
     printf("Digite o CPF a ser cadastrado:"); //coletando informação do usuario
     scanf("%s", cpf); // refere-se a string 
     
     strcpy(arquivo, cpf);  // responsavel por copiar os valores da string
     
     FILE *file; // cria os arquivos
     file = fopen(arquivo, "w"); // cria o arquivo e o w escreve 
     fprintf(file,cpf); // salvo o valor da variavel 
     fclose(file); // fecha o arquivo
     
     file= fopen(arquivo, "a");
     fprintf(file, ",");
     fclose(file);
     
     printf("Digite um nome a ser cadastro:");
     scanf("%s",nome);
     
     file = fopen(arquivo, "a");
     fprintf(file,nome);
     fclose(file);
     
     file= fopen(arquivo, "a");
     fprintf(file, ",");
     fclose(file);
     
     printf("Digite o sobrenome a ser cadastro:");
     scanf("%s", sobrenome);
     
     file = fopen(arquivo, "a");
     fprintf(file,sobrenome);
     fclose(file);
         
     file= fopen(arquivo, "a");
     fprintf(file, ",");
     fclose(file);
     
     printf("Digite o cargo a ser cadastrado:");
     scanf("%s", cargo);
     
     file = fopen(arquivo, "a");
     fprintf(file,cargo);
     fclose(file);
     
     system("pause");
}

int consulta()
{

				
setlocale(LC_ALL,"portuguese"); // definindo linguagem 

char cpf[40];
char conteudo[200];

printf("Digite o CPF a ser consultado:");
scanf("%s",cpf);

FILE *file;
file = fopen(cpf,"r");

if(file == NULL)
{
	printf("Não possivel abrir o arquivo, não localizado!\n");
}

while(fgets(conteudo, 200, file) != NULL)
{
	printf("\nEssas são as informações do usuário:");
	printf("%s",conteudo);
	printf("\n\n");

}
 system("pause");

}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if( file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	
	}
}

int main()
{  int opcao=0; // definindo as variáveis
   int laco=1;
    
	for(laco=1;laco=1;)
	{
	
	system("cls"); // responsavel por limpar a tela 
	
	setlocale(LC_ALL,"portuguese"); // definindo linguagem 

	
	printf("============= Cartório da EBAC ============\n\n"); // inicio do menu
	printf("============= SEJA BEM-VINDO ============= \n\n");
	printf("Escolha a opção desejada no menu:\n\n");
	printf("\t1 - Registrar nomes\n\n");
	printf("\t2 - Consultar os nomes\n\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("Opções:");
	
	scanf("%d",&opcao);

	system("cls");
	
	switch(opcao) // inicio da seleção do menu 
	{
		case 1:
		registro(); // chamada de funções
		break;
		
        case 2: 
        consulta();
        break;
	    
	    case 3:
		deletar();
		break;
    	
    	default:
    	printf("Essa opção não está disponível!\n");
    	system("pause");
    	break;
	}  // fim da seleção 
	
}
}

