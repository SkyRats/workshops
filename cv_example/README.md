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
* Teste em imagens estáticas
* Como detectar o movimento?
* Quais problemas aparecerão?

### Fase 2 - O MVP
* Como obter imagem em tempo real?
* O conceito de movimento é absoluto?

### Fase 3 - A solução final
* Quais são os problemas do MVP?
* O MVP performa em situações não ideais? com ruído?


## Compilação
```
g++ [nome do cpp].cpp -o [nome do executável] `pkg-config --cflags --libs opencv`
```