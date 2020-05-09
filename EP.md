# Exercício de ROS - Controlador de Posição

Esse exercício foi elaborado para treinar e fixar as habilidades desenvolvidas durante o Workshop de ROS. Ele trata de um problema muito comum na equipe (e em robótica no geral): o **controle de posição**, isto é, como enviar um agente móvel (como um drone ou uma tartaruga) para uma dada posição usando apenas comandos de velocidade. Isso é, de fato, o que temos que fazer em nossos drones indoor.

Neste EP, a tarefa consiste em **implementar um controlador de posição para a tartaruga do turtlesim** na forma de um **package do ROS**. Assim, o programa irá receber uma posição-alvo e dar comandos de velocidade para que a tartaruga chegue nesta posição. A forma de se passar as posições-alvo para o _node_ fica a seu critério, mas o objetivo é ser o mais fácil de integrar com outros packages quanto possível.

**O package deverá conter pelo menos:**
- Um ou mais nodes que implementem o controlador em si (**pode ser feito C++ ou Python**);
- Um **arquivo .launch** que abra tanto o turtlesim quanto o controlador.

Também é importante lembrar que o turtlesim recebe comandos de velocidade em apenas dois parâmetros: **velocidade linear em x** (movimento para a frente e para trás) e **velocidade angular em z** (girar para os lados). As demais velocidades são desprezadas pelo simulador. Não é permitido usar os serviços de teleport do turtlesim.

Para começar, recomendamos as seguintes reflexões:

1. Quais os tópicos que preciso observar? Como armazenar as informações publicadas neles?
2. Em que tópicos preciso publicar?
4. Como devo atualizar a velocidade da tartaruga?
3. Como irei passar a posição-alvo para o programa? Tópicos, serviços, input do usuário, uma combinação deles, nenhum dos acima...?

Mãos à obra e boa sorte!! Qualquer dúvida ou dificuldade, podem enviar nos grupos ou conversar com algum veterano.