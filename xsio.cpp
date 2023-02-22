///NOTA:Indicele matricei pleaca de la 1
///jucatorul pune X<->1 calculatorul 0<->0
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<fstream>
using namespace std;
fstream f;

int a[100][100],optiune;
char m[100][100];
bool mutare_calculator;

///initializez elementele martricei cu -1
void initializare()
{
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
        a[i][j]=-1;
}

///afisez elementele matricei in care se desfasoara areana (a[100][100])
void afisare_matrice()
{
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
            cout<<a[i][j]<<' ';
        cout<<'\n';
    }
}

///true-este remiza
///false-nu este remiza
bool remiza()
{
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
        if(a[i][j]==-1)
            return false;
return true;

}











/**verific daca cineva a castigat, abordand toate modurile posibile
true-exista un castigator
false-jocul se continua*/
bool terminat()
{


    ///am verificat daca cineva a castigat pe orizontala
    if(a[1][1]==a[1][2]&&a[1][2]==a[1][3]&&a[1][1]!=-1)
        return true;

    if(a[2][1]==a[2][2]&&a[2][2]==a[2][3]&&a[2][1]!=-1)
        return true;

    if(a[3][1]==a[3][2]&&a[3][2]==a[3][3]&&a[3][1]!=-1)
        return true;

    ///verific daca cineva a castigat pe verticala
    if(a[1][1]==a[2][1]&&a[2][1]==a[3][1]&&a[1][1]!=-1)
        return true;

    if(a[1][2]==a[2][2]&&a[2][2]==a[3][2]&&a[1][2]!=-1)
        return true;

    if(a[1][3]==a[2][3]&&a[2][3]==a[3][3]&&a[1][3]!=-1)
        return true;

    ///verific daca cineva castiga pe diagonala principala
    if(a[1][1]==a[2][2]&&a[2][2]==a[3][3]&&a[1][1]!=-1)
        return true;

    ///verific daca cineva castiga pe diagonala secundara
    if(a[1][3]==a[2][2]&&a[2][2]==a[3][1]&&a[1][3]!=-1)
        return true;

return false;

}


///generz un numar intre 1 si 3 fiind coordonatele in care calculatorul va scrie 0
int generat()
{
    int x;
    bool ok=false;
    while(ok==false)
    {
        x=rand();
        if(x>=1&&x<=3)
            ok=true;
    }
return x;


}


///afisez matricea podoaba, acea matrice care este afisata pe ecran si formata din coduri ASCII si
///elementele matricei arena (a)
void afisare_podoaba()
{
    for(int i=1;i<=7;i++)
    {for(int j=1;j<=7;j++)
            cout<<m[i][j];
    cout<<'\n';
    }
}


void impodobire_matrice()
{

///formez matricea podoaba (vezi programul "creu")
///se treg careurile


///dunga pe stanga
m[1][1]=(char)219;
m[2][1]=(char)219;
m[3][1]=(char)219;
m[4][1]=(char)219;
m[5][1]=(char)219;
m[6][1]=(char)219;
m[7][1]=(char)219;


///dunga pe jos
m[7][2]=(char)219;
m[7][3]=(char)219;
m[7][4]=(char)219;
m[7][5]=(char)219;
m[7][6]=(char)219;


///dunga pe dreapta
m[1][7]=(char)219;
m[2][7]=(char)219;
m[3][7]=(char)219;
m[4][7]=(char)219;
m[5][7]=(char)219;
m[6][7]=(char)219;
m[7][7]=(char)219;



///dunga pe sus
m[1][2]=(char)219;
m[1][3]=(char)219;
m[1][4]=(char)219;
m[1][5]=(char)219;
m[1][6]=(char)219;



///dunga pe mijloc
    ///de sus in jos
m[2][3]=(char)219;
m[3][3]=(char)219;
m[4][3]=(char)219;
m[5][3]=(char)219;
m[6][3]=(char)219;

m[2][5]=(char)219;
m[3][5]=(char)219;
m[4][5]=(char)219;
m[5][5]=(char)219;
m[6][5]=(char)219;


    ///de la stanga la dreapta
m[3][2]=(char)219;
m[3][3]=(char)219;
m[3][4]=(char)219;
m[3][5]=(char)219;
m[3][6]=(char)219;

m[5][2]=(char)219;
m[5][3]=(char)219;
m[5][3]=(char)219;
m[5][4]=(char)219;
m[5][5]=(char)219;
m[5][6]=(char)219;





}


void formare_podoaba()
{int l,c;
///prin l(linie) si c(coloana) parcurg matricea arena in forul ce urmeaza, pentru a constitui matricea
///podoaba(podoaba pentru ca este din coduri ASCII si elementele matricei rena)

l=1;///lungime
c=1;///coloana
for(int i=1;i<=7;i++)
    {for(int j=1;j<=7;j++)
        {
            if(m[i][j]!=(char)219)
            {
                if(a[l][c]==1)
                    m[i][j]='X';

                if(a[l][c]==0)
                    m[i][j]='O';

                if(a[l][c]==-1)
                    m[i][j]=' ';

                c++;
            }
        }
        c=1;

        if(i!=1&&i!=3&&i!=5&&i!=7)
            l++;

    }

afisare_podoaba();

}

///aceasta functie face ca toate valorile din fisier sa fie nule
void resetare()
{
    f.open("statistica",ios::out);
    f<<0<<'\n'<<0<<'\n'<<0;
    f.close();



}

void meniu()
{
  char s[100];


optiune=-1;

    while(optiune!=1&&optiune!=2&&optiune!=3&&optiune!=4)
    {
        system("color 43");
        system("cls");
    cout<<"Start joc"<<'\n';
    cout<<"Statistica"<<'\n';
    cout<<"Resetare"<<'\n';
    cout<<"Iesire"<<'\n';
    cin>>optiune;


        if(optiune==2)
        {
            system("color 37");
            system("cls");
            f.open("statistica",ios::in);
            f.getline(s,255);
            cout<<"Numar de jocuri castigate:"<<s<<'\n';

            f.getline(s,255);
            cout<<"Numar de remize:"<<s<<'\n';

            f.getline(s,255);
            cout<<"Numar de jocuri efectuate:"<<s<<'\n';

            f.close();
            cin>>optiune;///doar ca sa nu se ruleze in continuare...
        optiune=-1;
        }

        if(optiune==3)
        {
         resetare();

        }

    }

}

///1-castiga jucatorul|0-calculatorul|3-remiza
int castigator()
{
///am verificat daca jucatorul a castigat:
/// pe orizontala
    if(a[1][1]==a[1][2]&&a[1][2]==a[1][3]&&a[1][1]==1)
        return 1;

    if(a[2][1]==a[2][2]&&a[2][2]==a[2][3]&&a[2][1]==1)
        return 1;

    if(a[3][1]==a[3][2]&&a[3][2]==a[3][3]&&a[3][1]==1)
        return 1;

    ///verific  a castigat pe verticala
    if(a[1][1]==a[2][1]&&a[2][1]==a[3][1]&&a[1][1]==1)
        return 1;

    if(a[1][2]==a[2][2]&&a[2][2]==a[3][2]&&a[1][2]==1)
        return 1;

    if(a[1][3]==a[2][3]&&a[2][3]==a[3][3]&&a[1][3]==1)
        return 1;

    ///verific daca a castigat pe diagonala principala
    if(a[1][1]==a[2][2]&&a[2][2]==a[3][3]&&a[1][1]==1)
        return 1;

    ///verific daca a  castigat pe diagonala secundara
    if(a[1][3]==a[2][2]&&a[2][2]==a[3][1]&&a[1][3]==1)
        return 1;

///verific castigul calculatorului
///pe orizontala
if(a[1][1]==a[1][2]&&a[1][2]==a[1][3]&&a[1][1]==0)
        return 0;

    if(a[2][1]==a[2][2]&&a[2][2]==a[2][3]&&a[2][1]==0)
        return 0;

    if(a[3][1]==a[3][2]&&a[3][2]==a[3][3]&&a[3][1]==0)
        return 0;

    ///verific  a castigat pe verticala
    if(a[1][1]==a[2][1]&&a[2][1]==a[3][1]&&a[1][1]==0)
        return 0;

    if(a[1][2]==a[2][2]&&a[2][2]==a[3][2]&&a[1][2]==0)
        return 0;

    if(a[1][3]==a[2][3]&&a[2][3]==a[3][3]&&a[1][3]==0)
        return 0;

    ///verific daca a castigat pe diagonala principala
    if(a[1][1]==a[2][2]&&a[2][2]==a[3][3]&&a[1][1]==0)
        return 0;

    ///verific daca a  castigat pe diagonala secundara
    if(a[1][3]==a[2][2]&&a[2][2]==a[3][1]&&a[1][3]==0)
        return 0;

///in caz in care nu s-a intrat in nici o conditionala se returneaza 3(remiza)
return 3;

}

///dupa terminarea jocului se va modifica statistica, asa cum urmeaza
void modificare_statistica()
{int x,y,z;
    f.open("statistica",ios::in);
    f>>x>>y>>z;
    ///daca castiga jucatorul
    if(castigator()==1)
    {
        x++;
        z++;
    }

    ///daca castiga calculatorul
    if(castigator()==0)
    {
        z++;
    }

    ///daca este remiza
    if(castigator()==3)
    {
        y++;
        z++;
    }
f.close();

    f.open("statistica",ios::out);
    f<<x<<'\n'<<y<<'\n'<<z;
    f.close();


}

///in cazul in care se observa doi de x pe aceeasi linie sau aceeasi coloana sau pe diagonala principala/secundara
///calculatorul trebuie sa pareze atacul
void parare()
{int nr;

    ///s-a verificat pe linie
    if(mutare_calculator==false)
    for(int i=1;i<=3;i++)
        {nr=0;
            for(int j=1;j<=3;j++)
            {
                if(a[i][j]==1)
                    nr++;
            }
            if(nr==2)
            {
                for(int j=1;j<=3;j++)
                {
                    if(a[i][j]==-1)
                        {a[i][j]=0;
                        mutare_calculator=true;
                        }
                }
            }
        }

    ///se verifica pe coloana
    if(mutare_calculator==false)
    for(int i=1;i<=3;i++)
    {nr=0;
        for(int j=1;j<=3;j++)
            {
                if(a[j][i]==1)
                {
                    nr++;
                }
            }

            if(nr==2)
            {
                for(int j=1;j<=3;j++)
                {
                    if(a[j][i]==-1)
                     {a[j][i]=0;
                        mutare_calculator=true;
                     }
                }
            }
    }

    ///se verifica pe diagonala principala
    if(mutare_calculator==false)
    {nr=0;
        if(a[1][1]==1)
            nr++;
        if(a[2][2]==1)
            nr++;
        if(a[3][3]==1)
            nr++;

        if(nr==2)
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
                if(i==j&&a[i][j]==-1)
                    {
                        a[i][j]=0;
                        mutare_calculator=true;
                    }
    }



    ///se verifica pe diagonala secundara
    if(mutare_calculator==false)
    {
        nr=0;
        if(a[1][3]==1)
            nr++;
        if(a[2][2]==1)
            nr++;
        if(a[3][1]==1)
            nr++;

        if(nr==2)
            for(int i=1;i<=3;i++)
                for(int j=1;j<=3;j++)
                    {
                        if(i+j==4&&a[i][j]==-1)
                        {
                            a[i][j]=0;
                            mutare_calculator=true;
                        }
                    }
    }
}


///se intampla sa existe posibilitatea de castig, iar calculatorul sa nu o joace, prin codul de mai jos vom forta
///degizia calculatorului de a muta spre victorie
void atac()
{int nr;

    ///s-a verificat pe linie
    if(mutare_calculator==false)
    for(int i=1;i<=3;i++)
        {nr=0;
            for(int j=1;j<=3;j++)
            {
                if(a[i][j]==0)
                    nr++;
            }
            if(nr==2)
            {
                for(int j=1;j<=3;j++)
                {
                    if(a[i][j]==-1)
                        {a[i][j]=0;
                        mutare_calculator=true;
                        }
                }
            }
        }


    ///se verifica pe coloana
    if(mutare_calculator==false)
    for(int i=1;i<=3;i++)
    {nr=0;
        for(int j=1;j<=3;j++)
            {
                if(a[j][i]==0)
                {
                    nr++;
                }
            }

            if(nr==2)
            {
                for(int j=1;j<=3;j++)
                {
                    if(a[j][i]==-1)
                     {a[j][i]=0;
                        mutare_calculator=true;
                     }
                }
            }
    }


    ///se verifica pe diagonala principala
    if(mutare_calculator==false)
    {nr=0;
        if(a[1][1]==0)
            nr++;
        if(a[2][2]==0)
            nr++;
        if(a[3][3]==0)
            nr++;

        if(nr==2)
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
                if(i==j&&a[i][j]==-1)
                    {
                        a[i][j]=0;
                        mutare_calculator=true;
                    }
    }


 ///se verifica pe diagonala secundara
    if(mutare_calculator==false)
    {
        nr=0;
        if(a[1][3]==0)
            nr++;
        if(a[2][2]==0)
            nr++;
        if(a[3][1]==0)
            nr++;

        if(nr==2)
            for(int i=1;i<=3;i++)
                for(int j=1;j<=3;j++)
                    {
                        if(i+j==4&&a[i][j]==-1)
                        {
                            a[i][j]=0;
                            mutare_calculator=true;
                        }
                    }
    }





}








int main()
{
bool ok;
int x,y;
char stai;

srand(time(0));




///corpul jocului

while(0==0)
{

///meniu

system("cls");
meniu();
cout<<'\n'<<optiune<<'\n';
system("cls");
if(optiune==4)
    break;




    if(optiune==1)
    {
system("color b5");
    initializare();

        impodobire_matrice();
    formare_podoaba();



    while(terminat()==false)
    {
        ///evolutia partii jucatorului
        ok=false;
        while(ok==false)
        {   cin>>x>>y;///x-coordonata de pe orizontala, y-de pe verticala
            if(a[x][y]==-1)
            {
                ok=true;///valoare introdusa este corecta
                a[x][y]=1;///jucatorul este cu X
            }
        }



    ///verific daca jocul nu s-a terminat dupa runda jucatorului
    if(terminat()==true||remiza()==true)
        {
            break;
        }


        ///evolutia partii calculatorului
        mutare_calculator=false;///calculatorul inca nu a mutat
        atac();
        parare();
        ok=false;
        while(ok==false&&mutare_calculator==false)
        {
            x=generat();
            y=generat();
            if(a[x][y]==-1)
            {
                ok=true;
                a[x][y]=0;
            }
        }

    system("cls");
    formare_podoaba();
    cout<<'\n'<<'\n';

    ///verific daca jocul nu s-a terminat dupa runda calculatorului

    if(terminat()==true||remiza()==true)
        {

            break;
        }

    }

    system("cls");
    formare_podoaba();
    cout<<'\n'<<'\n';
    modificare_statistica();
    cout<<"Intoarcete la meniu...";cin>>stai;///este o valoare ce imi permite sa trag de timp


    }
}





    return 0;

}
