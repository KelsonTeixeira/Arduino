/* Módulo IR com CONTROLE REMOTO
 * Nesse projeto demonstraremos a utilização de um Controle
 * Remoto com um receptor infravermelho do Módulo IR GBK-P14
*/

   
#include <IRremote.h>    //Biblioteca para Sensor Infravermelho

/////////////////////////////////
// INICIALIZAÇÃO DAS VARIÁVEIS //
/////////////////////////////////     

int pinoRecep = 11;    //inicializando uma variável denominada
                       //pinoRecep para armazenar valor da 
                       //leitura proveniente do receptor IR.
const int Red = 2, Green = 3, Blue = 4;

                  
long tecla = 0;        //inicializando uma variável denominada
                       //tecla para armazenar valor lido
                       //pelo receptor IR.
/* 
  A Classe "IRrecv" tem a função de executar a decodificação
  e deve ser inicialidada através do enableIRIn.
*/
IRrecv receptorIr(pinoRecep);

/* 
  O Método "decode" é chamado para ver se um código foi recebido,
  e em caso afirmativo, ele retorna um valor diferente de zero  
  e coloca os resultados em uma estrutura chamada decode_results
*/
decode_results resultados;

                     
///////////
// SETUP //
///////////
void setup()
{ 
  Serial.begin(9600);      //setando a comunicação via porta 
                           //serial à uma velocidade de 9600bps(baud).
  pinMode (Red,OUTPUT);
  pinMode (Green,OUTPUT);
  pinMode (Blue,OUTPUT);
  
  receptorIr.enableIRIn(); //Inicializando o sensor IR.
  
  Serial.println("Modulo IR GBK-P14 ativado!");  //imprime uma mensagem
                                                 //no Serial Monitor
}

///////////
// LOOP  //
///////////
void loop()
{
  /*
    Verifica o valor do código lido pelo receptor IR para
    tomada das ações.
  */
  if (receptorIr.decode(&resultados)) 
  {
    tecla = resultados.value, DEC;         //armazena o código
                                           //decimal lido pelo
                                           //receptor IR.
    
    //imprime o código decimal lido pelo receptor IR.
    //Serial.print("Tecla pressionada em decimal = ");
    //Serial.println(resultados.value, DEC); 
    
    
      Serial.print("Tecla pressionada em decimal: ");     
      Serial.println(tecla, DEC);
      
      if (tecla == 417828975){
        digitalWrite (Red, HIGH);
      }
      if (tecla == 417833055){
        digitalWrite (Red, LOW);
      }
       if (tecla == 417835095){
        digitalWrite (Green, HIGH);
      }
      if (tecla == 417800415){
        digitalWrite (Green, LOW);
      }
      if (tecla == 417839175){
        digitalWrite (Blue, HIGH);
      }
      if (tecla == 417796335){
        digitalWrite (Blue, LOW);
      }
      
      
    
    receptorIr.resume(); //Prepara o módulo para receber o próximo código.                                  
  }
}