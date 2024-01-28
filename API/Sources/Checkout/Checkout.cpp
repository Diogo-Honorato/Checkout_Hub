#include <iostream>
#include <string>
#include "../../Headers/Estoque/Estoque.hpp"
#include "../../Headers/GerenciadorArquivos/GerenciadorArquivos.hpp"

int main()
{

    GerenciadorArquivos arquivo;

    arquivo.inserirProduto("Leite", 20.00f, 3);
    arquivo.inserirProduto("Arroz", 6.50f, 50);
    arquivo.inserirProduto("Cafe", 6.50f, 50);
    arquivo.inserirProduto("Arroz", 6.50f, 50);

}