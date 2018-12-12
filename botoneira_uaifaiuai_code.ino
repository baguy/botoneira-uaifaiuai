//
// Botoneira de 3 botões que enviam tweets e 
// emails padrões com avisos para condomínio
//

int button1 = 16; // BOTÃO 1 -- D0
int button2 = 5;  // BOTÃO 2 -- D1
int button3 = 4;  // BOTÃO 3 -- D2
int temp1 = 0;    // variável temporária para o status do botão
int temp2 = 0;
int temp3 = 0;
int led1 = 2;
int led2 = 14;
int led3 = 12;
int ledWifi = 0;

#include <ESP8266WiFi.h>

WiFiClient client;

String MakerIFTTT_Key ;
;String MakerIFTTT_Event;
char *append_str(char *here, String s) {  int i=0; while (*here++ = s[i]){i++;};return here-1;}
char *append_ul(char *here, unsigned long u) { char buf[20]; return append_str(here, ultoa(u, buf, 10));}
char post_rqst[256];char *p;char *content_length_here;char *json_start;int compi;

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(ledWifi, OUTPUT);
  Serial.begin(9600);
  WiFi.disconnect();
  delay(3000);
   //WiFi.begin("May ASUS","87f0d9019844");
   WiFi.begin("iPhone de Aruan","87654321");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(1000);
    digitalWrite(ledWifi, LOW);
    Serial.print(".");
  }
  Serial.println("Conectado");
  Serial.println(WiFi.localIP()); // mostra o IP do servidor 
  
  
}

void loop() {
  if (WiFi.status() == WL_CONNECTED){
      digitalWrite(ledWifi, HIGH);
      }
      else{
        digitalWrite(ledWifi, LOW);
      }
  //
  //// BOTÃO 1 \\\\
  //
  temp1 = digitalRead(button1);
     
     if (temp1 == HIGH) {
        String contador = String(random(10000));
        Serial.println(contador);
        digitalWrite(led1, HIGH);
        delay(3000);
        digitalWrite(led1, LOW);
        Serial.println("LED 1 ligou");
        if (client.connect("maker.ifttt.com",80)) {
          //
          // ENVIAR TWEET 1
          //
          Serial.println("Enviando...");
          MakerIFTTT_Key ="mTzjm0PAN54SZCTTcSti7";
          // EVENT (configurado no IFTTT)
          MakerIFTTT_Event ="tweet";
          p = post_rqst;
          p = append_str(p, "POST /trigger/");
          p = append_str(p, MakerIFTTT_Event);
          p = append_str(p, "/with/key/");
          p = append_str(p, MakerIFTTT_Key);
          p = append_str(p, " HTTP/1.1\r\n");
          p = append_str(p, "Host: maker.ifttt.com\r\n");
          p = append_str(p, "Content-Type: application/json\r\n");
          p = append_str(p, "Content-Length: ");
          content_length_here = p;
          p = append_str(p, "NN\r\n");
          p = append_str(p, "\r\n");
          json_start = p;
          p = append_str(p, "{\"value1\":\"");
          // MENSAGEM ENVIADA PELO TWEET 1
          p = append_str(p, "Coleta de LIXO ORGÂNICO no condomínio ");
          p = append_str(p, "\",\"value2\":\"");
          p = append_str(p, contador);
          p = append_str(p, "\",\"value3\":\"");
          p = append_str(p, "");
          p = append_str(p, "\"}");

          Serial.println("Tweet 1 enviado");
      
          compi= strlen(json_start);
          content_length_here[0] = '0' + (compi/10);
          content_length_here[1] = '0' + (compi%10);
          client.print(post_rqst);   
  }
        delay(1000);
       }
   //
   //// BOTÃO 2 \\\\ 
   //   
   temp2 = digitalRead(button2);
   
     if (temp2 == HIGH) {
        String contador = String(random(1000));
        Serial.println(contador);
        
        digitalWrite(led2, HIGH);
        delay(3000);
        digitalWrite(led2, LOW);
        Serial.println("LED 2 ligou");

        delay(1000);

        if (client.connect("maker.ifttt.com",80)) {
        //
        // ENVIAR TWEET 2
        //
          Serial.println("Enviando tweet 2...");
          MakerIFTTT_Key ="mTzjm0PAN54SZCTTcSti7";
          MakerIFTTT_Event ="tweet";
          p = post_rqst;
          p = append_str(p, "POST /trigger/");
          p = append_str(p, MakerIFTTT_Event);
          p = append_str(p, "/with/key/");
          p = append_str(p, MakerIFTTT_Key);
          p = append_str(p, " HTTP/1.1\r\n");
          p = append_str(p, "Host: maker.ifttt.com\r\n");
          p = append_str(p, "Content-Type: application/json\r\n");
          p = append_str(p, "Content-Length: ");
          content_length_here = p;
          p = append_str(p, "NN\r\n");
          p = append_str(p, "\r\n");
          json_start = p;
          p = append_str(p, "{\"value1\":\"");
          // MENSAGEM ENVIADA PELO TWEET 2:
          p = append_str(p, "Coleta de LIXO RECICLÁVEL no condomínio");
          p = append_str(p, "\",\"value2\":\"");
          p = append_str(p, contador);
          p = append_str(p, "\",\"value3\":\"");
          p = append_str(p, "");
          p = append_str(p, "\"}");

          Serial.println("Tweet 2 enviado");
      
          compi= strlen(json_start);
          content_length_here[0] = '0' + (compi/10);
          content_length_here[1] = '0' + (compi%10);
          client.print(post_rqst);
  }
        delay(1000);
       }

  //
  //// BOTÃO 3 \\\\
  //
  temp3 = digitalRead(button3);
     
     if (temp3 == HIGH) {
        String contador = String(random(1000));
        Serial.println(contador);
        
        digitalWrite(led3, HIGH);
        delay(3000);
        digitalWrite(led3, LOW);
        Serial.println("LED 3 ligou");

        delay(1000);

        if (client.connect("maker.ifttt.com",80)) {
          Serial.println("Enviando tweet 3...");
          MakerIFTTT_Key ="mTzjm0PAN54SZCTTcSti7";
          MakerIFTTT_Event ="tweet";
          p = post_rqst;
          p = append_str(p, "POST /trigger/");
          p = append_str(p, MakerIFTTT_Event);
          p = append_str(p, "/with/key/");
          p = append_str(p, MakerIFTTT_Key);
          p = append_str(p, " HTTP/1.1\r\n");
          p = append_str(p, "Host: maker.ifttt.com\r\n");
          p = append_str(p, "Content-Type: application/json\r\n");
          p = append_str(p, "Content-Length: ");
          content_length_here = p;
          p = append_str(p, "NN\r\n");
          p = append_str(p, "\r\n");
          json_start = p;
          p = append_str(p, "{\"value1\":\"");
          // MENSAGEM ENVIADA PELO TWEET 3:
          p = append_str(p, "Risco de alagamento no condomínio");
          p = append_str(p, "\",\"value2\":\"");
          p = append_str(p, contador);
          p = append_str(p, "\",\"value3\":\"");
          p = append_str(p, "");
          p = append_str(p, "\"}");

          Serial.println("Tweet 3 enviado");
      
          compi= strlen(json_start);
          content_length_here[0] = '0' + (compi/10);
          content_length_here[1] = '0' + (compi%10);
          client.print(post_rqst);
  }
        delay(1000);
       }
}
