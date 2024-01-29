#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <sstream>
#include <fstream>
#include "../../Headers/GerenciadorArquivos/GerenciadorArquivos.hpp"

void GerenciadorArquivos::inserirProduto(const std::string &produto, float valorProduto, int quantidadeProduto)
{

    std::string nomeArquivo = "API/Headers/GerenciadorArquivos/inputEstoque.txt";

    std::ofstream arquivoSaida;

    arquivoSaida.open(nomeArquivo, std::ios::app);

    if (arquivoSaida.is_open())
    {

        arquivoSaida << produto << " " << valorProduto << " " << quantidadeProduto << std::endl;

        arquivoSaida.close();

        std::cout << "Produto: '" << produto << "' armazenado com sucesso." << std::endl;
    }
    else
    {
        std::cerr << "ERRO: ao abrir o arquivo: '" << nomeArquivo << "' para escrita." << std::endl;
    }
}

std::vector<std::tuple<std::string, float, int>> lerArquivo()
{

    std::ifstream arquivoEntrada;
    std::string nomeArquivoEntrada = "inputEstoque.txt";

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
            std::cerr << "Erro ao ler valores da linha." << std::endl;
        }
    }

    arquivoEntrada.close();

    return matrizValores;
}