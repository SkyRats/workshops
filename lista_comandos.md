# Lista de Comandos - ROS

## Terminal

Esses são os mais comuns. Se você digitar só o início do comando (tipo `rostopic`) ele deve te dar a lista de todos. Colocar `-h` no final pede ajuda sobre a sintaxe.

### Topics
```bash
# Lista todos os tópicos ativos
rostopic list

# Informações sobre um tópico
rostopic info [tópico]

# Vê o que tá sendo publicado no tópico
rostopic echo [tópico]

# Vê a frequência com que estão publicando no tópico
rostopic hz [tópico]

# Publica no tópico
rostopic pub [tópico] [tipo de mensagem] [args...]
```

### Messages
```bash
# Lista todas os tipos de mensagem (são muitos kkk)
rosmsg list

# Informações sobre um tipo de mensagem
rosmsg show [mensagem]
```

### Services
```bash
# Lista todos os serviços
rosservice list

# Informações sobre um serviço
rosservice info [serviço]

# Chama um serviço
rosservice call [serviço] [args...]
```

### Nodes
```bash
# Lista todos os nodes
rosnode list

# Informações sobre um node
rosnode info [node]
```

### Params
```bash
# Lista todos os parâmetros
rosparam list

# Lê um parâmetro
rosparam get [param]

# Escreve em um parâmetro
rosparam set [param] [valor]
```

### Execução
```bash
# Inicia o ROS
roscore

# Executa um node
rosrun [package] [node]

# Executa um launchfile (não requer roscore)
roslaunch [package] [arquivo .launch] [argumento:=valor ...]
```

### ROS Bags
```bash
# Grava os tópicos 1, 2 e 3
rosbag record [topico1] [topico2] [topico3] e 3

# Grava todos os tópicos
rosbag record -a

# Executa um rosbag
rosbag play [nome_da_rosbag].bag
```

### Outros
```bash
# Acha um package e dá cd pra ele
roscd [package]

# Grafo dos tópicos
rqt_graph

# RViz (visualização de mensagens)
rviz
```

### Catkin
```bash
# Cria o workspace (deve ser executado DENTRO DA PASTA SRC DO WORKSPACE)
catkin_init_workspace

# Compila o workspace
catkin build

# Limpa o workspace (não apaga os packages)
catkin clean

# Deinicializa o workspace
catkin clean --deinit

# Cria um package (execute dentro da src)
catkin_create_pkg [nome no package] [dependencias...]
```

---

## Python

Os comandos não estão em ordem pra serem executados em um programa, apenas listados.

```python
# Essa linha precisa ser a primeira de todo código
#!/usr/bin/env python

# Tudo que vc faz passa por aqui, precisa importar
import rospy

# Declara que o programa é um node (NECESSÁRIO)
rospy.init_node("nome_do_node")

# Cria um Publisher
pub = rospy.Publisher("nome_do_topico", TipoDeMsg, queue_size=10)

# Publica uma mensagem
pub.publish(ObjetoMensagem)

# Cria um Subscriber
rospy.Subscriber("nome_do_topico", TipoDeMsg, funcao_de_callback)

# Deixa o programa executando (sem fazer nada)
rospy.spin()

# Cria um Rate
rate = rospy.Rate(frequencia_Hz)

# Espera completar o ciclo do rate
rate.sleep()

# Verifica se o ROS fechou (geralmente usado como condição em um while)
rospy.is_shutdown()
```