# Sistemas Embarcados Atividade 3 - Controle de estufa

## Objetivos
O objetivo deste projeto é controlar a luminosidade de uma estufa através de sensores e
controles de abertura e fechamento de telas que controlam a entrada de luz solar em um
ambiente simulado. Essa estufa foi projetada para plantas ornamentais, que precisam de
baixa luminosidade para seu crescimento ideal. Antes da construção real da estufa é
necessário criar uma base de teste. Para essa base de testes são definidos os seguintes
parâmetros:

- Um LDR será utilizado para verificar a luminosidade do local. A partir dele deverá
ser avaliada a luminosidade mais alta possível do local (o valor mais alto
alcançado). Esse valor tem que ser verificado através do Serial Monitor durante
algum tempo e será usado como referência (valor máximo de luminosidade do
local). Por exemplo, se o maior valor captado pelo LDR for 835, esse será o valor
máximo (referente a 100% de luminosidade);
- Três LEDs irão representar o status de luminosidade do local: o LED vermelho será
acesso quando a luminosidade do local estiver entre 80% a 100% da luminosidade
máxima do local; o LED amarelo será acesso quando a luminosidade estiver entre
50% a 79% da luminosidade máxima do local; e o LED verde indica uma
luminosidade ideal, abaixo dos 50%.
- Um buzzer irá representar o controle das telas. Quando o LED estiver vermelho, as
3 telas de proteção deverão ser fechadas, para impedir a entrada de luz solar e
assim reduzindo a luminosidade. Com isso, o buzzer deve apitar 3 sinais breves,
sendo cada um dos sinais indicativo que uma tela está fechada. Se o LED estiver
amarelo, serão emitidos 2 apitos breves (2 telas fechadas). Quando o LED estiver
verde, 1 apito será ouvido (1 tela fechada).
- O sistema também terá um botão de liga/desliga. Durante o dia (período que o
sistema deverá estar ligado) é necessário clicar uma vez no botão (push button).
Pressionar novamente o botão indica o desligamento do sistema, ou seja, o
sistema não estará mais ativo.

---
## Montagem da placa

![image](https://github.com/user-attachments/assets/b1b0cf03-a76c-434f-a6e5-3c53d09f1599)

<p align="center">
  <i>(*Arduino Uno R3*)</i>
</p>

#### Esquema elétrico - [Atividade 3 - Controle de estufa.pdf](https://github.com/user-attachments/files/17034595/Atividade.3.-.Controle.de.estufa.pdf)
