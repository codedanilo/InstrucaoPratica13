/*
Crie um tipo estruturado (struct) empregado para armazenar dados (nome,
sobrenome, ano de nascimento, RG, ano de admissão, salário) de empregados de
uma empresa. Defina um vetor de empregados para armazenar até 50 empregados.
Faça uma função chamada “Reajusta_dez_porcento( )” que receba por parâmetro o
vetor de empregados e a quantidade de elementos no vetor e atualize o salário de
cada empregado em 10%. Crie uma função main para testar a função.
*/

#include <iostream>
#include <string>

using namespace std;

// Definição da estrutura para representar um empregado
struct empregado {
    string nome;
    string sobrenome;
    int anoNascimento;
    string RG;
    int anoAdmissao;
    double salario;
};

// Função para reajustar o salário de um vetor de empregados em 10%
void Reajusta_dez_porcento(empregado vetor[], int numElementos) {
    for (int i = 0; i < numElementos; i++) {
        vetor[i].salario *= 1.10; // Aumento de 10%
    }
}

int main() {
    const int MAX_EMPREGADOS = 50;
    empregado vetorEmpregados[MAX_EMPREGADOS];
    int numEmpregados;

    // Solicita o número de empregados ao usuário
    cout << "Digite o número de empregados (até " << MAX_EMPREGADOS << "): ";
    cin >> numEmpregados;

    // Preenche os dados dos empregados
    for (int i = 0; i < numEmpregados; i++) {
        cout << "Empregado " << i + 1 << ":" << endl;
        cout << "Nome: ";
        cin >> vetorEmpregados[i].nome;
        cout << "Sobrenome: ";
        cin >> vetorEmpregados[i].sobrenome;
        cout << "Ano de Nascimento: ";
        cin >> vetorEmpregados[i].anoNascimento;
        cout << "RG: ";
        cin >> vetorEmpregados[i].RG;
        cout << "Ano de Admissão: ";
        cin >> vetorEmpregados[i].anoAdmissao;
        cout << "Salário: ";
        cin >> vetorEmpregados[i].salario;
    }

    // Chama a função para reajustar os salários
    Reajusta_dez_porcento(vetorEmpregados, numEmpregados);

    // Imprime os dados atualizados
    cout << "\nDados dos empregados após o reajuste de 10% no salário:" << endl;
    for (int i = 0; i < numEmpregados; i++) {
        cout << "Empregado " << i + 1 << ":" << endl;
        cout << "Nome: " << vetorEmpregados[i].nome << " " << vetorEmpregados[i].sobrenome << endl;
        cout << "Ano de Nascimento: " << vetorEmpregados[i].anoNascimento << endl;
        cout << "RG: " << vetorEmpregados[i].RG << endl;
        cout << "Ano de Admissão: " << vetorEmpregados[i].anoAdmissao << endl;
        cout << "Salário: R$" << vetorEmpregados[i].salario << endl;
    }

    return 0;
}
