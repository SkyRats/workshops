# ROS - Robot Operating System

## O que queremos fazer?

**Digamos que nós queremos construir uma tartaruga autônoma**. Vamos precisar de algorítmos de controle, integração de sensores, máquinas de estados, softwares de segurança e muitos outros...  Construir todo o código para cada um desses sistemas (sem falar na integração entre eles) seria muito complicado.

Para projetos maiores e mais complexos, **é quase impossível e bastante desnecessário implementar tudo do zero**. Muitos dos problemas já têm soluções disponíveis publicamente, e podemos investir nosso tempo aprimorando soluções novas. Ter um sistema que nos permite facilmente integrar funcionalidades nossas e de outros desenvolvedores seria muito legal...

**E é exatamente isso que o ROS faz**

## O que é o ROS afinal?

> Robot Operating System (ROS, sistema operacional de robôs) é uma coleção de frameworks de software para desenvolvimento de robôs, que fornece a funcionalidade de um sistema operacional em um cluster de computadores heterogêneo. ROS fornece serviços padrões de sistema operacional, tais como abstração de hardware, controle de dispositivos de baixo nível, a implementação de funcionalidades comumente usadas, passagem de mensagens entre processos e gerenciamento de pacotes.

Ou seja, o ROS é um ecossistema de softwares e ferramentas padronizadas que nos permite **integrar os diversos componentes** necessários para o funcionamento de um robô (ou de nossa tartaruga).

*Alguns recursos interessantes para procurar mais informações sobre o ROS e suas funcionalidades são a [ROS Wiki](http://wiki.ros.org/) e o [ROS Answers](https://answers.ros.org/questions/)*

## Como a Skyrats usa o ROS?

Usamos o ROS conforme as necessidades do projeto em que estamos trabalhando. Podemos mudar os pacotes utilizados, mas a estrutura por baixo permanece sempre a mesma. Alguns pacotes que usamos são:

* MAVROS
* CvBridge
* Gazebo
* bebop_driver, bebop_autonomy, bebop_msgs, bebop tools, _et cetera_.

## Como funciona o ROS?

O funcionamento do ROS é representado por um **Grafo de comunicação**, que organiza a interação entre os programas através de tópicos e serviços.

Para iniciar o ROS, usamos o comando `roscore` em um terminal

### Nodes

Os programas (em C++, Python ou Lisp) que participam na execução do ROS são chamdos de ***Nodes*** (ou Nós). Na verdade, qualquer programa que queira interagir com outros _nodes_ ou usar uma funcionalidade do ROS **é obrigado a se declarar como um node** no código (veremos como fazer isso mais para a frente).

Para ver os _nodes_ rodando no momento, executamos o seguinte comando em um outro terminal:

```
rosnode list
```

Note que, no momento, temos apenas um _node_ em funcionamento, o `/rosout`. Para executar um programa (que seja um _node_), utilizamos o comando `rosrun`, com a seguinte sintaxe

```
rosrun package_name program_name
```

Vamos começar executando o turtlesim, o simulador de tartarugas. Ele está contido no package _turtlesim_, e o simulador em si corresponde ao programa _turtlesim_node_.

```
rosrun turtlesim turtlesim_node
```

Veja que o programa roda e abre a linda janelinha do turtlesim. Examinando novamente os _nodes_ em execução, vemos que apareceu o `/turtlesim`.

**Comandos importantes:**
- `rosnode list`: lista todos os _nodes_ ativos
- `rosnode info node_name`: dá informações sobre um _node_ específico.

### Topics

Mas como esses _nodes_ se comunicam entre si? A forma mais comum é através de _topics_. Os tópicos funcionam como caixinhas de correio: um _node_ coloca uma mensagem em uma certa caixinha, e depois um outro _node_ pode ir nessa caixinha e ver a mensagem que foi colocada. No ROS, dizemos que um _node_ do tipo _Publisher_ publica mensagens em um _topic_, e um _node_ do tipo _Subscriber_ se inscreve nesse _topic_, recebendo todas as mensagens que são publicadas nele.

Vamos ver os tópicos atualmente em execução com o comando `rostopic list` em um terminal. Vamos examinar, por exemplo, o tópico `/turtle1/pose`, com o comando `rostopic info /turtle1/pose`:

```
Type: turtlesim/Pose

Publishers:
 * /turtlesim (http://henrique-Q550LF:38043/)

Subscribers: None
```

Esse tópico é publicado pelo _node_ `/turtlesim`, com mensagens do tipo `/turtlesim/Pose`. Neste tópico, o simulador publica a posição da tartaruginha turtle1. Vamos ver o que ele está publicando com o comando

```
rostopic echo /turtle1/pose
```

Uma ferramenta importante para visualizar o que está acontecendo é o _rqt_graph_. Executando `rqt_graph` em um terminal, vemos a seguinte tela:

![rqt_graph](images/rqt_graph.png)

Os _nodes_ são as elipses, os tópicos são os retângulos, e as setas indicam o fluxo de dados. Nesse caso, o /turtlesim publica mensagens no tópico /turtle1/pose, e um _node_ correspondendo ao nosso terminal com `rostopic echo` está inscrito nesse tópico.

Vamos analisar agora o tópico `/turtle1/cmd_vel`. Vemos que não há nenhum programa publicando nele, e o turtlesim é o único Subscriber. Nesse tópico, podemos publicar mensagens de velocidade, e o turtlesim irá recebê-la para fazer a tartaruga andar. O interessante disso é que nós não precisamos saber dos detalhes de como ele faz a tartaruga andar, basta publicarmos uma mensagem padrão nesse tópico e a mágica acontece.

Essa funcionalidade é implementada pelo seguinte node:

```
rosrun turtlesim turtle_teleop_key
```

Esse programa traduz

**Obs.:** Tópicos *não* são programas. Eles só começam a existir quando um _node_ inicia um Publisher ou Subscriber.

**Comandos importantes:**
- `rostopic list`: lista todos os tópicos
- `rostopic info /topic_name`: dá informações sobre um tópico específico
- `rostopic echo /topic_name`: imprime na tela todas as mensagens publicadas em um tópico específico
- `rostopic pub /topic_name msg_type args`: publica uma mensagem em um tópico
- `rostopic find msg_type`: encontra tópicos com um certo tipo de mensagem

### Messages

### Services

### Packages
Todo software ROS é organizado em **packages**. Eles são um jeito modular e organizar pedaços de código com funções diferentes, e geralmente estão presentes no nosso **catkin workspace**.
Cada package ROS é (idealmente) independente dos códigos presentes nos outros códigos, e pode conter **nodes**, **messages**, **config**'s, **libraries** ou qualquer coisa que constitua um módulo útil.
>> In general, ROS packages follow a "Goldilocks" principle: enough functionality to be useful, but not too much that the package is heavyweight and difficult to use from other software.

De maneira prática, um package ROS é organizado em um repositório "compilável", que contém:
* Um arquivo `CMakeLists.txt`

Nele, descrevemos as diretrizes de compilação dos códigos desse package.

* Um arquivo `package.sml`, que fornece informações básicas sobre o código como
    * Versão
    * Nome
    * Informações dos desenvolvedores
    * Licensa
    * Balela, perfumaria

* Uma pasta `src`, onde encontramos todos os codigos fontes que serão compilados

* Uma pasta `scripts`, para guardar scripts executáveis (python, bash, etc)

* Uma pasta `include/package_name`

Nela, colocamos todos os **headers C++** - os famosos .h. Para serem reconhecidos por este e por outros pacakges ROS

* Além destas, podemos ter pastas para definir ROS **messages** e **services**, denominadas
    * `msg`
    * `srv`

* Uma pasta `launch` para guardar os arquivos launchfiles

#### Criando o package
Putz, mas como eu vou lembrar de criar todas essas pastas?
Resposta: ~~não vou~~

Para a criação de um package, usamos o comando 
`catkin_create_pkg`

Além desse comando, temos vários outros para manipular packages, como

* `rospack` - obter informações do package
* `rosdep` - instala dependências de um package
Exemplo: `rosdep install PACKAGE` instala as dependências do package `PACKAGE`

### Workspaces
Todos os packages ROS que desenvolveremos estarão organizados em **workspaces**, para organizarmos os códigos que precisamos para determinada aplicação. Esses são os **catkin workspaces**, uma pasta onde modificamos, compilamos e instalamos packages.
A carinha de um workspace...
```
workspace_folder/         -- WORKSPACE
  src/                    -- SOURCE SPACE
    CMakeLists.txt        -- The 'toplevel' CMake file
    package_1/
      CMakeLists.txt
      package.xml
      ...
    package_n/
      CMakeLists.txt
      package.xml
      ...
  build/                  -- BUILD SPACE
  devel/                  -- DEVELOPMENT SPACE (set by CATKIN_DEVEL_PREFIX)
    bin/
    etc/
    include/
    lib/
    share/
    .catkin
    env.bash
    setup.bash
    setup.sh
    ...
  install/                -- INSTALL SPACE (set by CMAKE_INSTALL_PREFIX)
    bin/
    etc/
    include/
    lib/
    share/
    .catkin             
    env.bash
    setup.bash
    setup.sh
```

* `src`, nosso velho amigo

Na pasta `src` que estarão todos os códigos (compiláveis) que desenvolveremos - src <= source code <= código fonte.

* `build` irá guardar todos os informações e arquivos intermediarios de compilação do cmake.

* `devel` é onde todos os resultados das compilação estão, os binários e executáveis

* `install` os programas podem ser instalados no computador no diretório install, com o comando `make install`, por exemplo DEBUG

#### Como compilar o workspace

`catkin build` x `catkin_make`

#### Como usar o workspace
Para "entrar" no workspace, usamos os chamados **environment setup files**, que são basicamente scripts bash que configuram variáveis do sistema para que o sistema reconheça o seu catkin workspace.
Esses arquivos estão em `devel/`, e o que costumamos usar (para o terminal bash) eh o `devel/bash`.
Para usar o workspace então, precisamos dar o comando

`source ~/[nome_do_workspace]/devel/setup.bash`

`source /opt/ros/melodic/setup.bash`

### Roslaunch
O roslaunch é uma ferramenta que serve para **rodar diversos nodes ROS ao mesmo tempo**, e setar parametros no Parameter Server do ROS - e rodar outros arquivos launch :).
Para usá-la, criamos arquivos launch (um arquivo XML)

```XML
<?xml version="1.0"?>
<launch>

    <node pkg="your_package" name="josé" type="your_node"/>

    <arg name="x" default="0"/> <!--Seta o parametro x como 0-->
   
    <include file="$(find outropackage)/launch/file2.launch"> <!--lansa o outro arquivo-->
        <arg name="y" value="1"/> <!-- y = 1 -->
    </include>
</launch>
```

#### Rodando o roslaunch

`roslaunch package_name file.launch`

#### ROS Bags
Ferramenta para gravação e reprodução de mensagens ROS .

* `rosbag record [topico1] [topico2] [topico3]`
* `rosbag record -a` grava todos os tópicos
* `rosbag play [nome_da_rosbag].bag`

#### Symlinks

`ln -s ~/git/[package] ~/[workspace]/src/`



## Referências
1. [ROS Wiki](http://wiki.ros.org/)
2. [Robot Operating System - Wikipedia](https://pt.wikipedia.org/wiki/Robot_Operating_System)
