#include <iostream>
#include <string>
#include "../../Headers/Produto/Produto.hpp"

Produto::Produto(const std::string &nomeProduto, float valorProduto, int quantidadeProduto) 
: nome(nomeProduto), valor(valorProduto), quantidade(quantidadeProduto)
{

    setNome(nomeProduto);
    setValor(valorProduto);
}

std::string Produto::getNome()
{

    return nome;
}

float Produto::getValor()
{

    return valor;
}

int Produto::getQuantidade()
{

    return quantidade;
}

int Produto::setNome(const std::string &nomeProduto)
{

    if (nomeProduto.length() > 2)
    {

        nome = nomeProduto;

        return 1;
    }

    return 0;
}

float Produto::setValor(float valorProduto)
{

    if (valorProduto >= 0)
    {

        valor = valorProduto;

        return valor;
    }

    return 0;
}

int Produto::setQuantidade(int quantidadeProduto)
{
    if (quantidadeProduto <= 0)
    {

        quantidade = 0;

        return quantidade;
    }

    quantidade = quantidadeProduto;

    return quantidade;
}