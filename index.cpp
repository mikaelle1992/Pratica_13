#include <string>
#include <iostream>
#include <vector>

using namespace std;

    struct Passageiro_onibus
    {
        string nome, cpf, idade;

    };

    struct Poltrona
    {
        Passageiro_onibus passageiro;
        bool disponivel = true;
    };
    struct Data_viagem {
        string dia, mes, ano, hora;

    };

    struct Viagem
    {
        Poltrona poltrona[40]; 
        Data_viagem data;
        string destino_viagem; // ida ou volta
        bool tipo_viagem;
        double valor_viagem = 80.0; // valor_viagem = 80 para cada
    };


    void add_viagem(Viagem nova_viagem []){
        int poltrona_numero = 0;
        bool salva_poltrona = false;
        char resposta;

              
        for(int i = 0; i < 2; i++){
            cout << "Distino, ida  ou volta ?" <<endl;
            cin >> nova_viagem[i].destino_viagem;

            for(int j = 1; j < 3; j++){


                cout << "Digite o nome do passageiro:" <<endl;
                cin >> nova_viagem[i].poltrona[j].passageiro.nome;

                cout << "Digite o cpf do passageiro;" <<endl;
                cin >> nova_viagem[i].poltrona[j].passageiro.cpf;

                cout << "Digite a idade do passageiro;" <<endl;
                cin >> nova_viagem[i].poltrona[j].passageiro.cpf;


                if(nova_viagem[i].destino_viagem == "ida"){
                    cout << "Para a Ida escolha o horario, 6:00, 7:00, 8:00, 9:00, 11:00, " <<endl;
                    cin >> nova_viagem[i].data.hora;
                }else if(nova_viagem[i].destino_viagem == "volta"){
                    cout << "para a Volta escolha o horario, 14:00, 15:00, 16:00, 17:00, 18:00, " <<endl;
                    cin >>nova_viagem[i].data.hora;
                };
                cout << "Digite a dia" <<endl;
                cin >> nova_viagem[i].data.dia;

                cout << "Digite mês;" <<endl;
                cin >> nova_viagem[i].data.mes;

                do{
                    cout << "Digite a poltrona (1 -> 40)" <<endl;
                    cin >> poltrona_numero;

                    if(nova_viagem[i].poltrona[poltrona_numero].disponivel == true){
                        nova_viagem[i].poltrona[poltrona_numero].disponivel = false;

                        salva_poltrona = true;

                    }else if(nova_viagem[i].poltrona[poltrona_numero].disponivel == false){
                            cout << "a poltrona está ocupada, escolha outra diferente de "<< poltrona_numero <<endl;
                            salva_poltrona = false;
                    };

                }while (salva_poltrona == false);

                cout << " Deseja Adicionar outro passageiro (s/n)? " << endl;
                cin>> resposta;

                if(resposta != 's'){
                    break;
                };
      
            };
        };

    };

    string total_arrecadado(Viagem nova_viagem []){
        double valor_total =0;
        string dia_escolhido, mes_escolhido, ano_escolhido;
        string horario_escolhido;

        cout <<endl;
        cout << "======================================" <<endl;
        cout << "Total arrecadado" <<endl;


        cout << "Digite o horario da viagem" <<endl;
        cin >> horario_escolhido;

        cout << "Digite a dia da viagem" << endl;
        cin >> dia_escolhido;

        cout << "Digite o mes da viagem" << endl;
        cin >> mes_escolhido;

        // cout << "Digite o ano da viagem" <<endl;
        // cin >> ano_escolhido;


        for(int i=0; i< 10; i ++){
            if(nova_viagem[i].data.dia == dia_escolhido && nova_viagem[i].data.mes == mes_escolhido && nova_viagem[i].data.hora == horario_escolhido){         
                for(int j=0; j< 40; j ++){
                    if(nova_viagem[i].poltrona[j].disponivel == false){
                        valor_total += nova_viagem[i].valor_viagem;
                    };
                };     
            };
        }; 
        cout <<"Total de passagens \n"
                "Dia: "<< dia_escolhido <<"/"<< mes_escolhido <<"/2023:"
                "\nHorario: "<< horario_escolhido <<
                "\nTotal: "<< valor_total <<endl;
    };


    string total_arrecadado_por_mes(Viagem nova_viagem []){
        double valor_total =0;
        string mes_escolhido;

        cout << "Digite o mes da viagem" << endl;
        cin >> mes_escolhido;

        for(int i=0; i< 10; i++){
            if(nova_viagem [i].data.mes == mes_escolhido){
                for(int j=0; j< 40; j++){
                    if(nova_viagem[i].poltrona[j].disponivel == false){
                        valor_total += nova_viagem[i].valor_viagem;
                    }; 
                };
            };
        }; 
        cout <<"Total de passagens \n"
        "Mês: "<< mes_escolhido <<
        "\nAno: 2023"
        "\nTotal: "<< valor_total <<endl;
    };



    string busca_passageiro(Viagem nova_viagem[]){
        double valor_total =0;
        string nome_passageiro;

        cout << "Digite o nome do passageiro" << endl;
        cin >> nome_passageiro;

        for(int i=0; i< 10; i ++){
            for(int j=0; j< 40; j ++){
                if(nova_viagem[i].poltrona[j].passageiro.nome == nome_passageiro){
                    cout << "Nome: " << nova_viagem[i].poltrona[j].passageiro.nome <<
                    "\n Cpf: " << nova_viagem[i].poltrona[j].passageiro.cpf <<
                    "\n Idade: "<< nova_viagem[i].poltrona[j].passageiro.idade <<
                    "\n Destino: " << nova_viagem[i].destino_viagem<<
                    "\n Data: "<< nova_viagem[i].data.dia <<"/"<< nova_viagem[i].data.mes << "/" << nova_viagem[i].data.ano <<endl;
                };
            };     
        };

    };


int main(void){

    Viagem viagens[10];

    add_viagem(viagens);

    total_arrecadado(viagens);


    return 0;


}