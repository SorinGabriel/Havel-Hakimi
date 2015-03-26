#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

void sortare(vector<pair<int,char> > &v,int n)
{
    int i,j;
    pair <int,char> aux;
    for (i=0;i<n-1;i++)
        for (j=i+1;j<n;j++)
            if (v[i].first<v[j].first) {
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
    }
}

int main()
{
    int x,i,n,j;
    pair <int,char> p;
    pair <char,char> q;
    vector<pair<int,char> > v;
    vector<pair<char,char> > m;
    ifstream f("secventa.in");
    f>>n;
    for (i=0;i<n;i++) {
        f>>x;
        p.first=x;
        p.second=i+65;
        v.push_back(p);
    }
    sortare(v,n);
    for (i=0;i<n;i++)
    {
        j=i+1;
        while (v[i].first>0) {
            while (j<n && v[j].first==0) j++;
            if (j==n) {
                cout<<"Nu este secvente grafica";
                return 0;
            }
            v[j].first--;
            v[i].first--;
            q.first=v[i].second;
            q.second=v[j].second;
            m.push_back(q);
            j++;
        }
        j--;
        /* Explicatie pentru mai jos:
        Exista posibilitatea ca atunci cand avem 2 noduri cu graduri egale doar unul din ele sa fie scazut
        iar vectorul sa nu mai fie sortat.Pentru a rezolva asta am putea sorta vectorul din nou sau putem aplica
        algoritmul de mai jos.Conditia v[j]!=0 are scopul de a nu permite programului sa mute ultimul 1 in stanga astfel incat
        i sa fie mai mare decat pozitia pe care se afla acesta.De asemenea cazul v[j]==0 este acoperit prin skipul din
        algoritmul de deasupra. */
        if (v[j].first!=0) while (j<n-1 && v[j].first<v[j+1].first) {
            p=v[j];
            v[j]=v[j+1];
            v[j+1]=p;
        }

    }
    ofstream g("secventa.out");
    for (i=0;i<m.size();i++) g<<"("<<m[i].first<<","<<m[i].second<<")"<<endl;
    cout<<"Secventa grafica(Muchiile sunt in fisierul secventa.out)";
    return 0;
}
