# Projeto 2 - MC833
## Codigo para o Projeto 2 da disciplina MC833 - Laboratorio de Redes: Cliente/Servidor iterativo UDP

### Features

- [ ] Cadastrar um novo perfil
- [ ] Adicionar uma experiencia profissional
- [ ] Listar todas as pessoas formadas em um determinado curso
- [ ] Listar todas as pessoas que possuam uma determinada habilidade
- [ ] Listar todas as pessoas formadas em um determinado ano
- [ ] Listar todas as informações de todos os perfis
- [ ] Dado o email de um perfil, retornar suas informações
- [ ] Remover um perfil a partir de seu email


### Executando o projeto

--> Clonar este repositório
--> No diretíorio dele, deve-se executar os seguintes comandos:
    Compilar servidor: gcc -Wall server.c actions.c -o server
    Iniciar o servidor:  ./server oy

    Compilar cliente: gcc -o client client.c
    Iniciar o cliente: ./client ou telnet localhost 8080
    Finalizar sessão do cliente: exit

    Obs: O servidor utilizará a porta 8080

### Tecnologias

A tecnologia utilizada no projeto foi a linguagem C, com auxilio de bibliotecas que permitem a comunicação por sockets

### Autores

O projeto foi desenvolvido por Gabriel José de Souza Moraes e Renata Mancilha Lellis, alunos do curso de Laboratório
de Redes de computadores - MC 833 - Na UNICAMP