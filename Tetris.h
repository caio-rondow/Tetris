#ifndef TETRIS_H__
#define TETRIS_H__

#include <vector>
#include <iostream>

// Fazer uma classe MyExepctionTetris com as exceções de adicionaForma()

class Tetris{

private:
    std::vector<std::vector<char>> _jogo;
    int _largura;

    // =======================================

    std::vector< std::vector<char> > _peca;
    int _altura;
    int _base;

    void rotaciona(int angulo);          // Rotaciona uma peça 'id' em 'angulo'
    void transposeVecSentidoHorario();   // Faz a matriz transposta da peça(rotaciona)
    void setPeca(char id, int angulo);   // Cria uma _peca

    char getPeca(int c, int l) const;         // Seleciona um pixel da peça         
    int pecaHeight() const;                    // Altura da peça
    int pecaWidth() const;                      // Base da peça

    bool colisaoPixel(std::vector< std::vector<char> >&p, const int coluna, const int linha) const;    // Testa colisão antes de inserir a peça
    void deleteLine(int linha);                                                                        // deleta a linha completa

    void shrink_to_fit();

protected:

public:
    // Construtores/ Destrutores
    Tetris(int largura);                   // Construtor recebe a largura inicial do jogo
    ~Tetris();

    // Métodos
    char get(int coluna, int linha) const; // Retorna o estado do pixel atual na posição(linha, coluna)
    void removeColuna(const int c);        // Dada uma coluna c do jogo, remove-a, diminuindo a largura atual
    void removeLinhasCompletas();          // Remove as linhas completas do jogo e desloca a linha acima para baixo
    int getNumColunas() const;             // Retorna o número de colunas(largura do jogo)
    int getAltura(const int c) const;      // Retorna a altura da coluna c do jogo
    int getAltura() const;                 // Retorna a altura máxima do jogo(coluna mais alta)
    
    bool adicionaForma(int coluna, int linha, char id, int angulo);         // Adiciona uma peça ao jogo

    // =======================================================================
    void imprime() const;               // Imprime peça
    void imprimeTetris() const;
};

#endif