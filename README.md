# STW3100


## Linguagens de Programação
_"...conjunto de regras sintáticas e semânticas, de implementação de um código fonte."_ - Prof. Dr. Wikipedia
Java, C, C++, C#, Python, Javascript, PhP... **Qual a diferença?**
![alt text](./media/languages.gif "programming languages GIF")

Mas como a máquina pega essas instruções em alto nível que foram digitadas, e as executa?

### Principais abordagens: 
* Compilação - C, C++, C#, Java
    * Há um **compilador** (um programa), que lê o texto do seu código, sabendo das regras de sintaxe da linguagem, e o traduz para um arquivo em código de máquina.
    * Na prática, desenvolvendo em linguagens compiladas, sempre que quisermos rodar o que está sendo escrito, precisamos compilar. 
* Intepretação - Pyhton, PHP, JavaScript, Ruby
    * Há um... **interpretador** (outro programa), que lê, linha por linha de código da linguagem interpretada, e executa o comando **enquanto faz a leitura**.
    * Cruamente, as linguagens interpretadas são conhecidas por terem uma performance pior que as compiladas, porém existem técnicas para contornar isso.
* Outros...
    * Just-in-time compilation [olha q belezinha](http://numba.pydata.org/)
    * Structured programming


### Paradigmas de Programação
* Imperativo

* Orientado a Objetos (OO)

* Orientado a Eventos

* Declarativo, Estrutural e muitos outros

## O C++

C++ foi desenvolvido por Bjarne Stroustrup at Bell Labs in 1979, com o objetivo de ser uma extensão à linguagem C.

Ele pode ser usado para criar aplicações de alta performance e ao mesmo tempo permite um alto nível de controle dos recursos do sistema e memória aos programadores.

Por que usamos C++?

Sendo uma das liguagens de programação mais utilizadas, tão usada que é geralemnte encontrada em sistemas operacionais, GUI's (Graphical User Interface) e sistemas embarcados. Ele também é uma linguagem orientada à objetos, dandn uma estrutura bem definida para programas e permitindo o reuso de códigos, diminuindo custos de desenvolvimento.

Como o C++ se aproxima bastante de linguagens como C# e Java, é relativamente fácil para programadores incalar entre essas linguagens

### Variáveis - Estruturas de Dados Fundamentais
#### Tipos

| Tipo de variável | Tamanho | Range |
| --------- |:--------:| :----------:|
|   bool    |   1 bit  |
|    char   |   1 byte |
|    int    |  4 bytes | 	-2,147,483,648 to 2,147,483,647 |
|unsigned int | 4 bytes | 0 to 4,294,967,295 |
|float|4 bytes|1.175494e-38 a 3.402823e+38 (**8.5677e+14 mols**)|
|double|8 bytes|-inifinito a +infinito|
|void|||
|string|||

* Não existem números reais em sistemas digitais, um float é feito de ints!
    * 24 dígitos de mantissa
    * 7 bits pro expoente

#### Declaração
Em C++, precisamos **declarar** as variáveis, e seus tamanhos devem ser, a priori, definidos para que a máquina aloque a memória necessária para as variáveis.

```C++
int contador;
int contador = 0;
```
### PONTO E VIRGULA, SEMPRE!
Quando definimos uma variável o seu conteúdo não é conhecido, então é uma boa prática **inicializar as variáveis antes do seu uso**.
#### Uso
```C++
int C=0; // inicializando a variável

//Jeito 1 de incrementar variáveis
C = C + 1;
//Jeito equivalente
C++;
//Jeito equivalente
C += 1;

//O mesmo vale para subtrações, produtos e divisões
C = C - 1;
C--;
C -= 1;
// São 3 modos equivalentes de fazer a mesma operação
```
### Entrada e Saída básicas

#### Hello, drone

### Condicionais
#### if/else

### Loops
#### while

#### for

```C++
for (auto& x : foo().items()) { /* .. */ }
```

#### do ... while

#### Fatorial

### Funções

### Arrays

### Ponteiros

Um ponteiro é uma variável capaz de armazenar um endereço de memória ou o endereço de outra variável.

Funcionamento básico de um computador que utiliza a **Arquitetura de von Neumann**

<center><img
    src="/media/vonNeumann.png"
    width="430"
    height="222"
    alt="von Neumann Archtecture"
/></center>

#### Bhascara - retornar 2 raizes

### Recursão

#### Fatorial++

### Usando Bibliotecas

#### Subtração de 2 imagens, usando OpenCV