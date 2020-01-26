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
* `rm [nome_do_arquivo]` vem de _remove_, remove um arquivo. Caso queira remover uma pasta, é necessário usar a flag `-r` (de _repository_) como em `rm -r [nome_da_pasta]`

### Uma palavra sobre argumentos
Existem argumentos mandatórios e opcionais, os mandatórios não requerem _flags_
Exemplo `mkdir -p catkin_ws/src`
Nesse exemplo, `-p` é a chamada _flag_, que pode ser um caractere ou escrita por extenso, como em `mkdir --parents ctakin_ws/src`
#### Best argument ever
`--help` ou `-h`, quando usado com qualquer comando te lista as possibilidades do comando e te ajuda a usá-lo

## 3. Permissões 
Caso você tenha algum problema de permissão - algo do tipo `Access Denied` - e **saiba o que está fazendo**, a palavra mágica é `sudo` (_superuser do_). Use-o antes do comando e digite a senha que a permissão será concedida.
* É possível rodar a maioria dos comandos/programas como superuser
* Em geral, arquivos/diretórios gerados como _superuser_ necessitam da permissão do mesmo para serem modificados, então é bom não usar `sudo` para **tudo** - pq se não é a mesma coisa que não usar para nada

## 4. Git, seu lindo
Já atualizaram o iOS de vocês para a versão 11.4.1? Já se perguntaram como os desenvolvedores mantém registro de todas as mudanças entre as diferentes verões do sistema? E se alguma coisa der errado? Como voltamos atrás?.
A resposta pra essas e muitas outras perguntas é, **usando o Git**, o Git é um "sistema de controle de versões distribuído ... usado para registrar o histórico de edições de qualquer tipo de arquivo"

### O Github, Facebook dos devs
Uma das plataformas de hospedagem (a mais famosa) para controle de versão usando Git é o **Github**.

Já façam a conta de vcs <strike>e me sigam</strike> https://github.com/caio-freitas


Lá podemos encontrar hospedados os códigos que desenvolvemos <strike>e alguns outros, que as vezes podem ser úteis</strike>

* O git serve para registrar histórico de edições de _qualquer tipo de arquivo_, **incluindo esse workshop** ;)
