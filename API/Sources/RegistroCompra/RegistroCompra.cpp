#include <iostream>
#include <string>
#include <limits>
#include "../../Headers/RegistroCompra/RegistroCompra.hpp"
#include "../../Headers/Produto/Produto.hpp"

RegistroCompra::RegistroCompra(Estoque estoqueProdutos) : lucro(0.0f), estoque(estoqueProdutos), valorTotalCompra(0.0f)
{
}

float RegistroCompra::setLucro(float valorLucro)
{

    lucro = lucro + valorLucro;

    return lucro;
}

float RegistroCompra::getLucro()
{

    return lucro;
}

float RegistroCompra::getValorTotalCompra()
{

    return valorTotalCompra;
}

float RegistroCompra::encerrarExpediente()
{

    float lucroFinal = getLucro();
    lucro = 0;

    return lucroFinal;
}

float RegistroCompra::comprarProduto()
{

    Produto produto;

    std::string identificadorProduto;

    std::getline(std::cin, identificadorProduto);

    while (identificadorProduto != "0")
    {
        /*
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.clear();
        */
        produto = estoque.consultarEstoque(identificadorProduto);

        valorTotalCompra = valorTotalCompra + produto.getValor();

        std::getline(std::cin, identificadorProduto);
    }

    setLucro(valorTotalCompra);

    return valorTotalCompra;
}
