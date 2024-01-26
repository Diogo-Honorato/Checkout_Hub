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

    float quantidadeProduto;

    while (true)
    {
        std::cout << "Produto:" << std::endl;
        std::cin >> identificadorProduto;

        if (identificadorProduto != "0")
        {

            produto = estoque.consultarEstoque(identificadorProduto);

            std::cout << "Quantidade:" << std::endl;
            std::cin >> quantidadeProduto;

            valorTotalCompra = valorTotalCompra + (produto.getValor() * quantidadeProduto);
        }
        else
        {
            std::cout << "Compra Finalizada !" << std::endl;
            break;
        }
    }

    setLucro(valorTotalCompra);

    return valorTotalCompra;
}