#ifndef _PRODUTO_
#define _PRODUTO_
#include <string>

class Produto
{
private:
    std::string nome;
    float valor;
    int quantidade;

public:
    std::string getNome();
    float getValor();
    int getQuantidade();

    int setNome(const std::string &nomeProduto);
    float setValor(float valorProduto);
    int setQuantidade(int qunatidadeProduto);

    Produto(const std::string &nomeProduto = "Produto", float valorProduto = 0.0f, int quantidadeProduto = 0);
};

#endif