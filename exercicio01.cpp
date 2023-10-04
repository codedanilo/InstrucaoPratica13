/*
Uma empresa de ônibus faz diariamente 5 viagens de ida e 5 viagens de volta entre
as cidades do Rio de Janeiro e São Paulo. Cada ônibus tem 40 assentos para serem
preenchidos por passageiros. A empresa costuma vender as passagens
antecipadamente, e para cada passagem vendida é anotado o número do assento, a
data e hora, o CPF, o nome e a idade do passageiro. As passagens são vendidas por
80 reais cada.
Faça um programa para gerenciar a venda de passagens de ônibus. O programa deve
possibilitar obter as seguintes informações:

1. Qual o total arrecadado para uma determinada viagem.
2. Qual o total arrecadado em um determinado mês.
3. Qual o nome do passageiro de uma determinada poltrona P de uma
determinada viagem.
4. Qual o horário de viagem mais rentável.
5. Qual a média de idade dos passageiros.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definição da estrutura para armazenar informações de passagem
struct Passagem {
    int numeroAssento;
    string dataHora;
    string cpf;
    string nome;
    int idade;
};

// Função para calcular o total arrecadado para uma determinada viagem
double calcularTotalViagem(const vector<Passagem>& passagens) {
    double totalArrecadado = 0;
    for (const Passagem& passagem : passagens) {
        totalArrecadado += 80.0; // Cada passagem custa R$80
    }
    return totalArrecadado;
}

// Função para calcular o total arrecadado em um determinado mês
double calcularTotalMes(const vector<Passagem>& passagens, int mes) {
    double totalArrecadado = 0;
    for (const Passagem& passagem : passagens) {
        // Extrair o mês da dataHora e comparar com o mês fornecido
        int passagemMes = stoi(passagem.dataHora.substr(5, 2));
        if (passagemMes == mes) {
            totalArrecadado += 80.0; // Cada passagem custa R$80
        }
    }
    return totalArrecadado;
}

// Função para obter o nome do passageiro de uma determinada poltrona P de uma viagem
string obterNomePassageiro(const vector<Passagem>& passagens, int viagem, int poltrona) {
    for (const Passagem& passagem : passagens) {
        if (passagem.numeroAssento == poltrona) {
            return passagem.nome;
        }
    }
    return "Poltrona vazia";
}

// Função para encontrar o horário de viagem mais rentável
string encontrarHorarioMaisRentavel(const vector<Passagem>& passagens) {
    // Supomos que todos os horários são iguais para simplificar
    return passagens.empty() ? "Nenhuma passagem vendida" : passagens[0].dataHora;
}

// Função para calcular a média de idade dos passageiros
double calcularMediaIdade(const vector<Passagem>& passagens) {
    if (passagens.empty()) {
        return 0; // Não há passageiros
    }

    int totalIdade = 0;
    for (const Passagem& passagem : passagens) {
        totalIdade += passagem.idade;
    }

    return static_cast<double>(totalIdade) / passagens.size();
}

int main() {
    vector<Passagem> passagens;
    
    // Simulando a venda de passagens
    for (int i = 1; i <= 40; i++) {
        Passagem passagem;
        passagem.numeroAssento = i;
        passagem.dataHora = "2023-09-15 10:00"; 
        passagem.cpf = "123.456.789-00"; 
        passagem.nome = "Passageiro " + to_string(i);
        passagem.idade = 20 + i % 20; 
        passagens.push_back(passagem);
    }

    // Exemplo de uso das funções
    double totalViagem = calcularTotalViagem(passagens);
    cout << "Total arrecadado para a viagem: R$" << totalViagem << endl;

    double totalMes = calcularTotalMes(passagens, 9); 
    cout << "Total arrecadado no mês: R$" << totalMes << endl;

    int poltrona = 5; 
    string nomePassageiro = obterNomePassageiro(passagens, 1, poltrona); 
    cout << "Nome do passageiro da poltrona " << poltrona << ": " << nomePassageiro << endl;

    string horarioMaisRentavel = encontrarHorarioMaisRentavel(passagens);
    cout << "Horário de viagem mais rentável: " << horarioMaisRentavel << endl;

    double mediaIdade = calcularMediaIdade(passagens);
    cout << "Média de idade dos passageiros: " << mediaIdade << " anos" << endl;

    return 0;
}
