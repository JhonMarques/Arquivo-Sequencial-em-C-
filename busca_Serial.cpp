#include <iostream>
#include <conio2.h>
#include <iomanip>

using namespace std;

   const int N = 20;

   struct tNo{
               int cod;
               string nome;
               string endereco;
               string cidade;
               string uf;

              };







    tNo Cliente[N] = {{1, "Almir", "AV. Rui Barbosa 83", "Assis", "SP"},

                      {2, "Lucas", "R. São paulo 98", "Cândido Mota", "SP"},

                      {3, "Jhonatas", "R. Gaspar Ricardo 83","Brasília", "DF"},

                      {4, "Natan", "AV. Oliveira Pires 110","Tarumã", "SP"},

                      {5, "Wilian", "AV. Assis 54","Paraguaçu", "SP"},

                      {6, "Bruno", "R. São Paulo 93", "Assis", "SP"},

                      {0, "", "", "", ""}, {0, "", "", "", ""},
                      {0, "", "", "", ""}};


    tNo val;
    int cod = 0;
    int meio = 0;
    int id;
    int i = 0;
    int fim = 0;
    int total = 6;
    bool exclui = false;
    int cont = 0;
    int impressao = total;

    void Serial();
    void Aleatoria();
    void Inclui_Registro();
    void Exclui_Registro();
    void Imprimir();


int main(){
   //Menu de Entrada
    setlocale(LC_ALL,"PTB");
    textbackground(BLACK);

    fim = -1;
    int op = -1;

    textbackground(CYAN);

    while (op != 0){
        clrscr();

        textcolor (WHITE);
        gotoxy(30,1);
        cout<<"Arquivo Sequencial";
        gotoxy(30, 2);
        cout<<"------------------";
        gotoxy(27,4);
        cout<<"Opções:";
        gotoxy(27,6);
        cout<<" 1 - Busca Serial";
        gotoxy(27,8);
        cout<<" 2 - Busca Aleatória";
        gotoxy(27,10);
        cout<<" 3 - Inclusão de Registros";
        gotoxy(27,12);
        cout<<" 4 - Exclusão de Registros";
        gotoxy(27,14);
        cout<<" 5 - Imprimir Registros";
        gotoxy(27,16);
        cout<<" 0 - Sair";
        gotoxy(27,18);
        cout<<"Escolha uma Opção: ";
        cin>>op;
        switch (op){

            case 0: { clrscr();
                        gotoxy(32,6);
                        cout << "Bom Descanso...\n\n";
                        getch();
                        break;
                      }
            case 1:  Serial(); break;
            case 2:  Aleatoria(); break;
            case 3:  Inclui_Registro(); break;
            case 4:  Exclui_Registro(); break;
            case 5:  Imprimir();break;

            default: { cout << "\n\n\t\t\t    Opcao Invalida...\n";
                       getch();
                       break;}
       }

    }
}

void Serial(){

    clrscr();
    setlocale(LC_ALL,"PTB");
    fim = 0;

    gotoxy(30, 2);
    cout<<"Busca Serial";

    gotoxy(28, 6);
    cout<<"ID do Cliente: ";
    cin>> id;

    while(Cliente[fim].cod < id && fim < N )
    {
        fim++;
    }

    if(Cliente[fim].cod == id)
    {
       gotoxy(28,8);
       cout<<"Cliente: "<< Cliente[fim].nome;
       gotoxy(28, 10);
       cout<<"End: "<<Cliente[fim].endereco;
       gotoxy(28, 12);
       cout<<"Cidade: "<<Cliente[fim].cidade;
       gotoxy(28, 14);
       cout<<"Uf: "<<Cliente[fim].uf;

    }
    else
    {
        gotoxy(26, 9);
        cout<<"Cliente Não Encotrado!!!";
    }

    getch();
    gotoxy(26, 25);
}

void Aleatoria(){
    int inicio = 0;
    int fim = total;
    int meio = (inicio + fim) / 2;

    clrscr();
    gotoxy(29 , 2);
    cout<<"BUSCA ALEATÓRIA";
    gotoxy(29 , 3);
    cout<<"---------------";

    gotoxy(28 , 5);
    cout<<"Código Procurado: ";
    cin >> id;

    while ( inicio <= fim && id != Cliente[meio].cod )
    {
        if(Cliente[meio].cod > id)
        {
            fim = meio - 1;
        }
        else
        {
            inicio = meio + 1;
        }

        meio = (fim + inicio)/2;
    }


        if (Cliente[meio].cod == id)
        {

            gotoxy(28, 7);
            cout<<"Cliente: "<< Cliente[meio].nome;
            gotoxy(28, 9);
            cout<<"End: "<<Cliente[meio].endereco;
            gotoxy(28, 11);
            cout<<"Cidade: "<<Cliente[meio].cidade;
            gotoxy(28, 13);
            cout<<"Uf: "<<Cliente[meio].uf;

        }
        else
        {
             gotoxy(29, 9);
             cout<<"Não Encontrado!";

        }
    getch();
}

void Inclui_Registro(){

   struct T {
               int cod;
               string nome;
               string endereco;
               string cidade;
               string uf;
             }Tab_T[N];

    struct A {
               int cod;
               string nome;
               string endereco;
               string cidade;
               string uf;
             }Tab_A[N];

    clrscr();
    char incluir = 'S';
    char confirma;
    int ultimo = 0;
    int j = 0;
    int p = 0;
    int i = 0;
    fim = 0;

    ultimo = total + 1;

   if (ultimo <= N){
        while (incluir == 'S'){
            gotoxy(26 , 2);
            cout << "Inclusão de Registros";

            gotoxy(26 , 3);
            cout << "---------------------";
            gotoxy(26 , 5);
            cout << "Cod: ";
            cin >> Tab_T[i].cod;
            for (int r = 0; r < total; r++)
            {
                while (Tab_T[i].cod == Cliente[r].cod)
                {
                    gotoxy(23, 9);
                    cout<<"Código já exitente informe outro  código";
                    getch();

                    clrscr();
                    gotoxy(26 , 2);
                    cout << "Inclusão de Registros";

                    gotoxy(26 , 3);
                    cout << "---------------------";
                    gotoxy(26 , 5);
                    cout << "Cod: ";
                    cin >> Tab_T[i].cod;
                }

            }

            gotoxy(26 , 7 );
            cout<<"Cliente: ";
            cin >> Tab_T[i].nome;

            gotoxy(26, 9);
            cout<<"End: ";
            cin >>Tab_T[i].endereco;

            gotoxy(26, 11);
            cout<<"Cidade: ";
            cin >>Tab_T[i].cidade;

            gotoxy(26, 13);
            cout<<"Uf: ";
            cin >>Tab_T[i].uf;

            i++;
            total++;
            gotoxy(26, 15);
            cout <<"Deseja Incluir Mais Registros S/N: ";
            cin >> incluir;
            incluir = toupper(incluir);

            clrscr();
    }
        gotoxy(29, 8);
        cout<< "Digite S para Salvar: ";
        cin>>confirma;
        confirma = toupper(confirma);
        i = 0;
        j = 0;
        p = 0;
        if(confirma == 'S'){

            while (j <= total && p <= total) // total = tanto de registros existentes e não tamanho total da lista
            {
                if (Cliente[j].cod < Tab_T[p].cod && Cliente[j].cod > 0 && Tab_T[p].cod > 0)
                {
                    Tab_A[i].cod = Cliente[j].cod;
                    Tab_A[i].nome = Cliente[j].nome;
                    Tab_A[i].endereco = Cliente[j].endereco;
                    Tab_A[i].cidade = Cliente[j].cidade;
                    Tab_A[i].uf= Cliente[j].uf;
                    j++;
                    i++;
                 }
                else
                {
                    Tab_A[i].cod = Tab_T[p].cod;
                    Tab_A[i].nome = Tab_T[p].nome;
                    Tab_A[i].endereco = Tab_T[p].endereco;
                    Tab_A[i].cidade = Tab_T[p].cidade;
                    Tab_A[i].uf = Tab_T[p].uf;
                    p++;
                    i++;
                }

            }
            while (j <= total)
            {
                Tab_A[i].cod = Cliente[j].cod;
                Tab_A[i].nome = Cliente[j].nome;
                Tab_A[i].endereco = Cliente[j].endereco;
                Tab_A[i].cidade = Cliente[j].cidade;
                Tab_A[i].uf= Cliente[j].uf;
                j++;
                i++;
            }

            while (p <= total)
            {
                Tab_A[i].cod = Tab_T[p].cod;
                Tab_A[i].nome = Tab_T[p].nome;
                Tab_A[i].endereco = Tab_T[p].endereco;
                Tab_A[i].cidade = Tab_T[p].cidade;
                Tab_A[i].uf = Tab_T[p].uf;
                p++;
                i++;

            }
            while (i < N)
        {
            Cliente[i].cod = 0;
            Cliente[i].nome = " ";
            Cliente[i].endereco = " ";
            Cliente[i].cidade = " ";
            Cliente[i].uf = " ";
            i++;
        }

        i = 0;

        while (i <= total)
        {
            Cliente[i].cod = Tab_A[i].cod;
            Cliente[i].nome = Tab_A[i].nome;
            Cliente[i].cidade = Tab_A[i].cidade;
            Cliente[i].endereco = Tab_A[i].endereco;
            Cliente[i].uf = Tab_A[i].uf;
            i++;
        }
            gotoxy(27,10);
            cout<<"Operação realizada com sucesso!!!";
        }else {
            gotoxy(26,18);
            cout<< "Dados Não Confirmados!";
            total = 6;
            }

      }else {
        clrscr();
        gotoxy(30, 8);
        cout<< "Lista cheia!!!";
        getch();
        }
    impressao = total;

getch();
}

void Exclui_Registro(){
    clrscr();
   struct T {
               int cod;
               string nome;
               string endereco;
               string cidade;
               string uf;
             }Tab_T[N];

    struct A {
               int cod;
               string nome;
               string endereco;
               string cidade;
               string uf;
             }Tab_A[N];

    int j;
    int L = 6;
    int qtd = 0;
    int k;
    const int I = N;
    char continuar = 'S';
    char confirma;

    cont = 0;

    gotoxy(29, 2);
    cout<<"Exclusão de Registros";
    gotoxy(29, 3);
    cout<<"---------------------";
    gotoxy(23, 5);
    cout<<"Informe os Códigos que Deseja Excluir: ";

    for (j = 0; continuar == 'S' && j < N; j++, L++){

        gotoxy(35, L+2);
        cout<<qtd+1 <<"° Cód: ";
        cin>> Tab_T[j].cod;
        impressao++;
        gotoxy(26, L+5);
        cout<<"Deseja Excluir Mais Registros S/N: ";
        cin>> continuar;

        gotoxy(24, L+5);
        cout<<"                                       ";
        continuar = toupper(continuar);
        qtd ++;
    }


    clrscr();
    gotoxy(29, 2);
    cout<<"Exclusão de Registros";

    gotoxy(29, 3);
    cout<<"---------------------";

    for (i = 0; i<qtd; i++ )
    {
        gotoxy(19 , L++);
        cout<<"Cod: "<< Tab_T[i].cod << "  Nome: "<< Cliente[Tab_T[i].cod-1].nome <<"  End: "<< Cliente[Tab_T[i].cod-1].endereco;
    }
    gotoxy(18, 5);
    cout<<"Deseja Realmente Excluir Os Registros Informados S/N: ";
    cin >> confirma;
    confirma = toupper(confirma);

    k = 0;
    j = 0;
    i = 0;

    if (confirma == 'S')
        {   gotoxy(26, 14);
            cout<<"Remoção Efetuada Com Sucesso!";
            while(i < N)
                {
                    if(Cliente[i].cod != Tab_T[k].cod)
                        {
                            Tab_A[j].cod = Cliente[i].cod;
                            Tab_A[j].nome = Cliente[i].nome;
                            Tab_A[j].endereco = Cliente[i].endereco;
                            Tab_A[j].cidade = Cliente[i].cidade;
                            Tab_A[j].uf = Cliente[i].uf;
                            j++;

                        }
                    else k++;

                    i++;
                }


    while (i < N)
        {
            Cliente[i].cod = 0;
            Cliente[i].nome = " ";
            Cliente[i].endereco = " ";
            Cliente[i].cidade = " ";
            Cliente[i].uf = " ";
            i++;
        }

        i = 0;

        while (i <= j)
        {
            Cliente[i].cod = Tab_A[i].cod;
            Cliente[i].nome = Tab_A[i].nome;
            Cliente[i].cidade = Tab_A[i].cidade;
            Cliente[i].endereco = Tab_A[i].endereco;
            Cliente[i].uf = Tab_A[i].uf;
            i++;
        }
    }else
    {
          impressao = 6;
          gotoxy(26, 14);
          cout<<"Remoção Não Confirmada!";
    }
    getch();
}

void Imprimir(){
    clrscr();

    gotoxy(35 , 1);
    cout<<"Registros";
    gotoxy(35 , 2);
    cout<<"---------";

    int L = 4;

        for(int i = 0; i < impressao; i++, L++)
        {
            gotoxy(2 , L++);
            cout<<"Cod: "<< Cliente[i].cod << "  Nome: "<< Cliente[i].nome <<"  End: "<< Cliente[i].endereco
            <<"  Cidade: "<<Cliente[i].cidade << "  UF: "<< Cliente[i].uf;
            cout<<"\n--------------------------------------------------------------------------------";
        }

getch();

}







