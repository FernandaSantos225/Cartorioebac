#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //blioteca de alocação de espaço 
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsavél por cadastrar os usuários no sistema
{
	//Início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s",cpf); // %s refere-se a string 
	
	strcpy(arquivo,cpf); //Responsável por copiar os valores das string
	
	FILE*file; //cria arquivo
	file = fopen(arquivo,"w"); //cria arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo,"a"); //abrir arquivo para atualização
	fprintf(file,","); //adicionar uma virgula
	fclose(file); //fechar arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informção do usuário
	scanf("%s",nome); //armazenar dentro da string nome
	
	file = fopen(arquivo,"a"); //abrir aruivo para atualização
	fprintf(file,nome); //salvar na variavel nome
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo,"a"); //abrir arquivo para atualizar
	fprintf(file,","); //adicionar uma virgula
	fclose(file); //fechar arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",sobrenome); //armazenar dentro da string sobrenome
	
	file = fopen(arquivo,"a"); //abrir arquivo para atualizar
	fprintf(file,sobrenome); //adicionar sobrenome
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo,"a"); //abrir arquivo para atualizar
	fprintf(file,","); //adicionar virgula
	fclose(file); //fechar arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuário
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
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file)!=NULL);
	{
		printf("\nEssa são as infomações do usuário: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
}
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");	
	}
}

int main ()
    {
	int opcao=0;//Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	  system("cls");
	  
	  setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	 
	  printf("### Cartório da EBAC ###\n\n");//Início do menu
	  printf("Escolha a opção desejada do menu:\n\n");
	  printf("\t1- Registrar nomes\n");
	  printf("\t2- Consultar nomes\n");
	  printf("\t3- Deletar nomes\n\n");
	  printf("\t4- Sair do sistema\n\n");
	  printf("Opção:");//Fim do menu
  	 
	 scanf("%d", &opcao);//Armazenando escolha do usuário
	 
	 system("cls"); //Responsável por limpar a tela
	  
	  switch(opcao) //Início da seleção do menu
	  {
	    	case 1: //Chamada de funções
	    	registro();// Chamada de funções 
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
	    	printf("Essa opção não está disponível\n");
	    	system("pause");
	    	break;
	  		
	  	
	     }//Fim da seleção
	  
      }
    } 
