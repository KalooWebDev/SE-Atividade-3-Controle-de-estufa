// LDR (fotoresistor)
int LDR = A0;    // Entrada análogica(OUTPUT) do LDR
int LDR_Value;   // Representa o valor Analogico do LDR
int LDR_Porcent; // Representa o valor do LDR em porcentagem

// LEDs
int RED = 12;
int YELLOW = 11;
int GREEN = 10;

// Piezo
int BUZZER = 7;
int previousLDRState = 0;

// Botão
int BUTTON = 2;
int LIG_DES = 1;
int lastButtonState = 0;
int currentButtonState = 0;

void setup()
{
    Serial.begin(9600); // Inicia o monitor

    pinMode(RED, OUTPUT);
    pinMode(YELLOW, OUTPUT); // Define os LEDs como OUTPUT
    pinMode(GREEN, OUTPUT);

    pinMode(BUZZER, OUTPUT); // Define o Piezo como OUTPUT

    pinMode(BUTTON, INPUT); // Define o botão como input
}

void controlBuzzer(int time) // Função que controla o Buzzer, como parametro a função recebe a quantidade de vezes que o buzzer aciona (times)
{
    for (int i = 0; i < time; i++) // i controla o lopping, se i for menor que time, i ativa o lopping e recebe +1
    {
        tone(BUZZER, 350); // Ativa o Buzzer
        delay(1000);
        noTone(BUZZER); // Desativa o Buzzer
        delay(1000);
    }
}

void loop()
{

    currentButtonState = digitalRead(BUTTON); // Estado atual do botão igual ao valor lido no botão

    if (currentButtonState == 1 && lastButtonState == 0) // Se o estado atual do botão for true e o ultimo estado do botão for falso
    {
        LIG_DES = !LIG_DES; // Desliga ou Liga o sistema
    }

    lastButtonState = currentButtonState; // O ultimo estado do botão recebe o estado atual do botão
    if (LIG_DES == 1)                     // Se o sistema estiver ligado
    {
        LDR_Value = analogRead(LDR);                   // Obtem valor analogico do LDR
        LDR_Porcent = map(LDR_Value, 0, 1023, 0, 100); // mapeia os valores e devolve eles em outro formato(inMinimo, inMaximo, outMinimo, outMaximo)

     	Serial.print(LDR_Porcent);  // Imprime o valor da variável
		Serial.println(" %");       // Imprime o símbolo de porcentagem e pula para a próxima linha
      
        if (LDR_Porcent > 80)
        { // LDR acima de 80%

            digitalWrite(RED, 1);    // Acende LED Vermelho
            digitalWrite(GREEN, 0);  // Apaga LED Verde
            digitalWrite(YELLOW, 0); // Apaga LED Amarelo

            if (previousLDRState != 3)
            {                         // Se mudou de estado
                controlBuzzer(3);     // Toca o buzzer 2 vezes
                previousLDRState = 3; // Atualiza o estado anterior
            }
        }
        else if (LDR_Porcent < 50)
        { // LDR abaixo de 50%

            digitalWrite(GREEN, 1);  // Acende LED Verde
            digitalWrite(YELLOW, 0); // Apaga LED Amarelo
            digitalWrite(RED, 0);    // paga LED Vermelho

            if (previousLDRState != 1)
            {                         // Se mudou de estado
                controlBuzzer(1);     // Toca o buzzer 2 vezes
                previousLDRState = 1; // Atualiza o estado anterior
            }
        }
        else
        { // LDR entre 79% e 49%

            digitalWrite(YELLOW, 1); // Acende LED Amarelo
            digitalWrite(RED, 0);    // Apaga LED Vermelho
            digitalWrite(GREEN, 0);  // Apaga LED Verde

            if (previousLDRState != 2)
            {                         // Se mudou de estado
                controlBuzzer(2);     // Toca o buzzer 2 vezes
                previousLDRState = 2; // Atualiza o estado anterior
            }
        }
    }
    else // Se o sistema estiver desligado
    {
        digitalWrite(YELLOW, 0); // Apaga LED Amarelo
        digitalWrite(RED, 0);    // Apaga LED Vermelho
        digitalWrite(GREEN, 0);  // Apaga LED Verde
    };

    delay(2000);
};