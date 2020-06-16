#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace std;

string preanalisis;
int contador;
vector<string> arreglo;

void parea(string);
void error();

void Exp();
void Resto1();
void Resto2();
void Selector();
void Term();

void Exp()
{
    if(preanalisis=="("){
        parea("(");
        cout<<"( ";
        Term();
        Resto2();

    }else{
        Term();
        Resto1();
    }
};

void Selector(){
    if(preanalisis=="("){
        parea("(");
        cout<<"( ";
        Term();
        Resto2();
    }else{
        if(preanalisis=="Fin"){
            parea("Fin");
        }else{
            Resto1();
        }

    }
}

void Resto1()
{
 if (preanalisis == "+"){
    parea("+");
    if(preanalisis=="("){
        parea("(");
        cout<<"( ";
        Term();
        Resto2();
    }else{
        Term();
        cout<<"+ ";
        if(preanalisis=="+" || preanalisis=="-" || preanalisis=="*" || preanalisis=="/"){
            Resto1();
        }
    }
    if(preanalisis!="Fin"){
        Selector();
    }
 }else{
    if(preanalisis=="-"){
        parea("-");
        if(preanalisis=="("){
            parea("(");
            cout<<"( ";
            Term();
            Resto2();
        }else{
            Term();
            cout<<"- ";
            if(preanalisis=="+" || preanalisis=="-" || preanalisis=="*" || preanalisis=="/"){
                Resto1();
            }
        }
        if(preanalisis!="Fin"){
            Selector();
        }
    }else{
        if(preanalisis=="*"){
            parea("*");
            if(preanalisis=="("){
                parea("(");
                Term();
                Resto2();
            }else{
                Term();
                cout<<"* ";
                if(preanalisis=="+" || preanalisis=="-" || preanalisis=="*" || preanalisis=="/"){
                    Resto1();
                }
            }
            if(preanalisis!="Fin"){
                Selector();
            }
        }else{
            if(preanalisis=="/"){
                parea("/");
                if(preanalisis=="("){
                    parea("(");
                    cout<<"( ";
                    Term();
                    Resto2();
                }else{
                    Term();
                    cout<<"/ ";
                    if(preanalisis=="+" || preanalisis=="-" || preanalisis=="*" || preanalisis=="/"){
                        Resto1();
                    }
                }
                if(preanalisis!="Fin"){
                    Selector();
                }
            }else{
               if(preanalisis=="Fin"){
                    parea("Fin");
                }else{
                    if(preanalisis==")"){

                    }else{
                        error();
                    }

                }
            }
        }

    }
 }

};

void Resto2()
{
 if (preanalisis == "+"){
    parea("+");
    Term();
    if(preanalisis=="+" || preanalisis=="-" || preanalisis=="*" || preanalisis=="/"){
        Resto1();
    }
    parea(")");
    cout<<") ";
    cout<<"+ ";
    if(preanalisis!="Fin"){
        Selector();
    }
 }else{
    if(preanalisis=="-"){
        parea("-");
        Term();
        if(preanalisis=="+" || preanalisis=="-" || preanalisis=="*" || preanalisis=="/"){
            Resto1();
        }
        parea(")");
        cout<<") ";
        cout<<"- ";
        if(preanalisis!="Fin"){
            Selector();
        }
    }else{
        if(preanalisis=="*"){
            parea("*");
            Term();
            if(preanalisis=="+" || preanalisis=="-" || preanalisis=="*" || preanalisis=="/"){
                Resto1();
            }
            parea(")");
            cout<<") ";
            cout<<"* ";
            if(preanalisis!="Fin"){
                Selector();
            }
        }else{
            if(preanalisis=="/"){
                parea("/");
                Term();
                if(preanalisis=="+" || preanalisis=="-" || preanalisis=="*" || preanalisis=="/"){
                    Resto1();
                }
                parea(")");
                cout<<") ";
                cout<<"/ ";
                if(preanalisis!="Fin"){
                    Selector();
                }
            }else{
               if(preanalisis=="Fin"){
                    parea("Fin");
                }else{
                    error();
                }
            }
        }

    }
 }

};

void Term()
{
    cout<<preanalisis<<" ";
    int i=0;
    while(preanalisis[i]!=NULL){
       switch(preanalisis[i]){
            case '0':{
                i++;
                break;
            }
            case '1':{
                i++;
                break;
            }
            case '2':{
                i++;
                break;
            }
            case '3':{
                i++;
                break;
            }
            case '4':{
                i++;
                break;
            }
            case '5':{
                i++;
                break;
            }
            case '6':{
                i++;
                break;
            }
            case '7':{
                i++;
                break;
            }
            case '8':{
                i++;
                break;
            }
            case '9':{
                i++;
                break;
            }
            default:{
                error();
                break;
            }
       }
    }

    contador++;
    preanalisis=arreglo[contador];

}

void error()
{
    cout<<"Error de sintaxis"<<endl;
}

void parea(string t)
{
 if (preanalisis==t){
    contador++;
    if(t!="Fin"){
        preanalisis=arreglo[contador];
    }
 }
 else{
    error();
 }
}

int main(){

    ifstream fe("programa1.txt");
    string texto;
    getline(fe,texto);

    if(texto=="INICIO"){
        while (!fe.eof()) {
            if(texto=="FIN"){
                break;
            }else{
                getline(fe,texto);
                istringstream isstream(texto);
                while(!isstream.eof()){
                    string tempStr;
                    isstream >> tempStr;
                    arreglo.push_back(tempStr);

                }
                contador=0;
                preanalisis=arreglo[contador];
                if(arreglo[0]!="FIN"){
                    Exp();
                }
                contador=0;
                arreglo.clear();
            }
            cout<<endl;
        }


    }else{
        cout<<"Programa no Reconocido"<<endl;
    }


    return 0;
}
