# ROS - Robot Operating System

## Antes de tudo...

#### Digamos que a gente quer construir um software para um drone autônomo

Queremos um drone **autônomo** com software **robusto**, algorítmos de estimação de posição, visão computacional, máquinas de estados e softwares de segurança...

### Isso requer um conhecimento muito específico 

Um projeto complexo como esse é **muito** difícil para ser implementado "do zero" por qualquer indivíduo sozinho, ou até mesmo um laboratório ou instituição.

> Palavras da organização ROS

Pra um projeto como esse, é necessário **trabalho colaborativo para o desenvolvimento de softwares de robótica**, e é **exatamente** pra isso que o ROS existe.

> ROS was designed specifically for groups [ ... ] to collaborate and build upon each other's work

### Robot Operating System

> ROS is an open-source, meta-operating system for your robot, a flexible framework for writing robot software. It is a collection of tools, libraries, and conventions that aim to simplify the task of creating complex and robust robot behavior across a wide variety of robotic platforms.

Mas pera, o que é um _framework_?

> Conjunto de ferramentas (softwares), para abstrair códigos comuns, de funcionalidade "genérica" em um projeto.



[Dá uma olhada no que esse bb(ROS) pode te oferecer](<https://index.ros.org/packages/page/1/time/>)



![https://docs.google.com/drawings/d/1N3skvSyzZj_dWzCqwEfsNd3gtwTNGFDwpm_TM__Vk2s/edit](https://docs.google.com/drawings/d/1N3skvSyzZj_dWzCqwEfsNd3gtwTNGFDwpm_TM__Vk2s/pub?w=2312&h=1050)

## Como a Skyrats usa o ROS?

Usamos o ROS conforme as necessidades do projeto em que estamos trabalhando

* MAVROS
* CvBridge
* Gazebo
* bebop_driver, bebop_autonomy, bebop_msgs, bebop tools, _et cetera_
* _Whatever framework we  eventually need_

## Onde conseguir o tal ROS??

> [É só clicar aqui](http://wiki.ros.org/ROS/Installation)

E, para ter acesso a todos os packages ROS, [Clique aqui](<https://index.ros.org/packages/>)

A partir disso, cada _package_ (exceto os padrões) tem sua documentação e instalação separadas do ROS, em suas próprias plataformas.

# Como funciona o tal ROS??

## Grafos de Comunicação

### ROS Nodes

> Processos computacionais - Programas que escrevemos.
>
> Desenvolvidos usando uma biblioteca ros (roscpp em C++, e rospy em python)
>
> Programas que compartilham a informações por meio **mensagens** em **tópicos**

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

  

### Packages
> Estrutura de organização dos nodes - 1 package pode ter diversos nodes 
> Pense em um pacote de nodes
#### Packages são compostos de
* um arquivo `CMakeLIsts.txt`
* um arquivo `package.xml`
* uma pasta `src` - para códigos (principalmente em C) que serão compilados 
#### Eventualmente, podem ter:
* uma pasta `include` para definir headers (que devem ser especificados no CMakeLists.txt)
* uma pasta `msg`  para definir e criar mensagens específicas do _package_
* uma pasta `srv` para definir Services específicos do _package_
* uma pasta  `scripts` para executáveis
_PS. o comando `catkin_create_pkg` cria isso tudo sozinho pra vc_
Na dúvida, `rospack help` 

**Esses packages são organizados em um catkin workspace**, que nos permite trabalhar com packages ROS e compilar códigos em C++ facilmente.

### Exemplo: Entendendo um Package - Turtlesim

`opt/ros/[sua versao]/share/turtlesim`

`rosrun turtlesim turtlesim_node`

### MAVROS - Decolando um Drone

`import rospy`

`import mavros_msgs`

**Criando os Publishers**

Para isso, precisamos especificar:

* O tópico a ser publicado

* O tipo de mensagem a ser publicada

* O  queue_size

  * Mensagens a serem publicadas são guardadas numa lista (vc pode publicar em frequências diferentes do seu rospy.Rate). O queue_size estabelece o número máximo de mensagens a serem guardadas antes de serem descartadas.
* _queue_size_ pequeno - o último valor interessa mais/alta taxa de atualização
  * *queue_size* grande - previne perda de dados (ex: botão)
  
  

`pose_sub = Publisher('/mavros/setpoint_position/pose',PoseStamped, queue_size=10)`

Durante a execução do programa, publicaremos as mensagens passando um objeto - neste exemplo, um objeto do tipo PoseStamped - para o publisher.

`pose_sub.publish(goal_position)`

**Criando os Subscribers**

Para isso, precisamos especificar, além dos parâmetros da criação dos publishers, uma **função de _callback_**, que deve ser definida **antes** do subscriber. Esta, será responsável pelo **tratamento dos dados** recebidos pelo subscribers.

Ex:	`statesub = rospy.Subscriber('/mavros/state', State, state_callback)`

Onde a função armado_callback deve ser definida com um parâmetro - que será nesse caso, um objeto State -.

`def state_callback(state_data):`

Dentro da função de _callback_, podemos acessar atributos do `state_data`, como

`state_data.mode`

**Definindo os Services necessários**

Precisaremos de 2 services para decolar o drone

* Server para armar o drone
* Server para mudar o modo de voo

`arm = rospy.ServiceProxy('/mavros/cmd/arming', mavros_msgs.srv.CommandBool)`

Durante a execução do programa, esse service vai ser chamado de modo semelhante a uma função para a qual - neste exemplo - passamos um parametro do tipo mavros_msgs.srv.CommandBool

`arm(True)`
