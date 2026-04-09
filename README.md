Pontifícia Universidade Católica de Minas Gerais
Bacharelado em Engenharia de Software
Laboratório de Programação Modular
Prova Prática 1
Analise o cenário abaixo e desenvolva um sistema para atender à demanda solicitada.
Seu programa deve seguir todos os conceitos da Programação Orientada a Objetos e
implementá-los de forma correta. Leia com atenção todo o enunciado antes de iniciar.
Valor: 20 pontos
Critérios de Correção:
• Aplicação correta dos conceitos de modularização e POO: 10,0 pontos.
• Implementação correta das funcionalidades solicitadas: 6,0 pontos.
• Interação com o usuário e boas práticas de programação: 4,0 pontos.
Motivos que podem zerar sua prova:
• O código não está em Java
• O código não está orientado a objetos
• O código é cópia de terceiros
• Você acessou a internet durante a prova
Cenário
Uma empresa de logística deseja informatizar o sistema de gestão de sua frota de veículos
e entregas.
Cada veículo possui as seguintes informações: placa, modelo, ano de fabricação, capacidade
de carga, tipo do veículo.
Cada motorista possui: nome, CPF, categoria da CNH, telefone.
Cada veículo está vinculado a um motorista responsável.
Um veículo pode possuir várias entregas associadas.
Para cada entrega, devem ser armazenadas informações como: código, nome do destinatário, endereço de entrega, data da entrega, status da entrega (pendente, atribuída,
finalizada), peso da carga.
O sistema também deve permitir armazenar informações da rota associada a cada entrega.
A rota tem as informações: origem (cidade), destino (cidade), distância total, tempo estimado. Quando duas ou mais entregas possuem a mesma origem e destino, considera-se
que elas possuem a mesma rota.
1
Funcionalidades do Sistema
1. Associar um motorista a um veículo
2. Atribuir entrega a um veículo
3. Exibir todas as entregas atribuídas a um veículo específico. Informe também o total
de entregas ao final.
4. Informar a quantidade total de entregas realizadas (com status ”finalizada”) por cada
veículo
5. Buscar entregas por status. É necessário exibir os detalhes da entrega, incluindo
veículo e motorista.
6. Exibir os detalhes completos de uma entrega específica
Faça um método na classe main para criar 3 veículos e 3 motoristas assim que o programa
for executado (sem interação com o usuário).
Regras de negócio
1. Um motorista pode ser responsável por apenas um veículo.
2. Um veículo pode possuir várias entregas, mas a entrega não depende do veículo.
3. Entregas com status ”pendente” não possuem veículos atribuídos. Entregas com
status ”finalizada” precisam manter a informação do veículo que realizou. Porém, o
veículo não precisa manter a informação desta entrega.
