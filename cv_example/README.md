# Projeto de CV
Programa que detecta movimento no vídeo em tempo real obtido da webcam, usando OpenCV, em C++.

## Instalação
* rodar script `install_opencv.sh`

```
chmod +x install_opencv.sh
./install_opencv.sh
```

## Desenvolvimento
### Fase 1 - O processo
* Como detectar o movimento?
* Teste em imagens estáticas
* Quais problemas apareceram?

### Fase 2 - O MVP
* Como obter imagem em tempo real?
* O conceito de movimento é absoluto?

### Fase 3 - A solução final
* Quais são os problemas do MVP?
* O MVP performa em situações não ideais? com ruído?

## As "chaves do castelo"
* biblioteca `<opencv2/opencv.hpp>`
* Usar  `using namespace cv;`
* Variáveis imagens são do "tipo" `Mat` (com M maiúsculo)
* A função `imread([nome_do_arquivo], [flag]);` retorna a imagem passada
    * A flag `CV_LOAD_IMAGE_GRAYSCALE` lê as imagens como preto e branco
* A função `imshow([string], [imagem]);` cria uma janela para mostrar a imagem
* A função `waitKey([tempo]);` espera `[tempo]` milisegundos
    * É útil para visualizar a imagem
    * Quando `[tempo] = 0`, ela espera por tempo indeterminado
* `!image.data` retorna um booleano que informa se a imagem está vazia
* Informações adicionais sobre as funções do OpenCV podem ser encontradas [aqui](https://docs.opencv.org/master/d0/de1/group__core.html) e [aqui também](https://docs.opencv.org/2.4/modules/highgui/doc/reading_and_writing_images_and_video.html)
* A função `imagem.at<uchar>(linha, coluna)` retorna o valor do pixel (i, j) da imagem.
    Repare que a imagem não é tratada como somente uma matriz - graças ao OpenCV -, então a sintaxe será ligeiramente diferente.
    (Caso ela fosse uma matriz comum de inteiros, acessaríamos seus 
    elementos com `imagem[i][j]`.)

* Ao usar a biblioteca `<iostream>` para gerar saídas, vocês descobrirão para que servia aquele `using namespace std` que comentamos que era um "cabeçalho". Como neste código estaremos usando `cv` como namespace, **toda vez que usarmos um** `cout`, `cin`, `endl`, precisamos nos referir a estes como `std::cout`, `std::cin`, `std::endl`.
    * Uma outra opção é usar namespace `std` e explicitar todas as funções do OpenCV, como `cv::waitKey()`, `cv::imread()`, `cv::Mat`. A opção do namespace depende do que você vai usar mais no seu código.

## Compilação
```
g++ [nome do cpp].cpp -o [nome do executável] `pkg-config --cflags --libs opencv`
```

## Mentiras
Na concepção desse projeto, achamos que seria mais divertido e motivador para todos, já trabalhar em algo prático, que será efetivamente usado pela equipe ~~(a ideia é incorporar a versão final deste código ao package cv_detection)~~. Por conta disso, contamos algumas "mentiras" ao dar para vocês as chaves do castelo rs, para evitar confusões com conteúdos que ainda não estudamos. Mas, para os curiosos aqui vai:
* As "variáveis" do tipo `Mat` são, na verdade, *objetos* de uma *classe*
* A "função" `imagem.at(linha, coluna)`
    * é na verdade um *método* desta classe `Mat`, mais especificamente um _template_
    * Um template pode retornar o tipo que você quiser - int, char, double - basta colocar o tipo de variável desejada entre `<>`, por exemplo `image.at<double>(linha, coluna)`
    * No caso de matrizes do tipo _greyscale_, com as quais estamos trabalhando, o tipo de variável nos seus elementos é `uchar` (unsigned char), CV_8UC1
    https://riptutorial.com/opencv/example/6394/access-individual-pixel-values-with-cv--mat--at-t---

Toda a zoologia dos termos expostos desnecessariamente acima pertence à teoria de Orientação a Objetos e será explicada em mais detalhes no respectivo workshop. 