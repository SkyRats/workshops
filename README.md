# ROS - Robot Operating System

### Robot Operating System

> ROS is an open-source, meta-operating system for your robot, a flexible framework for writing robot software. It is a collection of tools, libraries, and conventions that aim to simplify the task of creating complex and robust robot behavior across a wide variety of robotic platforms.

Mas pera, o que é um _framework_?

> Conjunto de ferramentas (softwares), para abstrair códigos comuns, de funcionalidade "genérica" em um projeto.

## Como a Skyrats usa ~~deveria usar~~ o ROS?

* Integração
* Modularização
* "Dividir para Conquistar"

# Como funciona o tal ROS??

## Grafos de Comunicação - _peer to peer communication_

### Workspaces - _where the work begins_

Lugar que será reconhecido pelo ROS como o que contém tudo que iremos desenvolver

* Criando um workspace`mkdir [nome_do_workspace]` ``cd [nome_do_workspace] ` `mkdir src`

  Ou `mkdir -p [workspace]/src`  (parents)

* Precisamos ir até a`src` do workspace e iniciar o workspace `cd [workspace]/src`

  `catkin_init_workspace`

  **IMPORTANTE, não inicie o workspace fora da `src`**, isso inicia sua _home_ como um workspace, e você terá problemas depois na hora de `build`ar o workspace. Mas caso vc o faça, use `catkin clean --deinit`

* Então podemos compilar o workspace com `catkin build`

* Pastas criadas:
  * build - CMake stuff
  
  * devel - build targets
  
  * logs - registro da compilação
  
* Após buildar o workspace, será criado o arquivo `devel/setup.bash`, que precisaremos para indicar que o Ubuntu reconheça como executaveis os nodes do seu workspace com o comando `source ~/[workspace]/devel/setup.bash`

Podemos ter diversos workspaces configurados, para ultilizar intensamente algum deles (deixar configurado para todos os terminais que possamos abrir), podemos adicionar a linha `source ~/[workspace]/devel/setup.bash` no arquivo `~/.bashrc` (que é basicamente um script bash que roda toda vez que um terminal é aberto).

​	Uma prática comum é deixar diversas linhas comentadas no `.bashrc`, assim é só descomentar quando não quiser mais utilizar o workspace.

### Packages

> Estrutura de organização dos nodes - um package pode ter diversos nodes 
`catkin create pkg [pkg_name]`
#### Packages são compostos de

* um arquivo `CMakeLists.txt`
* um arquivo `package.xml`
* uma pasta `src` - para códigos (principalmente em C) que serão compilados 
* uma pasta `config` para definição de **parametros** que serão usados nos nodes
* uma pasta `launch` com arquivos `.launch`, dos quais falaremos mais a frente

#### Eventualmente, podem ter:

* uma pasta `include` para definir headers (que devem ser especificados no CMakeLists.txt)
* uma pasta `msg`  para definir e criar mensagens específicas do _package_
* uma pasta `srv` para definir Services específicos do _package_
* uma pasta  `scripts` para executáveis (os scripts tem que ser configurados como executáveis para rodar com `rosrun`, faça isso com o comando `chmod +x [script].py`)

**O conjunto desses packages forma o catkin workspace**, que nos permite trabalhar com packages ROS e compilar códigos em C++ facilmente.

* Alterando o ROS_PACKAGE_PATH (para compila o wokspace)

* `export ROS_PACKAGE_PATH=~/[workspace]/src:/opt/ros/kinetic/share`

  

#### Exemplo: packages no catkin_ws_bebop control_gui



### ROS Nodes

> Processos computacionais - Programas que escrevemos.
>
> Desenvolvidos usando uma biblioteca ros (ros/ros.h em C++, e rospy em python)
>
> Programas que compartilham a informações por meio **mensagens** em **tópicos**

#### Nodes em .cpp

* Organização dos arquivos

  * Arquivo que **só** roda o node

  * Arquivo(s) que definem o node que será rodado

    * Arquivo(s) gerais que resolvem o problema em questão

    * Arquivo que faz a integração do algoritmo com o ROS -> especifica para nossa aplicação
* `ros::init(argc, argv, "")` 
* `ros::Rate`
* `ros::spinOnce();`
* `ros::Time(), ros::Duration()`
* `ros::Publisher [pub_name] = nh.advertise<[msg_ype]>("topic", [queue_size])`
* `ros::Subscribe [sub_name] = nh.subscribe<[msg_type]>("topic", [queue_size], callback_function)`
* `ros::ServiceClient [client node] = nh.serviceClient<[msg_type]> ("srv");`




### ROS messages

> Uma estrutura de dados (uma classe) composta de tipos primitivos, que será usada para a comunicação nos tópicos.

* Ex: `mavros_msgs/OpticalFlowRad`:

  Composta por:

  `std_msgs/Header header
    uint32 seq
    time stamp
    string frame_id
  uint32* integration_time_us
  float32 integrated_x
  float32 integrated_y
  float32 integrated_xgyro
  float32 integrated_ygyro
  float32 integrated_zgyro
  int16 temperature
  uint8 quality
  uint32 time_delta_distance_us
  float32 distance`

  

### ROS Topics

![http://ros.org/images/wiki/ROS_basic_concepts.png](http://ros.org/images/wiki/ROS_basic_concepts.png)

>ROS ≈ Fórum
>
>Topicos são um **nome** para identificar o conteúdo da mensagem
>
>Os **Nodes** podem obter os dados de um tópico se inscrevendo nele - **Nodes Subscriber** - ou mudar os dados desse tópico publicando nele - **Nodes Publishers**.



#### 	Como obter:

* `rostopic list` - lista todos os tópicos ativos 
* `rostopic info [nome do tópico]` -  te diz
  * O tipo de mensagem publicada
  * Os publisher e subscribers
* `rosmsg show [tipo de mensagem]` - passa todos os parametros da mensagem
* `rostopic echo` - te mostra tudo que está sendo publicado nesse tópico
* Mostrar integracao_controle.py com interface

#### Como publicar em Tópicos pelo Terminal

Durante a execução do ROS, usar o comando

`rostopic pub [nome do tópico] [mensagem]`



### ROS Services

> Modelo mais apropriado pra "request/reply interactions" - comunicação direta entre nodes - que não são possiveis com a comunicação unilateral dos tópicos. Definido por **duas** estruturas de mensagens ( uma pro _request e outra pro reply_).

* Ex: /mavros/cmd/arming

  #### Como obter:

* `rosservice list` - lista todos os servers ativos.

* `rosserver info [nome do tópico]` -  te diz

  - O node que **recebe** o _request_
  - O tipo de mensagem de _request_
  - Os argumentos da mensagem

* Mostrar `rqt_graph` com alguma _state machine_

* Mostrar `rqt_plot`

#### Como chamar Services pelo Terminal

Durante a execução do ROS, usar o comando

`rosservice call [nome do service] [argumentos]`

#### Organização - Symlinks

Criar uma pasta git na `~/` e clonar todos os repositórios comuns para lá

```bash
cd ~/
mkdir git
cd git
git clone https://github.com/[PACKAGE]
```

Criar um **symlink** (symbolic link) dos packages clonados no(s) workspace(s)

`ln -s  ~/git/[PACKAGE] ~/[workspace]/src`

**IMPORTANTE: usar endereço global na criação do symlink**

### Exemplo: Decolando um Tello

* .py
* .cpp
  * Para compilar o .cpp corretamente, precisamos editar o CMakeLists.txt
  * Adicionar o roscpp ao find_packages
  * jutsu do `include_directories(${catkin_INCLUDE_DIRS})`
  * add_executable([node_name] src/[nodefile].cpp)
  * target_link_libraries([node_name] ${catkin_LIBRARIES})
