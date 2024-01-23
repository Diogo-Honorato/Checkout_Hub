#include <iostream>
#include <string>
#include "../../Headers/Estoque/Estoque.hpp"

int main(){

    Estoque estoque;

    estoque.adicionarProduto("Banana",65.00f,5);
    estoque.adicionarProduto("Leite",15.00f,16);
    estoque.adicionarProduto("Arroz",25.00f,510);

    estoque.removerProduto("Banana");
    
    estoque.incrementarQuantidadeProduto("Arroz",0);
    estoque.decrementarQuantidadeProduto("Leite",16);

    estoque.listarProdutos();


    Produto produto = estoque.consultarEstoque("Leite");

    std::cout <<"\n\nConsultando produto:"<< produto.getNome() << std::endl;
    std::cout << "valor: $" << produto.getValor() << std::endl;
    std::cout << "quantidade: " << produto.getQuantidade() << std::endl;

}