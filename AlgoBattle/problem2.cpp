#include <bits/stdc++.h>

using namespace std;
bool checkPremierGroupe(string verbe){
    int n=verbe.size()-1;
    return verbe[n]=='r' && verbe[n-1]=='e' && verbe!="aller"; 
}
void conjuger(string verbe){
    string v=verbe;
    int n=v.size();
    for(int i=0; i<n;i++){
        v[i]=toupper(v[i]);
    }
    //transform(v.begin(), v.end(),back_insert_iterator(v),::toupper );
    cout<<v<<endl;
    verbe.pop_back();
    verbe.pop_back();
    cout<<"Je "<< verbe<<"e"<<endl;
    cout<<"Tu "<<verbe<<"es"<<endl;
    cout<<"Il "<<verbe<<"e"<<endl;
    cout<<"Nous "<<verbe<<"ons"<<endl;
    cout<<"Vous "<<verbe<<"ez"<<endl;
    cout<<"Ils "<<verbe<<"ent"<<endl;
}

int main()
{
    // Obtenez plus de points en conjuguant correctement les verbes
    string in;
    int t, i;
    getline(cin, in);
    t=stoi(in);
    i=t;
    int count=0;
    while (t--)
    {
        string verbe;
        getline(cin, verbe);
        if(!checkPremierGroupe(verbe)) count++;
        else conjuger(verbe);

    }
    if(count==i) cout<<"NONE";
    
    return 0;
}
