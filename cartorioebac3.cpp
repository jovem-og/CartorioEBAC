#include <stdio.h> //biblioteca de comunica�ao de usario 
#include <stdlib.h> // biblioteca de aloca��o de espa�o em memoria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca responsavel por cuidar das string

int registro() //  fun��o responsavel por cadastrar o usuario no sistema
{
	// inicio cria��o de variaveis/string
	
	 char arquivo [40];
     char cpf[40];
     char nome [40];
     char sobrenome [40];
     char cargo [40];
     // final da cria��o das variaveis/ string
     
     printf("Digite o CPF a ser cadastrado:"); //coletando informa��o do usuario
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
	printf("N�o possivel abrir o arquivo, n�o localizado!\n");
}

while(fgets(conteudo, 200, file) != NULL)
{
	printf("\nEssas s�o as informa��es do usu�rio:");
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
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	
	}
}

int main()
{  int opcao=0; // definindo as vari�veis
   int laco=1;
    
	for(laco=1;laco=1;)
	{
	
	system("cls"); // responsavel por limpar a tela 
	
	setlocale(LC_ALL,"portuguese"); // definindo linguagem 

	
	printf("============= Cart�rio da EBAC ============\n\n"); // inicio do menu
	printf("============= SEJA BEM-VINDO ============= \n\n");
	printf("Escolha a op��o desejada no menu:\n\n");
	printf("\t1 - Registrar nomes\n\n");
	printf("\t2 - Consultar os nomes\n\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("Op��es:");
	
	scanf("%d",&opcao);

	system("cls");
	
	switch(opcao) // inicio da sele��o do menu 
	{
		case 1:
		registro(); // chamada de fun��es
		break;
		
        case 2: 
        consulta();
        break;
	    
	    case 3:
		deletar();
		break;
    	
    	default:
    	printf("Essa op��o n�o est� dispon�vel!\n");
    	system("pause");
    	break;
	}  // fim da sele��o 
	
}
}

