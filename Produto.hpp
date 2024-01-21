#ifndef _PRODUTO_
#define _PRODUTO_
#include <string>

class Produto
{
private:
    std::string nome;
    float valor;
    uint quantidade;

public:
    std::string getNome();
    float getValor();
    uint getQuantidade();

    int setNome(std::string nomeProduto);
    float setValor(float valorProduto);
    uint setQuantidade(uint qunatidadeProduto);
};

std::string Produto::getNome()
{

    return nome;
}

float Produto::getValor()
{

    return valor;
}

uint Produto::getQuantidade()
{

    return quantidade;
}

int Produto::setNome(std::string nomeProduto)
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

uint Produto::setQuantidade(uint quantidadeProduto)
{

    if (quantidadeProduto >= 0)
    {

        quantidade = quantidadeProduto;

        return quantidade;
    }

    return 0;
}

#endif