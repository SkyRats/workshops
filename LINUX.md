# Linux Basics

## 1. Árvore de Diretórios

​	O que talvez você conheça como "pastas" aqui no Linux iremos nos referir como "diretórios". Os diretórios são organizados em hierarquia como uma árvore, e todos partem da *root* (raíz) represetada por uma barra  `/`. Os diretórios indicados abaixo já estão no seu sistema operacional e é legal que você conheca alguns deles.

![Linux Directory Structure](http://researchhubs.com/uploads/linux-cmd-directory-1.png)

### **Principais Diretórios** 

* `/` - "Root". É o primeiro diretório da hierarquia.
* `/bin` - "Binaries". Diretório que armazena códigos primitivos e comandos básicos do sistema.
* `/home`  - Diretório que você mais vai usar. Aqui é onde estão armazenados diretórios como "Downloads", "Documents", "Desktop", etc.
* `/opt` - "Optional" ou "Third Party Software". Diretório onde se encontram softwares de terceiros (não relacionados diretamente com o Linux) como "Google Chrome".
* `/tmp` - "Temporary Space" - Diretório de arquivos temporários. Sempre que o computador inicia esse diretório será limpado, portanto evite salvar arquivos neste diretório.



### Caminhos

​	Para se referir a diretórios dentro de diretórios podemos adicionar uma barra `/` e escrever o nome do próximo diretório em seguida. 

**Exemplo:**

```
/home/Documents/poli/skyrats
```



## 2. Introdução ao Terminal

### O que é?

​	O Terminal é uma interface não gráfica que aceita comandos digitados e os usa para realizar determinadas tarefas. Parece complicado de inicio, mas estou aqui pra te ajudar a entender como ele funciona e te mostrar que é bem simples.



### Como abrir o Terminal?

​	Você pode buscar por ele na barra de busca, ou usar o atalho `CTRL + ALT + T`. Este atalho irá abrir uma nova janela com o terminal. Se você já tiver uma janela aberta tente usar o `CTRL + SHIFT + T` para abrir uma nova subjanela.



### .bashrc

​	Sempre que você abre uma janela de Terminal um *script* é executado com uma série de comandos. O nome dele é `.bashrc` e você pode acessá-lo usando um editor de texto. Tente usar o editor `nano` digitando no seu terminal `nano .bashrc`. Desca até o final, digite `echo Hello World!` e feche o `nano` com `CTRL + X`. Não se esqueça de salvar as alterações! Abra uma nova janela do Terminal e  divirta-se!



## 3. Comandos de Navegação

​	O principal comando para mudança de diretório é o `cd` (*Change Directory*). Para navegar entre os diretórios é necessário respeitar a ordem de hierarquia. Assim, seguindo o exemplo acima, se estivermos no diretório `/home/Documents`  e quisermos ir para o diretório `/home/Documents/poli/skyrats`  temos que digitar:

```
cd poli
cd skyrats
```

​	Ou então podemos passar o endereço em apenas uma linha:

```
cd poli/skyrats
```

​	Em ambos os casos acima o resultado é o mesmo.

​	Mas e se estivermos no diretório `/home/Documents/poli/skyrats` e quisermos voltar para o diretório `/home/Documents` ? Para "subir" na hierarquia, ou seja, voltar nos diretórios usamos o `cd ..`.

**Exemplo:**

```
cd ..
cd ..
```

​	Podemos também dar o endereço em uma linha assim como no caso anterior:

```
cd ../..
```



### Dicas de Navegação

* O comando  `ls` (*list*) lista arquivos e diretórios existentes no diretório em que você se encontra. Use com frequência para se localizar em qual diretório você precisa entrar ou qual arquivo acessar;

* A tecla [*TAB*] completa o que você está escrevendo. Assim, se você já tiver escrito `Docu` e apertar a tecla [*TAB*] o Terminal irá completar para `Documents` para você;

  * **Nota:** Para que o [*TAB*] funcione é necessário que exista algum arquivo ou diretório com o nome que você deseja dentro do seu diretório atual. O comando não adivinha o que você quer;

* O diretório `/home` pode ser chamado de `/~`. Podemos reescrever o exemplo do tópico **1.** como:

  ```
  ~/Documents/poli/skyrats
  ```

* Digitar apenas `cd` no terminal irá te levar até a sua `/home`;



## 4. Criando e Removendo Arquivos e Diretórios


### Criando Diretórios

Para criar diretórios é usado o comando `mkdir` (*make directory*).

**Exemplo:**

```
mkdir MeuDiretorio
```

​	Assim, é criado um novo diretório chamado MeuDiretorio dentro do diretório em que você está localizado.



### Argumentos

​	Alguns comandos do terminal possuem **argumentos**. Estes afetam o comando em questão de diversas maneiras. eles são escritos após o comando, seguido de um `-`. 

​	**Exemplo:** O comando `ls` possui diversos argumentos possíveis de serem usados como `-a` (*all*) e `-l`.  O argumento `-a` faz com que o Terminal liste, além dos dados já listados, arquivos ocultos enquanto o argumento `-l` mostra dados de permissão dos arquivos, tamanho dos arquivos entre outras informações. Para a sintaxe apenas digite o argumento ao lado do comando: `ls -a` ou `ls -l`. 
Caso você queira usar dois argumentos você pode apenas escrever um em sequência do outro:`ls -al`

Para obter inforações dos diversos argumentos de um comando, existe o argumento `--help` ou `-h`. O Terminal irá lhe mostrar todos os argumentos existentes para o determinado comando: `ls --help`.



### Removendo Arquivos e Diretórios

Para remover um arquivo usamos o comando `rm` (*remove*) e logo em seguida o nome do arquivo que queremos apagar.

**Exemplo:**
```bash
rm meuArquivo.pdf
```

Para remover diretórios usamos o comando `rm` junto com o argumento `-r` (*recursive*) e em seguida o nome do diretório a ser removido.

**Exemplo:**

```bash
rm -r MeuDiretorio
```

​	**Atenção:** Após remover um diretório com `rm -r` você apagará todos os arquivos que ele contém, portanto use o comando com cuidado!



## 5. Movendo, Copiando e Renomeando Arquivos e Diretórios


### Copiando Arquivos e Diretórios

Para copiar um arquivo é usado o comando `cp` (*copy*). Esse comando recebe como primeiro argumento o nome do arquivo que será copiado e, como segundo argumento, o nome que queremos dar à sua cópia. 

**Exemplo:**

```
cp arquivo1 arquivo2
```

​	No exemplo acima estamos copiando o conteúdo de `arquivo1` e renomeando como `arquivo2`. Ambos os arquivos estarão no diretório em que você está localizado. Para copiar um arquivo para outro diretório devemos dar o caminho, além do nome.

**Exemplo:**

```
cp arquivo1 ~/Documents/arquivo2
```

​	Acima o `arquivo1` foi copiado para o diretório `Documents` e renomeado como `arquivo2`.  Da mesma forma podemos copiar um arquivo de outro diretório para o diretório atual ou até mesmo copiar um arquivo de um diretório qualquer para outro diretório qualquer, basta apenas dar o caminho antes do nome do arquivo. Toda a teoria de **Caminhos** se aplica aqui.

​	O comando `cp` apenas consegue copiar arquivos. Para copiar um diretório é necessário usar o argumento `-r` (*recursive*). 

**Exemplo:**

```
cp -r dir1 dir2
```

### Movendo e Renomeando Arquivos e Diretórios

​	De maneira análoga ao `cp` aqui iremos usar o `mv` (*move*). Esse comando recebe no primeiro argumento o nome do arquivo que será movido e, como segundo argumento, o caminho de destino desse arquivo. 

**Exemplo:**

```
mv caio.py ~/Documents/FariaLima
```

​	Aqui estamos movendo o arquivo `caio.py` para o diretório `FariaLima`.

​	O terminal não possui um comando específico para renomear. Para realizar essa função usamos o próprio comando `mv` pois sempre que você move um arquivo/diretório você tem a opção de **renomear** ele (igual no comando`cp`). Imagine que estamos movendo um arquivo de um diretório para o mesmo diretório mas no processo estamos mudando o nome dele.

**Exemplo:**

```
mv caio.py farialimer.py
```

​	No exemplo acima estamos renomeando o arquivo `caio.py` para `farialimer.py`. O que estamos fazendo de fato é mover o arquivo para o mesmo diretório em que estamos, mas no processo mudamos o nome dele.

​	Se quisermos mover para outro diretório, mas mudar o nome no processo é só dar o caminho do diretório de destino.

**Exemplo:**

```
mv caio.py ~/Documents/FariaLima/farialimer.py
```

**Dica:** para os comandos `cp`, `mv`, `rm` recomendo usar o argumento `-v` (*verbose*). Ele mostra no seu terminal o que foi feito (qual arquivo foi copiado, movido e para onde ele foi), assim você consegue ter maior certeza e segurança no que você está fazendo.



## 6. File Globbing - Caracteres Coringa

​	Os *Caracteres Coringa* auxiliam a filtrar arquivos e diretórios que possuem semlhanças nos nomes. Assim, você consegue mover, renomear, listar ou copiar uma série de arquivos de uma vez só se todos estes possuírem nomes ou formato semelhantes. Darei aqui exemplos usando o comando `ls` mas saiba que o mesmo pode ser aplicado ao `cp` , `mv` também.

​	Imagine que temos um diretório com os seguintes arquivos:

```
exemplo12
Exemplo
Exemplo1
Exemplo2
Exemplo231
Exemplo3
arquivo12
arquivo123
Arquivo100
Arquivo5
```

​	O principal caracter coringa que usamos é o `*`. Tente ler esse comando como "qualquer coisa". 
	
Se usamos ele no começo, tudo que está depois dele é obrigatoriamente considerado, sem importar o que vem antes. Nesse caso, ele faria referência a arquivos ou diretórios com o mesmo final. 

**Exemplo:**
```
Input: ls *12
Output: exemplo12
		arquivo12
```
Aqui estão listados arquivos que possuem **qualquer coisa** no começo, mas terminam com "*12*".

Se usamos o caracter no final, ele fará referência a arquivos ou diretórios com o mesmo começo. 

**Exemplos:** 

```
Input: ls Exemplo*
Output: Exemplo
		Exemplo1
		Exemplo23
```

​	Aqui estão sendo listados todos os arquivos que começam com "*Exemplo*" e possuem **qualquer coisa** depois.


​	Lembrando que existe diferença entre caracteres maiúsculos e minúsculos ainda que eles representem a mesma letra do alfabeto.

## 7. Agrupando e Compactando Arquivos e Diretórios


### Conceitos

​	Antes de sair aprendendo comandos vamos entender conceitualmente a diferença entre **agrupar** e **compactar**.

* **Agrupar**  - Quando agrupamos uma série de arquivos nós geramos um novo arquivo que contém todos os arquivos que agrupamos. Assim o **tamanho** do arquivo gerado será a **soma** dos tamanhos de todos os arquivos agrupados.
* **Compactar** - Quando compactamos uma série de arquivos estamos, assim como quando agrupamos, gerando um novo arquivo que contém todos os arquivos compactados mas com a diferença de que eles serão comprimidos, de maneira a deixar o tamanho do arquivo gerado menor que quando agrupado. É importante ressaltar que existem diversos tipos de algoritmos diferentes para compactação. Aqui iremos trabalhar o GZip.

### Agrupando

Quando se quer fazer uso de algum documento dentro de algum arquivo agrupado ou compactado deve-se extrair esse arquivo. 

Para agrupar é usado o comando `tar` (Tape Archive), mas é necessário passar algumas informações ao terminal para usar esse comando. Vamos dar uma olhada em como funciona a sintaxe e vou explicando com mais calma o que cada coisa significa:

```
tar [o_que_deseja_fazer][f] [nome_do_arquivo_a_ser_criado][.tar] [arquivos_a_serem_agrupados] 
```

​	CALMA, OK? Eu sei que parece muita coisa, mas é bem mais tranquilo do que parece. Antes de mais nada saiba que aqui os colchetes `[]` estão apenas indicando o espaço onde vão os comandos. Eles não fazem parte do comando em si. Dito isso vamos por partes:

* o_que_deseja_fazer: Aqui você vai ter algumas opções, mas só vamos trabalhar duas delas:
  * c (*create*) - usado para criar um arquivo agrupado;
  * x (*extract*) - usado para extrair um arquivo agrupado ja criado;

* f (*file*): só escreve `f` que é sucesso. É obrigatório;
* nome_do_arquivo_a_ser_criado: sugestivo, não?;
* .tar: todo arquivo agrupado pelo comando `tar` é de extensão `.tar`, então tem que ter no final do nome do arquivo criado;
* arquivos_a_serem_agrupados: sugestivo parte2 o retorno;

**Exemplo:**

```
tar cf exemplo1.tar *png
```

​	No exemplo acima estamos **criando** um arquivo agrupado `.tar` chamado `exemplo1` que contém todos os arquivos de extensão `.png` do diretório em que estamos. Aqui os conceitos de *Caracteres Coringa* podem ser úteis pra filtrar os arquivos que você quer agrupar.

```
tar xf exemplo1.tar
```

​		Acima estamos **extraindo** todo os arquivos do `exemplo1.tar` pro diretório atual. Podíamos dar um caminho no final, ou até mesmo extrair arquivos específicos:

```
tar xf exemplo1.tar foto1.png
```

```
tar xf exemplo1.tar -C ~/Documents/ExtractedFiles
```

​	Como visto no exemplo, para dar o caminho é necessário adicinoar o `-C`.



### Compactando

​	Para compactar é bem mais fácil. Usamos apenas o comando `gzip` com o argumento `-k` (*keep*)  e escrevemos o nome do arquivo/diretório que queremos compactar. Não estranhe, mas seu arquivo compactado terá duas extensões sendo uma a original do arquivo e uma `.gz`.

**Exemplo:**

```
gzip -k foto1.png
```

​	Usamos o `-k`  para criar um backup do nosso arquivo original. Caso não usemos ele o gzip irá sobreescrever o arquivo original. É muito mais seguro mantermos uma cópia do original, copiarmos ele e compactarmos a cópia.

​	Para descompactar o processo é o mesmo mas é usado o comando `gunzip`

**Exemplo:**

```
gunzip *gz
```

​	No exemplo acima estamos descompactando todos os arquivos compactados do diretório, mas você pode descompactar um arquivo específico ou uma série de arquivos que você filtrar.

​	Você pode ainda agrupar e compactar arquivos num comando só. Para isso usamos o `tar` de maneira semelhante ao agrupamento mas acrescentamos um `z`(*zip*) e alteramos a extensão para `.tgz`.

**Exemplo:**

```
tar czf exemplo.tgz *png
```



## 8. Procurando Arquivos



Para realizar a busca por um arquivo é usado o comando `find`. Logo após o comando é necessário dizer o diretório em que você irá realizar a busca. Em seguida existem várias opções de busca. Veremos aqui a mais usada que é filtrar por nome. Para isso é usada a flag `-name`.

**Exemplo:**

```
find ~/Documents -name colombini.py
```

​	Estamos realizando uma busca por um arquivo chamado `colombini.py` no diretório `Documents`. Tente sempre ser o mais preciso no diretório de busca. Apesar de você poder procurar por um arquivo desde a `root` sua pesquisa pode ser mais demorada e com maior gasto computacional. 

​	Outra ferramenta que temos para realizar buscar é o `locate`. Apenas digite o comando e o arquivo/diretório que deseja buscar.

**Exemplo:**

```
locate colombini.py
```

​	Aqui estamos procurando em todos os lugares do computador pelo arquivo `colombini.py`

```
locate .py
```

​	Já no exemplo acima estamos procurando por todo o qualquer arquivo `.py`

​	Mas afinal, qual a diferença entre o `find` e o `locate`? O `find` faz uma varredura nos seus diretórios até achar o que você pediu. Assim, as coisas são atualizadas em tempo real. Se você criar um diretório novo o `find` irá buscar ele.
​	 O locate é um pouco diferente. Ele faz uso de um **banco de dados interno** do seu computador. Esse banco de dados é atualizado toda vez que seu computador é inicializado. Assim, se você criar um diretório ele ainda não vai estar registrado nesse banco de dados e você não irá encontrá-lo com o `locate`. 

Caso você queira, você pode atualizar na mão esse banco de dados. Apenas use o comando `updatedb`. Caso você apenas digite o comando irá perceber que deu erro. Isso é porque você não tem permissão para acessar esse comando. Vamos entender como isso funciona.

### Permissões

​	O seu sistema operacional te priva de executar alguns comandos como forma de te proteger de si mesmo. Isso porque você pode acidentalmente remover arquivos importantes ou instalar o que não deve. Lembra quando você executava arquivos como administrador no Windows? É algo próximo. 
​	Mas como eu uso isso no Linux? Simples! Existe o comando mágico `sudo` (*Super User Do*). Assim conseguimos atualizar nosso banco de dados da seguinte maneira.

**Exemplo:**

```
sudo updatedb
```

​	Perceba que sempre que você usar o `sudo` o Terminal irá pedir sua senha. 
​	**Atenção:** Você ganha permissão pra fazer quase tudo no seu computador com o `sudo`. Portanto use com cuidado! Tome **muito** cuidado com o `sudo autoremove` e coisas do tipo.



### Best argument ever

`--help` ou `-h`, quando usado com qualquer comando te lista as possibilidades do comando e te ajuda a usá-lo.
