/*
Faça um programa para um supermercado para a consulta de preço de produtos. O
programa deverá armazenar de cada produto o seu código, seu nome e seu preço.
Ao utilizar o programa o usuário deve poder:
1. Inserir um novo produto
2. Excluir um produto cadastrado
3. Listar todos os produtos com seus respectivos códigos e preços
4. Consultar o preço de um produto através de seu código.
O código deve ser formado de uma string numérica de 13 caracteres
O nome deve ter um tamanho de no máximo 20 caracteres
O preço deve ter duas casas decimais
O sistema deve permitir o cadastro de até 300 produtos diferentes.
O sistema deve controlar para que não tenha produtos com o mesmo código ou
mesmo nome, não permitindo o seu cadastro.
O sistema deverá ser feito modularizados, com qualidade e utilizando estrutura na
sua implementação.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Definição da estrutura para representar um produto
struct Produto {
    string codigo;
    string nome;
    double preco;
};

const int MAX_PRODUTOS = 300; // Número máximo de produtos que podem ser cadastrados

// Função para verificar se um produto com o mesmo código já existe
bool produtoExiste(const Produto estoque[], int numProdutos, const string& codigo) {
    for (int i = 0; i < numProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            return true;
        }
    }
    return false;
}

// Função para adicionar um novo produto ao estoque
void adicionarProduto(Produto estoque[], int& numProdutos) {
    if (numProdutos < MAX_PRODUTOS) {
        cout << "Digite o código do produto (13 caracteres numéricos): ";
        cin >> estoque[numProdutos].codigo;

        // Verifique se o produto com o mesmo código já existe
        if (produtoExiste(estoque, numProdutos, estoque[numProdutos].codigo)) {
            cout << "Produto com o mesmo código já existe. Não é possível cadastrá-lo novamente." << endl;
            return;
        }

        cout << "Digite o nome do produto (até 20 caracteres): ";
        cin.ignore();
        getline(cin, estoque[numProdutos].nome);

        cout << "Digite o preço do produto (com duas casas decimais): R$";
        cin >> estoque[numProdutos].preco;

        numProdutos++;
        cout << "Produto adicionado com sucesso!" << endl;
    } else {
        cout << "Limite máximo de produtos atingido." << endl;
    }
}

// Função para excluir um produto cadastrado
void excluirProduto(Produto estoque[], int& numProdutos, const string& codigo) {
    for (int i = 0; i < numProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            // Move todos os produtos após o produto excluído uma posição para trás
            for (int j = i; j < numProdutos - 1; j++) {
                estoque[j] = estoque[j + 1];
            }
            numProdutos--;
            cout << "Produto excluído com sucesso!" << endl;
            return;
        }
    }
    cout << "Produto não encontrado." << endl;
}

// Função para listar todos os produtos em estoque
void listarProdutos(const Produto estoque[], int numProdutos) {
    cout << "Lista de Produtos em Estoque:" << endl;
    cout << setw(15) << "Código" << setw(25) << "Nome" << setw(15) << "Preço" << endl;
    for (int i = 0; i < numProdutos; i++) {
        cout << setw(15) << estoque[i].codigo << setw(25) << estoque[i].nome << setw(15) << fixed << setprecision(2) << estoque[i].preco << endl;
    }
}

// Função para consultar o preço de um produto através de seu código
void consultarPreco(const Produto estoque[], int numProdutos, const string& codigo) {
    for (int i = 0; i < numProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            cout << "O preço do produto " << estoque[i].nome << " (Código: " << estoque[i].codigo << ") é R$" << fixed << setprecision(2) << estoque[i].preco << endl;
            return;
        }
    }
    cout << "Produto não encontrado." << endl;
}

int main() {
    Produto estoque[MAX_PRODUTOS]; // Array para armazenar os produtos
    int numProdutos = 0; // Contador de produtos cadastrados

    int opcao;
    do {
        cout << "\nMenu de Opções:" << endl;
        cout << "1. Inserir Produto" << endl;
        cout << "2. Excluir Produto" << endl;
        cout << "3. Listar Produtos" << endl;
        cout << "4. Consultar Preço" << endl;
        cout << "5. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                adicionarProduto(estoque, numProdutos);
                break;
            case 2:
                {
                    string codigo;
                    cout << "Digite o código do produto a ser excluído: ";
                    cin >> codigo;
                    excluirProduto(estoque, numProdutos, codigo);
                }
                break;
            case 3:
                listarProdutos(estoque, numProdutos);
                break;
            case 4:
                {
                    string codigo;
                    cout << "Digite o código do produto para consultar o preço: ";
                    cin >> codigo;
                    consultarPreco(estoque, numProdutos, codigo);
                }
                break;
            case 5:
                cout << "Encerrando o programa. Obrigado!" << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (opcao != 5);

    return 0;
}
