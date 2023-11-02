
// Aluno:Edvaldo Dos Santos
// Matrícula:202200025475
// Programação Imperativa
// Turma 18
// Professor: Renê Gusmão 
// arquivo de texto:"alunos.txt"
// formato de matricula:2023xxx
// *Para as alterações serem salvas no arquivo é necessário finalizar o sistema!*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//---estrutura dos alunos----//
typedef struct{
 int matricula;
 float nota1,nota2;
 float nota3,nota4;
 char nome[100];
 int turma;
 int faltas;   
} Alunos;
Alunos aluno[200];

//--------------------------//
//-funções ultilizadas----------//
void menu ();
void cadastro (Alunos aluno[]); 
void remover (Alunos aluno[]);
void atualizardados(Alunos aluno[]);
void printaralunos (Alunos aluno[]);
void aprovados( Alunos aluno[]);
void reprovadosmedia(Alunos aluno[]);
void listarporturma(Alunos aluno[]);
void reprovadosfaltas (Alunos aluno[]);
void ordenacao(Alunos aluno[]);
void salvaralunos(Alunos aluno[]);
void leralunos(Alunos aluno[]);
//---------------------------//
//---- início da função principal 
int main() {
 int i= 0,j=0,opcao;
  
  //zerando o vetor de estrutura que são valores numéricos e adicionando a string "Null" nos que são nomes//
   for (i=0;i<200;i++){
     aluno[i].matricula = 0;
     aluno[i].nota1 = 0.0;
     aluno[i].nota2 = 0.0;
     aluno[i].nota3 = 0.0;
     aluno[i].nota4 = 0.0;
     strcpy(aluno[i].nome, "NULL");
     aluno[i].turma = 0;
     aluno[i].faltas= 0;     
   }
  //----- Leitura  de dados de alunos do arquivo, se houver dados.
     leralunos(aluno);
  
  // Menu de opções sera exibido na tela
		 		menu();
		 					 			 	
  while (opcao != 10){
   
  scanf("%d",&opcao);  
      
  	// menu de opções 
   
	 switch (opcao)
	 {
     case 1: 
      system ("clear");
      cadastro(aluno);           
      menu ();
	  	break;
	  	
		 case 2:
		  system ("clear");
      remover(aluno);            
      menu ();
	  	break;
		  
		  
		 case 3: 
		  system ("clear");
      atualizardados(aluno);     	  	
      menu ();
      break;
		 
		  
		 case 4:
		  system ("clear");
      printaralunos(aluno);
       
	  	menu ();
      break;
		  
     case 5:
		  system ("clear");      
      aprovados(aluno);
      menu (); 
		  break;
     
     case 6:
		  system ("clear");         
      reprovadosmedia(aluno);
      menu ();
		  break;
     
		 case 7:
		  system ("clear");	       
      listarporturma(aluno);
      menu (); 
      break;
     case 8:
      system ("clear");	       
      reprovadosfaltas(aluno);
      menu (); 
      break;
     case 9:
      system ("clear");	       
      ordenacao(aluno);
      menu (); 
      break;
     case 10:
		  system ("clear");
      printf("Finalizando sistema ......");
      break;
     
		  default:
        system ("clear");
		    printf("Voce digitou uma opcao invalida\n");	
        menu();
		    break;
		       
		}		 
}
     salvaralunos(aluno);
  return 0;
}
// Fim da função principal//
//----------------------------

// Todas as funções ultilzadas no código 
//-------------------------------
// funcao que mostra as opções do menu
void menu (){
  printf("----------------------\n");
  printf("--------SODAC2.0------\n");
  printf("----------------------\n");
  printf("(*) Escolha uma opcao:\n ");
 
  printf("1-Cadastrar aluno\n 2-Remover aluno\n 3-Atualizar dados\n 4-Listar alunos\n 5-Listar alunos aprovados\n 6-Listar alunos reprovados por media\n 7-Listar alunos por turma\n 8-Listar alunos reprovados por faltas\n 9-Ordenacao de dados\n 10-Finalizar\n");
}
 //-----------------------------
 // funcao cadastro de matrículas 
   
 void cadastro (Alunos aluno[]){
	  	// analisando se a matricula obedece o formato e se há alguma matricula igual cadastrada
  int i = 0,matricula,indice;
	int analise,cont = 0,x=0;
    
    printf("Digite a matricula:\n");
	  scanf("%d",&matricula);
   
	  for (i= 0;i<200;i++){
	      if (aluno[i].matricula == matricula)
	    	{
	    		x++;
	      }
      }
    
	      analise = (matricula - 2023000);
	  if (x > 0){
 	 	printf("já existe um cadastro com essa matricula");
 	 } 
    else{
	  if (analise > 99 || analise < 0) {
	 printf("Matricula invalida ,digite uma matricula valida\n");
      }     
      
      else{
 			// procurando uma posiçao vazia para guardar a matrícula 
           indice = 200;
	  	 for (i=0;i<200;i++){
         if(aluno[i].matricula == 0){
           if(i < indice){
           indice = i;
           }
         }
         cont++;
       }
        aluno[indice].matricula = matricula;
 	             
 	    // analisando se a vagas para cadastro de matrícula 
        if(cont > 1){
         
         printf("Matricula cadastrada\n");
        }else{
    	   printf("Não há mais vagas para cadastro de matricula\n");
        
          } 	              
    }  
    }      
}
//------------------------------
// função que remove a matricula e os dados do aluno 
void remover (Alunos aluno[])
{
 int matricula,cont=0;
 int j=0,analise,i=0,posicao;
     
	printf("Qual a matricula do aluno que vai ser removido?\n");
	scanf("%d",&matricula);
 // analisando se a matrícula é válida 
       
 analise = (matricula - 2023000);
 
 if (analise < 100 && analise >= 0){   
	  // apagando dados do aluno da matricula digitada

	 for (i = 0;i<200;i++){
	      
	   if (aluno[i].matricula == matricula){
	    aluno[i].matricula = 0;
      aluno[i].nota1 = 0.0;
      aluno[i].nota2 = 0.0;
      aluno[i].nota3 = 0.0;
      aluno[i].nota4 = 0.0;
      strcpy(aluno[i].nome, "NULL");
      aluno[i].turma = 0;
      aluno[i].faltas= 0;
         
	   	 	 cont++;			   		
	   		}   	 
	 }     
	   
	if (cont == 1){
	   	printf(" O Aluno foi removido.\n");
	   	} 
	   	 else {
	   	printf ("Nao existe nenhum aluno cadastrado com essa matricula\n");
	     	}
	  
	    }else{
       system("clear");
       printf("Matricula invalida,digite uma matricula valida\n");	
       }       
  }

 //------------------------------
// funcao que atualiza notas,faltas,turma e nome.

void nota(Alunos aluno[], int matricula);
void frequenciaturmanome (Alunos aluno[],int matricula);

void atualizardados(Alunos aluno[])
{
	int i=0,j=0,opcao = 0,cont = 0;
	int matricula;
	
	       
	printf ("Qual a matricula do aluno?\n");
	scanf ("%d",&matricula);
    for (i = 0;i<200;i++){
	   	if (aluno[i].matricula == matricula){
	   		cont++;
	   		}
	 	}
                     
   if (cont==1){
    
     printf("O que voce quer atualizar?\n 1-Notas\n 2-Faltas,turma ou nome \n 3-Sair\n");
     
    	while (opcao != 3){
                
        scanf("%d",&opcao);
    	  switch (opcao){
    	   case 1:
           
    	  	system("clear");
           
          nota
        (aluno,matricula);
    	  	printf("O que voce quer atualizar?\n 1-Notas\n 2-Faltas,turma ou nome\n 3-Sair\n");
    	  	break;
          
         case 2:
           
         system("clear");	
         frequenciaturmanome(aluno, matricula);
         printf("O que voce quer atualizar?\n 1-Notas\n 2-Faltas,turma ou nome\n 3-Sair\n");
         break;
    	  	
    	   case 3:
           
    	  	system("clear");
          printf("Dados atualizados com sucesso\n");
    	  	
    	  	break;
    	  	
    	  	default:
          system("clear");
          printf ("Opcao invalida,digite uma opcao valida\n");
          printf("O que voce quer atualizar?\n 1-Notas\n 2-Faltas,turma ou nome\n 3-Sair\n");
          break;        
    	  	}
    	    	
    		}
       
	  }else{
    	printf ("Matricula nao cadastrada,digite uma matricula que ja tenha sido cadastrada\n");
     }      	    
}
//------------------------------
// funções auxiliares da função notas e frequências 

// função que atualiza a nota
  void menunotas();
  void incrementarnota (Alunos aluno[],int escolha,int matricula);
  
  void nota(Alunos aluno[],int matricula)
{
	
	 int escolha;

       menunotas();
    
   	while (escolha != 5){
   	  
   	   
    
	    scanf ("%d",&escolha);
	   
	    switch (escolha){
	   
	       case 1:
	    	  system("clear");
	    	  incrementarnota(aluno,escolha,matricula);
	    	  menunotas();
	    	   
	        break;

         case 2:
	        system("clear");
	    	  incrementarnota(aluno,escolha,matricula);
	    	  menunotas();
	        break;
	        
	       case 3:
	        system("clear");
	    	  incrementarnota(aluno,escolha,matricula);
	    	  menunotas();
	        break;
        
	       case 4:
	        system("clear");
	    	  incrementarnota(aluno,escolha,matricula);
	    	  menunotas();
	        break;
        
	       case 5:
	        system("clear");
	        printf ("Atualizado com sucesso\n");
	         
	        break;
	   
	        default:
           system("clear");

           printf ("Opcao invalida,digite uma opcao valida\n");
          menunotas();
	        break;
	    }
  }

}
//-----------------------------
//----menu das notas-------------
 void  menunotas() 
{
 	printf ("Selecione a opcao da nota que voce quer alterar:\n 1-primeira nota\n 2-segunda nota\n 3-terceira nota\n 4-quarta nota\n 5-Encerrar\n");
}
//-----------------------------
// funcao que incrementa a nota

 void incrementarnota (Alunos aluno[], int escolha,int matricula)
{
	 int nota,i;
	 
	 printf ("Digite a nota:\n");
	 scanf("%d",&nota);
	
	 if (nota <= 10 && nota >= 0){
	  for (i=0;i<200;i++){
	 	  if (matricula == aluno[i].matricula){
        if(escolha == 1){
	 	  	aluno[i].nota1 = nota;
	 	    }else{
          if(escolha == 2){
            aluno[i].nota2 = nota;
          }else{
            if(escolha == 3){
              aluno[i].nota3 = nota;    
              }else{
              if(escolha == 4){
                aluno[i].nota4=nota;
              }
            }
        
	    	}
     }
    }
  }
     system("clear");
	 	 printf("Nota cadastrada\n");	 	
	 }else{
	 	   printf("Nota invalida,digite uma nota valida\n");
	 	 } 	 
}
//----------------------------
// funcao que incrementa nome,faltas e turma
void frequenciaturmanome(Alunos aluno[],int matricula)
{
	 int falta,i;
	 
	 printf("Digite a quantidade de faltas\n");
	 scanf("%d",&falta);
   system("clear");
  
	 if(falta <= 36 && falta >= 0){
	  for(i= 0;i<200;i++){
	  	if(aluno[i].matricula == matricula){
       aluno[i].faltas = falta;
	  	 printf("Digite a turma\n");
       scanf ("%d",&aluno[i].turma);
        system("clear");
       printf("Digite o nome do aluno\n");
       scanf(" %[^\n]",aluno[i].nome);
       
	  		}
	   }
      system("clear");
	    printf("Turma e frequencia atualizadas\n");
     }else{
      printf("Quantidade de faltas invalidas,digite uma quantidade valida\n");
   }
}
//-------------------------------
// funcao que mostra os alunos cadastrados,para o aluno ser considerado cadastrado tem que está em alguma turma, não basta a matrícula está cadastrada.

void printaralunos (Alunos aluno[])
{
	int cont=0,i=0,j=0;
     
	   printf ("----Alunos Cadastrados----\n\n");
	   for(i=0;i<200;i++){
	   	if(aluno[i].turma != 0){
        cont++;
        
	   		printf ("Matricula:%d\n",aluno[i].matricula);
        printf   ("Turma:%d\n",aluno[i].turma);
        printf        ("Nome:%s\n",aluno[i].nome);      
	   		printf("1° nota:%.1f\n",aluno[i].nota1);
	   		printf("2° nota:%.1f\n",aluno[i].nota2);
	      printf("3° nota:%.1f\n",aluno[i].nota3);
        printf("4° nota:%.1f\n",aluno[i].nota4);
        printf("Faltas: %d\n\n",aluno[i].faltas);
        
	     }	     
	    }
       if(cont == 0){
         printf("Nao ha alunos cadastrados em nenhuma turma\n");
         }       
}
//-------------------------------
// função que mostra os alunos aprovados ,se o aluno estiver em alguma turma.
 void aprovados( Alunos aluno[])
{
	 int i,x=0,frequencia;
  float media;
  
  for(i=0;i<200;i++){
    if(aluno[i].turma != 0){
      x++;
    }
  }
 
  if(x>0){
    printf("-----Alunos aprovados----\n");
	  for(i=0;i<200;i++){
	 	 if(aluno[i].turma != 0){ 	  	  	  
	 	  
	 	   media = ((float)((aluno[i].nota1)+(aluno[i].nota2)+(aluno[i].nota3)+(aluno[i].nota4))/4);
	 	   frequencia = (((36-(aluno[i].faltas))*100)/36);
	 	   
	 	    if(((float)(media > 7)) && frequencia > 60){ 	  
         printf("Turma:%d\n",aluno[i].turma);
	 	     printf ("Matricula:%d\n",aluno[i].matricula);
         printf("Nome:%s\n",aluno[i].nome);
	 	     printf("Media :%.1f\n",media);
printf("Frequencia:%d%\n\n",frequencia);
	 	  
	 	  }	 
	   } 
	}
    
 }else{
    printf("Nenhum aluno cadastrado em nenhuma turma\n");
    }
}
//----------------------------
//função que mostra os alunos reprovados por media se ele estiver em alguma turma

void reprovadosmedia(Alunos aluno[])
{
	 int i,x=0;
  float media;
 
  for(i=0;i<200;i++){
      if(aluno[i].turma != 0){
      	x++;
  	}
  } 
  if (x >0){
   printf("--Alunos reprovados por media--\n");

 	 for(i=0;i<200;i++){
	 	 if(aluno[i].turma != 0){
	 	  	media = ((float)((aluno[i].nota1)+(aluno[i].nota2)+(aluno[i].nota3)+(aluno[i].nota4))/4);  	  	 	  
	 	   	 	   
	 	   if((float)(media < 7.0)){
        printf("Turma:%d\n",aluno[i].turma);
	 	    printf ("Matricula:%d\n",aluno[i].matricula);
         printf("Nome:%s\n",aluno[i].nome);
	 	     printf("Media :%.1f\n\n",media);
	 	     	 	  
	 	   }	 	 
     }
 	  }
  }else{
    printf("Nenhum aluno cadastrado em nenhuma turma\n");
    }
}
//------------------------------
//- Função que lista os alunos por turma
void listarporturma (Alunos aluno[])
{
	int cont=0,i=0,j=0,turma;
  float media;
  printf("Digite a turma:");
  scanf("%d",&turma);
  system("clear");
	   printf ("--Alunos Cadastrados na turma %d--\n\n",turma);
	   for(i=0;i<200;i++){
       media = ((float)((aluno[i].nota1)+(aluno[i].nota2)+(aluno[i].nota3)+(aluno[i].nota4))/4);  
	   	if(aluno[i].turma == turma){
        cont++;
	   		printf ("Matricula:%d\n",aluno[i].matricula);
        printf        ("Nome:%s\n",aluno[i].nome);      
        printf("Media:%.1f\n\n",media);
	     }	     
	    }
       if(cont == 0){
         printf("Nao ha alunos cadastrados nessa turma\n");
       }
}
//-----------------------------
// funcao que mostra os alunos reprovados por faltas se ele estiver em alguma turma
void reprovadosfaltas (Alunos aluno[])
{
	 int i,x=0,frequencia;
  
  for(i=0;i<200;i++){
      if(aluno[i].turma != 0){
      	x++;
  	}
  }
  
  if (x > 0){
   	printf("--Reprovados por faltas--\n");
 	 for(i=0;i<200;i++){
	 	 if(aluno[i].matricula != 0){
	 	  	  	  	 	  
	 	   frequencia = (((36-(aluno[i].faltas))*100)/36);
	 	   
	 	   if((float)(frequencia < 60)){
        printf("Turma:%d\n",aluno[i].turma);
        printf("Nome:%s\n",aluno[i].nome);
	 	    printf ("Matricula:%d\n",aluno[i]. matricula);
	 	    printf ("Frequencia:%d%\n\n",frequencia);	     	 	  
	 	   } 	 
	  }  
 	 }
 }else{
    printf("Nenhum aluno cadastrado em nenhuma turma\n");
    }
}
//-------------------------------
//---funcao que ordena os dados dos alunos de acordo com a escolha do usuário ,todas as ordenações são em ordem decrescente 
void menuord();
void ordenarpormatricula(Alunos aluno[]);
void ordenarpornome(Alunos aluno[]);
void ordenarpormedia(Alunos aluno[]);
void ordenarporfaltas(Alunos aluno[]);
void ordenacao(Alunos aluno[]){

       int opcao;
          menuord();
       
      	while (opcao != 5){
        
        scanf("%d",&opcao);
    	  switch (opcao){
    	   case 1:   
    	   system("clear");
      ordenarpormatricula(aluno);
    	   menuord();
    	   break;
          
         case 2:
           
         system("clear");	
         ordenarpornome(aluno);
         menuord();
         break;
         

         case 3:
           
         system("clear");	
         ordenarpormedia(aluno);
    	   menuord();
         break;

         case 4:
          
         system("clear");	
         ordenarporfaltas(aluno);
    	   menuord();
         break;
          
    	   case 5:
           
    	  	system("clear");
          printf("ordenação concluída\n");
    	  	
    	  	break;
    	  	
    	  	default:
          system("clear");
          printf ("Opcao invalida,digite uma opcao valida\n");
          menuord();
          break;        
    	  	}
    	    	
        }
}
//-------------------------------
//------ funções auxiliares da função ordenaçao 
//------------------------------
//- função menu de ordenação 
void menuord(){
  printf("Escolha a opcao da forma\nque deseja ordenar:\n 1-Por matricula\n 2-Por nome\n 3-Por media\n 4-Por faltas\n 5-Sair\n");
}
//--------------------------------
//--- função que ordena os alunos em ordem decrescente de matriculas
void ordenarpormatricula(Alunos aluno[]){
 
 int i,j,a1,a4,a9;
 char a2[100];
 float media[200],a3;
 float a5,a6,a7,a8;
  for(i=0;i<200;i++){
    media[i] = (float) (((aluno[i].nota1)+(aluno[i].nota2)+(aluno[i].nota3)+(aluno[i].nota4))/4);
  }

 for(i=0;i<200;i++){
   for(j=0;j<200-i-1;j++){
     if(aluno[j].matricula < aluno[j+1].matricula) {
       a1 = aluno[j].matricula;
       strcpy(a2,aluno[j].nome);
       a3 = media[j];
       a4 = aluno[j].faltas;
       a5 = aluno[j].nota1;
       a6 = aluno[j].nota2;
       a7 = aluno[j].nota3;
       a8 = aluno[j].nota4;
       a9 = aluno[j].turma;
       
       aluno[j].matricula = aluno[j+1].matricula;      strcpy(aluno[j].nome,aluno[j+1].nome);
       media[j] = media[j+1];
       aluno[j].faltas = aluno[j+1].faltas;
       aluno[j].nota1 = aluno[j+1].nota1;
       aluno[j].nota2 = aluno[j+1].nota2;
       aluno[j].nota3 = aluno[j+1].nota3;
       aluno[j].nota4 = aluno[j+1].nota4;
       aluno[j].turma = aluno[j+1].turma;
       
       aluno[j+1].matricula = a1;
       strcpy(aluno[j+1].nome,a2);
       media[j+1] = a3;
       aluno[j+1].faltas = a4;
       aluno[j+1].nota1 = a5;
       aluno[j+1].nota2 = a6;
       aluno[j+1].nota3 = a7;
       aluno[j+1].nota4 = a8;
       aluno[j+1].turma = a9;
     }
   }
 }
  printf("ordenado com sucesso\n");
}
//----------------------------
//função que ordena os alunos em ordem alfabética decrescente 
void ordenarpornome(Alunos aluno[]){
 
 int i,j,a1,a4,a9;
 char a2[100];
 float media[200],a3;
 float a5,a6,a7,a8;
  for(i=0;i<200;i++){
    media[i] = (float) (((aluno[i].nota1)+(aluno[i].nota2)+(aluno[i].nota3)+(aluno[i].nota4))/4);
  }

 for(i=0;i<200;i++){
   for(j=0;j<200-i-1;j++){
     if(strcmp((aluno[j].nome),(aluno[j+1].nome)) <0) {
       a1 = aluno[j].matricula;
       strcpy(a2,aluno[j].nome);
       a3 = media[j];
       a4 = aluno[j].faltas;
       a5 = aluno[j].nota1;
       a6 = aluno[j].nota2;
       a7 = aluno[j].nota3;
       a8 = aluno[j].nota4;
       a9 = aluno[j].turma;
       aluno[j].matricula = aluno[j+1].matricula;
       strcpy(aluno[j].nome,aluno[j+1].nome);
       media[j] = media[j+1];
       aluno[j].faltas = aluno[j+1].faltas;
       aluno[j].nota1 = aluno[j+1].nota1;
       aluno[j].nota2 = aluno[j+1].nota2;
       aluno[j].nota3 = aluno[j+1].nota3;
       aluno[j].nota4 = aluno[j+1].nota4;
       aluno[j].turma = aluno[j+1].turma;
       aluno[j+1].matricula = a1;
       strcpy(aluno[j+1].nome,a2);
       media[j+1] = a3;
       aluno[j+1].faltas = a4;
       aluno[j+1].nota1 = a5;
       aluno[j+1].nota2 = a6;
       aluno[j+1].nota3 = a7;
       aluno[j+1].nota4 = a8;
       aluno[j+1].turma = a9;
     }
   }
 }
  printf("ordenado com sucesso\n");
}
//-------------------------------
//---função que ordena os alunos em ordem decrescente de medias
void ordenarpormedia(Alunos aluno[]){
 
 int i,j,a1,a4,a9;
 char a2[100];
 float media[200],a3;
 float a5,a6,a7,a8;
  for(i=0;i<200;i++){
    media[i] = (float) (((aluno[i].nota1)+(aluno[i].nota2)+(aluno[i].nota3)+(aluno[i].nota4))/4);
  }

 for(i=0;i<200;i++){
   for(j=0;j<200-i-1;j++){
     if(media[j] < media[j+1]) {
       a1 = aluno[j].matricula;
       strcpy(a2,aluno[j].nome);
       a3 = media[j];
       a4 = aluno[j].faltas;
       a5 = aluno[j].nota1;
       a6 = aluno[j].nota2;
       a7 = aluno[j].nota3;
       a8 = aluno[j].nota4;
       a9 = aluno[j].turma;
       
       aluno[j].matricula = aluno[j+1].matricula;
      strcpy     (aluno[j].nome,aluno[j+1].nome);
       media[j] = media[j+1];
       aluno[j].faltas = aluno[j+1].faltas;
       aluno[j].nota1 = aluno[j+1].nota1;
       aluno[j].nota2 = aluno[j+1].nota2;
       aluno[j].nota3 = aluno[j+1].nota3;
       aluno[j].nota4 = aluno[j+1].nota4;
       aluno[j].turma = aluno[j+1].turma;
       
       aluno[j+1].matricula = a1;
       strcpy(aluno[j+1].nome,a2);
       media[j+1] = a3;
       aluno[j+1].faltas = a4;
       aluno[j+1].nota1 = a5;
       aluno[j+1].nota2 = a6;
       aluno[j+1].nota3 = a7;
       aluno[j+1].nota4 = a8;
       aluno[j+1].turma = a9;
     }
   }
 }
  printf("ordenado com sucesso\n");
}
//-------------------------------
//------ função que ordena os alunos em ordem decrescente de faltas
void ordenarporfaltas(Alunos aluno[]){
 
 int i,j,a1,a4,a9;
 char a2[100];
 float media[200],a3;
 float a5,a6,a7,a8;
  for(i=0;i<200;i++){
    media[i] = (float) (((aluno[i].nota1)+(aluno[i].nota2)+(aluno[i].nota3)+(aluno[i].nota4))/4);
  }

 for(i=0;i<200;i++){
   for(j=0;j<200-i-1;j++){
     if(aluno[j].faltas < aluno[j+1].faltas) {
       a1 = aluno[j].matricula;
       strcpy(a2,aluno[j].nome);
       a3 = media[j];
       a4 = aluno[j].faltas;
       a5 = aluno[j].nota1;
       a6 = aluno[j].nota2;
       a7 = aluno[j].nota3;
       a8 = aluno[j].nota4;
       a9 = aluno[j].turma;
       
       aluno[j].matricula = aluno[j+1].matricula;
       strcpy(aluno[j].nome,aluno[j+1].nome);
       media[j] = media[j+1];
       aluno[j].faltas = aluno[j+1].faltas;
       aluno[j].nota1 = aluno[j+1].nota1;
       aluno[j].nota2 = aluno[j+1].nota2;
       aluno[j].nota3 = aluno[j+1].nota3;
       aluno[j].nota4 = aluno[j+1].nota4;
       aluno[j].turma = aluno[j+1].turma;
       
       aluno[j+1].matricula = a1;
       strcpy(aluno[j+1].nome,a2);
       media[j+1] = a3;
       aluno[j+1].faltas = a4;
       aluno[j+1].nota1 = a5;
       aluno[j+1].nota2 = a6;
       aluno[j+1].nota3 = a7;
       aluno[j+1].nota4 = a8;
       aluno[j+1].turma = a9;
     }
   }
 }
  printf("ordenado com sucesso\n");
}
//-------------------------------
//---- funcao que salva os dados dos alunos cadastrados,para ser considerado cadastrado não basta ter a matrícula cadastrada precisa está em alguma turma
  void salvaralunos(Alunos aluno[]){
  int i,x=0;
	FILE *arquivo;
	arquivo= fopen("alunos.txt", "w");
    
  for(i=0; i<200; i++){
    if(aluno[i].turma != 0){
      
      fprintf(arquivo, "%d\n%d\n%s\n%.1f\n%.1f\n%.1f\n%.1f\n%d\n\n",aluno[i].matricula, aluno[i].turma,aluno[i].nome,aluno[i].nota1,aluno[i].nota2,aluno[i].nota3,aluno[i].nota4,aluno[i].faltas);
    }
  }
   
	fclose(arquivo);
  }
//-------------------------------
//--- função que lê os dados dos alunos que estão no arquivo 
void leralunos ( Alunos aluno[]){
  int i=0;
  FILE *arquivo;
  arquivo = fopen("alunos.txt","r");

  if(arquivo == NULL){
    printf("Erro! Nao foi possivel ler o arquivo");
  }else{
   while(fscanf(arquivo,"%d\n%d\n %[^\n]\n%f\n%f\n%f\n%f\n%d\n\n",&aluno[i].matricula,&aluno[i].turma,aluno[i].nome,&aluno[i].nota1,&aluno[i].nota2,&aluno[i].nota3,&aluno[i].nota4,&aluno[i].faltas) != EOF){
      i++;
    
  }
    fclose(arquivo);
 }
}