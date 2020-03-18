//
// Created by Filipe Quintal on 2020-03-18.
//
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void imprimePorChar(string caminho_ficheiro){
    ifstream ifs(caminho_ficheiro);

    char c = ifs.get();
    cout << c;

    while (ifs.good()) {

        cout << c ;
        c = ifs.get();
    }

    ifs.close();

}

void gravaString(string caminho_ficheiro){
    fstream fs;
    string content;
    fs.open(caminho_ficheiro,ifstream::out);
    cout << "introduza uma string para gravar :";
    cin >> content;
    fs << content;


    fs.close();

}

void gravaBinario(string caminho_ficheiro){
    fstream fs;
    fs.open(caminho_ficheiro, ios::out|ios::binary);

    char * data = "content to be saved in binary";

    fs.write(data,29);

}

string leLinhALinha(string caminho_ficheiro){

    ifstream myFile(caminho_ficheiro);
    string line="";
    string result = "";
    if(myFile.is_open()){ //verificar se o ficheiro existe

        while (getline(myFile, line)) {
            result = result + " ### "+line;
        }
    }
    myFile.close();
    return result;

}

void leFormato(string caminho_ficheiro){

    fstream ficheiro(caminho_ficheiro, ios::in);
    string nome;
    int numero;
    float media;
    char c;

    while ((ficheiro >>nome >> c >> numero >> c >> media )) {

      cout << "Nome: " << nome << " Número : "<<numero <<" Média : "<<media<<endl;
      //cout << "Valor de c"<<c<<endl;
    }

}