#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "../../Headers/RegistroCompra/RegistroCompra.hpp"
#include "../../Headers/Produto/Produto.hpp"
#include "../../Headers/GerenciadorArquivos/GerenciadorArquivos.hpp"

RegistroCompra::RegistroCompra() : lucro(0.0f), valorTotalCompra(0.0f)
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

float RegistroCompra::comprarProduto(Estoque &estoque)
{

    Produto produto;

    std::string identificadorProduto;

    std::vector<Produto> produtoLista;

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

            estoque.decrementarQuantidadeProduto(identificadorProduto, (int)quantidadeProduto);

            produto.setQuantidade((int)quantidadeProduto);

            produtoLista.push_back(produto);
        }
        else
        {
            std::cout << "Compra Finalizada !" << std::endl;

            arquivos.gerarRecibo(produtoLista, valorTotalCompra);
            
            break;
        }
    }

    setLucro(valorTotalCompra);

    return valorTotalCompra;
}