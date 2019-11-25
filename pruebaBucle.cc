#include <iostream>

using namespace std;

int main(){
    
    //VALIDO CUANDO LA VISTA VALE 0 ***********
    cout<<"Bucle numero 0"<<endl;
    cout<<"Comparo el 7 con el 0"<<endl;
    for(int i=1;i!=8;i++){
        cout<<"Comparo el "<<i-1<<" con el "<<i<<endl;
    }
    //VALIDO CUANDO LA VISTA VALE 1 ***************
    cout<<"Bucle numero 1"<<endl;
    for(int i=1;i!=0;i++){
        cout<<"Comparo el "<<i-1<<" con el "<<i<<endl;
        if(i==7){
            int aux=i;
            i=-1;
            cout<<"Comparo el "<<aux<<" con el "<<i+1<<endl;
        }
    }
    
    //VALIDO CUANDO LA VISTA VALE 2 **************
    cout<<"Bucle numero 2"<<endl;
    for(int i=2;i!=1;i++){
        //cout<<"EN ESTE MOMENTO I VALE: "<<i<<endl;
        cout<<"Comparo el "<<i-1<<" con el "<<i<<endl;
        if(i==7){
            int aux=i;
            i=1;
            cout<<"Comparo el "<<aux<<" con el "<<i-1<<endl;
        }
        if(i==1){
            cout<<"Comparo el "<<i-1<<" con el "<<i<<endl;
            i--;
        }
        
    }
    for(int n=3;n<=7;n++){
        cout<<"Bucle numero "<<n<<endl;
        for(int i=n;i!=n-1;i++){
            //cout<<"EN ESTE MOMENTO I VALE: "<<i<<endl;
            if(i==7){
                cout<<"Comparo el "<<i-1<<" con el "<<i<<endl;
                i=-1;
                //cout<<"Comparo el "<<7<<" con el "<<0<<endl;
            }
            else{
                if(i!=n-2){
                    if(i==0){
                        cout<<"Comparo el "<<7<<" con el "<<0<<endl;
                    }
                    else{
                        cout<<"Comparo el "<<i-1<<" con el "<<i<<endl;
                    }
                }   
            }
            if(i==n-2){
                cout<<"Comparo el "<<i-1<<" con el "<<i<<endl;
                cout<<"Comparo el "<<i<<" con el "<<i+1<<endl;
            }
        }
    }
}