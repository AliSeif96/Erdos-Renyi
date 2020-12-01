/* rand example: guess the number */
#include <iostream>//for cout
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>//for .txt

#include <string>
#include <sstream>

using namespace std;

int main ()
{
    int n=40;//number of node
    int numb=0;
    float p=0.4;
    int iSecret;
    float N[n][n]={0.0};//becaus matrix start from 0

    srand (time(NULL));/* initialize random seed: */


for (int i=0 ; i<n;i++){
cout<<'\t'<<i;
}
cout<<endl<<endl;
    for (int i=0 ; i<n;i++){
        for (int j=i ; j<n;j++){
            iSecret = rand() % 10 + 1;  /* generate secret number between 1 and 10: */
            int pp=p*10;
            if (iSecret<=pp && i!=j ){
                N[i][j]=1;
                numb=numb+1;

            }
            else{
               N[i][j]=0;
            }
            N[j][i]=N[i][j];
        }
    }
     for (int i=0 ; i<n;i++){
        cout<<i<<'\t';
        for (int j=0 ; j<n;j++){
            cout<<N[i][j]<<'\t';
        }
        cout<<endl<<endl;
    }

    ofstream temp("datas.txt", ios::out | ios::trunc);


    temp<<"{\"nodes\":[{\"name\":\"0\",\"group\":1}";



    for (int i=1 ; i<n;i++){
        temp<<",{\"name\":\""<<i<<"\",\"group\":"<<i<<"}";

    }
    temp<<"],\"links\":[";



int number=0;

    for (int i=0 ; i<n;i++){

        for (int j=i ; j<n;j++){

            if (N[i][j]==1){
                number=number+1;
                temp<<"{\"source\":"<<i<<",\"target\":"<<j<<",\"value\":1}";
                if(number<numb){
                    temp<<",";
                    }
            }
        }
    }






    temp<<"]}";

    temp.close();
    cout << "\nFinish" << endl;





  return 0;
}
