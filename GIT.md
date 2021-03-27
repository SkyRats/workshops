# Git: um Sistema de Controle de Versão Distribuído

## Por que controle de versão existe?

A programação antes da internet era muito diferente do que é hoje, porque era mais difícil acessar informação e compartilhar código, o que desacelerava a inovação. O surgimento de um mundo conectado exigiu novas formas de colaboração, e com elas novas ferramentas para colaborar.

Imagine que você é um programador da década de 70 tentando, por exemplo, fazer um drone voar sozinho. Você teria que programar tudo absolutamente do zero - desde como os motores são controlados até rotinas de pouso e movimentação por exemplo, e tudo isso antes de pensar em fazer o seu drone se controlar autonomamente! Isso acontece porque você não tem acesso ao trabalho de outros programadores, já que a única forma de compartilhar código era copiando em um disquete e mandando para outras pessoas. E esse problema não existia só em robótica - desenvolver uma nova aplicação muitas vezes envolvia escrever também o sistema operacional para o computador.

O desenvolvimento da internet permitiu que arquivos fossem compartilhados mais facilmente, possibilitando o trabalho remoto em um mesmo projeto, até de diferentes países. Assim, não era preciso inventar a roda de novo toda vez, mas existia um outro problema: como lidar com equipes de programadores em lugares diferentes, modificando todos ao mesmo tempo os mesmos arquivos?

Daí vem a necessidade de sistemas de controle de versão (SCV) para vários usuários. Esses sistemas permitem que várias pessoas façam modificações, e depois encontra um jeito de juntar todas elas automaticamente. Eles também permitem muito mais, como voltar em versões passadas dos seus arquivos, de uma forma simples e integrada.

Ok, mas esse é o workshop de Git, que é só um entre vários SCVs. Por que afinal a gente usa o Git? O que ele tem de especial?


## Por que o Git?

Primeiro, temos que mencionar que muitos desenvolvedores usam Git simplesmente porque é o SCV mais popular atualmente, então quase todo programador vai saber usar. Isso é importante porque queremos que o maior número de pessoas consiga usar o nosso código (foi pra isso que surgiu o controle de versão afinal).

Contudo, o Git é de fato superior e inovador em alguns aspectos:
1. É um SCV distribuído
Isso significa que cada programador tem uma cópia de todo o código no seu computador. Assim, você consegue trabalhar mesmo sem acesso à internet, e sincronizar suas mudanças quanto tiver uma conexão mais tarde;
2. Guarda *snapshots* dos arquivos, não só modificações 
Assim, você consegue retornar a uma versão antiga do seu projeto muito mais facilmente;
3. Tem um sistema de *branches* muito desenvolvido
Vamos falar de *branches* mais pra frente.


## Mas como isso funciona?

Agora que já sabemos porque o Git existe e porque usamos ele, vamos falar sobre o seu funcionamento. Antes de partirmos para os comandos, precisamos falar sobre um pouco de teoria.

O Git funciona a partir de **repositórios**. Você pode pensar em cada repositório como um diretório em que você pode chamar os comandos do sistema de controle de versão. Vale dizer que você pode ter subdiretórios, como em qualquer pasta.

Dentro de um repositório do Git, qualquer arquivo seu está em um de 5 estados:

![Os 5 estados de um arquivo no Git](./media/git.jpg)

1. Não versionado (*untracked*)  
Esses são os arquivos que não foram adicionados ao repositório ainda. É como se eles não existissem para o Git, então quase nenhum comando vai afetá-los;
2. Versionado  
Depois que você adiciona um arquivo ao seu repositório pela primeira vez, ele entra no seu *working directory*, e o Git começa a "ver" esse arquivo. Depois que você der o primeiro *commit* contendo esse arquivo, o Git vai conseguir guardar as modificações que ele sofre;
3. Adicionado (*staged*)  
Aqui os arquivos estão na *staging area*. As modificações colocadas aqui vão ser adicionadas ao histórico do repositório no próximo *commit*;
4. Em um *commit* local  
Com um *commit*, você coloca as suas modificações adicionadas no histórico do repositório. É como se os seus arquivos na *staging area* estivessem escritos a lápis - você ainda pode reverter essas mudanças facilmente. Quando você realiza um *commit*, você escerve à caneta - fica um registro mais permanente do que você fez, mas ainda relativamente fácil de voltar atrás;
5. Em um *commit* remoto  
Se um commit local é escrever à caneta, um *commit* remoto é como gravar em uma pedra. Qualquer um com acesso ao repositório pode ver exatamente o que você fez, e isso fica registrado praticamente para sempre* ;

(* é possível modificar um commit remoto, mas é extremamente não recomendado por causar vários problemas.)

### Na prática

Vamos mostrar com um exemplo como um arquivo passa pelas 4 primeiras etapas desse processo.
(As linhas com `$` na frente são comandos que você deve digitar e as sem, a saída desses comandos.)

1. Crie um repositório local do Git com `git init`
```bash
$ mkdir repo
$ cd repo
$ git init
Initialized empty Git repository in /path/to/repository/.git/
```
O repositório iniciado tem uma pasta `.git`
```bash
$ ls -a1
.
..
.git
```
2.  Adicione um arquivo na pasta do repositório
```bash
$ echo "Hello, world!" > hello.txt
```
3. Verifique o estado do repositório usando o comando `git status`
```bash
$ git status
On branch master

No commits yet

Untracked files:
 (use "git add <file>..." to include in what will be committed)

 hello.txt

nothing added to commit but untracked files present (use "git add" to track)

```
4. Adicione o arquivo à *staging area* usando `git add`
```bash
$ git add hello.txt
$ git status
On branch master

No commits yet

Changes to be committed:
 (use "git rm --cached <file>..." to unstage)

 new file:   hello.txt
```
5. Coloque em um commit usando `git commit`
Todos os commits precisam de uma mensagem; neste caso, a *flag* `-m` a fornece
```bash
$ git commit -m "Initial commit"
[master (root-commit) 1f3c605] Initial commit
1 file changed, 1 insertion(+)
create mode 100644 hello.txt
```


## Por que meu repositório tem galhos?

Repositórios do Git tem *branches*. Essas estruturas são uma forma de organizar o desenvolvimento de uma aplicação com várias partes. Assim, você pode trabalhar em diversas funcionalidades ao mesmo tempo sem que uma prejudique a outra. Por exemplo, um algoritmo de desvio de obstáculos para drones têm pelo menos duas partes que precisam trabalhar juntas: a detecção do obstáculo e o controle do drone em si. O desenvolvimento do algoritmo poderia ser separado então nas *branches* de `obstacle_detection` e `control`.

O que torna *branches* mais interessantes que diretórios separados é a capacidade de fundi-las, chamada de *merge*. Assim, no nosso exemplo, quando as partes do algoritmo estivessem prontas, ambas poderiam ser fundidas na branch principal (geralmente chamada de `main` ou `master`), gerando o programa completo.


## O que é esse *Remote Repository*?

Existe uma distinção entre repositórios locais e repositórios com *remote*. Um repositório local fica só no seu computador; você não consegue compartilhar código, mas pode controlar versões, criar branches e voltar para versões passadas dos seus arquivos. Um repositório com *remote* pode fazer isso, mas também pode sincronizar suas mudanças com um servidor para que outras pessoas acessem. Geralmente usamos o [GitHub](https://github.com/).

Existem duas formas de trabalhar com repositórios remotos: adicionando um *remote* a um repositório existente, ou copiando um repositório do servidor diretamente, chamado de **clonar** o repositório. É mais simples e comum clonarmos repositórios, então vamos usar isso como exemplo.

### Autenticação na linha de comando

Toda vez que você interage com o GitHub, ele vai pedir seu nome de usuário e senha. Para que isso não seja necessário, é recomendado [adicionar uma chave SSH à sua conta](https://docs.github.com/pt/github/authenticating-to-github/adding-a-new-ssh-key-to-your-github-account). Além de ser mais prático, é mais seguro, e no futuro próximo vai ser a única forma de usar o GitHub pelo terminal.

### Na prática

1. Clone um repositório do GitHub com `git clone`
Perceba que a URL para clonar é diferente dependendo do método de autenticação: HTTPS (com senha) ou SSH.
```bash
$ git clone git@github.com:SkyRats/workshops.git
# Ou https://github.com/SkyRats/workshops.git com HTTPS
```
2. Mude de *branch* com `git checkout`
```bash
$ git checkout linux_basics
```
3. Colete modificações do servidor com `git fetch` e `git merge`, ou `git pull`
```bash
$ git fetch
$ git merge # mesmo que git merge origin/master
# git pull é equivalente a git fetch & git merge
```
4. Faça *upload* de seus commits locais com `git push`
```bash
$ git push origin master
```

**Importante:** antes de dar `push` em um repositório, é recomendado dar `pull` para coletar *commits* que outras pessoas possam ter dado antes de você e, assim, impedir um conflito.

## É só isso?

Um uso extremamente básico do Git só necessita dos comandos que vimos até agora. Contudo, existem outras funcionalidades do Git que são muito úteis e que não mencionamos.

### `.gitignore`: deixando arquivos de fora do repositório

Muitas vezes, quando programamos, geramos arquivos binários usados para a execução dos nossos programas (como `.out` e `.o` em C ou `.pyc` em Python). O Git oferece uma ferramenta para impedir que binários sejam adicionados acidentalmente: o arquivo `.gitignore`. Ele deve ser colocado dentro do seu repositório, e contém um conjunto de expressões que dizem quais arquivos e diretórios não devem ser incluídos no seu repositório automaticamente. Um exemplo de regras de `.gitignore` é:

```
# Comentários começam com #

# Ignora todos os arquivos com extensão .a ...
*.a
# ... mas não lib.a
!lib.a

# Ignora todos os arquivos chamados TODO no diretório atual
/TODO

# Ignora o diretório build/ e todos os seus sub diretórios
build/
# Ignore todos .txt no diretório docs/, mas não em seus subdiretórios
doc/*.txt
# Ignora todos os .pdf em todos os subdiretórios de doc/
doc/**/*.pdf
```

### `git help`: *man pages* do Git

Todos os comandos que mostramos aqui tem várias *flags*; todas estão documentadas em *man pages*, acessíveis pelo comando `git help [nome do comando]`:
```bash
git help log
```

### `git log`: visualizando o histórico do seu repositório

Você pode ver todos os commits de uma branch do seu repositório usando `git log [nome da branch]`:
```bash
git log master
git log # Se não especificado, pega o log a partir do HEAD da branch atual
```

Existem muitas opções para o comando `git log`, que você pode ver usando o comando mencionado em `git help`.

### `git checkout`: volte no tempo

Já vimos que `git checkout` pode te levar para uma outra *branch*. Na verdade, o que o comando recebe não é uma branch, mas sim um commit qualquer; o nome das branches no final é só um atalho para o último commit (chamado `HEAD`) delas.

Isso significa que você pode passar qualquer *commit* para o `git checkout`. Com isso, você consegue encontrar um commit passado com `git log` e voltar o seu repositório para o estado anterior:
```bash
$ git log
commit d349a0a6a616f66e61b1a8jsjt345a0d5e22ec0e
Author: your-name <your.email@host.com>
Date:   Sat Feb 30 25:00:00 2021 -0300

   Initial commit
# Copie o hash do commit para o qual você deseja voltar
# e passe para `git checkout`
$ git checkout d349a0a6a616f66e61b1a8jsjt345a0d5e22ec0e
```

Como só *branches*  têm `HEAD`, ao "ir para o passado" você entra em um estado sem cabeça (*headless state*). Nele você pode mudar arquivos, fazer testes e dar commits para uma outra branch.

### `git stash`: guarde suas mudanças para depois

Um dos comandos mais úteis quando se trabalha com várias *branches* é o `git stash`. O *stash* guarda as mudanças que você realizou nos arquivos do seu repositório e as deleta do seu *working directory*. Assim, você pode mudar de *branch* e aplicar suas mudanças novamente. Ele tem alguns subcomandos:
* `push [-m <mensagem>] [-u] <nome do arquivo>`: Adiciona arquivos ao *stash*. Sem a opção `-u`, só adiciona as mudanças em arquivos já no repositório; com ela, adiciona modificações e novos arquivos;
* `pop <stash>`: Aplica as mudanças as remove do *stash*;
* `apply <stash>` Aplica as mudanças e NÃO as remove;
* `drop <stash>`: Remove as mudanças do *stash*;
* `branch <stash> <nome da branch>`: Aplica as mudanças do *stash* em uma nova *branch*;
* `list`: Lista os *stashes* existentes no repositório, mostrando suas mensagens também.

Ao aplicar um *stash*, é recomendado usar `git stash apply` seguido de `git stash drop` em vez de `git stash pop`. Isso porque, caso ocorra algum problema durante a aplicação do *stash*, você pode apagar as mudanças mas ainda tê-las salvas.

### `git diff`: compare arquivos em dois commits

Você pode comparar arquivos em dois commits diferentes usando `git diff <commit 1> <commit 2>`. Usando `git diff <commit>`, se compara o *commit* à `HEAD` da branch atual. Vale lembrar que nomes de *branches* são atalhos para o último commit da *branch*.
```bash
# Comparando a branch local com uma branch remota
$ git diff origin/main
# Comparando a `HEAD` de duas branches
$ git diff main feature
# Comparando commits pelos seus hashes
$ git diff 1d72b2c e2a3608
```

### `git reset`: um comando potencialmente perigoso

Existem só dois comandos que mencionamos que podem deletar informação de um repositório do Git: `git checkout` e `git reset`. Porém, só uma das opções dele é perigosa.

Usamos o comando com `git reset <opção> <commit>`. Existem 3 opções principais, dadas por *flags*:
* `--soft`: Retorna os arquivos não modificados ao estado do *commit*. Não altera os arquivos adicionados nem a *working tree*;
* `--mixed`: Opção padrão do reset - se você não especificar uma opção, esta será aplicada. Retorna os arquivos não modificados ao estado do *commit*. Remove os arquivos adicionados, mas não apaga suas modificações;
* `--hard`: **A opção perigosa**. Apaga **permanentemente** suas modificações locais que não estejam em um commit ainda. **Não use a menos que saiba MUITO BEM o que está fazendo**.

Vale ressaltar o comando `git reset HEAD`, ou seu equivalente mais curto `git reset --`. Ele aplica um reset `--mixed`, removendo os arquivos que você tinha adicionado para o próximo commit. Ou seja, se você adicionou um arquivo por engano, `git reset --` o remove para você da *staging area*.


## E se eu quiser saber mais?

Você pode acessar [aqui](https://www.notion.so/Git-888653ce74dd48d59c8db1ab698cb208) um tutorial (em inglês) que aborda conceitos como workflows do Git e como configurar um `.gitignore` global. Nesse mesmo link você vai encontrar uma lista de comandos com exemplos de algumas *flags* interessantes.

Existem diversos tutoriais na internet em que você pode aprender mais sobre Git; alguns examplos notáveis são os do próprio [GitHub](https://guides.github.com/) (em inglês) e da [Atlassian](https://www.atlassian.com/br/git) (que tem um serviço que concorre com o GitHub chamado BitBucket). Pessoalmente, recomendo ler em inglês caso você consiga, porque algumas traduções não são muito boas e podem confundir você, ainda mais se não conhecer muito do Git.

Por fim, se quiser muito aprender como o Git funciona, incluindo o que o Git faz debaixo dos panos para guardar todas as informações dos seus *commits*, você pode ler o livro [Git Pro](https://git-scm.com/book/en/v2). Foi dele que a maior parte do material de referência para este workshop veio.
