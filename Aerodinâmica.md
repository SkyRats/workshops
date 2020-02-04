# Aerodinâmica

### Sustentação

A Aerodinâmica é o estudo do movimento do ar, particularmente de sua interação com sólidos. A aerodinâmica também é um subcampo da Mecânica dos Fluídos - uma parte da física destinada a estudar o comportamento de fluídos.

Apesar desse estudo abordar conhecimentos que você provavelmente conhecerá mais pra frente aqui na poli, tentarei explicar brevemente como funciona a sustentação e o voo de um Veiculo Aéreo não Tripulado (VANT), nesse caso, mais especificamente conhecido como Drone.

De maneira geral, os motores acoplados de hélices geram uma força de sustentação ao empurrar o ar para "baixo" como podemos observar na análise aerodinâmica (CFD) de uma hélice a seguir:

![velocity_core](https://github.com/SkyRats/workshops/blob/master/doc/velocity_core.png)

Mas como exatamente isso funciona?
A hélice ela é ligeiramente curvada de modo que ela crie um ângulo (AoA - Angulo de Ataque ou Angle of Attack) que ao ser girado empurra o ar para baixo e, partindo do princípio da **Terceira lei de Newton**, gera uma força de reação para cima levando a uma sustenção.

![img](https://static.sciencelearn.org.nz/images/images/000/000/670/embed/FLT_SCI_ART_02_WingsAndLift_AirflowAngleAttackDeflection_V3.jpg?1522296060)

Uma outra teoria que é muito utilizada, mas a qual não é muito eficiente para explicar esse caso é pelo princípio de Bernoulli, onde, devido ao formato curvado da hélice/asa o ar acaba se dividindo em duas massas de ar, uma para cima a qual acaba convergindo com outras o que gera uma maior velocidade e por consequência uma menor pressão e uma para baixo com maior velocidade e maior pressão. Essas diferenças entre pressões faz com que a aeronave seja "sugada para cima".![img](https://static.sciencelearn.org.nz/images/images/000/000/671/embed/Airflow-v4.png?1572924268)

![img](https://github.com/SkyRats/workshops/blob/master/doc/velocity_core.png)

### Movimentos

De maneira geral pensaremos em um drone quadcóptero (quatro motores), porém a física também será análoga para outros drones.

![Spring 2017 Sketches key](https://www.wired.com/wp-content/uploads/2017/05/spring_2017_sketches_key4.jpg)

Com base nisso, já deu pra ter uma noção geral de como o as hélices conseguem gerar sustentação, mas e  para subir e descer? Oras, isso é simples basta aumentar ou diminuir a velocidade dos motores (thrust) e isso fará com que mais ou menos força gerada pelo ar rebatendo na hélice em um determinado AoA.

Para os outros movimentos teremos que olhar para o drone em 3D.

![img](https://github.com/SkyRats/workshops/blob/master/doc/movements.PNG)

E o movimento de rotação em seu eixo(Yaw) , como funciona? Nesse caso já começamos a brincar com um pouco mais de física. Como podemos observar na imagem do movimento dos motores, o drone apresenta 4 motores, sendo que dois giram no sentido horário (motores 1 e 3) e os outros dois no sentido anti-horário (motores 2 e 4).

Essa configuração ocorre porque ao realizar o giro dos motores, uma componente semelhante a quantidade de movimento, é gerada: o momento angular e isso faz com que o drone gire em relação ao seu próprio eixo caso não seja equilibrada pelo par de forças que gira na outra diagonal.

Para ir pra frente e pra trás (Pitch) ou pra direita e pra esquerda (Roll), os pares de motores do mesmo lado tem velocidades reduzidas e isso faz com q ele tombe pra esse lado, inclinando o drone.

