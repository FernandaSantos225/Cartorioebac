#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //blioteca de aloca��o de espa�o 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o responsav�l por cadastrar os usu�rios no sistema
{
	//In�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",cpf); // %s refere-se a string 
	
	strcpy(arquivo,cpf); //Respons�vel por copiar os valores das string
	
	FILE*file; //cria arquivo
	file = fopen(arquivo,"w"); //cria arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo,"a"); //abrir arquivo para atualiza��o
	fprintf(file,","); //adicionar uma virgula
	fclose(file); //fechar arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando inform��o do usu�rio
	scanf("%s",nome); //armazenar dentro da string nome
	
	file = fopen(arquivo,"a"); //abrir aruivo para atualiza��o
	fprintf(file,nome); //salvar na variavel nome
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo,"a"); //abrir arquivo para atualizar
	fprintf(file,","); //adicionar uma virgula
	fclose(file); //fechar arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",sobrenome); //armazenar dentro da string sobrenome
	
	file = fopen(arquivo,"a"); //abrir arquivo para atualizar
	fprintf(file,sobrenome); //adicionar sobrenome
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo,"a"); //abrir arquivo para atualizar
	fprintf(file,","); //adicionar virgula
	fclose(file); //fechar arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cargo); //armazenar dentro da string cargo
	
	file = fopen(arquivo,"a"); //abrir arquivo para atualizar 
	fprintf(file,cargo); //adicionar cargo
	fclose(file); //fechar arquivo
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE * file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file)!=NULL);
	{
		printf("\nEssa s�o as infoma��es do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
}
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");	
	}
}

int main ()
    {
	int opcao=0;//Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	  system("cls");
	  
	  setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	 
	  printf("### Cart�rio da EBAC ###\n\n");//In�cio do menu
	  printf("Escolha a op��o desejada do menu:\n\n");
	  printf("\t1- Registrar nomes\n");
	  printf("\t2- Consultar nomes\n");
	  printf("\t3- Deletar nomes\n\n");
	  printf("\t4- Sair do sistema\n\n");
	  printf("Op��o:");//Fim do menu
  	 
	 scanf("%d", &opcao);//Armazenando escolha do usu�rio
	 
	 system("cls"); //Respons�vel por limpar a tela
	  
	  switch(opcao) //In�cio da sele��o do menu
	  {
	    	case 1: //Chamada de fun��es
	    	registro();// Chamada de fun��es 
	    	break;
	    	
	    	case 2:
	    	consulta();
	     	break;
	    	
	    	case 3:
	    	deletar();
	    	break;
	    	
	    	case 4:
	    	printf("Obrigada por utilizar o sistema!\n");
	    	return 0;
	    	break;
	    	
	    	default: 
	    	printf("Essa op��o n�o est� dispon�vel\n");
	    	system("pause");
	    	break;
	  		
	  	
	     }//Fim da sele��o
	  
      }
    } 
