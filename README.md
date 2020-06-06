

# Photoshop



### 1. Imagem Bitmap x Vetor

​	Uma imagem *bitmap* é um **quadro (ou mapa) de pixels** onde cada pixel tem uma determinada cor. Assim, se você quiser expandir uma imagem bitmap ela irá perder resolução. 
​	Já uma imagem do tipo *vetor* é gerada a partir de de **curvas**. Deste modo o programa se preocupa com as proporções de cada elemento da sua imagem, te permitindo usar a mesma imagem para panfletos, flyers e outdoors.
​	De maneira geral usamos o Photoshop para trabalhar e editar imagens bitmap (geralmente fotografias) e o Illustrator para vetores (geralmete desenhos).



![A diferença entre o bitmap e vetor. - Sydra.pt](https://www.sydra.pt/wp-content/uploads/2017/12/a-diferenca-entre-bitmap-vetor-af4.jpg)





### 2. Sistemas de cores e Canais.

​	Como foi dito anteriormente cada pixel possui uma cor. O **Sistema de cores** são as cores bases que darão origem as cores da sua imagem, onde cada cor base é um canal. Assim, misturando as cores dos canais o programa interpreta e gera as cores da sua imagem.
​	Você pode considerar as cores como sendo coordenadas do sistema de cores.
​	Veremos aqui os seguintes canais: CMYK, RGB, Grayscale, HSV.



#### 	2.1 CMYK (Cyan, Magenta, Yellow, Key-Color)

​		Este sistema possui 4 canais (Ciano, Magenta, Amarelo, e Key-Color) e é usado majoritariamente para impressões. Qualquer imagem que você produzir que tenha como destino impressão deve ser feita em cima desse sistema de cor para que não haja incoerência de coloração com o material produzido no Photoshop. Repare inclusive que a sua impressora utiliza toners referentes a esse canal. 



![image-20200605195632243](/home/tei/.config/Typora/typora-user-images/image-20200605195632243.png)





Caso queira visualizar como as cores são geradas a partir desses canais da uma olhada nesse link:

​												https://www.w3schools.com/colors/colors_cmyk.asp



#### 	2.2 RGB (Red, Green, Blue)

​		O sistema **RGB** gera cores a partir dos canais Vermelho, Verde e Azul (duuuh). Este sistema é usado para imagens com finalidade **digital**, ou seja, **não serão impressas**. Posts e afins sempre devem ser feitos usando esse sistema de cores. O motivo disso é que o RGB consegue atingir cores hiper saturadas que o sistema CMYK não consegue.



![RGB-Slider | Capital Printing Print Shop in Austin TX](https://capitalprintingco.com/wp-content/uploads/RGB-Slider.png)



Para visualizar os canais de cor da uma olhada nesse link:

​												https://www.w3schools.com/colors/colors_rgb.asp



#### 	2.3 Grayscale

​		O **Grayscale** é composto apenas de um canal que vai do branco ao preto numa escala tonal de cinza. É uma conversão fácil de imagens coloridas para imagens preto e branco.



#### 	2.4 HSV (Hue, Saturation, Value)

​		Este sistema é um pouco mais complexo. O primeiro canal se chama **Hue** ou **Matiz** e ele vai determinar a cor em que você irá trabalhar (Roxo, Vermelho, Azul...). O segundo canal determina a **Saturação** (do cinza ao neon) da cor. Por fim terceiro canal é referente ao **Valor** da cor (Quão clara ou escura a cor é). 



![Color Sliders — Krita Manual version 4.3.0](https://docs.krita.org/en/_images/Color-slider-docker.png)

​	

​		O HSV é utlizado no Photoshop mais para a edição de cores a partir da ferramenta ADFSADGGZDG  do que como sistema de cor base para a sua imagem.

​		Para visulizar o sistema de cor entra nesse link:

​												https://alloyui.com/examples/color-picker/hsv.html



#### 	2.5 (extra) RGB x CMYK

​		Os sistemas RGB e CMYK são opostos e se complementam. Por exemplo: tomadas duas cores de um sistema, a soma delas irá resultar em uma cor do sistema oposto. Assim, as intersecções de um canal irão gerar o outro canal. Tente fazer o teste através dos links aí em cima. Note também que a soma dos três canais do sistema RGB resulta em branco, enquanto a soma dos três canais do sistema CMYK resulta em preto. Quando sua impressora não possui toner de tinta preta ela simula a cor desta maneira.

![Qual a diferença entre RGB e CMYK?](https://designermaodevaca.com/manager/upload/thumb-2-e0bd1e-qual-a-diferenca-entre-rgb-e-cmyk1.png)

### 3. Camadas

​	O Photoshop funciona com um sistema de **Camadas**. Imagine uma série de folhas transparentes empilhas e que você as olha de cima.



![Layer Basics](https://www.washington.edu/accessit/webdesign/student/unit4/pix/layers_example.gif)





​	Você pode alterar cada camada individualmente da maneira que desejar sem afetar as outras. Vamos usar esse conceito para 



### 4. Interface

​	A interface do Photoshop assusta no começo, mas ela é bem didática. Vamos separar por partes.



![Solved: Photoshop CC Work space too big - Adobe Support Community ...](https://community.adobe.com/legacyfs/online/776545_ps.jpg)



#### 4.1 Barra de Menus



![image-20200606003231161](/home/tei/.config/Typora/typora-user-images/image-20200606003231161.png)



​	Começando da parte superior esta é sua barra de Menu. Cada aba possui diversas opções referentes ao seu nome. As mais importantes são:

* Arquivo
  * Novo Arquivo
  * Abrir Arquivo
  * Exportar Arquivo
  * Salvar Arquivo
* Editar
  * Transformar
* Imagem
  * Modo (Altera o sistema de cores)
  * Ajustes
    * Brilho/Contraste
    * Levels (CTRL + L)
    * Curvas (CTRL + M)
    * Hue/Saturation (CTRL + U)
    * Balanço de Cor (Ctrl + B)
* Filtros
  * Filtro de Movimento
  * Filtro Gaussiano



#### 4.2 Menu de Opções



![image-20200606004201306](/home/tei/.config/Typora/typora-user-images/image-20200606004201306.png)



Essas são as opções referentes à ferramenta que você está trabalhando no momento. O menu pode ter drásticas alterações ao mudar de ferramenta.



#### 4.3 Painéis



![image-20200606004405397](/home/tei/.config/Typora/typora-user-images/image-20200606004405397.png)



​	É uma área completamente editável ao gosto do usuário. Na **Barra de Menu**, na aba **Janelas** existem diversas opções de janelas que podem ser agregadas à essa área. Fica a seu gosto pessoal! Apenas mantenha as **Camadas** de maneira à poder trabalhar com elas.



#### 4.4 Barra de Ferramentas



![image-20200606010602905](/home/tei/.config/Typora/typora-user-images/image-20200606010602905.png)



Aqui estão listadas todas as suas ferramentas disponíveis. Vamos passar pelas principais no próximo tópico.



### 5. Ferramentas

​	As ferramentas são os itens que usaremos para trabalhar em nossas edições. É importante frisar que não estão listadas todas as ferramentas do software aqui, estamos apenas discutindo as mais importantes para começar a trabalhar.
 Se atente à ferramentas que podem estar dentro de outras ferramentas, como por exemplo a ferramenta **Laço (L)**, **Laço Poligonal(L)** e **Laço Magnético(L)**. O atalho L pode o levar para qualquer uma das três ferramentas, sendo selecionada sempre a ultima ferramenta que foi utilizada dentre as opções. Para trocar dentre as ferramentas pressione com o **mouse** em cima do ícone dela que as outras opções serão mostradas. As ferramentas que possuem outras ferramentas com o mesmo atalho são indicadas com uma seta no canto inferior direito.

![image-20200605232515865](/home/tei/.config/Typora/typora-user-images/image-20200605232515865.png)

​																					 ![image-20200605232537487](/home/tei/.config/Typora/typora-user-images/image-20200605232537487.png)



#### 5.1 Ferramentas de Seleção



#### 	Mover (V)

​	Ferramenta usada para mover objetos. Se mover um objeto segurando **ALT** será criada uma cópia deste objeto.

![image-20200605231358967](/home/tei/.config/Typora/typora-user-images/image-20200605231358967.png)

​					

​	OBS: Para transformar a imagem (rotacionar e escalonar) use o atalho **CTRL + T**

#### 	

#### 	Letreiros de seleção (M)

​	Feramenta que cria caixa de seleção com formato geométrico. Caso você crie uma caixa de seleção segurando **SHIFT** ela será **simétrica**. Caso você segure **ALT** ela será criada a partir do **centro** da figura.



![image-20200605231916114](/home/tei/.config/Typora/typora-user-images/image-20200605231916114.png)

#### 	Laço (L)

​	Esta ferramenta lhe permite fazer uma seleção livre desenhando da maneira que lhe for conveniente sua caixa de seleção. Para **arescentar** uma seleção a uma caixa já existente segure **SHIFT** e desenhe sua caixa. Para **subtrair** segure **ALT** e desenhe. O ícone do cursor deve alterar. Caso você nõ feche o laço o Photoshop irá criar uma linha reta entre o ponto de início e o ponto em que você soltou o mouse. Essas dicas são válidas para todos os **Laços**.

![image-20200605233412127](/home/tei/.config/Typora/typora-user-images/image-20200605233412127.png)



#### 	Laço poligonal(L)

​	Funciona de maneira semelhante ao **Laço**, porém você cria poligonos a partir de pontos determinados arbitrariamente 

![image-20200605233629973](/home/tei/.config/Typora/typora-user-images/image-20200605233629973.png)

#### 	Laço Magnético (L)

​	Ferramenta de preguiçoso. Ela faz seleções automáticas a partir da cor da imagem.

![image-20200605233800496](/home/tei/.config/Typora/typora-user-images/image-20200605233800496.png)



#### 	Varinha Mágica (W)

​	Com a ferramenta selecionada clique em uma cor. O programa irá selecionar todos os pixels adjacentes que tenham cores semelhantes ao pixel selecionado. A sensibilidade pode ser alterada. Ótima ferramenta para remover fundos monocromáticos.

![image-20200605234113605](/home/tei/.config/Typora/typora-user-images/image-20200605234113605.png)

#### 	Seleção Rápida (W)

​	Funciona de maneira semelhante ao **Laço Magnético** mas ao invés de fazer a seleção por **linha** faz por **área**. 

![image-20200605234312385](/home/tei/.config/Typora/typora-user-images/image-20200605234312385.png)





#### 5.2 Ferramentas de Retoque



#### 	Pincel de Recuperação (J)

​	Essa ferramenta irá salvar a sua vida em diversos momentos. Faça uma seleção de uma determinada área. Essa área será substituida automaticamente por um padrão que o Photoshop encontrar ao redor da seleção. Geralmente fica bom.

![image-20200605235623547](/home/tei/.config/Typora/typora-user-images/image-20200605235623547.png)

#### 	Carimbo (S)

​	Essa ferramenta permite copiar uma determinada área da imagem e "carimbar" em outros lugares da imagem. Segure**ALT** e selecione uma área para ser seu "carimbo" e use sem pressionar nenhum botão.

![image-20200605235924732](/home/tei/.config/Typora/typora-user-images/image-20200605235924732.png)

#### 	Carimbo de Padrão (S)

​	Funciona de maneira similar ao **Carimbo**, mas cria novos padrões de textura.

![image-20200606000106701](/home/tei/.config/Typora/typora-user-images/image-20200606000106701.png)

​	

#### 	Borracha (E)

​	Funciona como uma borracha normal. Apaga a área selecionada.



#### 5.3 Ferramentas de Pintura 



#### 	Pincel (B) 

​	Pinta a área selecionada. A cor pode ser selecionada no final da caixa de ferramentas.

![image-20200606002329416](/home/tei/.config/Typora/typora-user-images/image-20200606002329416.png)





### 6. Máscara

​	A **Máscara** é um conceito que é aplicado à uma **Camada**. Ao por uma máscara numa camada apenas a parte selecionada pela máscara permitirá que alterações ocorram à camada. Assim, podemos aplicar filtros em locais específicos e podendo editar de maneira simples. Para aplicar uma máscara apenas clique no botão indicado.

![image-20200606010957923](/home/tei/.config/Typora/typora-user-images/image-20200606010957923.png)

​	Note que irá ser criada uma máscara ao lado da camada. Tudo o que for **preto** em sua máscara **NÃO** irá alterar a imagem, e tudo o que for **branco** irá **alterar**.









## Exercícios

### 	1. Cervelindo

​	Rejuvenesca o Cerveró.



![cerveroFeio](/home/tei/workshops/workshops/imagens/cerveroFeio.jpeg)



![cerveroArrumado](/home/tei/workshops/workshops/imagens/cerveroArrumado.jpg)



### 2. Galaranja

​	Com as imagens disponíveis na pasta fornecida recrie o Galaranja.

![galaranja](/home/tei/workshops/workshops/imagens/galaranja.jpg)