# ROS2 aplicado ao drone
## **Entendendo a simulação**
### PX4-Autopilot
Explicar FCU e px4_sitl
### Mavlink e GCS
Mostrar a comunicação através da QGroundControl
### Mavros
mavros_node transformando mavlink em ROS2
### Voando no modo offboard
arm, set_mode e set_position (cuidados com spoiler do EP)
## **Entendendo a vida real**
### QGroundControl
Conexão por telemetria, wifi ou usb
### Conexão por nsh
Mostrar dentro da FCU
mavlink_shell.py e Qgroundcontrol
### Mavros não embarcado (telemetria ou wifi)
Parâmetros diferentes na mavros_node, outra entrada e baudrate diferentes
#### Voo não embarcado
Mostrar que o script é o MESMO que rodamos na simulação -> isso que dá valor para a simulação
### A odroid
Explicar conceito e importancia de um computador de bordo (companion computer) para aumentar o grau de autonomia do drone
Usar ssh para se conectar nela remotamente
#### Voo embarcado
Rodar a mavros dentro da odroid e rodar, dnv, o MESMO script da simulaçao