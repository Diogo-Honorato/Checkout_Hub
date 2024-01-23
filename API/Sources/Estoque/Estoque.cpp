#include <iostream>
#include <string>
#include <iomanip>
#include "../../Headers/Estoque/Estoque.hpp"

Estoque::Estoque() : quantidadeTotalProdutos(0) {}

void Estoque::adicionarProduto(const std::string &nome, float valor, int quantidade)
{
    estoque[nome] = Produto(nome, valor, quantidade);

    quantidadeTotalProdutos = quantidadeTotalProdutos + quantidade;
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

    std::cout << "Quantidade total de produtos: " << quantidadeTotalProdutos << std::endl;

    std::cout << "\nProduto  |  Valor  |  Qauntidade" << std::endl;

    for (auto &par : estoque)
    {

        Produto &produto = par.second;

        std::cout << std::setw(0) << produto.getNome();

        std::cout << std::setw(12) << std::fixed << std::setprecision(2) << produto.getValor();

        std::cout << std::setw(11) << produto.getQuantidade() << std::endl;
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