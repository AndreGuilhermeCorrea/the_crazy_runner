# 🏃 the_crazy_runner

![FATEC](https://img.shields.io/badge/FATEC/SP-000?style=for-the-badge&logo=&logoColor=white)
![C](https://img.shields.io/badge/C-000?style=for-the-badge&logo=&logoColor=white)
![GNU](https://img.shields.io/badge/GNU-000?style=for-the-badge&logo=gnu&logoColor=white)
![CodeBlocks](https://img.shields.io/badge/CodeBlocks-000?style=for-the-badge&logo=&logoColor=white)

the_crazy_runner (O corredor maluco) é um game desenvolvido em C baseado no jogo "Chrome Dino" do Google Chrome. O jogo foi desenvolvido em março de 2024 como um projeto para a disciplina de Programação II (Profª Daniele Frosonido) do curso de Jogos Digitais do Centro Paula Souza - Faculdade Ministro Ralph Biasi (FATEC AMERICANA).

## 🎮 Screenshots

![Menu Principal](/img/screen_shot.png)

![Jogo](/img/screen_shot_ii.png)

## 📌 Descrição do Projeto

- **Inicialização do Jogo**: Quando o programa é iniciado, a tela aberta solicita ao jogador que insira seu nome. O jogo carrega os dados do jogador, incluindo seu nome e pontuação mais recente, de um arquivo binário. Tal tela é exibida com um tamanho pré-definido.

- **Menu Principal**: Após obter o nome do jogador, o jogo exibe um menu principal com opções para iniciar o jogo (pressionando 'W'), exibir créditos (pressionando 'C'), exibir ranking (pressionando 'R'), ou sair do jogo (pressionando 'X').

- **Iniciar o Jogo**: Se o jogador optar por iniciar o jogo, é exibido um ambiente de jogo onde o personagem está posicionado no canto esquerdo da tela. O jogador pode pular (pressionando 'W') para evitar obstáculos.

- **Obstáculos e Pontuação**: Durante o jogo, obstáculos se movem da direita para a esquerda na tela. O jogador ganha pontos à medida que avança e a velocidade do jogo aumenta progressivamente.

- **Fim do Jogo**: O jogo termina se o jogador colidir com um obstáculo. Nesse ponto, a pontuação final é exibida, e o jogador pode optar por reiniciar o jogo (pressionando 'W') ou retornar ao menu principal (pressionando 'X').

- **Créditos e Ranking**: O jogador pode optar por visualizar os créditos do jogo (opção 'C') ou o ranking dos jogadores (opção 'R') a qualquer momento a partir do menu principal.

- **Salvar Dados do Jogador**: O jogo salva os dados do jogador, incluindo seu nome e pontuação mais recente, em um arquivo binário.

- **Carregar Dados do Jogador**: Antes de iniciar o jogo, o jogo carrega os dados do último jogador salvo para exibir seu nome e pontuação anterior.

- **Ranking dos Jogadores**: O jogo também possui uma função para exibir um ranking dos jogadores com base em suas pontuações. Os jogadores são classificados em ordem decrescente de pontuação.

- **Créditos**: Os créditos do jogo são exibidos a partir de um arquivo de texto.

## 🛠️ Conceitos de Programação Utilizados

- **Ponteiros**: Os ponteiros são usados em várias funções para passar informações entre elas de forma eficiente. Por exemplo, na função `personagem(int pulo, Variavel *v)`, o ponteiro `v` é usado para atualizar a posição vertical do personagem.

- **Modularização**: O código está dividido em vários arquivos, cada um com uma função específica. Isso promove uma organização melhor do código e facilita a manutenção. Por exemplo, temos arquivos para tela, menu, início do jogo, obstáculos, personagem, limpeza de tela, manipulação de arquivo, e definição de variáveis globais.

- **Manipulação de Arquivos e Arquivos Binários**: O jogo utiliza arquivos para salvar dados do jogador e exibir créditos. Os dados do jogador são salvos em um arquivo binário usando as funções `gravarJogadorBinario()` e `gravarScoreJogadorArquivoBinario()`. Além disso, os créditos do jogo são lidos de um arquivo de texto usando a função `creditos()`.

- **Laços de Repetição**: Os laços de repetição são usados em várias partes do código, como para desenhar o personagem, movimentar obstáculos, atualizar a pontuação e exibir o ranking. Por exemplo, o laço `while` é usado no loop principal do jogo e dentro de outros loops para verificar teclas pressionadas e simular o pulo do personagem.

- **Estruturas de Controle (Condicional)**: As estruturas de controle condicional são usadas para tomar decisões com base nas ações do jogador e no estado do jogo. Por exemplo, os comandos `if`, `else if` e `else` são usados para verificar se o jogador pressionou uma tecla específica, se o jogo deve ser reiniciado após o fim do jogo, e se o jogador optou por visualizar os créditos ou o ranking.

- **Estruturas de Dados (Definição de Estruturas)**: O jogo define duas estruturas de dados - `Variavel` e `Player`. A estrutura `Variavel` é usada para controlar a velocidade e a posição do personagem, enquanto a estrutura `Player` é usada para armazenar informações do jogador, como nome e pontuação.

- **Manipulação de Strings**: A manipulação de strings é usada principalmente para exibir mensagens na tela e para interagir com o jogador. Por exemplo, as funções `printf()` e `fgets()` são usadas para exibir mensagens na tela e capturar o nome do jogador.

- **Importações**: O código importa várias bibliotecas padrão, como `stdio.h`, `stdlib.h`, `conio.h`, `time.h`, e `windows.h`, para fornecer funcionalidades como entrada e saída, manipulação de memória, entrada de teclado, manipulação de tempo, e funções específicas do Windows. Além disso, os próprios arquivos de cabeçalho são importados usando diretivas de pré-processamento, como `#include "header.h"`.

- **Funções**: O código contém várias funções que realizam tarefas específicas, como desenhar o personagem, movimentar obstáculos, atualizar a pontuação, exibir o ranking, e salvar dados do jogador. As funções são usadas para promover a reutilização de código e facilitar a manutenção.

- **Recursividade**: A recursividade é usada em algumas funções, como `creditos()`, para exibir os créditos do jogo. A função `creditos()` chama a si mesma para exibir cada linha dos créditos, até que todas as linhas tenham sido exibidas.

## 🚀 Como Jogar

1. Clone o repositório em sua máquina local.
2. Abra o arquivo `the_crazy_runner.c` em um compilador C (como o Code::Blocks).
3. Compile e execute o código.
4. Siga as instruções na tela para jogar o jogo.

## 📝 Lições Aprendidas

- **Desenvolvimento de Jogos em C**: O projeto me ensinou a desenvolver um jogo simples em C, incluindo a criação de telas, personagens, obstáculos, pontuação, e interações com o jogador.

- **Organização de Código**: A modularização do código em vários arquivos me ensinou a organizar melhor o código e a separar as responsabilidades de cada parte do jogo.

- **Manipulação de Arquivos**: A manipulação de arquivos em C me ensinou a salvar e carregar dados do jogador, bem como a exibir informações adicionais, como créditos, a partir de arquivos.

- **Uso de Ponteiros**: O uso de ponteiros em várias funções me ensinou a passar informações entre funções de forma eficiente e a atualizar variáveis globais.

- **Laços de Repetição e Estruturas de Controle**: O uso de laços de repetição e estruturas de controle me ensinou a controlar o fluxo do jogo e a tomar decisões com base nas ações do jogador.

- **Estruturas de Dados**: A definição de estruturas de dados me ensinou a organizar informações relacionadas em uma única estrutura e a acessar essas informações de forma eficiente.

- **Manipulação de Strings**: A manipulação de strings me ensinou a exibir mensagens na tela e a interagir com o jogador de forma eficaz.

- **Recursividade**: A recursividade me ensinou a chamar funções de forma recursiva para realizar tarefas repetitivas, como exibir créditos na tela.

## 📚 Referências

- [FATEC AMERICANA](https://www.cps.sp.gov.br/fatecs/fatec-americana-ministro-ralph-biasi/)
- [C Programming Language](https://devdocs.io/c/)
- [Code::Blocks](http://www.codeblocks.org/)

## 👩‍💻 Autores

- *Andre Guilherme Correa* | [correandre8@gmail.com](mailto:correandre8@gmail.com)
- *Fabiano Pedro da Silva Dias* | [fabianopedro89@gmail.com](mailto:fabianopedro89@gmail.com)
