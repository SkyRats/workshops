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
* Informações adicionais sobre as funções do OpenCV podem ser encontradas [aqui](https://docs.opencv.org/master/d0/de1/group__core.html)

## Compilação
```
g++ [nome do cpp].cpp -o [nome do executável] `pkg-config --cflags --libs opencv`
```