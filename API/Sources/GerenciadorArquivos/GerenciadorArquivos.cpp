#include <iostream> 
#include <string>
#include <fstream>
#include "../../Headers/GerenciadorArquivos/GerenciadorArquivos.hpp"

Estoque GerenciadorArquivos::getEstoque(){

    return estoque;
}

void GerenciadorArquivos::inserirProduto(const std::string &produto, float valorProduto, int quantidadeProduto){

    std::string nomeArquivo = "API/Headers/GerenciadorArquivos/inputEstoque.txt";

    std::ofstream arquivoSaida;

    arquivoSaida.open(nomeArquivo, std::ios::app);

    if(arquivoSaida.is_open()){

        arquivoSaida << produto << " " << valorProduto << " " << quantidadeProduto << std::endl;

        arquivoSaida.close();

        std::cout << "Produto: '" << produto << "' armazenado com sucesso." << std::endl;
    }
    else
    {
        std::cerr << "ERRO: ao abrir o arquivo: '" << nomeArquivo << "' para escrita." << std::endl; 
    }
}