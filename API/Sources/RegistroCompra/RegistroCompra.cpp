#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <istream>
#include <iomanip>
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

std::vector<float> RegistroCompra::formaPagamentoDinheiro(float valorPagamento)
{

    float dinheiroRecebido;
    float troco;
    std::vector<float> dadosPagamentoDinheiro;

    std::cout << "\nDinheiro recebido: $ ";
    std::cin >> dinheiroRecebido;
    troco = (dinheiroRecebido - valorPagamento);

    if (troco != 0.0)
    {

        std::cout << std::fixed << std::setprecision(2) << "Troco: " << troco << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n\n\033[3mPressione Enter para finalizar a compra...\033[0m" << std::endl;
        std::cin.get();
    }

    dadosPagamentoDinheiro.push_back(dinheiroRecebido);
    dadosPagamentoDinheiro.push_back(troco);

    return dadosPagamentoDinheiro;
}

std::vector<float> RegistroCompra::processarPagamento(float valorPagamento)
{

    int formaPagamento;
    std::vector<float> dadosPagamento;

    std::cout << std::fixed << std::setprecision(2) << "Valor total a pagar: $" << valorPagamento << std::endl;
    std::cout << "\nDigite a forma de pagamento:\n" << std::endl;
    std::cout << "(1) Dinheiro.\n(2) Debito.\n(3) Credito." << std::endl;
    std::cout << "\n >> ";
    std::cin >> formaPagamento;

    switch (formaPagamento)
    {
    case 1:
        dadosPagamento = formaPagamentoDinheiro(valorPagamento);
        std::cout << "\033[2J\033[1;1H";
        break;

    default:
        std::cerr << "Forma invalida de pagamento." << std::endl;
        break;
    }

    return dadosPagamento;
}

float RegistroCompra::comprarProduto(Estoque &estoque)
{

    Produto produto;

    std::string identificadorProduto;

    std::vector<Produto> produtoLista;

    std::vector<float> infoCompra;

    float unidadeProduto;

    while (true)
    {
        std::cout << "\nProduto: ";
        std::cin >> identificadorProduto;

        if (identificadorProduto != "0")
        {

            produto = estoque.consultarEstoque(identificadorProduto);

            std::cout << "Unidade: ";
            std::cin >> unidadeProduto;

            valorTotalCompra = valorTotalCompra + (produto.getValor() * unidadeProduto);

            estoque.decrementarQuantidadeProduto(identificadorProduto, (int)unidadeProduto);

            produto.setQuantidade((int)unidadeProduto);

            produtoLista.push_back(produto);
        }
        else
        {
            std::cout << "\033[2J\033[1;1H";

            infoCompra = processarPagamento(valorTotalCompra);

            std::cout << "\nCompra Finalizada !\n" << std::endl;

            arquivos.gerarRecibo(produtoLista, valorTotalCompra, infoCompra);

            break;
        }
    }

    setLucro(valorTotalCompra);

    return valorTotalCompra;
}