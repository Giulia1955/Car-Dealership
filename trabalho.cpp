//Concessionária de Carros Antigos MotoresFun Dido's
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <limits>
#include <assert.h> 
#define Qnt_Carros 2
using namespace std;

typedef struct{
    string modelo;
    string marca;
    int ano;
    float preco;
    string cor;
}carros;

carros* carro;

int Verifica_Int()
{
    bool loop = true;
    int num;
    while (loop){
        cin >> num;

        if (cin.fail())
        {
            cout << "Entrada Invalida, digite novamente" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
        else
        {
            loop = false;
        }
    }
    return num;
}

char Verifica_Char()
{
    bool loop = true;
    char letra;
    while (loop){
        cin >> letra;

        if (cin.fail())
        {
            cout << "Entrada Invalida, digite novamente" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
        else
        {
            loop = false;
        }
    }
    return letra;
}

float Verifica_Float(){
    bool loop = true;
    float flutuante;
    while (loop){
        cin >> flutuante;

        if (cin.fail())
        {
            cout << "Entrada Invalida, digite novamente" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
        else
        {
            loop = false;
        }
    }
    return flutuante;
}

void Carros_Sist(){
    for (int i = 0; i < Qnt_Carros; i++){
        cout << "modelo:" << endl;

        getline (cin, (carro+i)->modelo);
        
        cout << "marca:" << endl;

        cin.ignore();
        getline(cin, (carro+i)->marca);

        cout << "ano: " << endl;
        (carro + i)->ano = Verifica_Int();
        while((carro[i].ano) > 2005){
            cout << "modelo novo demais para a nossa concessionaria, nem paga IPVA!, escolha outro!" << endl;
            (carro + i)->ano = Verifica_Int();
        }

        cout << "preco:" << endl;
        (carro+i)->preco = Verifica_Float();

        cout << "cor:" << endl;
        cin.ignore();
        getline (cin, (carro+i)->cor);
         
    }
    cout << "modelos registrados: " <<endl;
    for (int i = 0; i < Qnt_Carros; i++){
            cout << (carro+i)->modelo << endl;
    }
}

void Subt_Estoque(int N_Car){
    if (N_Car < Qnt_Carros){
        cout << "modelo:" << endl;

        getline (cin, (carro+N_Car)->modelo);
        
        cout << "marca:" << endl;

        cin.ignore();
        getline(cin, (carro+N_Car)->marca);
        //cin.ignore();

        cout << "ano: " << endl;
        (carro + N_Car)->ano = Verifica_Int();
        while((carro[N_Car].ano) > 2005){
            cout << "modelo novo demais para a nossa concessionaria, nem paga IPVA!, escolha outro!" << endl;
            (carro + N_Car)->ano = Verifica_Int();
        }

        cout << "preco:" << endl;
        (carro+N_Car)->preco = Verifica_Float();

        cout << "cor:" << endl;
        cin.ignore();
        getline (cin, (carro+N_Car)->cor);
    }
}

void Ord_Preco(){
    carros temp;
    for (int i = 1; i < Qnt_Carros; i++) {
        temp = *(carro + i); 
        int j = i - 1;

        while (j >= 0 && (carro + j)->preco > temp.preco) {
            *(carro + j + 1) = *(carro + j);
            j = j - 1;
        }
    *(carro + j + 1) = temp;
    }
}

void Ord_Cor(){
    carros temp;
    for (int i = 1; i < Qnt_Carros; i++) {
        temp = *(carro + i); 
        int j = i - 1;

        while (j >= 0 && (carro + j)->cor > temp.cor) {
            *(carro + j + 1) = *(carro + j);
            j = j - 1;
        }
        *(carro + j + 1) = temp;
    }
}

void Ord_Marca(){
    carros temp;
    for (int i = 1; i < Qnt_Carros; i++) {
        temp = *(carro + i); 
        int j = i - 1;

    while (j >= 0 && (carro + j)->marca > temp.marca) {
        *(carro + j + 1) = *(carro + j);
        j = j - 1;
    }
    *(carro + j + 1) = temp;
    }
}

void Ord_Ano(){
    carros temp;
        for (int i = 1; i < Qnt_Carros; i++) {
            temp = *(carro + i); 
            int j = i - 1;

        while (j >= 0 && (carro + j)->ano > temp.ano) {
            *(carro + j + 1) = *(carro + j);
            j = j - 1;
        }
        *(carro + j + 1) = temp;
    }
}

void Ord_Model() {
    for (int i = 1; i < Qnt_Carros; i++) {
        carros temp = *(carro + i); 
        int j = i - 1;

        while (j >= 0 && (carro + j)->modelo > temp.modelo) {
            *(carro + j + 1) = *(carro + j);
            j--;
        }
        *(carro + j + 1) = temp;
    }
}

void Busca_Valores(float Valor_Min, float Valor_Max) {
    Ord_Preco();

    bool encontrado = false;
    for (int i = 0; i < Qnt_Carros; i++) {
        if (((carro + i)->preco >= Valor_Min) && ((carro + i)->preco <= Valor_Max)) {
            cout << "O modelo " << (carro + i)->modelo << " está disponivel por R$ ";
            cout << fixed << setprecision(2) << (carro + i)->preco << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "Nenhum carro encontrado na faixa de preço especificada." << endl;
    }
}

bool Disponibilidade_Modelo(string model, int esquerda, int direita) {
    int temp[Qnt_Carros] = {-1};
    int j = 0;
    
    if (esquerda > direita) {
        return false; 
    }

    int meio = (esquerda + direita) / 2; 

    if (model < (carro + meio)->modelo) {
        return Disponibilidade_Modelo(model, esquerda, (meio - 1)); 
    } else if (model > (carro + meio)->modelo) {
        return Disponibilidade_Modelo(model, (meio + 1), direita); 
    } else if (model == (carro + meio)->modelo)  {
        temp[j] = meio;
        j++;

        int left = meio - 1;
        while (left >= 0 && (carro + meio)->modelo == model) {
            temp[j] = left;
            left--;
            j++;
        }

        int right = meio + 1;
        while (right <= Qnt_Carros && (carro + meio)->modelo == model) {
            temp[j] = right;
            right++;
            j++;
        }

        for (int i = 0; i < Qnt_Carros; i++){
            if (temp[i] >= 0){
                cout << "Modelo " << model << " disponivel na vaga " << i << endl;
            }
        }
        return true;
    }else{
        return false;
    }
}

bool Disponibilidade_Cor(string cor, int esquerda, int direita) {
    int temp[Qnt_Carros] = {-1};
    int j = 0;
    
    if (esquerda > direita) {
        return false; 
    }

    int meio = (esquerda + direita) / 2; 

    if (cor < (carro + meio)->cor) {
        return Disponibilidade_Cor(cor, esquerda, (meio - 1)); 
    } else if (cor > (carro + meio)->cor) {
        return Disponibilidade_Cor(cor, (meio + 1), direita); 
    } else if (cor == (carro + meio)->cor)  {
        temp[j] = meio;
        j++;

        int left = meio - 1;
        while (left >= 0 && (carro + meio)->cor == cor) {
            temp[j] = left;
            left--;
            j++;
        }

        int right = meio + 1;
        while (right <= Qnt_Carros && (carro + meio)->cor == cor) {
            temp[j] = right;
            right++;
            j++;
        }

        for (int i = 0; i < Qnt_Carros; i++){
            if (temp[i] >= 0){
                cout << "Cor " << cor << " disponivel na vaga " << i << endl;
            }
        }
        return true;
    }else{
        return false;
    }
}

bool Disponibilidade_Marca(string marca, int esquerda, int direita) {
    int temp[Qnt_Carros] = {-1};
    int j = 0;
    
    if (esquerda > direita) {
        return false; 
    }

    int meio = (esquerda + direita) / 2; 

    if (marca < (carro + meio)->marca) {
        return Disponibilidade_Marca(marca, esquerda, (meio - 1)); 
    } else if (marca > (carro + meio)->marca) {
        return Disponibilidade_Marca(marca, (meio + 1), direita); 
    } else if (marca == (carro + meio)->marca)  {
        temp[j] = meio;
        j++;

        int left = meio - 1;
        while (left >= 0 && (carro + meio)->marca == marca) {
            temp[j] = left;
            left--;
            j++;
        }

        int right = meio + 1;
        while (right <= Qnt_Carros && (carro + meio)->marca == marca) {
            temp[j] = right;
            right++;
            j++;
        }

        for (int i = 0; i < Qnt_Carros; i++){
            if (temp[i] >= 0){
                cout << "Marca " << marca << " disponivel na vaga " << i << endl;
            }
        }
        return true;
    }else{
        return false;
    }
}

void Busca_Ano(int ano) {
    Ord_Ano();

    bool encontrado = false;
    for (int i = 0; i < Qnt_Carros; i++) {
        if (((carro + i)->ano == ano)) {
            cout << "O carro de ano " << (carro + i)->ano << " está disponivel na vaga " << i << endl;;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "Nenhum carro encontrado no ano especificado." << endl;
    }
}


void Menu(){
    char Seletor;
    int N_Car, aux, ano;
    float Valor_Min, Valor_Max;
    bool disponivel;
    string model, marca, cor;

    cout << "********************************" << endl;
    cout << "Digite a tecla para a acao desejada: " << endl;
    cout << endl;
    cout << "Alteracao de Modelo - (A)" << endl;
    cout << "Busca por Valores - (B)"<< endl;
    cout << "Busca por Marca - (C)" << endl;
    cout << "Busca por Modelo - (D)" << endl;
    cout << "Busca por Ano - (E)" << endl;
    cout << "Busca por Cor - (F)" << endl;
    cout << endl;
    cout << "********************************" << endl;

    Seletor = Verifica_Char();
    if (Seletor >= 'a' && Seletor <= 'z') { 
        Seletor = Seletor - 32;
    } else if (Seletor < 'A' || Seletor > 'Z') {
        while ((Seletor < 'A' || Seletor > 'Z')){
             cout << "Isso nao é uma letra. Tente novamente: " << endl;
             Seletor = Verifica_Char();
        }
}
    switch (Seletor){
    case 'A':
        cout << "Em qual das vagas o carro vai ficar?" << endl;
        N_Car = Verifica_Int();
        Subt_Estoque(N_Car);
        break;

    case 'B':
        cout << "Selecione a faixa de valores que deseja" << endl;
        Valor_Min = Verifica_Float();
        Valor_Max = Verifica_Float();

        if (Valor_Min > Valor_Max){
            aux = Valor_Min;
            Valor_Min = Valor_Max;
            Valor_Max = aux;
        }

        Busca_Valores(Valor_Min, Valor_Max);
        break;

    case 'C':
        cout << "Que marca gostaria?"<< endl;
        cin.ignore();
        getline (cin, marca);

        Ord_Marca();
        disponivel = Disponibilidade_Marca(marca, 0, (Qnt_Carros - 1));
        if (!disponivel){
            cout << "Marca Indisponivel" << endl;
        }
        break;

    case 'D':
        cout << "Que modelo desejas?"<< endl;
        cin.ignore();
        getline (cin, model);

        Ord_Model();
        disponivel = Disponibilidade_Modelo(model, 0, (Qnt_Carros - 1));
        if (!disponivel){
            cout << "Modelo Indisponivel" << endl;
        }
        break;

    case 'E':
        cout << "Que ano gostaria?"<< endl;
        ano = Verifica_Int();
        Busca_Ano(ano);
        break;

    case 'F':
        cout << "Que cor gostaria?"<< endl;
        cin.ignore();
        getline (cin, cor);

        Ord_Cor();
        disponivel = Disponibilidade_Cor(cor, 0, (Qnt_Carros - 1));
        if (!disponivel){
            cout << "Cor Indisponivel" << endl;
        }
        break;
    default:
        cout << "nenhuma acao disponível nessa letra" << endl;
        break;
    }
}

void Nova_Acao(carros *carro) {
    char sel;
    bool enq;
    do {
        cout << "Deseja fazer mais alguma acao? (S ou N)" << endl;
        sel = Verifica_Char();
        if (sel == 'S' || sel == 's') {
            Menu();
        } else if (sel == 'N' || sel == 'n') {
            cout << "Obrigada por usar o sistema da Concessionaria de Carros Antigos MotoresFun Dido's :)" << endl;
            enq = false; 
        } else {
            cout << "Resposta invalida. Tente novamente." << endl;
        }
    } while (enq);
}


int main(){
    carro = new (nothrow) carros[Qnt_Carros];

    if (!carro) {
        cerr << "Erro ao alocar memória para os carros." << endl;
        return -1; 
    }
    cout << "*****************************************************************" << endl;
    cout << endl;
    cout << "Bem-vindo a Concessionaria de Carros Antigos MotoresFun Dido's " << endl;
    cout << endl;
    cout << "*****************************************************************" << endl;
    cout << "Insira os modelos no sistema" << endl;
    Carros_Sist();

    Menu();
    Nova_Acao(carro);

    delete[] carro; 
    carro = nullptr;

    return 0;
}