#include <iostream>
#include <string>
#include <iomanip>
#include "../../Headers/Estoque/Estoque.hpp"

Estoque::Estoque() : quantidadeTotalProdutos(0)
{

    inciarEstoque();
}

Estoque::~Estoque(){

    arquivos.atualizarArquivo(estoque);
}

void Estoque::adicionarProduto(const std::string &nome, float valor, int quantidade)
{
    estoque[nome] = Produto(nome, valor, quantidade);

    quantidadeTotalProdutos = quantidadeTotalProdutos + quantidade;
}

bool Estoque::inciarEstoque()
{
    auto matrizArquivo = arquivos.lerArquivo();

    for (const auto &iterador : matrizArquivo)
    {
        adicionarProduto(std::get<0>(iterador), std::get<1>(iterador), std::get<2>(iterador));
    }

    return true;
}

bool Estoque::removerProduto(const std::string &nome)
{

    auto iterador = estoque.find(nome);

    if (iterador != estoque.end())
    {
        quantidadeTotalProdutos = quantidadeTotalProdutos - iterador->second.getQuantidade();

        estoque.erase(iterador);

        return true;
    }

    return false;
}

Produto Estoque::consultarEstoque(const std::string &nome)
{

    auto iterador = estoque.find(nome);

    if (iterador != estoque.end())
    {

        return iterador->second;
    }

    return Produto("Produto nao encontrado", 0, 0);
}

void Estoque::listarProdutos()
{

std::cout << "Quantidade total de produtos: " << quantidadeTotalProdutos << "\n\n";
    std::cout << std::left << std::setw(20) << "|Produto|" << std::setw(10) << "|Valor|" << std::setw(12) << "|Quantidade|" << "\n";
    std::cout << std::string(42, '-') << "\n";

    for ( auto& par : estoque) {

        Produto& produto = par.second;

        std::cout << std::left << std::setw(20) << produto.getNome()
                  << std::right << std::fixed << std::setw(1) << std::setprecision(2) << produto.getValor()
                  << std::right << std::setw(12) << produto.getQuantidade() << "\n";

        std::cout << std::string(42, '-') << "\n";
    }
    
}

int Estoque::incrementarQuantidadeProduto(const std::string &nomeProduto, int valorQuantidade)
{
    int resultadoTotal;
    auto iterador = estoque.find(nomeProduto);

    if (iterador != estoque.end())
    {
        resultadoTotal = iterador->second.getQuantidade() + valorQuantidade;

        iterador->second.setQuantidade(resultadoTotal);

        quantidadeTotalProdutos = quantidadeTotalProdutos + valorQuantidade;

        return valorQuantidade;
    }

    return 0;
}

int Estoque::decrementarQuantidadeProduto(const std::string &nomeProduto, int valorQuantidade)
{
    int resultadoFinal;
    auto iterador = estoque.find(nomeProduto);

    if (iterador != estoque.end())
    {
        if (valorQuantidade >= iterador->second.getQuantidade())
        {
            quantidadeTotalProdutos = quantidadeTotalProdutos - iterador->second.getQuantidade();
        }
        else
        {
            quantidadeTotalProdutos = quantidadeTotalProdutos - valorQuantidade;
        }

        resultadoFinal = iterador->second.getQuantidade() - valorQuantidade;

        iterador->second.setQuantidade(resultadoFinal);

        return valorQuantidade;
    }

    return 0;
}