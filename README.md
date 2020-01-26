# Linux Workshop

## 1. Navegando por pastas
* `cd [algum_diretorio]` vem de "_change directory_", vai para uma pasta contida no atual diretório
Exemplo: `cd Downloads`
  * É possível também navegar por meio de endereço global.
  Quando usamos `cd ~/[algum_diretorio]`, o caractere `~` faz menção à _home_ do sistema. Analogamente, `cd /home/[nome_do_usuario]/[algum_diretorio]`. Os dois ultimos comandos são equivalentes, e no segundo, a barra inicial `/` faz menção à **raiz** do sistema
  * `sudo rm -r /` ;)
* `ls` vem de "_list_", lista todos os arquivos e pastas no atual diretório - _takes no arguments_

## 2. Criando/Removendo
* `mkdir [nome_do_repositorio]` vem de _make directory_, cria um diretório com o argumento que vai ser passado em seguida

### Uma palavra sobre argumentos
Existem argumentos mandatórios e opcionais, os mandatórios não requerem _flags_
Exemplo `mkdir -p catkin_ws/src`
Nesse exemplo, `-p` é a chamada _flag_, que pode ser um caractere ou escrita por extenso, como em `mkdir --parents ctakin_ws/src`
#### Best argument ever
`--help` ou `-h`, quando usado com qualquer comando te lista as possibilidades do comando e te ajuda a usá-lo
