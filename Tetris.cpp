#include "Tetris.h"

Tetris::Tetris(int largura):_largura(largura), _base(0), _altura(0), _jogo(largura, std::vector<char>()){}

Tetris::~Tetris(){}

bool Tetris::adicionaForma(int coluna, int linha, char id, int angulo){
    
    // Crio uma nova peça
    setPeca(id, angulo);

    // Verificar se eu posso colocar a peça em (coluna, linha)...
    // Se eu estou colocando a peça numa coluna ou linha inválida  
    // Se o tamanho da peça(_base) é maior do que a _largura da tela
    // Se a altura da peça ultrapassa o limite inferior da tela
    if(coluna < 0 || coluna >= _largura || linha < 0) return false;
    if(pecaWidth() > _largura - coluna) return false;
    if(linha+1 - pecaHeight() < 0) return false;
    
    // verificar a colição se pixels
    if(colisaoPixel(_peca, coluna, linha)) return false;

    // Adicionando linhas ao jogo para colocar a peça
    // Se eu preciso adicionar linhas...
    // TRANSFORMAR ISSO NUMA FUNÇÃO DA CLASSE JOGO
    for(int c = coluna; c < pecaWidth() + coluna; c++){
        
        // Se eu não preciso realocar na coluna i...
        // Senão, realoca...
        if(!_jogo[c].empty() && _jogo[c].size()-1 >= linha) continue;
        else _jogo[c].resize(linha+1, ' ');
    }
    
    // Coloco ela em (coluna, linha) 
    for(int l = linha; l > linha-pecaHeight(); l--){
        for(int c = coluna; c < pecaWidth()+coluna; c++){
            // quer dizer que tem uma peça ali
            if(_jogo[c][l] != ' ') continue;
            
            // Se não tem uma peça em c l, coloca uma entao
            _jogo[c][l] = getPeca(c-coluna, linha-l);
        } 
    }

    shrink_to_fit();

    return true;
}

char Tetris::get(int coluna, int linha) const{

    // Se o jogo estiver vazio ou ele não tem um pixel alocado na pos(coluna, linha), imprime pixel vazio
    // Senão, imprime o pixel que está na pos(coluna, linha)
    if(_jogo[coluna].empty() || _jogo[coluna].size()-1 < linha) return ' ';
    return _jogo[coluna][linha];
}

int Tetris::getNumColunas() const{return _largura;}

bool Tetris::colisaoPixel(std::vector< std::vector<char> >&p, const int coluna, const int linha) const{

    for(int l = linha; l > linha-pecaHeight(); l--){
        for(int c = coluna; c < coluna + pecaWidth(); c++){
            // Se não tenha um pixel na posição, pule-a
            // Se eu estou tentando colocar um pixel não vazio em cima de outro, colisão encontrada
            if(_jogo[c].empty() || _jogo[c].size()-1 < l) continue;
            if(_jogo[c][l] != ' ' && getPeca(c-coluna, linha-l) != ' ') return true;
        }
    }

    return false;
}

int Tetris::getAltura() const{

    int alturaMax = _jogo[0].size();

    // Encontra altura maxima do jogo
    for(int c = 1; c < _largura; c++){
        if(_jogo[c].size() > alturaMax)
            alturaMax = _jogo[c].size();
    }

    return alturaMax;
}

int Tetris::getAltura(const int c) const{

    // Se coluna é vazia, retorna 0
    // Senão, retorna a altura da coluna
    if(_jogo[c].empty()) return 0;
    return _jogo[c].size();
}

void Tetris::removeLinhasCompletas(){
    
    bool isFilled;
    int alturaMax = getAltura();

    // percorrendo o jogo inteiro para achar linhas completas
    for(int l = alturaMax-1; l >= 0; l--){
        isFilled = true;
        for(int c = 0; c < _largura; c++){

            // Se a a coluna está vazia ou não tem pelo menos um pixel na linha l
            // vai para a próxima linha
            if(_jogo[c].empty() || _jogo[c].size()-1 < l || _jogo[c][l] == ' '){
                isFilled = false;
                break;
            }
        }

        // Se uma linhas está completa, remove ela
        if(isFilled) deleteLine(l);
    }
}

void Tetris::deleteLine(int linha){

    for(int c = 0; c < _largura; c++){
        
        // Se só tem um elemento na coluna
        if(_jogo[c].size() == 1){
            _jogo[c].clear();
            continue;
        } 
        
        // Senão, passa os pixeis para a coluna de baixo
        for(int l = linha; l < _jogo[c].size()-1; l++){
            _jogo[c][l] = _jogo[c][l+1];
        }
        _jogo[c].resize(_jogo[c].size() - 1);
    } 

    // deixando as colunas justas
    shrink_to_fit();
}

void Tetris::removeColuna(const int c){

    // Se a coluna que eu quero remover não é válida
    if(c < 0 || c >= _largura) return;

    // Criando um vetor temporário com menos uma coluna
    std::vector< std::vector<char> > temp(_largura-1, std::vector<char>());
    int i=0;

    for(int coluna = 0; coluna < _largura; coluna++){
        // Se eu cheguei a coluna que quero deletar
        // pula ela
        if(coluna == c) continue;
        // copia a coluna atual pro vetor temporário
        temp[i++] = _jogo[coluna]; 
    }
    
    // Copia o novo jogo sem a coluna c
    // Diminui a largura do jogo
    _jogo = temp;
    _largura -= 1;

/*
    std::cout << "\nAlturas depois: ";
    for(int i = 0; i < _largura; i++) std::cout << getAltura(i) << " ";
    std::cout << "NOVO JOGO::largura = " << _largura << "\n\n";
    for(int l = 4; l >= 0; l--){
        std::cout << "linha " << l << ": ";
        for(int c = 0; c < _largura; c++){
            if(_jogo[c].size() <= l) std::cout << "  ";
            else std::cout << _jogo[c][l] << " ";
        }
        std::cout << "\n";
    }
*/

}

// colocar isso na classe MyGame depois
void Tetris::shrink_to_fit(){

    // Percorre o jogo inteiro procurando pelo ultimo pixel não vazio
    // e deixa a coluna do tamanho da posição dele
    for(int c=0; c < _largura; c++){
        for(int l=_jogo[c].size()-1; l>=0; l--){
            if(_jogo[c].empty()) break;
            if(_jogo[c][l] != ' '){
                _jogo[c].resize(l+1);
                break;
            } 
        }
    }
}

// ===============================================================================

void Tetris::setPeca(char id, int angulo){
    
    // Limpa a peça anterior
    _peca.clear();
    
    // peças padrões 
    const char Ishaped[4] = {'I','I','I','I'};
    const char Oshaped[2][2] = {
        {'O', 'O'},
        {'O', 'O'}
    };
    const char Jshaped[2][4] = {
        {'J','J','J','J'},
        {' ',' ',' ','J'}
    };
    const char Lshaped[2][4] = {
        {'L','L','L','L'},
        {'L',' ',' ',' '}
    };
    const char Sshaped[2][3] = {
        {' ','S','S'},
        {'S','S',' '}
    };
    const char Zshaped[2][3] = {
        {'Z','Z',' '},
        {' ','Z','Z'}
    };
    const char Tshaped[2][3] = {
        {'T','T','T'},
        {' ','T',' '}
    };

    // Atribui a peça
    switch (id)
    {
        case 'I':{
            _peca.resize(1);
            _peca[0].insert(_peca[0].end(), Ishaped, Ishaped+4);
            _base=1; _altura=4;
        }break;
        
        case 'O':{
            _peca.resize(2);
            _peca[0].insert(_peca[0].end(), Oshaped[0], Oshaped[0]+2);
            _peca[1].insert(_peca[1].end(), Oshaped[1], Oshaped[1]+2);
            _base=_altura=2;
        }break;

        case 'J':{
            _peca.resize(4);
            for(int c=0; c < 4; c++){
                for(int l=0; l < 2; l++){
                    _peca[c].push_back(Jshaped[l][c]);
                }
            }
            _base=4; _altura=2;
        }break;

        case 'L':{
            _peca.resize(4);
            for(int c=0; c < 4; c++){
                for(int l=0; l < 2; l++){
                    _peca[c].push_back(Lshaped[l][c]);
                }
            }
            _base=4; _altura=2;
        }break;

        case 'S':{
            _peca.resize(3);
            for(int c=0; c < 3; c++){
                for(int l=0; l < 2; l++){
                    _peca[c].push_back(Sshaped[l][c]);
                }
            }
            _base=3; _altura=2;
        }break;

        case 'T':{
            _peca.resize(3);
            for(int c=0; c < 3; c++){
                for(int l=0; l < 2; l++){
                    _peca[c].push_back(Tshaped[l][c]);
                }
            }
            _base=3; _altura=2;

        }break;
        
        case 'Z':{
            _peca.resize(3);
            for(int c=0; c < 3; c++){
                for(int l=0; l < 2; l++){
                    _peca[c].push_back(Zshaped[l][c]);
                }
            }
            _base=3; _altura=2;
        }break;

        default:{
            std::cerr << "Essa peca nao existe.\n";
            exit(1);
        }break;
    }

    // rotaciona a peça
    rotaciona(angulo);
}

void Tetris::rotaciona(int angulo){

    // Se eu não quero rotacionar a peça...
    if(angulo == 0) return;
    
    // Senão, rotaciona a peçã em 90 graus
    rotaciona(angulo - 90);
    transposeVecSentidoHorario();
}

void Tetris::transposeVecSentidoHorario(){
    // Temp vec
    std::vector<std::vector<char>> transpose_vec(_altura, std::vector<char>(_base));
    int aux;

    // Fazendo a matriz transposta no sentido horário
    for(int c = 0; c < _altura; c++)
        for(int l = 0; l < _base; l++)
            transpose_vec[c][l] = _peca[l][_altura-1-c];

    aux = _altura;
    _altura = _base;
    _base = aux;

    _peca = transpose_vec;
}

void Tetris::imprime() const{   
    for(int i = 0; i < _altura; i++){
        for(int j = 0; j < _base; j++){
            if(i == 0 && j == 0) std::cout << "X";
            else std::cout << _peca[j][i];
        }
        std::cout << "\n";
    }
}

char Tetris::getPeca(int c, int l) const{return _peca[c][l];}

int Tetris::pecaWidth() const {return _base;}

int Tetris::pecaHeight() const{return _altura;}

void Tetris::imprimeTetris() const{
    
    std::cout << "\nAlturas depois: ";
    for(int i = 0; i < _largura; i++) std::cout << getAltura(i) << " ";
    std::cout << "\n";

    int alturaMax = getAltura();
    for(int l = alturaMax-1; l >= 0; l--){
        for(int c = 0; c < _largura; c++){
            if(_jogo[c].size() <= l) std::cout << "- ";
            else std::cout << _jogo[c][l] << " ";
        }
        std::cout << "\n";
    }
}