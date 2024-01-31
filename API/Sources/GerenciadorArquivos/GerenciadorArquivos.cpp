#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <sstream>
#include <fstream>
#include <iomanip> 
#include "../../Headers/GerenciadorArquivos/GerenciadorArquivos.hpp"
#include "../../Headers/Produto/Produto.hpp"

std::vector<std::tuple<std::string, float, int>> GerenciadorArquivos::lerArquivo()
{

    std::ifstream arquivoEntrada;
    std::string nomeArquivoEntrada = "API/Arquivos/InputEstoque/inputEstoque.txt";

    arquivoEntrada.open(nomeArquivoEntrada);

    if (!arquivoEntrada.is_open())
    {

        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivoEntrada << std::endl;

        return {};
    }

    std::vector<std::tuple<std::string, float, int>> matrizValores;

    std::string linha;

    while (std::getline(arquivoEntrada, linha))
    {

        std::istringstream stream(linha);

        std::string indentificador;
        float valorProduto;
        int quantidadeProduto;

        if (stream >> indentificador >> valorProduto >> quantidadeProduto)
        {

            matrizValores.emplace_back(indentificador, valorProduto, quantidadeProduto);
        }
        else
        {
            std::cerr << "Erro ao ler valores da linha: " << indentificador << " " << valorProduto << " " << quantidadeProduto << std::endl;
        }
    }

    arquivoEntrada.close();

    return matrizValores;
}

int GerenciadorArquivos::atualizarArquivo(std::unordered_map<std::string, Produto> estoque)
{
    std::string nomeArquivo = "API/Arquivos/InputEstoque/inputEstoque.txt";

    std::ofstream arquivoAtualizado;

    arquivoAtualizado.open(nomeArquivo, std::ios::trunc);

    if(!arquivoAtualizado.is_open()){

        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;

        return 0;
    }

    for(auto iterador : estoque){

        arquivoAtualizado << iterador.second.getNome() << " " << iterador.second.getValor() << " " << iterador.second.getQuantidade() << std::endl;
    }

    arquivoAtualizado.close();

    return 1;
}

int GerenciadorArquivos::gerarRecibo(std::vector<Produto> produtoLista, float totalValorCompra){

    std::ofstream arquivoRecibo;

    std::string nomeArquivo = "API/Arquivos/OutputRecibo/recibo.txt";

    arquivoRecibo.open(nomeArquivo, std::ios::trunc);

    if(!arquivoRecibo.is_open()){

        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo <<  std::endl;

        return 0;
    }

    arquivoRecibo << std::left << std::setw(20) << "Produto" << std::setw(15) << "Valor" << std::setw(10) << "Unid.\n" << std::endl;

    for( auto &iterador : produtoLista){

        arquivoRecibo << std::fixed << std::setprecision(2) << std::left << std::setw(20) << iterador.getNome() << "$" << std::setw(15) << iterador.getValor() << iterador.getQuantidade() << std::endl;
    }

    arquivoRecibo << std::string(50, '-') << std::endl;

    arquivoRecibo << std::fixed << std::setprecision(2) << "TOTAL: $" << totalValorCompra << std::endl;

    arquivoRecibo.close();

    return 1;
}

int GerenciadorArquivos::gerarListaProdutos(std::vector<std::string> chavesEstoque ,std::unordered_map<std::string, Produto> estoque, int totalProdutos ){

    std::string nomeArquivo = "API/Arquivos/OutputListaProdutos/listaProdutos.txt";

    std::ofstream arquivoLista;

    arquivoLista.open(nomeArquivo, std::ios::trunc);

    if(!arquivoLista.is_open()){

        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo <<  std::endl;

        return 0;
    }

    arquivoLista << "\nQuantidade total de produtos: " << totalProdutos << "\n" << std::string(42, '=') <<"\n\n";
    arquivoLista << std::left << std::setw(20) << "Produto" << std::setw(13) << "Valor" << "Unid." << "\n";
    arquivoLista << std::string(42, '-') << "\n";

    for ( auto& chave : chavesEstoque) {

        arquivoLista << std::left << std::setw(21) << chave
                     << std::fixed << std::setprecision(2)
                     << std::setw(13) << estoque[chave].getValor()
                     << estoque[chave].getQuantidade() << "\n";

        arquivoLista << std::string(42, '-') << "\n";
    }

    arquivoLista.close();

    return 1;
}