# ROS - Robot Operating System

## O que queremos fazer?

**Digamos que nós queremos construir uma tartaruga autônoma**. Vamos precisar de algorítmos de controle, integração de sensores, máquinas de estados, softwares de segurança e muitos outros...  Construir todo o código para cada um desses sistemas (sem falar na integração entre eles) seria muito complicado.

Para projetos maiores e mais complexos, **é quase impossível e bastante desnecessário implementar tudo do zero**. Muitos dos problemas já têm soluções disponíveis publicamente, e podemos investir nosso tempo aprimorando soluções novas. Ter um sistema que nos permite facilmente integrar funcionalidades nossas e de outros desenvolvedores seria muito legal...

**E é exatamente isso que o ROS faz**

## O que é o ROS afinal?

> Robot Operating System (ROS, sistema operacional de robôs) é uma coleção de frameworks de software para desenvolvimento de robôs, que fornece a funcionalidade de um sistema operacional em um cluster de computadores heterogêneo. ROS fornece serviços padrões de sistema operacional, tais como abstração de hardware, controle de dispositivos de baixo nível, a implementação de funcionalidades comumente usadas, passagem de mensagens entre processos e gerenciamento de pacotes.

Ou seja, o ROS é um ecossistema de softwares e ferramentas padronizadas que nos permite **integrar os diversos componentes** necessários para o funcionamento de um robô (ou de nossa tartaruga).

*Alguns recursos interessantes para procurar mais informações sobre o ROS e suas funcionalidades são a [ROS Wiki](http://wiki.ros.org/), o [ROS Answers](https://answers.ros.org/questions/)*

## Como a Skyrats usa o ROS?

Usamos o ROS conforme as necessidades do projeto em que estamos trabalhando. Podemos mudar os pacotes utilizados, mas a estrutura por baixo permanece sempre a mesma. Alguns pacotes que usamos são:

* MAVROS
* CvBridge
* Gazebo
* bebop_driver, bebop_autonomy, bebop_msgs, bebop tools, _et cetera_

## Como funciona o ROS?

O funcionamento do ROS é representado por um Grafo de comunicação, em que cada programa é um . 



## Referências
1. [ROS Wiki](http://wiki.ros.org/)
2. [Robot Operating System - Wikipedia](https://pt.wikipedia.org/wiki/Robot_Operating_System)
